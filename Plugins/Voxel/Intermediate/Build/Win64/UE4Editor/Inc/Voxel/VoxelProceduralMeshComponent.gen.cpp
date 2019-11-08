// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelRender/VoxelProceduralMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelProceduralMeshComponent() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelProceduralMeshComponent_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelProceduralMeshComponent();
	ENGINE_API UClass* Z_Construct_UClass_UMeshComponent();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBodySetup_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UInterface_CollisionDataProvider_NoRegister();
// End Cross Module References
	void UVoxelProceduralMeshComponent::StaticRegisterNativesUVoxelProceduralMeshComponent()
	{
	}
	UClass* Z_Construct_UClass_UVoxelProceduralMeshComponent_NoRegister()
	{
		return UVoxelProceduralMeshComponent::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SectionMaterials_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SectionMaterials;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SectionMaterials_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AsyncBodySetupQueue_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_AsyncBodySetupQueue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AsyncBodySetupQueue_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProcMeshBodySetup_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProcMeshBodySetup;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMeshComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Mobility Trigger" },
		{ "IncludePath", "VoxelRender/VoxelProceduralMeshComponent.h" },
		{ "ModuleRelativePath", "Public/VoxelRender/VoxelProceduralMeshComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_SectionMaterials_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelRender/VoxelProceduralMeshComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_SectionMaterials = { UE4CodeGen_Private::EPropertyClass::Array, "SectionMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelProceduralMeshComponent, SectionMaterials), METADATA_PARAMS(Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_SectionMaterials_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_SectionMaterials_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_SectionMaterials_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "SectionMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_AsyncBodySetupQueue_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelRender/VoxelProceduralMeshComponent.h" },
		{ "ToolTip", "Queue for async body setups that are being cooked" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_AsyncBodySetupQueue = { UE4CodeGen_Private::EPropertyClass::Array, "AsyncBodySetupQueue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelProceduralMeshComponent, AsyncBodySetupQueue), METADATA_PARAMS(Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_AsyncBodySetupQueue_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_AsyncBodySetupQueue_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_AsyncBodySetupQueue_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "AsyncBodySetupQueue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UBodySetup_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_ProcMeshBodySetup_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelRender/VoxelProceduralMeshComponent.h" },
		{ "ToolTip", "Collision data" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_ProcMeshBodySetup = { UE4CodeGen_Private::EPropertyClass::Object, "ProcMeshBodySetup", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelProceduralMeshComponent, ProcMeshBodySetup), Z_Construct_UClass_UBodySetup_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_ProcMeshBodySetup_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_ProcMeshBodySetup_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_SectionMaterials,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_SectionMaterials_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_AsyncBodySetupQueue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_AsyncBodySetupQueue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::NewProp_ProcMeshBodySetup,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInterface_CollisionDataProvider_NoRegister, (int32)VTABLE_OFFSET(UVoxelProceduralMeshComponent, IInterface_CollisionDataProvider), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelProceduralMeshComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::ClassParams = {
		&UVoxelProceduralMeshComponent::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		InterfaceParams, ARRAY_COUNT(InterfaceParams),
		METADATA_PARAMS(Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelProceduralMeshComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelProceduralMeshComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelProceduralMeshComponent, 4283123374);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelProceduralMeshComponent(Z_Construct_UClass_UVoxelProceduralMeshComponent, &UVoxelProceduralMeshComponent::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelProceduralMeshComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelProceduralMeshComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
