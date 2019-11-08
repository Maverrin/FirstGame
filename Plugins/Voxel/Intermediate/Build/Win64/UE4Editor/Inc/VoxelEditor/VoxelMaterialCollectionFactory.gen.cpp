// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/Factories/VoxelMaterialCollectionFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelMaterialCollectionFactory() {}
// Cross Module References
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelMaterialCollectionFactory_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelMaterialCollectionFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
// End Cross Module References
	void UVoxelMaterialCollectionFactory::StaticRegisterNativesUVoxelMaterialCollectionFactory()
	{
	}
	UClass* Z_Construct_UClass_UVoxelMaterialCollectionFactory_NoRegister()
	{
		return UVoxelMaterialCollectionFactory::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelMaterialCollectionFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelMaterialCollectionFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollectionFactory_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Factories/VoxelMaterialCollectionFactory.h" },
		{ "ModuleRelativePath", "Private/Factories/VoxelMaterialCollectionFactory.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelMaterialCollectionFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelMaterialCollectionFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelMaterialCollectionFactory_Statics::ClassParams = {
		&UVoxelMaterialCollectionFactory::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollectionFactory_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollectionFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelMaterialCollectionFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelMaterialCollectionFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelMaterialCollectionFactory, 4242138745);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelMaterialCollectionFactory(Z_Construct_UClass_UVoxelMaterialCollectionFactory, &UVoxelMaterialCollectionFactory::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelMaterialCollectionFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelMaterialCollectionFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
