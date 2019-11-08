// Copyright 2018 Phyronnaz

#include "VoxelSpawners/VoxelActor.h"
#include "VoxelLogStatDefinitions.h"
#include "VoxelData/VoxelData.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "ProceduralMeshComponent.h"
#include "VoxelWorld.h"
#include "PhysicsEngine/AggregateGeom.h"
#include "Logging/MessageLog.h"

DECLARE_CYCLE_STAT(TEXT("VoxelActor::IsOverlappingVoxelWorld"), STAT_VoxelActor_IsOverlappingVoxelWorld, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("VoxelActor::IsOverlappingVoxelWorld::FindPositions"), STAT_VoxelActor_IsOverlappingVoxelWorld_FindPositions, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("VoxelActor::IsOverlappingVoxelWorld::GetValues"), STAT_VoxelActor_IsOverlappingVoxelWorld_GetValues, STATGROUP_Voxel);

TMap<UClass*, TArray<FVector>> AVoxelActor::VerticesByClass;
bool AVoxelActor::bMapsHaveBeenEmptied = true;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

AVoxelActor::AVoxelActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

bool AVoxelActor::IsOverlappingVoxelWorld(AVoxelWorld* World, bool bOnlyCheckVoxelsAtPositionForOverlap)
{
	return AVoxelActor::IsOverlappingVoxelWorld(GetClass(), World, GetTransform(), bOnlyCheckVoxelsAtPositionForOverlap);
}

inline FVoxelValue GetValue(AVoxelWorld* World, const FIntVector& Position)
{
	auto Data = World->GetData();
	FVoxelScopeGetLock Lock(Data, FIntBox(Position));
	return Data->GetValue(Position);
}

bool AVoxelActor::IsOverlappingVoxelWorld(TSubclassOf<AVoxelActor> VoxelActorClass, AVoxelWorld* World, const FTransform& Transform, bool bOnlyCheckVoxelsAtPositionForOverlap)
{
	SCOPE_CYCLE_COUNTER(STAT_VoxelActor_IsOverlappingVoxelWorld);
	
	auto Default = GetDefault<AVoxelActor>(VoxelActorClass);
	
	TSet<FIntVector> Positions;
	if (bOnlyCheckVoxelsAtPositionForOverlap)
	{
		Positions.Append(World->GetNeighboringPositions(Transform.GetLocation()));
	}
	else
	{
		if (!VerticesByClass.Contains(VoxelActorClass))
		{
			auto Actor = World->GetWorld()->SpawnActor<AVoxelActor>(VoxelActorClass, FVector::ZeroVector, FRotator::ZeroRotator);
			Actor->Destroy();
		}

		{
			SCOPE_CYCLE_COUNTER(STAT_VoxelActor_IsOverlappingVoxelWorld_FindPositions);
			for (auto& V : VerticesByClass[VoxelActorClass])
			{
				Positions.Append(World->GetNeighboringPositions(Transform.TransformPosition(V)));
			}
		}
	}

	{
		SCOPE_CYCLE_COUNTER(STAT_VoxelActor_IsOverlappingVoxelWorld_GetValues);
		for (auto& P : Positions)
		{
			if (!GetValue(World, P).IsEmpty())
			{
				return true;
			}
		}
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void AVoxelActor::BeginPlay()
{
	Super::BeginPlay();

	if (!bMapsHaveBeenEmptied)
	{
		VerticesByClass.Empty();
		bMapsHaveBeenEmptied = true;
	}

	if (!VerticesByClass.Contains(GetClass()))
	{
		TArray<FVector>& Vertices = VerticesByClass.Add(GetClass());

		UStaticMesh* StaticMesh = Mesh->GetStaticMesh();
		auto& RenderData = StaticMesh->RenderData;
		check(RenderData);
		auto& LODResources = RenderData->LODResources;

		int LOD = FMath::Clamp(MeshLODToUseForOverlapDetection, 0, LODResources.Num());
		if (LOD != MeshLODToUseForOverlapDetection)
		{
			FMessageLog("PIE").Error(FText::FromString(GetName() + ": MeshLODToUseForOverlapDetection == " + FString::FromInt(MeshLODToUseForOverlapDetection) + " but max mesh LOD is " + FString::FromInt(LOD)));
		}
		auto& Buffer = LODResources[LOD].VertexBuffers.PositionVertexBuffer;

		for (uint32 Index = 0; Index < Buffer.GetNumVertices(); Index++)
		{
			Vertices.Add(Buffer.VertexPosition(Index));
		}
	}
}

void AVoxelActor::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	bMapsHaveBeenEmptied = false;
}
