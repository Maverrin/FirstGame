// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/Graph/VoxelDebugNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelDebugNode() {}
// Cross Module References
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelDebugNode_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelDebugNode();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
// End Cross Module References
	void UVoxelDebugNode::StaticRegisterNativesUVoxelDebugNode()
	{
	}
	UClass* Z_Construct_UClass_UVoxelDebugNode_NoRegister()
	{
		return UVoxelDebugNode::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelDebugNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelDebugNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNode,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDebugNode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "Graph/VoxelDebugNode.h" },
		{ "ModuleRelativePath", "Private/Graph/VoxelDebugNode.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelDebugNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelDebugNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelDebugNode_Statics::ClassParams = {
		&UVoxelDebugNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000012A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelDebugNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelDebugNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelDebugNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelDebugNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelDebugNode, 2046598606);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelDebugNode(Z_Construct_UClass_UVoxelDebugNode, &UVoxelDebugNode::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelDebugNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelDebugNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
