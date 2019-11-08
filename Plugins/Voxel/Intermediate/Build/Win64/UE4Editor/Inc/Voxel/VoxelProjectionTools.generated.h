// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EBlueprintSuccess : uint8;
struct FGetVoxelProjectionVoxel;
class AVoxelWorld;
struct FVector;
enum class EFailReason : uint8;
struct FModifiedVoxelMaterial;
struct FVoxelPaintMaterial;
class UCurveFloat;
struct FModifiedVoxelValue;
class UObject;
struct FLatentActionInfo;
#ifdef VOXEL_VoxelProjectionTools_generated_h
#error "VoxelProjectionTools.generated.h already included, missing '#pragma once' in VoxelProjectionTools.h"
#endif
#define VOXEL_VoxelProjectionTools_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_63_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics; \
	VOXEL_API static class UScriptStruct* StaticStruct();


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_48_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics; \
	VOXEL_API static class UScriptStruct* StaticStruct();


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_33_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics; \
	VOXEL_API static class UScriptStruct* StaticStruct();


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetVoxelsProjection) \
	{ \
		P_GET_ENUM_REF(EBlueprintSuccess,Z_Param_Out_Branches); \
		P_GET_TARRAY_REF(FGetVoxelProjectionVoxel,Z_Param_Out_OutVoxels); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ToolHeight); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StepInVoxel); \
		P_GET_UBOOL(Z_Param_bShowRaycasts); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelProjectionTools::GetVoxelsProjection((EBlueprintSuccess&)(Z_Param_Out_Branches),Z_Param_Out_OutVoxels,Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_Radius,Z_Param_ToolHeight,Z_Param_EditDistance,Z_Param_StepInVoxel,Z_Param_bShowRaycasts); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterialProjectionNew) \
	{ \
		P_GET_ENUM_REF(EBlueprintSuccess,Z_Param_Out_Branches); \
		P_GET_ENUM_REF(EFailReason,Z_Param_Out_FailReason); \
		P_GET_TARRAY_REF(FModifiedVoxelMaterial,Z_Param_Out_ModifiedVoxels); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_STRUCT(FVoxelPaintMaterial,Z_Param_PaintMaterial); \
		P_GET_OBJECT(UCurveFloat,Z_Param_StrengthCurve); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ToolHeight); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StepInVoxel); \
		P_GET_PROPERTY(UIntProperty,Z_Param_TimeoutInMicroSeconds); \
		P_GET_UBOOL(Z_Param_bShowRaycasts); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelProjectionTools::SetMaterialProjectionNew((EBlueprintSuccess&)(Z_Param_Out_Branches),(EFailReason&)(Z_Param_Out_FailReason),Z_Param_Out_ModifiedVoxels,Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_PaintMaterial,Z_Param_StrengthCurve,Z_Param_Radius,Z_Param_ToolHeight,Z_Param_EditDistance,Z_Param_StepInVoxel,Z_Param_TimeoutInMicroSeconds,Z_Param_bShowRaycasts); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetValueProjectionNew) \
	{ \
		P_GET_ENUM_REF(EBlueprintSuccess,Z_Param_Out_Branches); \
		P_GET_ENUM_REF(EFailReason,Z_Param_Out_FailReason); \
		P_GET_TARRAY_REF(FModifiedVoxelValue,Z_Param_Out_ModifiedVoxels); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Strength); \
		P_GET_OBJECT(UCurveFloat,Z_Param_StrengthCurve); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ToolHeight); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StepInVoxel); \
		P_GET_PROPERTY(UIntProperty,Z_Param_TimeoutInMicroSeconds); \
		P_GET_UBOOL(Z_Param_bShowRaycasts); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelProjectionTools::SetValueProjectionNew((EBlueprintSuccess&)(Z_Param_Out_Branches),(EFailReason&)(Z_Param_Out_FailReason),Z_Param_Out_ModifiedVoxels,Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_Radius,Z_Param_Strength,Z_Param_StrengthCurve,Z_Param_ToolHeight,Z_Param_EditDistance,Z_Param_StepInVoxel,Z_Param_TimeoutInMicroSeconds,Z_Param_bShowRaycasts); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelsProjectionAsync) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_ENUM_REF(EBlueprintSuccess,Z_Param_Out_Branches); \
		P_GET_TARRAY_REF(FGetVoxelProjectionVoxel,Z_Param_Out_OutVoxels); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ToolHeight); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StepInVoxel); \
		P_GET_UBOOL(Z_Param_bShowRaycasts); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelProjectionTools::GetVoxelsProjectionAsync(Z_Param_WorldContextObject,Z_Param_LatentInfo,(EBlueprintSuccess&)(Z_Param_Out_Branches),Z_Param_Out_OutVoxels,Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_Radius,Z_Param_ToolHeight,Z_Param_EditDistance,Z_Param_StepInVoxel,Z_Param_bShowRaycasts); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterialProjectionAsync) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_ENUM_REF(EBlueprintSuccess,Z_Param_Out_Branches); \
		P_GET_ENUM_REF(EFailReason,Z_Param_Out_FailReason); \
		P_GET_TARRAY_REF(FModifiedVoxelMaterial,Z_Param_Out_ModifiedVoxels); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_STRUCT(FVoxelPaintMaterial,Z_Param_PaintMaterial); \
		P_GET_OBJECT(UCurveFloat,Z_Param_StrengthCurve); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ToolHeight); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StepInVoxel); \
		P_GET_PROPERTY(UIntProperty,Z_Param_TimeoutInMicroSeconds); \
		P_GET_UBOOL(Z_Param_bShowRaycasts); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelProjectionTools::SetMaterialProjectionAsync(Z_Param_WorldContextObject,Z_Param_LatentInfo,(EBlueprintSuccess&)(Z_Param_Out_Branches),(EFailReason&)(Z_Param_Out_FailReason),Z_Param_Out_ModifiedVoxels,Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_PaintMaterial,Z_Param_StrengthCurve,Z_Param_Radius,Z_Param_ToolHeight,Z_Param_EditDistance,Z_Param_StepInVoxel,Z_Param_TimeoutInMicroSeconds,Z_Param_bShowRaycasts); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetValueProjectionAsync) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_ENUM_REF(EBlueprintSuccess,Z_Param_Out_Branches); \
		P_GET_ENUM_REF(EFailReason,Z_Param_Out_FailReason); \
		P_GET_TARRAY_REF(FModifiedVoxelValue,Z_Param_Out_ModifiedVoxels); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Strength); \
		P_GET_OBJECT(UCurveFloat,Z_Param_StrengthCurve); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ToolHeight); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StepInVoxel); \
		P_GET_PROPERTY(UIntProperty,Z_Param_TimeoutInMicroSeconds); \
		P_GET_UBOOL(Z_Param_bShowRaycasts); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelProjectionTools::SetValueProjectionAsync(Z_Param_WorldContextObject,Z_Param_LatentInfo,(EBlueprintSuccess&)(Z_Param_Out_Branches),(EFailReason&)(Z_Param_Out_FailReason),Z_Param_Out_ModifiedVoxels,Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_Radius,Z_Param_Strength,Z_Param_StrengthCurve,Z_Param_ToolHeight,Z_Param_EditDistance,Z_Param_StepInVoxel,Z_Param_TimeoutInMicroSeconds,Z_Param_bShowRaycasts); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetVoxelsProjection) \
	{ \
		P_GET_ENUM_REF(EBlueprintSuccess,Z_Param_Out_Branches); \
		P_GET_TARRAY_REF(FGetVoxelProjectionVoxel,Z_Param_Out_OutVoxels); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ToolHeight); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StepInVoxel); \
		P_GET_UBOOL(Z_Param_bShowRaycasts); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelProjectionTools::GetVoxelsProjection((EBlueprintSuccess&)(Z_Param_Out_Branches),Z_Param_Out_OutVoxels,Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_Radius,Z_Param_ToolHeight,Z_Param_EditDistance,Z_Param_StepInVoxel,Z_Param_bShowRaycasts); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterialProjectionNew) \
	{ \
		P_GET_ENUM_REF(EBlueprintSuccess,Z_Param_Out_Branches); \
		P_GET_ENUM_REF(EFailReason,Z_Param_Out_FailReason); \
		P_GET_TARRAY_REF(FModifiedVoxelMaterial,Z_Param_Out_ModifiedVoxels); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_STRUCT(FVoxelPaintMaterial,Z_Param_PaintMaterial); \
		P_GET_OBJECT(UCurveFloat,Z_Param_StrengthCurve); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ToolHeight); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StepInVoxel); \
		P_GET_PROPERTY(UIntProperty,Z_Param_TimeoutInMicroSeconds); \
		P_GET_UBOOL(Z_Param_bShowRaycasts); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelProjectionTools::SetMaterialProjectionNew((EBlueprintSuccess&)(Z_Param_Out_Branches),(EFailReason&)(Z_Param_Out_FailReason),Z_Param_Out_ModifiedVoxels,Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_PaintMaterial,Z_Param_StrengthCurve,Z_Param_Radius,Z_Param_ToolHeight,Z_Param_EditDistance,Z_Param_StepInVoxel,Z_Param_TimeoutInMicroSeconds,Z_Param_bShowRaycasts); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetValueProjectionNew) \
	{ \
		P_GET_ENUM_REF(EBlueprintSuccess,Z_Param_Out_Branches); \
		P_GET_ENUM_REF(EFailReason,Z_Param_Out_FailReason); \
		P_GET_TARRAY_REF(FModifiedVoxelValue,Z_Param_Out_ModifiedVoxels); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Strength); \
		P_GET_OBJECT(UCurveFloat,Z_Param_StrengthCurve); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ToolHeight); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StepInVoxel); \
		P_GET_PROPERTY(UIntProperty,Z_Param_TimeoutInMicroSeconds); \
		P_GET_UBOOL(Z_Param_bShowRaycasts); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelProjectionTools::SetValueProjectionNew((EBlueprintSuccess&)(Z_Param_Out_Branches),(EFailReason&)(Z_Param_Out_FailReason),Z_Param_Out_ModifiedVoxels,Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_Radius,Z_Param_Strength,Z_Param_StrengthCurve,Z_Param_ToolHeight,Z_Param_EditDistance,Z_Param_StepInVoxel,Z_Param_TimeoutInMicroSeconds,Z_Param_bShowRaycasts); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelsProjectionAsync) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_ENUM_REF(EBlueprintSuccess,Z_Param_Out_Branches); \
		P_GET_TARRAY_REF(FGetVoxelProjectionVoxel,Z_Param_Out_OutVoxels); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ToolHeight); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StepInVoxel); \
		P_GET_UBOOL(Z_Param_bShowRaycasts); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelProjectionTools::GetVoxelsProjectionAsync(Z_Param_WorldContextObject,Z_Param_LatentInfo,(EBlueprintSuccess&)(Z_Param_Out_Branches),Z_Param_Out_OutVoxels,Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_Radius,Z_Param_ToolHeight,Z_Param_EditDistance,Z_Param_StepInVoxel,Z_Param_bShowRaycasts); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterialProjectionAsync) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_ENUM_REF(EBlueprintSuccess,Z_Param_Out_Branches); \
		P_GET_ENUM_REF(EFailReason,Z_Param_Out_FailReason); \
		P_GET_TARRAY_REF(FModifiedVoxelMaterial,Z_Param_Out_ModifiedVoxels); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_STRUCT(FVoxelPaintMaterial,Z_Param_PaintMaterial); \
		P_GET_OBJECT(UCurveFloat,Z_Param_StrengthCurve); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ToolHeight); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StepInVoxel); \
		P_GET_PROPERTY(UIntProperty,Z_Param_TimeoutInMicroSeconds); \
		P_GET_UBOOL(Z_Param_bShowRaycasts); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelProjectionTools::SetMaterialProjectionAsync(Z_Param_WorldContextObject,Z_Param_LatentInfo,(EBlueprintSuccess&)(Z_Param_Out_Branches),(EFailReason&)(Z_Param_Out_FailReason),Z_Param_Out_ModifiedVoxels,Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_PaintMaterial,Z_Param_StrengthCurve,Z_Param_Radius,Z_Param_ToolHeight,Z_Param_EditDistance,Z_Param_StepInVoxel,Z_Param_TimeoutInMicroSeconds,Z_Param_bShowRaycasts); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetValueProjectionAsync) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_ENUM_REF(EBlueprintSuccess,Z_Param_Out_Branches); \
		P_GET_ENUM_REF(EFailReason,Z_Param_Out_FailReason); \
		P_GET_TARRAY_REF(FModifiedVoxelValue,Z_Param_Out_ModifiedVoxels); \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Strength); \
		P_GET_OBJECT(UCurveFloat,Z_Param_StrengthCurve); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ToolHeight); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StepInVoxel); \
		P_GET_PROPERTY(UIntProperty,Z_Param_TimeoutInMicroSeconds); \
		P_GET_UBOOL(Z_Param_bShowRaycasts); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelProjectionTools::SetValueProjectionAsync(Z_Param_WorldContextObject,Z_Param_LatentInfo,(EBlueprintSuccess&)(Z_Param_Out_Branches),(EFailReason&)(Z_Param_Out_FailReason),Z_Param_Out_ModifiedVoxels,Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_Radius,Z_Param_Strength,Z_Param_StrengthCurve,Z_Param_ToolHeight,Z_Param_EditDistance,Z_Param_StepInVoxel,Z_Param_TimeoutInMicroSeconds,Z_Param_bShowRaycasts); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelProjectionTools(); \
	friend struct Z_Construct_UClass_UVoxelProjectionTools_Statics; \
public: \
	DECLARE_CLASS(UVoxelProjectionTools, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelProjectionTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelProjectionTools(); \
	friend struct Z_Construct_UClass_UVoxelProjectionTools_Statics; \
public: \
	DECLARE_CLASS(UVoxelProjectionTools, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelProjectionTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelProjectionTools(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelProjectionTools) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelProjectionTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelProjectionTools); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelProjectionTools(UVoxelProjectionTools&&); \
	NO_API UVoxelProjectionTools(const UVoxelProjectionTools&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelProjectionTools(UVoxelProjectionTools&&); \
	NO_API UVoxelProjectionTools(const UVoxelProjectionTools&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelProjectionTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelProjectionTools); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UVoxelProjectionTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_139_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h_142_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelProjectionTools_h


#define FOREACH_ENUM_EFAILREASON(op) \
	op(EFailReason::VoxelDataLocked) \
	op(EFailReason::LinetracesPending) \
	op(EFailReason::OtherError) 
#define FOREACH_ENUM_EBLUEPRINTSUCCESS(op) \
	op(EBlueprintSuccess::Success) \
	op(EBlueprintSuccess::Failed) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
