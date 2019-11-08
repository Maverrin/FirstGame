// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelWorldGenerator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelWorldGenerator() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelWorldGenerator_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelWorldGenerator();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_Voxel();
// End Cross Module References
	void UVoxelWorldGenerator::StaticRegisterNativesUVoxelWorldGenerator()
	{
	}
	UClass* Z_Construct_UClass_UVoxelWorldGenerator_NoRegister()
	{
		return UVoxelWorldGenerator::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelWorldGenerator_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelWorldGenerator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelWorldGenerator_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelWorldGenerator.h" },
		{ "ModuleRelativePath", "Public/VoxelWorldGenerator.h" },
		{ "ToolTip", "A UVoxelWorldGenerator is used to create a FVoxelWorldGeneratorInstance" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelWorldGenerator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelWorldGenerator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelWorldGenerator_Statics::ClassParams = {
		&UVoxelWorldGenerator::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A1u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelWorldGenerator_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelWorldGenerator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelWorldGenerator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelWorldGenerator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelWorldGenerator, 3779585860);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelWorldGenerator(Z_Construct_UClass_UVoxelWorldGenerator, &UVoxelWorldGenerator::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelWorldGenerator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelWorldGenerator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
