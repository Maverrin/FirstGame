// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoxelActor.generated.h"

class AVoxelWorld;
class UStaticMeshComponent;

UCLASS()
class VOXEL_API AVoxelActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Voxel Actor Config")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, Category = "Voxel Actor Config", meta = (UIMin = 0, ClampMin = 0, DisplayName = "Mesh LOD To Use For Overlap Detection"))
	int MeshLODToUseForOverlapDetection = 0;
	
	AVoxelActor();

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	bool IsOverlappingVoxelWorld(AVoxelWorld* World, bool bOnlyCheckVoxelsAtPositionForOverlap);

	static bool IsOverlappingVoxelWorld(TSubclassOf<AVoxelActor> VoxelActorClass, AVoxelWorld* World, const FTransform& Transform, bool bOnlyCheckVoxelsAtPositionForOverlap);
	
protected:
	//~ AActor Interface Start
	void BeginPlay() override;
	void EndPlay(EEndPlayReason::Type EndPlayReason) override;
	//~ AActor Interface End

private:
	static TMap<UClass*, TArray<FVector>> VerticesByClass;
	static bool bMapsHaveBeenEmptied;

	bool bEnabled = true;
};
