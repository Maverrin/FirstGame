// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelPlaceableItems/VoxelPlaceableItemActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelPlaceableItemActor() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_AVoxelPlaceableItemActor_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelPlaceableItemActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
// End Cross Module References
	void AVoxelPlaceableItemActor::StaticRegisterNativesAVoxelPlaceableItemActor()
	{
	}
	UClass* Z_Construct_UClass_AVoxelPlaceableItemActor_NoRegister()
	{
		return AVoxelPlaceableItemActor::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelPlaceableItemActor_Statics
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
	UObject* (*const Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Tick Replication Input Actor Rendering HOLD LOD Cooking" },
		{ "IncludePath", "VoxelPlaceableItems/VoxelPlaceableItemActor.h" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelPlaceableItemActor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::NewProp_World_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelPlaceableItemActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AVoxelPlaceableItemActor, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::NewProp_World_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::NewProp_World_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::NewProp_World,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelPlaceableItemActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::ClassParams = {
		&AVoxelPlaceableItemActor::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelPlaceableItemActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelPlaceableItemActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelPlaceableItemActor, 1817612750);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelPlaceableItemActor(Z_Construct_UClass_AVoxelPlaceableItemActor, &AVoxelPlaceableItemActor::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelPlaceableItemActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelPlaceableItemActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
