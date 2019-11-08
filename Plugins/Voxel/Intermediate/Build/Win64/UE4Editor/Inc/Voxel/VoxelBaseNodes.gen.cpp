// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelGraph/VoxelBaseNodes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelBaseNodes() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelMaterialNode_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelMaterialNode();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNodeHelper();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelSeedNode_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelSeedNode();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelFloatNode_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelFloatNode();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelIntNode_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelIntNode();
// End Cross Module References
	void UVoxelMaterialNode::StaticRegisterNativesUVoxelMaterialNode()
	{
	}
	UClass* Z_Construct_UClass_UVoxelMaterialNode_NoRegister()
	{
		return UVoxelMaterialNode::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelMaterialNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelMaterialNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNodeHelper,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialNode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelBaseNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelBaseNodes.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelMaterialNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelMaterialNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelMaterialNode_Statics::ClassParams = {
		&UVoxelMaterialNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A1u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelMaterialNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelMaterialNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelMaterialNode, 2774404758);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelMaterialNode(Z_Construct_UClass_UVoxelMaterialNode, &UVoxelMaterialNode::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelMaterialNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelMaterialNode);
	void UVoxelSeedNode::StaticRegisterNativesUVoxelSeedNode()
	{
	}
	UClass* Z_Construct_UClass_UVoxelSeedNode_NoRegister()
	{
		return UVoxelSeedNode::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelSeedNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelSeedNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNodeHelper,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelSeedNode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelBaseNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelBaseNodes.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelSeedNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelSeedNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelSeedNode_Statics::ClassParams = {
		&UVoxelSeedNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A1u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelSeedNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelSeedNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelSeedNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelSeedNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelSeedNode, 2136200504);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelSeedNode(Z_Construct_UClass_UVoxelSeedNode, &UVoxelSeedNode::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelSeedNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelSeedNode);
	void UVoxelFloatNode::StaticRegisterNativesUVoxelFloatNode()
	{
	}
	UClass* Z_Construct_UClass_UVoxelFloatNode_NoRegister()
	{
		return UVoxelFloatNode::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelFloatNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelFloatNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNodeHelper,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelFloatNode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelBaseNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelBaseNodes.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelFloatNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelFloatNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelFloatNode_Statics::ClassParams = {
		&UVoxelFloatNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A1u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelFloatNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelFloatNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelFloatNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelFloatNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelFloatNode, 3265457353);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelFloatNode(Z_Construct_UClass_UVoxelFloatNode, &UVoxelFloatNode::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelFloatNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelFloatNode);
	void UVoxelIntNode::StaticRegisterNativesUVoxelIntNode()
	{
	}
	UClass* Z_Construct_UClass_UVoxelIntNode_NoRegister()
	{
		return UVoxelIntNode::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelIntNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelIntNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNodeHelper,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelIntNode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelBaseNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelBaseNodes.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelIntNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelIntNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelIntNode_Statics::ClassParams = {
		&UVoxelIntNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A1u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelIntNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelIntNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelIntNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelIntNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelIntNode, 3590439445);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelIntNode(Z_Construct_UClass_UVoxelIntNode, &UVoxelIntNode::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelIntNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelIntNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
