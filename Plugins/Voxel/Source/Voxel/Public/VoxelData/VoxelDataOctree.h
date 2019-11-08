// Copyright 2018 Phyronnaz

#pragma once

#include <shared_mutex>

#include "CoreMinimal.h"
#include "VoxelOctree.h"
#include "VoxelDiff.h"
#include "VoxelGlobals.h"
#include "VoxelWorldGenerator.h"
#include "VoxelPlaceableItems/VoxelPlaceableItem.h"
#include "VoxelLogStatDefinitions.h"
#include "VoxelData/VoxelDataCell.h"

DECLARE_MEMORY_STAT(TEXT("Value Octrees Memory"), STAT_VoxelOctreesMemory, STATGROUP_VoxelMemory);
DECLARE_DWORD_ACCUMULATOR_STAT(TEXT("Num Value Octrees"), STAT_VoxelNumValueOctrees, STATGROUP_VoxelMemory);

class FVoxelPlaceableItem;
struct FVoxelUncompressedWorldSave;
using FVoxelMap = TMap<FIntVector, const FVoxelDataCell*>;

/**
 * Octree that holds modified values & materials
 */
class VOXEL_API FVoxelDataOctree : public TVoxelOctree<FVoxelDataOctree, VOXEL_CELL_SIZE>
{
public:
	FVoxelDataOctree(const FVoxelWorldGeneratorInstance* WorldGenerator, uint8 LOD, bool bEnableMultiplayer, bool bEnableUndoRedo)
		: TVoxelOctree(LOD)
		, WorldGenerator(WorldGenerator)
		, bEnableMultiplayer(bEnableMultiplayer)
		, bEnableUndoRedo(bEnableUndoRedo)
	{
		check(LOD > 0);
		INC_DWORD_STAT_BY(STAT_VoxelNumValueOctrees, 1);
		INC_MEMORY_STAT_BY(STAT_VoxelOctreesMemory, sizeof(FVoxelDataOctree));
	}
	FVoxelDataOctree(FVoxelDataOctree* Parent, uint8 ChildIndex)
		: TVoxelOctree(Parent, ChildIndex)
		, WorldGenerator(Parent->WorldGenerator)
		, bEnableMultiplayer(Parent->bEnableMultiplayer)
		, bEnableUndoRedo(Parent->bEnableUndoRedo)
	{
		INC_DWORD_STAT_BY(STAT_VoxelNumValueOctrees, 1);
		INC_MEMORY_STAT_BY(STAT_VoxelOctreesMemory, sizeof(FVoxelDataOctree));
	}

	~FVoxelDataOctree()
	{
		DEC_DWORD_STAT_BY(STAT_VoxelNumValueOctrees, 1);
		DEC_MEMORY_STAT_BY(STAT_VoxelOctreesMemory, sizeof(FVoxelDataOctree));
	}

	inline bool IsCreated() const { check(LOD == 0); return Cell.IsValid(); }
	inline bool IsEmpty() const { check(LOD == 0); check(ItemHolder->IsEmpty() || EmptyState == EVoxelEmptyState::Unknown); return !IsCreated() && EmptyState != EVoxelEmptyState::Unknown; }
	inline bool IsCacheOnly() const { check(LOD == 0); return !IsCreated() || (!Cell->IsBufferDirty<FVoxelValue>() && !Cell->IsBufferDirty<FVoxelMaterial>()); }

	void Cache();
	void ClearCache();

public:
	void GetMap(const FIntBox& Bounds, FVoxelMap& OutMap) const;

public:
	EVoxelEmptyState IsEmpty(const FIntBox& Bounds, int LOD) const;

	void GetValuesAndMaterials(FVoxelValue Values[], FVoxelMaterial Materials[], const FIntBox& Bounds, const FIntVector& Offset, int LOD, const FIntVector& ArraySize, int QueryLOD) const;
	inline void GetValueAndMaterial(FVoxelValue* Value, FVoxelMaterial* Material, int X, int Y, int Z, int QueryLOD) const
	{
		check(IsLeaf());
		check(IsInOctree(X, Y, Z));

		if (LOD > 0 || !IsCreated())
		{
			auto Bounds = FIntBox(X, Y, Z);
			WorldGenerator->GetValuesAndMaterials(Value, Material, Bounds, Bounds.Min, 0, FIntVector(1, 1, 1), QueryLOD, *ItemHolder);
		}
		else
		{
			auto* CellValues = Cell->GetArray<FVoxelValue>();
			auto* CellMaterials = Cell->GetArray<FVoxelMaterial>();

			int Index = IndexFromGlobalCoordinates(X, Y, Z);

			if (Value)
			{
				*Value = CellValues[Index];
			}
			if (Material)
			{
				*Material = CellMaterials[Index];
			}
		}
	}
	
