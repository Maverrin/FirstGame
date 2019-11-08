// Copyright 2018 Phyronnaz

#pragma once


#include "CoreMinimal.h"
#include "VoxelGraph/VoxelNodeHelpers.h"
#include "VoxelBaseNodes.generated.h"

#define LOCTEXT_NAMESPACE "VoxelNodes"

UCLASS(abstract)
class VOXEL_API UVoxelMaterialNode : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:
	UVoxelMaterialNode()
	{
		SetColor(FLinearColor::Blue);
	}
};

UCLASS(abstract)
class VOXEL_API UVoxelSeedNode : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:
	UVoxelSeedNode()
	{
		SetColor(FLinearColor(1.f, 0.3f, 1.f, 1.f));
	}
};

UCLASS(abstract)
class VOXEL_API UVoxelFloatNode : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:
	UVoxelFloatNode()
	{
		SetColor(FLinearColor::Green);
	}
};

UCLASS(abstract)
class VOXEL_API UVoxelIntNode : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:
	UVoxelIntNode()
	{
		SetColor(FLinearColor::Blue);
	}
};

#undef LOCTEXT_NAMESPACE

