// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelWorldGenerator.h"
#include "EmptyWorldGenerator.generated.h"

class VOXEL_API FEmptyWorldGeneratorInstance : public FVoxelWorldGeneratorInstance
{
public:
	FEmptyWorldGeneratorInstance(TSharedPtr<const FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> WorldUpGenerator = nullptr)
		: WorldUpGenerator(WorldUpGenerator)
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
					SetValueAndMaterial(Values, Materials, Offset, LOD, ArraySize, ItemHolder, X, Y, Z, FVoxelValue::Empty, FVoxelMaterial());
				}
			}
		}
	}
	EVoxelEmptyState IsEmpty(const FIntBox& Bounds, int LOD) const final
	{
		return EVoxelEmptyState::Unknown;
	}

	FVector GetUpVector(int X, int Y, int Z) const override
	{
		return WorldUpGenerator.IsValid() ? WorldUpGenerator->GetUpVector(X, Y, Z) : FVector::UpVector;
	}
	//~ End FVoxelWorldGeneratorInstance Interface

private:
	const TSharedPtr<const FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> WorldUpGenerator;
};

/**
 * Empty World
 */
UCLASS(Blueprintable)
class VOXEL_API UEmptyWorldGenerator : public UVoxelWorldGenerator
{
	GENERATED_BODY()
	
public:
	//~ Begin UVoxelWorldGenerator Interface
	TSharedRef<FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> GetWorldGenerator() override
	{
		return MakeShared<FEmptyWorldGeneratorInstance, ESPMode::ThreadSafe>();
	}
	//~ End UVoxelWorldGenerator Interface
};