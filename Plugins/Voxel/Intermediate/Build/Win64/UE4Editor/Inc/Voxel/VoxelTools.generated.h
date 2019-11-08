// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AVoxelWorld;
struct FVector;
struct FIntBox;
struct FVoxelPaintMaterial;
struct FIntVector;
class UCurveFloat;
#ifdef VOXEL_VoxelTools_generated_h
#error "VoxelTools.generated.h already included, missing '#pragma once' in VoxelTools.h"
#endif
#define VOXEL_VoxelTools_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execFlatten) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Strength); \
		P_GET_UBOOL(Z_Param_bDontModifyVoxelsAroundPosition); \
		P_GET_UBOOL(Z_Param_bDontModifyEmptyVoxels); \
		P_GET_UBOOL(Z_Param_bDontModifyFullVoxels); \
		P_GET_PROPERTY(UIntProperty,Z_Param_TimeoutInMicroSeconds); \
		P_GET_UBOOL(Z_Param_bShowModifiedVoxels); \
		P_GET_UBOOL(Z_Param_bShowTestedVoxels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UVoxelTools::Flatten(Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_Radius,Z_Param_Strength,Z_Param_bDontModifyVoxelsAroundPosition,Z_Param_bDontModifyEmptyVoxels,Z_Param_bDontModifyFullVoxels,Z_Param_TimeoutInMicroSeconds,Z_Param_bShowModifiedVoxels,Z_Param_bShowTestedVoxels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRoundVoxels) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::RoundVoxels(Z_Param_World,Z_Param_Bounds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBoxAsDirty) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_GET_UBOOL(Z_Param_bSetValuesAsDirty); \
		P_GET_UBOOL(Z_Param_bSetMaterialsAsDirty); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::SetBoxAsDirty(Z_Param_World,Z_Param_Bounds,Z_Param_bSetValuesAsDirty,Z_Param_bSetMaterialsAsDirty); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterialBox) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_GET_STRUCT(FVoxelPaintMaterial,Z_Param_PaintMaterial); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::SetMaterialBox(Z_Param_World,Z_Param_Bounds,Z_Param_PaintMaterial); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveBox) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::RemoveBox(Z_Param_World,Z_Param_Bounds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddBox) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::AddBox(Z_Param_World,Z_Param_Bounds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetValueBox) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::SetValueBox(Z_Param_World,Z_Param_Bounds,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterialSphere) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_STRUCT(FVoxelPaintMaterial,Z_Param_PaintMaterial); \
		P_GET_OBJECT(UCurveFloat,Z_Param_StrengthCurve); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::SetMaterialSphere(Z_Param_World,Z_Param_Position,Z_Param_Radius,Z_Param_PaintMaterial,Z_Param_StrengthCurve); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveSphere) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::RemoveSphere(Z_Param_World,Z_Param_Position,Z_Param_Radius); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddSphere) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::AddSphere(Z_Param_World,Z_Param_Position,Z_Param_Radius); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetValueSphere) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::SetValueSphere(Z_Param_World,Z_Param_Position,Z_Param_Radius,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddNeighborsToSet) \
	{ \
		P_GET_TSET_REF(FIntVector,Z_Param_Out_InSet); \
		P_GET_TSET_REF(FIntVector,Z_Param_Out_OutSet); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::AddNeighborsToSet(Z_Param_Out_InSet,Z_Param_Out_OutSet); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execFlatten) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Strength); \
		P_GET_UBOOL(Z_Param_bDontModifyVoxelsAroundPosition); \
		P_GET_UBOOL(Z_Param_bDontModifyEmptyVoxels); \
		P_GET_UBOOL(Z_Param_bDontModifyFullVoxels); \
		P_GET_PROPERTY(UIntProperty,Z_Param_TimeoutInMicroSeconds); \
		P_GET_UBOOL(Z_Param_bShowModifiedVoxels); \
		P_GET_UBOOL(Z_Param_bShowTestedVoxels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UVoxelTools::Flatten(Z_Param_World,Z_Param_Position,Z_Param_Normal,Z_Param_Radius,Z_Param_Strength,Z_Param_bDontModifyVoxelsAroundPosition,Z_Param_bDontModifyEmptyVoxels,Z_Param_bDontModifyFullVoxels,Z_Param_TimeoutInMicroSeconds,Z_Param_bShowModifiedVoxels,Z_Param_bShowTestedVoxels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRoundVoxels) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::RoundVoxels(Z_Param_World,Z_Param_Bounds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBoxAsDirty) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_GET_UBOOL(Z_Param_bSetValuesAsDirty); \
		P_GET_UBOOL(Z_Param_bSetMaterialsAsDirty); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::SetBoxAsDirty(Z_Param_World,Z_Param_Bounds,Z_Param_bSetValuesAsDirty,Z_Param_bSetMaterialsAsDirty); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterialBox) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_GET_STRUCT(FVoxelPaintMaterial,Z_Param_PaintMaterial); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::SetMaterialBox(Z_Param_World,Z_Param_Bounds,Z_Param_PaintMaterial); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveBox) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::RemoveBox(Z_Param_World,Z_Param_Bounds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddBox) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::AddBox(Z_Param_World,Z_Param_Bounds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetValueBox) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::SetValueBox(Z_Param_World,Z_Param_Bounds,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterialSphere) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_STRUCT(FVoxelPaintMaterial,Z_Param_PaintMaterial); \
		P_GET_OBJECT(UCurveFloat,Z_Param_StrengthCurve); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::SetMaterialSphere(Z_Param_World,Z_Param_Position,Z_Param_Radius,Z_Param_PaintMaterial,Z_Param_StrengthCurve); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveSphere) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::RemoveSphere(Z_Param_World,Z_Param_Position,Z_Param_Radius); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddSphere) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::AddSphere(Z_Param_World,Z_Param_Position,Z_Param_Radius); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetValueSphere) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::SetValueSphere(Z_Param_World,Z_Param_Position,Z_Param_Radius,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddNeighborsToSet) \
	{ \
		P_GET_TSET_REF(FIntVector,Z_Param_Out_InSet); \
		P_GET_TSET_REF(FIntVector,Z_Param_Out_OutSet); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVoxelTools::AddNeighborsToSet(Z_Param_Out_InSet,Z_Param_Out_OutSet); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelTools(); \
	friend struct Z_Construct_UClass_UVoxelTools_Statics; \
public: \
	DECLARE_CLASS(UVoxelTools, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelTools(); \
	friend struct Z_Construct_UClass_UVoxelTools_Statics; \
public: \
	DECLARE_CLASS(UVoxelTools, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(UVoxelTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelTools(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelTools) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelTools); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelTools(UVoxelTools&&); \
	NO_API UVoxelTools(const UVoxelTools&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelTools(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelTools(UVoxelTools&&); \
	NO_API UVoxelTools(const UVoxelTools&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelTools); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelTools)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_30_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h_33_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelTools_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
