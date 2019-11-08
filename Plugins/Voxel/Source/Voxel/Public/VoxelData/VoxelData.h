// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelMaterial.h"
#include "IntBox.h"
#include "VoxelDiff.h"
#include "VoxelSave.h"
#include "VoxelValue.h"
#include "VoxelData/VoxelDataOctree.h"

class FVoxelWorldGeneratorInstance;
class FVoxelPlaceableItem;

/**
 * Class that handle voxel data
 */
class VOXEL_API FVoxelData
{
public:
	class FVoxelScopeSetLock
	{
	public:
		FVoxelScopeSetLock(FVoxelData* Data, const FIntBox& Bounds)
			: Data(Data)
		{
			Data->BeginSet(Bounds, LockedOctrees);
		}
		template<ESPMode Mode>
		FVoxelScopeSetLock(const TSharedPtr<FVoxelData, Mode>& Data, const FIntBox& Bounds)
			: FVoxelScopeSetLock(Data.Get(), Bounds)
		{
		}

		~FVoxelScopeSetLock()
		{
			Data->EndSet(LockedOctrees);
		}

	private:
		TArray<FVoxelId> LockedOctrees;
		FVoxelData* const Data;
	};

	class FVoxelScopeGetLock
	{
	public:
		FVoxelScopeGetLock(FVoxelData* Data, const FIntBox& Bounds)
			: Data(Data)
		{
			Data->BeginGet(Bounds, LockedOctrees);
		}
		template<ESPMode Mode>
		FVoxelScopeGetLock(const TSharedPtr<FVoxelData, Mode>& Data, const FIntBox& Bounds)
			: FVoxelScopeGetLock(Data.Get(), Bounds)
		{
		}

		~FVoxelScopeGetLock()
		{
			Data->EndGet(LockedOctrees);
		}

	private:
		TArray<FVoxelId> LockedOctrees;
		FVoxelData* const Data;
	};

public:
	/**
	 * Constructor
	 * @param	Depth			Depth of this world; Size = VOXEL_CELL_SIZE * 2^Depth
	 * @param	WorldGenerator	Generator for this world
	 * @param	bMultiplayer	Is this for a multiplayer world
	 * @param	bEnableUndoRedo	Enable Undo/Redo?
	 */
	FVoxelData(int Depth, const FIntBox& WorldBounds, TSharedRef<const FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> WorldGenerator, bool bEnableMultiplayer, bool bEnableUndoRedo)
		: Depth(Depth)
		, WorldBounds(WorldBounds)
		, bEnableMultiplayer(bEnableMultiplayer)
		, bEnableUndoRedo(bEnableUndoRedo)
		, WorldGenerator(WorldGenerator)
		, Octree(MakeUnique<FVoxelDataOctree>(&WorldGenerator.Get(), Depth, bEnableMultiplayer, bEnableUndoRedo))
		, HistoryPosition(0)
		, MaxHistoryPosition(0)
	{
		check(Depth > 0);
		check(Octree->GetBounds().Contains(WorldBounds));
	}
	FVoxelData(int Depth, TSharedRef<const FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> WorldGenerator, bool bEnableMultiplayer, bool bEnableUndoRedo)
		: FVoxelData(Depth, FVoxelUtilities::GetBoundsFromDepth<VOXEL_CELL_SIZE>(Depth), WorldGenerator, bEnableMultiplayer, bEnableUndoRedo)
	{

	}

	const int Depth;
	const FIntBox WorldBounds;
	const bool bEnableMultiplayer;
	const bool bEnableUndoRedo;

	TSharedRef<const FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> const WorldGenerator;

	// Size = VOXEL_CELL_SIZE * 2^Depth
	inline int32 Size() const { return VOXEL_CELL_SIZE << Depth; }
	inline FIntBox GetBounds() const
	{
		return WorldBounds;
	}
	inline FVoxelDataOctree* GetOctree() const { return Octree.Get(); }

public:
	/**
	 * Lock Box in read/write
	 * @param	Box			Box to lock
	 * @param	OutOctrees	Locked octrees
	 */
	void BeginSet(const FIntBox& Box, TArray<FVoxelId>& OutOctrees);
	bool TryBeginSet(const FIntBox& Box, int TimeoutMicroSeconds, TArray<FVoxelId>& OutOctrees);
	/**
	 * End the lock on LockedOctrees
	 * @param	LockedOctrees		Returned by BeginSet
	 */
	 void EndSet(TArray<FVoxelId>& LockedOctrees);
	 
