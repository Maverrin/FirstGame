// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelWorldGeneratorPicker.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelWorldGeneratorPicker() {}
// Cross Module References
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelWorldGeneratorPickerType();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelWorldGenerator_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
// End Cross Module References
	static UEnum* EVoxelWorldGeneratorPickerType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelWorldGeneratorPickerType, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelWorldGeneratorPickerType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelWorldGeneratorPickerType(EVoxelWorldGeneratorPickerType_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelWorldGeneratorPickerType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelWorldGeneratorPickerType_CRC() { return 1509861514U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelWorldGeneratorPickerType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelWorldGeneratorPickerType"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelWorldGeneratorPickerType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelWorldGeneratorPickerType::Class", (int64)EVoxelWorldGeneratorPickerType::Class },
				{ "EVoxelWorldGeneratorPickerType::Object", (int64)EVoxelWorldGeneratorPickerType::Object },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/VoxelWorldGeneratorPicker.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelWorldGeneratorPickerType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelWorldGeneratorPickerType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FVoxelWorldGeneratorPicker::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelWorldGeneratorPicker"), sizeof(FVoxelWorldGeneratorPicker), Get_Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelWorldGeneratorPicker(FVoxelWorldGeneratorPicker::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelWorldGeneratorPicker"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelWorldGeneratorPicker
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelWorldGeneratorPicker()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelWorldGeneratorPicker")),new UScriptStruct::TCppStructOps<FVoxelWorldGeneratorPicker>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelWorldGeneratorPicker;
	struct Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldGeneratorObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldGeneratorObject;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldGeneratorClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_WorldGeneratorClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Type;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VoxelWorldGeneratorPicker.h" },
		{ "ToolTip", "Used to select a world generator" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelWorldGeneratorPicker>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_WorldGeneratorObject_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelWorldGeneratorPicker.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_WorldGeneratorObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldGeneratorObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelWorldGeneratorPicker, WorldGeneratorObject), Z_Construct_UClass_UVoxelWorldGenerator_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_WorldGeneratorObject_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_WorldGeneratorObject_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_WorldGeneratorClass_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelWorldGeneratorPicker.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_WorldGeneratorClass = { UE4CodeGen_Private::EPropertyClass::Class, "WorldGeneratorClass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0014000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelWorldGeneratorPicker, WorldGeneratorClass), Z_Construct_UClass_UVoxelWorldGenerator_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_WorldGeneratorClass_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_WorldGeneratorClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_Type_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelWorldGeneratorPicker.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_Type = { UE4CodeGen_Private::EPropertyClass::Enum, "Type", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelWorldGeneratorPicker, Type), Z_Construct_UEnum_Voxel_EVoxelWorldGeneratorPickerType, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_Type_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_Type_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_Type_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_WorldGeneratorObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_WorldGeneratorClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_Type,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::NewProp_Type_Underlying,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelWorldGeneratorPicker",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelWorldGeneratorPicker),
		alignof(FVoxelWorldGeneratorPicker),
		Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelWorldGeneratorPicker"), sizeof(FVoxelWorldGeneratorPicker), Get_Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelWorldGeneratorPicker_CRC() { return 1900826096U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
