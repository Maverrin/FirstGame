// Copyright 2018 Phyronnaz

#pragma once

#include "VoxelSpawners/VoxelGrassSpawner.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Runtime/Engine/Private/InstancedStaticMesh.h"
#include "VoxelRender/VoxelSpawnUtilities.h"
#include "Runtime/Launch/Resources/Version.h"

class FVoxelGrassUtilities
{
public:
	static void InitGrass(UHierarchicalInstancedStaticMeshComponent* NewGrass, const FVoxelGrassVariety& GrassVariety)
	{		
		int32 FolSeed = FCrc::StrCrc32((GrassVariety.GrassMesh->GetName()).GetCharArray().GetData());
		if (FolSeed == 0)
		{
			FolSeed++;
		}

		NewGrass->SetStaticMesh(GrassVariety.GrassMesh);
		NewGrass->MinLOD = GrassVariety.MinLOD;
		NewGrass->bSelectable = false;
		NewGrass->bHasPerInstanceHitProxies = false;
		NewGrass->bReceivesDecals = GrassVariety.bReceivesDecals;
		static FName NoCollision(TEXT("NoCollision"));
		NewGrass->SetCollisionProfileName(NoCollision);
		NewGrass->bDisableCollision = true;
		NewGrass->SetCanEverAffectNavigation(false);
		NewGrass->InstancingRandomSeed = FolSeed;
		NewGrass->LightingChannels = GrassVariety.LightingChannels;
		NewGrass->bCastStaticShadow = false;
		NewGrass->CastShadow = GrassVariety.bCastDynamicShadow;
		NewGrass->bCastDynamicShadow = GrassVariety.bCastDynamicShadow;

		NewGrass->InstanceStartCullDistance = GrassVariety.StartCullDistance;
		NewGrass->InstanceEndCullDistance = GrassVariety.EndCullDistance;

		NewGrass->bAffectDistanceFieldLighting = false;
	}

	static void SetNewPositions(UHierarchicalInstancedStaticMeshComponent* NewGrass, const TSharedPtr<FVoxelGrassBuffer>& Buffer)
	{
		int32 NumBuiltRenderInstances = Buffer->InstanceBuffer.GetNumInstances();
		if (NumBuiltRenderInstances > 0)
		{
			QUICK_SCOPE_CYCLE_COUNTER(STAT_FoliageGrassEndComp_AcceptPrebuiltTree);

			if (!NewGrass->PerInstanceRenderData.IsValid())
			{
#if ENGINE_MINOR_VERSION < 20
				NewGrass->InitPerInstanceRenderData(true, &Buffer->InstanceBuffer);
#else
				NewGrass->InitPerInstanceRenderData(true, &Buffer->InstanceBuffer, true);
#endif
			}
			else
			{
#if ENGINE_MINOR_VERSION < 20
				NewGrass->PerInstanceRenderData->UpdateFromPreallocatedData(NewGrass, Buffer->InstanceBuffer, true);
#else
				NewGrass->PerInstanceRenderData->UpdateFromPreallocatedData(Buffer->InstanceBuffer);
#endif
			}
			
#if ENGINE_MINOR_VERSION < 20
			NewGrass->AcceptPrebuiltTree(Buffer->ClusterTree, Buffer->OutOcclusionLayerNum);
#else
			NewGrass->AcceptPrebuiltTree(Buffer->ClusterTree, Buffer->OutOcclusionLayerNum, NumBuiltRenderInstances);
#endif
			NewGrass->MarkRenderStateDirty();
		}
		else
		{
			NewGrass->ClearInstances();
		}
	}
};
