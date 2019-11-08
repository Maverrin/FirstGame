// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelAssets/VoxelDataAsset.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelDataAsset() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelDataAsset_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelDataAsset();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelWorldGenerator();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelDataAsset_GetSize();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
// End Cross Module References
	void UVoxelDataAsset::StaticRegisterNativesUVoxelDataAsset()
	{
		UClass* Class = UVoxelDataAsset::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetSize", &UVoxelDataAsset::execGetSize },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelDataAsset_GetSize_Statics
	{
		struct VoxelDataAsset_eventGetSize_Parms
		{
			FIntVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelDataAsset_GetSize_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelDataAsset_eventGetSize_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelDataAsset_GetSize_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelDataAsset_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelDataAsset_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelDataAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelDataAsset_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelDataAsset, "GetSize", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54820401, sizeof(VoxelDataAsset_eventGetSize_Parms), Z_Construct_UFunction_UVoxelDataAsset_GetSize_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelDataAsset_GetSize_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelDataAsset_GetSize_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelDataAsset_GetSize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelDataAsset_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelDataAsset_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelDataAsset_NoRegister()
	{
		return UVoxelDataAsset::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelDataAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Size;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CompressedData_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_CompressedData;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CompressedData_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Version_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Version;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Offset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelDataAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelWorldGenerator,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelDataAsset_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelDataAsset_GetSize, "GetSize" }, // 3859425079
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDataAsset_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "VoxelAssets/VoxelDataAsset.h" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelDataAsset.h" },
		{ "SerializeToFArchive", "" },
		{ "ToolTip", "A Data Asset stores the values of every voxel inside it" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Size_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelDataAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Size = { UE4CodeGen_Private::EPropertyClass::Struct, "Size", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelDataAsset, Size), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Size_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Size_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_CompressedData_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelDataAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_CompressedData = { UE4CodeGen_Private::EPropertyClass::Array, "CompressedData", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000020000000, 1, nullptr, STRUCT_OFFSET(UVoxelDataAsset, CompressedData_DEPRECATED), METADATA_PARAMS(Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_CompressedData_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_CompressedData_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_CompressedData_Inner = { UE4CodeGen_Private::EPropertyClass::Byte, "CompressedData", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000020000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Version_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelDataAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Version = { UE4CodeGen_Private::EPropertyClass::Int, "Version", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelDataAsset, Version), METADATA_PARAMS(Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Version_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Version_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Offset_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelDataAsset.h" },
		{ "ToolTip", "Final position = Position + Offset" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Offset = { UE4CodeGen_Private::EPropertyClass::Struct, "Offset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UVoxelDataAsset, Offset), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Offset_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Offset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Position_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelDataAsset.h" },
		{ "ToolTip", "Final position = Position + Offset" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UVoxelDataAsset, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Position_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Position_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelDataAsset_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Size,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_CompressedData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_CompressedData_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Version,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Offset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAsset_Statics::NewProp_Position,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelDataAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelDataAsset>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelDataAsset_Statics::ClassParams = {
		&UVoxelDataAsset::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x041000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UVoxelDataAsset_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAsset_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelDataAsset_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAsset_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelDataAsset()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelDataAsset_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelDataAsset, 4119129130);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelDataAsset(Z_Construct_UClass_UVoxelDataAsset, &UVoxelDataAsset::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelDataAsset"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelDataAsset);
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(UVoxelDataAsset)
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
