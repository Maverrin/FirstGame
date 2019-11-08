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
class AVoxelWorld;
class UVoxelDataAsset;
struct FIntVector;
enum class EVoxelAssetPositionOffset : uint8;
enum class EVoxelAssetSmartImportType : uint8;
#ifdef VOXEL_VoxelAssetTools_generated_h
#error "VoxelAssetTools.generated.h already included, missing '#pragma once' in VoxelAssetTools.h"
#endif
#define VOXEL_VoxelAssetTools_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execImportAssetAsync) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_OBJECT(UVoxelDataAsset,Z_Param_Asset); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_GET_ENUM(EVoxelAssetPositionOffset,Z_Param_OffsetX); \
		P_GET_ENUM(EVoxelAssetPositionOffset,Z_Param_OffsetY); \
		P_GET_ENUM(EVoxelAssetPositionOffset,Z_Param_OffsetZ); \
		P_GET_UBOOL(Z_Param_bImportValues); \
		P_GET_UBOOL(Z_Param_bImportMaterials); \
		P_GET_UBOOL(Z_Param_bSmartImport); \
		P_GET_ENUM(EVoxelAssetSmartImportType,Z_Param_SmartImportType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelAssetTools::ImportAssetAsync(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_World,Z_Param_Asset,Z_Param_Out_Position,EVoxelAssetPositionOffset(Z_Param_OffsetX),EVoxelAssetPositionOffset(Z_Param_OffsetY),EVoxelAssetPositionOffset(Z_Param_OffsetZ),Z_Param_bImportValues,Z_Param_bImportMaterials,Z_Param_bSmartImport,EVoxelAssetSmartImportType(Z_Param_SmartImportType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execImportAsset) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_OBJECT(UVoxelDataAsset,Z_Param_Asset); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_GET_ENUM(EVoxelAssetPositionOffset,Z_Param_OffsetX); \
		P_GET_ENUM(EVoxelAssetPositionOffset,Z_Param_OffsetY); \
		P_GET_ENUM(EVoxelAssetPositionOffset,Z_Param_OffsetZ); \
		P_GET_UBOOL(Z_Param_bImportValues); \
		P_GET_UBOOL(Z_Param_bImportMaterials); \
		P_GET_UBOOL(Z_Param_bSmartImport); \
		P_GET_ENUM(EVoxelAssetSmartImportType,Z_Param_SmartImportType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelAssetTools::ImportAsset(Z_Param_World,Z_Param_Asset,Z_Param_Out_Position,EVoxelAssetPositionOffset(Z_Param_OffsetX),EVoxelAssetPositionOffset(Z_Param_OffsetY),EVoxelAssetPositionOffset(Z_Param_OffsetZ),Z_Param_bImportValues,Z_Param_bImportMaterials,Z_Param_bSmartImport,EVoxelAssetSmartImportType(Z_Param_SmartImportType)); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execImportAssetAsync) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_OBJECT(UVoxelDataAsset,Z_Param_Asset); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_GET_ENUM(EVoxelAssetPositionOffset,Z_Param_OffsetX); \
		P_GET_ENUM(EVoxelAssetPositionOffset,Z_Param_OffsetY); \
		P_GET_ENUM(EVoxelAssetPositionOffset,Z_Param_OffsetZ); \
		P_GET_UBOOL(Z_Param_bImportValues); \
		P_GET_UBOOL(Z_Param_bImportMaterials); \
		P_GET_UBOOL(Z_Param_bSmartImport); \
		P_GET_ENUM(EVoxelAssetSmartImportType,Z_Param_SmartImportType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelAssetTools::ImportAssetAsync(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_World,Z_Param_Asset,Z_Param_Out_Position,EVoxelAssetPositionOffset(Z_Param_OffsetX),EVoxelAssetPositionOffset(Z_Param_OffsetY),EVoxelAssetPositionOffset(Z_Param_OffsetZ),Z_Param_bImportValues,Z_Param_bImportMaterials,Z_Param_bSmartImport,EVoxelAssetSmartImportType(Z_Param_SmartImportType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execImportAsset) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_OBJECT(UVoxelDataAsset,Z_Param_Asset); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_GET_ENUM(EVoxelAssetPositionOffset,Z_Param_OffsetX); \
		P_GET_ENUM(EVoxelAssetPositionOffset,Z_Param_OffsetY); \
		P_GET_ENUM(EVoxelAssetPositionOffset,Z_Param_OffsetZ); \
		P_GET_UBOOL(Z_Param_bImportValues); \
		P_GET_UBOOL(Z_Param_bImportMaterials); \
		P_GET_UBOOL(Z_Param_bSmartImport); \
		P_GET_ENUM(EVoxelAssetSmartImportType,Z_Param_SmartImportType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelAssetTools::ImportAsset(Z_Param_World,Z_Param_Asset,Z_Param_Out_Position,EVoxelAssetPositionOffset(Z_Param_OffsetX),EVoxelAssetPositionOffset(Z_Param_OffsetY),EVoxelAssetPositionOffset(Z_Param_OffsetZ),Z_Param_bImportValues,Z_Param_bImportMaterials,Z_Param_bSmartImport,EVoxelAssetSmartImportType(Z_Param_SmartImportType)); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelAssetTools(); \
	friend struct Z_Construct_UClass_UVoxelAssetTools_Statics; \
public: \
	DECLARE_CLASS(UVoxelAssetTools, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelAssetTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelAssetTools(); \
	friend struct Z_Construct_UClass_UVoxelAssetTools_Statics; \
public: \
	DECLARE_CLASS(UVoxelAssetTools, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelAssetTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelAssetTools(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelAssetTools) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelAssetTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelAssetTools); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelAssetTools(UVoxelAssetTools&&); \
	NO_API UVoxelAssetTools(const UVoxelAssetTools&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelAssetTools(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelAssetTools(UVoxelAssetTools&&); \
	NO_API UVoxelAssetTools(const UVoxelAssetTools&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelAssetTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelAssetTools); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelAssetTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_60_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h_63_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelAssetTools_h


#define FOREACH_ENUM_EVOXELASSETSMARTIMPORTTYPE(op) \
	op(EVoxelAssetSmartImportType::Add) \
	op(EVoxelAssetSmartImportType::Remove) 
#define FOREACH_ENUM_EVOXELASSETPOSITIONOFFSET(op) \
	op(EVoxelAssetPositionOffset::PositionIsMin) \
	op(EVoxelAssetPositionOffset::PositionIsMiddle) \
	op(EVoxelAssetPositionOffset::PositionIsMax) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