	/**
	 * Lock Box in read only
	 * @param	Box		Box to lock
	 * @param	OutOctrees	Locked octrees
	 */
	 void BeginGet(const FIntBox& Box, TArray<FVoxelId>& OutOctrees);
	 bool TryBeginGet(const FIntBox& Box, int TimeoutMicroSeconds, TArray<FVoxelId>& OutOctrees);
	/**
	 * End the lock on LockedOctrees
	 * @param	LockedOctrees		Returned by BeginGet
	 */
	void EndGet(TArray<FVoxelId>& LockedOctrees);
	
public:	
	void GetValuesAndMaterials(FVoxelValue Values[], FVoxelMaterial Materials[], const FIntBox& Bounds, const FIntVector& Offset, int InLOD, const FIntVector& ArraySize, int QueryLOD = 0) const;

	inline bool IsEmpty(const FIntBox& Bounds, int InLOD) const { return Octree->IsEmpty(Bounds, InLOD) != EVoxelEmptyState::Unknown; }
	
	template<typename T>
	void SetValueOrMaterial(int X, int Y, int Z, const T& Value)
	{
		if (LIKELY(IsInWorld(X, Y, Z)))
		{
			Octree->GetLeaf(X, Y, Z)->SetValueOrMaterial<T>(X, Y, Z, Value);
		}
	}
	template<typename T, typename F>
	void SetValueOrMaterialLambda(const FIntBox& Bounds, F Lambda) { Octree->SetValueOrMaterialLambda<T>(Bounds.Overlap(WorldBounds), Lambda); }

	template<bool bOnlyIfDirty, typename F>
	void CallLambdaOnValuesInBounds(const FIntBox& Bounds, F Lambda) { Octree->CallLambdaOnValuesInBounds<bOnlyIfDirty>(Bounds, Lambda); }

public:
	inline void GetMap(const FIntBox& Bounds, FVoxelMap& OutMap) const { Octree->GetMap(Bounds, OutMap); }

	inline void GetValueAndMaterial(int X, int Y, int Z, FVoxelValue* OutValue, FVoxelMaterial* OutMaterial, const FVoxelMap& InMap, int QueryLOD = 0) const
	{
		FIntVector Position(FMath::FloorToInt((float)X / VOXEL_CELL_SIZE), FMath::FloorToInt((float)Y / VOXEL_CELL_SIZE), FMath::FloorToInt((float)Z / VOXEL_CELL_SIZE));	
		auto* Chunk = InMap.Find(Position);
		if (Chunk)
		{
			int Index = FVoxelDataCellUtilities::IndexFromCoordinates(X - Position.X * VOXEL_CELL_SIZE, Y - Position.Y * VOXEL_CELL_SIZE, Z - Position.Z * VOXEL_CELL_SIZE);
			if (OutValue)
			{
				*OutValue = (*Chunk)->GetBuffer<FVoxelValue>()[Index];
			}
			if (OutMaterial)
			{
				*OutMaterial = (*Chunk)->GetBuffer<FVoxelMaterial>()[Index];
			}
		}
		else
		{
			GetValueAndMaterial(X, Y, Z, OutValue, OutMaterial, QueryLOD);
		}
	}

	inline void GetValueAndMaterial(int X, int Y, int Z, FVoxelValue& OutValue, FVoxelMaterial& OutMaterial, const FVoxelMap& InMap, int QueryLOD = 0) const { GetValueAndMaterial(X, Y, Z, &OutValue, &OutMaterial, InMap, QueryLOD); }

	inline FVoxelValue GetValue(int X, int Y, int Z, const FVoxelMap& InMap, int QueryLOD = 0) const { FVoxelValue Value; GetValueAndMaterial(X, Y, Z, &Value, nullptr, InMap, QueryLOD); return Value; }
	inline FVoxelValue GetValue(const FIntVector& P, const FVoxelMap& InMap, int QueryLOD = 0) const { return GetValue(P.X, P.Y, P.Z, InMap, QueryLOD); }

