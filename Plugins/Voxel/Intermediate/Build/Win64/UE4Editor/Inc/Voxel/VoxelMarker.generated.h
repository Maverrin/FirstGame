// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AVoxelWorld;
enum class EVoxelMode : uint8;
struct FVector;
struct FIntVector;
struct FIntBox;
#ifdef VOXEL_VoxelMarker_generated_h
#error "VoxelMarker.generated.h already included, missing '#pragma once' in VoxelMarker.h"
#endif
#define VOXEL_VoxelMarker_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_RPC_WRAPPERS
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_RPC_WRAPPERS_NO_PURE_DECLS
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVoxelMarker(); \
	friend struct Z_Construct_UClass_AVoxelMarker_Statics; \
public: \
	DECLARE_CLASS(AVoxelMarker, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelMarker)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_INCLASS \
private: \
	static void StaticRegisterNativesAVoxelMarker(); \
	friend struct Z_Construct_UClass_AVoxelMarker_Statics; \
public: \
	DECLARE_CLASS(AVoxelMarker, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelMarker)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelMarker(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelMarker) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelMarker); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelMarker); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelMarker(AVoxelMarker&&); \
	NO_API AVoxelMarker(const AVoxelMarker&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelMarker(AVoxelMarker&&); \
	NO_API AVoxelMarker(const AVoxelMarker&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelMarker); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelMarker); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVoxelMarker)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_31_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_34_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUpdateProjectionMarker) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_ENUM(EVoxelMode,Z_Param_Mode); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_HeightOffset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateProjectionMarker(Z_Param_World,EVoxelMode(Z_Param_Mode),Z_Param_Position,Z_Param_Normal,Z_Param_Radius,Z_Param_EditDistance,Z_Param_HeightOffset); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateProjectionMarker) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_ENUM(EVoxelMode,Z_Param_Mode); \
		P_GET_STRUCT(FVector,Z_Param_Position); \
		P_GET_STRUCT(FVector,Z_Param_Normal); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_EditDistance); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_HeightOffset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateProjectionMarker(Z_Param_World,EVoxelMode(Z_Param_Mode),Z_Param_Position,Z_Param_Normal,Z_Param_Radius,Z_Param_EditDistance,Z_Param_HeightOffset); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVoxelProjectionMarker(); \
	friend struct Z_Construct_UClass_AVoxelProjectionMarker_Statics; \
public: \
	DECLARE_CLASS(AVoxelProjectionMarker, AVoxelMarker, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelProjectionMarker)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_INCLASS \
private: \
	static void StaticRegisterNativesAVoxelProjectionMarker(); \
	friend struct Z_Construct_UClass_AVoxelProjectionMarker_Statics; \
public: \
	DECLARE_CLASS(AVoxelProjectionMarker, AVoxelMarker, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelProjectionMarker)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelProjectionMarker(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelProjectionMarker) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelProjectionMarker); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelProjectionMarker); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelProjectionMarker(AVoxelProjectionMarker&&); \
	NO_API AVoxelProjectionMarker(const AVoxelProjectionMarker&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelProjectionMarker(AVoxelProjectionMarker&&); \
	NO_API AVoxelProjectionMarker(const AVoxelProjectionMarker&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelProjectionMarker); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelProjectionMarker); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVoxelProjectionMarker)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_43_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_46_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUpdateSphereMarker) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_ENUM(EVoxelMode,Z_Param_Mode); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateSphereMarker(Z_Param_World,EVoxelMode(Z_Param_Mode),Z_Param_Position,Z_Param_Radius); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateSphereMarker) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_ENUM(EVoxelMode,Z_Param_Mode); \
		P_GET_STRUCT(FIntVector,Z_Param_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateSphereMarker(Z_Param_World,EVoxelMode(Z_Param_Mode),Z_Param_Position,Z_Param_Radius); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVoxelSphereMarker(); \
	friend struct Z_Construct_UClass_AVoxelSphereMarker_Statics; \
public: \
	DECLARE_CLASS(AVoxelSphereMarker, AVoxelMarker, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelSphereMarker)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_INCLASS \
private: \
	static void StaticRegisterNativesAVoxelSphereMarker(); \
	friend struct Z_Construct_UClass_AVoxelSphereMarker_Statics; \
public: \
	DECLARE_CLASS(AVoxelSphereMarker, AVoxelMarker, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelSphereMarker)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelSphereMarker(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelSphereMarker) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelSphereMarker); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelSphereMarker); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelSphereMarker(AVoxelSphereMarker&&); \
	NO_API AVoxelSphereMarker(const AVoxelSphereMarker&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelSphereMarker(AVoxelSphereMarker&&); \
	NO_API AVoxelSphereMarker(const AVoxelSphereMarker&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelSphereMarker); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelSphereMarker); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVoxelSphereMarker)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_60_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_63_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUpdateBoxMarker) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_ENUM(EVoxelMode,Z_Param_Mode); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateBoxMarker(Z_Param_World,EVoxelMode(Z_Param_Mode),Z_Param_Bounds); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateBoxMarker) \
	{ \
		P_GET_OBJECT(AVoxelWorld,Z_Param_World); \
		P_GET_ENUM(EVoxelMode,Z_Param_Mode); \
		P_GET_STRUCT(FIntBox,Z_Param_Bounds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateBoxMarker(Z_Param_World,EVoxelMode(Z_Param_Mode),Z_Param_Bounds); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVoxelBoxMarker(); \
	friend struct Z_Construct_UClass_AVoxelBoxMarker_Statics; \
public: \
	DECLARE_CLASS(AVoxelBoxMarker, AVoxelMarker, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelBoxMarker)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_INCLASS \
private: \
	static void StaticRegisterNativesAVoxelBoxMarker(); \
	friend struct Z_Construct_UClass_AVoxelBoxMarker_Statics; \
public: \
	DECLARE_CLASS(AVoxelBoxMarker, AVoxelMarker, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelBoxMarker)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelBoxMarker(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelBoxMarker) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelBoxMarker); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelBoxMarker); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelBoxMarker(AVoxelBoxMarker&&); \
	NO_API AVoxelBoxMarker(const AVoxelBoxMarker&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelBoxMarker(AVoxelBoxMarker&&); \
	NO_API AVoxelBoxMarker(const AVoxelBoxMarker&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelBoxMarker); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelBoxMarker); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVoxelBoxMarker)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_81_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h_84_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelTools_VoxelMarker_h


#define FOREACH_ENUM_EVOXELTOOL(op) \
	op(EVoxelTool::Projection) \
	op(EVoxelTool::Sphere) \
	op(EVoxelTool::Box) 
#define FOREACH_ENUM_EVOXELMODE(op) \
	op(EVoxelMode::Add) \
	op(EVoxelMode::Remove) \
	op(EVoxelMode::Flatten) \
	op(EVoxelMode::Paint) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
