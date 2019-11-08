// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoxelRender/VoxelIntermediateChunk.h"
#include "IntBox.h"
#include "VoxelPart.generated.h"

class UMaterialInterface;
class FVoxelData;
class UVoxelProceduralMeshComponent;
class UVoxelAutoDisableComponent;
class AVoxelWorld;
class UHierarchicalInstancedStaticMeshComponent;
class FVoxelPolygonizerAsyncWork;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVoxelPartOnLoaded);

/**
 * Abstract class, DO NOT USE DIRECTLY
 */
UCLASS(hidedropdown, abstract, notplaceable)
class VOXEL_API AVoxelPart : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Voxel")
	AVoxelWorld* World;

	UPROPERTY(BlueprintAssignable, Category = "Voxel")
	FVoxelPartOnLoaded OnLoaded;

public:
	virtual void Init(TSharedPtr<FVoxelData, ESPMode::ThreadSafe> Data, const FIntBox& Bounds, float Mass, const FIntVector& Position) {}
	virtual void WorldUpdateDone() { bWorldUpdateDone = true; }

protected:
	bool bWorldUpdateDone = false;
};

UCLASS()
class VOXEL_API AVoxelPartSimpleMesh : public AVoxelPart
{
	GENERATED_BODY()

public:
	AVoxelPartSimpleMesh();

	virtual void Init(TSharedPtr<FVoxelData, ESPMode::ThreadSafe> Data, const FIntBox& Bounds, float Mass, const FIntVector& Position) override;

protected:
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY()
	FVoxelMaterialsRefHolder MaterialsRef;

	TSharedPtr<FVoxelData, ESPMode::ThreadSafe> Data;
	float Mass = 0;

	TSharedPtr<FVoxelChunkMaterials> Materials;
	TArray<TSharedPtr<FVoxelPolygonizerAsyncWork>> Threads;
	TSet<FVoxelPolygonizerAsyncWork*> DoneThreads;
	int ThreadsRemaining = 0;

	inline UHierarchicalInstancedStaticMeshComponent* GetGrass(const FVector& Position);
	inline UVoxelProceduralMeshComponent* GetMesh(const FVector& Position);
};

UCLASS()
class VOXEL_API AVoxelPartCube : public AVoxelPart
{
	GENERATED_BODY()

public:
	// Same material as the voxel world, but instead of a vertex color input use a vector parameter named VertexColor
	UPROPERTY(EditDefaultsOnly, Category = "Voxel")
	UMaterialInterface* Material;

	UFUNCTION(BlueprintImplementableEvent, Category = "Voxel")
	void OnCubesCreated(const TArray<AStaticMeshActor*>& Cubes);

	virtual void Init(TSharedPtr<FVoxelData, ESPMode::ThreadSafe> Data, const FIntBox& Bounds, float Mass, const FIntVector& Position) override;
};
