// Copyright 2018 Phyronnaz

#include "VoxelMaterialCollection.h"
#include "VoxelRender/VoxelIntermediateChunk.h"
#include "Materials/MaterialInstanceDynamic.h"

UMaterialInterface* UVoxelMaterialCollection::GetVoxelMaterial(const FVoxelBlendedMaterial& Index)
{
	switch (Index.Kind)
	{
	case FVoxelBlendedMaterial::Single:
	{
		UMaterialInterface** Result = GeneratedSingleMaterials.Find(Index.Index0);
		return Result ? *Result : nullptr;
	}
	case FVoxelBlendedMaterial::Double:
	{
		UMaterialInterface** Result = GeneratedDoubleMaterials.Find(FVoxelMaterialCollectionDoubleIndex(Index.Index0, Index.Index1));
		return Result ? *Result : nullptr;
	}
	case FVoxelBlendedMaterial::Triple:
	{
		UMaterialInterface** Result = GeneratedTripleMaterials.Find(FVoxelMaterialCollectionTripleIndex(Index.Index0, Index.Index1, Index.Index2));
		return Result ? *Result : nullptr;
	}
	default:
	{
		check(false);
		return nullptr;
	}
	}
}

UMaterialInterface* UVoxelMaterialCollection::GetVoxelMaterialWithTessellation(const FVoxelBlendedMaterial& Index)
{
	switch (Index.Kind)
	{
	case FVoxelBlendedMaterial::Single:
	{
		UMaterialInterface** Result = GeneratedSingleMaterialsTess.Find(Index.Index0);
		return Result ? *Result : nullptr;
	}
	case FVoxelBlendedMaterial::Double:
	{
		UMaterialInterface** Result = GeneratedDoubleMaterialsTess.Find(FVoxelMaterialCollectionDoubleIndex(Index.Index0, Index.Index1));
		return Result ? *Result : nullptr;
	}
	case FVoxelBlendedMaterial::Triple:
	{
		UMaterialInterface** Result = GeneratedTripleMaterialsTess.Find(FVoxelMaterialCollectionTripleIndex(Index.Index0, Index.Index1, Index.Index2));
		return Result ? *Result : nullptr;
	}
	default:
	{
		check(false);
		return nullptr;
	}
	}
}
