// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelRender/VoxelIntermediateChunk.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelIntermediateChunk() {}
// Cross Module References
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
// End Cross Module References
class UScriptStruct* FVoxelMaterialsRefHolder::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelMaterialsRefHolder"), sizeof(FVoxelMaterialsRefHolder), Get_Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelMaterialsRefHolder(FVoxelMaterialsRefHolder::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelMaterialsRefHolder"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialsRefHolder
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialsRefHolder()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelMaterialsRefHolder")),new UScriptStruct::TCppStructOps<FVoxelMaterialsRefHolder>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialsRefHolder;
	struct Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UsedMaterials_MetaData[];
#endif
		static const UE4CodeGen_Private::FSetPropertyParams NewProp_UsedMaterials;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_UsedMaterials_ElementProp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelRender/VoxelIntermediateChunk.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelMaterialsRefHolder>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::NewProp_UsedMaterials_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelRender/VoxelIntermediateChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FSetPropertyParams Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::NewProp_UsedMaterials = { UE4CodeGen_Private::EPropertyClass::Set, "UsedMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FVoxelMaterialsRefHolder, UsedMaterials), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::NewProp_UsedMaterials_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::NewProp_UsedMaterials_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::NewProp_UsedMaterials_ElementProp = { UE4CodeGen_Private::EPropertyClass::Object, "UsedMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::NewProp_UsedMaterials,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::NewProp_UsedMaterials_ElementProp,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelMaterialsRefHolder",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FVoxelMaterialsRefHolder),
		alignof(FVoxelMaterialsRefHolder),
		Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelMaterialsRefHolder"), sizeof(FVoxelMaterialsRefHolder), Get_Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder_CRC() { return 3231512731U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
