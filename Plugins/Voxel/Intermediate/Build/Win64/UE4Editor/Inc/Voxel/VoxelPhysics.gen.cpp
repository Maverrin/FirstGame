// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelTools/VoxelPhysics.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelPhysics() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelPhysicsTools_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelPhysicsTools();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelPart_NoRegister();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FIntBox();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FLatentActionInfo();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	void UVoxelPhysicsTools::StaticRegisterNativesUVoxelPhysicsTools()
	{
		UClass* Class = UVoxelPhysicsTools::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "RemoveFloatingBlocks", &UVoxelPhysicsTools::execRemoveFloatingBlocks },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics
	{
		struct VoxelPhysicsTools_eventRemoveFloatingBlocks_Parms
		{
			UObject* WorldContextObject;
			FLatentActionInfo LatentInfo;
			TArray<AVoxelPart*> SpawnedActors;
			AVoxelWorld* World;
			FIntBox Bounds;
			TSubclassOf<AVoxelPart>  ClassToSpawn;
		};
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ClassToSpawn;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Bounds_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Bounds;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SpawnedActors;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpawnedActors_Inner;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_ClassToSpawn = { UE4CodeGen_Private::EPropertyClass::Class, "ClassToSpawn", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0014000000000080, 1, nullptr, STRUCT_OFFSET(VoxelPhysicsTools_eventRemoveFloatingBlocks_Parms, ClassToSpawn), Z_Construct_UClass_AVoxelPart_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_Bounds_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_Bounds = { UE4CodeGen_Private::EPropertyClass::Struct, "Bounds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelPhysicsTools_eventRemoveFloatingBlocks_Parms, Bounds), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_Bounds_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_Bounds_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelPhysicsTools_eventRemoveFloatingBlocks_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_SpawnedActors = { UE4CodeGen_Private::EPropertyClass::Array, "SpawnedActors", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelPhysicsTools_eventRemoveFloatingBlocks_Parms, SpawnedActors), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_SpawnedActors_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "SpawnedActors", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_AVoxelPart_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_LatentInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "LatentInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelPhysicsTools_eventRemoveFloatingBlocks_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelPhysicsTools_eventRemoveFloatingBlocks_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_ClassToSpawn,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_Bounds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_World,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_SpawnedActors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_SpawnedActors_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_LatentInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelPhysics.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelPhysicsTools, "RemoveFloatingBlocks", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(VoxelPhysicsTools_eventRemoveFloatingBlocks_Parms), Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelPhysicsTools_NoRegister()
	{
		return UVoxelPhysicsTools::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelPhysicsTools_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelPhysicsTools_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelPhysicsTools_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelPhysicsTools_RemoveFloatingBlocks, "RemoveFloatingBlocks" }, // 3535954831
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelPhysicsTools_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelTools/VoxelPhysics.h" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelPhysics.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelPhysicsTools_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelPhysicsTools>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelPhysicsTools_Statics::ClassParams = {
		&UVoxelPhysicsTools::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelPhysicsTools_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelPhysicsTools_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelPhysicsTools()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelPhysicsTools_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelPhysicsTools, 199337924);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelPhysicsTools(Z_Construct_UClass_UVoxelPhysicsTools, &UVoxelPhysicsTools::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelPhysicsTools"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelPhysicsTools);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
