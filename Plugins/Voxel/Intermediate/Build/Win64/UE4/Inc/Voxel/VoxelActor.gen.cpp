// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelSpawners/VoxelActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelActor() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_AVoxelActor_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UFunction* Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AVoxelActor::StaticRegisterNativesAVoxelActor()
	{
		UClass* Class = AVoxelActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "IsOverlappingVoxelWorld", &AVoxelActor::execIsOverlappingVoxelWorld },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics
	{
		struct VoxelActor_eventIsOverlappingVoxelWorld_Parms
		{
			AVoxelWorld* World;
			bool bOnlyCheckVoxelsAtPositionForOverlap;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static void NewProp_bOnlyCheckVoxelsAtPositionForOverlap_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bOnlyCheckVoxelsAtPositionForOverlap;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VoxelActor_eventIsOverlappingVoxelWorld_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelActor_eventIsOverlappingVoxelWorld_Parms), &Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::NewProp_bOnlyCheckVoxelsAtPositionForOverlap_SetBit(void* Obj)
	{
		((VoxelActor_eventIsOverlappingVoxelWorld_Parms*)Obj)->bOnlyCheckVoxelsAtPositionForOverlap = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::NewProp_bOnlyCheckVoxelsAtPositionForOverlap = { UE4CodeGen_Private::EPropertyClass::Bool, "bOnlyCheckVoxelsAtPositionForOverlap", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelActor_eventIsOverlappingVoxelWorld_Parms), &Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::NewProp_bOnlyCheckVoxelsAtPositionForOverlap_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelActor_eventIsOverlappingVoxelWorld_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::NewProp_bOnlyCheckVoxelsAtPositionForOverlap,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelActor, "IsOverlappingVoxelWorld", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VoxelActor_eventIsOverlappingVoxelWorld_Parms), Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AVoxelActor_NoRegister()
	{
		return AVoxelActor::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshLODToUseForOverlapDetection_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MeshLODToUseForOverlapDetection;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVoxelActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVoxelActor_IsOverlappingVoxelWorld, "IsOverlappingVoxelWorld" }, // 4128804446
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelSpawners/VoxelActor.h" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelActor_Statics::NewProp_MeshLODToUseForOverlapDetection_MetaData[] = {
		{ "Category", "Voxel Actor Config" },
		{ "ClampMin", "0" },
		{ "DisplayName", "Mesh LOD To Use For Overlap Detection" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActor.h" },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelActor_Statics::NewProp_MeshLODToUseForOverlapDetection = { UE4CodeGen_Private::EPropertyClass::Int, "MeshLODToUseForOverlapDetection", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010001, 1, nullptr, STRUCT_OFFSET(AVoxelActor, MeshLODToUseForOverlapDetection), METADATA_PARAMS(Z_Construct_UClass_AVoxelActor_Statics::NewProp_MeshLODToUseForOverlapDetection_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelActor_Statics::NewProp_MeshLODToUseForOverlapDetection_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelActor_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "Voxel Actor Config" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelSpawners/VoxelActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelActor_Statics::NewProp_Mesh = { UE4CodeGen_Private::EPropertyClass::Object, "Mesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(AVoxelActor, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelActor_Statics::NewProp_Mesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelActor_Statics::NewProp_Mesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelActor_Statics::NewProp_MeshLODToUseForOverlapDetection,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelActor_Statics::NewProp_Mesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelActor_Statics::ClassParams = {
		&AVoxelActor::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AVoxelActor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelActor_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelActor_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelActor, 2504312459);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelActor(Z_Construct_UClass_AVoxelActor, &AVoxelActor::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
