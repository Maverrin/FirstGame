// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Runtime/Launch/Resources/Version.h"
#include "VoxelSpawners/VoxelGrassSpawner.h"
#include "VoxelSpawners/VoxelActorSpawner.h"
#include "VoxelSpawners/VoxelActorOctree.h"

class AVoxelWorld;
struct FVoxelChunk;
class FVoxelWorldGeneratorInstance;

struct FVoxelGrassBuffer
{
	FVoxelGrassVariety GrassVariety;
	FStaticMeshInstanceData InstanceBuffer;
	TArray<FClusterNode> ClusterTree;
	int OutOcclusionLayerNum;

	FVoxelGrassBuffer()
#if ENGINE_MINOR_VERSION >= 20
		: InstanceBuffer(false)
#endif
	{

	}
};

struct FVoxelGrassInfoIndex
{
	int GrassId;
	int GrassVariety;

	FVoxelGrassInfoIndex(int GrassId, int GrassVariety)
		: GrassId(GrassId)
		, GrassVariety(GrassVariety)
	{
	}

	inline bool operator==(const FVoxelGrassInfoIndex& Other) const
	{
		return GrassId == Other.GrassId && GrassVariety == Other.GrassVariety;
	}
	inline bool operator!=(const FVoxelGrassInfoIndex& Other) const
	{
		return GrassId != Other.GrassId || GrassVariety != Other.GrassVariety;
	}
};

inline uint32 GetTypeHash(const FVoxelGrassInfoIndex& Index)
{
	return Index.GrassId ^ Index.GrassVariety;
}

typedef TMap<FVoxelGrassInfoIndex, TSet<FIntVector>> FVoxelPreviousGrassInfo;
typedef TMap<FVoxelGrassInfoIndex, TSharedPtr<FVoxelGrassBuffer>> FVoxelGrassBufferMap;

class FVoxelSpawnUtilities
{
public:
	static void SpawnGrass(
		int VoxelSize,
		bool bEnableGrassWhenEditing,
		const FVoxelGrassSpawner_ThreadSafe& Spawner,
		const FVoxelWorldGeneratorInstance& Generator,
		const FVoxelChunk& Chunk,
		const FIntVector& ChunkPosition,
		const FVoxelPreviousGrassInfo& OldPreviousGrassInfo,
		FVoxelGrassBufferMap& GrassBuffers,
		FVoxelPreviousGrassInfo& NewPreviousGrassInfo
	);

	static void SpawnActors(
		int VoxelSize,
		const FVoxelActorSpawner_ThreadSafe& Spawner,
		const FVoxelWorldGeneratorInstance& Generator,
		const FVoxelChunk& Chunk,
		const FIntVector& ChunkPosition,
		TArray<FVoxelActorSpawnInfo>& ActorsSpawnInfo
	);
};

