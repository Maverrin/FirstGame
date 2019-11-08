// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VoxelLatentActionHelpers.h"
#include "VoxelAssets/VoxelDataAsset.h"
#include "VoxelAssetTools.generated.h"

class AVoxelWorld;

UENUM(BlueprintType)
enum class EVoxelAssetPositionOffset : uint8
{
	PositionIsMin,
	PositionIsMiddle,
	PositionIsMax
};

UENUM(BlueprintType)
enum class EVoxelAssetSmartImportType : uint8
{
	Add,
	Remove
};

class FVoxelImportAssetAsyncWork : public FVoxelLatentActionAsyncWork
{
public:
	// In
	const bool bSmartImport;
	const bool bAdd;
	TSharedRef<const FVoxelDataAssetData, ESPMode::ThreadSafe> AssetData;
	FIntBox Bounds;
	const bool bImportValues;
	const bool bImportMaterials;

	FVoxelImportAssetAsyncWork(
		TWeakObjectPtr<AVoxelWorld> World,
		bool bSmartImport,
		bool bAdd,
		TSharedRef<const FVoxelDataAssetData, ESPMode::ThreadSafe> AssetData,
		const FIntBox& Bounds,
		bool bImportValues, 
		bool bImportMaterials)
		: FVoxelLatentActionAsyncWork(World)
		, bSmartImport(bSmartImport)
		, bAdd(bAdd)
		, AssetData(AssetData)
		, Bounds(Bounds)
		, bImportValues(bImportValues)
		, bImportMaterials(bImportMaterials)
	{
	}

	virtual void DoWork() override;
};

UCLASS()
class VOXEL_API UVoxelAssetTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	static void ImportAsset(
		AVoxelWorld* World,
		UVoxelDataAsset* Asset, 
		const FIntVector& Position,
		EVoxelAssetPositionOffset OffsetX = EVoxelAssetPositionOffset::PositionIsMiddle,
		EVoxelAssetPositionOffset OffsetY = EVoxelAssetPositionOffset::PositionIsMiddle,
		EVoxelAssetPositionOffset OffsetZ = EVoxelAssetPositionOffset::PositionIsMin,
		bool bImportValues = true,
		bool bImportMaterials = true,
		bool bSmartImport = true,
		EVoxelAssetSmartImportType SmartImportType = EVoxelAssetSmartImportType::Add);
	
	UFUNCTION(BlueprintCallable, Category = "Voxel", meta = (Latent, LatentInfo="LatentInfo", WorldContext = "WorldContextObject"))
	static void ImportAssetAsync(
		UObject* WorldContextObject,
		FLatentActionInfo LatentInfo,
		AVoxelWorld* World,
		UVoxelDataAsset* Asset, 
		const FIntVector& Position,
		EVoxelAssetPositionOffset OffsetX = EVoxelAssetPositionOffset::PositionIsMiddle,
		EVoxelAssetPositionOffset OffsetY = EVoxelAssetPositionOffset::PositionIsMiddle,
		EVoxelAssetPositionOffset OffsetZ = EVoxelAssetPositionOffset::PositionIsMin,
		bool bImportValues = true,
		bool bImportMaterials = true,
		bool bSmartImport = true,
		EVoxelAssetSmartImportType SmartImportType = EVoxelAssetSmartImportType::Add);
};

