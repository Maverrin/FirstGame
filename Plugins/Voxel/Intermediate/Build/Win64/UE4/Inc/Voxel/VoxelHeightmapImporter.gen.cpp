// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelImporters/VoxelHeightmapImporter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelHeightmapImporter() {}
// Cross Module References
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelHeightmapImporterRGB();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FFilePath();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelHeightmapImporter_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelHeightmapImporter();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelMaterialConfig();
// End Cross Module References
	static UEnum* EVoxelHeightmapImporterRGB_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelHeightmapImporterRGB, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelHeightmapImporterRGB"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelHeightmapImporterRGB(EVoxelHeightmapImporterRGB_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelHeightmapImporterRGB"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelHeightmapImporterRGB_CRC() { return 3495343602U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelHeightmapImporterRGB()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelHeightmapImporterRGB"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelHeightmapImporterRGB_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelHeightmapImporterRGB::R", (int64)EVoxelHeightmapImporterRGB::R },
				{ "EVoxelHeightmapImporterRGB::G", (int64)EVoxelHeightmapImporterRGB::G },
				{ "EVoxelHeightmapImporterRGB::B", (int64)EVoxelHeightmapImporterRGB::B },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/VoxelImporters/VoxelHeightmapImporter.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelHeightmapImporterRGB",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelHeightmapImporterRGB",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FVoxelHeightmapImporterWeightmapInfos::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelHeightmapImporterWeightmapInfos"), sizeof(FVoxelHeightmapImporterWeightmapInfos), Get_Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos(FVoxelHeightmapImporterWeightmapInfos::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelHeightmapImporterWeightmapInfos"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelHeightmapImporterWeightmapInfos
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelHeightmapImporterWeightmapInfos()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelHeightmapImporterWeightmapInfos")),new UScriptStruct::TCppStructOps<FVoxelHeightmapImporterWeightmapInfos>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelHeightmapImporterWeightmapInfos;
	struct Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_File_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_File;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelHeightmapImporter.h" },
		{ "ToolTip", "Hold informations for a weightmap import" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelHeightmapImporterWeightmapInfos>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_Index_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelHeightmapImporter.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Byte, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelHeightmapImporterWeightmapInfos, Index), nullptr, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_Index_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_Index_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_Layer_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelHeightmapImporter.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_Layer = { UE4CodeGen_Private::EPropertyClass::Enum, "Layer", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelHeightmapImporterWeightmapInfos, Layer), Z_Construct_UEnum_Voxel_EVoxelHeightmapImporterRGB, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_Layer_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_Layer_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_Layer_Underlying = { UE4CodeGen_Private::EPropertyClass::Int, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_File_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelHeightmapImporter.h" },
		{ "ToolTip", "The weightmap" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_File = { UE4CodeGen_Private::EPropertyClass::Struct, "File", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelHeightmapImporterWeightmapInfos, File), Z_Construct_UScriptStruct_FFilePath, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_File_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_File_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_Layer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_Layer_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::NewProp_File,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelHeightmapImporterWeightmapInfos",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelHeightmapImporterWeightmapInfos),
		alignof(FVoxelHeightmapImporterWeightmapInfos),
		Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelHeightmapImporterWeightmapInfos"), sizeof(FVoxelHeightmapImporterWeightmapInfos), Get_Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos_CRC() { return 2142574561U; }
	void AVoxelHeightmapImporter::StaticRegisterNativesAVoxelHeightmapImporter()
	{
	}
	UClass* Z_Construct_UClass_AVoxelHeightmapImporter_NoRegister()
	{
		return AVoxelHeightmapImporter::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelHeightmapImporter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Weightmaps_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Weightmaps;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Weightmaps_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialConfig_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_MaterialConfig;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_MaterialConfig_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Heightmap_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Heightmap;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelHeightmapImporter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelHeightmapImporter_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Tick Replication Input Actor Rendering HOLD LOD Cooking" },
		{ "IncludePath", "VoxelImporters/VoxelHeightmapImporter.h" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelHeightmapImporter.h" },
		{ "ToolTip", "Actor that create a UVoxelLandscapeAsset from an heightmap and its weightmaps" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_Weightmaps_MetaData[] = {
		{ "Category", "Import configuration" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelHeightmapImporter.h" },
		{ "ToolTip", "The weightmaps" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_Weightmaps = { UE4CodeGen_Private::EPropertyClass::Array, "Weightmaps", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AVoxelHeightmapImporter, Weightmaps), METADATA_PARAMS(Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_Weightmaps_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_Weightmaps_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_Weightmaps_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Weightmaps", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelHeightmapImporterWeightmapInfos, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_MaterialConfig_MetaData[] = {
		{ "Category", "Import configuration" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelHeightmapImporter.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_MaterialConfig = { UE4CodeGen_Private::EPropertyClass::Enum, "MaterialConfig", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AVoxelHeightmapImporter, MaterialConfig), Z_Construct_UEnum_Voxel_EVoxelMaterialConfig, METADATA_PARAMS(Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_MaterialConfig_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_MaterialConfig_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_MaterialConfig_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_Heightmap_MetaData[] = {
		{ "Category", "Import configuration" },
		{ "ModuleRelativePath", "Public/VoxelImporters/VoxelHeightmapImporter.h" },
		{ "ToolTip", "The path of the heightmap" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_Heightmap = { UE4CodeGen_Private::EPropertyClass::Struct, "Heightmap", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AVoxelHeightmapImporter, Heightmap), Z_Construct_UScriptStruct_FFilePath, METADATA_PARAMS(Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_Heightmap_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_Heightmap_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelHeightmapImporter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_Weightmaps,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_Weightmaps_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_MaterialConfig,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_MaterialConfig_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelHeightmapImporter_Statics::NewProp_Heightmap,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelHeightmapImporter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelHeightmapImporter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelHeightmapImporter_Statics::ClassParams = {
		&AVoxelHeightmapImporter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AVoxelHeightmapImporter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelHeightmapImporter_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelHeightmapImporter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelHeightmapImporter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelHeightmapImporter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelHeightmapImporter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelHeightmapImporter, 1969372317);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelHeightmapImporter(Z_Construct_UClass_AVoxelHeightmapImporter, &AVoxelHeightmapImporter::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelHeightmapImporter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelHeightmapImporter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
