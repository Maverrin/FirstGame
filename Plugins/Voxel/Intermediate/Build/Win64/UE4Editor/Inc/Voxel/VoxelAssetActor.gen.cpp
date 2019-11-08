// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelPlaceableItems/VoxelAssetActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelAssetActor() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_AVoxelAssetActor_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelAssetActor();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelPlaceableItemActor();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelProceduralMeshComponent_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelDataAsset_NoRegister();
// End Cross Module References
	void AVoxelAssetActor::StaticRegisterNativesAVoxelAssetActor()
	{
	}
	UClass* Z_Construct_UClass_AVoxelAssetActor_NoRegister()
	{
		return AVoxelAssetActor::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelAssetActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialsRef_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MaterialsRef;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Root_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Root;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Box_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Box;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Meshes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Meshes;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Meshes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxOctreeDepth_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MaxOctreeDepth;
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bInvert_MetaData[];
#endif
		static void NewProp_bInvert_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInvert;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Priority_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Priority;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Asset_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelAssetActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AVoxelPlaceableItemActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelAssetActor_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Tick Replication Input Actor Rendering HOLD LOD Cooking" },
		{ "IncludePath", "VoxelPlaceableItems/VoxelAssetActor.h" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelAssetActor.h" },
	};
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_MaterialsRef_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelAssetActor.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_MaterialsRef = { UE4CodeGen_Private::EPropertyClass::Struct, "MaterialsRef", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000800000000, 1, nullptr, STRUCT_OFFSET(AVoxelAssetActor, MaterialsRef), Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder, METADATA_PARAMS(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_MaterialsRef_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_MaterialsRef_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Root_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelAssetActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Root = { UE4CodeGen_Private::EPropertyClass::Object, "Root", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000800080008, 1, nullptr, STRUCT_OFFSET(AVoxelAssetActor, Root), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Root_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Root_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Box_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelAssetActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Box = { UE4CodeGen_Private::EPropertyClass::Object, "Box", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000800080008, 1, nullptr, STRUCT_OFFSET(AVoxelAssetActor, Box), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Box_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Box_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Meshes_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelAssetActor.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Meshes = { UE4CodeGen_Private::EPropertyClass::Array, "Meshes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040008800002008, 1, nullptr, STRUCT_OFFSET(AVoxelAssetActor, Meshes), METADATA_PARAMS(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Meshes_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Meshes_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Meshes_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Meshes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000800080008, 1, nullptr, 0, Z_Construct_UClass_UVoxelProceduralMeshComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_MaxOctreeDepth_MetaData[] = {
		{ "Category", "Preview Settings" },
		{ "ClampMax", "25" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelAssetActor.h" },
		{ "UIMax", "25" },
		{ "UIMin", "1" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_MaxOctreeDepth = { UE4CodeGen_Private::EPropertyClass::Int, "MaxOctreeDepth", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000800000001, 1, nullptr, STRUCT_OFFSET(AVoxelAssetActor, MaxOctreeDepth), METADATA_PARAMS(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_MaxOctreeDepth_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_MaxOctreeDepth_MetaData)) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_bInvert_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelAssetActor.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_bInvert_SetBit(void* Obj)
	{
		((AVoxelAssetActor*)Obj)->bInvert = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_bInvert = { UE4CodeGen_Private::EPropertyClass::Bool, "bInvert", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelAssetActor), &Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_bInvert_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_bInvert_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_bInvert_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Priority_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelAssetActor.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Priority = { UE4CodeGen_Private::EPropertyClass::Int, "Priority", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AVoxelAssetActor, Priority), METADATA_PARAMS(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Priority_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Priority_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Asset_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelPlaceableItems/VoxelAssetActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Asset = { UE4CodeGen_Private::EPropertyClass::Object, "Asset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AVoxelAssetActor, Asset), Z_Construct_UClass_UVoxelDataAsset_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Asset_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Asset_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelAssetActor_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_MaterialsRef,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Root,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Box,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Meshes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Meshes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_MaxOctreeDepth,
#endif // WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_bInvert,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Priority,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelAssetActor_Statics::NewProp_Asset,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelAssetActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelAssetActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelAssetActor_Statics::ClassParams = {
		&AVoxelAssetActor::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AVoxelAssetActor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelAssetActor_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelAssetActor_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelAssetActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelAssetActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelAssetActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelAssetActor, 2157187162);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelAssetActor(Z_Construct_UClass_AVoxelAssetActor, &AVoxelAssetActor::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelAssetActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelAssetActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
