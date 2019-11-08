// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VOXEL_VoxelNode_generated_h
#error "VoxelNode.generated.h already included, missing '#pragma once' in VoxelNode.h"
#endif
#define VOXEL_VoxelNode_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_66_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FVoxelPin_Statics; \
	VOXEL_API static class UScriptStruct* StaticStruct();


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_RPC_WRAPPERS
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_RPC_WRAPPERS_NO_PURE_DECLS
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelNode(); \
	friend struct Z_Construct_UClass_UVoxelNode_Statics; \
public: \
	DECLARE_CLASS(UVoxelNode, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelNode)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelNode(); \
	friend struct Z_Construct_UClass_UVoxelNode_Statics; \
public: \
	DECLARE_CLASS(UVoxelNode, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelNode)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelNode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelNode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelNode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelNode(UVoxelNode&&); \
	NO_API UVoxelNode(const UVoxelNode&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelNode(UVoxelNode&&); \
	NO_API UVoxelNode(const UVoxelNode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelNode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelNode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelNode)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__InputPinCount() { return STRUCT_OFFSET(UVoxelNode, InputPinCount); }


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_102_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h_105_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelGraph_VoxelNode_h


#define FOREACH_ENUM_EVOXELPINCATEGORY(op) \
	op(EVoxelPinCategory::Exec) \
	op(EVoxelPinCategory::Boolean) \
	op(EVoxelPinCategory::Int) \
	op(EVoxelPinCategory::Float) \
	op(EVoxelPinCategory::Material) \
	op(EVoxelPinCategory::Seed) \
	op(EVoxelPinCategory::Wildcard) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
