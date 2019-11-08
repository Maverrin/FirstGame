// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelGraph/VoxelExposedNodes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelExposedNodes() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelExposedNode_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelExposedNode();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNodeHelper();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_FConstant_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_FConstant();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_IConstant_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_IConstant();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_Curve_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_Curve();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_CurveColor_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_CurveColor();
	ENGINE_API UClass* Z_Construct_UClass_UCurveLinearColor_NoRegister();
// End Cross Module References
	void UVoxelExposedNode::StaticRegisterNativesUVoxelExposedNode()
	{
	}
	UClass* Z_Construct_UClass_UVoxelExposedNode_NoRegister()
	{
		return UVoxelExposedNode::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelExposedNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Priority_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Priority;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Category;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UniqueName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_UniqueName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelExposedNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNodeHelper,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelExposedNode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExposedNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_Priority_MetaData[] = {
		{ "Category", "Parameter" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_Priority = { UE4CodeGen_Private::EPropertyClass::Int, "Priority", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelExposedNode, Priority), METADATA_PARAMS(Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_Priority_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_Priority_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_Category_MetaData[] = {
		{ "Category", "Parameter" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_Category = { UE4CodeGen_Private::EPropertyClass::Str, "Category", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelExposedNode, Category), METADATA_PARAMS(Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_Category_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_Category_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_UniqueName_MetaData[] = {
		{ "Category", "Parameter" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_UniqueName = { UE4CodeGen_Private::EPropertyClass::Str, "UniqueName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelExposedNode, UniqueName), METADATA_PARAMS(Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_UniqueName_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_UniqueName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelExposedNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_Priority,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_Category,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelExposedNode_Statics::NewProp_UniqueName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelExposedNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelExposedNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelExposedNode_Statics::ClassParams = {
		&UVoxelExposedNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A1u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelExposedNode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelExposedNode_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelExposedNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelExposedNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelExposedNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelExposedNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelExposedNode, 3122849960);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelExposedNode(Z_Construct_UClass_UVoxelExposedNode, &UVoxelExposedNode::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelExposedNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelExposedNode);
	void UVoxelNode_FConstant::StaticRegisterNativesUVoxelNode_FConstant()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_FConstant_NoRegister()
	{
		return UVoxelNode_FConstant::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_FConstant_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bExposeToBP_MetaData[];
#endif
		static void NewProp_bExposeToBP_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bExposeToBP;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_FConstant_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelExposedNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_FConstant_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Constant (float)" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExposedNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
		{ "ToolTip", "Float constant" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_FConstant_Statics::NewProp_bExposeToBP_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelNode_FConstant_Statics::NewProp_bExposeToBP_SetBit(void* Obj)
	{
		((UVoxelNode_FConstant*)Obj)->bExposeToBP = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelNode_FConstant_Statics::NewProp_bExposeToBP = { UE4CodeGen_Private::EPropertyClass::Bool, "bExposeToBP", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelNode_FConstant), &Z_Construct_UClass_UVoxelNode_FConstant_Statics::NewProp_bExposeToBP_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_FConstant_Statics::NewProp_bExposeToBP_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_FConstant_Statics::NewProp_bExposeToBP_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_FConstant_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelNode_FConstant_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelNode_FConstant, Value), METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_FConstant_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_FConstant_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelNode_FConstant_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_FConstant_Statics::NewProp_bExposeToBP,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_FConstant_Statics::NewProp_Value,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_FConstant_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode_FConstant>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_FConstant_Statics::ClassParams = {
		&UVoxelNode_FConstant::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelNode_FConstant_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_FConstant_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_FConstant_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_FConstant_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode_FConstant()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_FConstant_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode_FConstant, 2000481878);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode_FConstant(Z_Construct_UClass_UVoxelNode_FConstant, &UVoxelNode_FConstant::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode_FConstant"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode_FConstant);
	void UVoxelNode_IConstant::StaticRegisterNativesUVoxelNode_IConstant()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_IConstant_NoRegister()
	{
		return UVoxelNode_IConstant::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_IConstant_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bExposeToBP_MetaData[];
#endif
		static void NewProp_bExposeToBP_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bExposeToBP;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_IConstant_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelExposedNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_IConstant_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Constant (int)" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExposedNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
		{ "ToolTip", "Int constant" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_IConstant_Statics::NewProp_bExposeToBP_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelNode_IConstant_Statics::NewProp_bExposeToBP_SetBit(void* Obj)
	{
		((UVoxelNode_IConstant*)Obj)->bExposeToBP = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelNode_IConstant_Statics::NewProp_bExposeToBP = { UE4CodeGen_Private::EPropertyClass::Bool, "bExposeToBP", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelNode_IConstant), &Z_Construct_UClass_UVoxelNode_IConstant_Statics::NewProp_bExposeToBP_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_IConstant_Statics::NewProp_bExposeToBP_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_IConstant_Statics::NewProp_bExposeToBP_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_IConstant_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UVoxelNode_IConstant_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelNode_IConstant, Value), METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_IConstant_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_IConstant_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelNode_IConstant_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_IConstant_Statics::NewProp_bExposeToBP,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_IConstant_Statics::NewProp_Value,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_IConstant_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode_IConstant>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_IConstant_Statics::ClassParams = {
		&UVoxelNode_IConstant::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelNode_IConstant_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_IConstant_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_IConstant_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_IConstant_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode_IConstant()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_IConstant_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode_IConstant, 2366258901);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode_IConstant(Z_Construct_UClass_UVoxelNode_IConstant, &UVoxelNode_IConstant::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode_IConstant"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode_IConstant);
	void UVoxelNode_WorldGeneratorSampler::StaticRegisterNativesUVoxelNode_WorldGeneratorSampler()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_NoRegister()
	{
		return UVoxelNode_WorldGeneratorSampler::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Seeds_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Seeds;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Seeds_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldGenerator_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_WorldGenerator;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelExposedNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "World Generator Sampler" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExposedNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
		{ "ToolTip", "Sample another world generator. Expensive" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::NewProp_Seeds_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::NewProp_Seeds = { UE4CodeGen_Private::EPropertyClass::Array, "Seeds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelNode_WorldGeneratorSampler, Seeds), METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::NewProp_Seeds_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::NewProp_Seeds_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::NewProp_Seeds_Inner = { UE4CodeGen_Private::EPropertyClass::Str, "Seeds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::NewProp_WorldGenerator_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::NewProp_WorldGenerator = { UE4CodeGen_Private::EPropertyClass::Struct, "WorldGenerator", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelNode_WorldGeneratorSampler, WorldGenerator), Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker, METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::NewProp_WorldGenerator_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::NewProp_WorldGenerator_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::NewProp_Seeds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::NewProp_Seeds_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::NewProp_WorldGenerator,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode_WorldGeneratorSampler>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::ClassParams = {
		&UVoxelNode_WorldGeneratorSampler::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode_WorldGeneratorSampler, 3790520612);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode_WorldGeneratorSampler(Z_Construct_UClass_UVoxelNode_WorldGeneratorSampler, &UVoxelNode_WorldGeneratorSampler::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode_WorldGeneratorSampler"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode_WorldGeneratorSampler);
	void UVoxelNode_Curve::StaticRegisterNativesUVoxelNode_Curve()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_Curve_NoRegister()
	{
		return UVoxelNode_Curve::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_Curve_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Curve_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Curve;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_Curve_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelExposedNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_Curve_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Curve" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExposedNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
		{ "ToolTip", "Apply a float curve" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_Curve_Statics::NewProp_Curve_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelNode_Curve_Statics::NewProp_Curve = { UE4CodeGen_Private::EPropertyClass::Object, "Curve", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelNode_Curve, Curve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_Curve_Statics::NewProp_Curve_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_Curve_Statics::NewProp_Curve_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelNode_Curve_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_Curve_Statics::NewProp_Curve,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_Curve_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode_Curve>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_Curve_Statics::ClassParams = {
		&UVoxelNode_Curve::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelNode_Curve_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_Curve_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_Curve_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_Curve_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode_Curve()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_Curve_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode_Curve, 951058219);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode_Curve(Z_Construct_UClass_UVoxelNode_Curve, &UVoxelNode_Curve::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode_Curve"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode_Curve);
	void UVoxelNode_CurveColor::StaticRegisterNativesUVoxelNode_CurveColor()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_CurveColor_NoRegister()
	{
		return UVoxelNode_CurveColor::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_CurveColor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Curve_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Curve;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_CurveColor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelExposedNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_CurveColor_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Curve Color" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExposedNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
		{ "ToolTip", "Apply a color curve" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_CurveColor_Statics::NewProp_Curve_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExposedNodes.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelNode_CurveColor_Statics::NewProp_Curve = { UE4CodeGen_Private::EPropertyClass::Object, "Curve", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelNode_CurveColor, Curve), Z_Construct_UClass_UCurveLinearColor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_CurveColor_Statics::NewProp_Curve_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_CurveColor_Statics::NewProp_Curve_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelNode_CurveColor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_CurveColor_Statics::NewProp_Curve,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_CurveColor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode_CurveColor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_CurveColor_Statics::ClassParams = {
		&UVoxelNode_CurveColor::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelNode_CurveColor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_CurveColor_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_CurveColor_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_CurveColor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode_CurveColor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_CurveColor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode_CurveColor, 3460513503);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode_CurveColor(Z_Construct_UClass_UVoxelNode_CurveColor, &UVoxelNode_CurveColor::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode_CurveColor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode_CurveColor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
