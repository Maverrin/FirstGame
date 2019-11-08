// Copyright 2018 Phyronnaz

#include "ActorFactoryVoxelAssetActor.h"
#include "VoxelPlaceableItems/VoxelAssetActor.h"
#include "VoxelAssets/VoxelDataAsset.h"
#include "VoxelWorld.h"
#include "EngineUtils.h"

#define LOCTEXT_NAMESPACE "ActorFactoryVoxelAssetActor"

UActorFactoryVoxelAssetActor::UActorFactoryVoxelAssetActor()
{
	DisplayName = LOCTEXT("AssetActorDisplayName", "Asset Actor");
	NewActorClass = AVoxelAssetActor::StaticClass();
}

void UActorFactoryVoxelAssetActor::PostSpawnActor(UObject* Asset, AActor* NewActor)
{
	Super::PostSpawnActor(Asset, NewActor);

	UVoxelDataAsset* DataAsset = Cast<UVoxelDataAsset>(Asset);

	if (DataAsset)
	{
		AVoxelAssetActor* AssetActor = CastChecked<AVoxelAssetActor>(NewActor);
		AssetActor->Asset = DataAsset;

		for (TActorIterator<AVoxelWorld> ActorItr(AssetActor->GetWorld()); ActorItr; ++ActorItr)
		{
			AssetActor->World = *ActorItr;
			break;
		}
	}
}

void UActorFactoryVoxelAssetActor::PostCreateBlueprint(UObject* Asset, AActor* CDO)
{
	if (Asset&& CDO)
	{
		UVoxelDataAsset* DataAsset = Cast<UVoxelDataAsset>(Asset);

		if (DataAsset)
		{
			AVoxelAssetActor* AssetActor = CastChecked<AVoxelAssetActor>(CDO);
			AssetActor->Asset = DataAsset;
		}
	}
}

bool UActorFactoryVoxelAssetActor::CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg)
{
	//We allow creating AVoxelAssetActor without an existing data asset
	if (UActorFactory::CanCreateActorFrom(AssetData, OutErrorMsg))
	{
		return true;
	}

	if (AssetData.IsValid() && !AssetData.GetClass()->IsChildOf(UVoxelDataAsset::StaticClass()))
	{
		OutErrorMsg = NSLOCTEXT("CanCreateActor", "NoVoxelAsset", "A valid voxel data asset must be specified.");
		return false;
	}

	return true;
}

UObject* UActorFactoryVoxelAssetActor::GetAssetFromActorInstance(AActor* ActorInstance)
{
	check(ActorInstance->IsA(NewActorClass));
	AVoxelAssetActor* AssetActor = CastChecked<AVoxelAssetActor>(ActorInstance);

	return AssetActor->Asset;
}

#undef LOCTEXT_NAMESPACE

