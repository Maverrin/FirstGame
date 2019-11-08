// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/Graph/VoxelGraphNode_Root.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelGraphNode_Root() {}
// Cross Module References
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGraphNode_Root_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGraphNode_Root();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGraphNode_Base();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
// End Cross Module References
	void UVoxelGraphNode_Root::StaticRegisterNativesUVoxelGraphNode_Root()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGraphNode_Root_NoRegister()
	{
		return UVoxelGraphNode_Root::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGraphNode_Root_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGraphNode_Root_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelGraphNode_Base,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphNode_Root_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/VoxelGraphNode_Root.h" },
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphNode_Root.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGraphNode_Root_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGraphNode_Root>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGraphNode_Root_Statics::ClassParams = {
		&UVoxelGraphNode_Root::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000800A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphNode_Root_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphNode_Root_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGraphNode_Root()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGraphNode_Root_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGraphNode_Root, 2670759388);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGraphNode_Root(Z_Construct_UClass_UVoxelGraphNode_Root, &UVoxelGraphNode_Root::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelGraphNode_Root"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGraphNode_Root);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
