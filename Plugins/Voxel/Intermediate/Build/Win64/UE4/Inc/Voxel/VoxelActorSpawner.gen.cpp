// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelSpawners/VoxelActorSpawner.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelActorSpawner() {}
// Cross Module References
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelActorGroupId();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelActorGroup_NoRegister();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelActorConfig();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelDefaultSpawner();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UHierarchicalInstancedStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelActor_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelActorGroup();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelActorSpawner_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelActorSpawner();
// End Cross Module References
class UScriptStruct* FVoxelActorGroupId::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelActorGroupId_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelActorGroupId, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelActorGroupId"), sizeof(FVoxelActorGroupId), Get_Z_Construct_UScriptStruct_FVoxelActorGroupId_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelActorGroupId(FVoxelActorGroupId::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelActorGroupId"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelActorGroupId
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelActorGroupId()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelActorGroupId")),new UScriptStruct::TCppStructOps<FVoxelActorGroupId>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelActorGroupId;
	struct Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActorGroup_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActorGroup;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActorId_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ActorId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelActorGroupId>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::NewProp_ActorGroup_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::NewProp_ActorGroup = { UE4CodeGen_Private::EPropertyClass::Object, "ActorGroup", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelActorGroupId, ActorGroup), Z_Construct_UClass_UVoxelActorGroup_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::NewProp_ActorGroup_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::NewProp_ActorGroup_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::NewProp_ActorId_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::NewProp_ActorId = { UE4CodeGen_Private::EPropertyClass::Byte, "ActorId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelActorGroupId, ActorId), nullptr, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::NewProp_ActorId_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::NewProp_ActorId_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::NewProp_ActorGroup,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::NewProp_ActorId,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelActorGroupId",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FVoxelActorGroupId),
		alignof(FVoxelActorGroupId),
		Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelActorGroupId()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelActorGroupId_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelActorGroupId"), sizeof(FVoxelActorGroupId), Get_Z_Construct_UScriptStruct_FVoxelActorGroupId_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelActorGroupId_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelActorGroupId_CRC() { return 2280954736U; }
class UScriptStruct* FVoxelActorConfig::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelActorConfig_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelActorConfig, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelActorConfig"), sizeof(FVoxelActorConfig), Get_Z_Construct_UScriptStruct_FVoxelActorConfig_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelActorConfig(FVoxelActorConfig::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelActorConfig"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelActorConfig
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelActorConfig()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelActorConfig")),new UScriptStruct::TCppStructOps<FVoxelActorConfig>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelActorConfig;
	struct Z_Construct_UScriptStruct_FVoxelActorConfig_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RotationOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RotationOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScaleOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ScaleOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PositionOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PositionOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HISMEndCullDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_HISMEndCullDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HISMStartCullDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_HISMStartCullDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HISMTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_HISMTemplate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bSpawnActorAndNotImposterMesh_MetaData[];
#endif
		static void NewProp_bSpawnActorAndNotImposterMesh_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSpawnActorAndNotImposterMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bOnlyCheckVoxelsAtPositionForOverlap_MetaData[];
#endif
		static void NewProp_bOnlyCheckVoxelsAtPositionForOverlap_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bOnlyCheckVoxelsAtPositionForOverlap;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Actor_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Actor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseActorClass_MetaData[];
