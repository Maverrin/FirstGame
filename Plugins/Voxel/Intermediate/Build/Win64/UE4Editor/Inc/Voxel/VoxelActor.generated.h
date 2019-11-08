// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AVoxelWorld;
#ifdef VOXEL_VoxelActor_generated_h
#error "VoxelActor.generated.h already included, missing '#pragma once' in VoxelActor.h"
#endif
#define VOXEL_VoxelActor_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsOverlappingVoxelWorld) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_UBOOL(Z_Param_bOnlyCheckVoxelsAtPositionForOverlap); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsOverlappingVoxelWorld(Z_Param_World,Z_Param_bOnlyCheckVoxelsAtPositionForOverlap); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsOverlappingVoxelWorld) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_UBOOL(Z_Param_bOnlyCheckVoxelsAtPositionForOverlap); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsOverlappingVoxelWorld(Z_Param_World,Z_Param_bOnlyCheckVoxelsAtPositionForOverlap); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVoxelActor(); \
	friend struct Z_Construct_UClass_AVoxelActor_Statics; \
public: \
	DECLARE_CLASS(AVoxelActor, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelActor)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAVoxelActor(); \
	friend struct Z_Construct_UClass_AVoxelActor_Statics; \
public: \
	DECLARE_CLASS(AVoxelActor, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelActor)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelActor(AVoxelActor&&); \
	NO_API AVoxelActor(const AVoxelActor&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelActor(AVoxelActor&&); \
	NO_API AVoxelActor(const AVoxelActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVoxelActor)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_12_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSpawners_VoxelActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
