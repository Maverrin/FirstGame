// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/IntBox.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIntBox() {}
// Cross Module References
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FIntBox();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
// End Cross Module References
class UScriptStruct* FIntBox::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FIntBox_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FIntBox, Z_Construct_UPackage__Script_Voxel(), TEXT("IntBox"), sizeof(FIntBox), Get_Z_Construct_UScriptStruct_FIntBox_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FIntBox(FIntBox::StaticStruct, TEXT("/Script/Voxel"), TEXT("IntBox"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFIntBox
{
	FScriptStruct_Voxel_StaticRegisterNativesFIntBox()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("IntBox")),new UScriptStruct::TCppStructOps<FIntBox>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFIntBox;
	struct Z_Construct_UScriptStruct_FIntBox_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Max_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Max;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Min_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Min;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FIntBox_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/IntBox.h" },
		{ "ToolTip", "A Box with int coordinates" },
	};
#endif
	void* Z_Construct_UScriptStruct_FIntBox_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FIntBox>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FIntBox_Statics::NewProp_Max_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/IntBox.h" },
		{ "ToolTip", "Max of the box. Exclusive" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FIntBox_Statics::NewProp_Max = { UE4CodeGen_Private::EPropertyClass::Struct, "Max", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FIntBox, Max), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FIntBox_Statics::NewProp_Max_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FIntBox_Statics::NewProp_Max_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FIntBox_Statics::NewProp_Min_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/IntBox.h" },
		{ "ToolTip", "Min of the box. Inclusive" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FIntBox_Statics::NewProp_Min = { UE4CodeGen_Private::EPropertyClass::Struct, "Min", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FIntBox, Min), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FIntBox_Statics::NewProp_Min_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FIntBox_Statics::NewProp_Min_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FIntBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FIntBox_Statics::NewProp_Max,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FIntBox_Statics::NewProp_Min,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FIntBox_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"IntBox",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FIntBox),
		alignof(FIntBox),
		Z_Construct_UScriptStruct_FIntBox_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FIntBox_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FIntBox_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FIntBox_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FIntBox()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FIntBox_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("IntBox"), sizeof(FIntBox), Get_Z_Construct_UScriptStruct_FIntBox_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FIntBox_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FIntBox_CRC() { return 3985004541U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
