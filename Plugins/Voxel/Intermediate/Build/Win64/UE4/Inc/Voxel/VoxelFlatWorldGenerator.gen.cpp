// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelWorldGenerators/VoxelFlatWorldGenerator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelFlatWorldGenerator() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelFlatWorldGenerator_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelFlatWorldGenerator();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelWorldGenerator();
	UPackage* Z_Construct_UPackage__Script_Voxel();
// End Cross Module References
	void UVoxelFlatWorldGenerator::StaticRegisterNativesUVoxelFlatWorldGenerator()
	{
	}
	UClass* Z_Construct_UClass_UVoxelFlatWorldGenerator_NoRegister()
	{
		return UVoxelFlatWorldGenerator::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelFlatWorldGenerator_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelFlatWorldGenerator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelWorldGenerator,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelFlatWorldGenerator_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "VoxelWorldGenerators/VoxelFlatWorldGenerator.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VoxelWorldGenerators/VoxelFlatWorldGenerator.h" },
		{ "ToolTip", "Flat world" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelFlatWorldGenerator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelFlatWorldGenerator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelFlatWorldGenerator_Statics::ClassParams = {
		&UVoxelFlatWorldGenerator::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelFlatWorldGenerator_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelFlatWorldGenerator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelFlatWorldGenerator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelFlatWorldGenerator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelFlatWorldGenerator, 214670486);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelFlatWorldGenerator(Z_Construct_UClass_UVoxelFlatWorldGenerator, &UVoxelFlatWorldGenerator::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelFlatWorldGenerator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelFlatWorldGenerator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
