// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelMaterial.h"
#include "VoxelValue.h"
#include "IntBox.h"
#include "VoxelPlaceableItems/VoxelPlaceableItem.h"
#include "VoxelPlaceableItems/VoxelDefaultItems.h"
#include "VoxelWorldGenerator.generated.h"

struct FVoxelWorldGeneratorInit
{
	TMap<FString, int> Seeds;
	float VoxelSize = 100;

	FVoxelWorldGeneratorInit() {};

	FVoxelWorldGeneratorInit(const TMap<FString, int>& Seeds, float VoxelSize)
		: Seeds(Seeds)
		, VoxelSize(VoxelSize)
	{
	}
};

enum class EVoxelEmptyState : uint8
{
	Unknown,
	AllFull,
	AllEmpty
};

/**
 * A FVoxelWorldGeneratorInstance is a constant object created by a UVoxelWorldGenerator
 */
class VOXEL_API FVoxelWorldGeneratorInstance
{
public:
	virtual ~FVoxelWorldGeneratorInstance() = default;

	inline static int GetIndex(int X, int Y, int Z, const FIntVector& Offset, int LOD, const FIntVector& ArraySize)
	{
		int LX = (uint32)(X - Offset.X) >> LOD;
		int LY = (uint32)(Y - Offset.Y) >> LOD;
		int LZ = (uint32)(Z - Offset.Z) >> LOD;

		/*check(LX == (X - Offset.X) / (1 << LOD));
		check(LY == (Y - Offset.Y) / (1 << LOD));
		check(LZ == (Z - Offset.Z) / (1 << LOD));

		check(0 <= LX && LX < ArraySize.X);
		check(0 <= LY && LY < ArraySize.Y);
		check(0 <= LZ && LZ < ArraySize.Z);*/

		return LX + ArraySize.X * LY + ArraySize.X * ArraySize.Y * LZ;
	}

	inline static void ApplyVoxelAssetItems(const FVoxelPlaceableItemHolder& ItemHolder, int X, int Y, int Z, FVoxelValue* Value, FVoxelMaterial* Material)
	{
		FVoxelValue CurrentValue = Value? *Value : FVoxelValue::Empty;
		FVoxelMaterial CurrentMaterial = Material ? *Material : FVoxelMaterial();

		for (FVoxelAssetItem* Item : ItemHolder.GetItems<FVoxelAssetItem>())
		{
			if (!Item->Bounds.IsInside(X, Y, Z))
			{
				continue;
			}

			FVoxelValue TmpValue;
			FVoxelMaterial TmpMaterial;
			Item->Asset->GetValueAndMaterial(X, Y, Z, &TmpValue, Material ? &TmpMaterial : nullptr);

			if (!TmpValue.IsEmpty())
			{
				if (Value)
				{
					*Value = Item->bInvert ? TmpValue.GetInverse() : TmpValue;
				}
				if (Material)
				{
					*Material = TmpMaterial;
				}
				return;
			}
			else if (!TmpValue.IsTotallyEmpty())
			{
				if (Item->bInvert)
				{
					TmpValue.Inverse();
				}
				if ((!Item->bInvert && TmpValue < CurrentValue) || (Item->bInvert && TmpValue > CurrentValue))
				{
					CurrentValue = TmpValue;
					CurrentMaterial = TmpMaterial;
				}
			}
		}
		if (Value)
		{
			*Value = CurrentValue;
		}
		if (Material)
		{
			*Material = CurrentMaterial;
		}
	}

	inline static void ApplyVoxelExclusionBoxItems(const FVoxelPlaceableItemHolder& ItemHolder, int X, int Y, int Z, FVoxelValue* Value, FVoxelMaterial* Material)
	{
		for (FVoxelExclusionBoxItem* Item : ItemHolder.GetItems<FVoxelExclusionBoxItem>())
		{
			if (!Item->Bounds.IsInside(X, Y, Z))
			{
				continue;
			}
			if (Value)
			{
				if (Item->bExcludeTerrain)
				{
					*Value = FVoxelValue::Empty;
				}
			}
			if (Material)
			{
				if (Item->bExcludeVoxelGrass)
				{
					Material->SetVoxelGrassId(255);
				}
				if (Item->bExcludeVoxelSpawnedActors)
				{
					Material->SetVoxelActorId(255);
				}
			}
		}
	}

