// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VOXEL_VoxelPoolManager_generated_h
#error "VoxelPoolManager.generated.h already included, missing '#pragma once' in VoxelPoolManager.h"
#endif
#define VOXEL_VoxelPoolManager_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsGlobalVoxelPoolCreated) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UVoxelPoolManager::IsGlobalVoxelPoolCreated(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDestroyGlobalVoxelPool) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelPoolManager::DestroyGlobalVoxelPool(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateGlobalVoxelPool) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_MeshThreadCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelPoolManager::CreateGlobalVoxelPool(Z_Param_MeshThreadCount); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsGlobalVoxelPoolCreated) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UVoxelPoolManager::IsGlobalVoxelPoolCreated(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDestroyGlobalVoxelPool) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelPoolManager::DestroyGlobalVoxelPool(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateGlobalVoxelPool) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_MeshThreadCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelPoolManager::CreateGlobalVoxelPool(Z_Param_MeshThreadCount); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelPoolManager(); \
	friend struct Z_Construct_UClass_UVoxelPoolManager_Statics; \
public: \
	DECLARE_CLASS(UVoxelPoolManager, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelPoolManager)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelPoolManager(); \
	friend struct Z_Construct_UClass_UVoxelPoolManager_Statics; \
public: \
	DECLARE_CLASS(UVoxelPoolManager, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelPoolManager)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelPoolManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelPoolManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelPoolManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelPoolManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelPoolManager(UVoxelPoolManager&&); \
	NO_API UVoxelPoolManager(const UVoxelPoolManager&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelPoolManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelPoolManager(UVoxelPoolManager&&); \
	NO_API UVoxelPoolManager(const UVoxelPoolManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelPoolManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelPoolManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelPoolManager)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_66_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h_69_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelPoolManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
