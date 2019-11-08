// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVoxelCompressedWorldSave;
struct FVoxelUncompressedWorldSave;
#ifdef VOXEL_VoxelSave_generated_h
#error "VoxelSave.generated.h already included, missing '#pragma once' in VoxelSave.h"
#endif
#define VOXEL_VoxelSave_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_239_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FVoxelCompressedWorldSave_Statics; \
	static class UScriptStruct* StaticStruct();


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_26_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave_Statics; \
	static class UScriptStruct* StaticStruct();


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDecompressVoxelSave) \
	{ \
		P_GET_STRUCT_REF(FVoxelCompressedWorldSave,Z_Param_Out_CompressedSave); \
		P_GET_STRUCT_REF(FVoxelUncompressedWorldSave,Z_Param_Out_OutUncompressedSave); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UVoxelSaveUtilities::DecompressVoxelSave(Z_Param_Out_CompressedSave,Z_Param_Out_OutUncompressedSave); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCompressVoxelSave) \
	{ \
		P_GET_STRUCT_REF(FVoxelUncompressedWorldSave,Z_Param_Out_UncompressedSave); \
		P_GET_STRUCT_REF(FVoxelCompressedWorldSave,Z_Param_Out_OutCompressedSave); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelSaveUtilities::CompressVoxelSave(Z_Param_Out_UncompressedSave,Z_Param_Out_OutCompressedSave); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDecompressVoxelSave) \
	{ \
		P_GET_STRUCT_REF(FVoxelCompressedWorldSave,Z_Param_Out_CompressedSave); \
		P_GET_STRUCT_REF(FVoxelUncompressedWorldSave,Z_Param_Out_OutUncompressedSave); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UVoxelSaveUtilities::DecompressVoxelSave(Z_Param_Out_CompressedSave,Z_Param_Out_OutUncompressedSave); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCompressVoxelSave) \
	{ \
		P_GET_STRUCT_REF(FVoxelUncompressedWorldSave,Z_Param_Out_UncompressedSave); \
		P_GET_STRUCT_REF(FVoxelCompressedWorldSave,Z_Param_Out_OutCompressedSave); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelSaveUtilities::CompressVoxelSave(Z_Param_Out_UncompressedSave,Z_Param_Out_OutCompressedSave); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelSaveUtilities(); \
	friend struct Z_Construct_UClass_UVoxelSaveUtilities_Statics; \
public: \
	DECLARE_CLASS(UVoxelSaveUtilities, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelSaveUtilities)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelSaveUtilities(); \
	friend struct Z_Construct_UClass_UVoxelSaveUtilities_Statics; \
public: \
	DECLARE_CLASS(UVoxelSaveUtilities, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelSaveUtilities)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelSaveUtilities(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelSaveUtilities) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelSaveUtilities); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelSaveUtilities); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelSaveUtilities(UVoxelSaveUtilities&&); \
	NO_API UVoxelSaveUtilities(const UVoxelSaveUtilities&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelSaveUtilities(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelSaveUtilities(UVoxelSaveUtilities&&); \
	NO_API UVoxelSaveUtilities(const UVoxelSaveUtilities&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelSaveUtilities); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelSaveUtilities); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelSaveUtilities)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_308_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_311_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_RPC_WRAPPERS
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_RPC_WRAPPERS_NO_PURE_DECLS
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelWorldSaveObject(); \
	friend struct Z_Construct_UClass_UVoxelWorldSaveObject_Statics; \
public: \
	DECLARE_CLASS(UVoxelWorldSaveObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelWorldSaveObject)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelWorldSaveObject(); \
	friend struct Z_Construct_UClass_UVoxelWorldSaveObject_Statics; \
public: \
	DECLARE_CLASS(UVoxelWorldSaveObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelWorldSaveObject)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelWorldSaveObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelWorldSaveObject) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelWorldSaveObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelWorldSaveObject); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelWorldSaveObject(UVoxelWorldSaveObject&&); \
	NO_API UVoxelWorldSaveObject(const UVoxelWorldSaveObject&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelWorldSaveObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelWorldSaveObject(UVoxelWorldSaveObject&&); \
	NO_API UVoxelWorldSaveObject(const UVoxelWorldSaveObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelWorldSaveObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelWorldSaveObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelWorldSaveObject)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_352_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h_355_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelSave_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
