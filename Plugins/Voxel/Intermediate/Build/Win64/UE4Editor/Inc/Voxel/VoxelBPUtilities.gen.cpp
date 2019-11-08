// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelTools/VoxelBPUtilities.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelBPUtilities() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelBPUtilities_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelBPUtilities();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterial();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelPaintMaterial();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetBlend();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetColor();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetIndex();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FIntBox();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetBlend();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetColor();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetIndex();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox();
// End Cross Module References
	void UVoxelBPUtilities::StaticRegisterNativesUVoxelBPUtilities()
	{
		UClass* Class = UVoxelBPUtilities::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Add_IntVectorIntVector", &UVoxelBPUtilities::execAdd_IntVectorIntVector },
			{ "ApplyPaintMaterial", &UVoxelBPUtilities::execApplyPaintMaterial },
			{ "CreateActorPaintMaterial", &UVoxelBPUtilities::execCreateActorPaintMaterial },
			{ "CreateGrassPaintMaterial", &UVoxelBPUtilities::execCreateGrassPaintMaterial },
			{ "CreateIndexPaintMaterial", &UVoxelBPUtilities::execCreateIndexPaintMaterial },
			{ "CreateMaterialFromColor", &UVoxelBPUtilities::execCreateMaterialFromColor },
			{ "CreateMaterialFromDoubleIndex", &UVoxelBPUtilities::execCreateMaterialFromDoubleIndex },
			{ "CreateMaterialFromIndex", &UVoxelBPUtilities::execCreateMaterialFromIndex },
			{ "CreateRGBPaintMaterial", &UVoxelBPUtilities::execCreateRGBPaintMaterial },
			{ "Divide_IntVectorInt", &UVoxelBPUtilities::execDivide_IntVectorInt },
			{ "GetBlend", &UVoxelBPUtilities::execGetBlend },
			{ "GetColor", &UVoxelBPUtilities::execGetColor },
			{ "GetIndex", &UVoxelBPUtilities::execGetIndex },
			{ "GetIndexA", &UVoxelBPUtilities::execGetIndexA },
			{ "GetIndexB", &UVoxelBPUtilities::execGetIndexB },
			{ "GetVoxelActorId", &UVoxelBPUtilities::execGetVoxelActorId },
			{ "GetVoxelGrassId", &UVoxelBPUtilities::execGetVoxelGrassId },
			{ "MakeBoxFromGlobalPositionAndRadius", &UVoxelBPUtilities::execMakeBoxFromGlobalPositionAndRadius },
			{ "MakeBoxFromLocalPositionAndRadius", &UVoxelBPUtilities::execMakeBoxFromLocalPositionAndRadius },
			{ "Multiply_IntIntVector", &UVoxelBPUtilities::execMultiply_IntIntVector },
			{ "Multiply_IntVectorInt", &UVoxelBPUtilities::execMultiply_IntVectorInt },
			{ "Multiply_IntVectorIntVector", &UVoxelBPUtilities::execMultiply_IntVectorIntVector },
			{ "SetBlend", &UVoxelBPUtilities::execSetBlend },
			{ "SetColor", &UVoxelBPUtilities::execSetColor },
			{ "SetIndex", &UVoxelBPUtilities::execSetIndex },
			{ "SetIndexA", &UVoxelBPUtilities::execSetIndexA },
			{ "SetIndexB", &UVoxelBPUtilities::execSetIndexB },
			{ "SetVoxelActorId", &UVoxelBPUtilities::execSetVoxelActorId },
			{ "SetVoxelGrassId", &UVoxelBPUtilities::execSetVoxelGrassId },
			{ "Substract_IntVectorIntVector", &UVoxelBPUtilities::execSubstract_IntVectorIntVector },
			{ "TranslateBox", &UVoxelBPUtilities::execTranslateBox },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics
	{
		struct VoxelBPUtilities_eventAdd_IntVectorIntVector_Parms
		{
			FIntVector Left;
			FIntVector Right;
			FIntVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Right;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Left;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventAdd_IntVectorIntVector_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::NewProp_Right = { UE4CodeGen_Private::EPropertyClass::Struct, "Right", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventAdd_IntVectorIntVector_Parms, Right), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::NewProp_Left = { UE4CodeGen_Private::EPropertyClass::Struct, "Left", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventAdd_IntVectorIntVector_Parms, Left), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::NewProp_Right,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::NewProp_Left,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::Function_MetaDataParams[] = {
		{ "Category", "Math|IntVector" },
		{ "CompactNodeTitle", "+" },
		{ "DisplayName", "IntVector + IntVector" },
		{ "Keywords", "+ add plus" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
		{ "ToolTip", "FIntVector helpers" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "Add_IntVectorIntVector", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14822401, sizeof(VoxelBPUtilities_eventAdd_IntVectorIntVector_Parms), Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics
	{
		struct VoxelBPUtilities_eventApplyPaintMaterial_Parms
		{
			FVoxelMaterial Material;
			FVoxelPaintMaterial PaintMaterial;
			FVoxelMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PaintMaterial;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventApplyPaintMaterial_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::NewProp_PaintMaterial = { UE4CodeGen_Private::EPropertyClass::Struct, "PaintMaterial", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventApplyPaintMaterial_Parms, PaintMaterial), Z_Construct_UScriptStruct_FVoxelPaintMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventApplyPaintMaterial_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::NewProp_PaintMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
		{ "ToolTip", "Apply a Paint Material to a Voxel Material" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "ApplyPaintMaterial", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventApplyPaintMaterial_Parms), Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial_Statics
	{
		struct VoxelBPUtilities_eventCreateActorPaintMaterial_Parms
		{
			uint8 ActorId;
			FVoxelPaintMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ActorId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateActorPaintMaterial_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelPaintMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial_Statics::NewProp_ActorId = { UE4CodeGen_Private::EPropertyClass::Byte, "ActorId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateActorPaintMaterial_Parms, ActorId), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial_Statics::NewProp_ActorId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
		{ "ToolTip", "Create from actor id" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "CreateActorPaintMaterial", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventCreateActorPaintMaterial_Parms), Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial_Statics
	{
		struct VoxelBPUtilities_eventCreateGrassPaintMaterial_Parms
		{
			uint8 GrassId;
			FVoxelPaintMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_GrassId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateGrassPaintMaterial_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelPaintMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial_Statics::NewProp_GrassId = { UE4CodeGen_Private::EPropertyClass::Byte, "GrassId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateGrassPaintMaterial_Parms, GrassId), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial_Statics::NewProp_GrassId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
		{ "ToolTip", "Create from grass id" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "CreateGrassPaintMaterial", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventCreateGrassPaintMaterial_Parms), Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial_Statics
	{
		struct VoxelBPUtilities_eventCreateIndexPaintMaterial_Parms
		{
			uint8 Index;
			FVoxelPaintMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateIndexPaintMaterial_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelPaintMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Byte, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateIndexPaintMaterial_Parms, Index), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
		{ "ToolTip", "Create from index" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "CreateIndexPaintMaterial", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventCreateIndexPaintMaterial_Parms), Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor_Statics
	{
		struct VoxelBPUtilities_eventCreateMaterialFromColor_Parms
		{
			FLinearColor Color;
			FVoxelMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateMaterialFromColor_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor_Statics::NewProp_Color = { UE4CodeGen_Private::EPropertyClass::Struct, "Color", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateMaterialFromColor_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor_Statics::NewProp_Color,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "CreateMaterialFromColor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14822401, sizeof(VoxelBPUtilities_eventCreateMaterialFromColor_Parms), Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics
	{
		struct VoxelBPUtilities_eventCreateMaterialFromDoubleIndex_Parms
		{
			uint8 IndexA;
			uint8 IndexB;
			float Blend;
			FVoxelMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Blend;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_IndexB;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_IndexA;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateMaterialFromDoubleIndex_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::NewProp_Blend = { UE4CodeGen_Private::EPropertyClass::Float, "Blend", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateMaterialFromDoubleIndex_Parms, Blend), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::NewProp_IndexB = { UE4CodeGen_Private::EPropertyClass::Byte, "IndexB", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateMaterialFromDoubleIndex_Parms, IndexB), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::NewProp_IndexA = { UE4CodeGen_Private::EPropertyClass::Byte, "IndexA", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateMaterialFromDoubleIndex_Parms, IndexA), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::NewProp_Blend,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::NewProp_IndexB,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::NewProp_IndexA,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "CreateMaterialFromDoubleIndex", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventCreateMaterialFromDoubleIndex_Parms), Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex_Statics
	{
		struct VoxelBPUtilities_eventCreateMaterialFromIndex_Parms
		{
			uint8 Index;
			FVoxelMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateMaterialFromIndex_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Byte, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateMaterialFromIndex_Parms, Index), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "CreateMaterialFromIndex", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventCreateMaterialFromIndex_Parms), Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics
	{
		struct VoxelBPUtilities_eventCreateRGBPaintMaterial_Parms
		{
			FLinearColor Color;
			float Amount;
			FVoxelPaintMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Amount;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateRGBPaintMaterial_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelPaintMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::NewProp_Amount = { UE4CodeGen_Private::EPropertyClass::Float, "Amount", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateRGBPaintMaterial_Parms, Amount), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::NewProp_Color = { UE4CodeGen_Private::EPropertyClass::Struct, "Color", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventCreateRGBPaintMaterial_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::NewProp_Amount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::NewProp_Color,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "DisplayName", "Create RGB Paint Material" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
		{ "ToolTip", "FVoxelPaintMaterial helpers\n        // Create from color" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "CreateRGBPaintMaterial", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14822401, sizeof(VoxelBPUtilities_eventCreateRGBPaintMaterial_Parms), Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics
	{
		struct VoxelBPUtilities_eventDivide_IntVectorInt_Parms
		{
			FIntVector Left;
			int32 Right;
			FIntVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Right;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Left_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Left;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventDivide_IntVectorInt_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::NewProp_Right = { UE4CodeGen_Private::EPropertyClass::Int, "Right", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventDivide_IntVectorInt_Parms, Right), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::NewProp_Left_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::NewProp_Left = { UE4CodeGen_Private::EPropertyClass::Struct, "Left", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventDivide_IntVectorInt_Parms, Left), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::NewProp_Left_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::NewProp_Left_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::NewProp_Right,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::NewProp_Left,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::Function_MetaDataParams[] = {
		{ "Category", "Math|IntVector" },
		{ "CompactNodeTitle", "/" },
		{ "DisplayName", "IntVector / int" },
		{ "Keywords", "/ divide" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "Divide_IntVectorInt", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14C22401, sizeof(VoxelBPUtilities_eventDivide_IntVectorInt_Parms), Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_GetBlend_Statics
	{
		struct VoxelBPUtilities_eventGetBlend_Parms
		{
			FVoxelMaterial Material;
			uint8 ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetBlend_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Byte, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetBlend_Parms, ReturnValue), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetBlend_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetBlend_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_GetBlend_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetBlend_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetBlend_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_GetBlend_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_GetBlend_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "GetBlend", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventGetBlend_Parms), Z_Construct_UFunction_UVoxelBPUtilities_GetBlend_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetBlend_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_GetBlend_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetBlend_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetBlend()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_GetBlend_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_GetColor_Statics
	{
		struct VoxelBPUtilities_eventGetColor_Parms
		{
			FVoxelMaterial Material;
			FLinearColor ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetColor_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetColor_Parms, ReturnValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetColor_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetColor_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_GetColor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetColor_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetColor_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_GetColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_GetColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "GetColor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14822401, sizeof(VoxelBPUtilities_eventGetColor_Parms), Z_Construct_UFunction_UVoxelBPUtilities_GetColor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetColor_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_GetColor_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetColor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_GetColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_GetIndex_Statics
	{
		struct VoxelBPUtilities_eventGetIndex_Parms
		{
			FVoxelMaterial Material;
			uint8 ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetIndex_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Byte, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetIndex_Parms, ReturnValue), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetIndex_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetIndex_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_GetIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetIndex_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetIndex_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_GetIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_GetIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "GetIndex", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventGetIndex_Parms), Z_Construct_UFunction_UVoxelBPUtilities_GetIndex_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetIndex_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_GetIndex_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_GetIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA_Statics
	{
		struct VoxelBPUtilities_eventGetIndexA_Parms
		{
			FVoxelMaterial Material;
			uint8 ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Byte, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetIndexA_Parms, ReturnValue), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetIndexA_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "GetIndexA", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventGetIndexA_Parms), Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB_Statics
	{
		struct VoxelBPUtilities_eventGetIndexB_Parms
		{
			FVoxelMaterial Material;
			uint8 ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Byte, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetIndexB_Parms, ReturnValue), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetIndexB_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "GetIndexB", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventGetIndexB_Parms), Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId_Statics
	{
		struct VoxelBPUtilities_eventGetVoxelActorId_Parms
		{
			FVoxelMaterial Material;
			uint8 ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Byte, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetVoxelActorId_Parms, ReturnValue), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetVoxelActorId_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "GetVoxelActorId", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventGetVoxelActorId_Parms), Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId_Statics
	{
		struct VoxelBPUtilities_eventGetVoxelGrassId_Parms
		{
			FVoxelMaterial Material;
			uint8 ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Byte, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetVoxelGrassId_Parms, ReturnValue), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventGetVoxelGrassId_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "GetVoxelGrassId", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventGetVoxelGrassId_Parms), Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics
	{
		struct VoxelBPUtilities_eventMakeBoxFromGlobalPositionAndRadius_Parms
		{
			AVoxelWorld* World;
			FVector GlobalPosition;
			float RadiusInVoxels;
			FIntBox ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RadiusInVoxels;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GlobalPosition_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GlobalPosition;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMakeBoxFromGlobalPositionAndRadius_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::NewProp_RadiusInVoxels = { UE4CodeGen_Private::EPropertyClass::Float, "RadiusInVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMakeBoxFromGlobalPositionAndRadius_Parms, RadiusInVoxels), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::NewProp_GlobalPosition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::NewProp_GlobalPosition = { UE4CodeGen_Private::EPropertyClass::Struct, "GlobalPosition", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMakeBoxFromGlobalPositionAndRadius_Parms, GlobalPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::NewProp_GlobalPosition_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::NewProp_GlobalPosition_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMakeBoxFromGlobalPositionAndRadius_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::NewProp_RadiusInVoxels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::NewProp_GlobalPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
		{ "ToolTip", "From Floor(-Radius) (included) to Ceil(Radius) (excluded)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "MakeBoxFromGlobalPositionAndRadius", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14C22401, sizeof(VoxelBPUtilities_eventMakeBoxFromGlobalPositionAndRadius_Parms), Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics
	{
		struct VoxelBPUtilities_eventMakeBoxFromLocalPositionAndRadius_Parms
		{
			FIntVector Position;
			int32 Radius;
			FIntBox ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Radius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMakeBoxFromLocalPositionAndRadius_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Int, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMakeBoxFromLocalPositionAndRadius_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::NewProp_Position_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMakeBoxFromLocalPositionAndRadius_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::NewProp_Position_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::NewProp_Position_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::NewProp_Position,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::Function_MetaDataParams[] = {
		{ "Category", "Math|IntBox" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
		{ "ToolTip", "From -Radius(included) to Radius(excluded)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "MakeBoxFromLocalPositionAndRadius", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14C22401, sizeof(VoxelBPUtilities_eventMakeBoxFromLocalPositionAndRadius_Parms), Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics
	{
		struct VoxelBPUtilities_eventMultiply_IntIntVector_Parms
		{
			int32 Left;
			FIntVector Right;
			FIntVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Right_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Right;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Left;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMultiply_IntIntVector_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::NewProp_Right_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::NewProp_Right = { UE4CodeGen_Private::EPropertyClass::Struct, "Right", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMultiply_IntIntVector_Parms, Right), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::NewProp_Right_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::NewProp_Right_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::NewProp_Left = { UE4CodeGen_Private::EPropertyClass::Int, "Left", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMultiply_IntIntVector_Parms, Left), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::NewProp_Right,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::NewProp_Left,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::Function_MetaDataParams[] = {
		{ "Category", "Math|IntVector" },
		{ "CompactNodeTitle", "*" },
		{ "DisplayName", "int * IntVector" },
		{ "Keywords", "* multiply" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "Multiply_IntIntVector", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14C22401, sizeof(VoxelBPUtilities_eventMultiply_IntIntVector_Parms), Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics
	{
		struct VoxelBPUtilities_eventMultiply_IntVectorInt_Parms
		{
			FIntVector Left;
			int32 Right;
			FIntVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Right;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Left_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Left;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMultiply_IntVectorInt_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::NewProp_Right = { UE4CodeGen_Private::EPropertyClass::Int, "Right", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMultiply_IntVectorInt_Parms, Right), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::NewProp_Left_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::NewProp_Left = { UE4CodeGen_Private::EPropertyClass::Struct, "Left", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMultiply_IntVectorInt_Parms, Left), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::NewProp_Left_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::NewProp_Left_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::NewProp_Right,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::NewProp_Left,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::Function_MetaDataParams[] = {
		{ "Category", "Math|IntVector" },
		{ "CompactNodeTitle", "*" },
		{ "DisplayName", "IntVector * int" },
		{ "Keywords", "* multiply" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "Multiply_IntVectorInt", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14C22401, sizeof(VoxelBPUtilities_eventMultiply_IntVectorInt_Parms), Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics
	{
		struct VoxelBPUtilities_eventMultiply_IntVectorIntVector_Parms
		{
			FIntVector Left;
			FIntVector Right;
			FIntVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Right_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Right;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Left_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Left;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMultiply_IntVectorIntVector_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::NewProp_Right_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::NewProp_Right = { UE4CodeGen_Private::EPropertyClass::Struct, "Right", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMultiply_IntVectorIntVector_Parms, Right), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::NewProp_Right_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::NewProp_Right_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::NewProp_Left_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::NewProp_Left = { UE4CodeGen_Private::EPropertyClass::Struct, "Left", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventMultiply_IntVectorIntVector_Parms, Left), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::NewProp_Left_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::NewProp_Left_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::NewProp_Right,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::NewProp_Left,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::Function_MetaDataParams[] = {
		{ "Category", "Math|IntVector" },
		{ "CompactNodeTitle", "*" },
		{ "DisplayName", "IntVector * IntVector" },
		{ "Keywords", "* multiply" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "Multiply_IntVectorIntVector", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14C22401, sizeof(VoxelBPUtilities_eventMultiply_IntVectorIntVector_Parms), Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics
	{
		struct VoxelBPUtilities_eventSetBlend_Parms
		{
			FVoxelMaterial Material;
			float Blend;
			FVoxelMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Blend;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetBlend_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::NewProp_Blend = { UE4CodeGen_Private::EPropertyClass::Float, "Blend", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetBlend_Parms, Blend), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetBlend_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::NewProp_Blend,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "SetBlend", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventSetBlend_Parms), Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetBlend()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_SetBlend_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics
	{
		struct VoxelBPUtilities_eventSetColor_Parms
		{
			FVoxelMaterial Material;
			FLinearColor Color;
			FVoxelMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetColor_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::NewProp_Color = { UE4CodeGen_Private::EPropertyClass::Struct, "Color", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetColor_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetColor_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::NewProp_Color,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "SetColor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14822401, sizeof(VoxelBPUtilities_eventSetColor_Parms), Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_SetColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics
	{
		struct VoxelBPUtilities_eventSetIndex_Parms
		{
			FVoxelMaterial Material;
			uint8 Index;
			FVoxelMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetIndex_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Byte, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetIndex_Parms, Index), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetIndex_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "SetIndex", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventSetIndex_Parms), Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_SetIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics
	{
		struct VoxelBPUtilities_eventSetIndexA_Parms
		{
			FVoxelMaterial Material;
			uint8 Index;
			FVoxelMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetIndexA_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Byte, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetIndexA_Parms, Index), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetIndexA_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "SetIndexA", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventSetIndexA_Parms), Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics
	{
		struct VoxelBPUtilities_eventSetIndexB_Parms
		{
			FVoxelMaterial Material;
			uint8 Index;
			FVoxelMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetIndexB_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Byte, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetIndexB_Parms, Index), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetIndexB_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "SetIndexB", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventSetIndexB_Parms), Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics
	{
		struct VoxelBPUtilities_eventSetVoxelActorId_Parms
		{
			FVoxelMaterial Material;
			uint8 VoxelSpawnedActorId;
			FVoxelMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_VoxelSpawnedActorId;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetVoxelActorId_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::NewProp_VoxelSpawnedActorId = { UE4CodeGen_Private::EPropertyClass::Byte, "VoxelSpawnedActorId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetVoxelActorId_Parms, VoxelSpawnedActorId), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetVoxelActorId_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::NewProp_VoxelSpawnedActorId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "SetVoxelActorId", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventSetVoxelActorId_Parms), Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics
	{
		struct VoxelBPUtilities_eventSetVoxelGrassId_Parms
		{
			FVoxelMaterial Material;
			uint8 VoxelGrassId;
			FVoxelMaterial ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_VoxelGrassId;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetVoxelGrassId_Parms, ReturnValue), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::NewProp_VoxelGrassId = { UE4CodeGen_Private::EPropertyClass::Byte, "VoxelGrassId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetVoxelGrassId_Parms, VoxelGrassId), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSetVoxelGrassId_Parms, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::NewProp_VoxelGrassId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::NewProp_Material,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "SetVoxelGrassId", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VoxelBPUtilities_eventSetVoxelGrassId_Parms), Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics
	{
		struct VoxelBPUtilities_eventSubstract_IntVectorIntVector_Parms
		{
			FIntVector Left;
			FIntVector Right;
			FIntVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Right_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Right;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Left_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Left;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSubstract_IntVectorIntVector_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::NewProp_Right_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::NewProp_Right = { UE4CodeGen_Private::EPropertyClass::Struct, "Right", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSubstract_IntVectorIntVector_Parms, Right), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::NewProp_Right_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::NewProp_Right_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::NewProp_Left_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::NewProp_Left = { UE4CodeGen_Private::EPropertyClass::Struct, "Left", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventSubstract_IntVectorIntVector_Parms, Left), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::NewProp_Left_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::NewProp_Left_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::NewProp_Right,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::NewProp_Left,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::Function_MetaDataParams[] = {
		{ "Category", "Math|IntVector" },
		{ "CompactNodeTitle", "-" },
		{ "DisplayName", "IntVector - IntVector" },
		{ "Keywords", "- subtract minus" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "Substract_IntVectorIntVector", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14C22401, sizeof(VoxelBPUtilities_eventSubstract_IntVectorIntVector_Parms), Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics
	{
		struct VoxelBPUtilities_eventTranslateBox_Parms
		{
			FIntBox Box;
			FIntVector Position;
			FIntBox ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Box_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Box;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventTranslateBox_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::NewProp_Position_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventTranslateBox_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::NewProp_Position_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::NewProp_Position_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::NewProp_Box_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::NewProp_Box = { UE4CodeGen_Private::EPropertyClass::Struct, "Box", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelBPUtilities_eventTranslateBox_Parms, Box), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::NewProp_Box_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::NewProp_Box_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::NewProp_Box,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::Function_MetaDataParams[] = {
		{ "Category", "Math|IntBox" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
		{ "ToolTip", "FIntBox helpers" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelBPUtilities, "TranslateBox", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14C22401, sizeof(VoxelBPUtilities_eventTranslateBox_Parms), Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelBPUtilities_NoRegister()
	{
		return UVoxelBPUtilities::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelBPUtilities_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelBPUtilities_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelBPUtilities_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelBPUtilities_Add_IntVectorIntVector, "Add_IntVectorIntVector" }, // 2979531563
		{ &Z_Construct_UFunction_UVoxelBPUtilities_ApplyPaintMaterial, "ApplyPaintMaterial" }, // 2405959132
		{ &Z_Construct_UFunction_UVoxelBPUtilities_CreateActorPaintMaterial, "CreateActorPaintMaterial" }, // 3095657723
		{ &Z_Construct_UFunction_UVoxelBPUtilities_CreateGrassPaintMaterial, "CreateGrassPaintMaterial" }, // 2220100007
		{ &Z_Construct_UFunction_UVoxelBPUtilities_CreateIndexPaintMaterial, "CreateIndexPaintMaterial" }, // 4262637049
		{ &Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromColor, "CreateMaterialFromColor" }, // 2343057830
		{ &Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromDoubleIndex, "CreateMaterialFromDoubleIndex" }, // 3977938951
		{ &Z_Construct_UFunction_UVoxelBPUtilities_CreateMaterialFromIndex, "CreateMaterialFromIndex" }, // 3830633985
		{ &Z_Construct_UFunction_UVoxelBPUtilities_CreateRGBPaintMaterial, "CreateRGBPaintMaterial" }, // 1727911646
		{ &Z_Construct_UFunction_UVoxelBPUtilities_Divide_IntVectorInt, "Divide_IntVectorInt" }, // 1565105509
		{ &Z_Construct_UFunction_UVoxelBPUtilities_GetBlend, "GetBlend" }, // 174103555
		{ &Z_Construct_UFunction_UVoxelBPUtilities_GetColor, "GetColor" }, // 3840693756
		{ &Z_Construct_UFunction_UVoxelBPUtilities_GetIndex, "GetIndex" }, // 909740427
		{ &Z_Construct_UFunction_UVoxelBPUtilities_GetIndexA, "GetIndexA" }, // 1826565903
		{ &Z_Construct_UFunction_UVoxelBPUtilities_GetIndexB, "GetIndexB" }, // 3235997092
		{ &Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelActorId, "GetVoxelActorId" }, // 4140184371
		{ &Z_Construct_UFunction_UVoxelBPUtilities_GetVoxelGrassId, "GetVoxelGrassId" }, // 4021316865
		{ &Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromGlobalPositionAndRadius, "MakeBoxFromGlobalPositionAndRadius" }, // 381915510
		{ &Z_Construct_UFunction_UVoxelBPUtilities_MakeBoxFromLocalPositionAndRadius, "MakeBoxFromLocalPositionAndRadius" }, // 981878351
		{ &Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntIntVector, "Multiply_IntIntVector" }, // 129124087
		{ &Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorInt, "Multiply_IntVectorInt" }, // 3844749184
		{ &Z_Construct_UFunction_UVoxelBPUtilities_Multiply_IntVectorIntVector, "Multiply_IntVectorIntVector" }, // 2680949425
		{ &Z_Construct_UFunction_UVoxelBPUtilities_SetBlend, "SetBlend" }, // 2286938313
		{ &Z_Construct_UFunction_UVoxelBPUtilities_SetColor, "SetColor" }, // 556027256
		{ &Z_Construct_UFunction_UVoxelBPUtilities_SetIndex, "SetIndex" }, // 1853772355
		{ &Z_Construct_UFunction_UVoxelBPUtilities_SetIndexA, "SetIndexA" }, // 4209757193
		{ &Z_Construct_UFunction_UVoxelBPUtilities_SetIndexB, "SetIndexB" }, // 1578900778
		{ &Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelActorId, "SetVoxelActorId" }, // 2202105901
		{ &Z_Construct_UFunction_UVoxelBPUtilities_SetVoxelGrassId, "SetVoxelGrassId" }, // 3453618545
		{ &Z_Construct_UFunction_UVoxelBPUtilities_Substract_IntVectorIntVector, "Substract_IntVectorIntVector" }, // 4197075010
		{ &Z_Construct_UFunction_UVoxelBPUtilities_TranslateBox, "TranslateBox" }, // 3560801457
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelBPUtilities_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelTools/VoxelBPUtilities.h" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelBPUtilities.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelBPUtilities_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelBPUtilities>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelBPUtilities_Statics::ClassParams = {
		&UVoxelBPUtilities::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelBPUtilities_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelBPUtilities_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelBPUtilities()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelBPUtilities_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelBPUtilities, 557748245);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelBPUtilities(Z_Construct_UClass_UVoxelBPUtilities, &UVoxelBPUtilities::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelBPUtilities"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelBPUtilities);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
