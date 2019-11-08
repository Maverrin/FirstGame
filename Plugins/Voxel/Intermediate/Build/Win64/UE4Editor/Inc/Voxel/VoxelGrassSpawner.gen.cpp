// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelSpawners/VoxelGrassSpawner.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelGrassSpawner() {}
// Cross Module References
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelGrassTypeId();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGrassGroup_NoRegister();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelGrassVariety();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelDefaultSpawner();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FLightingChannels();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGrassGroup();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGrassSpawner_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGrassSpawner();
// End Cross Module References
class UScriptStruct* FVoxelGrassTypeId::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelGrassTypeId_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelGrassTypeId, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelGrassTypeId"), sizeof(FVoxelGrassTypeId), Get_Z_Construct_UScriptStruct_FVoxelGrassTypeId_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelGrassTypeId(FVoxelGrassTypeId::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelGrassTypeId"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelGrassTypeId
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelGrassTypeId()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelGrassTypeId")),new UScriptStruct::TCppStructOps<FVoxelGrassTypeId>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelGrassTypeId;
	struct Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GrassGroup_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GrassGroup;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GrassId_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_GrassId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelGrassTypeId>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::NewProp_GrassGroup_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::NewProp_GrassGroup = { UE4CodeGen_Private::EPropertyClass::Object, "GrassGroup", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelGrassTypeId, GrassGroup), Z_Construct_UClass_UVoxelGrassGroup_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::NewProp_GrassGroup_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::NewProp_GrassGroup_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::NewProp_GrassId_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::NewProp_GrassId = { UE4CodeGen_Private::EPropertyClass::Byte, "GrassId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelGrassTypeId, GrassId), nullptr, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::NewProp_GrassId_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::NewProp_GrassId_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::NewProp_GrassGroup,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::NewProp_GrassId,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelGrassTypeId",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FVoxelGrassTypeId),
		alignof(FVoxelGrassTypeId),
		Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelGrassTypeId()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelGrassTypeId_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelGrassTypeId"), sizeof(FVoxelGrassTypeId), Get_Z_Construct_UScriptStruct_FVoxelGrassTypeId_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelGrassTypeId_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelGrassTypeId_CRC() { return 522296777U; }
class UScriptStruct* FVoxelGrassVariety::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelGrassVariety_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelGrassVariety, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelGrassVariety"), sizeof(FVoxelGrassVariety), Get_Z_Construct_UScriptStruct_FVoxelGrassVariety_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelGrassVariety(FVoxelGrassVariety::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelGrassVariety"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelGrassVariety
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelGrassVariety()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelGrassVariety")),new UScriptStruct::TCppStructOps<FVoxelGrassVariety>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelGrassVariety;
	struct Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCastDynamicShadow_MetaData[];
#endif
		static void NewProp_bCastDynamicShadow_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCastDynamicShadow;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bReceivesDecals_MetaData[];
