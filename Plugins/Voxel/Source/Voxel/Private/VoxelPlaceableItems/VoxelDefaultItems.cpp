// Copyright 2018 Phyronnaz

#include "VoxelPlaceableItems/VoxelDefaultItems.h"
#include "VoxelPlaceableItems/VoxelPlaceableItemActor.h"
#include "VoxelWorld.h"
#include "EngineUtils.h"
#include "VoxelAssets/VoxelDataAsset.h"

FVoxelAssetItem::FVoxelAssetItem(const TSharedRef<FVoxelDataAssetInstance, ESPMode::ThreadSafe>& Asset, int Priority, bool bInvert)
	: FVoxelPlaceableItem(Asset->GetWorldBounds(), Priority)
	, Asset(Asset)
	, bInvert(bInvert)
{

}
