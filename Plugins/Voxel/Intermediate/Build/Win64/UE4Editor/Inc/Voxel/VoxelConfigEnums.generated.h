// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VOXEL_VoxelConfigEnums_generated_h
#error "VoxelConfigEnums.generated.h already included, missing '#pragma once' in VoxelConfigEnums.h"
#endif
#define VOXEL_VoxelConfigEnums_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelConfigEnums_h


#define FOREACH_ENUM_EVOXELUVCONFIG(op) \
	op(EVoxelUVConfig::GlobalUVs) \
	op(EVoxelUVConfig::UseRGAsUVs) \
	op(EVoxelUVConfig::PackWorldUpInUVs) \
	op(EVoxelUVConfig::PerVoxelUVs) 
#define FOREACH_ENUM_EVOXELMATERIALCONFIG(op) \
	op(EVoxelMaterialConfig::RGB) \
	op(EVoxelMaterialConfig::IndexWithMultipleMaterials) \
	op(EVoxelMaterialConfig::DoubleIndexWithMultipleMaterials) 
#define FOREACH_ENUM_EVOXELNORMALCONFIG(op) \
	op(EVoxelNormalConfig::NoNormal) \
	op(EVoxelNormalConfig::GradientNormal) \
	op(EVoxelNormalConfig::MeshNormal) 
#define FOREACH_ENUM_EVOXELRENDERTYPE(op) \
	op(EVoxelRenderType::MarchingCubes) \
	op(EVoxelRenderType::Cubic) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
