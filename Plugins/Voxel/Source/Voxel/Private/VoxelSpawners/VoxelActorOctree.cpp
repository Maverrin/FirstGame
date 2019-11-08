// Copyright 2018 Phyronnaz

#include "VoxelSpawners/VoxelActorOctree.h"
#include "VoxelLogStatDefinitions.h"
#include "VoxelGlobals.h"
#include "VoxelSpawners/VoxelActor.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Logging/MessageLog.h"
#include "VoxelUtilities.h"
#include "VoxelWorld.h"
#include "VoxelComponents/VoxelInvokerComponent.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Engine/StaticMesh.h"
#include "PhysicsEngine/BodySetup.h"

DECLARE_CYCLE_STAT(TEXT("FVoxelActorOctreeManager::AddActorInfos"), STAT_VoxelActorOctreeManager_AddActorInfos, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("FVoxelActorOctreeManager::Cull"), STAT_VoxelActorOctreeManager_Cull, STATGROUP_Voxel);

FVoxelActorComputedChunksOctree::FVoxelActorComputedChunksOctree(uint8 LOD)
	: TVoxelOctree(LOD)
{

}

FVoxelActorComputedChunksOctree::FVoxelActorComputedChunksOctree(FVoxelActorComputedChunksOctree* Parent, uint8 ChildIndex)
	: TVoxelOctree(Parent, ChildIndex)
{

}

///////////////////////////////////////////////////////////////////////////////

void FVoxelActorComputedChunksOctree::SetAsComputed(const FIntBox& Box)
{
	if (!bComputed && GetBounds().Intersect(Box))
	{
		if (Box.Contains(GetBounds()) || LOD == 0)
		{
			bComputed = true;
		}
		else
		{
			if (IsLeaf())
			{
				CreateChildren();
			}
			bool bAllComputed = true;
			for (auto& Child : GetChildren())
			{
				Child->SetAsComputed(Box);
				bAllComputed &= Child->bComputed;
			}
			if (bAllComputed)
			{
				DestroyChildren();
				bComputed = true;
			}
		}
	}
}

