// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelSpawners/VoxelDefaultSpawner.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelDefaultSpawner() {}
// Cross Module References
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelSpawnerRotation();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelSpawnerScaling();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelDefaultSpawner();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FFloatInterval();
// End Cross Module References
	static UEnum* EVoxelSpawnerRotation_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelSpawnerRotation, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelSpawnerRotation"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelSpawnerRotation(EVoxelSpawnerRotation_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelSpawnerRotation"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelSpawnerRotation_CRC() { return 3968686872U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelSpawnerRotation()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelSpawnerRotation"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelSpawnerRotation_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelSpawnerRotation::AlignToSurface", (int64)EVoxelSpawnerRotation::AlignToSurface },
				{ "EVoxelSpawnerRotation::AlignToWorldUp", (int64)EVoxelSpawnerRotation::AlignToWorldUp },
				{ "EVoxelSpawnerRotation::DontAlign", (int64)EVoxelSpawnerRotation::DontAlign },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelDefaultSpawner.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelSpawnerRotation",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelSpawnerRotation",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EVoxelSpawnerScaling_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelSpawnerScaling, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelSpawnerScaling"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelSpawnerScaling(EVoxelSpawnerScaling_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelSpawnerScaling"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelSpawnerScaling_CRC() { return 3384958805U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelSpawnerScaling()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelSpawnerScaling"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelSpawnerScaling_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelSpawnerScaling::Uniform", (int64)EVoxelSpawnerScaling::Uniform },
				{ "EVoxelSpawnerScaling::Free", (int64)EVoxelSpawnerScaling::Free },
				{ "EVoxelSpawnerScaling::LockXY", (int64)EVoxelSpawnerScaling::LockXY },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Free.ToolTip", "Grass instances will have random X, Y and Z scales." },
				{ "LockXY.ToolTip", "X and Y will be the same random scale, Z will be another" },
				{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelDefaultSpawner.h" },
				{ "Uniform.ToolTip", "Grass instances will have uniform X, Y and Z scales." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelSpawnerScaling",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelSpawnerScaling",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FVoxelDefaultSpawner::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelDefaultSpawner_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelDefaultSpawner, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelDefaultSpawner"), sizeof(FVoxelDefaultSpawner), Get_Z_Construct_UScriptStruct_FVoxelDefaultSpawner_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelDefaultSpawner(FVoxelDefaultSpawner::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelDefaultSpawner"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelDefaultSpawner
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelDefaultSpawner()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelDefaultSpawner")),new UScriptStruct::TCppStructOps<FVoxelDefaultSpawner>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelDefaultSpawner;
	struct Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxAngleWithWorldUp_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxAngleWithWorldUp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinAngleWithWorldUp_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MinAngleWithWorldUp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RotationAlignment_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_RotationAlignment;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_RotationAlignment_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RandomRotation_MetaData[];
#endif
		static void NewProp_RandomRotation_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_RandomRotation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScaleZ_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ScaleZ;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScaleY_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ScaleY;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScaleX_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ScaleX;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Scaling_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Scaling;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Scaling_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Density_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Density;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Seed_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Seed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelDefaultSpawner.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelDefaultSpawner>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_MaxAngleWithWorldUp_MetaData[] = {
		{ "Category", "Spawn settings" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelDefaultSpawner.h" },
		{ "ToolTip", "Max angle between object up vector and world generator up vector in degrees" },
		{ "UIMax", "180" },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_MaxAngleWithWorldUp = { UE4CodeGen_Private::EPropertyClass::Float, "MaxAngleWithWorldUp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelDefaultSpawner, MaxAngleWithWorldUp), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_MaxAngleWithWorldUp_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_MaxAngleWithWorldUp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_MinAngleWithWorldUp_MetaData[] = {
		{ "Category", "Spawn settings" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelDefaultSpawner.h" },
		{ "ToolTip", "Min angle between object up vector and world generator up vector in degrees" },
		{ "UIMax", "180" },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_MinAngleWithWorldUp = { UE4CodeGen_Private::EPropertyClass::Float, "MinAngleWithWorldUp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelDefaultSpawner, MinAngleWithWorldUp), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_MinAngleWithWorldUp_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_MinAngleWithWorldUp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RotationAlignment_MetaData[] = {
		{ "Category", "Spawn settings" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelDefaultSpawner.h" },
		{ "ToolTip", "Whether the actor instances should be tilted to the normal of the landscape (true), or always vertical (false)" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RotationAlignment = { UE4CodeGen_Private::EPropertyClass::Enum, "RotationAlignment", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelDefaultSpawner, RotationAlignment), Z_Construct_UEnum_Voxel_EVoxelSpawnerRotation, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RotationAlignment_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RotationAlignment_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RotationAlignment_Underlying = { UE4CodeGen_Private::EPropertyClass::Int, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RandomRotation_MetaData[] = {
		{ "Category", "Spawn settings" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelDefaultSpawner.h" },
		{ "ToolTip", "Whether the actor instances should be placed at random rotation (true) or all at the same rotation (false)" },
	};
#endif
	void Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RandomRotation_SetBit(void* Obj)
	{
		((FVoxelDefaultSpawner*)Obj)->RandomRotation = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RandomRotation = { UE4CodeGen_Private::EPropertyClass::Bool, "RandomRotation", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FVoxelDefaultSpawner), &Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RandomRotation_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RandomRotation_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RandomRotation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleZ_MetaData[] = {
		{ "Category", "Spawn settings" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelDefaultSpawner.h" },
		{ "ToolTip", "Specifies the range of scale, from minimum to maximum, to apply to an actor instance's Z Scale property" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleZ = { UE4CodeGen_Private::EPropertyClass::Struct, "ScaleZ", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelDefaultSpawner, ScaleZ), Z_Construct_UScriptStruct_FFloatInterval, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleZ_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleZ_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleY_MetaData[] = {
		{ "Category", "Spawn settings" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelDefaultSpawner.h" },
		{ "ToolTip", "Specifies the range of scale, from minimum to maximum, to apply to an actor instance's Y Scale property" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleY = { UE4CodeGen_Private::EPropertyClass::Struct, "ScaleY", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelDefaultSpawner, ScaleY), Z_Construct_UScriptStruct_FFloatInterval, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleY_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleY_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleX_MetaData[] = {
		{ "Category", "Spawn settings" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelDefaultSpawner.h" },
		{ "ToolTip", "Specifies the range of scale, from minimum to maximum, to apply to an actor instance's X Scale property" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleX = { UE4CodeGen_Private::EPropertyClass::Struct, "ScaleX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelDefaultSpawner, ScaleX), Z_Construct_UScriptStruct_FFloatInterval, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleX_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleX_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Scaling_MetaData[] = {
		{ "Category", "Spawn settings" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelDefaultSpawner.h" },
		{ "ToolTip", "Specifies instance scaling type" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Scaling = { UE4CodeGen_Private::EPropertyClass::Enum, "Scaling", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelDefaultSpawner, Scaling), Z_Construct_UEnum_Voxel_EVoxelSpawnerScaling, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Scaling_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Scaling_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Scaling_Underlying = { UE4CodeGen_Private::EPropertyClass::Int, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Density_MetaData[] = {
		{ "Category", "Spawn settings" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelDefaultSpawner.h" },
		{ "ToolTip", "Instances per 10 square meters." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Density = { UE4CodeGen_Private::EPropertyClass::Float, "Density", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelDefaultSpawner, Density), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Density_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Density_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Seed_MetaData[] = {
		{ "Category", "Grass" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelDefaultSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Seed = { UE4CodeGen_Private::EPropertyClass::Int, "Seed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelDefaultSpawner, Seed), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Seed_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Seed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_MaxAngleWithWorldUp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_MinAngleWithWorldUp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RotationAlignment,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RotationAlignment_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_RandomRotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_ScaleX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Scaling,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Scaling_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Density,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::NewProp_Seed,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelDefaultSpawner",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FVoxelDefaultSpawner),
		alignof(FVoxelDefaultSpawner),
		Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelDefaultSpawner()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelDefaultSpawner_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelDefaultSpawner"), sizeof(FVoxelDefaultSpawner), Get_Z_Construct_UScriptStruct_FVoxelDefaultSpawner_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelDefaultSpawner_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelDefaultSpawner_CRC() { return 3491891696U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
