// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelGraph/VoxelGraphWorldGenerator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelGraphWorldGenerator() {}
// Cross Module References
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelGraphGeneratorWorldKind();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelGraphPreviewType();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelGraphPreviewAxes();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphPreviewSettings_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphPreviewSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphGenerator_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelMaterialConfig();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphGenerator();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelWorldGenerator();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraph_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
// End Cross Module References
	static UEnum* EVoxelGraphGeneratorWorldKind_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelGraphGeneratorWorldKind, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelGraphGeneratorWorldKind"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelGraphGeneratorWorldKind(EVoxelGraphGeneratorWorldKind_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelGraphGeneratorWorldKind"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelGraphGeneratorWorldKind_CRC() { return 3806257613U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelGraphGeneratorWorldKind()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelGraphGeneratorWorldKind"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelGraphGeneratorWorldKind_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelGraphGeneratorWorldKind::Flat", (int64)EVoxelGraphGeneratorWorldKind::Flat },
				{ "EVoxelGraphGeneratorWorldKind::Sphere", (int64)EVoxelGraphGeneratorWorldKind::Sphere },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelGraphGeneratorWorldKind",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelGraphGeneratorWorldKind",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EVoxelGraphPreviewType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelGraphPreviewType, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelGraphPreviewType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelGraphPreviewType(EVoxelGraphPreviewType_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelGraphPreviewType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelGraphPreviewType_CRC() { return 15448790U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelGraphPreviewType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelGraphPreviewType"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelGraphPreviewType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelGraphPreviewType::Density", (int64)EVoxelGraphPreviewType::Density },
				{ "EVoxelGraphPreviewType::Material", (int64)EVoxelGraphPreviewType::Material },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelGraphPreviewType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelGraphPreviewType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EVoxelGraphPreviewAxes_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelGraphPreviewAxes, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelGraphPreviewAxes"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelGraphPreviewAxes(EVoxelGraphPreviewAxes_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelGraphPreviewAxes"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelGraphPreviewAxes_CRC() { return 4081900200U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelGraphPreviewAxes()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelGraphPreviewAxes"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelGraphPreviewAxes_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelGraphPreviewAxes::X", (int64)EVoxelGraphPreviewAxes::X },
				{ "EVoxelGraphPreviewAxes::Y", (int64)EVoxelGraphPreviewAxes::Y },
				{ "EVoxelGraphPreviewAxes::Z", (int64)EVoxelGraphPreviewAxes::Z },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelGraphPreviewAxes",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelGraphPreviewAxes",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void UVoxelGraphPreviewSettings::StaticRegisterNativesUVoxelGraphPreviewSettings()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGraphPreviewSettings_NoRegister()
	{
		return UVoxelGraphPreviewSettings::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Graph_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Graph;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShadowDensity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ShadowDensity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Brightness_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Brightness;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LightDirection_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LightDirection;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Height;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshScale_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MeshScale;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Material;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ColorsForIndexMaterialConfig_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ColorsForIndexMaterialConfig;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ColorsForIndexMaterialConfig_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MinValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VoxelsPerPixel_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_VoxelsPerPixel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ImageResolution_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ImageResolution;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Center_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Center;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BottomToTop_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_BottomToTop;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_BottomToTop_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LeftToRight_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_LeftToRight;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_LeftToRight_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEnableWater_MetaData[];
#endif
		static void NewProp_bEnableWater_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEnableWater;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseDensityAsColor_MetaData[];
#endif
		static void NewProp_bUseDensityAsColor_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseDensityAsColor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ImagePreviewType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ImagePreviewType;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ImagePreviewType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialConfig_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_MaterialConfig;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_MaterialConfig_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelGraph/VoxelGraphWorldGenerator.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Graph_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Graph = { UE4CodeGen_Private::EPropertyClass::Object, "Graph", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, Graph), Z_Construct_UClass_UVoxelGraphGenerator_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Graph_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Graph_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ShadowDensity_MetaData[] = {
		{ "Category", "3D Preview Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
		{ "NoRebuild", "" },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ShadowDensity = { UE4CodeGen_Private::EPropertyClass::Float, "ShadowDensity", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, ShadowDensity), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ShadowDensity_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ShadowDensity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Brightness_MetaData[] = {
		{ "Category", "3D Preview Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
		{ "NoRebuild", "" },
		{ "UIMax", "1" },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Brightness = { UE4CodeGen_Private::EPropertyClass::Float, "Brightness", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, Brightness), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Brightness_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Brightness_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_LightDirection_MetaData[] = {
		{ "Category", "3D Preview Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
		{ "NoRebuild", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_LightDirection = { UE4CodeGen_Private::EPropertyClass::Struct, "LightDirection", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, LightDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_LightDirection_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_LightDirection_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Height_MetaData[] = {
		{ "Category", "3D Preview Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
		{ "NoRebuild", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Height = { UE4CodeGen_Private::EPropertyClass::Float, "Height", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, Height), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Height_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Height_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MeshScale_MetaData[] = {
		{ "Category", "3D Preview Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
		{ "NoRebuild", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MeshScale = { UE4CodeGen_Private::EPropertyClass::Struct, "MeshScale", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, MeshScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MeshScale_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MeshScale_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Material_MetaData[] = {
		{ "Category", "3D Preview Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
		{ "NoRebuild", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Object, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, Material), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Material_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Material_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "3D Preview Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
		{ "NoRebuild", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Mesh = { UE4CodeGen_Private::EPropertyClass::Object, "Mesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, Mesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Mesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Mesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ColorsForIndexMaterialConfig_MetaData[] = {
		{ "Category", "Material Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ColorsForIndexMaterialConfig = { UE4CodeGen_Private::EPropertyClass::Array, "ColorsForIndexMaterialConfig", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, ColorsForIndexMaterialConfig), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ColorsForIndexMaterialConfig_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ColorsForIndexMaterialConfig_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ColorsForIndexMaterialConfig_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ColorsForIndexMaterialConfig", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MaxValue_MetaData[] = {
		{ "Category", "Density Settings" },
		{ "DisplayName", "Max Value (white)" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MaxValue = { UE4CodeGen_Private::EPropertyClass::Float, "MaxValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, MaxValue), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MaxValue_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MaxValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MinValue_MetaData[] = {
		{ "Category", "Density Settings" },
		{ "DisplayName", "Min Value (black)" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MinValue = { UE4CodeGen_Private::EPropertyClass::Float, "MinValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, MinValue), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MinValue_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MinValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_VoxelsPerPixel_MetaData[] = {
		{ "Category", "Preview Settings" },
		{ "DisplayName", "Voxels Per Pixel (pow of 2)" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
		{ "ToolTip", "Voxels Per Pixel (pow of 2)" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_VoxelsPerPixel = { UE4CodeGen_Private::EPropertyClass::Int, "VoxelsPerPixel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, VoxelsPerPixel), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_VoxelsPerPixel_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_VoxelsPerPixel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ImageResolution_MetaData[] = {
		{ "Category", "Preview Settings" },
		{ "DisplayName", "Image Resolution (pow of 2)" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
		{ "ToolTip", "Image Resolution (pow of 2)" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ImageResolution = { UE4CodeGen_Private::EPropertyClass::Int, "ImageResolution", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, ImageResolution), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ImageResolution_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ImageResolution_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Center_MetaData[] = {
		{ "Category", "Preview Settings" },
		{ "DisplayName", "Center (multiple of Voxels Per Pixel)" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
		{ "ToolTip", "Center (multiple of Voxels Per Pixel)" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Center = { UE4CodeGen_Private::EPropertyClass::Struct, "Center", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, Center), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Center_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Center_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_BottomToTop_MetaData[] = {
		{ "Category", "Preview Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_BottomToTop = { UE4CodeGen_Private::EPropertyClass::Enum, "BottomToTop", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, BottomToTop), Z_Construct_UEnum_Voxel_EVoxelGraphPreviewAxes, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_BottomToTop_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_BottomToTop_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_BottomToTop_Underlying = { UE4CodeGen_Private::EPropertyClass::Int, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_LeftToRight_MetaData[] = {
		{ "Category", "Preview Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_LeftToRight = { UE4CodeGen_Private::EPropertyClass::Enum, "LeftToRight", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, LeftToRight), Z_Construct_UEnum_Voxel_EVoxelGraphPreviewAxes, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_LeftToRight_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_LeftToRight_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_LeftToRight_Underlying = { UE4CodeGen_Private::EPropertyClass::Int, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bEnableWater_MetaData[] = {
		{ "Category", "Preview Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bEnableWater_SetBit(void* Obj)
	{
		((UVoxelGraphPreviewSettings*)Obj)->bEnableWater = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bEnableWater = { UE4CodeGen_Private::EPropertyClass::Bool, "bEnableWater", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelGraphPreviewSettings), &Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bEnableWater_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bEnableWater_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bEnableWater_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bUseDensityAsColor_MetaData[] = {
		{ "Category", "Preview Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bUseDensityAsColor_SetBit(void* Obj)
	{
		((UVoxelGraphPreviewSettings*)Obj)->bUseDensityAsColor = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bUseDensityAsColor = { UE4CodeGen_Private::EPropertyClass::Bool, "bUseDensityAsColor", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelGraphPreviewSettings), &Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bUseDensityAsColor_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bUseDensityAsColor_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bUseDensityAsColor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ImagePreviewType_MetaData[] = {
		{ "Category", "Preview Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ImagePreviewType = { UE4CodeGen_Private::EPropertyClass::Enum, "ImagePreviewType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, ImagePreviewType), Z_Construct_UEnum_Voxel_EVoxelGraphPreviewType, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ImagePreviewType_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ImagePreviewType_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ImagePreviewType_Underlying = { UE4CodeGen_Private::EPropertyClass::Int, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MaterialConfig_MetaData[] = {
		{ "Category", "Preview Settings" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MaterialConfig = { UE4CodeGen_Private::EPropertyClass::Enum, "MaterialConfig", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphPreviewSettings, MaterialConfig), Z_Construct_UEnum_Voxel_EVoxelMaterialConfig, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MaterialConfig_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MaterialConfig_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MaterialConfig_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Graph,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ShadowDensity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Brightness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_LightDirection,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Height,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MeshScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Material,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Mesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ColorsForIndexMaterialConfig,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ColorsForIndexMaterialConfig_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MaxValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MinValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_VoxelsPerPixel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ImageResolution,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_Center,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_BottomToTop,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_BottomToTop_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_LeftToRight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_LeftToRight_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bEnableWater,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_bUseDensityAsColor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ImagePreviewType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_ImagePreviewType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MaterialConfig,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::NewProp_MaterialConfig_Underlying,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGraphPreviewSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::ClassParams = {
		&UVoxelGraphPreviewSettings::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGraphPreviewSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGraphPreviewSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGraphPreviewSettings, 3568992284);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGraphPreviewSettings(Z_Construct_UClass_UVoxelGraphPreviewSettings, &UVoxelGraphPreviewSettings::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelGraphPreviewSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGraphPreviewSettings);
	void UVoxelGraphGenerator::StaticRegisterNativesUVoxelGraphGenerator()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGraphGenerator_NoRegister()
	{
		return UVoxelGraphGenerator::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGraphGenerator_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PreviewTexture_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PreviewTexture;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PreviewTextureSave_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_PreviewTextureSave;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PreviewTextureSave_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DebugNodes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_DebugNodes;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DebugNodes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VoxelDebugGraph_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VoxelDebugGraph;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VoxelGraph_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VoxelGraph;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PreviewSettings_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PreviewSettings;
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FirstNodePindId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FirstNodePindId;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FirstNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FirstNode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AllNodes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_AllNodes;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AllNodes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHideNonExecNodes_MetaData[];
#endif
		static void NewProp_bHideNonExecNodes_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHideNonExecNodes;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StepY_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StepY;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StepX_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StepX;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEnableDebug_MetaData[];
#endif
		static void NewProp_bEnableDebug_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEnableDebug;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDependenciesAnalysis_MetaData[];
#endif
		static void NewProp_bDependenciesAnalysis_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDependenciesAnalysis;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCompactPassthroughs_MetaData[];
#endif
		static void NewProp_bCompactPassthroughs_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCompactPassthroughs;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bReplaceFlowMerges_MetaData[];
#endif
		static void NewProp_bReplaceFlowMerges_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bReplaceFlowMerges;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bInlineMacros_MetaData[];
#endif
		static void NewProp_bInlineMacros_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInlineMacros;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEnableStats_MetaData[];
#endif
		static void NewProp_bEnableStats_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEnableStats;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowAxisDependencies_MetaData[];
#endif
		static void NewProp_bShowAxisDependencies_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowAxisDependencies;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldKind_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_WorldKind;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_WorldKind_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGraphGenerator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelWorldGenerator,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelGraphWorldGenerator.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
		{ "ToolTip", "A graph world generator" },
	};
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewTexture_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewTexture = { UE4CodeGen_Private::EPropertyClass::Object, "PreviewTexture", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000800002000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphGenerator, PreviewTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewTexture_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewTexture_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewTextureSave_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewTextureSave = { UE4CodeGen_Private::EPropertyClass::Array, "PreviewTextureSave", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000800000000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphGenerator, PreviewTextureSave), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewTextureSave_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewTextureSave_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewTextureSave_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "PreviewTextureSave", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000800000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_DebugNodes_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_DebugNodes = { UE4CodeGen_Private::EPropertyClass::Array, "DebugNodes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000800000000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphGenerator, DebugNodes), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_DebugNodes_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_DebugNodes_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_DebugNodes_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "DebugNodes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000800000000, 1, nullptr, 0, Z_Construct_UClass_UVoxelNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_VoxelDebugGraph_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_VoxelDebugGraph = { UE4CodeGen_Private::EPropertyClass::Object, "VoxelDebugGraph", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000800000000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphGenerator, VoxelDebugGraph), Z_Construct_UClass_UEdGraph_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_VoxelDebugGraph_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_VoxelDebugGraph_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_VoxelGraph_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_VoxelGraph = { UE4CodeGen_Private::EPropertyClass::Object, "VoxelGraph", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000800000000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphGenerator, VoxelGraph), Z_Construct_UClass_UEdGraph_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_VoxelGraph_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_VoxelGraph_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewSettings_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewSettings = { UE4CodeGen_Private::EPropertyClass::Object, "PreviewSettings", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000800000000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphGenerator, PreviewSettings), Z_Construct_UClass_UVoxelGraphPreviewSettings_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewSettings_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewSettings_MetaData)) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_FirstNodePindId_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_FirstNodePindId = { UE4CodeGen_Private::EPropertyClass::Struct, "FirstNodePindId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphGenerator, FirstNodePindId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_FirstNodePindId_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_FirstNodePindId_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_FirstNode_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_FirstNode = { UE4CodeGen_Private::EPropertyClass::Object, "FirstNode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphGenerator, FirstNode), Z_Construct_UClass_UVoxelNode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_FirstNode_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_FirstNode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_AllNodes_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_AllNodes = { UE4CodeGen_Private::EPropertyClass::Array, "AllNodes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphGenerator, AllNodes), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_AllNodes_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_AllNodes_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_AllNodes_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "AllNodes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UVoxelNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bHideNonExecNodes_MetaData[] = {
		{ "Category", "Debug" },
		{ "EditCondition", "bEnableDebug" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bHideNonExecNodes_SetBit(void* Obj)
	{
		((UVoxelGraphGenerator*)Obj)->bHideNonExecNodes = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bHideNonExecNodes = { UE4CodeGen_Private::EPropertyClass::Bool, "bHideNonExecNodes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelGraphGenerator), &Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bHideNonExecNodes_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bHideNonExecNodes_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bHideNonExecNodes_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_StepY_MetaData[] = {
		{ "Category", "Debug" },
		{ "EditCondition", "bEnableDebug" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_StepY = { UE4CodeGen_Private::EPropertyClass::Float, "StepY", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphGenerator, StepY), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_StepY_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_StepY_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_StepX_MetaData[] = {
		{ "Category", "Debug" },
		{ "EditCondition", "bEnableDebug" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_StepX = { UE4CodeGen_Private::EPropertyClass::Float, "StepX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphGenerator, StepX), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_StepX_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_StepX_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableDebug_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableDebug_SetBit(void* Obj)
	{
		((UVoxelGraphGenerator*)Obj)->bEnableDebug = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableDebug = { UE4CodeGen_Private::EPropertyClass::Bool, "bEnableDebug", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelGraphGenerator), &Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableDebug_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableDebug_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableDebug_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bDependenciesAnalysis_MetaData[] = {
		{ "Category", "Compile options" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bDependenciesAnalysis_SetBit(void* Obj)
	{
		((UVoxelGraphGenerator*)Obj)->bDependenciesAnalysis = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bDependenciesAnalysis = { UE4CodeGen_Private::EPropertyClass::Bool, "bDependenciesAnalysis", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelGraphGenerator), &Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bDependenciesAnalysis_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bDependenciesAnalysis_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bDependenciesAnalysis_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bCompactPassthroughs_MetaData[] = {
		{ "Category", "Compile options" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bCompactPassthroughs_SetBit(void* Obj)
	{
		((UVoxelGraphGenerator*)Obj)->bCompactPassthroughs = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bCompactPassthroughs = { UE4CodeGen_Private::EPropertyClass::Bool, "bCompactPassthroughs", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelGraphGenerator), &Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bCompactPassthroughs_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bCompactPassthroughs_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bCompactPassthroughs_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bReplaceFlowMerges_MetaData[] = {
		{ "Category", "Compile options" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bReplaceFlowMerges_SetBit(void* Obj)
	{
		((UVoxelGraphGenerator*)Obj)->bReplaceFlowMerges = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bReplaceFlowMerges = { UE4CodeGen_Private::EPropertyClass::Bool, "bReplaceFlowMerges", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelGraphGenerator), &Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bReplaceFlowMerges_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bReplaceFlowMerges_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bReplaceFlowMerges_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bInlineMacros_MetaData[] = {
		{ "Category", "Compile options" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bInlineMacros_SetBit(void* Obj)
	{
		((UVoxelGraphGenerator*)Obj)->bInlineMacros = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bInlineMacros = { UE4CodeGen_Private::EPropertyClass::Bool, "bInlineMacros", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelGraphGenerator), &Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bInlineMacros_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bInlineMacros_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bInlineMacros_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableStats_MetaData[] = {
		{ "Category", "Feedback" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableStats_SetBit(void* Obj)
	{
		((UVoxelGraphGenerator*)Obj)->bEnableStats = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableStats = { UE4CodeGen_Private::EPropertyClass::Bool, "bEnableStats", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelGraphGenerator), &Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableStats_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableStats_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableStats_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bShowAxisDependencies_MetaData[] = {
		{ "Category", "Feedback" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bShowAxisDependencies_SetBit(void* Obj)
	{
		((UVoxelGraphGenerator*)Obj)->bShowAxisDependencies = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bShowAxisDependencies = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowAxisDependencies", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelGraphGenerator), &Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bShowAxisDependencies_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bShowAxisDependencies_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bShowAxisDependencies_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_WorldKind_MetaData[] = {
		{ "Category", "Generator settings" },
		{ "DisplayName", "World Kind (for grass & actors min/max angle)" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphWorldGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_WorldKind = { UE4CodeGen_Private::EPropertyClass::Enum, "WorldKind", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphGenerator, WorldKind), Z_Construct_UEnum_Voxel_EVoxelGraphGeneratorWorldKind, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_WorldKind_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_WorldKind_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_WorldKind_Underlying = { UE4CodeGen_Private::EPropertyClass::Int, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelGraphGenerator_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewTexture,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewTextureSave,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewTextureSave_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_DebugNodes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_DebugNodes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_VoxelDebugGraph,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_VoxelGraph,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_PreviewSettings,
#endif // WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_FirstNodePindId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_FirstNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_AllNodes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_AllNodes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bHideNonExecNodes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_StepY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_StepX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableDebug,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bDependenciesAnalysis,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bCompactPassthroughs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bReplaceFlowMerges,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bInlineMacros,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bEnableStats,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_bShowAxisDependencies,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_WorldKind,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphGenerator_Statics::NewProp_WorldKind_Underlying,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGraphGenerator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGraphGenerator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGraphGenerator_Statics::ClassParams = {
		&UVoxelGraphGenerator::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x041000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelGraphGenerator_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphGenerator_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphGenerator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGraphGenerator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGraphGenerator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGraphGenerator, 1343646740);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGraphGenerator(Z_Construct_UClass_UVoxelGraphGenerator, &UVoxelGraphGenerator::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelGraphGenerator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGraphGenerator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
