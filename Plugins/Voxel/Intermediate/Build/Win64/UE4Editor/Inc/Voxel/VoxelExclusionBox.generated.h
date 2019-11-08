// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AVoxelWorld;
struct FIntBox;
#ifdef VOXEL_VoxelExclusionBox_generated_h
#error "VoxelExclusionBox.generated.h already included, missing '#pragma once' in VoxelExclusionBox.h"
#endif
#define VOXEL_VoxelExclusionBox_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAddExclusionBoxToWorld) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_InWorld); \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Bounds); \
		P_GET_UBOOL(Z_Param_bInExcludeTerrain); \
		P_GET_UBOOL(Z_Param_bInExcludeVoxelActors); \
		P_GET_UBOOL(Z_Param_bInExcludeVoxelGrass); \
		P_GET_UBOOL(Z_Param_bInDisableEdits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		AVoxelExclusionBox::AddExclusionBoxToWorld(Z_Param_InWorld,Z_Param_Out_Bounds,Z_Param_bInExcludeTerrain,Z_Param_bInExcludeVoxelActors,Z_Param_bInExcludeVoxelGrass,Z_Param_bInDisableEdits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBox) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntBox*)Z_Param__Result=P_THIS->GetBox(); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAddExclusionBoxToWorld) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_InWorld); \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Bounds); \
		P_GET_UBOOL(Z_Param_bInExcludeTerrain); \
		P_GET_UBOOL(Z_Param_bInExcludeVoxelActors); \
		P_GET_UBOOL(Z_Param_bInExcludeVoxelGrass); \
		P_GET_UBOOL(Z_Param_bInDisableEdits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		AVoxelExclusionBox::AddExclusionBoxToWorld(Z_Param_InWorld,Z_Param_Out_Bounds,Z_Param_bInExcludeTerrain,Z_Param_bInExcludeVoxelActors,Z_Param_bInExcludeVoxelGrass,Z_Param_bInDisableEdits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBox) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntBox*)Z_Param__Result=P_THIS->GetBox(); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVoxelExclusionBox(); \
	friend struct Z_Construct_UClass_AVoxelExclusionBox_Statics; \
public: \
	DECLARE_CLASS(AVoxelExclusionBox, AVoxelPlaceableItemActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelExclusionBox)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAVoxelExclusionBox(); \
	friend struct Z_Construct_UClass_AVoxelExclusionBox_Statics; \
public: \
	DECLARE_CLASS(AVoxelExclusionBox, AVoxelPlaceableItemActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelExclusionBox)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelExclusionBox(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelExclusionBox) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelExclusionBox); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelExclusionBox); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelExclusionBox(AVoxelExclusionBox&&); \
	NO_API AVoxelExclusionBox(const AVoxelExclusionBox&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelExclusionBox(AVoxelExclusionBox&&); \
	NO_API AVoxelExclusionBox(const AVoxelExclusionBox&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelExclusionBox); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelExclusionBox); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVoxelExclusionBox)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_13_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPlaceableItems_VoxelExclusionBox_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
