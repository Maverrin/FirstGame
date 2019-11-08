// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelPaintMaterial.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelPaintMaterial() {}
// Cross Module References
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelPaintMaterialType();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelPaintMaterial();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
// End Cross Module References
	static UEnum* EVoxelPaintMaterialType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelPaintMaterialType, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelPaintMaterialType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelPaintMaterialType(EVoxelPaintMaterialType_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelPaintMaterialType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelPaintMaterialType_CRC() { return 4015259952U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelPaintMaterialType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelPaintMaterialType"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelPaintMaterialType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelPaintMaterialType::RGB", (int64)EVoxelPaintMaterialType::RGB },
				{ "EVoxelPaintMaterialType::Index", (int64)EVoxelPaintMaterialType::Index },
				{ "EVoxelPaintMaterialType::Grass", (int64)EVoxelPaintMaterialType::Grass },
				{ "EVoxelPaintMaterialType::Actor", (int64)EVoxelPaintMaterialType::Actor },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/VoxelPaintMaterial.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelPaintMaterialType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelPaintMaterialType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FVoxelPaintMaterial::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelPaintMaterial_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelPaintMaterial, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelPaintMaterial"), sizeof(FVoxelPaintMaterial), Get_Z_Construct_UScriptStruct_FVoxelPaintMaterial_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelPaintMaterial(FVoxelPaintMaterial::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelPaintMaterial"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelPaintMaterial
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelPaintMaterial()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelPaintMaterial")),new UScriptStruct::TCppStructOps<FVoxelPaintMaterial>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelPaintMaterial;
	struct Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Amount_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Amount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Type;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Type_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VoxelPaintMaterial.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelPaintMaterial>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Index_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelPaintMaterial.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Byte, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FVoxelPaintMaterial, Index), nullptr, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Index_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Index_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Amount_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelPaintMaterial.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Amount = { UE4CodeGen_Private::EPropertyClass::Float, "Amount", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FVoxelPaintMaterial, Amount), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Amount_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Amount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Color_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelPaintMaterial.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Color = { UE4CodeGen_Private::EPropertyClass::Struct, "Color", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FVoxelPaintMaterial, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Color_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Color_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelPaintMaterial.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Type = { UE4CodeGen_Private::EPropertyClass::Enum, "Type", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FVoxelPaintMaterial, Type), Z_Construct_UEnum_Voxel_EVoxelPaintMaterialType, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Type_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Type_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Type_Underlying = { UE4CodeGen_Private::EPropertyClass::Int, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Amount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Color,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Type,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::NewProp_Type_Underlying,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelPaintMaterial",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelPaintMaterial),
		alignof(FVoxelPaintMaterial),
		Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelPaintMaterial()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelPaintMaterial_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelPaintMaterial"), sizeof(FVoxelPaintMaterial), Get_Z_Construct_UScriptStruct_FVoxelPaintMaterial_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelPaintMaterial_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelPaintMaterial_CRC() { return 3850877190U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
