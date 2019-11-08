// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VOXEL_VoxelStats_generated_h
#error "VoxelStats.generated.h already included, missing '#pragma once' in VoxelStats.h"
#endif
#define VOXEL_VoxelStats_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStartRecordingStats) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelStatsHelper::StartRecordingStats(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopRecordingStatsAndSaveStatsFile) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelStatsHelper::StopRecordingStatsAndSaveStatsFile(); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStartRecordingStats) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelStatsHelper::StartRecordingStats(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopRecordingStatsAndSaveStatsFile) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelStatsHelper::StopRecordingStatsAndSaveStatsFile(); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelStatsHelper(); \
	friend struct Z_Construct_UClass_UVoxelStatsHelper_Statics; \
public: \
	DECLARE_CLASS(UVoxelStatsHelper, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelStatsHelper)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelStatsHelper(); \
	friend struct Z_Construct_UClass_UVoxelStatsHelper_Statics; \
public: \
	DECLARE_CLASS(UVoxelStatsHelper, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelStatsHelper)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelStatsHelper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelStatsHelper) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelStatsHelper); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelStatsHelper); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelStatsHelper(UVoxelStatsHelper&&); \
	NO_API UVoxelStatsHelper(const UVoxelStatsHelper&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelStatsHelper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelStatsHelper(UVoxelStatsHelper&&); \
	NO_API UVoxelStatsHelper(const UVoxelStatsHelper&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelStatsHelper); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelStatsHelper); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelStatsHelper)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_223_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h_226_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelDebug_VoxelStats_h


#define FOREACH_ENUM_EVOXELSTATSTYPE(op) \
	op(EVoxelStatsType::NormalMarchingCubes) \
	op(EVoxelStatsType::TransitionsMarchingCubes) \
	op(EVoxelStatsType::NormalCubic) \
	op(EVoxelStatsType::TransitionsCubic) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
