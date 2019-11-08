// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelMaterialCollection.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelMaterialCollection() {}
// Cross Module References
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex();
	ENGINE_API UClass* Z_Construct_UClass_UPhysicalMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialFunction_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceConstant_NoRegister();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelMaterialCollection_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelMaterialCollection();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
// End Cross Module References
class UScriptStruct* FVoxelMaterialCollectionElement::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelMaterialCollectionElement"), sizeof(FVoxelMaterialCollectionElement), Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelMaterialCollectionElement(FVoxelMaterialCollectionElement::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelMaterialCollectionElement"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialCollectionElement
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialCollectionElement()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelMaterialCollectionElement")),new UScriptStruct::TCppStructOps<FVoxelMaterialCollectionElement>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialCollectionElement;
	struct Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Children_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Children;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Children_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PhysicalMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PhysicalMaterial;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialFunction_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MaterialFunction;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Index_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelMaterialCollectionElement>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_Children_MetaData[] = {
		{ "Category", "Voxel" },
		{ "DisplayName", "Instances" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_Children = { UE4CodeGen_Private::EPropertyClass::Array, "Children", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelMaterialCollectionElement, Children), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_Children_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_Children_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_Children_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Children", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_PhysicalMaterial_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_PhysicalMaterial = { UE4CodeGen_Private::EPropertyClass::Object, "PhysicalMaterial", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelMaterialCollectionElement, PhysicalMaterial), Z_Construct_UClass_UPhysicalMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_PhysicalMaterial_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_PhysicalMaterial_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_MaterialFunction_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_MaterialFunction = { UE4CodeGen_Private::EPropertyClass::Object, "MaterialFunction", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelMaterialCollectionElement, MaterialFunction), Z_Construct_UClass_UMaterialFunction_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_MaterialFunction_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_MaterialFunction_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_Index_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Byte, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelMaterialCollectionElement, Index), nullptr, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_Index_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_Index_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_Children,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_Children_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_PhysicalMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_MaterialFunction,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::NewProp_Index,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelMaterialCollectionElement",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FVoxelMaterialCollectionElement),
		alignof(FVoxelMaterialCollectionElement),
		Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelMaterialCollectionElement"), sizeof(FVoxelMaterialCollectionElement), Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement_CRC() { return 1193160859U; }
class UScriptStruct* FVoxelMaterialCollectionElementIndex::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelMaterialCollectionElementIndex"), sizeof(FVoxelMaterialCollectionElementIndex), Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelMaterialCollectionElementIndex(FVoxelMaterialCollectionElementIndex::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelMaterialCollectionElementIndex"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialCollectionElementIndex
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialCollectionElementIndex()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelMaterialCollectionElementIndex")),new UScriptStruct::TCppStructOps<FVoxelMaterialCollectionElementIndex>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialCollectionElementIndex;
	struct Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PhysicalMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PhysicalMaterial;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MaterialInstance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InstanceIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_InstanceIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelMaterialCollectionElementIndex>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_PhysicalMaterial_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_PhysicalMaterial = { UE4CodeGen_Private::EPropertyClass::Object, "PhysicalMaterial", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelMaterialCollectionElementIndex, PhysicalMaterial), Z_Construct_UClass_UPhysicalMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_PhysicalMaterial_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_PhysicalMaterial_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_MaterialInstance_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_MaterialInstance = { UE4CodeGen_Private::EPropertyClass::Object, "MaterialInstance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelMaterialCollectionElementIndex, MaterialInstance), Z_Construct_UClass_UMaterialInstanceConstant_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_MaterialInstance_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_MaterialInstance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_InstanceIndex_MetaData[] = {
		{ "Category", "Voxel" },
		{ "DisplayName", "Index" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_InstanceIndex = { UE4CodeGen_Private::EPropertyClass::Byte, "InstanceIndex", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelMaterialCollectionElementIndex, InstanceIndex), nullptr, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_InstanceIndex_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_InstanceIndex_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_PhysicalMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_MaterialInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::NewProp_InstanceIndex,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelMaterialCollectionElementIndex",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FVoxelMaterialCollectionElementIndex),
		alignof(FVoxelMaterialCollectionElementIndex),
		Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelMaterialCollectionElementIndex"), sizeof(FVoxelMaterialCollectionElementIndex), Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionElementIndex_CRC() { return 1062995412U; }
class UScriptStruct* FVoxelMaterialCollectionTripleIndex::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelMaterialCollectionTripleIndex"), sizeof(FVoxelMaterialCollectionTripleIndex), Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelMaterialCollectionTripleIndex(FVoxelMaterialCollectionTripleIndex::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelMaterialCollectionTripleIndex"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialCollectionTripleIndex
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialCollectionTripleIndex()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelMaterialCollectionTripleIndex")),new UScriptStruct::TCppStructOps<FVoxelMaterialCollectionTripleIndex>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialCollectionTripleIndex;
	struct Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_K_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_K;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_J_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_J;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_I_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_I;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelMaterialCollectionTripleIndex>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_K_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_K = { UE4CodeGen_Private::EPropertyClass::Int, "K", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelMaterialCollectionTripleIndex, K), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_K_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_K_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_J_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_J = { UE4CodeGen_Private::EPropertyClass::Int, "J", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelMaterialCollectionTripleIndex, J), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_J_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_J_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_I_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_I = { UE4CodeGen_Private::EPropertyClass::Int, "I", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelMaterialCollectionTripleIndex, I), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_I_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_I_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_K,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_J,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::NewProp_I,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelMaterialCollectionTripleIndex",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelMaterialCollectionTripleIndex),
		alignof(FVoxelMaterialCollectionTripleIndex),
		Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelMaterialCollectionTripleIndex"), sizeof(FVoxelMaterialCollectionTripleIndex), Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex_CRC() { return 2830765960U; }
class UScriptStruct* FVoxelMaterialCollectionDoubleIndex::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelMaterialCollectionDoubleIndex"), sizeof(FVoxelMaterialCollectionDoubleIndex), Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex(FVoxelMaterialCollectionDoubleIndex::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelMaterialCollectionDoubleIndex"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialCollectionDoubleIndex
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialCollectionDoubleIndex()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelMaterialCollectionDoubleIndex")),new UScriptStruct::TCppStructOps<FVoxelMaterialCollectionDoubleIndex>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelMaterialCollectionDoubleIndex;
	struct Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_J_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_J;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_I_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_I;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelMaterialCollectionDoubleIndex>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::NewProp_J_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::NewProp_J = { UE4CodeGen_Private::EPropertyClass::Int, "J", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelMaterialCollectionDoubleIndex, J), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::NewProp_J_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::NewProp_J_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::NewProp_I_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::NewProp_I = { UE4CodeGen_Private::EPropertyClass::Int, "I", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelMaterialCollectionDoubleIndex, I), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::NewProp_I_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::NewProp_I_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::NewProp_J,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::NewProp_I,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelMaterialCollectionDoubleIndex",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelMaterialCollectionDoubleIndex),
		alignof(FVoxelMaterialCollectionDoubleIndex),
		Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelMaterialCollectionDoubleIndex"), sizeof(FVoxelMaterialCollectionDoubleIndex), Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex_CRC() { return 404396126U; }
	void UVoxelMaterialCollection::StaticRegisterNativesUVoxelMaterialCollection()
	{
	}
	UClass* Z_Construct_UClass_UVoxelMaterialCollection_NoRegister()
	{
		return UVoxelMaterialCollection::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelMaterialCollection_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeneratedTripleMaterialsTess_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_GeneratedTripleMaterialsTess;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GeneratedTripleMaterialsTess_Key_KeyProp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GeneratedTripleMaterialsTess_ValueProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeneratedDoubleMaterialsTess_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_GeneratedDoubleMaterialsTess;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GeneratedDoubleMaterialsTess_Key_KeyProp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GeneratedDoubleMaterialsTess_ValueProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeneratedSingleMaterialsTess_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_GeneratedSingleMaterialsTess;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_GeneratedSingleMaterialsTess_Key_KeyProp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GeneratedSingleMaterialsTess_ValueProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeneratedTripleMaterials_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_GeneratedTripleMaterials;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GeneratedTripleMaterials_Key_KeyProp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GeneratedTripleMaterials_ValueProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeneratedDoubleMaterials_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_GeneratedDoubleMaterials;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GeneratedDoubleMaterials_Key_KeyProp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GeneratedDoubleMaterials_ValueProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeneratedSingleMaterials_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_GeneratedSingleMaterials;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_GeneratedSingleMaterials_Key_KeyProp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GeneratedSingleMaterials_ValueProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PhysicalMaterials_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_PhysicalMaterials;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PhysicalMaterials_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialFunctions_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_MaterialFunctions;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MaterialFunctions_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Materials_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Materials;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Materials_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TripleMaterialTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TripleMaterialTemplate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DoubleMaterialTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DoubleMaterialTemplate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SingleMaterialTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SingleMaterialTemplate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEnableTessellation_MetaData[];
#endif
		static void NewProp_bEnableTessellation_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEnableTessellation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelMaterialCollection_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "VoxelMaterialCollection.h" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterialsTess_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterialsTess = { UE4CodeGen_Private::EPropertyClass::Map, "GeneratedTripleMaterialsTess", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelMaterialCollection, GeneratedTripleMaterialsTess), METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterialsTess_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterialsTess_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterialsTess_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Struct, "GeneratedTripleMaterialsTess_Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterialsTess_ValueProp = { UE4CodeGen_Private::EPropertyClass::Object, "GeneratedTripleMaterialsTess", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 1, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterialsTess_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterialsTess = { UE4CodeGen_Private::EPropertyClass::Map, "GeneratedDoubleMaterialsTess", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelMaterialCollection, GeneratedDoubleMaterialsTess), METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterialsTess_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterialsTess_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterialsTess_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Struct, "GeneratedDoubleMaterialsTess_Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterialsTess_ValueProp = { UE4CodeGen_Private::EPropertyClass::Object, "GeneratedDoubleMaterialsTess", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 1, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterialsTess_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterialsTess = { UE4CodeGen_Private::EPropertyClass::Map, "GeneratedSingleMaterialsTess", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelMaterialCollection, GeneratedSingleMaterialsTess), METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterialsTess_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterialsTess_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterialsTess_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Byte, "GeneratedSingleMaterialsTess_Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterialsTess_ValueProp = { UE4CodeGen_Private::EPropertyClass::Object, "GeneratedSingleMaterialsTess", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 1, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterials_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterials = { UE4CodeGen_Private::EPropertyClass::Map, "GeneratedTripleMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelMaterialCollection, GeneratedTripleMaterials), METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterials_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterials_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterials_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Struct, "GeneratedTripleMaterials_Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelMaterialCollectionTripleIndex, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterials_ValueProp = { UE4CodeGen_Private::EPropertyClass::Object, "GeneratedTripleMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 1, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterials_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterials = { UE4CodeGen_Private::EPropertyClass::Map, "GeneratedDoubleMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelMaterialCollection, GeneratedDoubleMaterials), METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterials_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterials_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterials_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Struct, "GeneratedDoubleMaterials_Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelMaterialCollectionDoubleIndex, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterials_ValueProp = { UE4CodeGen_Private::EPropertyClass::Object, "GeneratedDoubleMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 1, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterials_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterials = { UE4CodeGen_Private::EPropertyClass::Map, "GeneratedSingleMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelMaterialCollection, GeneratedSingleMaterials), METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterials_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterials_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterials_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Byte, "GeneratedSingleMaterials_Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterials_ValueProp = { UE4CodeGen_Private::EPropertyClass::Object, "GeneratedSingleMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 1, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_PhysicalMaterials_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_PhysicalMaterials = { UE4CodeGen_Private::EPropertyClass::Array, "PhysicalMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000020000000, 1, nullptr, STRUCT_OFFSET(UVoxelMaterialCollection, PhysicalMaterials_DEPRECATED), METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_PhysicalMaterials_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_PhysicalMaterials_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_PhysicalMaterials_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "PhysicalMaterials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000020000000, 1, nullptr, 0, Z_Construct_UClass_UPhysicalMaterial_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_MaterialFunctions_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_MaterialFunctions = { UE4CodeGen_Private::EPropertyClass::Array, "MaterialFunctions", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000020000000, 1, nullptr, STRUCT_OFFSET(UVoxelMaterialCollection, MaterialFunctions_DEPRECATED), METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_MaterialFunctions_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_MaterialFunctions_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_MaterialFunctions_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "MaterialFunctions", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000020000000, 1, nullptr, 0, Z_Construct_UClass_UMaterialFunction_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_Materials_MetaData[] = {
		{ "Category", "Layers" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_Materials = { UE4CodeGen_Private::EPropertyClass::Array, "Materials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelMaterialCollection, Materials), METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_Materials_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_Materials_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_Materials_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Materials", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelMaterialCollectionElement, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_TripleMaterialTemplate_MetaData[] = {
		{ "Category", "Templates" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_TripleMaterialTemplate = { UE4CodeGen_Private::EPropertyClass::Object, "TripleMaterialTemplate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelMaterialCollection, TripleMaterialTemplate), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_TripleMaterialTemplate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_TripleMaterialTemplate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_DoubleMaterialTemplate_MetaData[] = {
		{ "Category", "Templates" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_DoubleMaterialTemplate = { UE4CodeGen_Private::EPropertyClass::Object, "DoubleMaterialTemplate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelMaterialCollection, DoubleMaterialTemplate), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_DoubleMaterialTemplate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_DoubleMaterialTemplate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_SingleMaterialTemplate_MetaData[] = {
		{ "Category", "Templates" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_SingleMaterialTemplate = { UE4CodeGen_Private::EPropertyClass::Object, "SingleMaterialTemplate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelMaterialCollection, SingleMaterialTemplate), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_SingleMaterialTemplate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_SingleMaterialTemplate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_bEnableTessellation_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/VoxelMaterialCollection.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_bEnableTessellation_SetBit(void* Obj)
	{
		((UVoxelMaterialCollection*)Obj)->bEnableTessellation = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_bEnableTessellation = { UE4CodeGen_Private::EPropertyClass::Bool, "bEnableTessellation", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelMaterialCollection), &Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_bEnableTessellation_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_bEnableTessellation_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_bEnableTessellation_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelMaterialCollection_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterialsTess,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterialsTess_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterialsTess_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterialsTess,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterialsTess_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterialsTess_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterialsTess,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterialsTess_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterialsTess_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterials,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterials_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedTripleMaterials_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterials,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterials_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedDoubleMaterials_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterials,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterials_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_GeneratedSingleMaterials_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_PhysicalMaterials,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_PhysicalMaterials_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_MaterialFunctions,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_MaterialFunctions_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_Materials,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_Materials_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_TripleMaterialTemplate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_DoubleMaterialTemplate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_SingleMaterialTemplate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelMaterialCollection_Statics::NewProp_bEnableTessellation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelMaterialCollection_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelMaterialCollection>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelMaterialCollection_Statics::ClassParams = {
		&UVoxelMaterialCollection::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelMaterialCollection_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelMaterialCollection_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelMaterialCollection_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelMaterialCollection()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelMaterialCollection_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelMaterialCollection, 4155385909);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelMaterialCollection(Z_Construct_UClass_UVoxelMaterialCollection, &UVoxelMaterialCollection::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelMaterialCollection"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelMaterialCollection);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