#endif
		static void NewProp_bReceivesDecals_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bReceivesDecals;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LightingChannels_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LightingChannels;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinLOD_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MinLOD;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EndCullDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_EndCullDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StartCullDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_StartCullDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GrassMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GrassMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelGrassVariety>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bCastDynamicShadow_MetaData[] = {
		{ "Category", "Grass Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
		{ "ToolTip", "Whether the grass should cast shadows when using non-precomputed shadowing. *" },
	};
#endif
	void Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bCastDynamicShadow_SetBit(void* Obj)
	{
		((FVoxelGrassVariety*)Obj)->bCastDynamicShadow = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bCastDynamicShadow = { UE4CodeGen_Private::EPropertyClass::Bool, "bCastDynamicShadow", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FVoxelGrassVariety), &Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bCastDynamicShadow_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bCastDynamicShadow_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bCastDynamicShadow_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bReceivesDecals_MetaData[] = {
		{ "Category", "Grass Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
		{ "ToolTip", "Whether the grass instances should receive decals." },
	};
#endif
	void Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bReceivesDecals_SetBit(void* Obj)
	{
		((FVoxelGrassVariety*)Obj)->bReceivesDecals = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bReceivesDecals = { UE4CodeGen_Private::EPropertyClass::Bool, "bReceivesDecals", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FVoxelGrassVariety), &Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bReceivesDecals_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bReceivesDecals_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bReceivesDecals_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_LightingChannels_MetaData[] = {
		{ "Category", "Grass Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
		{ "ToolTip", "Lighting channels that the grass will be assigned. Lights with matching channels will affect the grass.\nThese channels only apply to opaque materials, direct lighting, and dynamic lighting and shadowing." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_LightingChannels = { UE4CodeGen_Private::EPropertyClass::Struct, "LightingChannels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000001, 1, nullptr, STRUCT_OFFSET(FVoxelGrassVariety, LightingChannels), Z_Construct_UScriptStruct_FLightingChannels, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_LightingChannels_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_LightingChannels_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_MinLOD_MetaData[] = {
		{ "Category", "Grass Config" },
		{ "ClampMax", "8" },
		{ "ClampMin", "-1" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
		{ "ToolTip", "Specifies the smallest LOD that will be used for this component.\nIf -1 (default), the MinLOD of the static mesh asset will be used instead." },
		{ "UIMax", "8" },
		{ "UIMin", "-1" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_MinLOD = { UE4CodeGen_Private::EPropertyClass::Int, "MinLOD", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelGrassVariety, MinLOD), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_MinLOD_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_MinLOD_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_EndCullDistance_MetaData[] = {
		{ "Category", "Grass Config" },
		{ "ClampMax", "1000000" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
		{ "ToolTip", "The distance where instances will have completely faded out when using a PerInstanceFadeAmount material node. 0 disables.\nWhen the entire cluster is beyond this distance, the cluster is completely culled and not rendered at all." },
		{ "UIMax", "1000000" },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_EndCullDistance = { UE4CodeGen_Private::EPropertyClass::Int, "EndCullDistance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelGrassVariety, EndCullDistance), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_EndCullDistance_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_EndCullDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_StartCullDistance_MetaData[] = {
		{ "Category", "Grass Config" },
		{ "ClampMax", "1000000" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
		{ "ToolTip", "The distance where instances will begin to fade out if using a PerInstanceFadeAmount material node. 0 disables." },
		{ "UIMax", "1000000" },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_StartCullDistance = { UE4CodeGen_Private::EPropertyClass::Int, "StartCullDistance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelGrassVariety, StartCullDistance), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_StartCullDistance_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_StartCullDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_GrassMesh_MetaData[] = {
		{ "Category", "Grass Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_GrassMesh = { UE4CodeGen_Private::EPropertyClass::Object, "GrassMesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelGrassVariety, GrassMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_GrassMesh_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_GrassMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bCastDynamicShadow,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_bReceivesDecals,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_LightingChannels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_MinLOD,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_EndCullDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_StartCullDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::NewProp_GrassMesh,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		Z_Construct_UScriptStruct_FVoxelDefaultSpawner,
		&NewStructOps,
		"VoxelGrassVariety",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelGrassVariety),
		alignof(FVoxelGrassVariety),
		Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelGrassVariety()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelGrassVariety_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelGrassVariety"), sizeof(FVoxelGrassVariety), Get_Z_Construct_UScriptStruct_FVoxelGrassVariety_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelGrassVariety_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelGrassVariety_CRC() { return 3096868081U; }
	void UVoxelGrassGroup::StaticRegisterNativesUVoxelGrassGroup()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGrassGroup_NoRegister()
	{
		return UVoxelGrassGroup::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGrassGroup_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GrassVarieties_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_GrassVarieties;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GrassVarieties_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGrassGroup_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGrassGroup_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelSpawners/VoxelGrassSpawner.h" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGrassGroup_Statics::NewProp_GrassVarieties_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelGrassGroup_Statics::NewProp_GrassVarieties = { UE4CodeGen_Private::EPropertyClass::Array, "GrassVarieties", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGrassGroup, GrassVarieties), METADATA_PARAMS(Z_Construct_UClass_UVoxelGrassGroup_Statics::NewProp_GrassVarieties_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGrassGroup_Statics::NewProp_GrassVarieties_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelGrassGroup_Statics::NewProp_GrassVarieties_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "GrassVarieties", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelGrassVariety, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelGrassGroup_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGrassGroup_Statics::NewProp_GrassVarieties,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGrassGroup_Statics::NewProp_GrassVarieties_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGrassGroup_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGrassGroup>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGrassGroup_Statics::ClassParams = {
		&UVoxelGrassGroup::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelGrassGroup_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelGrassGroup_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGrassGroup_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGrassGroup_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGrassGroup()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGrassGroup_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGrassGroup, 3270535335);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGrassGroup(Z_Construct_UClass_UVoxelGrassGroup, &UVoxelGrassGroup::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelGrassGroup"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGrassGroup);
	void UVoxelGrassSpawner::StaticRegisterNativesUVoxelGrassSpawner()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGrassSpawner_NoRegister()
	{
		return UVoxelGrassSpawner::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGrassSpawner_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GrassTypes_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_GrassTypes;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_GrassTypes_Key_KeyProp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GrassTypes_ValueProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GrassTypeIds_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_GrassTypeIds;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GrassTypeIds_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGrassSpawner_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGrassSpawner_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelSpawners/VoxelGrassSpawner.h" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypes_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypes = { UE4CodeGen_Private::EPropertyClass::Map, "GrassTypes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000020000000, 1, nullptr, STRUCT_OFFSET(UVoxelGrassSpawner, GrassTypes_DEPRECATED), METADATA_PARAMS(Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypes_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypes_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypes_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Byte, "GrassTypes_Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypes_ValueProp = { UE4CodeGen_Private::EPropertyClass::Object, "GrassTypes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000020000000, 1, nullptr, 1, Z_Construct_UClass_UVoxelGrassGroup_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypeIds_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelGrassSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypeIds = { UE4CodeGen_Private::EPropertyClass::Array, "GrassTypeIds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGrassSpawner, GrassTypeIds), METADATA_PARAMS(Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypeIds_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypeIds_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypeIds_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "GrassTypeIds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelGrassTypeId, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelGrassSpawner_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypes_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypes_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypeIds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGrassSpawner_Statics::NewProp_GrassTypeIds_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGrassSpawner_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGrassSpawner>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGrassSpawner_Statics::ClassParams = {
		&UVoxelGrassSpawner::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelGrassSpawner_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelGrassSpawner_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGrassSpawner_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGrassSpawner_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGrassSpawner()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGrassSpawner_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGrassSpawner, 3830237492);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGrassSpawner(Z_Construct_UClass_UVoxelGrassSpawner, &UVoxelGrassSpawner::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelGrassSpawner"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGrassSpawner);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
