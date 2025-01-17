// Copyright 2018 Phyronnaz

#include "VoxelData/VoxelDataOctree.h"
#include "VoxelWorldGenerator.h"
#include "VoxelUtilities.h"
#include "Misc/ScopeLock.h"
#include "VoxelData/VoxelData.h"
#include "VoxelPlaceableItems/VoxelPlaceableItem.h"
#include "HAL/Platform.h"

void FVoxelDataOctree::Cache()
{
	check(LOD == 0);

	if (IsCreated() || IsEmpty())
	{
		return; // Already cached
	}
	if (!ItemHolder->IsEmpty())
	{
		// No need to check if it's empty
		Create(true);
		return;
	}
	auto WorldGeneratorState = WorldGenerator->IsEmpty(GetBounds(), 0);
	if (WorldGeneratorState != EVoxelEmptyState::Unknown)
	{
		EmptyState = WorldGeneratorState;
		return;
	}

	TUniquePtr<FVoxelDataCell> TmpCell = MakeUnique<FVoxelDataCell>();

	auto* Values = TmpCell->GetArray<FVoxelValue>();
	auto* Materials = TmpCell->GetArray<FVoxelMaterial>();
	WorldGenerator->GetValuesAndMaterials(Values, Materials, GetBounds(), GetBounds().Min, 0, FIntVector(VOXEL_CELL_SIZE), 0, *ItemHolder);

	bool bAllSame = true;
	bool bAreEmpty = Values[0].IsEmpty();
	for (int Index = 1; Index < VOXEL_CELL_COUNT; Index++)
	{
		if (bAreEmpty != Values[Index].IsEmpty())
		{
			bAllSame = false;
			break;
		}
	}

	if (bAllSame)
	{
		// Don't create & save that info in bIsEmpty
		EmptyState = bAreEmpty ? EVoxelEmptyState::AllEmpty : EVoxelEmptyState::AllFull;
	}
	else
	{
		// Create
		Create(false);
		Cell = MoveTemp(TmpCell);
	}
}

