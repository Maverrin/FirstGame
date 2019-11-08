// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "IntBox.h"
#include "VoxelPlaceableItems/VoxelPlaceableItemActor.h"
#include "VoxelExclusionBox.generated.h"

class UBoxComponent;
class AVoxelWorld;

UCLASS()
class VOXEL_API AVoxelExclusionBox : public AVoxelPlaceableItemActor
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, Category = "Config")
	bool bExcludeTerrain = true;

	UPROPERTY(EditAnywhere, Category = "Config")
	bool bExcludeVoxelActors = false;

	UPROPERTY(EditAnywhere, Category = "Config")
	bool bExcludeVoxelGrass = false;

	UPROPERTY(EditAnywhere, Category = "Config")
	bool bDisableEdits = false;

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	FIntBox GetBox() const;
	
public:
	//~ Begin AVoxelPlaceableItemActor Interface
	void AddItemToWorld(AVoxelWorld* InWorld) const override;
	//~ End AVoxelPlaceableItemActor Interface

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	static void AddExclusionBoxToWorld(AVoxelWorld* InWorld, const FIntBox& Bounds, bool bInExcludeTerrain, bool bInExcludeVoxelActors, bool bInExcludeVoxelGrass, bool bInDisableEdits);

#if WITH_EDITOR
public:
	AVoxelExclusionBox();

protected:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	bool ShouldTickIfViewportsOnly() const override { return true; }
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	void PostEditMove(bool bFinished) override;
#else
public:
	AVoxelExclusionBox() {}
#endif

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	UBoxComponent* Box;
#endif

#if WITH_EDITOR
	float CurrentVoxelSize;
	FVector CurrentWorldLocation;

	void ClampTransform();
#endif
};