	template<typename TValue>
	inline void SetValueOrMaterial(int X, int Y, int Z, const TValue& Value)
	{
		check(IsLeaf());
		check(IsInOctree(X, Y, Z));

		if (LOD == 0)
		{
			if (!IsCreated())
			{
				Create(true);
			}
			if (!CanEdit(X, Y, Z))
			{
				return;
			}

			Cell->SetBufferAsDirty<TValue>();
			TValue* Array = Cell->GetArray<TValue>();
			FVoxelCellIndex Index = IndexFromGlobalCoordinates(X, Y, Z);

			AddEdit(Index, Array[Index], bEnableMultiplayer, bEnableUndoRedo);

			Array[Index] = Value;
		}
		else
		{
			CreateChildren();
			GetChild(X, Y, Z)->SetValueOrMaterial<TValue>(X, Y, Z, Value);
		}
	}

	template<typename TValue, typename F>
	inline void SetValueOrMaterialLambda(const FIntBox& Bounds, F Lambda)
	{
		if (bEnableMultiplayer)
		{
			if (bEnableUndoRedo)
			{
				SetValueOrMaterialLambdaInternal<TValue, F, true, true>(Bounds, Lambda);
			}
			else
			{
				SetValueOrMaterialLambdaInternal<TValue, F, true, false>(Bounds, Lambda);
			}
		}
		else
		{
			if (bEnableUndoRedo)
			{
				SetValueOrMaterialLambdaInternal<TValue, F, false, true>(Bounds, Lambda);
			}
			else
			{
				SetValueOrMaterialLambdaInternal<TValue, F, false, false>(Bounds, Lambda);
			}
		}
	}
	template<typename TValue, typename F, bool bTEnableMultiplayer, bool bTEnableUndoRedo>
	inline void SetValueOrMaterialLambdaInternal(const FIntBox& Bounds, F Lambda)
	{
		if (Bounds.Intersect(GetBounds()))
		{
			if (LOD == 0)
			{
				if (!IsCreated())
				{
					Create(true);
				}
				
				Cell->SetBufferAsDirty<TValue>();
				TValue* Array = Cell->GetArray<TValue>();

				TArray<FIntBox> LocalBoundsArray = GetEditableBoxes(Bounds.Overlap(GetBounds()));
				for (auto& LocalBounds : LocalBoundsArray)
				{
					const FIntVector& Offset = OctreeBounds.Min;
					const FIntVector Min = LocalBounds.Min - Offset;
					const FIntVector Max = LocalBounds.Max - Offset;

					for (int Z = Min.Z; Z < Max.Z; Z++)
					{
						for (int Y = Min.Y; Y < Max.Y; Y++)
						{
							for (int X = Min.X; X < Max.X; X++)
							{
								FVoxelCellIndex Index = FVoxelDataCellUtilities::IndexFromCoordinates(X, Y, Z);

								if (bTEnableMultiplayer || bTEnableUndoRedo)
								{
									TValue& Ref = Array[Index];
									TValue Old = Ref;

									Lambda(X + Offset.X, Y + Offset.Y, Z + Offset.Z, Ref);

									if (Ref != Old)
									{
										AddEdit<TValue, bTEnableMultiplayer, bTEnableUndoRedo>(Index, Old);
									}
								}
								else
								{
									Lambda(X + Offset.X, Y + Offset.Y, Z + Offset.Z, Array[Index]);
								}
							}
						}
					}
				}
			}
			else
			{
				if (IsLeaf())
				{
					CreateChildren();
				}

				for (auto& Child : GetChildren())
				{
					Child->SetValueOrMaterialLambdaInternal<TValue, F, bTEnableMultiplayer, bTEnableUndoRedo>(Bounds, Lambda);
				}
			}
		}
	}

