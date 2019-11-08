// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/VoxelWorldEditor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelWorldEditor() {}
// Cross Module References
	VOXELEDITOR_API UClass* Z_Construct_UClass_AVoxelWorldEditor_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_AVoxelWorldEditor();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorldEditorInterface();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelInvokerComponent_NoRegister();
// End Cross Module References
	void AVoxelWorldEditor::StaticRegisterNativesAVoxelWorldEditor()
	{
	}
	UClass* Z_Construct_UClass_AVoxelWorldEditor_NoRegister()
	{
		return AVoxelWorldEditor::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelWorldEditor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Invoker_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Invoker;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelWorldEditor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AVoxelWorldEditorInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelWorldEditor_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Tick Replication Input Actor Rendering Hide Tick Replication Input Actor Rendering Hide" },
		{ "IncludePath", "VoxelWorldEditor.h" },
		{ "ModuleRelativePath", "Private/VoxelWorldEditor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelWorldEditor_Statics::NewProp_Invoker_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/VoxelWorldEditor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelWorldEditor_Statics::NewProp_Invoker = { UE4CodeGen_Private::EPropertyClass::Object, "Invoker", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000080008, 1, nullptr, STRUCT_OFFSET(AVoxelWorldEditor, Invoker), Z_Construct_UClass_UVoxelInvokerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelWorldEditor_Statics::NewProp_Invoker_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelWorldEditor_Statics::NewProp_Invoker_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelWorldEditor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelWorldEditor_Statics::NewProp_Invoker,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelWorldEditor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelWorldEditor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelWorldEditor_Statics::ClassParams = {
		&AVoxelWorldEditor::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A0u,
		nullptr, 0,
		Z_Construct_UClass_AVoxelWorldEditor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelWorldEditor_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelWorldEditor_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelWorldEditor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelWorldEditor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelWorldEditor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelWorldEditor, 2225391172);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelWorldEditor(Z_Construct_UClass_AVoxelWorldEditor, &AVoxelWorldEditor::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("AVoxelWorldEditor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelWorldEditor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
