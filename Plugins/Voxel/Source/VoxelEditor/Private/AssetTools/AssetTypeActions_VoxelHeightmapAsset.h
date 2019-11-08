// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"
#include "VoxelAssets/VoxelHeightmapAsset.h"

class FAssetTypeActions_VoxelHeightmapAsset : public FAssetTypeActions_Base
{
public:
	FAssetTypeActions_VoxelHeightmapAsset(EAssetTypeCategories::Type InAssetCategory)
		: MyAssetCategory(InAssetCategory)
	{

	}

	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "FAssetTypeActions_VoxelHeightmapAsset", "Voxel Heightmap Asset"); }
	virtual FColor GetTypeColor() const override { return FColor(200, 80, 80); }
	virtual UClass* GetSupportedClass() const override { return UVoxelHeightmapAsset::StaticClass(); }
	virtual uint32 GetCategories() override { return MyAssetCategory; }

private:
	EAssetTypeCategories::Type MyAssetCategory;
};
