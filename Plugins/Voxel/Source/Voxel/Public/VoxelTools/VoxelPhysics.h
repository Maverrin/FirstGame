// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IntBox.h"
#include "VoxelPart.h"
#include "Misc/IQueuedWork.h"
#include "LatentActions.h"
#include "VoxelValue.h"
#include "VoxelMaterial.h"
#include "VoxelLatentActionHelpers.h"
#include "VoxelPhysics.generated.h"

class AVoxelWorld;

///////////////////////////////////////////////////////////////////////////////

struct FVoxelPhysicsResult
{
	TArray<FVoxelValue> Values;
	TArray<FVoxelMaterial> Materials;
	TArray<bool> Visited;
	TArray<FIntVector> FloatingPoints;
	FIntBox BoxToUpdate;
};

///////////////////////////////////////////////////////////////////////////////

class FVoxelPhysicsAsyncWork : public FVoxelLatentActionAsyncWork
{
public:
	// In
	FIntBox Bounds;
	// Out
	FVoxelPhysicsResult Result;

	FVoxelPhysicsAsyncWork(TWeakObjectPtr<AVoxelWorld> World, const FIntBox& Bounds)
		: FVoxelLatentActionAsyncWork(World)
		, Bounds(Bounds)
	{
	}

	virtual void DoWork() override;
};

///////////////////////////////////////////////////////////////////////////////

UCLASS()
class VOXEL_API UVoxelPhysicsTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Voxel", meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject"))
	static void RemoveFloatingBlocks(
		UObject* WorldContextObject,
		struct FLatentActionInfo LatentInfo,
		TArray<AVoxelPart*>& SpawnedActors,
		AVoxelWorld* World,
		const FIntBox& Bounds,
		TSubclassOf<AVoxelPart> ClassToSpawn);

private:
	static TMap<UWorld*, bool> SearchIsRunning;
};

