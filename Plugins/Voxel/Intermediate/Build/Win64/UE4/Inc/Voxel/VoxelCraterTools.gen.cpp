// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelTools/VoxelCraterTools.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelCraterTools() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelCraterTools_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelCraterTools();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelCraterTools_AddCrater();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FLatentActionInfo();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	void UVoxelCraterTools::StaticRegisterNativesUVoxelCraterTools()
	{
		UClass* Class = UVoxelCraterTools::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddCrater", &UVoxelCraterTools::execAddCrater },
			{ "AddCraterAsync", &UVoxelCraterTools::execAddCraterAsync },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics
	{
		struct VoxelCraterTools_eventAddCrater_Parms
		{
			AVoxelWorld* World;
			FIntVector Position;
			float Radius;
			float PositionsSampleRate;
			TArray<FIntVector> Positions;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Positions;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Positions_Inner;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PositionsSampleRate;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::NewProp_Positions = { UE4CodeGen_Private::EPropertyClass::Array, "Positions", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelCraterTools_eventAddCrater_Parms, Positions), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::NewProp_Positions_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Positions", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::NewProp_PositionsSampleRate = { UE4CodeGen_Private::EPropertyClass::Float, "PositionsSampleRate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelCraterTools_eventAddCrater_Parms, PositionsSampleRate), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelCraterTools_eventAddCrater_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelCraterTools_eventAddCrater_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelCraterTools_eventAddCrater_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::NewProp_Positions,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::NewProp_Positions_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::NewProp_PositionsSampleRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelCraterTools.h" },
		{ "ToolTip", "Add a crater\n@param       World                           Voxel World\n@param       Position                        Center of the crater\n@param       Radius                          Radius of the crater in voxels" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelCraterTools, "AddCrater", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C22401, sizeof(VoxelCraterTools_eventAddCrater_Parms), Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelCraterTools_AddCrater()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelCraterTools_AddCrater_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics
	{
		struct VoxelCraterTools_eventAddCraterAsync_Parms
		{
			UObject* WorldContextObject;
			AVoxelWorld* World;
			FIntVector Position;
			float Radius;
			float PositionsSampleRate;
			TArray<FIntVector> Positions;
			FLatentActionInfo LatentInfo;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Positions;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Positions_Inner;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PositionsSampleRate;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_LatentInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "LatentInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelCraterTools_eventAddCraterAsync_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_Positions = { UE4CodeGen_Private::EPropertyClass::Array, "Positions", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelCraterTools_eventAddCraterAsync_Parms, Positions), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_Positions_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Positions", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_PositionsSampleRate = { UE4CodeGen_Private::EPropertyClass::Float, "PositionsSampleRate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelCraterTools_eventAddCraterAsync_Parms, PositionsSampleRate), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelCraterTools_eventAddCraterAsync_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelCraterTools_eventAddCraterAsync_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelCraterTools_eventAddCraterAsync_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelCraterTools_eventAddCraterAsync_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_LatentInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_Positions,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_Positions_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_PositionsSampleRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_World,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelCraterTools.h" },
		{ "ToolTip", "Add a crater in an async thread\n@param       World                           Voxel World\n@param       Position                        Center of the crater\n@param       Radius                          Radius of the crater in voxels" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelCraterTools, "AddCraterAsync", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C22401, sizeof(VoxelCraterTools_eventAddCraterAsync_Parms), Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelCraterTools_NoRegister()
	{
		return UVoxelCraterTools::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelCraterTools_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelCraterTools_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelCraterTools_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelCraterTools_AddCrater, "AddCrater" }, // 1208976230
		{ &Z_Construct_UFunction_UVoxelCraterTools_AddCraterAsync, "AddCraterAsync" }, // 4293468060
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelCraterTools_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelTools/VoxelCraterTools.h" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelCraterTools.h" },
		{ "ToolTip", "Crater blueprint tools for voxels" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelCraterTools_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelCraterTools>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelCraterTools_Statics::ClassParams = {
		&UVoxelCraterTools::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelCraterTools_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelCraterTools_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelCraterTools()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelCraterTools_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelCraterTools, 3003146540);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelCraterTools(Z_Construct_UClass_UVoxelCraterTools, &UVoxelCraterTools::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelCraterTools"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelCraterTools);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
