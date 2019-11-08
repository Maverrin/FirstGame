// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGlobals.h"
#include "VoxelMaterial.h"
#include "VoxelPlaceableItems/VoxelPlaceableItem.h"
#include "VoxelPlaceableItems/VoxelDefaultItems.h"

struct FVoxelContext
{
	int32 X;
	int32 Y;
	int32 Z;
	const FVoxelPlaceableItemHolder& ItemHolder;
	const int LOD;

	FVoxelContext(const FVoxelPlaceableItemHolder& ItemHolder, int LOD)
		: ItemHolder(ItemHolder)
		, LOD(LOD)
	{
	}
};

namespace FVoxelNodeFunctions
{
	FORCEINLINE void GetDoubleIndex(const FVoxelMaterial& Material, int& OutA, int& OutB, float& OutBlend)
	{
		OutA = Material.GetIndexA();
		OutB = Material.GetIndexB();
		OutBlend = Material.GetBlend() / 255.999f;
	}

	FORCEINLINE void GetColor(const FVoxelMaterial& Material, float& OutR, float& OutG, float& OutB, float& OutA)
	{
		FLinearColor Color = Material.GetLinearColor();
		OutR = Color.R;
		OutG = Color.G;
		OutB = Color.B;
		OutA = Color.A;
	}
	// For compat
	FORCEINLINE void GetColor(const FVoxelMaterial& Material, float& OutR, float& OutG, float& OutB)
	{
		float Dummy;
		GetColor(Material, OutR, OutG, OutB, Dummy);
	}

	FORCEINLINE float VectorLength(float X, float Y, float Z)
	{
		return FMath::Sqrt(X*X + Y*Y + Z*Z);
	}

	FORCEINLINE void VectorRotateAngleAxis(float X, float Y, float Z, float AxisX, float AxisY, float AxisZ, float Angle, float& OutX, float& OutY, float& OutZ)
	{
		// taken from FVector; not using directly to keep from allocating an fvector
		float S, C;
		FMath::SinCos(&S, &C, FMath::DegreesToRadians(Angle));

		const float XX = AxisX * AxisX;
		const float YY = AxisY * AxisY;
		const float ZZ = AxisZ * AxisZ;

		const float XY = AxisX * AxisY;
		const float YZ = AxisY * AxisZ;
		const float ZX = AxisZ * AxisX;

		const float XS = AxisX * S;
		const float YS = AxisY * S;
		const float ZS = AxisZ * S;

		const float OMC = 1.f - C;

		OutX = (OMC * XX + C) * X + (OMC * XY - ZS) * Y + (OMC * ZX + YS) * Z;
		OutY = (OMC * XY + ZS) * X + (OMC * YY + C) * Y + (OMC * YZ - XS) * Z;
		OutZ = (OMC * ZX - YS) * X + (OMC * YZ + XS) * Y + (OMC * ZZ + C) * Z;
	}
	FORCEINLINE float GetPerlinWormsDistance(const FVoxelPlaceableItemHolder& ItemHolder, const FVector& Position)
	{
		float Dist = 0;
		for (auto& Item : ItemHolder.GetItems<FVoxelPerlinWorm>())
		{
			Dist = FMath::Max(Dist, Item->GetDistance(Position));
		}
		return Dist;
	}

	FORCEINLINE float Sqrt(float F)
	{
		if (F <= 0)
		{
			return 0;
		}
		else
		{
			return FMath::Sqrt(F);
		}
	}
}
