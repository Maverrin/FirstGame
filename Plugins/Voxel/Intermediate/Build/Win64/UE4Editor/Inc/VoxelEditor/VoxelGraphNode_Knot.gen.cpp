// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/Graph/VoxelGraphNode_Knot.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelGraphNode_Knot() {}
// Cross Module References
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGraphNode_Knot_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGraphNode_Knot();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGraphNode_Base();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
// End Cross Module References
	void UVoxelGraphNode_Knot::StaticRegisterNativesUVoxelGraphNode_Knot()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGraphNode_Knot_NoRegister()
	{
		return UVoxelGraphNode_Knot::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGraphNode_Knot_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGraphNode_Knot_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelGraphNode_Base,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphNode_Knot_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/VoxelGraphNode_Knot.h" },
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphNode_Knot.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGraphNode_Knot_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGraphNode_Knot>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGraphNode_Knot_Statics::ClassParams = {
		&UVoxelGraphNode_Knot::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000800A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphNode_Knot_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphNode_Knot_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGraphNode_Knot()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGraphNode_Knot_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGraphNode_Knot, 2281519138);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGraphNode_Knot(Z_Construct_UClass_UVoxelGraphNode_Knot, &UVoxelGraphNode_Knot::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelGraphNode_Knot"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGraphNode_Knot);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
