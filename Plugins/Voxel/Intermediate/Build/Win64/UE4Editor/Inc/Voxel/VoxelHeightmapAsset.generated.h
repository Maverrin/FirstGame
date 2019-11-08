// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VOXEL_VoxelHeightmapAsset_generated_h
#error "VoxelHeightmapAsset.generated.h already included, missing '#pragma once' in VoxelHeightmapAsset.h"
#endif
#define VOXEL_VoxelHeightmapAsset_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetHeight) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetHeight(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWidth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetWidth(); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetHeight) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetHeight(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWidth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetWidth(); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(UVoxelHeightmapAsset, NO_API)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelHeightmapAsset(); \
	friend struct Z_Construct_UClass_UVoxelHeightmapAsset_Statics; \
public: \
	DECLARE_CLASS(UVoxelHeightmapAsset, UVoxelWorldGenerator, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelHeightmapAsset) \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_ARCHIVESERIALIZER


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelHeightmapAsset(); \
	friend struct Z_Construct_UClass_UVoxelHeightmapAsset_Statics; \
public: \
	DECLARE_CLASS(UVoxelHeightmapAsset, UVoxelWorldGenerator, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelHeightmapAsset) \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_ARCHIVESERIALIZER


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelHeightmapAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelHeightmapAsset) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelHeightmapAsset); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelHeightmapAsset); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelHeightmapAsset(UVoxelHeightmapAsset&&); \
	NO_API UVoxelHeightmapAsset(const UVoxelHeightmapAsset&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelHeightmapAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelHeightmapAsset(UVoxelHeightmapAsset&&); \
	NO_API UVoxelHeightmapAsset(const UVoxelHeightmapAsset&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelHeightmapAsset); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelHeightmapAsset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelHeightmapAsset)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Version() { return STRUCT_OFFSET(UVoxelHeightmapAsset, Version); } \
	FORCEINLINE static uint32 __PPO__Width() { return STRUCT_OFFSET(UVoxelHeightmapAsset, Width); } \
	FORCEINLINE static uint32 __PPO__Height() { return STRUCT_OFFSET(UVoxelHeightmapAsset, Height); }


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_219_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_222_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_RPC_WRAPPERS
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_RPC_WRAPPERS_NO_PURE_DECLS
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelHeightmapAssetFloat(); \
	friend struct Z_Construct_UClass_UVoxelHeightmapAssetFloat_Statics; \
public: \
	DECLARE_CLASS(UVoxelHeightmapAssetFloat, UVoxelHeightmapAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelHeightmapAssetFloat)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelHeightmapAssetFloat(); \
	friend struct Z_Construct_UClass_UVoxelHeightmapAssetFloat_Statics; \
public: \
	DECLARE_CLASS(UVoxelHeightmapAssetFloat, UVoxelHeightmapAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelHeightmapAssetFloat)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelHeightmapAssetFloat(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelHeightmapAssetFloat) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelHeightmapAssetFloat); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelHeightmapAssetFloat); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelHeightmapAssetFloat(UVoxelHeightmapAssetFloat&&); \
	NO_API UVoxelHeightmapAssetFloat(const UVoxelHeightmapAssetFloat&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelHeightmapAssetFloat(UVoxelHeightmapAssetFloat&&); \
	NO_API UVoxelHeightmapAssetFloat(const UVoxelHeightmapAssetFloat&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelHeightmapAssetFloat); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelHeightmapAssetFloat); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UVoxelHeightmapAssetFloat)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_361_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_364_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_RPC_WRAPPERS
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_RPC_WRAPPERS_NO_PURE_DECLS
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelHeightmapAssetUINT16(); \
	friend struct Z_Construct_UClass_UVoxelHeightmapAssetUINT16_Statics; \
public: \
	DECLARE_CLASS(UVoxelHeightmapAssetUINT16, UVoxelHeightmapAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelHeightmapAssetUINT16)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelHeightmapAssetUINT16(); \
	friend struct Z_Construct_UClass_UVoxelHeightmapAssetUINT16_Statics; \
public: \
	DECLARE_CLASS(UVoxelHeightmapAssetUINT16, UVoxelHeightmapAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelHeightmapAssetUINT16)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelHeightmapAssetUINT16(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelHeightmapAssetUINT16) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelHeightmapAssetUINT16); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelHeightmapAssetUINT16); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelHeightmapAssetUINT16(UVoxelHeightmapAssetUINT16&&); \
	NO_API UVoxelHeightmapAssetUINT16(const UVoxelHeightmapAssetUINT16&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelHeightmapAssetUINT16(UVoxelHeightmapAssetUINT16&&); \
	NO_API UVoxelHeightmapAssetUINT16(const UVoxelHeightmapAssetUINT16&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelHeightmapAssetUINT16); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelHeightmapAssetUINT16); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UVoxelHeightmapAssetUINT16)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_395_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h_398_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelAssets_VoxelHeightmapAsset_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
