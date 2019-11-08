// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelTools/VoxelAssetTools.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelAssetTools() {}
// Cross Module References
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelAssetSmartImportType();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelAssetPositionOffset();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelAssetTools_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelAssetTools();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelAssetTools_ImportAsset();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelDataAsset_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FLatentActionInfo();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	static UEnum* EVoxelAssetSmartImportType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelAssetSmartImportType, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelAssetSmartImportType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelAssetSmartImportType(EVoxelAssetSmartImportType_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelAssetSmartImportType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelAssetSmartImportType_CRC() { return 276666855U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelAssetSmartImportType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelAssetSmartImportType"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelAssetSmartImportType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelAssetSmartImportType::Add", (int64)EVoxelAssetSmartImportType::Add },
				{ "EVoxelAssetSmartImportType::Remove", (int64)EVoxelAssetSmartImportType::Remove },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/VoxelTools/VoxelAssetTools.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelAssetSmartImportType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelAssetSmartImportType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EVoxelAssetPositionOffset_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelAssetPositionOffset, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelAssetPositionOffset"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelAssetPositionOffset(EVoxelAssetPositionOffset_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelAssetPositionOffset"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelAssetPositionOffset_CRC() { return 2562720000U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelAssetPositionOffset()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelAssetPositionOffset"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelAssetPositionOffset_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelAssetPositionOffset::PositionIsMin", (int64)EVoxelAssetPositionOffset::PositionIsMin },
				{ "EVoxelAssetPositionOffset::PositionIsMiddle", (int64)EVoxelAssetPositionOffset::PositionIsMiddle },
				{ "EVoxelAssetPositionOffset::PositionIsMax", (int64)EVoxelAssetPositionOffset::PositionIsMax },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/VoxelTools/VoxelAssetTools.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelAssetPositionOffset",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelAssetPositionOffset",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void UVoxelAssetTools::StaticRegisterNativesUVoxelAssetTools()
	{
		UClass* Class = UVoxelAssetTools::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ImportAsset", &UVoxelAssetTools::execImportAsset },
			{ "ImportAssetAsync", &UVoxelAssetTools::execImportAssetAsync },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics
	{
		struct VoxelAssetTools_eventImportAsset_Parms
		{
			AVoxelWorld* World;
			UVoxelDataAsset* Asset;
			FIntVector Position;
			EVoxelAssetPositionOffset OffsetX;
			EVoxelAssetPositionOffset OffsetY;
			EVoxelAssetPositionOffset OffsetZ;
			bool bImportValues;
			bool bImportMaterials;
			bool bSmartImport;
			EVoxelAssetSmartImportType SmartImportType;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_SmartImportType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_SmartImportType_Underlying;
		static void NewProp_bSmartImport_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSmartImport;
		static void NewProp_bImportMaterials_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bImportMaterials;
		static void NewProp_bImportValues_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bImportValues;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_OffsetZ;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_OffsetZ_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_OffsetY;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_OffsetY_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_OffsetX;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_OffsetX_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_SmartImportType = { UE4CodeGen_Private::EPropertyClass::Enum, "SmartImportType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAsset_Parms, SmartImportType), Z_Construct_UEnum_Voxel_EVoxelAssetSmartImportType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_SmartImportType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_bSmartImport_SetBit(void* Obj)
	{
		((VoxelAssetTools_eventImportAsset_Parms*)Obj)->bSmartImport = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_bSmartImport = { UE4CodeGen_Private::EPropertyClass::Bool, "bSmartImport", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelAssetTools_eventImportAsset_Parms), &Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_bSmartImport_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_bImportMaterials_SetBit(void* Obj)
	{
		((VoxelAssetTools_eventImportAsset_Parms*)Obj)->bImportMaterials = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_bImportMaterials = { UE4CodeGen_Private::EPropertyClass::Bool, "bImportMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelAssetTools_eventImportAsset_Parms), &Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_bImportMaterials_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_bImportValues_SetBit(void* Obj)
	{
		((VoxelAssetTools_eventImportAsset_Parms*)Obj)->bImportValues = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_bImportValues = { UE4CodeGen_Private::EPropertyClass::Bool, "bImportValues", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelAssetTools_eventImportAsset_Parms), &Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_bImportValues_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_OffsetZ = { UE4CodeGen_Private::EPropertyClass::Enum, "OffsetZ", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAsset_Parms, OffsetZ), Z_Construct_UEnum_Voxel_EVoxelAssetPositionOffset, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_OffsetZ_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_OffsetY = { UE4CodeGen_Private::EPropertyClass::Enum, "OffsetY", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAsset_Parms, OffsetY), Z_Construct_UEnum_Voxel_EVoxelAssetPositionOffset, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_OffsetY_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_OffsetX = { UE4CodeGen_Private::EPropertyClass::Enum, "OffsetX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAsset_Parms, OffsetX), Z_Construct_UEnum_Voxel_EVoxelAssetPositionOffset, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_OffsetX_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_Position_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAsset_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_Position_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_Position_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_Asset = { UE4CodeGen_Private::EPropertyClass::Object, "Asset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAsset_Parms, Asset), Z_Construct_UClass_UVoxelDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAsset_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_SmartImportType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_SmartImportType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_bSmartImport,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_bImportMaterials,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_bImportValues,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_OffsetZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_OffsetZ_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_OffsetY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_OffsetY_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_OffsetX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_OffsetX_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_Asset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "CPP_Default_bImportMaterials", "true" },
		{ "CPP_Default_bImportValues", "true" },
		{ "CPP_Default_bSmartImport", "true" },
		{ "CPP_Default_OffsetX", "PositionIsMiddle" },
		{ "CPP_Default_OffsetY", "PositionIsMiddle" },
		{ "CPP_Default_OffsetZ", "PositionIsMin" },
		{ "CPP_Default_SmartImportType", "Add" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelAssetTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelAssetTools, "ImportAsset", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C22401, sizeof(VoxelAssetTools_eventImportAsset_Parms), Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelAssetTools_ImportAsset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelAssetTools_ImportAsset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics
	{
		struct VoxelAssetTools_eventImportAssetAsync_Parms
		{
			UObject* WorldContextObject;
			FLatentActionInfo LatentInfo;
			AVoxelWorld* World;
			UVoxelDataAsset* Asset;
			FIntVector Position;
			EVoxelAssetPositionOffset OffsetX;
			EVoxelAssetPositionOffset OffsetY;
			EVoxelAssetPositionOffset OffsetZ;
			bool bImportValues;
			bool bImportMaterials;
			bool bSmartImport;
			EVoxelAssetSmartImportType SmartImportType;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_SmartImportType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_SmartImportType_Underlying;
		static void NewProp_bSmartImport_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSmartImport;
		static void NewProp_bImportMaterials_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bImportMaterials;
		static void NewProp_bImportValues_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bImportValues;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_OffsetZ;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_OffsetZ_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_OffsetY;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_OffsetY_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_OffsetX;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_OffsetX_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_SmartImportType = { UE4CodeGen_Private::EPropertyClass::Enum, "SmartImportType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAssetAsync_Parms, SmartImportType), Z_Construct_UEnum_Voxel_EVoxelAssetSmartImportType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_SmartImportType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_bSmartImport_SetBit(void* Obj)
	{
		((VoxelAssetTools_eventImportAssetAsync_Parms*)Obj)->bSmartImport = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_bSmartImport = { UE4CodeGen_Private::EPropertyClass::Bool, "bSmartImport", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelAssetTools_eventImportAssetAsync_Parms), &Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_bSmartImport_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_bImportMaterials_SetBit(void* Obj)
	{
		((VoxelAssetTools_eventImportAssetAsync_Parms*)Obj)->bImportMaterials = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_bImportMaterials = { UE4CodeGen_Private::EPropertyClass::Bool, "bImportMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelAssetTools_eventImportAssetAsync_Parms), &Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_bImportMaterials_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_bImportValues_SetBit(void* Obj)
	{
		((VoxelAssetTools_eventImportAssetAsync_Parms*)Obj)->bImportValues = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_bImportValues = { UE4CodeGen_Private::EPropertyClass::Bool, "bImportValues", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelAssetTools_eventImportAssetAsync_Parms), &Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_bImportValues_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_OffsetZ = { UE4CodeGen_Private::EPropertyClass::Enum, "OffsetZ", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAssetAsync_Parms, OffsetZ), Z_Construct_UEnum_Voxel_EVoxelAssetPositionOffset, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_OffsetZ_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_OffsetY = { UE4CodeGen_Private::EPropertyClass::Enum, "OffsetY", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAssetAsync_Parms, OffsetY), Z_Construct_UEnum_Voxel_EVoxelAssetPositionOffset, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_OffsetY_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_OffsetX = { UE4CodeGen_Private::EPropertyClass::Enum, "OffsetX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAssetAsync_Parms, OffsetX), Z_Construct_UEnum_Voxel_EVoxelAssetPositionOffset, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_OffsetX_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_Position_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAssetAsync_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_Position_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_Position_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_Asset = { UE4CodeGen_Private::EPropertyClass::Object, "Asset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAssetAsync_Parms, Asset), Z_Construct_UClass_UVoxelDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAssetAsync_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_LatentInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "LatentInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAssetAsync_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelAssetTools_eventImportAssetAsync_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_SmartImportType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_SmartImportType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_bSmartImport,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_bImportMaterials,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_bImportValues,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_OffsetZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_OffsetZ_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_OffsetY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_OffsetY_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_OffsetX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_OffsetX_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_Asset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_World,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_LatentInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "CPP_Default_bImportMaterials", "true" },
		{ "CPP_Default_bImportValues", "true" },
		{ "CPP_Default_bSmartImport", "true" },
		{ "CPP_Default_OffsetX", "PositionIsMiddle" },
		{ "CPP_Default_OffsetY", "PositionIsMiddle" },
		{ "CPP_Default_OffsetZ", "PositionIsMin" },
		{ "CPP_Default_SmartImportType", "Add" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelAssetTools.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelAssetTools, "ImportAssetAsync", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C22401, sizeof(VoxelAssetTools_eventImportAssetAsync_Parms), Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelAssetTools_NoRegister()
	{
		return UVoxelAssetTools::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelAssetTools_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelAssetTools_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelAssetTools_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelAssetTools_ImportAsset, "ImportAsset" }, // 2170998873
		{ &Z_Construct_UFunction_UVoxelAssetTools_ImportAssetAsync, "ImportAssetAsync" }, // 2656813434
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelAssetTools_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelTools/VoxelAssetTools.h" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelAssetTools.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelAssetTools_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelAssetTools>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelAssetTools_Statics::ClassParams = {
		&UVoxelAssetTools::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelAssetTools_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelAssetTools_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelAssetTools()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelAssetTools_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelAssetTools, 2662996872);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelAssetTools(Z_Construct_UClass_UVoxelAssetTools, &UVoxelAssetTools::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelAssetTools"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelAssetTools);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
