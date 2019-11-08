// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/DataAssetEditor/VoxelDataAssetEditorVoxelWorld.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelDataAssetEditorVoxelWorld() {}
// Cross Module References
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelMaterialConfig();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelNormalConfig();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelRenderType();
	VOXELEDITOR_API UClass* Z_Construct_UClass_AVoxelDataAssetEditorVoxelWorld_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_AVoxelDataAssetEditorVoxelWorld();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld();
// End Cross Module References
	void UVoxelDataAssetEditorVoxelWorldSettings::StaticRegisterNativesUVoxelDataAssetEditorVoxelWorldSettings()
	{
	}
	UClass* Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_NoRegister()
	{
		return UVoxelDataAssetEditorVoxelWorldSettings::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialCollectionPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_MaterialCollectionPath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VoxelMaterialPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_VoxelMaterialPath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialConfig_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_MaterialConfig;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_MaterialConfig_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NormalConfig_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_NormalConfig;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_NormalConfig_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RenderType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_RenderType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_RenderType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VoxelSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VoxelSize;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DataAssetEditor/VoxelDataAssetEditorVoxelWorld.h" },
		{ "ModuleRelativePath", "Private/DataAssetEditor/VoxelDataAssetEditorVoxelWorld.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_MaterialCollectionPath_MetaData[] = {
		{ "ModuleRelativePath", "Private/DataAssetEditor/VoxelDataAssetEditorVoxelWorld.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_MaterialCollectionPath = { UE4CodeGen_Private::EPropertyClass::Str, "MaterialCollectionPath", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000004000, 1, nullptr, STRUCT_OFFSET(UVoxelDataAssetEditorVoxelWorldSettings, MaterialCollectionPath), METADATA_PARAMS(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_MaterialCollectionPath_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_MaterialCollectionPath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_VoxelMaterialPath_MetaData[] = {
		{ "ModuleRelativePath", "Private/DataAssetEditor/VoxelDataAssetEditorVoxelWorld.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_VoxelMaterialPath = { UE4CodeGen_Private::EPropertyClass::Str, "VoxelMaterialPath", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000004000, 1, nullptr, STRUCT_OFFSET(UVoxelDataAssetEditorVoxelWorldSettings, VoxelMaterialPath), METADATA_PARAMS(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_VoxelMaterialPath_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_VoxelMaterialPath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_MaterialConfig_MetaData[] = {
		{ "ModuleRelativePath", "Private/DataAssetEditor/VoxelDataAssetEditorVoxelWorld.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_MaterialConfig = { UE4CodeGen_Private::EPropertyClass::Enum, "MaterialConfig", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000004000, 1, nullptr, STRUCT_OFFSET(UVoxelDataAssetEditorVoxelWorldSettings, MaterialConfig), Z_Construct_UEnum_Voxel_EVoxelMaterialConfig, METADATA_PARAMS(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_MaterialConfig_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_MaterialConfig_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_MaterialConfig_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_NormalConfig_MetaData[] = {
		{ "ModuleRelativePath", "Private/DataAssetEditor/VoxelDataAssetEditorVoxelWorld.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_NormalConfig = { UE4CodeGen_Private::EPropertyClass::Enum, "NormalConfig", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000004000, 1, nullptr, STRUCT_OFFSET(UVoxelDataAssetEditorVoxelWorldSettings, NormalConfig), Z_Construct_UEnum_Voxel_EVoxelNormalConfig, METADATA_PARAMS(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_NormalConfig_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_NormalConfig_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_NormalConfig_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_RenderType_MetaData[] = {
		{ "ModuleRelativePath", "Private/DataAssetEditor/VoxelDataAssetEditorVoxelWorld.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_RenderType = { UE4CodeGen_Private::EPropertyClass::Enum, "RenderType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000004000, 1, nullptr, STRUCT_OFFSET(UVoxelDataAssetEditorVoxelWorldSettings, RenderType), Z_Construct_UEnum_Voxel_EVoxelRenderType, METADATA_PARAMS(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_RenderType_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_RenderType_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_RenderType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_VoxelSize_MetaData[] = {
		{ "ModuleRelativePath", "Private/DataAssetEditor/VoxelDataAssetEditorVoxelWorld.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_VoxelSize = { UE4CodeGen_Private::EPropertyClass::Float, "VoxelSize", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000004000, 1, nullptr, STRUCT_OFFSET(UVoxelDataAssetEditorVoxelWorldSettings, VoxelSize), METADATA_PARAMS(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_VoxelSize_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_VoxelSize_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_MaterialCollectionPath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_VoxelMaterialPath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_MaterialConfig,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_MaterialConfig_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_NormalConfig,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_NormalConfig_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_RenderType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_RenderType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::NewProp_VoxelSize,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelDataAssetEditorVoxelWorldSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::ClassParams = {
		&UVoxelDataAssetEditorVoxelWorldSettings::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A4u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::PropPointers),
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelDataAssetEditorVoxelWorldSettings, 1628807398);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelDataAssetEditorVoxelWorldSettings(Z_Construct_UClass_UVoxelDataAssetEditorVoxelWorldSettings, &UVoxelDataAssetEditorVoxelWorldSettings::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelDataAssetEditorVoxelWorldSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelDataAssetEditorVoxelWorldSettings);
	void AVoxelDataAssetEditorVoxelWorld::StaticRegisterNativesAVoxelDataAssetEditorVoxelWorld()
	{
	}
	UClass* Z_Construct_UClass_AVoxelDataAssetEditorVoxelWorld_NoRegister()
	{
		return AVoxelDataAssetEditorVoxelWorld::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelDataAssetEditorVoxelWorld_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelDataAssetEditorVoxelWorld_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AVoxelWorld,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelDataAssetEditorVoxelWorld_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DataAssetEditor/VoxelDataAssetEditorVoxelWorld.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Private/DataAssetEditor/VoxelDataAssetEditorVoxelWorld.h" },
		{ "NotBlueprintType", "true" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelDataAssetEditorVoxelWorld_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelDataAssetEditorVoxelWorld>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelDataAssetEditorVoxelWorld_Statics::ClassParams = {
		&AVoxelDataAssetEditorVoxelWorld::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x048002A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelDataAssetEditorVoxelWorld_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelDataAssetEditorVoxelWorld_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelDataAssetEditorVoxelWorld()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelDataAssetEditorVoxelWorld_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelDataAssetEditorVoxelWorld, 487722371);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelDataAssetEditorVoxelWorld(Z_Construct_UClass_AVoxelDataAssetEditorVoxelWorld, &AVoxelDataAssetEditorVoxelWorld::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("AVoxelDataAssetEditorVoxelWorld"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelDataAssetEditorVoxelWorld);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
