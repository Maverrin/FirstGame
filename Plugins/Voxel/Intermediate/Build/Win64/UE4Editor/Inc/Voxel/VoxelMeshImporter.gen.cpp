// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelImporters/VoxelMeshImporter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelMeshImporter() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_AVoxelMeshImporter_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelMeshImporter();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
// End Cross Module References
	void AVoxelMeshImporter::StaticRegisterNativesAVoxelMeshImporter()
	{
	}
	UClass* Z_Construct_UClass_AVoxelMeshImporter_NoRegister()
	{
		return AVoxelMeshImporter::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelMeshImporter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VoxelSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VoxelSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StaticMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelMeshImporter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelMeshImporter_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Tick Replication Input Actor Rendering HOLD LOD Cooking" },
		{ "IncludePath", "VoxelImporters/VoxelMeshImporter.h" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelMeshImporter.h" },
		{ "ToolTip", "Actor that creates a VoxelDataAsset from a static mesh" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_MeshComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelMeshImporter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_MeshComponent = { UE4CodeGen_Private::EPropertyClass::Object, "MeshComponent", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000080008, 1, nullptr, STRUCT_OFFSET(AVoxelMeshImporter, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_MeshComponent_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_MeshComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_VoxelSize_MetaData[] = {
		{ "Category", "Import configuration" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelMeshImporter.h" },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_VoxelSize = { UE4CodeGen_Private::EPropertyClass::Float, "VoxelSize", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AVoxelMeshImporter, VoxelSize), METADATA_PARAMS(Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_VoxelSize_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_VoxelSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_StaticMesh_MetaData[] = {
		{ "Category", "Import configuration" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelMeshImporter.h" },
		{ "ToolTip", "The static mesh to import from" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_StaticMesh = { UE4CodeGen_Private::EPropertyClass::Object, "StaticMesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AVoxelMeshImporter, StaticMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_StaticMesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_StaticMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelMeshImporter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_MeshComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_VoxelSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelMeshImporter_Statics::NewProp_StaticMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelMeshImporter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelMeshImporter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelMeshImporter_Statics::ClassParams = {
		&AVoxelMeshImporter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AVoxelMeshImporter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelMeshImporter_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelMeshImporter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelMeshImporter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelMeshImporter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelMeshImporter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelMeshImporter, 3632209151);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelMeshImporter(Z_Construct_UClass_AVoxelMeshImporter, &AVoxelMeshImporter::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelMeshImporter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelMeshImporter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