	template<bool bOnlyIfDirty, typename F>
	inline void CallLambdaOnValuesInBounds(const FIntBox& Bounds, F Lambda) const
	{
		if (Bounds.Intersect(OctreeBounds))
		{
			if (LOD == 0 && IsCreated())
			{
				auto* Values = Cell->GetArray<FVoxelValue>();
				auto* Materials = Cell->GetArray<FVoxelMaterial>();

				const FIntVector& Offset = OctreeBounds.Min;
				const FIntVector Min = FVoxelIntVector::Clamp(Bounds.Min - Offset, 0, VOXEL_CELL_SIZE);
				const FIntVector Max = FVoxelIntVector::Clamp(Bounds.Max - Offset, 0, VOXEL_CELL_SIZE);

				for (int Z = Min.Z; Z < Max.Z; Z++)
				{
					for (int Y = Min.Y; Y < Max.Y; Y++)
					{
						for (int X = Min.X; X < Max.X; X++)
						{
							FVoxelCellIndex Index = FVoxelDataCellUtilities::IndexFromCoordinates(X, Y, Z);
							Lambda(X + Offset.X, Y + Offset.Y, Z + Offset.Z, (const FVoxelValue&)Values[Index], (const FVoxelMaterial&)Materials[Index]);
						}
					}
				}
			}
			else if (IsLeaf())
			{
				if (!bOnlyIfDirty)
				{
					const FIntBox LocalBounds = Bounds.Overlap(GetBounds());
					const FIntVector Size = LocalBounds.Size();
					const FIntVector& Offset = LocalBounds.Min;
					
					int Num = Size.X * Size.Y * Size.Z;
					TArray<FVoxelValue> Values;
					TArray<FVoxelMaterial> Materials;
					Values.SetNumUninitialized(Num);
					Materials.SetNumUninitialized(Num);

					WorldGenerator->GetValuesAndMaterials(Values.GetData(), Materials.GetData(), LocalBounds, LocalBounds.Min, 0, Size);

					int Index = 0;
					for (int Z = 0; Z < Size.Z; Z++)
					{
						for (int Y = 0; Y < Size.Y; Y++)
						{
							for (int X = 0; X < Size.X; X++)
							{
								Lambda(X + Offset.X, Y + Offset.Y, Z + Offset.Z, Values[Index], Materials[Index]);
								Index++;
							}
						}
					}
				}
			}
			else
			{
				for (auto& Child : GetChildren())
				{
					Child->CallLambdaOnValuesInBounds<bOnlyIfDirty>(Bounds, Lambda);
				}
			}
		}
	}

	void ClearData();

public:
	void GetCreatedChunksOverlappingBox(const FIntBox& Box, TArray<FVoxelDataOctree*>& OutOctrees)
	{
		if (GetBounds().Intersect(Box))
		{
			if (IsLeaf())
			{
				if (LOD == 0 && IsCreated())
				{
					OutOctrees.Add(this);
				}
			}
			else
			{
				for (auto& Child : GetChildren())
				{
					Child->GetCreatedChunksOverlappingBox(Box, OutOctrees);
				}
			}
		}
	}
	
public:
	/**
	 * Add dirty chunks to SaveList
	 * @param	SaveQueue				Queue to save chunks into. Sorted by increasing Id
	 */
	void Save(FVoxelUncompressedWorldSave& Save);
	/**
	 * Load chunks from Save list
	 * @param	SaveQueue				Queue to load chunks from. Sorted by decreasing Id (top is lowest Id)
	 * @param	OutBoundsToUpdate		The modified bounds
	 */
	void Load(int& Index, const FVoxelUncompressedWorldSave& Save, TArray<FIntBox>& OutBoundsToUpdate);
		
public:
	// sorted by increasing Id
	bool BeginSet(const FIntBox& Box, TArray<FVoxelId>& OutIds, int MicroSeconds);
	// sorted by decreasing Id
	void EndSet(TArray<FVoxelId>& Ids);
	
	// sorted by increasing Id
	bool BeginGet(const FIntBox& Box, TArray<FVoxelId>& OutIds, int MicroSeconds);
	// sorted by decreasing Id
	void EndGet(TArray<FVoxelId>& Ids);

	void LockTransactions();

public:
	template<typename T>
	void AddItem(T* Item)
	{
		if (Item->Bounds.Intersect(GetBounds()))
		{
			if (IsLeaf())
			{
				ItemHolder->AddItem<T>(Item);

				if (ItemHolder->Num() > MAX_PLACEABLE_ITEMS_PER_OCTREE && LOD > 0)
				{
					CreateChildren();
					
				}
			}
			else
			{
				for (auto& Child : GetChildren())
				{
					Child->AddItem(Item);
				}
			}
		}
	}

public:
	void AddChunksToDiffQueues(TArray<TVoxelChunkDiff<FVoxelValue>>& ValueDiffQueue, TArray<TVoxelChunkDiff<FVoxelMaterial>>& MaterialDiffQueue);

