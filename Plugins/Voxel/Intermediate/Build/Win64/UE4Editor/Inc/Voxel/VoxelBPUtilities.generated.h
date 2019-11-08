// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVoxelMaterial;
struct FLinearColor;
struct FVoxelPaintMaterial;
struct FIntVector;
class AVoxelWorld;
struct FVector;
struct FIntBox;
#ifdef VOXEL_VoxelBPUtilities_generated_h
#error "VoxelBPUtilities.generated.h already included, missing '#pragma once' in VoxelBPUtilities.h"
#endif
#define VOXEL_VoxelBPUtilities_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetVoxelGrassId) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_PROPERTY(UByteProperty,Z_Param_VoxelGrassId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetVoxelGrassId(Z_Param_Material,Z_Param_VoxelGrassId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelGrassId) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=UVoxelBPUtilities::GetVoxelGrassId(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVoxelActorId) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_PROPERTY(UByteProperty,Z_Param_VoxelSpawnedActorId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetVoxelActorId(Z_Param_Material,Z_Param_VoxelSpawnedActorId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelActorId) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=UVoxelBPUtilities::GetVoxelActorId(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateMaterialFromDoubleIndex) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_IndexA); \
		P_GET_PROPERTY(UByteProperty,Z_Param_IndexB); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Blend); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateMaterialFromDoubleIndex(Z_Param_IndexA,Z_Param_IndexB,Z_Param_Blend); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBlend) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Blend); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetBlend(Z_Param_Material,Z_Param_Blend); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIndexB) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_PROPERTY(UByteProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetIndexB(Z_Param_Material,Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIndexA) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_PROPERTY(UByteProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetIndexA(Z_Param_Material,Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBlend) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=UVoxelBPUtilities::GetBlend(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIndexB) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=UVoxelBPUtilities::GetIndexB(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIndexA) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=UVoxelBPUtilities::GetIndexA(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateMaterialFromIndex) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateMaterialFromIndex(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIndex) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_PROPERTY(UByteProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetIndex(Z_Param_Material,Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIndex) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=UVoxelBPUtilities::GetIndex(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateMaterialFromColor) \
	{ \
		P_GET_STRUCT(FLinearColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateMaterialFromColor(Z_Param_Color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetColor) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_STRUCT(FLinearColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetColor(Z_Param_Material,Z_Param_Color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetColor) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FLinearColor*)Z_Param__Result=UVoxelBPUtilities::GetColor(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execApplyPaintMaterial) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_STRUCT(FVoxelPaintMaterial,Z_Param_PaintMaterial); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::ApplyPaintMaterial(Z_Param_Material,Z_Param_PaintMaterial); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateActorPaintMaterial) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_ActorId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelPaintMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateActorPaintMaterial(Z_Param_ActorId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateGrassPaintMaterial) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_GrassId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelPaintMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateGrassPaintMaterial(Z_Param_GrassId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateIndexPaintMaterial) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelPaintMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateIndexPaintMaterial(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateRGBPaintMaterial) \
	{ \
		P_GET_STRUCT(FLinearColor,Z_Param_Color); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Amount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelPaintMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateRGBPaintMaterial(Z_Param_Color,Z_Param_Amount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMultiply_IntIntVector) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Left); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Right); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=UVoxelBPUtilities::Multiply_IntIntVector(Z_Param_Left,Z_Param_Out_Right); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMultiply_IntVectorInt) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Left); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Right); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=UVoxelBPUtilities::Multiply_IntVectorInt(Z_Param_Out_Left,Z_Param_Right); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDivide_IntVectorInt) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Left); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Right); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=UVoxelBPUtilities::Divide_IntVectorInt(Z_Param_Out_Left,Z_Param_Right); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMultiply_IntVectorIntVector) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Left); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Right); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=UVoxelBPUtilities::Multiply_IntVectorIntVector(Z_Param_Out_Left,Z_Param_Out_Right); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSubstract_IntVectorIntVector) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Left); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Right); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=UVoxelBPUtilities::Substract_IntVectorIntVector(Z_Param_Out_Left,Z_Param_Out_Right); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdd_IntVectorIntVector) \
	{ \
		P_GET_STRUCT(FIntVector,Z_Param_Left); \
		P_GET_STRUCT(FIntVector,Z_Param_Right); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=UVoxelBPUtilities::Add_IntVectorIntVector(Z_Param_Left,Z_Param_Right); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMakeBoxFromGlobalPositionAndRadius) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_GlobalPosition); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_RadiusInVoxels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntBox*)Z_Param__Result=UVoxelBPUtilities::MakeBoxFromGlobalPositionAndRadius(Z_Param_World,Z_Param_Out_GlobalPosition,Z_Param_RadiusInVoxels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMakeBoxFromLocalPositionAndRadius) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Radius); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntBox*)Z_Param__Result=UVoxelBPUtilities::MakeBoxFromLocalPositionAndRadius(Z_Param_Out_Position,Z_Param_Radius); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTranslateBox) \
	{ \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Box); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntBox*)Z_Param__Result=UVoxelBPUtilities::TranslateBox(Z_Param_Out_Box,Z_Param_Out_Position); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetVoxelGrassId) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_PROPERTY(UByteProperty,Z_Param_VoxelGrassId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetVoxelGrassId(Z_Param_Material,Z_Param_VoxelGrassId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelGrassId) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=UVoxelBPUtilities::GetVoxelGrassId(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVoxelActorId) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_PROPERTY(UByteProperty,Z_Param_VoxelSpawnedActorId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetVoxelActorId(Z_Param_Material,Z_Param_VoxelSpawnedActorId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelActorId) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=UVoxelBPUtilities::GetVoxelActorId(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateMaterialFromDoubleIndex) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_IndexA); \
		P_GET_PROPERTY(UByteProperty,Z_Param_IndexB); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Blend); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateMaterialFromDoubleIndex(Z_Param_IndexA,Z_Param_IndexB,Z_Param_Blend); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBlend) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Blend); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetBlend(Z_Param_Material,Z_Param_Blend); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIndexB) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_PROPERTY(UByteProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetIndexB(Z_Param_Material,Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIndexA) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_PROPERTY(UByteProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetIndexA(Z_Param_Material,Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBlend) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=UVoxelBPUtilities::GetBlend(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIndexB) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=UVoxelBPUtilities::GetIndexB(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIndexA) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=UVoxelBPUtilities::GetIndexA(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateMaterialFromIndex) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateMaterialFromIndex(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIndex) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_PROPERTY(UByteProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetIndex(Z_Param_Material,Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIndex) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=UVoxelBPUtilities::GetIndex(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateMaterialFromColor) \
	{ \
		P_GET_STRUCT(FLinearColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateMaterialFromColor(Z_Param_Color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetColor) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_STRUCT(FLinearColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::SetColor(Z_Param_Material,Z_Param_Color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetColor) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FLinearColor*)Z_Param__Result=UVoxelBPUtilities::GetColor(Z_Param_Material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execApplyPaintMaterial) \
	{ \
		P_GET_STRUCT(FVoxelMaterial,Z_Param_Material); \
		P_GET_STRUCT(FVoxelPaintMaterial,Z_Param_PaintMaterial); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=UVoxelBPUtilities::ApplyPaintMaterial(Z_Param_Material,Z_Param_PaintMaterial); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateActorPaintMaterial) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_ActorId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelPaintMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateActorPaintMaterial(Z_Param_ActorId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateGrassPaintMaterial) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_GrassId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelPaintMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateGrassPaintMaterial(Z_Param_GrassId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateIndexPaintMaterial) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelPaintMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateIndexPaintMaterial(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateRGBPaintMaterial) \
	{ \
		P_GET_STRUCT(FLinearColor,Z_Param_Color); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Amount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelPaintMaterial*)Z_Param__Result=UVoxelBPUtilities::CreateRGBPaintMaterial(Z_Param_Color,Z_Param_Amount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMultiply_IntIntVector) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Left); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Right); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=UVoxelBPUtilities::Multiply_IntIntVector(Z_Param_Left,Z_Param_Out_Right); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMultiply_IntVectorInt) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Left); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Right); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=UVoxelBPUtilities::Multiply_IntVectorInt(Z_Param_Out_Left,Z_Param_Right); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDivide_IntVectorInt) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Left); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Right); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=UVoxelBPUtilities::Divide_IntVectorInt(Z_Param_Out_Left,Z_Param_Right); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMultiply_IntVectorIntVector) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Left); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Right); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=UVoxelBPUtilities::Multiply_IntVectorIntVector(Z_Param_Out_Left,Z_Param_Out_Right); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSubstract_IntVectorIntVector) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Left); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Right); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=UVoxelBPUtilities::Substract_IntVectorIntVector(Z_Param_Out_Left,Z_Param_Out_Right); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdd_IntVectorIntVector) \
	{ \
		P_GET_STRUCT(FIntVector,Z_Param_Left); \
		P_GET_STRUCT(FIntVector,Z_Param_Right); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=UVoxelBPUtilities::Add_IntVectorIntVector(Z_Param_Left,Z_Param_Right); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMakeBoxFromGlobalPositionAndRadius) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_GlobalPosition); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_RadiusInVoxels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntBox*)Z_Param__Result=UVoxelBPUtilities::MakeBoxFromGlobalPositionAndRadius(Z_Param_World,Z_Param_Out_GlobalPosition,Z_Param_RadiusInVoxels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMakeBoxFromLocalPositionAndRadius) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Radius); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntBox*)Z_Param__Result=UVoxelBPUtilities::MakeBoxFromLocalPositionAndRadius(Z_Param_Out_Position,Z_Param_Radius); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTranslateBox) \
	{ \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Box); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntBox*)Z_Param__Result=UVoxelBPUtilities::TranslateBox(Z_Param_Out_Box,Z_Param_Out_Position); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelBPUtilities(); \
	friend struct Z_Construct_UClass_UVoxelBPUtilities_Statics; \
public: \
	DECLARE_CLASS(UVoxelBPUtilities, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelBPUtilities)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelBPUtilities(); \
	friend struct Z_Construct_UClass_UVoxelBPUtilities_Statics; \
public: \
	DECLARE_CLASS(UVoxelBPUtilities, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelBPUtilities)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelBPUtilities(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelBPUtilities) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelBPUtilities); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelBPUtilities); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelBPUtilities(UVoxelBPUtilities&&); \
	NO_API UVoxelBPUtilities(const UVoxelBPUtilities&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelBPUtilities(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelBPUtilities(UVoxelBPUtilities&&); \
	NO_API UVoxelBPUtilities(const UVoxelBPUtilities&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelBPUtilities); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelBPUtilities); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelBPUtilities)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_44_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h_47_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelBPUtilities_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
