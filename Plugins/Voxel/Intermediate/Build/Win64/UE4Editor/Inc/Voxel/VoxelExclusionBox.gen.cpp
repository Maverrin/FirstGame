// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelPlaceableItems/VoxelExclusionBox.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelExclusionBox() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_AVoxelExclusionBox_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelExclusionBox();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelPlaceableItemActor();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UFunction* Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FIntBox();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
	VOXEL_API UFunction* Z_Construct_UFunction_AVoxelExclusionBox_GetBox();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
// End Cross Module References
	void AVoxelExclusionBox::StaticRegisterNativesAVoxelExclusionBox()
	{
		UClass* Class = AVoxelExclusionBox::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddExclusionBoxToWorld", &AVoxelExclusionBox::execAddExclusionBoxToWorld },
			{ "GetBox", &AVoxelExclusionBox::execGetBox },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics
	{
		struct VoxelExclusionBox_eventAddExclusionBoxToWorld_Parms
		{
			AVoxelWorld* InWorld;
			FIntBox Bounds;
			bool bInExcludeTerrain;
			bool bInExcludeVoxelActors;
			bool bInExcludeVoxelGrass;
			bool bInDisableEdits;
		};
		static void NewProp_bInDisableEdits_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInDisableEdits;
		static void NewProp_bInExcludeVoxelGrass_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInExcludeVoxelGrass;
		static void NewProp_bInExcludeVoxelActors_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInExcludeVoxelActors;
		static void NewProp_bInExcludeTerrain_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInExcludeTerrain;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Bounds_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Bounds;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InWorld;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInDisableEdits_SetBit(void* Obj)
	{
		((VoxelExclusionBox_eventAddExclusionBoxToWorld_Parms*)Obj)->bInDisableEdits = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInDisableEdits = { UE4CodeGen_Private::EPropertyClass::Bool, "bInDisableEdits", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelExclusionBox_eventAddExclusionBoxToWorld_Parms), &Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInDisableEdits_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInExcludeVoxelGrass_SetBit(void* Obj)
	{
		((VoxelExclusionBox_eventAddExclusionBoxToWorld_Parms*)Obj)->bInExcludeVoxelGrass = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInExcludeVoxelGrass = { UE4CodeGen_Private::EPropertyClass::Bool, "bInExcludeVoxelGrass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelExclusionBox_eventAddExclusionBoxToWorld_Parms), &Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInExcludeVoxelGrass_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInExcludeVoxelActors_SetBit(void* Obj)
	{
		((VoxelExclusionBox_eventAddExclusionBoxToWorld_Parms*)Obj)->bInExcludeVoxelActors = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInExcludeVoxelActors = { UE4CodeGen_Private::EPropertyClass::Bool, "bInExcludeVoxelActors", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelExclusionBox_eventAddExclusionBoxToWorld_Parms), &Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInExcludeVoxelActors_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInExcludeTerrain_SetBit(void* Obj)
	{
		((VoxelExclusionBox_eventAddExclusionBoxToWorld_Parms*)Obj)->bInExcludeTerrain = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInExcludeTerrain = { UE4CodeGen_Private::EPropertyClass::Bool, "bInExcludeTerrain", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelExclusionBox_eventAddExclusionBoxToWorld_Parms), &Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInExcludeTerrain_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_Bounds_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_Bounds = { UE4CodeGen_Private::EPropertyClass::Struct, "Bounds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelExclusionBox_eventAddExclusionBoxToWorld_Parms, Bounds), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_Bounds_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_Bounds_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_InWorld = { UE4CodeGen_Private::EPropertyClass::Object, "InWorld", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelExclusionBox_eventAddExclusionBoxToWorld_Parms, InWorld), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInDisableEdits,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInExcludeVoxelGrass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInExcludeVoxelActors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_bInExcludeTerrain,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_Bounds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::NewProp_InWorld,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelExclusionBox.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelExclusionBox, "AddExclusionBoxToWorld", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(VoxelExclusionBox_eventAddExclusionBoxToWorld_Parms), Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelExclusionBox_GetBox_Statics
	{
		struct VoxelExclusionBox_eventGetBox_Parms
		{
			FIntBox ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelExclusionBox_GetBox_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelExclusionBox_eventGetBox_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelExclusionBox_GetBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelExclusionBox_GetBox_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelExclusionBox_GetBox_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelExclusionBox.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelExclusionBox_GetBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelExclusionBox, "GetBox", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(VoxelExclusionBox_eventGetBox_Parms), Z_Construct_UFunction_AVoxelExclusionBox_GetBox_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelExclusionBox_GetBox_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelExclusionBox_GetBox_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelExclusionBox_GetBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelExclusionBox_GetBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelExclusionBox_GetBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AVoxelExclusionBox_NoRegister()
	{
		return AVoxelExclusionBox::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelExclusionBox_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Box_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Box;
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDisableEdits_MetaData[];
#endif
		static void NewProp_bDisableEdits_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDisableEdits;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bExcludeVoxelGrass_MetaData[];
#endif
		static void NewProp_bExcludeVoxelGrass_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bExcludeVoxelGrass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bExcludeVoxelActors_MetaData[];
#endif
		static void NewProp_bExcludeVoxelActors_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bExcludeVoxelActors;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bExcludeTerrain_MetaData[];
#endif
		static void NewProp_bExcludeTerrain_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bExcludeTerrain;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelExclusionBox_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AVoxelPlaceableItemActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVoxelExclusionBox_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVoxelExclusionBox_AddExclusionBoxToWorld, "AddExclusionBoxToWorld" }, // 1142668036
		{ &Z_Construct_UFunction_AVoxelExclusionBox_GetBox, "GetBox" }, // 3180727390
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelExclusionBox_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Tick Replication Input Actor Rendering HOLD LOD Cooking" },
		{ "IncludePath", "VoxelPlaceableItems/VoxelExclusionBox.h" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelExclusionBox.h" },
	};
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_Box_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelExclusionBox.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_Box = { UE4CodeGen_Private::EPropertyClass::Object, "Box", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000800080008, 1, nullptr, STRUCT_OFFSET(AVoxelExclusionBox, Box), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_Box_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_Box_MetaData)) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bDisableEdits_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelExclusionBox.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bDisableEdits_SetBit(void* Obj)
	{
		((AVoxelExclusionBox*)Obj)->bDisableEdits = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bDisableEdits = { UE4CodeGen_Private::EPropertyClass::Bool, "bDisableEdits", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelExclusionBox), &Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bDisableEdits_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bDisableEdits_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bDisableEdits_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelGrass_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelExclusionBox.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelGrass_SetBit(void* Obj)
	{
		((AVoxelExclusionBox*)Obj)->bExcludeVoxelGrass = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelGrass = { UE4CodeGen_Private::EPropertyClass::Bool, "bExcludeVoxelGrass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelExclusionBox), &Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelGrass_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelGrass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelGrass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelActors_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelExclusionBox.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelActors_SetBit(void* Obj)
	{
		((AVoxelExclusionBox*)Obj)->bExcludeVoxelActors = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelActors = { UE4CodeGen_Private::EPropertyClass::Bool, "bExcludeVoxelActors", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelExclusionBox), &Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelActors_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelActors_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelActors_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeTerrain_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelExclusionBox.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeTerrain_SetBit(void* Obj)
	{
		((AVoxelExclusionBox*)Obj)->bExcludeTerrain = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeTerrain = { UE4CodeGen_Private::EPropertyClass::Bool, "bExcludeTerrain", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelExclusionBox), &Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeTerrain_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeTerrain_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeTerrain_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelExclusionBox_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_Box,
#endif // WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bDisableEdits,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelGrass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeVoxelActors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelExclusionBox_Statics::NewProp_bExcludeTerrain,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelExclusionBox_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelExclusionBox>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelExclusionBox_Statics::ClassParams = {
		&AVoxelExclusionBox::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AVoxelExclusionBox_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelExclusionBox_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelExclusionBox_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelExclusionBox_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelExclusionBox()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelExclusionBox_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelExclusionBox, 3391904099);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelExclusionBox(Z_Construct_UClass_AVoxelExclusionBox, &AVoxelExclusionBox::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelExclusionBox"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelExclusionBox);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
