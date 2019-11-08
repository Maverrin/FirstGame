// Copyright 2018 Phyronnaz

#pragma once


#include "CoreMinimal.h"
#include "VoxelOctree.h"
#include "VoxelGlobals.h"

#define ACTOROCTREE_LOD_DIFF 1

class AVoxelWorld;
class AVoxelActor;
class UStaticMesh;
class UHierarchicalInstancedStaticMeshComponent;
class FVoxelActorOctree;
class UVoxelInvokerComponent;
struct FVoxelActorConfig;

struct FVoxelActorSpawnInfo
{
	const FVoxelActorConfig* Config;
	FTransform LocalTransform;

	FVoxelActorSpawnInfo(const FVoxelActorConfig* Config, FTransform&& LocalTransform)
		: Config(Config)
		, LocalTransform(LocalTransform)
	{

	}
};

///////////////////////////////////////////////////////////////////////////////

class FVoxelActorComputedChunksOctree : public TVoxelOctree<FVoxelActorComputedChunksOctree, CHUNK_SIZE>
{
public:
	FVoxelActorComputedChunksOctree(uint8 LOD);
	FVoxelActorComputedChunksOctree(FVoxelActorComputedChunksOctree* Parent, uint8 ChildIndex);

	void SetAsComputed(const FIntBox& Box);
	bool IsPartiallyComputed(const FIntBox& Box) const;

private:
	bool bComputed = false;
};

///////////////////////////////////////////////////////////////////////////////

struct FHISMHolder
{
public:
	AVoxelWorld* const World;
	const int Step;

	FHISMHolder(AVoxelWorld* World, int Step)
		: World(World)
		, Step(Step)
	{

	}

	UHierarchicalInstancedStaticMeshComponent* GetHISM(const FIntVector& Position, const FVoxelActorConfig* Config);
	void Cull(const TArray<FIntVector>& CameraPositions);
	void RecomputeMeshPositions();
	
	const FVoxelActorConfig* GetActorConfigFromHISM(UHierarchicalInstancedStaticMeshComponent* Component);

private:
	TMap<FIntVector, TMap<const FVoxelActorConfig*, UHierarchicalInstancedStaticMeshComponent*>> Map;

	TArray<FIntVector> LastCameraPositions;

	void CullImpl(const FIntVector& Position);
};

class FVoxelActorOctreeManager
{
public:
	FVoxelActorOctreeManager(AVoxelWorld* World);
	
public:
	void AddActorInfos(const TArray<FVoxelActorSpawnInfo>& ActorInfos);
	void Cull();
	void RecomputeMeshPositions();

public:
	void EnableFloatingActorsInArea(const FIntBox& Box, TArray<AVoxelActor*>& OutActors);
	void EnableActorsInArea(const FIntBox& Box, TArray<AVoxelActor*>& OutActors);
	AVoxelActor* EnableInstanceInArea(UHierarchicalInstancedStaticMeshComponent* Component, const FIntBox& Box, int InstanceIndex);
	void RemoveInstance(UHierarchicalInstancedStaticMeshComponent* Component, FIntBox Box, int InstanceIndex);
	
	UClass* GetActorClassFromHISM(UHierarchicalInstancedStaticMeshComponent* Component);

private:
	AVoxelWorld* const World;
	TUniquePtr<FVoxelActorOctree> const Octree;
	FHISMHolder HISMHolder;
	TArray<TWeakObjectPtr<UVoxelInvokerComponent>> Invokers;

	AVoxelActor* EnableActor(struct FVoxelActorInstanceInfo* Info, bool bOnlyIfOverlapping, bool bSpawnActor, bool bUseHISMTransform = true);
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

struct FVoxelActorOctreeInstanceRef
{
	FVoxelActorOctree* Octree = nullptr;
	int Index = -1;
};

struct FVoxelActorInstanceInfo
{
	const FVoxelActorConfig* Config = nullptr;
	FTransform Transform;
	FIntVector RoundedPosition;
	int InstanceIndex = -1;

	FVoxelActorInstanceInfo() = default;
	FVoxelActorInstanceInfo(const FVoxelActorConfig* Config, FTransform&& Transform, FIntVector&& RoundedPosition)
		: Config(Config)
		, Transform(Transform)
		, RoundedPosition(RoundedPosition)
	{
	}
};

class FVoxelActorOctree : public TVoxelOctree<FVoxelActorOctree, CHUNK_SIZE << ACTOROCTREE_LOD_DIFF>
{
public:
	FVoxelActorOctree(uint8 LOD, FVoxelActorOctreeManager* Manager)
		: TVoxelOctree(LOD)
		, Manager(Manager)
	{
	}
	FVoxelActorOctree(FVoxelActorOctree* Parent, uint8 ChildIndex)
		: TVoxelOctree(Parent, ChildIndex)
		, Manager(Parent->Manager)
	{
	}

	void AddInstance(const FVoxelActorInstanceInfo& InstanceInfo, FVoxelActorOctreeInstanceRef& OutInstanceRef);
	void GetActorsInBox(const FIntBox& Box, TArray<FVoxelActorInstanceInfo*>& OutActors);

	inline static FVoxelActorInstanceInfo& GetInfoFromRef(const FVoxelActorOctreeInstanceRef& Ref)
	{
		return Ref.Octree->InstanceInfos[Ref.Index];
	}

private:
	FVoxelActorOctreeManager* const Manager;
	TArray<FVoxelActorInstanceInfo> InstanceInfos;
};

