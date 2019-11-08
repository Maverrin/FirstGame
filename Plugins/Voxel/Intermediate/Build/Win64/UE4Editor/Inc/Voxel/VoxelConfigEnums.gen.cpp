// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelConfigEnums.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelConfigEnums() {}
// Cross Module References
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelUVConfig();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelMaterialConfig();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelNormalConfig();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelRenderType();
// End Cross Module References
	static UEnum* EVoxelUVConfig_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelUVConfig, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelUVConfig"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelUVConfig(EVoxelUVConfig_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelUVConfig"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelUVConfig_CRC() { return 2892080526U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelUVConfig()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelUVConfig"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelUVConfig_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelUVConfig::GlobalUVs", (int64)EVoxelUVConfig::GlobalUVs },
				{ "EVoxelUVConfig::UseRGAsUVs", (int64)EVoxelUVConfig::UseRGAsUVs },
				{ "EVoxelUVConfig::PackWorldUpInUVs", (int64)EVoxelUVConfig::PackWorldUpInUVs },
				{ "EVoxelUVConfig::PerVoxelUVs", (int64)EVoxelUVConfig::PerVoxelUVs },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/VoxelConfigEnums.h" },
				{ "PackWorldUpInUVs.DisplayName", "Pack WorldUp in UVs" },
				{ "PerVoxelUVs.DisplayName", "Per Voxel UVs (Cubic only)" },
				{ "UseRGAsUVs.DisplayName", "Use Red and Green as UVs" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelUVConfig",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelUVConfig",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EVoxelMaterialConfig_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelMaterialConfig, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelMaterialConfig"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelMaterialConfig(EVoxelMaterialConfig_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelMaterialConfig"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelMaterialConfig_CRC() { return 3564680837U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelMaterialConfig()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelMaterialConfig"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelMaterialConfig_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelMaterialConfig::RGB", (int64)EVoxelMaterialConfig::RGB },
				{ "EVoxelMaterialConfig::IndexWithMultipleMaterials", (int64)EVoxelMaterialConfig::IndexWithMultipleMaterials },
				{ "EVoxelMaterialConfig::DoubleIndexWithMultipleMaterials", (int64)EVoxelMaterialConfig::DoubleIndexWithMultipleMaterials },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/VoxelConfigEnums.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelMaterialConfig",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelMaterialConfig",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EVoxelNormalConfig_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelNormalConfig, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelNormalConfig"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelNormalConfig(EVoxelNormalConfig_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelNormalConfig"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelNormalConfig_CRC() { return 960573652U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelNormalConfig()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelNormalConfig"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelNormalConfig_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelNormalConfig::NoNormal", (int64)EVoxelNormalConfig::NoNormal },
				{ "EVoxelNormalConfig::GradientNormal", (int64)EVoxelNormalConfig::GradientNormal },
				{ "EVoxelNormalConfig::MeshNormal", (int64)EVoxelNormalConfig::MeshNormal },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/VoxelConfigEnums.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelNormalConfig",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelNormalConfig",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EVoxelRenderType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelRenderType, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelRenderType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelRenderType(EVoxelRenderType_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelRenderType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelRenderType_CRC() { return 1800222781U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelRenderType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelRenderType"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelRenderType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelRenderType::MarchingCubes", (int64)EVoxelRenderType::MarchingCubes },
				{ "EVoxelRenderType::Cubic", (int64)EVoxelRenderType::Cubic },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/VoxelConfigEnums.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelRenderType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelRenderType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
