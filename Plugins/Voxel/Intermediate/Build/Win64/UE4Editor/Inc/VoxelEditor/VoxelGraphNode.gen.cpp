// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/Graph/VoxelGraphNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelGraphNode() {}
// Cross Module References
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGraphNode_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGraphNode();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGraphNode_Base();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_NoRegister();
// End Cross Module References
	void UVoxelGraphNode::StaticRegisterNativesUVoxelGraphNode()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGraphNode_NoRegister()
	{
		return UVoxelGraphNode::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGraphNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VoxelNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VoxelNode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGraphNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelGraphNode_Base,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/VoxelGraphNode.h" },
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphNode.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphNode_Statics::NewProp_VoxelNode_MetaData[] = {
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphNode.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphNode_Statics::NewProp_VoxelNode = { UE4CodeGen_Private::EPropertyClass::Object, "VoxelNode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphNode, VoxelNode), Z_Construct_UClass_UVoxelNode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphNode_Statics::NewProp_VoxelNode_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphNode_Statics::NewProp_VoxelNode_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelGraphNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphNode_Statics::NewProp_VoxelNode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGraphNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGraphNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGraphNode_Statics::ClassParams = {
		&UVoxelGraphNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000800A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelGraphNode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphNode_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGraphNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGraphNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGraphNode, 2551821702);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGraphNode(Z_Construct_UClass_UVoxelGraphNode, &UVoxelGraphNode::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelGraphNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGraphNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
