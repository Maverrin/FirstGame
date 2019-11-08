// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/Factories/VoxelActorSpawnerFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelActorSpawnerFactory() {}
// Cross Module References
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelActorSpawnerFactory_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelActorSpawnerFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
// End Cross Module References
	void UVoxelActorSpawnerFactory::StaticRegisterNativesUVoxelActorSpawnerFactory()
	{
	}
	UClass* Z_Construct_UClass_UVoxelActorSpawnerFactory_NoRegister()
	{
		return UVoxelActorSpawnerFactory::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelActorSpawnerFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelActorSpawnerFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelActorSpawnerFactory_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Factories/VoxelActorSpawnerFactory.h" },
		{ "ModuleRelativePath", "Private/Factories/VoxelActorSpawnerFactory.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelActorSpawnerFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelActorSpawnerFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelActorSpawnerFactory_Statics::ClassParams = {
		&UVoxelActorSpawnerFactory::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelActorSpawnerFactory_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelActorSpawnerFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelActorSpawnerFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelActorSpawnerFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelActorSpawnerFactory, 2527395188);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelActorSpawnerFactory(Z_Construct_UClass_UVoxelActorSpawnerFactory, &UVoxelActorSpawnerFactory::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelActorSpawnerFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelActorSpawnerFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
