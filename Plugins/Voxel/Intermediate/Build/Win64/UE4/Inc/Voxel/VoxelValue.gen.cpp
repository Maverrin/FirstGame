// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelValue.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelValue() {}
// Cross Module References
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelValue();
	UPackage* Z_Construct_UPackage__Script_Voxel();
// End Cross Module References
class UScriptStruct* FVoxelValue::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelValue_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelValue, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelValue"), sizeof(FVoxelValue), Get_Z_Construct_UScriptStruct_FVoxelValue_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelValue(FVoxelValue::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelValue"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelValue
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelValue()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelValue")),new UScriptStruct::TCppStructOps<FVoxelValue>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelValue;
	struct Z_Construct_UScriptStruct_FVoxelValue_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelValue_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VoxelValue.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelValue_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelValue>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelValue_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelValue",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelValue),
		alignof(FVoxelValue),
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelValue_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelValue_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelValue()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelValue_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelValue"), sizeof(FVoxelValue), Get_Z_Construct_UScriptStruct_FVoxelValue_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelValue_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelValue_CRC() { return 3707964876U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