#endif
		static void NewProp_bUseActorClass_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseActorClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelActorConfig>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_RotationOffset_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_RotationOffset = { UE4CodeGen_Private::EPropertyClass::Struct, "RotationOffset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelActorConfig, RotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_RotationOffset_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_RotationOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_ScaleOffset_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_ScaleOffset = { UE4CodeGen_Private::EPropertyClass::Struct, "ScaleOffset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelActorConfig, ScaleOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_ScaleOffset_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_ScaleOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_PositionOffset_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_PositionOffset = { UE4CodeGen_Private::EPropertyClass::Struct, "PositionOffset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelActorConfig, PositionOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_PositionOffset_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_PositionOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMEndCullDistance_MetaData[] = {
		{ "Category", "Instance Config" },
		{ "DisplayName", "HISM End Cull Distance" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMEndCullDistance = { UE4CodeGen_Private::EPropertyClass::Int, "HISMEndCullDistance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelActorConfig, HISMEndCullDistance), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMEndCullDistance_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMEndCullDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMStartCullDistance_MetaData[] = {
		{ "Category", "Instance Config" },
		{ "DisplayName", "HISM Start Cull Distance" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMStartCullDistance = { UE4CodeGen_Private::EPropertyClass::Int, "HISMStartCullDistance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelActorConfig, HISMStartCullDistance), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMStartCullDistance_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMStartCullDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMTemplate_MetaData[] = {
		{ "Category", "Instance Config" },
		{ "DisplayName", "HISM Template" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
		{ "ToolTip", "If you want to edit the HISM properties create a BP inheriting from HierarchicalInstancedStaticMeshComponent and set it here" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMTemplate = { UE4CodeGen_Private::EPropertyClass::Class, "HISMTemplate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0014000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelActorConfig, HISMTemplate), Z_Construct_UClass_UHierarchicalInstancedStaticMeshComponent_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMTemplate_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMTemplate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bSpawnActorAndNotImposterMesh_MetaData[] = {
		{ "Category", "Actor Config" },
		{ "EditCondition", "bUseActorClass" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bSpawnActorAndNotImposterMesh_SetBit(void* Obj)
	{
		((FVoxelActorConfig*)Obj)->bSpawnActorAndNotImposterMesh = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bSpawnActorAndNotImposterMesh = { UE4CodeGen_Private::EPropertyClass::Bool, "bSpawnActorAndNotImposterMesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FVoxelActorConfig), &Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bSpawnActorAndNotImposterMesh_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bSpawnActorAndNotImposterMesh_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bSpawnActorAndNotImposterMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bOnlyCheckVoxelsAtPositionForOverlap_MetaData[] = {
		{ "Category", "Actor Config" },
		{ "EditCondition", "bUseActorClass" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
		{ "ToolTip", "If false more precise but way more expensive" },
	};
#endif
	void Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bOnlyCheckVoxelsAtPositionForOverlap_SetBit(void* Obj)
	{
		((FVoxelActorConfig*)Obj)->bOnlyCheckVoxelsAtPositionForOverlap = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bOnlyCheckVoxelsAtPositionForOverlap = { UE4CodeGen_Private::EPropertyClass::Bool, "bOnlyCheckVoxelsAtPositionForOverlap", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FVoxelActorConfig), &Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bOnlyCheckVoxelsAtPositionForOverlap_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bOnlyCheckVoxelsAtPositionForOverlap_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bOnlyCheckVoxelsAtPositionForOverlap_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "Config" },
		{ "EditCondition", "!bUseActorClass" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_Mesh = { UE4CodeGen_Private::EPropertyClass::Object, "Mesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelActorConfig, Mesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_Mesh_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_Mesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_Actor_MetaData[] = {
		{ "Category", "Config" },
		{ "EditCondition", "bUseActorClass" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Class, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0014000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelActorConfig, Actor), Z_Construct_UClass_AVoxelActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_Actor_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_Actor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bUseActorClass_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bUseActorClass_SetBit(void* Obj)
	{
		((FVoxelActorConfig*)Obj)->bUseActorClass = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bUseActorClass = { UE4CodeGen_Private::EPropertyClass::Bool, "bUseActorClass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FVoxelActorConfig), &Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bUseActorClass_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bUseActorClass_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bUseActorClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_RotationOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_ScaleOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_PositionOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMEndCullDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMStartCullDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_HISMTemplate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bSpawnActorAndNotImposterMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bOnlyCheckVoxelsAtPositionForOverlap,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_Mesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_Actor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::NewProp_bUseActorClass,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		Z_Construct_UScriptStruct_FVoxelDefaultSpawner,
		&NewStructOps,
		"VoxelActorConfig",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelActorConfig),
		alignof(FVoxelActorConfig),
		Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelActorConfig()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelActorConfig_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelActorConfig"), sizeof(FVoxelActorConfig), Get_Z_Construct_UScriptStruct_FVoxelActorConfig_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelActorConfig_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelActorConfig_CRC() { return 3105568164U; }
	void UVoxelActorGroup::StaticRegisterNativesUVoxelActorGroup()
	{
	}
	UClass* Z_Construct_UClass_UVoxelActorGroup_NoRegister()
	{
		return UVoxelActorGroup::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelActorGroup_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActorConfigs_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ActorConfigs;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ActorConfigs_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelActorGroup_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelActorGroup_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelSpawners/VoxelActorSpawner.h" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelActorGroup_Statics::NewProp_ActorConfigs_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelActorGroup_Statics::NewProp_ActorConfigs = { UE4CodeGen_Private::EPropertyClass::Array, "ActorConfigs", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelActorGroup, ActorConfigs), METADATA_PARAMS(Z_Construct_UClass_UVoxelActorGroup_Statics::NewProp_ActorConfigs_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelActorGroup_Statics::NewProp_ActorConfigs_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelActorGroup_Statics::NewProp_ActorConfigs_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ActorConfigs", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelActorConfig, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelActorGroup_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelActorGroup_Statics::NewProp_ActorConfigs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelActorGroup_Statics::NewProp_ActorConfigs_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelActorGroup_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelActorGroup>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelActorGroup_Statics::ClassParams = {
		&UVoxelActorGroup::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelActorGroup_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelActorGroup_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelActorGroup_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelActorGroup_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelActorGroup()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelActorGroup_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelActorGroup, 2105717249);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelActorGroup(Z_Construct_UClass_UVoxelActorGroup, &UVoxelActorGroup::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelActorGroup"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelActorGroup);
	void UVoxelActorSpawner::StaticRegisterNativesUVoxelActorSpawner()
	{
	}
	UClass* Z_Construct_UClass_UVoxelActorSpawner_NoRegister()
	{
		return UVoxelActorSpawner::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelActorSpawner_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActorGroups_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_ActorGroups;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ActorGroups_Key_KeyProp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActorGroups_ValueProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActorGroupIds_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ActorGroupIds;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ActorGroupIds_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelActorSpawner_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelActorSpawner_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelSpawners/VoxelActorSpawner.h" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroups_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroups = { UE4CodeGen_Private::EPropertyClass::Map, "ActorGroups", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000020000000, 1, nullptr, STRUCT_OFFSET(UVoxelActorSpawner, ActorGroups_DEPRECATED), METADATA_PARAMS(Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroups_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroups_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroups_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Byte, "ActorGroups_Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroups_ValueProp = { UE4CodeGen_Private::EPropertyClass::Object, "ActorGroups", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000020000000, 1, nullptr, 1, Z_Construct_UClass_UVoxelActorGroup_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroupIds_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActorSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroupIds = { UE4CodeGen_Private::EPropertyClass::Array, "ActorGroupIds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelActorSpawner, ActorGroupIds), METADATA_PARAMS(Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroupIds_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroupIds_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroupIds_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ActorGroupIds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelActorGroupId, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelActorSpawner_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroups,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroups_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroups_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroupIds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelActorSpawner_Statics::NewProp_ActorGroupIds_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelActorSpawner_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelActorSpawner>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelActorSpawner_Statics::ClassParams = {
		&UVoxelActorSpawner::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelActorSpawner_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelActorSpawner_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelActorSpawner_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelActorSpawner_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelActorSpawner()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelActorSpawner_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelActorSpawner, 623618399);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelActorSpawner(Z_Construct_UClass_UVoxelActorSpawner, &UVoxelActorSpawner::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelActorSpawner"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelActorSpawner);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
