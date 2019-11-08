// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoxelMeshImporter.generated.h"

class UStaticMesh;
struct FVoxelDataAssetData;

/**
 * Actor that creates a VoxelDataAsset from a static mesh
 */
UCLASS(BlueprintType, HideCategories = ("Tick", "Replication", "Input", "Actor", "Rendering", "HOLD", "LOD", "Cooking"))
class VOXEL_API AVoxelMeshImporter : public AActor
{
	GENERATED_BODY()

public:
	// The static mesh to import from
	UPROPERTY(EditAnywhere, Category = "Import configuration")
	UStaticMesh* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Import configuration", meta = (ClampMin = "0", UIMin = "0"))
	float VoxelSize;

	AVoxelMeshImporter();

	void ImportToAsset(FVoxelDataAssetData& Asset, FIntVector& OutOffset);
	
protected:
#if WITH_EDITOR
	void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	UPROPERTY()
	UStaticMeshComponent* MeshComponent;
};