bool FVoxelActorComputedChunksOctree::IsPartiallyComputed(const FIntBox& Box) const
{
	if (GetBounds().Intersect(Box))
	{
		if (bComputed)
		{
			return true;
		}
		else
		{
			for (auto& Child : GetChildren())
			{
				if (Child->IsPartiallyComputed(Box))
				{
					return true;
				}
			}
			return false;
		}
	}
	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

UHierarchicalInstancedStaticMeshComponent* FHISMHolder::GetHISM(const FIntVector& Position, const FVoxelActorConfig* Config)
{	
	FIntVector NewPosition;
	NewPosition.X = FMath::FloorToInt(Position.X / float(Step)) * Step;
	NewPosition.Y = FMath::FloorToInt(Position.Y / float(Step)) * Step;
	NewPosition.Z = FMath::FloorToInt(Position.Z / float(Step)) * Step;

	auto& ConfigMap = Map.FindOrAdd(NewPosition);
	auto*& HISM = ConfigMap.FindOrAdd(Config);

	if (!HISM)
	{
		HISM = NewObject<UHierarchicalInstancedStaticMeshComponent>(World, Config->HISMTemplate ? (UClass*)Config->HISMTemplate : UHierarchicalInstancedStaticMeshComponent::StaticClass(), NAME_None, RF_Transient);
		HISM->SetRelativeLocation(World->GetChunkRelativePosition(NewPosition));
		HISM->SetupAttachment(World->GetRootComponent(), NAME_None);
		HISM->Mobility = EComponentMobility::Movable;
		HISM->InstanceStartCullDistance = Config->HISMStartCullDistance;
		HISM->InstanceEndCullDistance = Config->HISMEndCullDistance;
		auto* Mesh = Config->GetMesh();
		if (Mesh)
		{
			HISM->SetStaticMesh(Mesh);
			HISM->BodyInstance = Mesh->BodySetup->DefaultInstance;
		}
		HISM->RegisterComponent();
		CullImpl(NewPosition);
	}

	return HISM;
}

void FHISMHolder::Cull(const TArray<FIntVector>& CameraPositions)
{
	LastCameraPositions = CameraPositions;

	for (auto& It : Map)
	{
		CullImpl(It.Key);
	}
}

void FHISMHolder::RecomputeMeshPositions()
{
	for (auto& PositionsIt : Map)
	{
		for (auto& ClassIt : PositionsIt.Value)
		{
			ClassIt.Value->SetRelativeLocation(World->GetChunkRelativePosition(PositionsIt.Key));
		}
	}
}

const FVoxelActorConfig* FHISMHolder::GetActorConfigFromHISM(UHierarchicalInstancedStaticMeshComponent* Component)
{
	for (auto& PositionsIt : Map)
	{
		for (auto& ClassIt : PositionsIt.Value)
		{
			if (ClassIt.Value == Component)
			{
				return ClassIt.Key;
			}
		}
	}
	return nullptr;
}

void FHISMHolder::CullImpl(const FIntVector& Position)
{
	FIntBox Box(Position, Position + FIntVector(Step));

	uint32 SquaredDistance = LastCameraPositions.Num() == 0 ? MAX_uint32 : Box.ComputeSquaredDistanceFromBoxToPoint(LastCameraPositions[0]);
	for (int Index = 1; Index < LastCameraPositions.Num(); Index++)
	{
		SquaredDistance = FMath::Min(SquaredDistance, Box.ComputeSquaredDistanceFromBoxToPoint(LastCameraPositions[Index]));
	}

	float VoxelSize = World->GetVoxelSize();
	int DistanceBetweenHISM = World->GetDistanceBetweenActorHISMInVoxels();
	auto& PositionMap = Map.FindChecked(Position);
	for (auto& It : PositionMap)
	{
		auto* Config = It.Key;
		auto* HISM = It.Value;
		uint64 SquaredActorDistance = FMath::Square<uint64>(FMath::CeilToInt(Config->HISMEndCullDistance / VoxelSize) + 2 * DistanceBetweenHISM);
		HISM->SetHiddenInGame(SquaredDistance >= SquaredActorDistance);
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

FVoxelActorOctreeManager::FVoxelActorOctreeManager(AVoxelWorld* World) 
	: World(World)
	, Octree(MakeUnique<FVoxelActorOctree>(World->GetOctreeDepth() - ACTOROCTREE_LOD_DIFF, this))
	, HISMHolder(World, World->GetDistanceBetweenActorHISMInVoxels())
{
}

///////////////////////////////////////////////////////////////////////////////

void FVoxelActorOctreeManager::AddActorInfos(const TArray<FVoxelActorSpawnInfo>& ActorInfos)
{
	SCOPE_CYCLE_COUNTER(STAT_VoxelActorOctreeManager_AddActorInfos);

	auto* Data = World->GetData();

	TMap<UHierarchicalInstancedStaticMeshComponent*, TArray<FVoxelActorOctreeInstanceRef>> SortedInstances;
	for (auto& Info : ActorInfos)
	{
		auto* Config = Info.Config;
		check(Config);
		FVoxelActorInstanceInfo InstanceInfo(Config, Config->GetTransform() * FTransform(Info.LocalTransform.GetRotation(), World->LocalToGlobalFloat(Info.LocalTransform.GetLocation()), Info.LocalTransform.GetScale3D()), FVoxelIntVector::RoundToInt(Info.LocalTransform.GetLocation()));
		if (Config->bSpawnActorAndNotImposterMesh)
		{
			EnableActor(&InstanceInfo, false, true, false);
		}
		else
		{
			if (Octree->IsInOctree(InstanceInfo.RoundedPosition))
			{
				auto HISM = HISMHolder.GetHISM(InstanceInfo.RoundedPosition, InstanceInfo.Config);
				InstanceInfo.Transform.SetLocation(InstanceInfo.Transform.GetLocation() - HISM->GetComponentLocation());

				FVoxelActorOctreeInstanceRef InstanceRef;
				Octree->AddInstance(InstanceInfo, InstanceRef);
				check(InstanceRef.Octree && InstanceRef.Index >= 0);
				
				SortedInstances.FindOrAdd(HISM).Add(InstanceRef);
			}
		}
	}

	for (auto& It : SortedInstances)
	{
		auto& HISM = It.Key;
		auto& InstancesArray = It.Value;
		
#if ENGINE_MINOR_VERSION >= 20
		HISM->PreAllocateInstancesMemory(InstancesArray.Num());
#endif

		for (auto InstanceRef : InstancesArray)
		{
			auto& Info = FVoxelActorOctree::GetInfoFromRef(InstanceRef);
			Info.InstanceIndex = HISM->AddInstance(Info.Transform);
		}
	}
}

void FVoxelActorOctreeManager::Cull()
{
	SCOPE_CYCLE_COUNTER(STAT_VoxelActorOctreeManager_Cull);

	TArray<FIntVector> CameraPositions;
	for (auto& Invoker : World->GetInvokers())
	{
		if (Invoker.IsValid() && Invoker->IsLocalInvoker())
		{
			CameraPositions.Add(World->GlobalToLocal(Invoker->GetPosition()));
		}
	}
	HISMHolder.Cull(CameraPositions);
}

void FVoxelActorOctreeManager::RecomputeMeshPositions()
{
	HISMHolder.RecomputeMeshPositions();
}

///////////////////////////////////////////////////////////////////////////////

void FVoxelActorOctreeManager::EnableFloatingActorsInArea(const FIntBox& Box, TArray<AVoxelActor*>& OutActors)
{
	TArray<FVoxelActorInstanceInfo*> Infos;
	Octree->GetActorsInBox(Box, Infos);
	for (auto& Info : Infos)
	{
		AVoxelActor* NewActor = EnableActor(Info, true, true);
		if(NewActor)
		{
			OutActors.Add(NewActor);
		}
	}
}

void FVoxelActorOctreeManager::EnableActorsInArea(const FIntBox& Box, TArray<AVoxelActor*>& OutActors)
{	
	TArray<FVoxelActorInstanceInfo*> Infos;
	Octree->GetActorsInBox(Box, Infos);
	for (auto& Info : Infos)
	{
		AVoxelActor* NewActor = EnableActor(Info, false, true);
		check(NewActor);
		OutActors.Add(NewActor);
	}
}

AVoxelActor* FVoxelActorOctreeManager::EnableInstanceInArea(UHierarchicalInstancedStaticMeshComponent* Component, const FIntBox& Box, int InstanceIndex)
{
	TArray<FVoxelActorInstanceInfo*> Infos;
	Octree->GetActorsInBox(Box, Infos);
	for (auto& Info : Infos)
	{
		if (Info->InstanceIndex == InstanceIndex && HISMHolder.GetHISM(Info->RoundedPosition, Info->Config) == Component)
		{
			AVoxelActor* NewActor = EnableActor(Info, false, true);
			check(NewActor);
			return NewActor;
		}
	}

	return nullptr;
}

void FVoxelActorOctreeManager::RemoveInstance(UHierarchicalInstancedStaticMeshComponent* Component, FIntBox Box, int InstanceIndex)
{
	TArray<FVoxelActorInstanceInfo*> Infos;
	Octree->GetActorsInBox(Box, Infos);
	for (auto& Info : Infos)
	{
		if (Info->InstanceIndex == InstanceIndex && HISMHolder.GetHISM(Info->RoundedPosition, Info->Config) == Component)
		{
			EnableActor(Info, false, false);
			return;
		}
	}
}

UClass* FVoxelActorOctreeManager::GetActorClassFromHISM(UHierarchicalInstancedStaticMeshComponent* Component)
{
	auto* Config = HISMHolder.GetActorConfigFromHISM(Component);
	if (!Config->bUseActorClass)
	{
		FMessageLog("PIE").Warning(FText::FromString("GetActorClassFromHISM: ActorConfig is using mesh and not actor class!"));
	}
	return Config->Actor;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

AVoxelActor* FVoxelActorOctreeManager::EnableActor(FVoxelActorInstanceInfo* Info, bool bOnlyIfOverlapping, bool bSpawnActor, bool bUseHISMTransform)
{
	auto* Config = Info->Config;
	UClass* ActorClass = Config->Actor;
	auto* HISM = HISMHolder.GetHISM(Info->RoundedPosition, Config);
	FTransform Transform;
	if (bUseHISMTransform)
	{
		Transform = Info->Transform * HISM->GetRelativeTransform() * World->GetTransform();
	}
	else
	{
		Transform = Info->Transform * World->GetTransform();
	}

	if (Config->bUseActorClass && ActorClass && (!bOnlyIfOverlapping || !AVoxelActor::IsOverlappingVoxelWorld(ActorClass, World, Transform, Config->bOnlyCheckVoxelsAtPositionForOverlap)))
	{
		const int Index = Info->InstanceIndex;
		if (Index >= 0)
		{
			Info->InstanceIndex = -1;
			HISM->UpdateInstanceTransform(Index, FTransform(FRotator::ZeroRotator, Info->Transform.GetLocation(), FVector::ZeroVector), false, true, true);
		}

		if (bSpawnActor)
		{
			AVoxelActor* NewActor = World->GetWorld()->SpawnActor<AVoxelActor>(ActorClass, Transform);
			NewActor->SetActorTransform(Transform);
			return NewActor;
		}
	}
	return nullptr;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelActorOctree::AddInstance(const FVoxelActorInstanceInfo& InstanceInfo, FVoxelActorOctreeInstanceRef& OutInstanceRef)
{
	if (LOD == 0)
	{
		int Index = InstanceInfos.Add(InstanceInfo);
		OutInstanceRef.Octree = this;
		OutInstanceRef.Index = Index;
	}
	else
	{
		if (IsLeaf())
		{
			CreateChildren();
		}
		for (auto& Child : GetChildren())
		{
			if (Child->GetBounds().IsInside(InstanceInfo.RoundedPosition))
			{
				Child->AddInstance(InstanceInfo, OutInstanceRef);
				break;
			}
		}
	}
}

void FVoxelActorOctree::GetActorsInBox(const FIntBox& Box, TArray<FVoxelActorInstanceInfo*>& OutActors)
{
	if (Box.Intersect(GetBounds()))
	{
		if (IsLeaf())
		{
			if (LOD == 0)
			{
				for (auto& Actor : InstanceInfos)
				{
					if (Actor.InstanceIndex >= 0 && Box.IsInside(Actor.RoundedPosition))
					{
						OutActors.Add(&Actor);
					}
				}
			}
		}
		else
		{
			for (auto& Child : GetChildren())
			{
				Child->GetActorsInBox(Box, OutActors);
			}
		}
	}
}

