// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelTools/VoxelProjectionTools.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelProjectionTools() {}
// Cross Module References
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EFailReason();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EBlueprintSuccess();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterial();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FModifiedVoxelMaterial();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FModifiedVoxelValue();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelProjectionTools_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelProjectionTools();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FLatentActionInfo();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelPaintMaterial();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew();
// End Cross Module References
	static UEnum* EFailReason_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EFailReason, Z_Construct_UPackage__Script_Voxel(), TEXT("EFailReason"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EFailReason(EFailReason_StaticEnum, TEXT("/Script/Voxel"), TEXT("EFailReason"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EFailReason_CRC() { return 2055234557U; }
	UEnum* Z_Construct_UEnum_Voxel_EFailReason()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EFailReason"), 0, Get_Z_Construct_UEnum_Voxel_EFailReason_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EFailReason::VoxelDataLocked", (int64)EFailReason::VoxelDataLocked },
				{ "EFailReason::LinetracesPending", (int64)EFailReason::LinetracesPending },
				{ "EFailReason::OtherError", (int64)EFailReason::OtherError },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EFailReason",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EFailReason",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EBlueprintSuccess_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EBlueprintSuccess, Z_Construct_UPackage__Script_Voxel(), TEXT("EBlueprintSuccess"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EBlueprintSuccess(EBlueprintSuccess_StaticEnum, TEXT("/Script/Voxel"), TEXT("EBlueprintSuccess"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EBlueprintSuccess_CRC() { return 582468017U; }
	UEnum* Z_Construct_UEnum_Voxel_EBlueprintSuccess()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EBlueprintSuccess"), 0, Get_Z_Construct_UEnum_Voxel_EBlueprintSuccess_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EBlueprintSuccess::Success", (int64)EBlueprintSuccess::Success },
				{ "EBlueprintSuccess::Failed", (int64)EBlueprintSuccess::Failed },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EBlueprintSuccess",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EBlueprintSuccess",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FGetVoxelProjectionVoxel::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel, Z_Construct_UPackage__Script_Voxel(), TEXT("GetVoxelProjectionVoxel"), sizeof(FGetVoxelProjectionVoxel), Get_Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FGetVoxelProjectionVoxel(FGetVoxelProjectionVoxel::StaticStruct, TEXT("/Script/Voxel"), TEXT("GetVoxelProjectionVoxel"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFGetVoxelProjectionVoxel
{
	FScriptStruct_Voxel_StaticRegisterNativesFGetVoxelProjectionVoxel()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("GetVoxelProjectionVoxel")),new UScriptStruct::TCppStructOps<FGetVoxelProjectionVoxel>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFGetVoxelProjectionVoxel;
	struct Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGetVoxelProjectionVoxel>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Material_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FGetVoxelProjectionVoxel, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Material_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Material_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FGetVoxelProjectionVoxel, Value), METADATA_PARAMS(Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Value_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Position_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FGetVoxelProjectionVoxel, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Position_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Position_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Material,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::NewProp_Position,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"GetVoxelProjectionVoxel",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FGetVoxelProjectionVoxel),
		alignof(FGetVoxelProjectionVoxel),
		Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("GetVoxelProjectionVoxel"), sizeof(FGetVoxelProjectionVoxel), Get_Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel_CRC() { return 2610121920U; }
class UScriptStruct* FModifiedVoxelMaterial::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FModifiedVoxelMaterial_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FModifiedVoxelMaterial, Z_Construct_UPackage__Script_Voxel(), TEXT("ModifiedVoxelMaterial"), sizeof(FModifiedVoxelMaterial), Get_Z_Construct_UScriptStruct_FModifiedVoxelMaterial_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FModifiedVoxelMaterial(FModifiedVoxelMaterial::StaticStruct, TEXT("/Script/Voxel"), TEXT("ModifiedVoxelMaterial"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFModifiedVoxelMaterial
{
	FScriptStruct_Voxel_StaticRegisterNativesFModifiedVoxelMaterial()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ModifiedVoxelMaterial")),new UScriptStruct::TCppStructOps<FModifiedVoxelMaterial>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFModifiedVoxelMaterial;
	struct Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NewMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NewMaterial;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OldMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OldMaterial;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModifiedVoxelMaterial>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_NewMaterial_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_NewMaterial = { UE4CodeGen_Private::EPropertyClass::Struct, "NewMaterial", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FModifiedVoxelMaterial, NewMaterial), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_NewMaterial_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_NewMaterial_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_OldMaterial_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_OldMaterial = { UE4CodeGen_Private::EPropertyClass::Struct, "OldMaterial", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FModifiedVoxelMaterial, OldMaterial), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_OldMaterial_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_OldMaterial_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_Position_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FModifiedVoxelMaterial, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_Position_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_Position_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_NewMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_OldMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::NewProp_Position,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"ModifiedVoxelMaterial",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FModifiedVoxelMaterial),
		alignof(FModifiedVoxelMaterial),
		Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FModifiedVoxelMaterial()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FModifiedVoxelMaterial_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ModifiedVoxelMaterial"), sizeof(FModifiedVoxelMaterial), Get_Z_Construct_UScriptStruct_FModifiedVoxelMaterial_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FModifiedVoxelMaterial_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FModifiedVoxelMaterial_CRC() { return 88289522U; }
class UScriptStruct* FModifiedVoxelValue::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FModifiedVoxelValue_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FModifiedVoxelValue, Z_Construct_UPackage__Script_Voxel(), TEXT("ModifiedVoxelValue"), sizeof(FModifiedVoxelValue), Get_Z_Construct_UScriptStruct_FModifiedVoxelValue_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FModifiedVoxelValue(FModifiedVoxelValue::StaticStruct, TEXT("/Script/Voxel"), TEXT("ModifiedVoxelValue"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFModifiedVoxelValue
{
	FScriptStruct_Voxel_StaticRegisterNativesFModifiedVoxelValue()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ModifiedVoxelValue")),new UScriptStruct::TCppStructOps<FModifiedVoxelValue>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFModifiedVoxelValue;
	struct Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NewValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OldValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_OldValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModifiedVoxelValue>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_NewValue_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_NewValue = { UE4CodeGen_Private::EPropertyClass::Float, "NewValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FModifiedVoxelValue, NewValue), METADATA_PARAMS(Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_NewValue_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_NewValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_OldValue_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_OldValue = { UE4CodeGen_Private::EPropertyClass::Float, "OldValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FModifiedVoxelValue, OldValue), METADATA_PARAMS(Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_OldValue_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_OldValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_Position_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FModifiedVoxelValue, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_Position_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_Position_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_NewValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_OldValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::NewProp_Position,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"ModifiedVoxelValue",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FModifiedVoxelValue),
		alignof(FModifiedVoxelValue),
		Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FModifiedVoxelValue()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FModifiedVoxelValue_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ModifiedVoxelValue"), sizeof(FModifiedVoxelValue), Get_Z_Construct_UScriptStruct_FModifiedVoxelValue_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FModifiedVoxelValue_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FModifiedVoxelValue_CRC() { return 563466065U; }
	void UVoxelProjectionTools::StaticRegisterNativesUVoxelProjectionTools()
	{
		UClass* Class = UVoxelProjectionTools::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetVoxelsProjection", &UVoxelProjectionTools::execGetVoxelsProjection },
			{ "GetVoxelsProjectionAsync", &UVoxelProjectionTools::execGetVoxelsProjectionAsync },
			{ "SetMaterialProjectionAsync", &UVoxelProjectionTools::execSetMaterialProjectionAsync },
			{ "SetMaterialProjectionNew", &UVoxelProjectionTools::execSetMaterialProjectionNew },
			{ "SetValueProjectionAsync", &UVoxelProjectionTools::execSetValueProjectionAsync },
			{ "SetValueProjectionNew", &UVoxelProjectionTools::execSetValueProjectionNew },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics
	{
		struct VoxelProjectionTools_eventGetVoxelsProjection_Parms
		{
			EBlueprintSuccess Branches;
			TArray<FGetVoxelProjectionVoxel> OutVoxels;
			AVoxelWorld* World;
			FVector Position;
			FVector Normal;
			float Radius;
			float ToolHeight;
			float EditDistance;
			float StepInVoxel;
			bool bShowRaycasts;
		};
		static void NewProp_bShowRaycasts_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowRaycasts;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StepInVoxel;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_EditDistance;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ToolHeight;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OutVoxels;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutVoxels_Inner;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Branches;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Branches_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_bShowRaycasts_SetBit(void* Obj)
	{
		((VoxelProjectionTools_eventGetVoxelsProjection_Parms*)Obj)->bShowRaycasts = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_bShowRaycasts = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowRaycasts", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelProjectionTools_eventGetVoxelsProjection_Parms), &Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_bShowRaycasts_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_StepInVoxel = { UE4CodeGen_Private::EPropertyClass::Float, "StepInVoxel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjection_Parms, StepInVoxel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_EditDistance = { UE4CodeGen_Private::EPropertyClass::Float, "EditDistance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjection_Parms, EditDistance), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_ToolHeight = { UE4CodeGen_Private::EPropertyClass::Float, "ToolHeight", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjection_Parms, ToolHeight), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjection_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_Normal = { UE4CodeGen_Private::EPropertyClass::Struct, "Normal", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjection_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjection_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjection_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_OutVoxels = { UE4CodeGen_Private::EPropertyClass::Array, "OutVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjection_Parms, OutVoxels), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_OutVoxels_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "OutVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_Branches = { UE4CodeGen_Private::EPropertyClass::Enum, "Branches", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjection_Parms, Branches), Z_Construct_UEnum_Voxel_EBlueprintSuccess, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_Branches_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_bShowRaycasts,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_StepInVoxel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_EditDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_ToolHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_Normal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_World,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_OutVoxels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_OutVoxels_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_Branches,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::NewProp_Branches_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "6" },
		{ "Category", "Voxel" },
		{ "CPP_Default_bShowRaycasts", "false" },
		{ "CPP_Default_EditDistance", "400.000000" },
		{ "CPP_Default_Radius", "100.000000" },
		{ "CPP_Default_StepInVoxel", "0.500000" },
		{ "CPP_Default_ToolHeight", "200.000000" },
		{ "ExpandEnumAsExecs", "Branches" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelProjectionTools, "GetVoxelsProjection", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C22401, sizeof(VoxelProjectionTools_eventGetVoxelsProjection_Parms), Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics
	{
		struct VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms
		{
			UObject* WorldContextObject;
			FLatentActionInfo LatentInfo;
			EBlueprintSuccess Branches;
			TArray<FGetVoxelProjectionVoxel> OutVoxels;
			AVoxelWorld* World;
			FVector Position;
			FVector Normal;
			float Radius;
			float ToolHeight;
			float EditDistance;
			float StepInVoxel;
			bool bShowRaycasts;
		};
		static void NewProp_bShowRaycasts_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowRaycasts;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StepInVoxel;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_EditDistance;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ToolHeight;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OutVoxels;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutVoxels_Inner;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Branches;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Branches_Underlying;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_bShowRaycasts_SetBit(void* Obj)
	{
		((VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms*)Obj)->bShowRaycasts = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_bShowRaycasts = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowRaycasts", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms), &Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_bShowRaycasts_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_StepInVoxel = { UE4CodeGen_Private::EPropertyClass::Float, "StepInVoxel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms, StepInVoxel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_EditDistance = { UE4CodeGen_Private::EPropertyClass::Float, "EditDistance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms, EditDistance), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_ToolHeight = { UE4CodeGen_Private::EPropertyClass::Float, "ToolHeight", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms, ToolHeight), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_Normal = { UE4CodeGen_Private::EPropertyClass::Struct, "Normal", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_OutVoxels = { UE4CodeGen_Private::EPropertyClass::Array, "OutVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms, OutVoxels), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_OutVoxels_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "OutVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FGetVoxelProjectionVoxel, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_Branches = { UE4CodeGen_Private::EPropertyClass::Enum, "Branches", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms, Branches), Z_Construct_UEnum_Voxel_EBlueprintSuccess, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_Branches_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_LatentInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "LatentInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_bShowRaycasts,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_StepInVoxel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_EditDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_ToolHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_Normal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_World,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_OutVoxels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_OutVoxels_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_Branches,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_Branches_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_LatentInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "8" },
		{ "Category", "Voxel" },
		{ "CPP_Default_bShowRaycasts", "false" },
		{ "CPP_Default_EditDistance", "400.000000" },
		{ "CPP_Default_Radius", "100.000000" },
		{ "CPP_Default_StepInVoxel", "0.500000" },
		{ "CPP_Default_ToolHeight", "200.000000" },
		{ "ExpandEnumAsExecs", "Branches" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelProjectionTools, "GetVoxelsProjectionAsync", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C22401, sizeof(VoxelProjectionTools_eventGetVoxelsProjectionAsync_Parms), Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics
	{
		struct VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms
		{
			UObject* WorldContextObject;
			FLatentActionInfo LatentInfo;
			EBlueprintSuccess Branches;
			EFailReason FailReason;
			TArray<FModifiedVoxelMaterial> ModifiedVoxels;
			AVoxelWorld* World;
			FVector Position;
			FVector Normal;
			FVoxelPaintMaterial PaintMaterial;
			UCurveFloat* StrengthCurve;
			float Radius;
			float ToolHeight;
			float EditDistance;
			float StepInVoxel;
			int32 TimeoutInMicroSeconds;
			bool bShowRaycasts;
		};
		static void NewProp_bShowRaycasts_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowRaycasts;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_TimeoutInMicroSeconds;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StepInVoxel;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_EditDistance;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ToolHeight;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StrengthCurve;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PaintMaterial;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ModifiedVoxels;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ModifiedVoxels_Inner;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_FailReason;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_FailReason_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Branches;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Branches_Underlying;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_bShowRaycasts_SetBit(void* Obj)
	{
		((VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms*)Obj)->bShowRaycasts = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_bShowRaycasts = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowRaycasts", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms), &Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_bShowRaycasts_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_TimeoutInMicroSeconds = { UE4CodeGen_Private::EPropertyClass::Int, "TimeoutInMicroSeconds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, TimeoutInMicroSeconds), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_StepInVoxel = { UE4CodeGen_Private::EPropertyClass::Float, "StepInVoxel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, StepInVoxel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_EditDistance = { UE4CodeGen_Private::EPropertyClass::Float, "EditDistance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, EditDistance), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_ToolHeight = { UE4CodeGen_Private::EPropertyClass::Float, "ToolHeight", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, ToolHeight), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_StrengthCurve = { UE4CodeGen_Private::EPropertyClass::Object, "StrengthCurve", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, StrengthCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_PaintMaterial = { UE4CodeGen_Private::EPropertyClass::Struct, "PaintMaterial", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, PaintMaterial), Z_Construct_UScriptStruct_FVoxelPaintMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_Normal = { UE4CodeGen_Private::EPropertyClass::Struct, "Normal", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_ModifiedVoxels = { UE4CodeGen_Private::EPropertyClass::Array, "ModifiedVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, ModifiedVoxels), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_ModifiedVoxels_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ModifiedVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FModifiedVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_FailReason = { UE4CodeGen_Private::EPropertyClass::Enum, "FailReason", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, FailReason), Z_Construct_UEnum_Voxel_EFailReason, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_FailReason_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_Branches = { UE4CodeGen_Private::EPropertyClass::Enum, "Branches", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, Branches), Z_Construct_UEnum_Voxel_EBlueprintSuccess, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_Branches_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_LatentInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "LatentInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_bShowRaycasts,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_TimeoutInMicroSeconds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_StepInVoxel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_EditDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_ToolHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_StrengthCurve,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_PaintMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_Normal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_World,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_ModifiedVoxels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_ModifiedVoxels_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_FailReason,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_FailReason_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_Branches,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_Branches_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_LatentInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "11" },
		{ "Category", "Voxel" },
		{ "CPP_Default_bShowRaycasts", "false" },
		{ "CPP_Default_EditDistance", "400.000000" },
		{ "CPP_Default_Radius", "100.000000" },
		{ "CPP_Default_StepInVoxel", "0.500000" },
		{ "CPP_Default_StrengthCurve", "None" },
		{ "CPP_Default_TimeoutInMicroSeconds", "500" },
		{ "CPP_Default_ToolHeight", "200.000000" },
		{ "ExpandEnumAsExecs", "Branches" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
		{ "ToolTip", "Set Material Projection Async\n@param       ModifiedVoxels\n@param       World\n@param       Position                                In world space\n@param       Normal\n@param       Radius                                  In world space\n@param       PaintMaterial\n@param       ToolHeight\n@param       EditDistance\n@param       StepInVoxel                             Step between traces\n@param       TimeoutInMicroSeconds   Timeout on the lock query\n@param       bShowRaycasts" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelProjectionTools, "SetMaterialProjectionAsync", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C22401, sizeof(VoxelProjectionTools_eventSetMaterialProjectionAsync_Parms), Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics
	{
		struct VoxelProjectionTools_eventSetMaterialProjectionNew_Parms
		{
			EBlueprintSuccess Branches;
			EFailReason FailReason;
			TArray<FModifiedVoxelMaterial> ModifiedVoxels;
			AVoxelWorld* World;
			FVector Position;
			FVector Normal;
			FVoxelPaintMaterial PaintMaterial;
			UCurveFloat* StrengthCurve;
			float Radius;
			float ToolHeight;
			float EditDistance;
			float StepInVoxel;
			int32 TimeoutInMicroSeconds;
			bool bShowRaycasts;
		};
		static void NewProp_bShowRaycasts_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowRaycasts;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_TimeoutInMicroSeconds;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StepInVoxel;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_EditDistance;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ToolHeight;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StrengthCurve;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PaintMaterial;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ModifiedVoxels;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ModifiedVoxels_Inner;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_FailReason;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_FailReason_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Branches;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Branches_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_bShowRaycasts_SetBit(void* Obj)
	{
		((VoxelProjectionTools_eventSetMaterialProjectionNew_Parms*)Obj)->bShowRaycasts = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_bShowRaycasts = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowRaycasts", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms), &Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_bShowRaycasts_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_TimeoutInMicroSeconds = { UE4CodeGen_Private::EPropertyClass::Int, "TimeoutInMicroSeconds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms, TimeoutInMicroSeconds), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_StepInVoxel = { UE4CodeGen_Private::EPropertyClass::Float, "StepInVoxel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms, StepInVoxel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_EditDistance = { UE4CodeGen_Private::EPropertyClass::Float, "EditDistance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms, EditDistance), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_ToolHeight = { UE4CodeGen_Private::EPropertyClass::Float, "ToolHeight", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms, ToolHeight), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_StrengthCurve = { UE4CodeGen_Private::EPropertyClass::Object, "StrengthCurve", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms, StrengthCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_PaintMaterial = { UE4CodeGen_Private::EPropertyClass::Struct, "PaintMaterial", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms, PaintMaterial), Z_Construct_UScriptStruct_FVoxelPaintMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_Normal = { UE4CodeGen_Private::EPropertyClass::Struct, "Normal", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_ModifiedVoxels = { UE4CodeGen_Private::EPropertyClass::Array, "ModifiedVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms, ModifiedVoxels), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_ModifiedVoxels_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ModifiedVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FModifiedVoxelMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_FailReason = { UE4CodeGen_Private::EPropertyClass::Enum, "FailReason", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms, FailReason), Z_Construct_UEnum_Voxel_EFailReason, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_FailReason_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_Branches = { UE4CodeGen_Private::EPropertyClass::Enum, "Branches", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms, Branches), Z_Construct_UEnum_Voxel_EBlueprintSuccess, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_Branches_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_bShowRaycasts,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_TimeoutInMicroSeconds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_StepInVoxel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_EditDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_ToolHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_StrengthCurve,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_PaintMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_Normal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_World,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_ModifiedVoxels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_ModifiedVoxels_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_FailReason,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_FailReason_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_Branches,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::NewProp_Branches_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "9" },
		{ "Category", "Voxel" },
		{ "CPP_Default_bShowRaycasts", "false" },
		{ "CPP_Default_EditDistance", "400.000000" },
		{ "CPP_Default_Radius", "100.000000" },
		{ "CPP_Default_StepInVoxel", "0.500000" },
		{ "CPP_Default_StrengthCurve", "None" },
		{ "CPP_Default_TimeoutInMicroSeconds", "500" },
		{ "CPP_Default_ToolHeight", "200.000000" },
		{ "DisplayName", "Set Material Projection" },
		{ "ExpandEnumAsExecs", "Branches" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
		{ "ToolTip", "Set Material Projection\n@param       ModifiedVoxels\n@param       World\n@param       Position                                In world space\n@param       Normal\n@param       Radius                                  In world space\n@param       PaintMaterial\n@param       ToolHeight\n@param       EditDistance\n@param       StepInVoxel                             Step between traces\n@param       TimeoutInMicroSeconds   Timeout on the lock query\n@param       bShowRaycasts" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelProjectionTools, "SetMaterialProjectionNew", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C22401, sizeof(VoxelProjectionTools_eventSetMaterialProjectionNew_Parms), Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics
	{
		struct VoxelProjectionTools_eventSetValueProjectionAsync_Parms
		{
			UObject* WorldContextObject;
			FLatentActionInfo LatentInfo;
			EBlueprintSuccess Branches;
			EFailReason FailReason;
			TArray<FModifiedVoxelValue> ModifiedVoxels;
			AVoxelWorld* World;
			FVector Position;
			FVector Normal;
			float Radius;
			float Strength;
			UCurveFloat* StrengthCurve;
			float ToolHeight;
			float EditDistance;
			float StepInVoxel;
			int32 TimeoutInMicroSeconds;
			bool bShowRaycasts;
		};
		static void NewProp_bShowRaycasts_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowRaycasts;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_TimeoutInMicroSeconds;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StepInVoxel;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_EditDistance;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ToolHeight;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StrengthCurve;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Strength;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ModifiedVoxels;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ModifiedVoxels_Inner;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_FailReason;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_FailReason_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Branches;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Branches_Underlying;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_bShowRaycasts_SetBit(void* Obj)
	{
		((VoxelProjectionTools_eventSetValueProjectionAsync_Parms*)Obj)->bShowRaycasts = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_bShowRaycasts = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowRaycasts", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelProjectionTools_eventSetValueProjectionAsync_Parms), &Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_bShowRaycasts_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_TimeoutInMicroSeconds = { UE4CodeGen_Private::EPropertyClass::Int, "TimeoutInMicroSeconds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, TimeoutInMicroSeconds), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_StepInVoxel = { UE4CodeGen_Private::EPropertyClass::Float, "StepInVoxel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, StepInVoxel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_EditDistance = { UE4CodeGen_Private::EPropertyClass::Float, "EditDistance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, EditDistance), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_ToolHeight = { UE4CodeGen_Private::EPropertyClass::Float, "ToolHeight", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, ToolHeight), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_StrengthCurve = { UE4CodeGen_Private::EPropertyClass::Object, "StrengthCurve", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, StrengthCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_Strength = { UE4CodeGen_Private::EPropertyClass::Float, "Strength", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, Strength), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_Normal = { UE4CodeGen_Private::EPropertyClass::Struct, "Normal", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_ModifiedVoxels = { UE4CodeGen_Private::EPropertyClass::Array, "ModifiedVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, ModifiedVoxels), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_ModifiedVoxels_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ModifiedVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FModifiedVoxelValue, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_FailReason = { UE4CodeGen_Private::EPropertyClass::Enum, "FailReason", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, FailReason), Z_Construct_UEnum_Voxel_EFailReason, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_FailReason_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_Branches = { UE4CodeGen_Private::EPropertyClass::Enum, "Branches", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, Branches), Z_Construct_UEnum_Voxel_EBlueprintSuccess, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_Branches_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_LatentInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "LatentInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionAsync_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_bShowRaycasts,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_TimeoutInMicroSeconds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_StepInVoxel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_EditDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_ToolHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_StrengthCurve,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_Strength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_Normal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_World,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_ModifiedVoxels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_ModifiedVoxels_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_FailReason,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_FailReason_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_Branches,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_Branches_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_LatentInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "11" },
		{ "Category", "Voxel" },
		{ "CPP_Default_bShowRaycasts", "false" },
		{ "CPP_Default_EditDistance", "400.000000" },
		{ "CPP_Default_Radius", "100.000000" },
		{ "CPP_Default_StepInVoxel", "0.500000" },
		{ "CPP_Default_Strength", "0.500000" },
		{ "CPP_Default_StrengthCurve", "None" },
		{ "CPP_Default_TimeoutInMicroSeconds", "500" },
		{ "CPP_Default_ToolHeight", "200.000000" },
		{ "ExpandEnumAsExecs", "Branches" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
		{ "ToolTip", "Set Value Projection Async\n@param       ModifiedVoxels\n@param       World\n@param       Position                                In world space\n@param       Normal\n@param       Radius                                  In world space\n@param       Strength                                Between -1 and 1\n@param       StrengthCurve                   Strength multiplier = Curve(DistanceToCenter/Radius)\n@param       ToolHeight\n@param       EditDistance\n@param       StepInVoxel                             Step between traces\n@param       TimeoutInMicroSeconds   Timeout on the lock query\n@param       bShowRaycasts" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelProjectionTools, "SetValueProjectionAsync", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C22401, sizeof(VoxelProjectionTools_eventSetValueProjectionAsync_Parms), Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics
	{
		struct VoxelProjectionTools_eventSetValueProjectionNew_Parms
		{
			EBlueprintSuccess Branches;
			EFailReason FailReason;
			TArray<FModifiedVoxelValue> ModifiedVoxels;
			AVoxelWorld* World;
			FVector Position;
			FVector Normal;
			float Radius;
			float Strength;
			UCurveFloat* StrengthCurve;
			float ToolHeight;
			float EditDistance;
			float StepInVoxel;
			int32 TimeoutInMicroSeconds;
			bool bShowRaycasts;
		};
		static void NewProp_bShowRaycasts_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowRaycasts;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_TimeoutInMicroSeconds;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StepInVoxel;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_EditDistance;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ToolHeight;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StrengthCurve;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Strength;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ModifiedVoxels;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ModifiedVoxels_Inner;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_FailReason;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_FailReason_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Branches;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Branches_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_bShowRaycasts_SetBit(void* Obj)
	{
		((VoxelProjectionTools_eventSetValueProjectionNew_Parms*)Obj)->bShowRaycasts = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_bShowRaycasts = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowRaycasts", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelProjectionTools_eventSetValueProjectionNew_Parms), &Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_bShowRaycasts_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_TimeoutInMicroSeconds = { UE4CodeGen_Private::EPropertyClass::Int, "TimeoutInMicroSeconds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionNew_Parms, TimeoutInMicroSeconds), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_StepInVoxel = { UE4CodeGen_Private::EPropertyClass::Float, "StepInVoxel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionNew_Parms, StepInVoxel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_EditDistance = { UE4CodeGen_Private::EPropertyClass::Float, "EditDistance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionNew_Parms, EditDistance), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_ToolHeight = { UE4CodeGen_Private::EPropertyClass::Float, "ToolHeight", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionNew_Parms, ToolHeight), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_StrengthCurve = { UE4CodeGen_Private::EPropertyClass::Object, "StrengthCurve", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionNew_Parms, StrengthCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_Strength = { UE4CodeGen_Private::EPropertyClass::Float, "Strength", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionNew_Parms, Strength), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionNew_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_Normal = { UE4CodeGen_Private::EPropertyClass::Struct, "Normal", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionNew_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionNew_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionNew_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_ModifiedVoxels = { UE4CodeGen_Private::EPropertyClass::Array, "ModifiedVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionNew_Parms, ModifiedVoxels), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_ModifiedVoxels_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ModifiedVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FModifiedVoxelValue, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_FailReason = { UE4CodeGen_Private::EPropertyClass::Enum, "FailReason", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionNew_Parms, FailReason), Z_Construct_UEnum_Voxel_EFailReason, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_FailReason_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_Branches = { UE4CodeGen_Private::EPropertyClass::Enum, "Branches", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelProjectionTools_eventSetValueProjectionNew_Parms, Branches), Z_Construct_UEnum_Voxel_EBlueprintSuccess, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_Branches_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_bShowRaycasts,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_TimeoutInMicroSeconds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_StepInVoxel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_EditDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_ToolHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_StrengthCurve,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_Strength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_Normal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_World,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_ModifiedVoxels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_ModifiedVoxels_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_FailReason,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_FailReason_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_Branches,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::NewProp_Branches_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "9" },
		{ "Category", "Voxel" },
		{ "CPP_Default_bShowRaycasts", "false" },
		{ "CPP_Default_EditDistance", "400.000000" },
		{ "CPP_Default_Radius", "100.000000" },
		{ "CPP_Default_StepInVoxel", "0.500000" },
		{ "CPP_Default_Strength", "0.500000" },
		{ "CPP_Default_StrengthCurve", "None" },
		{ "CPP_Default_TimeoutInMicroSeconds", "500" },
		{ "CPP_Default_ToolHeight", "200.000000" },
		{ "DisplayName", "Set Value Projection" },
		{ "ExpandEnumAsExecs", "Branches" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
		{ "ToolTip", "Set Value Projection\n@param       ModifiedVoxels\n@param       World\n@param       Position                                In world space\n@param       Normal\n@param       Radius                                  In world space\n@param       Strength                                Between -1 and 1\n@param       StrengthCurve                   Strength multiplier = Curve(DistanceToCenter/Radius)\n@param       ToolHeight\n@param       EditDistance\n@param       StepInVoxel                             Step between traces\n@param       TimeoutInMicroSeconds   Timeout on the lock query\n@param       bShowRaycasts" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelProjectionTools, "SetValueProjectionNew", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C22401, sizeof(VoxelProjectionTools_eventSetValueProjectionNew_Parms), Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelProjectionTools_NoRegister()
	{
		return UVoxelProjectionTools::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelProjectionTools_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelProjectionTools_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelProjectionTools_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjection, "GetVoxelsProjection" }, // 1135485960
		{ &Z_Construct_UFunction_UVoxelProjectionTools_GetVoxelsProjectionAsync, "GetVoxelsProjectionAsync" }, // 1262681156
		{ &Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionAsync, "SetMaterialProjectionAsync" }, // 3152246868
		{ &Z_Construct_UFunction_UVoxelProjectionTools_SetMaterialProjectionNew, "SetMaterialProjectionNew" }, // 236202485
		{ &Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionAsync, "SetValueProjectionAsync" }, // 3079908832
		{ &Z_Construct_UFunction_UVoxelProjectionTools_SetValueProjectionNew, "SetValueProjectionNew" }, // 1519873649
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelProjectionTools_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelTools/VoxelProjectionTools.h" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelProjectionTools.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelProjectionTools_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelProjectionTools>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelProjectionTools_Statics::ClassParams = {
		&UVoxelProjectionTools::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelProjectionTools_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelProjectionTools_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelProjectionTools()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelProjectionTools_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelProjectionTools, 80579279);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelProjectionTools(Z_Construct_UClass_UVoxelProjectionTools, &UVoxelProjectionTools::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelProjectionTools"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelProjectionTools);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
