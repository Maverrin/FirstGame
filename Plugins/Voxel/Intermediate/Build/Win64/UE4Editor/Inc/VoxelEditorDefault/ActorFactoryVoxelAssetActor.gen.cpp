// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditorDefault/Private/ActorFactoryVoxelAssetActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActorFactoryVoxelAssetActor() {}
// Cross Module References
	VOXELEDITORDEFAULT_API UClass* Z_Construct_UClass_UActorFactoryVoxelAssetActor_NoRegister();
	VOXELEDITORDEFAULT_API UClass* Z_Construct_UClass_UActorFactoryVoxelAssetActor();
	UNREALED_API UClass* Z_Construct_UClass_UActorFactory();
	UPackage* Z_Construct_UPackage__Script_VoxelEditorDefault();
// End Cross Module References
	void UActorFactoryVoxelAssetActor::StaticRegisterNativesUActorFactoryVoxelAssetActor()
	{
	}
	UClass* Z_Construct_UClass_UActorFactoryVoxelAssetActor_NoRegister()
	{
		return UActorFactoryVoxelAssetActor::StaticClass();
	}
	struct Z_Construct_UClass_UActorFactoryVoxelAssetActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UActorFactoryVoxelAssetActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditorDefault,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActorFactoryVoxelAssetActor_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "ActorFactoryVoxelAssetActor.h" },
		{ "ModuleRelativePath", "Private/ActorFactoryVoxelAssetActor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UActorFactoryVoxelAssetActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UActorFactoryVoxelAssetActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UActorFactoryVoxelAssetActor_Statics::ClassParams = {
		&UActorFactoryVoxelAssetActor::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000030ACu,
		nullptr, 0,
		nullptr, 0,
		"Editor",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UActorFactoryVoxelAssetActor_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UActorFactoryVoxelAssetActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UActorFactoryVoxelAssetActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UActorFactoryVoxelAssetActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UActorFactoryVoxelAssetActor, 3312410818);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UActorFactoryVoxelAssetActor(Z_Construct_UClass_UActorFactoryVoxelAssetActor, &UActorFactoryVoxelAssetActor::StaticClass, TEXT("/Script/VoxelEditorDefault"), TEXT("UActorFactoryVoxelAssetActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UActorFactoryVoxelAssetActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
