// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/VoxelEditorTools/VoxelEditorToolsPanel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelEditorToolsPanel() {}
// Cross Module References
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelEditorVoxelWorldSelect();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
// End Cross Module References
	void UVoxelEditorVoxelWorldSelect::StaticRegisterNativesUVoxelEditorVoxelWorldSelect()
	{
	}
	UClass* Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_NoRegister()
	{
		return UVoxelEditorVoxelWorldSelect::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_World_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelEditorTools/VoxelEditorToolsPanel.h" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelEditorToolsPanel.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::NewProp_World_MetaData[] = {
		{ "Category", "World to edit" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelEditorToolsPanel.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelEditorVoxelWorldSelect, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::NewProp_World_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::NewProp_World_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::NewProp_World,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelEditorVoxelWorldSelect>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::ClassParams = {
		&UVoxelEditorVoxelWorldSelect::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelEditorVoxelWorldSelect()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelEditorVoxelWorldSelect_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelEditorVoxelWorldSelect, 993665112);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelEditorVoxelWorldSelect(Z_Construct_UClass_UVoxelEditorVoxelWorldSelect, &UVoxelEditorVoxelWorldSelect::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelEditorVoxelWorldSelect"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelEditorVoxelWorldSelect);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
