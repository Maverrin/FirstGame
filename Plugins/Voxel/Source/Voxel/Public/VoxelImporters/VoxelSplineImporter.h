// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelMaterial.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "VoxelSplineImporter.generated.h"

class USplineComponent;
struct FVoxelDataAssetData;

/**
 * Actor that convert splines to voxels
 */
UCLASS(Blueprintable, HideCategories = ("Tick", "Replication", "Input", "Actor", "Rendering", "HOLD", "LOD", "Cooking"))
class VOXEL_API AVoxelSplineImporter : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Splines configuration")
	TArray<USplineComponent*> Splines;

	UPROPERTY(EditAnywhere, Category = "Import configuration")
	float VoxelSize;


	AVoxelSplineImporter();

	void ImportToAsset(FVoxelDataAssetData& Asset);

protected:
#if WITH_EDITOR
	//~ Begin AActor Interface
	void Tick(float DeltaTime) override;
	bool ShouldTickIfViewportsOnly() const override;
	void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	//~ End AActor Interface
#endif

private:
	UPROPERTY()
	TArray<USphereComponent*> Spheres;
};
