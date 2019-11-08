// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelWorldGenerators/EmptyWorldGenerator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEmptyWorldGenerator() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UEmptyWorldGenerator_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UEmptyWorldGenerator();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelWorldGenerator();
	UPackage* Z_Construct_UPackage__Script_Voxel();
// End Cross Module References
	void UEmptyWorldGenerator::StaticRegisterNativesUEmptyWorldGenerator()
	{
	}
	UClass* Z_Construct_UClass_UEmptyWorldGenerator_NoRegister()
	{
		return UEmptyWorldGenerator::StaticClass();
	}
	struct Z_Construct_UClass_UEmptyWorldGenerator_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEmptyWorldGenerator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelWorldGenerator,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEmptyWorldGenerator_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "VoxelWorldGenerators/EmptyWorldGenerator.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VoxelWorldGenerators/EmptyWorldGenerator.h" },
		{ "ToolTip", "Empty World" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEmptyWorldGenerator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEmptyWorldGenerator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UEmptyWorldGenerator_Statics::ClassParams = {
		&UEmptyWorldGenerator::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UEmptyWorldGenerator_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UEmptyWorldGenerator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEmptyWorldGenerator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UEmptyWorldGenerator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UEmptyWorldGenerator, 3329822342);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UEmptyWorldGenerator(Z_Construct_UClass_UEmptyWorldGenerator, &UEmptyWorldGenerator::StaticClass, TEXT("/Script/Voxel"), TEXT("UEmptyWorldGenerator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEmptyWorldGenerator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
