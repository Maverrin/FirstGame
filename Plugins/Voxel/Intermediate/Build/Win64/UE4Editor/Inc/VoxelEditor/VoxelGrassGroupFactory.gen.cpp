// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/Factories/VoxelGrassGroupFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelGrassGroupFactory() {}
// Cross Module References
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGrassGroupFactory_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGrassGroupFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
// End Cross Module References
	void UVoxelGrassGroupFactory::StaticRegisterNativesUVoxelGrassGroupFactory()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGrassGroupFactory_NoRegister()
	{
		return UVoxelGrassGroupFactory::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGrassGroupFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGrassGroupFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGrassGroupFactory_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Factories/VoxelGrassGroupFactory.h" },
		{ "ModuleRelativePath", "Private/Factories/VoxelGrassGroupFactory.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGrassGroupFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGrassGroupFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGrassGroupFactory_Statics::ClassParams = {
		&UVoxelGrassGroupFactory::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGrassGroupFactory_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGrassGroupFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGrassGroupFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGrassGroupFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGrassGroupFactory, 3013804121);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGrassGroupFactory(Z_Construct_UClass_UVoxelGrassGroupFactory, &UVoxelGrassGroupFactory::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelGrassGroupFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGrassGroupFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