	inline FVoxelMaterial GetMaterial(int X, int Y, int Z, const FVoxelMap& InMap, int QueryLOD = 0) const { FVoxelMaterial Material; GetValueAndMaterial(X, Y, Z, nullptr, &Material, InMap, QueryLOD); return Material; }
	inline FVoxelMaterial GetMaterial(const FIntVector& P, const FVoxelMap& InMap, int QueryLOD = 0) const { return GetMaterial(P.X, P.Y, P.Z, InMap, QueryLOD); }
	
public:
	inline void GetValueAndMaterial(int X, int Y, int Z, FVoxelValue* OutValue, FVoxelMaterial* OutMaterial, FVoxelDataOctree*& InOctree, int QueryLOD = 0) const
	{
		if (UNLIKELY(!IsInWorld(X, Y, Z)))
		{
			auto Bounds = FIntBox(X, Y, Z);
			WorldGenerator->GetValuesAndMaterials(OutValue, OutMaterial, Bounds, Bounds.Min, 0, FIntVector(1, 1, 1), QueryLOD);
		}
		else
		{
			if (UNLIKELY(!InOctree || !InOctree->IsInOctree(X, Y, Z) || !InOctree->IsLeaf()))
			{
				InOctree = Octree->GetLeaf(X, Y, Z);
			}
			InOctree->GetValueAndMaterial(OutValue, OutMaterial, X, Y, Z, QueryLOD);
		}
	}
	template<typename T>
	void SetValueOrMaterial(int X, int Y, int Z, FVoxelDataOctree*& InOctree, const T& Value)
	{
		if (UNLIKELY(!IsInWorld(X, Y, Z)))
		{
			return;
		}
		if (UNLIKELY(!InOctree || !InOctree->IsInOctree(X, Y, Z)))
		{
			InOctree = Octree->GetLeaf(X, Y, Z);
		}
		InOctree->SetValueOrMaterial<T>(X, Y, Z, Value);
	}

	inline void GetValueAndMaterial(int X, int Y, int Z, FVoxelValue& OutValue, FVoxelMaterial& OutMaterial, FVoxelDataOctree*& InOctree, int QueryLOD = 0) const { GetValueAndMaterial(X, Y, Z, &OutValue, &OutMaterial, InOctree, QueryLOD); }
	inline void GetValueAndMaterial(const FIntVector& P, FVoxelValue& OutValue, FVoxelMaterial& OutMaterial, FVoxelDataOctree*& InOctree, int QueryLOD = 0) const { GetValueAndMaterial(P.X, P.Y, P.Z, OutValue, OutMaterial, InOctree, QueryLOD); }

	inline FVoxelValue GetValue(int X, int Y, int Z, FVoxelDataOctree*& InOctree, int QueryLOD = 0) const { FVoxelValue Value; GetValueAndMaterial(X, Y, Z, &Value, nullptr, InOctree, QueryLOD); return Value; }
	inline FVoxelValue GetValue(const FIntVector& P, FVoxelDataOctree*& InOctree, int QueryLOD = 0) const { return GetValue(P.X, P.Y, P.Z, InOctree, QueryLOD); }

	inline FVoxelMaterial GetMaterial(int X, int Y, int Z, FVoxelDataOctree*& InOctree, int QueryLOD = 0) const { FVoxelMaterial Material; GetValueAndMaterial(X, Y, Z, nullptr, &Material, InOctree, QueryLOD); return Material; }
	inline FVoxelMaterial GetMaterial(const FIntVector& P, FVoxelDataOctree*& InOctree, int QueryLOD = 0) const { return GetMaterial(P.X, P.Y, P.Z, InOctree, QueryLOD); }
	
	inline void SetValue(int X, int Y, int Z, FVoxelValue Value, FVoxelDataOctree*& InOctree) { SetValueOrMaterial<FVoxelValue>(X, Y, Z, InOctree, Value); }
	inline void SetValue(const FIntVector& P, FVoxelValue Value, FVoxelDataOctree*& InOctree) { SetValue(P.X, P.Y, P.Z, Value); }