	template<typename T>
	FIntBox LoadVoxelDiff(TVoxelChunkDiff<T>& ChunkDiff)
	{
		if (LOD == 0)
		{
			check(Position == ChunkDiff.Position);
			if (!IsCreated())
			{
				Create(true);
			}

			for (auto& Diff : ChunkDiff.Diffs)
			{
				check(0 <= Diff.Index && Diff.Index < VOXEL_CELL_COUNT);
				Cell->GetArray<T>()[Diff.Index] = Diff.Value;
			}

			return GetBounds();
		}
		else
		{
			check(GetBounds().IsInside(ChunkDiff.Position));
			if (IsLeaf())
			{
				CreateChildren();
			}
			for (auto& Child : GetChildren())
			{
				if (Child->GetBounds().IsInside(ChunkDiff.Position))
				{
					return Child->LoadVoxelDiff(ChunkDiff);
				}
			}
			check(false);
			return FIntBox();
		}
	}


public:
	/**
	 * Add the current frame to the undo stack. Clear the redo stack
	 */
	void SaveFrame(int HistoryPosition);
	/**
	 * Undo one frame and add it to the redo stack. Current frame must be empty
	 */
	void Undo(int HistoryPosition, TArray<FIntBox>& OutBoundsToUpdate);
	/**
	 * Redo one frame and add it to the undo stack. Current frame must be empty
	 */
	void Redo(int HistoryPosition, TArray<FIntBox>& OutBoundsToUpdate);
	/**
	 * Clear all the frames
	 */
	void ClearFrames();
	/**
	 * Check that the current frame is empty (safe to call Undo/Redo)
	 */
	bool CheckIfCurrentFrameIsEmpty() const;

protected:
	TUniquePtr<FVoxelDataCell> Cell;
	TUniquePtr<FVoxelDataCellMultiplayer> MultiplayerCell;
	TUniquePtr<FVoxelDataCellUndoRedo> UndoRedoCell;
	TUniquePtr<FVoxelPlaceableItemHolder> ItemHolder = MakeUnique<FVoxelPlaceableItemHolder>(); // Always valid on a leaf

	const FVoxelWorldGeneratorInstance* const WorldGenerator;
	const bool bEnableMultiplayer : 1;
	const bool bEnableUndoRedo : 1;

	EVoxelEmptyState EmptyState = EVoxelEmptyState::Unknown;

	virtual void CreateChildren() override;

private:
	std::shared_timed_mutex MainLock;
	std::mutex TransactionLock;
	
private:
	void Create(bool bInitFromWorldGenerator);
	void Destroy();

private:
	inline FVoxelCellIndex IndexFromGlobalCoordinates(int X, int Y, int Z) const
	{
		X -= GetBounds().Min.X;
		Y -= GetBounds().Min.Y;
		Z -= GetBounds().Min.Z;
		return FVoxelDataCellUtilities::IndexFromCoordinates(X, Y, Z);
	}

	template<typename T>
	inline void AddEdit(FVoxelCellIndex Index, T& Old, bool bInEnableMultiplayer, bool bInEnableUndoRedo)
	{
		if (bInEnableMultiplayer)
		{
			MultiplayerCell->AddEdit(Index, Old);
		}
		if (bInEnableUndoRedo)
		{
			UndoRedoCell->AddEdit(Index, Old);
		}
	}
	template<typename T, bool bInEnableMultiplayer, bool bInEnableUndoRedo>
	inline void AddEdit(FVoxelCellIndex Index, T& Old)
	{
		if (bInEnableMultiplayer)
		{
			MultiplayerCell->AddEdit(Index, Old);
		}
		if (bInEnableUndoRedo)
		{
			UndoRedoCell->AddEdit(Index, Old);
		}
	}

	inline bool CanEdit(int X, int Y, int Z)
	{		
		for (FVoxelPlaceableItem* Item : ItemHolder->GetItems(FVoxelPlaceableItem::EVoxelDisableEditsBox))
		{
			if (Item->Bounds.IsInside(X, Y, Z))
			{
				return false;
			}
		}
		return true;
	}

	inline TArray<FIntBox> GetEditableBoxes(const FIntBox& Bounds)
	{
		TArray<FIntBox> Result;
		Result.Add(Bounds);
		for (FVoxelPlaceableItem* Item : ItemHolder->GetItems(FVoxelPlaceableItem::EVoxelDisableEditsBox))
		{
			TArray<FIntBox> NewArray;
			for (auto& OldBounds : Result)
			{
				FIntBox::GetRemainingBoxes(OldBounds, Item->Bounds, NewArray);
			}
			Result = NewArray;
		}
		return Result;
	}
};