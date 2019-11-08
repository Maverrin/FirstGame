// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelPlaceableItems/VoxelPlaceableItem.h"

class VOXEL_API FVoxelPerlinWorm : public FVoxelPlaceableItem
{
public:
	inline static int StaticId() { return EVoxelPerlinWorm; }

	const float Radius;
	const FVector Start;
	const FVector N;
	const float Length;

	FVoxelPerlinWorm(const FVector& InStart, const FVector& InEnd, float InRadius)
		: FVoxelPlaceableItem(FIntBox(
			FIntVector(
				FMath::FloorToInt(FMath::Min(InStart.X, InEnd.X) - InRadius),
				FMath::FloorToInt(FMath::Min(InStart.Y, InEnd.Y) - InRadius),
				FMath::FloorToInt(FMath::Min(InStart.Z, InEnd.Z) - InRadius)),
			FIntVector(
				FMath::CeilToInt(FMath::Max(InStart.X, InEnd.X) + InRadius),
				FMath::CeilToInt(FMath::Max(InStart.Y, InEnd.Y) + InRadius),
				FMath::CeilToInt(FMath::Max(InStart.Z, InEnd.Z) + InRadius))))
		, Radius(InRadius)
		, Start(InStart)
		, N((InEnd - InStart).GetSafeNormal())
		, Length((InEnd - InStart).Size())
	{

	}

	inline float GetDistance(const FVector& Position) const
	{
		float T = FVector::DotProduct(Position - Start, N);
		if (0 <= T && T <= Length)
		{
			return FMath::Max(0.f, Radius - FVector::Dist(T * N + Start, Position));
		}
		else
		{
			return 0;
		}
	}
};

class VOXEL_API FVoxelAssetItem : public FVoxelPlaceableItem
{
public:
	inline static int StaticId() { return EVoxelAssetItem; }

	const TSharedRef<class FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> Asset; // FVoxelWorldGeneratorInstance to be able to use it in FVoxelWorldGeneratorInstance
	const bool bInvert;

	FVoxelAssetItem(const TSharedRef<class FVoxelDataAssetInstance, ESPMode::ThreadSafe>& Asset, int Priority, bool bInvert);
};

class VOXEL_API FVoxelExclusionBoxItem : public FVoxelPlaceableItem
{
public:
	inline static int StaticId() { return EVoxelExclusionBoxItem; }

	const bool bExcludeTerrain;
	const bool bExcludeVoxelSpawnedActors;
	const bool bExcludeVoxelGrass;

	FVoxelExclusionBoxItem(const FIntBox& Bounds, bool bExcludeTerrain, bool bExcludeVoxelSpawnedActors, bool bExcludeVoxelGrass)
		: FVoxelPlaceableItem(Bounds)
		, bExcludeTerrain(bExcludeTerrain)
		, bExcludeVoxelSpawnedActors(bExcludeVoxelSpawnedActors)
		, bExcludeVoxelGrass(bExcludeVoxelGrass)
	{

	}
};

class VOXEL_API FVoxelDisableEditsBoxItem : public FVoxelPlaceableItem
{
public:
	inline static int StaticId() { return EVoxelDisableEditsBox; }

	FVoxelDisableEditsBoxItem(const FIntBox& Bounds)
		: FVoxelPlaceableItem(Bounds)
	{

	}
};
