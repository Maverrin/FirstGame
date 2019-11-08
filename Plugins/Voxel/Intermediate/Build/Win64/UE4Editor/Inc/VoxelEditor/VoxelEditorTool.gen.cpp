// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Public/VoxelEditorTool.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelEditorTool() {}
// Cross Module References
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelEditorTool_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelEditorTool();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
// End Cross Module References
	void UVoxelEditorTool::StaticRegisterNativesUVoxelEditorTool()
	{
	}
	UClass* Z_Construct_UClass_UVoxelEditorTool_NoRegister()
	{
		return UVoxelEditorTool::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelEditorTool_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelEditorTool_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelEditorTool_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelEditorTool.h" },
		{ "ModuleRelativePath", "Public/VoxelEditorTool.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelEditorTool_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelEditorTool>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelEditorTool_Statics::ClassParams = {
		&UVoxelEditorTool::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A1u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelEditorTool_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelEditorTool_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelEditorTool()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelEditorTool_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelEditorTool, 1889237518);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelEditorTool(Z_Construct_UClass_UVoxelEditorTool, &UVoxelEditorTool::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelEditorTool"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelEditorTool);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