	inline void SetMaterial(int X, int Y, int Z, FVoxelMaterial Material, FVoxelDataOctree*& InOctree) { SetValueOrMaterial<FVoxelMaterial>(X, Y, Z, InOctree, Material); }
	inline void SetMaterial(const FIntVector& P, FVoxelMaterial Material, FVoxelDataOctree*& InOctree) { SetMaterial(P.X, P.Y, P.Z, Material); }

public:
	/**
	 * Get the value and material at position. Requires BeginGet
	 */
	inline void GetValueAndMaterial(int X, int Y, int Z, FVoxelValue* OutValue, FVoxelMaterial* OutMaterial, int QueryLOD = 0) const
	{
		if (UNLIKELY(!IsInWorld(X, Y, Z)))
		{
			auto Bounds = FIntBox(X, Y, Z);
			WorldGenerator->GetValuesAndMaterials(OutValue, OutMaterial, Bounds, Bounds.Min, 0, FIntVector(1, 1, 1), QueryLOD);
		}
		else
		{
			Octree->GetLeaf(X, Y, Z)->GetValueAndMaterial(OutValue, OutMaterial, X, Y, Z, QueryLOD);
		}
	}
	inline void GetValueAndMaterial(int X, int Y, int Z, FVoxelValue& OutValue, FVoxelMaterial& OutMaterial, int QueryLOD = 0) const { GetValueAndMaterial(X, Y, Z, &OutValue, &OutMaterial, QueryLOD); }
	inline void GetValueAndMaterial(const FIntVector& P, FVoxelValue& OutValue, FVoxelMaterial& OutMaterial, int QueryLOD = 0) const { GetValueAndMaterial(P.X, P.Y, P.Z, OutValue, OutMaterial, QueryLOD); }
	/**
	 * Get the value at position. Requires BeginGet
	 */
	inline FVoxelValue GetValue(int X, int Y, int Z, int QueryLOD = 0) const { FVoxelValue Value; GetValueAndMaterial(X, Y, Z, &Value, nullptr, QueryLOD); return Value; }
	inline FVoxelValue GetValue(const FIntVector& P, int QueryLOD = 0) const { return GetValue(P.X, P.Y, P.Z, QueryLOD); }
	/**
	 * Get the material at position. Requires BeginGet
	 */
	inline FVoxelMaterial GetMaterial(int X, int Y, int Z, int QueryLOD = 0) const { FVoxelMaterial Material; GetValueAndMaterial(X, Y, Z, nullptr, &Material, QueryLOD); return Material; }
	inline FVoxelMaterial GetMaterial(const FIntVector& P, int QueryLOD = 0) const { return GetMaterial(P.X, P.Y, P.Z, QueryLOD); }

	/**
	 * Requires BeginGet with an offset of 1 (final box has size 3)
	 */
	inline FVector GetGradient(int X, int Y, int Z) const
	{
		FVector Gradient;
		Gradient.X = GetValue(X + 1, Y, Z).ToFloat() - GetValue(X - 1, Y, Z).ToFloat();
		Gradient.Y = GetValue(X, Y + 1, Z).ToFloat() - GetValue(X, Y - 1, Z).ToFloat();
		Gradient.Z = GetValue(X, Y, Z + 1).ToFloat() - GetValue(X, Y, Z - 1).ToFloat();
		return Gradient.GetSafeNormal();
	}
	inline FVector GetGradient(const FIntVector& P) const { return GetGradient(P.X, P.Y, P.Z); }

	/**
	 * Set value at position. Requires BeginSet
	 * @param	X,Y,Z	Position in voxel space
	 * @param	Value 		Value to set
	 */
	inline void SetValue(int X, int Y, int Z, FVoxelValue Value)
	{
		if (UNLIKELY(!IsInWorld(X, Y, Z)))
		{
			return;
		}
		Octree->GetLeaf(X, Y, Z)->SetValueOrMaterial<FVoxelValue>(X, Y, Z, Value);
	}
	inline void SetValue(const FIntVector& P, FVoxelValue Value) { SetValue(P.X, P.Y, P.Z, Value); }

	/**
	 * Set material at position. Requires BeginSet
	 * @param	X,Y,Z		Position in voxel space
	 * @param	Material	Material to set
	 */
	inline void SetMaterial(int X, int Y, int Z, FVoxelMaterial Material)
	{
		if (UNLIKELY(!IsInWorld(X, Y, Z)))
		{
			return;
		}
		Octree->GetLeaf(X, Y, Z)->SetValueOrMaterial<FVoxelMaterial>(X, Y, Z, Material);
	}
	inline void SetMaterial(const FIntVector& P, FVoxelMaterial Material) { SetMaterial(P.X, P.Y, P.Z, Material); }

public:	
	/**
	 * Is Position in this world?
	 * @param	X,Y,Z	Position in voxel space
	 */
	template<typename TNumeric>
	inline bool IsInWorld(TNumeric X, TNumeric Y, TNumeric Z) const
	{
		return WorldBounds.IsInside(X, Y, Z);
	}
	template<typename TVector>
	inline bool IsInWorld(const TVector& P) const { return IsInWorld(P.X, P.Y, P.Z); }

