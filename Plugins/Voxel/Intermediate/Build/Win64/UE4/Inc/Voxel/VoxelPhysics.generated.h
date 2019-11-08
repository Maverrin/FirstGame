// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
struct FLatentActionInfo;
class AVoxelPart;
class AVoxelWorld;
struct FIntBox;
#ifdef VOXEL_VoxelPhysics_generated_h
#error "VoxelPhysics.generated.h already included, missing '#pragma once' in VoxelPhysics.h"
#endif
#define VOXEL_VoxelPhysics_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRemoveFloatingBlocks) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_TARRAY_REF(AVoxelPart*,Z_Param_Out_SpawnedActors); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Bounds); \
		P_GET_OBJECT(UClass,Z_Param_ClassToSpawn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelPhysicsTools::RemoveFloatingBlocks(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_Out_SpawnedActors,Z_Param_World,Z_Param_Out_Bounds,Z_Param_ClassToSpawn); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRemoveFloatingBlocks) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_TARRAY_REF(AVoxelPart*,Z_Param_Out_SpawnedActors); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Bounds); \
		P_GET_OBJECT(UClass,Z_Param_ClassToSpawn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelPhysicsTools::RemoveFloatingBlocks(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_Out_SpawnedActors,Z_Param_World,Z_Param_Out_Bounds,Z_Param_ClassToSpawn); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelPhysicsTools(); \
	friend struct Z_Construct_UClass_UVoxelPhysicsTools_Statics; \
public: \
	DECLARE_CLASS(UVoxelPhysicsTools, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelPhysicsTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelPhysicsTools(); \
	friend struct Z_Construct_UClass_UVoxelPhysicsTools_Statics; \
public: \
	DECLARE_CLASS(UVoxelPhysicsTools, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelPhysicsTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelPhysicsTools(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelPhysicsTools) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelPhysicsTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelPhysicsTools); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelPhysicsTools(UVoxelPhysicsTools&&); \
	NO_API UVoxelPhysicsTools(const UVoxelPhysicsTools&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelPhysicsTools(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelPhysicsTools(UVoxelPhysicsTools&&); \
	NO_API UVoxelPhysicsTools(const UVoxelPhysicsTools&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelPhysicsTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelPhysicsTools); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelPhysicsTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_50_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h_53_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelPhysics_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
