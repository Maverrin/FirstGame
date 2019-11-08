// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelImporters/VoxelSplineImporter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelSplineImporter() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_AVoxelSplineImporter_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelSplineImporter();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
// End Cross Module References
	void AVoxelSplineImporter::StaticRegisterNativesAVoxelSplineImporter()
	{
	}
	UClass* Z_Construct_UClass_AVoxelSplineImporter_NoRegister()
	{
		return AVoxelSplineImporter::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelSplineImporter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Spheres_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Spheres;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Spheres_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VoxelSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VoxelSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Splines_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Splines;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Splines_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelSplineImporter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelSplineImporter_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Tick Replication Input Actor Rendering HOLD LOD Cooking" },
		{ "IncludePath", "VoxelImporters/VoxelSplineImporter.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelSplineImporter.h" },
		{ "ToolTip", "Actor that convert splines to voxels" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Spheres_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelSplineImporter.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Spheres = { UE4CodeGen_Private::EPropertyClass::Array, "Spheres", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040008000000008, 1, nullptr, STRUCT_OFFSET(AVoxelSplineImporter, Spheres), METADATA_PARAMS(Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Spheres_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Spheres_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Spheres_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Spheres", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000080008, 1, nullptr, 0, Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_VoxelSize_MetaData[] = {
		{ "Category", "Import configuration" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelSplineImporter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_VoxelSize = { UE4CodeGen_Private::EPropertyClass::Float, "VoxelSize", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AVoxelSplineImporter, VoxelSize), METADATA_PARAMS(Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_VoxelSize_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_VoxelSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Splines_MetaData[] = {
		{ "Category", "Splines configuration" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelSplineImporter.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Splines = { UE4CodeGen_Private::EPropertyClass::Array, "Splines", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010008000000009, 1, nullptr, STRUCT_OFFSET(AVoxelSplineImporter, Splines), METADATA_PARAMS(Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Splines_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Splines_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Splines_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Splines", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000080008, 1, nullptr, 0, Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelSplineImporter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Spheres,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Spheres_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_VoxelSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Splines,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelSplineImporter_Statics::NewProp_Splines_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelSplineImporter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelSplineImporter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelSplineImporter_Statics::ClassParams = {
		&AVoxelSplineImporter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AVoxelSplineImporter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelSplineImporter_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelSplineImporter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelSplineImporter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelSplineImporter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelSplineImporter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelSplineImporter, 3376692122);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelSplineImporter(Z_Construct_UClass_AVoxelSplineImporter, &AVoxelSplineImporter::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelSplineImporter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelSplineImporter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
