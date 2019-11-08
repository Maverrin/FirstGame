// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Landscape.h"
#include "LandscapeLayerInfoObject.h"
#include "VoxelMaterial.h"
#include "VoxelConfigEnums.h"
#include "GameFramework/Actor.h"
#include "VoxelLandscapeImporter.generated.h"

UENUM()
enum class EVoxelLandscapeImporterRGB
{
	R,
	G,
	B
};

/**
 * Hold informations for landscape layers import
 */
USTRUCT()
struct VOXEL_API FVoxelLandscapeImporterLayerInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Voxel")
	ULandscapeLayerInfoObject* LayerInfo;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	EVoxelLandscapeImporterRGB Layer;
	
	UPROPERTY(EditAnywhere, Category = "Voxel")
	uint8 Index;
};

/**
 * Actor that create a UVoxelLandscapeAsset from an ALandscape
 */
UCLASS(BlueprintType, HideCategories = ("Tick", "Replication", "Input", "Actor", "Rendering", "HOLD", "LOD", "Cooking"))
class VOXEL_API AVoxelLandscapeImporter : public AActor
{
	GENERATED_BODY()

public:
	// The landscape to import
	UPROPERTY(EditAnywhere, Category = "Import configuration")
	ALandscape* Landscape;

	UPROPERTY(EditAnywhere, Category = "Import configuration")
	EVoxelMaterialConfig MaterialConfig;

	// The layers to import
	UPROPERTY(EditAnywhere, Category = "Import configuration")
	TArray<FVoxelLandscapeImporterLayerInfo> LayerInfos;
};