	inline static void SetValueAndMaterial(FVoxelValue* Values, FVoxelMaterial* Materials, const FIntVector& Offset, int LOD, const FIntVector& ArraySize, const FVoxelPlaceableItemHolder& ItemHolder, int X, int Y, int Z, const FVoxelValue& Value, const FVoxelMaterial& Material)
	{
		FVoxelValue ValueCopy = Value;
		FVoxelMaterial MaterialCopy = Material;

		ApplyVoxelAssetItems(ItemHolder, X, Y, Z, Values ? &ValueCopy : nullptr, Materials ? &MaterialCopy : nullptr);
		ApplyVoxelExclusionBoxItems(ItemHolder, X, Y, Z, Values ? &ValueCopy : nullptr, Materials ? &MaterialCopy : nullptr);
		
		int Index = GetIndex(X, Y, Z, Offset, LOD, ArraySize);
		if (Values)
		{
			Values[Index] = ValueCopy;
		}
		if (Materials)
		{
			Materials[Index] = MaterialCopy;
		}
	}

	/** Get the value and material (X, Y, Z) */
	inline void GetValueAndMaterial(int X, int Y, int Z, FVoxelValue* OutValue, FVoxelMaterial* OutMaterial, int QueryLOD = 0) const
	{
		GetValuesAndMaterials(OutValue, OutMaterial, FIntBox(X, Y, Z), FIntVector(X, Y, Z), 0, FIntVector(1, 1, 1));
	}
	inline void GetValueAndMaterial(int X, int Y, int Z, FVoxelValue& OutValue, FVoxelMaterial& OutMaterial, int QueryLOD = 0) const
	{
		GetValueAndMaterial(X, Y, Z, &OutValue, &OutMaterial, QueryLOD);
	}

	/** Get the value at (X, Y, Z) */
	inline FVoxelValue GetValue(int X, int Y, int Z, int QueryLOD = 0) const
	{
		FVoxelValue Value;
		GetValueAndMaterial(X, Y, Z, &Value, nullptr, QueryLOD);
		return Value;
	}

	/** Get the material at (X, Y, Z) */
	inline FVoxelMaterial GetMaterial(int X, int Y, int Z, int QueryLOD = 0) const
	{
		FVoxelMaterial Material;
		GetValueAndMaterial(X, Y, Z, nullptr, &Material, QueryLOD);
		return Material;
	}

	virtual void GetValuesAndMaterials(FVoxelValue Values[], FVoxelMaterial Materials[], const FIntBox& Bounds, const FIntVector& Offset, int LOD, const FIntVector& ArraySize, int QueryLOD = 0, const FVoxelPlaceableItemHolder& ItemHolder = FVoxelPlaceableItemHolder()) const
	{
		unimplemented();

		const int Step = 1 << LOD;
		
		check(Bounds.IsMultipleOf(Step));
		
		FVoxelValue Value;
		FVoxelMaterial Material;

		for (int Z = Bounds.Min.Z; Z < Bounds.Max.Z; Z += Step)
		{
			// If Value/Material doesn't depend on X and Y, you should compute it here
			for (int Y = Bounds.Min.Y; Y < Bounds.Max.Y; Y += Step)
			{
				// If Value/Material doesn't depend on X, you should compute it here
				for (int X = Bounds.Min.X; X < Bounds.Max.X; X += Step)
				{
					SetValueAndMaterial(Values, Materials, Offset, LOD, ArraySize, ItemHolder, X, Y, Z, Value, Material);
				}
			}
		}
	}

	/**
	 * Initialization
	 */
	virtual void Init(const FVoxelWorldGeneratorInit& InitStruct) {}

	/**
	 * World up vector at position (must be normalized). Mainly used for grass
	 */
	virtual FVector GetUpVector(int X, int Y, int Z) const { return FVector::UpVector; }
	inline FVector GetUpVector(const FIntVector& V) const { return GetUpVector(V.X, V.Y, V.Z); }

	/**
	 * If true, GetValuesAndMaterials(Start, Step, Size) MUST be empty, else it MIGHT be empty
	 */
	virtual EVoxelEmptyState IsEmpty(const FIntBox& Bounds, int LOD) const { return EVoxelEmptyState::Unknown; }
};

/**
 * A UVoxelWorldGenerator is used to create a FVoxelWorldGeneratorInstance
 */
UCLASS(abstract)
class VOXEL_API UVoxelWorldGenerator : public UObject
{
	GENERATED_BODY()

public:
	//~ Begin UVoxelWorldGenerator Interface
	virtual TSharedRef<FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> GetWorldGenerator()
	{
		unimplemented();
		return MakeShared<FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe>();
	}
	//~ End UVoxelWorldGenerator Interface
};