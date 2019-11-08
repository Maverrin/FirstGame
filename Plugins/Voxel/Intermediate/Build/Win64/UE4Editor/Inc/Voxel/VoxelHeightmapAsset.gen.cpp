// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelAssets/VoxelHeightmapAsset.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelHeightmapAsset() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelHeightmapAsset_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelHeightmapAsset();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelWorldGenerator();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelHeightmapAssetFloat_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelHeightmapAssetFloat();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelHeightmapAssetUINT16_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelHeightmapAssetUINT16();
// End Cross Module References
	void UVoxelHeightmapAsset::StaticRegisterNativesUVoxelHeightmapAsset()
	{
		UClass* Class = UVoxelHeightmapAsset::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetHeight", &UVoxelHeightmapAsset::execGetHeight },
			{ "GetWidth", &UVoxelHeightmapAsset::execGetWidth },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight_Statics
	{
		struct VoxelHeightmapAsset_eventGetHeight_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelHeightmapAsset_eventGetHeight_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelHeightmapAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelHeightmapAsset, "GetHeight", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(VoxelHeightmapAsset_eventGetHeight_Parms), Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth_Statics
	{
		struct VoxelHeightmapAsset_eventGetWidth_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelHeightmapAsset_eventGetWidth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelHeightmapAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelHeightmapAsset, "GetWidth", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(VoxelHeightmapAsset_eventGetWidth_Parms), Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelHeightmapAsset_NoRegister()
	{
		return UVoxelHeightmapAsset::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelHeightmapAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Height;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Width;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Version_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Version;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScaleMultiplier_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ScaleMultiplier;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AdditionalThickness_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AdditionalThickness;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HeightOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HeightOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HeightMultiplier_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HeightMultiplier;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Precision_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Precision;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelHeightmapAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelWorldGenerator,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelHeightmapAsset_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelHeightmapAsset_GetHeight, "GetHeight" }, // 1321641280
		{ &Z_Construct_UFunction_UVoxelHeightmapAsset_GetWidth, "GetWidth" }, // 981880710
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapAsset_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "VoxelAssets/VoxelHeightmapAsset.h" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelHeightmapAsset.h" },
		{ "SerializeToFArchive", "" },
		{ "ToolTip", "Asset that holds 2D information." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Height_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelHeightmapAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Height = { UE4CodeGen_Private::EPropertyClass::Int, "Height", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelHeightmapAsset, Height), METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Height_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Height_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Width_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelHeightmapAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Width = { UE4CodeGen_Private::EPropertyClass::Int, "Width", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelHeightmapAsset, Width), METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Width_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Width_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Version_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelHeightmapAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Version = { UE4CodeGen_Private::EPropertyClass::Int, "Version", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelHeightmapAsset, Version), METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Version_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Version_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_ScaleMultiplier_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelHeightmapAsset.h" },
		{ "UIMin", "1" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_ScaleMultiplier = { UE4CodeGen_Private::EPropertyClass::Int, "ScaleMultiplier", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelHeightmapAsset, ScaleMultiplier), METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_ScaleMultiplier_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_ScaleMultiplier_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_AdditionalThickness_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelHeightmapAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_AdditionalThickness = { UE4CodeGen_Private::EPropertyClass::Float, "AdditionalThickness", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelHeightmapAsset, AdditionalThickness), METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_AdditionalThickness_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_AdditionalThickness_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_HeightOffset_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelHeightmapAsset.h" },
		{ "ToolTip", "In world size, applied after HeightMultiplier" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_HeightOffset = { UE4CodeGen_Private::EPropertyClass::Float, "HeightOffset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelHeightmapAsset, HeightOffset), METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_HeightOffset_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_HeightOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_HeightMultiplier_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelHeightmapAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_HeightMultiplier = { UE4CodeGen_Private::EPropertyClass::Float, "HeightMultiplier", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelHeightmapAsset, HeightMultiplier), METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_HeightMultiplier_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_HeightMultiplier_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Precision_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelHeightmapAsset.h" },
		{ "ToolTip", "Higher precision can improve render quality, but voxel values are lower (hardness not constant)" },
		{ "UIMin", "1" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Precision = { UE4CodeGen_Private::EPropertyClass::Int, "Precision", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelHeightmapAsset, Precision), METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Precision_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Precision_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelHeightmapAsset_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Height,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Width,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Version,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_ScaleMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_AdditionalThickness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_HeightOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_HeightMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelHeightmapAsset_Statics::NewProp_Precision,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelHeightmapAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelHeightmapAsset>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelHeightmapAsset_Statics::ClassParams = {
		&UVoxelHeightmapAsset::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A1u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UVoxelHeightmapAsset_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapAsset_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelHeightmapAsset()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelHeightmapAsset_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelHeightmapAsset, 1986232422);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelHeightmapAsset(Z_Construct_UClass_UVoxelHeightmapAsset, &UVoxelHeightmapAsset::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelHeightmapAsset"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelHeightmapAsset);
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(UVoxelHeightmapAsset)
	void UVoxelHeightmapAssetFloat::StaticRegisterNativesUVoxelHeightmapAssetFloat()
	{
	}
	UClass* Z_Construct_UClass_UVoxelHeightmapAssetFloat_NoRegister()
	{
		return UVoxelHeightmapAssetFloat::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelHeightmapAssetFloat_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelHeightmapAssetFloat_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelHeightmapAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapAssetFloat_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelAssets/VoxelHeightmapAsset.h" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelHeightmapAsset.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelHeightmapAssetFloat_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelHeightmapAssetFloat>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelHeightmapAssetFloat_Statics::ClassParams = {
		&UVoxelHeightmapAssetFloat::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x041000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapAssetFloat_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapAssetFloat_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelHeightmapAssetFloat()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelHeightmapAssetFloat_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelHeightmapAssetFloat, 1610526678);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelHeightmapAssetFloat(Z_Construct_UClass_UVoxelHeightmapAssetFloat, &UVoxelHeightmapAssetFloat::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelHeightmapAssetFloat"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelHeightmapAssetFloat);
	void UVoxelHeightmapAssetUINT16::StaticRegisterNativesUVoxelHeightmapAssetUINT16()
	{
	}
	UClass* Z_Construct_UClass_UVoxelHeightmapAssetUINT16_NoRegister()
	{
		return UVoxelHeightmapAssetUINT16::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelHeightmapAssetUINT16_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelHeightmapAssetUINT16_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelHeightmapAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapAssetUINT16_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelAssets/VoxelHeightmapAsset.h" },
		{ "ModuleRelativePath", "Public/VoxelAssets/VoxelHeightmapAsset.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelHeightmapAssetUINT16_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelHeightmapAssetUINT16>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelHeightmapAssetUINT16_Statics::ClassParams = {
		&UVoxelHeightmapAssetUINT16::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x041000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapAssetUINT16_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapAssetUINT16_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelHeightmapAssetUINT16()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelHeightmapAssetUINT16_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelHeightmapAssetUINT16, 2145926842);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelHeightmapAssetUINT16(Z_Construct_UClass_UVoxelHeightmapAssetUINT16, &UVoxelHeightmapAssetUINT16::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelHeightmapAssetUINT16"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelHeightmapAssetUINT16);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
