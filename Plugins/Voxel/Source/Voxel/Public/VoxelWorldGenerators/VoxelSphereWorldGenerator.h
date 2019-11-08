// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelMaterial.h"
#include "VoxelWorldGenerator.h"
#include "VoxelSphereWorldGenerator.generated.h"

class VOXEL_API FVoxelSphereWorldGeneratorInstance : public FVoxelWorldGeneratorInstance
{
public:
	FVoxelSphereWorldGeneratorInstance(float Radius, const FVoxelMaterial& Material, bool bInverseOutsideInside)
		: Radius(Radius)
		, Material(Material)
		, bInverseOutsideInside(bInverseOutsideInside)
	{
	}

	//~ Begin FVoxelWorldGeneratorInstance Interface
	void GetValuesAndMaterials(
		FVoxelValue Values[],
		FVoxelMaterial Materials[],
		const FIntBox& Bounds, 
		const FIntVector& Offset, 
		int LOD, 
		const FIntVector& ArraySize, 
		int QueryLOD, 
		const FVoxelPlaceableItemHolder& ItemHolder) const final
	{
		const int Step = 1 << LOD;

		check(Bounds.IsMultipleOf(Step));

		for (int Z = Bounds.Min.Z; Z < Bounds.Max.Z; Z += Step)
		{
			for (int Y = Bounds.Min.Y; Y < Bounds.Max.Y; Y += Step)
			{
				for (int X = Bounds.Min.X; X < Bounds.Max.X; X += Step)
				{
					int Index = GetIndex(X, Y, Z, Offset, LOD, ArraySize);

					// Distance to the center
					float Distance = FVector(X, Y, Z).Size();

					// Alpha = -1 inside the sphere, 1 outside and an interpolated value on intersection
					float Alpha = FMath::Clamp(Distance - Radius, -2.f, 2.f) / 2;

					FVoxelValue Value = Alpha * (bInverseOutsideInside ? -1 : 1);

					SetValueAndMaterial(Values, Materials, Offset, LOD, ArraySize, ItemHolder, X, Y, Z, Value, Material);
				}
			}
		}
	}
	FVector GetUpVector(int X, int Y, int Z) const final
	{
		return FVector(X, Y, Z).GetSafeNormal();
	}
	//~ End FVoxelWorldGeneratorInstance Interface

private:
	const float Radius;
	const FVoxelMaterial Material;
	const bool bInverseOutsideInside;
};

/**
 * Sphere World
 */
UCLASS(Blueprintable)
class VOXEL_API UVoxelSphereWorldGenerator : public UVoxelWorldGenerator
{
	GENERATED_BODY()

public:
	// Radius of the sphere in voxels
	UPROPERTY(EditAnywhere, Category = "Voxel")
	float Radius = 10;

	// Material of the sphere
	UPROPERTY(EditAnywhere, Category = "Voxel")
	FVoxelMaterial Material;

	// If true, sphere is a hole in a full world
	UPROPERTY(EditAnywhere, Category = "Voxel")
	bool InverseOutsideInside = false;

	//~ Begin UVoxelWorldGenerator Interface
	TSharedRef<FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> GetWorldGenerator() override
	{
		return MakeShared<FVoxelSphereWorldGeneratorInstance, ESPMode::ThreadSafe>(Radius, Material, InverseOutsideInside);
	}
	//~ End UVoxelWorldGenerator Interface
};