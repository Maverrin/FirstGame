// Copyright 2018 Phyronnaz

#include "VoxelRender/VoxelPolygonizerAsyncWork.h"
#include "VoxelLogStatDefinitions.h"
#include "Async/Async.h"
#include "Misc/ScopeLock.h"
#include "Renderers/VoxelRenderChunk.h"
#include "VoxelWorld.h"
#include "VoxelData/VoxelData.h"
#include "VoxelDebug/VoxelCrashReporter.h"

FVoxelPolygonizerAsyncWorkBase::FVoxelPolygonizerAsyncWorkBase(
	int LOD,
	uint64 Distance,
	const FIntVector& ChunkPosition,
	AVoxelWorld* World, 
	TSharedRef<FVoxelData, ESPMode::ThreadSafe> Data,
	FVoxelRenderChunk* ChunkCallback)
	: FVoxelAsyncWork(ChunkCallback)
	, LOD(LOD)
	, Distance(Distance)
	, ChunkPosition(ChunkPosition)
	, Data(Data)
	, VoxelSize(World->GetVoxelSize())
	, NormalConfig(World->GetNormalConfig())
	, MaterialConfig(World->GetMaterialConfig())
	, UVConfig(World->GetUVConfig())
	, MeshParameters(World->IsTessellationEnabled(LOD), World->GetOptimizeIndices())
{
	Stats.SetLOD(LOD);
	Stats.StartStat("Waiting In Thread Queue");
}

void FVoxelPolygonizerAsyncWorkBase::ShowError()
{
	AsyncTask(ENamedThreads::GameThread, []() { FVoxelCrashReporter::ShowWorldGeneratorError(); });
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

FVoxelPolygonizerAsyncWork::FVoxelPolygonizerAsyncWork(
	int LOD,
	uint64 Distance,
	const FIntVector& ChunkPosition,
	AVoxelWorld* World,
	TSharedRef<FVoxelData, ESPMode::ThreadSafe> Data,
	bool bComputeGrass,
	bool bComputeActors,
	const FVoxelPreviousGrassInfo& OldPreviousGrassInfo,
	FVoxelRenderChunk* ChunkCallback)
	: FVoxelPolygonizerAsyncWorkBase(LOD, Distance, ChunkPosition, World, Data, ChunkCallback)
	, bComputeGrass(bComputeGrass)
	, bComputeActors(bComputeActors)
	, OldPreviousGrassInfo(OldPreviousGrassInfo)
	, GrassSpawner(World->GetGrassSpawnerThreadSafe())
	, ActorSpawner(World->GetActorSpawnerThreadSafe())
	, bEnableGrassWhenEditing(World->GetEnableGrassWhenEditing() || World->IsEditor())
{
}

void FVoxelPolygonizerAsyncWork::BuildGrassAndActors()
{
	if (IsCanceled()) { return; }

	// Grass
	if (bComputeGrass && GrassSpawner.IsValid())
	{
		FVoxelSpawnUtilities::SpawnGrass(VoxelSize, bEnableGrassWhenEditing, *GrassSpawner.Get(), Data->WorldGenerator.Get(), *Chunk, ChunkPosition, OldPreviousGrassInfo, GrassBuffers, NewPreviousGrassInfo);
	}

	if (IsCanceled()) { return; }

	// Actors
	if (bComputeActors && ActorSpawner.IsValid())
	{
		FVoxelSpawnUtilities::SpawnActors(VoxelSize, *ActorSpawner.Get(), Data->WorldGenerator.Get(), *Chunk, ChunkPosition, ActorsToSpawn);
	}
}

