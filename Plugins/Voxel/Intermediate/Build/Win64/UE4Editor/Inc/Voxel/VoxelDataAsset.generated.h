// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FIntVector;
#ifdef VOXEL_VoxelDataAsset_generated_h
#error "VoxelDataAsset.generated.h already included, missing '#pragma once' in VoxelDataAsset.h"
#endif
#define VOXEL_VoxelDataAsset_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetSize) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=P_THIS->GetSize(); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetSize) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=P_THIS->GetSize(); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(UVoxelDataAsset, NO_API)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelDataAsset(); \
	friend struct Z_Construct_UClass_UVoxelDataAsset_Statics; \
public: \
	DECLARE_CLASS(UVoxelDataAsset, UVoxelWorldGenerator, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelDataAsset) \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_ARCHIVESERIALIZER


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelDataAsset(); \
	friend struct Z_Construct_UClass_UVoxelDataAsset_Statics; \
public: \
	DECLARE_CLASS(UVoxelDataAsset, UVoxelWorldGenerator, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelDataAsset) \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_ARCHIVESERIALIZER


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelDataAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelDataAsset) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelDataAsset); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelDataAsset); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelDataAsset(UVoxelDataAsset&&); \
	NO_API UVoxelDataAsset(const UVoxelDataAsset&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelDataAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelDataAsset(UVoxelDataAsset&&); \
	NO_API UVoxelDataAsset(const UVoxelDataAsset&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelDataAsset); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelDataAsset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelDataAsset)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Version() { return STRUCT_OFFSET(UVoxelDataAsset, Version); } \
	FORCEINLINE static uint32 __PPO__CompressedData_DEPRECATED() { return STRUCT_OFFSET(UVoxelDataAsset, CompressedData_DEPRECATED); } \
	FORCEINLINE static uint32 __PPO__Size() { return STRUCT_OFFSET(UVoxelDataAsset, Size); }


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_166_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h_169_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelDataAsset_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