void FVoxelDataOctree::ClearCache()
{
	check(LOD == 0);
	if (IsCreated() && IsCacheOnly())
	{
		Destroy();
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelDataOctree::GetMap(const FIntBox& Bounds, FVoxelMap& OutMap) const
{
	if (Bounds.Intersect(GetBounds()))
	{
		if (IsLeaf())
		{
			if (LOD == 0 && IsCreated())
			{
				OutMap.Add(GetBounds().Min / VOXEL_CELL_SIZE, Cell.Get());
			}
		}
		else
		{
			for (auto& Child : GetChildren())
			{
				Child->GetMap(Bounds, OutMap);
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

EVoxelEmptyState FVoxelDataOctree::IsEmpty(const FIntBox& Bounds, int InLOD) const
{
	const int Step = 1 << InLOD;

	check(Bounds.IsMultipleOf(Step));

	if (IsLeaf())
	{
		check(ItemHolder);

		if (LOD == 0)
		{
			if (IsCreated())
			{
				return EVoxelEmptyState::Unknown;
			}
			if (IsEmpty())
			{
				return EmptyState;
			}
		}
		for (auto& Items : ItemHolder->GetAllItems())
		{
			for (auto& Item : Items)
			{
				if (Item->Bounds.Intersect(Bounds))
				{
					return EVoxelEmptyState::Unknown;
				}
			}
		}
		return WorldGenerator->IsEmpty(Bounds, Step);
	}
	else
	{
		EVoxelEmptyState TmpEmptyState = EVoxelEmptyState::Unknown;
		for (auto& Child : GetChildren())
		{
			if (Child->GetBounds().Intersect(Bounds))
			{
				auto ChildEmptyState = Child->IsEmpty(Bounds, InLOD);
				if (TmpEmptyState == EVoxelEmptyState::Unknown)
				{
					// First init
					TmpEmptyState = ChildEmptyState;
				}
				else if (TmpEmptyState != ChildEmptyState)
				{
					TmpEmptyState = EVoxelEmptyState::Unknown;
				}

				if (TmpEmptyState == EVoxelEmptyState::Unknown)
				{
					break;
				}
			}
		}
		return TmpEmptyState;
	}
}

void FVoxelDataOctree::GetValuesAndMaterials(FVoxelValue Values[], FVoxelMaterial Materials[], const FIntBox& Bounds, const FIntVector& Offset, int InLOD, const FIntVector& ArraySize, int QueryLOD) const
{
	if (!Bounds.Intersect(GetBounds()))
	{
		return;
	}

	const int Step = 1 << InLOD;
	check(Bounds.IsMultipleOf(Step));

	FIntBox LocalBounds = Bounds.Overlap(GetBounds());
	LocalBounds.MakeMultipleOfExclusive(Step);

	if (IsLeaf())
	{
		if (LOD > 0 || !IsCreated())
		{
			WorldGenerator->GetValuesAndMaterials(Values, Materials, LocalBounds, Offset, InLOD, ArraySize, QueryLOD, *ItemHolder);
		}
		else
		{
			auto* CellValues = Cell->GetArray<FVoxelValue>();
			auto* CellMaterials = Cell->GetArray<FVoxelMaterial>();

			for (int Z = LocalBounds.Min.Z; Z < LocalBounds.Max.Z; Z += Step)
			{
				for (int Y = LocalBounds.Min.Y; Y < LocalBounds.Max.Y; Y += Step)
				{
					for (int X = LocalBounds.Min.X; X < LocalBounds.Max.X; X += Step)
					{
						int Index = FVoxelWorldGeneratorInstance::GetIndex(X, Y, Z, Offset, InLOD, ArraySize);
						int CellIndex = IndexFromGlobalCoordinates(X, Y, Z);

						if (Values)
						{
							Values[Index] = CellValues[CellIndex];
						}
						if (Materials)
						{
							Materials[Index] = CellMaterials[CellIndex];
						}
					}
				}
			}
		}
	}
	else
	{
		for (auto& Child : GetChildren())
		{
			if (Child->GetBounds().Intersect(LocalBounds))
			{
				Child->GetValuesAndMaterials(Values, Materials, LocalBounds, Offset, InLOD, ArraySize, QueryLOD);
			}
		}
	}
}

void FVoxelDataOctree::ClearData()
{	
	if (IsLeaf())
	{
		check(ItemHolder);
		ItemHolder = MakeUnique<FVoxelPlaceableItemHolder>();

		if (LOD == 0)
		{
			Cell.Reset();
		}
	}
	else
	{
		check(!ItemHolder);
		for (auto& Child : GetChildren())
		{
			Child->ClearData();
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelDataOctree::Save(FVoxelUncompressedWorldSave& Save)
{
	if (IsLeaf())
	{
		if (LOD == 0 && IsCreated())
		{
			Save.AddChunk(Position,
				Cell->IsBufferDirty<FVoxelValue   >() ? &Cell->GetBuffer<FVoxelValue   >() : nullptr,
				Cell->IsBufferDirty<FVoxelMaterial>() ? &Cell->GetBuffer<FVoxelMaterial>() : nullptr);
		}
	}
	else
	{
		for (auto& Child : GetChildren())
		{
			Child->Save(Save);
		}
	}
}

void FVoxelDataOctree::Load(int& Index, const FVoxelUncompressedWorldSave& Save, TArray<FIntBox>& OutBoundsToUpdate)
{
	if (Index == Save.NumChunks())
	{
		return;
	}

	FIntVector CurrentPosition = Save.GetChunkPosition(Index);
	if (LOD == 0)
	{
		if (CurrentPosition == Position)
		{
			if (!IsCreated())
			{
				Create(false);
			}
			
			bool bValuesAreSet;
			bool bMaterialsAreSet;
			Save.CopyChunkToBuffers(Index, Cell->GetBuffer<FVoxelValue>(), Cell->GetBuffer<FVoxelMaterial>(), bValuesAreSet, bMaterialsAreSet);
			if (bValuesAreSet)
			{
				Cell->SetBufferAsDirty<FVoxelValue>();
			}
			if (bMaterialsAreSet)
			{
				Cell->SetBufferAsDirty<FVoxelMaterial>();
			}

			if (!bValuesAreSet || !bMaterialsAreSet)
			{
				FVoxelValue* Values = bValuesAreSet ? nullptr : Cell->GetArray<FVoxelValue>();
				FVoxelMaterial* Materials = bMaterialsAreSet ? nullptr : Cell->GetArray<FVoxelMaterial>();
				WorldGenerator->GetValuesAndMaterials(Values, Materials, GetBounds(), GetBounds().Min, 0, FIntVector(VOXEL_CELL_SIZE), 0, *ItemHolder);
			}

			Index++;
			OutBoundsToUpdate.Add(GetBounds());
		}
	}
	else
	{
		if (GetBounds().IsInside(CurrentPosition))
		{
			if (IsLeaf())
			{
				CreateChildren();
			}
			for (auto& Child : GetChildren())
			{
				Child->Load(Index, Save, OutBoundsToUpdate);
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

bool FVoxelDataOctree::BeginSet(const FIntBox& Box, TArray<FVoxelId>& Ids, int MicroSeconds)
{
	if (GetBounds().Intersect(Box))
	{
#if !PLATFORM_ANDROID
		if (!MainLock.try_lock_for(std::chrono::microseconds(MicroSeconds)))
		{
			TransactionLock.unlock();
			return false;
		}		
#else
        MainLock.lock();
#endif
		MainLock.unlock();


		if (IsLeaf())
		{
			// Lock
			MainLock.lock();
			Ids.Add(Id);

			// Unlock transactions
			TransactionLock.unlock();
			return true;
		}
		else
		{
			// First lock childs
			for (auto& Child : GetChildren())
			{
				Child->LockTransactions();
			}
			// Then unlock this
			TransactionLock.unlock();
			
			// Finally propagate to childs
			for (int I = 0; I < 8; I++)
			{
				auto& Child = GetChildren()[I];

				if (!Child->BeginSet(Box, Ids, MicroSeconds))
				{
					for (int J = I + 1; J < 8; J++)
					{
						GetChildren()[J]->TransactionLock.unlock();
					}
					return false;
				}
			}

			return true;
		}
	}
	else
	{		
		TransactionLock.unlock();
		return true;
	}
}

void FVoxelDataOctree::EndSet(TArray<FVoxelId>& Ids)
{
	if (Ids.Num() > 0)
	{
		if (Ids.Last() == Id)
		{
			Ids.Pop(false);
			MainLock.unlock();
		}

		if (Ids.Num() > 0)
		{
			if (IsIdChild(Ids.Last()))
			{
				for (auto& Child : GetChildren())
				{
					Child->EndSet(Ids);
				}
			}
		}
	}
}

bool FVoxelDataOctree::BeginGet(const FIntBox& Box, TArray<FVoxelId>& Ids, int MicroSeconds)
{
	if (GetBounds().Intersect(Box))
	{
#if !PLATFORM_ANDROID
		if (!MainLock.try_lock_shared_for(std::chrono::microseconds(MicroSeconds)))
		{
			TransactionLock.unlock();
			return false;
		}
#else
        MainLock.lock_shared();
#endif
		MainLock.unlock_shared();


		if (IsLeaf())
		{
			// Lock
			MainLock.lock_shared();
			Ids.Add(Id);

			// Unlock transactions
			TransactionLock.unlock();
			return true;
		}
		else
		{
			// First lock childs
			for (auto& Child : GetChildren())
			{
				Child->LockTransactions();
			}
			// Then unlock this
			TransactionLock.unlock();

			// Finally propagate to childs
			for (int I = 0; I < 8; I++)
			{
				auto& Child = GetChildren()[I];

				if (!Child->BeginGet(Box, Ids, MicroSeconds))
				{
					for (int J = I + 1; J < 8; J++)
					{
						GetChildren()[J]->TransactionLock.unlock();
					}
					return false;
				}
			}

			return true;
		}
	}
	else
	{
		TransactionLock.unlock();
		return true;
	}
}

void FVoxelDataOctree::EndGet(TArray<FVoxelId>& Ids)
{
	if (Ids.Num() > 0)
	{
		if (Ids.Last() == Id)
		{
			Ids.Pop(false);
			MainLock.unlock_shared();
		}

		if (Ids.Num() > 0)
		{
			if (IsIdChild(Ids.Last()))
			{
				for (auto& Child : GetChildren())
				{
					Child->EndGet(Ids);
				}
			}
		}
	}
}

void FVoxelDataOctree::LockTransactions()
{
	TransactionLock.lock();
}

void FVoxelDataOctree::CreateChildren()
{
	TVoxelOctree::CreateChildren();

	const auto& AllItems = ItemHolder->GetAllItems();
	for (auto& Child : GetChildren())
	{
		for (uint32 ItemId = 0; ItemId < (uint32)AllItems.Num(); ItemId++)
		{
			for (auto Item : AllItems[ItemId])
			{
				if (Item->Bounds.Intersect(Child->GetBounds()))
				{
					Child->ItemHolder->AddItem(ItemId, Item);
				}
			}
		}
	}
	ItemHolder.Reset();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelDataOctree::Create(bool bInitFromWorldGenerator)
{
	check(LOD == 0 && !IsCreated());

	Cell = MakeUnique<FVoxelDataCell>();
	if (bEnableMultiplayer)
	{
		MultiplayerCell = MakeUnique<FVoxelDataCellMultiplayer>();
	}
	if (bEnableUndoRedo)
	{
		UndoRedoCell = MakeUnique<FVoxelDataCellUndoRedo>();
	}

	if (bInitFromWorldGenerator)
	{
		auto* Values = Cell->GetArray<FVoxelValue>();
		auto* Materials = Cell->GetArray<FVoxelMaterial>();
		WorldGenerator->GetValuesAndMaterials(Values, Materials, GetBounds(), GetBounds().Min, 0, FIntVector(VOXEL_CELL_SIZE), 0, *ItemHolder);
	}
}

void FVoxelDataOctree::Destroy()
{
	check(LOD == 0 && IsCreated());
	Cell.Reset();
	MultiplayerCell.Reset();
	UndoRedoCell.Reset();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelDataOctree::AddChunksToDiffQueues(TArray<TVoxelChunkDiff<FVoxelValue>>& ValueDiffQueue, TArray<TVoxelChunkDiff<FVoxelMaterial>>& MaterialDiffQueue)
{
	if (IsLeaf())
	{
		if (LOD == 0 && IsCreated())
		{
			if (MultiplayerCell->IsNetworkDirty<FVoxelValue>())
			{
				int Index = ValueDiffQueue.Emplace(Position);
				auto& Diff = ValueDiffQueue[Index];
				MultiplayerCell->AddToDiffQueueAndReset(Cell.Get(), Diff.Diffs);
			}
			if (MultiplayerCell->IsNetworkDirty<FVoxelMaterial>())
			{
				int Index = MaterialDiffQueue.Emplace(Position);
				auto& Diff = MaterialDiffQueue[Index];
				MultiplayerCell->AddToDiffQueueAndReset(Cell.Get(),Diff.Diffs);
			}
		}
	}
	else
	{
		for (auto& Child : GetChildren())
		{
			Child->AddChunksToDiffQueues(ValueDiffQueue, MaterialDiffQueue);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelDataOctree::SaveFrame(int HistoryPosition)
{	
	if (IsLeaf())
	{
		if (LOD == 0 && IsCreated())
		{
			UndoRedoCell->SaveFrame(HistoryPosition);
		}
	}
	else
	{
		for (auto& Child : GetChildren())
		{
			Child->SaveFrame(HistoryPosition);
		}
	}
}

void FVoxelDataOctree::Undo(int HistoryPosition, TArray<FIntBox>& OutBoundsToUpdate)
{
	if (IsLeaf())
	{
		if (LOD == 0 && IsCreated())
		{
			if (UndoRedoCell->TryUndo(Cell.Get(), HistoryPosition))
			{
				OutBoundsToUpdate.Add(GetBounds());
			}
		}
	}
	else
	{
		for (auto& Child : GetChildren())
		{
			Child->Undo(HistoryPosition, OutBoundsToUpdate);
		}
	}
}

void FVoxelDataOctree::Redo(int HistoryPosition, TArray<FIntBox>& OutBoundsToUpdate)
{	
	if (IsLeaf())
	{
		if (LOD == 0 && IsCreated())
		{
			if (UndoRedoCell->TryRedo(Cell.Get(), HistoryPosition))
			{
				OutBoundsToUpdate.Add(GetBounds());
			}
		}
	}
	else
	{
		for (auto& Child : GetChildren())
		{
			Child->Redo(HistoryPosition, OutBoundsToUpdate);
		}
	}
}

void FVoxelDataOctree::ClearFrames()
{	
	if (IsLeaf())
	{
		if (LOD == 0 && IsCreated())
		{
			UndoRedoCell->ClearFrames();
		}
	}
	else
	{
		for (auto& Child : GetChildren())
		{
			Child->ClearFrames();
		}
	}
}

bool FVoxelDataOctree::CheckIfCurrentFrameIsEmpty() const
{
	if (IsLeaf())
	{
		if (LOD == 0 && IsCreated())
		{
			return UndoRedoCell->IsCurrentFrameEmpty();
		}
		return true;
	}
	else
	{
		bool bSuccess = true;
		for (auto& Child : GetChildren())
		{
			bSuccess = bSuccess && Child->CheckIfCurrentFrameIsEmpty();
		}
		return bSuccess;
	}
}