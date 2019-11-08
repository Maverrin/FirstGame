// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelWorldGenerator.h"
#include "VoxelFlatWorldGenerator.generated.h"

class VOXEL_API FVoxelFlatWorldGeneratorInstance : public FVoxelWorldGeneratorInstance
{
public:
	FVoxelFlatWorldGeneratorInstance() = default;

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

		FVoxelValue Value;
		FVoxelMaterial Material;

		for (int Z = Bounds.Min.Z; Z < Bounds.Max.Z; Z += Step)
		{
			Value = Z >= 0 ? FVoxelValue::Empty : FVoxelValue::Full;

			for (int Y = Bounds.Min.Y; Y < Bounds.Max.Y; Y += Step)
			{
				for (int X = Bounds.Min.X; X < Bounds.Max.X; X += Step)
				{
					SetValueAndMaterial(Values, Materials, Offset, LOD, ArraySize, ItemHolder, X, Y, Z, Value, Material);
				}
			}
		}
	}

	EVoxelEmptyState IsEmpty(const FIntBox& Bounds, int LOD) const final
	{
		return (Bounds.Max.Z) <= 0 ? EVoxelEmptyState::AllFull : (0 <= Bounds.Min.Z) ? EVoxelEmptyState::AllEmpty : EVoxelEmptyState::Unknown;
	}
	//~ End FVoxelWorldGeneratorInstance Interface
};

/**
 * Flat world
 */
UCLASS(Blueprintable)
class VOXEL_API UVoxelFlatWorldGenerator : public UVoxelWorldGenerator
{
	GENERATED_BODY()

public:
	//~ Begin UVoxelWorldGenerator Interface
	TSharedRef<FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> GetWorldGenerator() override
	{
		return MakeShared<FVoxelFlatWorldGeneratorInstance, ESPMode::ThreadSafe>();
	}
	//~ End UVoxelWorldGenerator Interface
};