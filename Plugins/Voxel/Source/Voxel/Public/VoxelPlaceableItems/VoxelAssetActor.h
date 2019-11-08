// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelPlaceableItems/VoxelPlaceableItemActor.h"
#include "VoxelRender/VoxelIntermediateChunk.h"
#include "VoxelConfigEnums.h"
#include "VoxelAssetActor.generated.h"

class UVoxelProceduralMeshComponent;
class UBoxComponent;
class AVoxelWorld;
class UMaterialInterface;
class UVoxelDataAsset;
class UVoxelMaterialCollection;
class FVoxelQueuedThreadPool;

UCLASS()
class VOXEL_API AVoxelAssetActor : public AVoxelPlaceableItemActor
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, Category = "Config")
	UVoxelDataAsset* Asset;
	
	UPROPERTY(EditAnywhere, Category = "Config")
	int Priority;

	UPROPERTY(EditAnywhere, Category = "Config")
	bool bInvert;
	
public:
	//~ Begin AVoxelPlaceableItemActor Interface
	void AddItemToWorld(AVoxelWorld* InWorld) const override;
	//~ End AVoxelPlaceableItemActor Interface
#if WITH_EDITOR
public:
	AVoxelAssetActor();

	void Update();
	
protected:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	bool ShouldTickIfViewportsOnly() const override { return true; }
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	void PostEditMove(bool bFinished) override;
#else
public:
	AVoxelAssetActor() {}
#endif

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category = "Preview Settings", meta = (ClampMin = "1", ClampMax = "25", UIMin = "1", UIMax = "25"))
	int MaxOctreeDepth = 4;
	UPROPERTY(Transient)
	TArray<UVoxelProceduralMeshComponent*> Meshes;
	UPROPERTY()
	UBoxComponent* Box;
	UPROPERTY()
	USceneComponent* Root;
	UPROPERTY()
	FVoxelMaterialsRefHolder MaterialsRef;
#endif
	
#if WITH_EDITOR
	bool bBuilt = false;

	float CurrentVoxelSize = 0;
	FVector CurrentWorldLocation;
	EVoxelRenderType CurrentRenderType;
	EVoxelUVConfig CurrentUVConfig;
	EVoxelNormalConfig CurrentNormalConfig;
	EVoxelMaterialConfig CurrentMaterialConfig;
	UMaterialInterface* CurrentVoxelMaterial;
	UVoxelMaterialCollection* CurrentMaterialCollection;

	TSharedPtr<FVoxelChunkMaterials> Materials;

	static FVoxelQueuedThreadPool* ThreadPool;

	void ClampTransform();
#endif
};