	/**
	 * Clamp (X, Y, Z) in the world
	 */
	inline void ClampToWorld(int& X, int& Y, int& Z) const
	{
		int32 S = Size() / 2;
		X = FMath::Clamp(X, -WorldBounds.Min.X, WorldBounds.Max.X - 1);
		Y = FMath::Clamp(Y, -WorldBounds.Min.Y, WorldBounds.Max.Y - 1);
		Z = FMath::Clamp(Z, -WorldBounds.Min.Z, WorldBounds.Max.Z - 1);
	}

public:
	/**
	 * Get a save of this world
	 */
	void GetSave(FVoxelUncompressedWorldSave& OutSave);

	/**
	 * Load this world from save
	 * @param	Save						Save to load from
	 * @param	OutBoundsToUpdate			The modified bounds
	 */
	void LoadFromSave(const FVoxelUncompressedWorldSave& Save, TArray<FIntBox>& OutBoundsToUpdate);

public:
	/**
	 * Get diff arrays to allow network transmission
	 * @param	OutValueDiffQueue		Values diff array; sorted by increasing Id
	 * @param	OutMaterialDiffQueue	Materials diff array; sorted by increasing Id
	 */
	void GetDiffQueues(TArray<TVoxelChunkDiff<FVoxelValue>>& OutValueDiffQueue, TArray<TVoxelChunkDiff<FVoxelMaterial>>& OutMaterialDiffQueue);

	/**
	 * Load values and materials from diffs, and add modified positions
	 * @param	ValueDiffQueue			Values diff array; sorted by increasing Id
	 * @param	MaterialDiffQueue		Materials diff array; sorted by increasing Id
	 */
	void LoadFromDiffQueues(TArray<TVoxelChunkDiff<FVoxelValue>>& ValueDiffQueue, TArray<TVoxelChunkDiff<FVoxelMaterial>>& MaterialDiffQueue, TArray<FIntBox>& OutModifiedBounds);

public:
	/**
	 * Undo one frame and add it to the redo stack. Current frame must be empty
	 */
	void Undo(TArray<FIntBox>& OutBoundsToUpdate)
	{
		FVoxelScopeSetLock Lock(this, FIntBox::Infinite);
		if (HistoryPosition > 0)
		{
			HistoryPosition--;
			Octree->Undo(HistoryPosition, OutBoundsToUpdate);
		}
	}
	/**
	 * Redo one frame and add it to the undo stack. Current frame must be empty
	 */
	void Redo(TArray<FIntBox>& OutBoundsToUpdate)
	{
		FVoxelScopeSetLock Lock(this, FIntBox::Infinite);
		if (HistoryPosition < MaxHistoryPosition)
		{
			HistoryPosition++;
			Octree->Redo(HistoryPosition, OutBoundsToUpdate);
		}
	}
	/**
	 * Clear all the frames
	 */
	void ClearFrames()
	{
		FVoxelScopeSetLock Lock(this, FIntBox::Infinite);
		Octree->ClearFrames();
		HistoryPosition = 0;
		MaxHistoryPosition = 0;
	}
	/**
	 * Add the current frame to the undo stack. Clear the redo stack
	 */
	void SaveFrame()
	{
		FVoxelScopeSetLock Lock(this, FIntBox::Infinite);
		Octree->SaveFrame(HistoryPosition);
		HistoryPosition++;
		MaxHistoryPosition = HistoryPosition;
	}
	/**
	 * Check that the current frame is empty (safe to call Undo/Redo)
	 */
	bool CheckIfCurrentFrameIsEmpty()
	{
		FVoxelScopeGetLock Lock(this, FIntBox::Infinite);
		return Octree->CheckIfCurrentFrameIsEmpty();
	}
	/**
	 * Get the history position
	 */
	int GetHistoryPosition() const { return HistoryPosition; }
	/**
	 * Get the max history position (including redo frames)
	 */
	inline int GetMaxHistory() const { return MaxHistoryPosition; }

public:
	template<typename T, typename... TArgs>
	void AddItem(TArgs... Args)
	{
		TUniquePtr<T> Item = MakeUnique<T>(Args...);
		Octree->AddItem<T>(Item.Get());
		Items.Add(MoveTemp(Item));
	}

private:
	TUniquePtr<FVoxelDataOctree> const Octree;
	int HistoryPosition;
	int MaxHistoryPosition;
	TArray<TUniquePtr<FVoxelPlaceableItem>> Items;
};

using FVoxelScopeSetLock = FVoxelData::FVoxelScopeSetLock;
using FVoxelScopeGetLock = FVoxelData::FVoxelScopeGetLock;