// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class AVoxelWorld;
struct FIntVector;
struct FLatentActionInfo;
#ifdef VOXEL_VoxelCraterTools_generated_h
#error "VoxelCraterTools.generated.h already included, missing '#pragma once' in VoxelCraterTools.h"
#endif
#define VOXEL_VoxelCraterTools_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAddCraterAsync) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PositionsSampleRate); \
		P_GET_TARRAY_REF(FIntVector,Z_Param_Out_Positions); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelCraterTools::AddCraterAsync(Z_Param_WorldContextObject,Z_Param_World,Z_Param_Position,Z_Param_Radius,Z_Param_PositionsSampleRate,Z_Param_Out_Positions,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddCrater) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PositionsSampleRate); \
		P_GET_TARRAY_REF(FIntVector,Z_Param_Out_Positions); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelCraterTools::AddCrater(Z_Param_World,Z_Param_Position,Z_Param_Radius,Z_Param_PositionsSampleRate,Z_Param_Out_Positions); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAddCraterAsync) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PositionsSampleRate); \
		P_GET_TARRAY_REF(FIntVector,Z_Param_Out_Positions); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelCraterTools::AddCraterAsync(Z_Param_WorldContextObject,Z_Param_World,Z_Param_Position,Z_Param_Radius,Z_Param_PositionsSampleRate,Z_Param_Out_Positions,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddCrater) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PositionsSampleRate); \
		P_GET_TARRAY_REF(FIntVector,Z_Param_Out_Positions); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelCraterTools::AddCrater(Z_Param_World,Z_Param_Position,Z_Param_Radius,Z_Param_PositionsSampleRate,Z_Param_Out_Positions); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelCraterTools(); \
	friend struct Z_Construct_UClass_UVoxelCraterTools_Statics; \
public: \
	DECLARE_CLASS(UVoxelCraterTools, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelCraterTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelCraterTools(); \
	friend struct Z_Construct_UClass_UVoxelCraterTools_Statics; \
public: \
	DECLARE_CLASS(UVoxelCraterTools, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelCraterTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelCraterTools(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelCraterTools) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelCraterTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelCraterTools); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelCraterTools(UVoxelCraterTools&&); \
	NO_API UVoxelCraterTools(const UVoxelCraterTools&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelCraterTools(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelCraterTools(UVoxelCraterTools&&); \
	NO_API UVoxelCraterTools(const UVoxelCraterTools&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelCraterTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelCraterTools); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelCraterTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_44_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h_47_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelCraterTools_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
