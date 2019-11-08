// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelPoolManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelPoolManager() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelPoolManager_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelPoolManager();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelPoolManager_DestroyGlobalVoxelPool();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated();
// End Cross Module References
	void UVoxelPoolManager::StaticRegisterNativesUVoxelPoolManager()
	{
		UClass* Class = UVoxelPoolManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateGlobalVoxelPool", &UVoxelPoolManager::execCreateGlobalVoxelPool },
			{ "DestroyGlobalVoxelPool", &UVoxelPoolManager::execDestroyGlobalVoxelPool },
			{ "IsGlobalVoxelPoolCreated", &UVoxelPoolManager::execIsGlobalVoxelPoolCreated },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool_Statics
	{
		struct VoxelPoolManager_eventCreateGlobalVoxelPool_Parms
		{
			int32 MeshThreadCount;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MeshThreadCount;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool_Statics::NewProp_MeshThreadCount = { UE4CodeGen_Private::EPropertyClass::Int, "MeshThreadCount", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelPoolManager_eventCreateGlobalVoxelPool_Parms, MeshThreadCount), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool_Statics::NewProp_MeshThreadCount,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "CPP_Default_MeshThreadCount", "2" },
		{ "ModuleRelativePath", "Public/VoxelPoolManager.h" },
		{ "ToolTip", "Min 1" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelPoolManager, "CreateGlobalVoxelPool", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(VoxelPoolManager_eventCreateGlobalVoxelPool_Parms), Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelPoolManager_DestroyGlobalVoxelPool_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelPoolManager_DestroyGlobalVoxelPool_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelPoolManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelPoolManager_DestroyGlobalVoxelPool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelPoolManager, "DestroyGlobalVoxelPool", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelPoolManager_DestroyGlobalVoxelPool_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelPoolManager_DestroyGlobalVoxelPool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelPoolManager_DestroyGlobalVoxelPool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelPoolManager_DestroyGlobalVoxelPool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated_Statics
	{
		struct VoxelPoolManager_eventIsGlobalVoxelPoolCreated_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VoxelPoolManager_eventIsGlobalVoxelPoolCreated_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelPoolManager_eventIsGlobalVoxelPoolCreated_Parms), &Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelPoolManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelPoolManager, "IsGlobalVoxelPoolCreated", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(VoxelPoolManager_eventIsGlobalVoxelPoolCreated_Parms), Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelPoolManager_NoRegister()
	{
		return UVoxelPoolManager::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelPoolManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelPoolManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelPoolManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelPoolManager_CreateGlobalVoxelPool, "CreateGlobalVoxelPool" }, // 3805496930
		{ &Z_Construct_UFunction_UVoxelPoolManager_DestroyGlobalVoxelPool, "DestroyGlobalVoxelPool" }, // 3587696044
		{ &Z_Construct_UFunction_UVoxelPoolManager_IsGlobalVoxelPoolCreated, "IsGlobalVoxelPoolCreated" }, // 3820843398
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelPoolManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelPoolManager.h" },
		{ "ModuleRelativePath", "Public/VoxelPoolManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelPoolManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelPoolManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelPoolManager_Statics::ClassParams = {
		&UVoxelPoolManager::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelPoolManager_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelPoolManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelPoolManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelPoolManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelPoolManager, 1940523267);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelPoolManager(Z_Construct_UClass_UVoxelPoolManager, &UVoxelPoolManager::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelPoolManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelPoolManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
