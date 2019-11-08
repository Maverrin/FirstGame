// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Math/Interval.h"
#include "VoxelDefaultSpawner.generated.h"

UENUM()
enum class EVoxelSpawnerScaling
{
	/** Grass instances will have uniform X, Y and Z scales. */
	Uniform,
	/** Grass instances will have random X, Y and Z scales. */
	Free,
	/** X and Y will be the same random scale, Z will be another */
	LockXY
};

UENUM()
enum class EVoxelSpawnerRotation
{
	AlignToSurface,
	AlignToWorldUp,
	DontAlign
};

USTRUCT()
struct FVoxelDefaultSpawner
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = Grass)
	int32 Seed = 1337;
	
	/** Instances per 10 square meters. */
	UPROPERTY(EditAnywhere, Category = "Spawn settings")
	float Density = 10;
	
	/** Specifies instance scaling type */
	UPROPERTY(EditAnywhere, Category = "Spawn settings")
	EVoxelSpawnerScaling Scaling = EVoxelSpawnerScaling::Uniform;

	/** Specifies the range of scale, from minimum to maximum, to apply to an actor instance's X Scale property */
	UPROPERTY(EditAnywhere, Category = "Spawn settings")
	FFloatInterval ScaleX = FFloatInterval(1.0f, 1.0f);

	/** Specifies the range of scale, from minimum to maximum, to apply to an actor instance's Y Scale property */
	UPROPERTY(EditAnywhere, Category = "Spawn settings")
	FFloatInterval ScaleY = FFloatInterval(1.0f, 1.0f);

	/** Specifies the range of scale, from minimum to maximum, to apply to an actor instance's Z Scale property */
	UPROPERTY(EditAnywhere, Category = "Spawn settings")
	FFloatInterval ScaleZ = FFloatInterval(1.0f, 1.0f);

	/** Whether the actor instances should be placed at random rotation (true) or all at the same rotation (false) */
	UPROPERTY(EditAnywhere, Category = "Spawn settings")
	bool RandomRotation = true;

	/** Whether the actor instances should be tilted to the normal of the landscape (true), or always vertical (false) */
	UPROPERTY(EditAnywhere, Category = "Spawn settings")
	EVoxelSpawnerRotation RotationAlignment = EVoxelSpawnerRotation::AlignToSurface;
	
	/** Min angle between object up vector and world generator up vector in degrees */
	UPROPERTY(EditAnywhere, meta = (UIMin = "0", UIMax = "180"), Category = "Spawn settings")
	float MinAngleWithWorldUp = 0;
	/** Max angle between object up vector and world generator up vector in degrees */
	UPROPERTY(EditAnywhere, meta = (UIMin = "0", UIMax = "180"), Category = "Spawn settings")
	float MaxAngleWithWorldUp = 90;
};

