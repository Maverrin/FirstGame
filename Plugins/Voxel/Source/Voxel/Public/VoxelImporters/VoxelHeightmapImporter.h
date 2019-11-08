// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelMaterial.h"
#include "VoxelConfigEnums.h"
#include "GameFramework/Actor.h"
#include "VoxelHeightmapImporter.generated.h"

UENUM()
enum class EVoxelHeightmapImporterRGB
{
	R,
	G,
	B
};

/**
 * Hold informations for a weightmap import
 */
USTRUCT()
struct VOXEL_API FVoxelHeightmapImporterWeightmapInfos
{
	GENERATED_BODY()

	// The weightmap
	UPROPERTY(EditAnywhere, Category = "Voxel")
	FFilePath File;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	EVoxelHeightmapImporterRGB Layer;
	
	UPROPERTY(EditAnywhere, Category = "Voxel")
	uint8 Index;
};

/**
 * Actor that create a UVoxelLandscapeAsset from an heightmap and its weightmaps
 */
UCLASS(BlueprintType, HideCategories = ("Tick", "Replication", "Input", "Actor", "Rendering", "HOLD", "LOD", "Cooking"))
class VOXEL_API AVoxelHeightmapImporter : public AActor
{
	GENERATED_BODY()

public:
	// The path of the heightmap
	UPROPERTY(EditAnywhere, Category = "Import configuration")
	FFilePath Heightmap;

	UPROPERTY(EditAnywhere, Category = "Import configuration")
	EVoxelMaterialConfig MaterialConfig;

	// The weightmaps
	UPROPERTY(EditAnywhere, Category = "Import configuration")
	TArray<FVoxelHeightmapImporterWeightmapInfos> Weightmaps;
};
