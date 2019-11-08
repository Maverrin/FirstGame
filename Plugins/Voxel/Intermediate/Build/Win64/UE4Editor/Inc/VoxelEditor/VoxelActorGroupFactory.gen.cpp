// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/Factories/VoxelActorGroupFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelActorGroupFactory() {}
// Cross Module References
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelActorGroupFactory_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelActorGroupFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
// End Cross Module References
	void UVoxelActorGroupFactory::StaticRegisterNativesUVoxelActorGroupFactory()
	{
	}
	UClass* Z_Construct_UClass_UVoxelActorGroupFactory_NoRegister()
	{
		return UVoxelActorGroupFactory::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelActorGroupFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelActorGroupFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelActorGroupFactory_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Factories/VoxelActorGroupFactory.h" },
		{ "ModuleRelativePath", "Private/Factories/VoxelActorGroupFactory.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelActorGroupFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelActorGroupFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelActorGroupFactory_Statics::ClassParams = {
		&UVoxelActorGroupFactory::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelActorGroupFactory_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelActorGroupFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelActorGroupFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelActorGroupFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelActorGroupFactory, 575529690);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelActorGroupFactory(Z_Construct_UClass_UVoxelActorGroupFactory, &UVoxelActorGroupFactory::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelActorGroupFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelActorGroupFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
