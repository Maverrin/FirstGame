// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FKey;
class AVoxelMarker;
class AVoxelWorld;
enum class EVoxelEditorTool_SculptPaint : uint8;
struct FVector;
#ifdef VOXELEDITOR_VoxelDefaultEditorTools_generated_h
#error "VoxelDefaultEditorTools.generated.h already included, missing '#pragma once' in VoxelDefaultEditorTools.h"
#endif
#define VOXELEDITOR_VoxelDefaultEditorTools_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEndEdit) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EndEdit(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsKeyDown) \
	{ \
		P_GET_STRUCT(FKey,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsKeyDown(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMarker) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AVoxelMarker**)Z_Param__Result=P_THIS->GetMarker(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentVoxelWorld) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AVoxelWorld**)Z_Param__Result=P_THIS->GetCurrentVoxelWorld(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentMode) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EVoxelEditorTool_SculptPaint*)Z_Param__Result=P_THIS->GetCurrentMode(); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEndEdit) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EndEdit(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsKeyDown) \
	{ \
		P_GET_STRUCT(FKey,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsKeyDown(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMarker) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AVoxelMarker**)Z_Param__Result=P_THIS->GetMarker(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentVoxelWorld) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AVoxelWorld**)Z_Param__Result=P_THIS->GetCurrentVoxelWorld(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentMode) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EVoxelEditorTool_SculptPaint*)Z_Param__Result=P_THIS->GetCurrentMode(); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_EVENT_PARMS \
	struct VoxelEditorTool_SculptPaintBase_eventK2_HandleVoxelWorldClick_Parms \
	{ \
		FVector Position; \
		FVector Normal; \
	}; \
	struct VoxelEditorTool_SculptPaintBase_eventK2_InputAxis_Parms \
	{ \
		FKey Key; \
		float Delta; \
		float DeltaTime; \
		bool Handled; \
	}; \
	struct VoxelEditorTool_SculptPaintBase_eventK2_InputKey_Parms \
	{ \
		FKey Key; \
		TEnumAsByte<EInputEvent> Event; \
		bool Handled; \
	}; \
	struct VoxelEditorTool_SculptPaintBase_eventK2_Tick_Parms \
	{ \
		float DeltaTime; \
		FVector LastPosition; \
		FVector LastNormal; \
		bool bHidden; \
	};


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_CALLBACK_WRAPPERS
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelEditorTool_SculptPaintBase(); \
	friend struct Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics; \
public: \
	DECLARE_CLASS(UVoxelEditorTool_SculptPaintBase, UVoxelEditorTool, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/VoxelEditor"), NO_API) \
	DECLARE_SERIALIZER(UVoxelEditorTool_SculptPaintBase)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelEditorTool_SculptPaintBase(); \
	friend struct Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics; \
public: \
	DECLARE_CLASS(UVoxelEditorTool_SculptPaintBase, UVoxelEditorTool, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/VoxelEditor"), NO_API) \
	DECLARE_SERIALIZER(UVoxelEditorTool_SculptPaintBase)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelEditorTool_SculptPaintBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelEditorTool_SculptPaintBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelEditorTool_SculptPaintBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelEditorTool_SculptPaintBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelEditorTool_SculptPaintBase(UVoxelEditorTool_SculptPaintBase&&); \
	NO_API UVoxelEditorTool_SculptPaintBase(const UVoxelEditorTool_SculptPaintBase&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelEditorTool_SculptPaintBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelEditorTool_SculptPaintBase(UVoxelEditorTool_SculptPaintBase&&); \
	NO_API UVoxelEditorTool_SculptPaintBase(const UVoxelEditorTool_SculptPaintBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelEditorTool_SculptPaintBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelEditorTool_SculptPaintBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelEditorTool_SculptPaintBase)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Marker() { return STRUCT_OFFSET(UVoxelEditorTool_SculptPaintBase, Marker); }


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_105_PROLOG \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_EVENT_PARMS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_CALLBACK_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_CALLBACK_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h_108_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_VoxelEditor_Private_VoxelEditorTools_VoxelDefaultEditorTools_h


#define FOREACH_ENUM_EVOXELEDITORTOOL_ICONS(op) \
	op(EVoxelEditorTool_Icons::Projection) \
	op(EVoxelEditorTool_Icons::Sphere) \
	op(EVoxelEditorTool_Icons::Box) \
	op(EVoxelEditorTool_Icons::Custom0) \
	op(EVoxelEditorTool_Icons::Custom1) \
	op(EVoxelEditorTool_Icons::Custom2) \
	op(EVoxelEditorTool_Icons::Custom3) \
	op(EVoxelEditorTool_Icons::Custom4) \
	op(EVoxelEditorTool_Icons::Custom5) \
	op(EVoxelEditorTool_Icons::Custom6) \
	op(EVoxelEditorTool_Icons::Custom7) \
	op(EVoxelEditorTool_Icons::Custom8) \
	op(EVoxelEditorTool_Icons::Custom9) 
#define FOREACH_ENUM_EVOXELEDITORTOOL_SCULPTPAINT(op) \
	op(EVoxelEditorTool_SculptPaint::Sculpt) \
	op(EVoxelEditorTool_SculptPaint::Paint) \
	op(EVoxelEditorTool_SculptPaint::Grass) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
