// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelComponents/VoxelAutoDisableComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelAutoDisableComponent() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelAutoDisableComponent_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelAutoDisableComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
// End Cross Module References
	void UVoxelAutoDisableComponent::StaticRegisterNativesUVoxelAutoDisableComponent()
	{
	}
	UClass* Z_Construct_UClass_UVoxelAutoDisableComponent_NoRegister()
	{
		return UVoxelAutoDisableComponent::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelAutoDisableComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimeToWaitBeforeActivating_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TimeToWaitBeforeActivating;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxLODForPhysics_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_MaxLODForPhysics;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultWorld_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DefaultWorld;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAutoFindWorld_MetaData[];
#endif
		static void NewProp_bAutoFindWorld_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAutoFindWorld;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "VoxelComponents/VoxelAutoDisableComponent.h" },
		{ "ModuleRelativePath", "Public/VoxelComponents/VoxelAutoDisableComponent.h" },
		{ "ToolTip", "Disable physics on actors that are out of the Voxel World collision range" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_TimeToWaitBeforeActivating_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelComponents/VoxelAutoDisableComponent.h" },
		{ "ToolTip", "Delay to allow physics cooking" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_TimeToWaitBeforeActivating = { UE4CodeGen_Private::EPropertyClass::Float, "TimeToWaitBeforeActivating", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UVoxelAutoDisableComponent, TimeToWaitBeforeActivating), METADATA_PARAMS(Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_TimeToWaitBeforeActivating_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_TimeToWaitBeforeActivating_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_MaxLODForPhysics_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "Category", "Voxel" },
		{ "ClampMax", "25" },
		{ "ClampMin", "0" },
		{ "DisplayName", "Max LOD For Collisions" },
		{ "ModuleRelativePath", "Public/VoxelComponents/VoxelAutoDisableComponent.h" },
		{ "ToolTip", "Inclusive" },
		{ "UIMax", "25" },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_MaxLODForPhysics = { UE4CodeGen_Private::EPropertyClass::Byte, "MaxLODForPhysics", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UVoxelAutoDisableComponent, MaxLODForPhysics), nullptr, METADATA_PARAMS(Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_MaxLODForPhysics_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_MaxLODForPhysics_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_DefaultWorld_MetaData[] = {
		{ "Category", "Voxel" },
		{ "DisplayName", "World" },
		{ "EditCondition", "!bAutoFindWorld" },
		{ "ModuleRelativePath", "Public/VoxelComponents/VoxelAutoDisableComponent.h" },
		{ "ToolTip", "Set automatically if bAutoFindWorld" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_DefaultWorld = { UE4CodeGen_Private::EPropertyClass::Object, "DefaultWorld", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UVoxelAutoDisableComponent, DefaultWorld), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_DefaultWorld_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_DefaultWorld_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_bAutoFindWorld_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelComponents/VoxelAutoDisableComponent.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_bAutoFindWorld_SetBit(void* Obj)
	{
		((UVoxelAutoDisableComponent*)Obj)->bAutoFindWorld = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_bAutoFindWorld = { UE4CodeGen_Private::EPropertyClass::Bool, "bAutoFindWorld", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelAutoDisableComponent), &Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_bAutoFindWorld_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_bAutoFindWorld_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_bAutoFindWorld_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_TimeToWaitBeforeActivating,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_MaxLODForPhysics,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_DefaultWorld,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::NewProp_bAutoFindWorld,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelAutoDisableComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::ClassParams = {
		&UVoxelAutoDisableComponent::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelAutoDisableComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelAutoDisableComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelAutoDisableComponent, 920075646);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelAutoDisableComponent(Z_Construct_UClass_UVoxelAutoDisableComponent, &UVoxelAutoDisableComponent::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelAutoDisableComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelAutoDisableComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
