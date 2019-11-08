// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/Factories/VoxelPlaceableItemActorFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelPlaceableItemActorFactory() {}
// Cross Module References
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelPlaceableItemActorFactory_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelPlaceableItemActorFactory();
	UNREALED_API UClass* Z_Construct_UClass_UActorFactory();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelExclusionBoxFactory_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelExclusionBoxFactory();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelAssetActorFactory_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelAssetActorFactory();
// End Cross Module References
	void UVoxelPlaceableItemActorFactory::StaticRegisterNativesUVoxelPlaceableItemActorFactory()
	{
	}
	UClass* Z_Construct_UClass_UVoxelPlaceableItemActorFactory_NoRegister()
	{
		return UVoxelPlaceableItemActorFactory::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelPlaceableItemActorFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelPlaceableItemActorFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelPlaceableItemActorFactory_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "Factories/VoxelPlaceableItemActorFactory.h" },
		{ "ModuleRelativePath", "Private/Factories/VoxelPlaceableItemActorFactory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelPlaceableItemActorFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelPlaceableItemActorFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelPlaceableItemActorFactory_Statics::ClassParams = {
		&UVoxelPlaceableItemActorFactory::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000030ACu,
		nullptr, 0,
		nullptr, 0,
		"Editor",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelPlaceableItemActorFactory_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelPlaceableItemActorFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelPlaceableItemActorFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelPlaceableItemActorFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelPlaceableItemActorFactory, 3559582589);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelPlaceableItemActorFactory(Z_Construct_UClass_UVoxelPlaceableItemActorFactory, &UVoxelPlaceableItemActorFactory::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelPlaceableItemActorFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelPlaceableItemActorFactory);
	void UVoxelExclusionBoxFactory::StaticRegisterNativesUVoxelExclusionBoxFactory()
	{
	}
	UClass* Z_Construct_UClass_UVoxelExclusionBoxFactory_NoRegister()
	{
		return UVoxelExclusionBoxFactory::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelExclusionBoxFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelExclusionBoxFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelPlaceableItemActorFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelExclusionBoxFactory_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "Factories/VoxelPlaceableItemActorFactory.h" },
		{ "ModuleRelativePath", "Private/Factories/VoxelPlaceableItemActorFactory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelExclusionBoxFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelExclusionBoxFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelExclusionBoxFactory_Statics::ClassParams = {
		&UVoxelExclusionBoxFactory::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000030ACu,
		nullptr, 0,
		nullptr, 0,
		"Editor",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelExclusionBoxFactory_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelExclusionBoxFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelExclusionBoxFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelExclusionBoxFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelExclusionBoxFactory, 3045415027);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelExclusionBoxFactory(Z_Construct_UClass_UVoxelExclusionBoxFactory, &UVoxelExclusionBoxFactory::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelExclusionBoxFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelExclusionBoxFactory);
	void UVoxelAssetActorFactory::StaticRegisterNativesUVoxelAssetActorFactory()
	{
	}
	UClass* Z_Construct_UClass_UVoxelAssetActorFactory_NoRegister()
	{
		return UVoxelAssetActorFactory::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelAssetActorFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelAssetActorFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelPlaceableItemActorFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelAssetActorFactory_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "Factories/VoxelPlaceableItemActorFactory.h" },
		{ "ModuleRelativePath", "Private/Factories/VoxelPlaceableItemActorFactory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelAssetActorFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelAssetActorFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelAssetActorFactory_Statics::ClassParams = {
		&UVoxelAssetActorFactory::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000030ACu,
		nullptr, 0,
		nullptr, 0,
		"Editor",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelAssetActorFactory_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelAssetActorFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelAssetActorFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelAssetActorFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelAssetActorFactory, 1266753629);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelAssetActorFactory(Z_Construct_UClass_UVoxelAssetActorFactory, &UVoxelAssetActorFactory::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelAssetActorFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelAssetActorFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
