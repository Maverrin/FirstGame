// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelImporters/VoxelLandscapeImporter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelLandscapeImporter() {}
// Cross Module References
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelLandscapeImporterRGB();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo();
	LANDSCAPE_API UClass* Z_Construct_UClass_ULandscapeLayerInfoObject_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelLandscapeImporter_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelLandscapeImporter();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelMaterialConfig();
	LANDSCAPE_API UClass* Z_Construct_UClass_ALandscape_NoRegister();
// End Cross Module References
	static UEnum* EVoxelLandscapeImporterRGB_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelLandscapeImporterRGB, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelLandscapeImporterRGB"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelLandscapeImporterRGB(EVoxelLandscapeImporterRGB_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelLandscapeImporterRGB"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelLandscapeImporterRGB_CRC() { return 2156146761U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelLandscapeImporterRGB()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelLandscapeImporterRGB"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelLandscapeImporterRGB_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelLandscapeImporterRGB::R", (int64)EVoxelLandscapeImporterRGB::R },
				{ "EVoxelLandscapeImporterRGB::G", (int64)EVoxelLandscapeImporterRGB::G },
				{ "EVoxelLandscapeImporterRGB::B", (int64)EVoxelLandscapeImporterRGB::B },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/VoxelImporters/VoxelLandscapeImporter.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelLandscapeImporterRGB",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelLandscapeImporterRGB",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FVoxelLandscapeImporterLayerInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelLandscapeImporterLayerInfo"), sizeof(FVoxelLandscapeImporterLayerInfo), Get_Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelLandscapeImporterLayerInfo(FVoxelLandscapeImporterLayerInfo::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelLandscapeImporterLayerInfo"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelLandscapeImporterLayerInfo
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelLandscapeImporterLayerInfo()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelLandscapeImporterLayerInfo")),new UScriptStruct::TCppStructOps<FVoxelLandscapeImporterLayerInfo>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelLandscapeImporterLayerInfo;
	struct Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Index_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Index;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Layer_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Layer;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Layer_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LayerInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LayerInfo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelLandscapeImporter.h" },
		{ "ToolTip", "Hold informations for landscape layers import" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelLandscapeImporterLayerInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_Index_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelLandscapeImporter.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Byte, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelLandscapeImporterLayerInfo, Index), nullptr, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_Index_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_Index_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_Layer_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelLandscapeImporter.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_Layer = { UE4CodeGen_Private::EPropertyClass::Enum, "Layer", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelLandscapeImporterLayerInfo, Layer), Z_Construct_UEnum_Voxel_EVoxelLandscapeImporterRGB, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_Layer_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_Layer_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_Layer_Underlying = { UE4CodeGen_Private::EPropertyClass::Int, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_LayerInfo_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelLandscapeImporter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_LayerInfo = { UE4CodeGen_Private::EPropertyClass::Object, "LayerInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelLandscapeImporterLayerInfo, LayerInfo), Z_Construct_UClass_ULandscapeLayerInfoObject_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_LayerInfo_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_LayerInfo_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_Layer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_Layer_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::NewProp_LayerInfo,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelLandscapeImporterLayerInfo",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelLandscapeImporterLayerInfo),
		alignof(FVoxelLandscapeImporterLayerInfo),
		Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelLandscapeImporterLayerInfo"), sizeof(FVoxelLandscapeImporterLayerInfo), Get_Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo_CRC() { return 1149178166U; }
	void AVoxelLandscapeImporter::StaticRegisterNativesAVoxelLandscapeImporter()
	{
	}
	UClass* Z_Construct_UClass_AVoxelLandscapeImporter_NoRegister()
	{
		return AVoxelLandscapeImporter::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelLandscapeImporter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LayerInfos_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_LayerInfos;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LayerInfos_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialConfig_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_MaterialConfig;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_MaterialConfig_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Landscape_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Landscape;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelLandscapeImporter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscapeImporter_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Tick Replication Input Actor Rendering HOLD LOD Cooking" },
		{ "IncludePath", "VoxelImporters/VoxelLandscapeImporter.h" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelLandscapeImporter.h" },
		{ "ToolTip", "Actor that create a UVoxelLandscapeAsset from an ALandscape" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_LayerInfos_MetaData[] = {
		{ "Category", "Import configuration" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelLandscapeImporter.h" },
		{ "ToolTip", "The layers to import" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_LayerInfos = { UE4CodeGen_Private::EPropertyClass::Array, "LayerInfos", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AVoxelLandscapeImporter, LayerInfos), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_LayerInfos_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_LayerInfos_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_LayerInfos_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "LayerInfos", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelLandscapeImporterLayerInfo, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_MaterialConfig_MetaData[] = {
		{ "Category", "Import configuration" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelLandscapeImporter.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_MaterialConfig = { UE4CodeGen_Private::EPropertyClass::Enum, "MaterialConfig", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AVoxelLandscapeImporter, MaterialConfig), Z_Construct_UEnum_Voxel_EVoxelMaterialConfig, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_MaterialConfig_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_MaterialConfig_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_MaterialConfig_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_Landscape_MetaData[] = {
		{ "Category", "Import configuration" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelLandscapeImporter.h" },
		{ "ToolTip", "The landscape to import" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_Landscape = { UE4CodeGen_Private::EPropertyClass::Object, "Landscape", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AVoxelLandscapeImporter, Landscape), Z_Construct_UClass_ALandscape_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_Landscape_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_Landscape_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelLandscapeImporter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_LayerInfos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_LayerInfos_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_MaterialConfig,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_MaterialConfig_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscapeImporter_Statics::NewProp_Landscape,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelLandscapeImporter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelLandscapeImporter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelLandscapeImporter_Statics::ClassParams = {
		&AVoxelLandscapeImporter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AVoxelLandscapeImporter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscapeImporter_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscapeImporter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscapeImporter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelLandscapeImporter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelLandscapeImporter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelLandscapeImporter, 2449154419);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelLandscapeImporter(Z_Construct_UClass_AVoxelLandscapeImporter, &AVoxelLandscapeImporter::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelLandscapeImporter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelLandscapeImporter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
