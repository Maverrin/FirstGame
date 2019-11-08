// Copyright 2018 Phyronnaz

#include "VoxelPlaceableItemActorFactory.h"
#include "VoxelPlaceableItems/VoxelPlaceableItemActor.h"
#include "VoxelPlaceableItems/VoxelExclusionBox.h"
#include "EngineUtils.h"
#include "VoxelPlaceableItems/VoxelAssetActor.h"
#include "VoxelWorld.h"

#define LOCTEXT_NAMESPACE "VoxelPlaceableItemActorFactory"

UVoxelPlaceableItemActorFactory::UVoxelPlaceableItemActorFactory()
{
	DisplayName = LOCTEXT("VoxelPlaceableItemActorDisplayName", "Voxel Placeable Item Actor");
	NewActorClass = AVoxelPlaceableItemActor::StaticClass();
}

void UVoxelPlaceableItemActorFactory::PostSpawnActor(UObject* Asset, AActor* NewActor)
{
	Super::PostSpawnActor(Asset, NewActor);

	AVoxelPlaceableItemActor* ItemActor = CastChecked<AVoxelPlaceableItemActor>(NewActor);
	
	for (TActorIterator<AVoxelWorld> ActorItr(ItemActor->GetWorld()); ActorItr; ++ActorItr)
	{
		ItemActor->World = *ActorItr;
		break;
	}
}

UVoxelExclusionBoxFactory::UVoxelExclusionBoxFactory()
{
	DisplayName = LOCTEXT("VoxelExclusionBoxDisplayName", "Voxel Exclusion Box");
	NewActorClass = AVoxelExclusionBox::StaticClass();
}

UVoxelAssetActorFactory::UVoxelAssetActorFactory()
{
	DisplayName = LOCTEXT("VoxelAssetActorDisplayName", "Voxel Asset Actor");
	NewActorClass = AVoxelAssetActor::StaticClass();
}

#undef LOCTEXT_NAMESPACE
