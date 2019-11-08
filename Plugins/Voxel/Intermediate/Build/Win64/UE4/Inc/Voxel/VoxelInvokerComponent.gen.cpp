// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelComponents/VoxelInvokerComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelInvokerComponent() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelInvokerComponent_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelInvokerComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_Voxel();
// End Cross Module References
	void UVoxelInvokerComponent::StaticRegisterNativesUVoxelInvokerComponent()
	{
	}
	UClass* Z_Construct_UClass_UVoxelInvokerComponent_NoRegister()
	{
		return UVoxelInvokerComponent::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelInvokerComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DistanceOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DistanceOffset;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelInvokerComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelInvokerComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "VoxelComponents/VoxelInvokerComponent.h" },
		{ "ModuleRelativePath", "Public/VoxelComponents/VoxelInvokerComponent.h" },
		{ "ToolTip", "Component to set the voxels LOD and collisions" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelInvokerComponent_Statics::NewProp_DistanceOffset_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelComponents/VoxelInvokerComponent.h" },
		{ "ToolTip", "In world space. Chunks under this distance will have the highest resolution" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelInvokerComponent_Statics::NewProp_DistanceOffset = { UE4CodeGen_Private::EPropertyClass::Float, "DistanceOffset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UVoxelInvokerComponent, DistanceOffset), METADATA_PARAMS(Z_Construct_UClass_UVoxelInvokerComponent_Statics::NewProp_DistanceOffset_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelInvokerComponent_Statics::NewProp_DistanceOffset_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelInvokerComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelInvokerComponent_Statics::NewProp_DistanceOffset,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelInvokerComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelInvokerComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelInvokerComponent_Statics::ClassParams = {
		&UVoxelInvokerComponent::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelInvokerComponent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelInvokerComponent_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelInvokerComponent_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelInvokerComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelInvokerComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelInvokerComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelInvokerComponent, 122129661);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelInvokerComponent(Z_Construct_UClass_UVoxelInvokerComponent, &UVoxelInvokerComponent::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelInvokerComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelInvokerComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
