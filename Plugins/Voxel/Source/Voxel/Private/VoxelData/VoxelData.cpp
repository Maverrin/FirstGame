// Copyright 2018 Phyronnaz

#include "VoxelData/VoxelData.h"
#include "VoxelLogStatDefinitions.h"
#include "VoxelData/VoxelDataOctree.h"
#include "VoxelSave.h"
#include "VoxelDiff.h"
#include "VoxelWorldGenerator.h"
#include "Algo/Reverse.h"
#include "Misc/ScopeLock.h"

DECLARE_CYCLE_STAT(TEXT("FVoxelData::LoadFromDiffQueues"), STAT_VoxelData_LoadFromDiffQueues, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("FVoxelData::LoadFromDiffQueues::BeginSet"), STAT_VoxelData_LoadFromDiffQueues_BeginSet, STATGROUP_Voxel);

void FVoxelData::BeginSet(const FIntBox& Box, TArray<FVoxelId>& OutOctrees)
{
	OutOctrees.Empty();

	Octree->LockTransactions();
	Octree->BeginSet(Box, OutOctrees, 1e9);

	Algo::Reverse(OutOctrees);
}

bool FVoxelData::TryBeginSet(const FIntBox& Box, int MicroSeconds, TArray<FVoxelId>& OutOctrees)
{
	OutOctrees.Empty();

	Octree->LockTransactions();

	bool bSuccess = Octree->BeginSet(Box, OutOctrees, MicroSeconds);

	Algo::Reverse(OutOctrees);

	if (!bSuccess)
	{
		EndSet(OutOctrees);
	}

	return bSuccess;
}

void FVoxelData::EndSet(TArray<FVoxelId>& LockedOctrees)
{
	Octree->EndSet(LockedOctrees);
	check(LockedOctrees.Num() == 0);
}

void FVoxelData::BeginGet(const FIntBox& Box, TArray<FVoxelId>& OutOctrees)
{
	OutOctrees.Empty();

	Octree->LockTransactions();
	Octree->BeginGet(Box, OutOctrees, 1e9);

	Algo::Reverse(OutOctrees);
}

bool FVoxelData::TryBeginGet(const FIntBox& Box, int MicroSeconds, TArray<FVoxelId>& OutOctrees)
{
	OutOctrees.Empty();

	Octree->LockTransactions();

	bool bSuccess = Octree->BeginGet(Box, OutOctrees, MicroSeconds);

	Algo::Reverse(OutOctrees);

	if (!bSuccess)
	{
		EndGet(OutOctrees);
	}

	return bSuccess;
}

void FVoxelData::EndGet(TArray<FVoxelId>& LockedOctrees)
{
	Octree->EndGet(LockedOctrees);
	check(LockedOctrees.Num() == 0);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelData::GetValuesAndMaterials(FVoxelValue Values[], FVoxelMaterial Materials[], const FIntBox& Bounds, const FIntVector& Offset, int InLOD, const FIntVector& ArraySize, int QueryLOD) const
{
	const int Step = 1 << InLOD;

	check(Bounds.IsMultipleOf(Step));
	check(GetBounds().IsMultipleOf(Step));

	Octree->GetValuesAndMaterials(Values, Materials, Bounds, Offset, InLOD, ArraySize, QueryLOD);

	if (!GetBounds().Contains(Bounds))
	{
		TArray<FIntBox> BoundsOutsideWorld;
		FIntBox::GetRemainingBoxes(Bounds, GetBounds(), BoundsOutsideWorld);

		for (auto& LocalBounds : BoundsOutsideWorld)
		{
			check(LocalBounds.IsMultipleOf(Step));
			WorldGenerator->GetValuesAndMaterials(Values, Materials, LocalBounds, Offset, InLOD, ArraySize, QueryLOD);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelData::GetSave(FVoxelUncompressedWorldSave& OutSave)
{
	FVoxelScopeGetLock Lock(this, FIntBox::Infinite);

	OutSave.Init(Depth);
	Octree->Save(OutSave);
	OutSave.Save();
}

void FVoxelData::LoadFromSave(const FVoxelUncompressedWorldSave& Save, TArray<FIntBox>& OutBoundsToUpdate)
{
	FVoxelScopeSetLock Lock(this, FIntBox::Infinite);

	Octree->GetLeavesBounds(OutBoundsToUpdate, 0);
	Octree->ClearData();
	if (bEnableUndoRedo)
	{
		HistoryPosition = 0;
		MaxHistoryPosition = 0;
	}

	int Index = 0;
	Octree->Load(Index, Save, OutBoundsToUpdate);

	check(Index == Save.NumChunks() || Save.GetDepth() > Depth);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelData::GetDiffQueues(TArray<TVoxelChunkDiff<FVoxelValue>>& OutValueDiffQueue, TArray<TVoxelChunkDiff<FVoxelMaterial>>& OutMaterialDiffQueue)
{
	FVoxelScopeGetLock Lock(this, FIntBox::Infinite);
	Octree->AddChunksToDiffQueues(OutValueDiffQueue, OutMaterialDiffQueue);
}

template<typename T>
inline void LoadFromDiffQueueImpl(FVoxelData* Data, TArray<TVoxelChunkDiff<T>>& Queue, TArray<FIntBox>& OutModifiedBounds)
{
	SCOPE_CYCLE_COUNTER(STAT_VoxelData_LoadFromDiffQueues);

	for (auto& Diff : Queue)
	{
		auto Bounds = FIntBox(Diff.Position - FIntVector(VOXEL_CELL_SIZE / 2), Diff.Position + FIntVector(VOXEL_CELL_SIZE / 2));
		TArray<FVoxelId> Octrees;
		{
			SCOPE_CYCLE_COUNTER(STAT_VoxelData_LoadFromDiffQueues_BeginSet);
			Data->BeginSet(Bounds, Octrees);
		}
		OutModifiedBounds.Emplace(Data->GetOctree()->GetLeaf(Diff.Position)->LoadVoxelDiff(Diff));
		Data->EndSet(Octrees);
	}
}

void FVoxelData::LoadFromDiffQueues(TArray<TVoxelChunkDiff<FVoxelValue>>& ValueDiffQueue, TArray<TVoxelChunkDiff<FVoxelMaterial>>& MaterialDiffQueue, TArray<FIntBox>& OutModifiedBounds)
{
	LoadFromDiffQueueImpl(this, ValueDiffQueue, OutModifiedBounds);
	LoadFromDiffQueueImpl(this, MaterialDiffQueue, OutModifiedBounds);
}
