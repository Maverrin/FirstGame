// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelMaterial.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelMaterial() {}
// Cross Module References
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterial();
	UPackage* Z_Construct_UPackage__Script_Voxel();
// End Cross Module References
class UScriptStruct* FVoxelMaterial::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterial_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelMaterial, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelMaterial"), sizeof(FVoxelMaterial), Get_Z_Construct_UScriptStruct_FVoxelMaterial_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelMaterial(FVoxelMaterial::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelMaterial"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterial
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterial()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelMaterial")),new UScriptStruct::TCppStructOps<FVoxelMaterial>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterial;
	struct Z_Construct_UScriptStruct_FVoxelMaterial_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterial_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VoxelMaterial.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelMaterial_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelMaterial>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelMaterial_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelMaterial",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelMaterial),
		alignof(FVoxelMaterial),
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterial_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterial_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterial()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterial_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelMaterial"), sizeof(FVoxelMaterial), Get_Z_Construct_UScriptStruct_FVoxelMaterial_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelMaterial_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterial_CRC() { return 2074538990U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
