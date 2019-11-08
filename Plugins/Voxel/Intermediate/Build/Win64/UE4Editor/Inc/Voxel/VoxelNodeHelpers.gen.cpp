// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelGraph/VoxelNodeHelpers.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelNodeHelpers() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNodeHelper_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNodeHelper();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode();
	UPackage* Z_Construct_UPackage__Script_Voxel();
// End Cross Module References
	void UVoxelNodeHelper::StaticRegisterNativesUVoxelNodeHelper()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNodeHelper_NoRegister()
	{
		return UVoxelNodeHelper::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNodeHelper_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNodeHelper_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNodeHelper_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelNodeHelpers.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNodeHelpers.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNodeHelper_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNodeHelper>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNodeHelper_Statics::ClassParams = {
		&UVoxelNodeHelper::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A1u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNodeHelper_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNodeHelper_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNodeHelper()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNodeHelper_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNodeHelper, 505976478);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNodeHelper(Z_Construct_UClass_UVoxelNodeHelper, &UVoxelNodeHelper::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNodeHelper"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNodeHelper);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
