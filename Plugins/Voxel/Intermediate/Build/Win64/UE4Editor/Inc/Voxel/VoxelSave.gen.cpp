// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelSave.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelSave() {}
// Cross Module References
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelCompressedWorldSave();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelSaveUtilities_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelSaveUtilities();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelWorldSaveObject_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelWorldSaveObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
class UScriptStruct* FVoxelCompressedWorldSave::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelCompressedWorldSave_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelCompressedWorldSave, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelCompressedWorldSave"), sizeof(FVoxelCompressedWorldSave), Get_Z_Construct_UScriptStruct_FVoxelCompressedWorldSave_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelCompressedWorldSave(FVoxelCompressedWorldSave::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelCompressedWorldSave"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelCompressedWorldSave
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelCompressedWorldSave()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelCompressedWorldSave")),new UScriptStruct::TCppStructOps<FVoxelCompressedWorldSave>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelCompressedWorldSave;
	struct Z_Construct_UScriptStruct_FVoxelCompressedWorldSave_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelCompressedWorldSave_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelSave.h" },
		{ "ToolTip", "Compressed save of the world" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelCompressedWorldSave_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelCompressedWorldSave>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelCompressedWorldSave_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelCompressedWorldSave",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelCompressedWorldSave),
		alignof(FVoxelCompressedWorldSave),
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelCompressedWorldSave_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelCompressedWorldSave_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelCompressedWorldSave()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelCompressedWorldSave_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelCompressedWorldSave"), sizeof(FVoxelCompressedWorldSave), Get_Z_Construct_UScriptStruct_FVoxelCompressedWorldSave_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelCompressedWorldSave_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelCompressedWorldSave_CRC() { return 3322644545U; }
class UScriptStruct* FVoxelUncompressedWorldSave::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelUncompressedWorldSave"), sizeof(FVoxelUncompressedWorldSave), Get_Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelUncompressedWorldSave(FVoxelUncompressedWorldSave::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelUncompressedWorldSave"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelUncompressedWorldSave
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelUncompressedWorldSave()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelUncompressedWorldSave")),new UScriptStruct::TCppStructOps<FVoxelUncompressedWorldSave>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelUncompressedWorldSave;
	struct Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelSave.h" },
		{ "ToolTip", "Uncompressed save of the world" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelUncompressedWorldSave>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelUncompressedWorldSave",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelUncompressedWorldSave),
		alignof(FVoxelUncompressedWorldSave),
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelUncompressedWorldSave"), sizeof(FVoxelUncompressedWorldSave), Get_Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave_CRC() { return 3330230404U; }
	void UVoxelSaveUtilities::StaticRegisterNativesUVoxelSaveUtilities()
	{
		UClass* Class = UVoxelSaveUtilities::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CompressVoxelSave", &UVoxelSaveUtilities::execCompressVoxelSave },
			{ "DecompressVoxelSave", &UVoxelSaveUtilities::execDecompressVoxelSave },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave_Statics
	{
		struct VoxelSaveUtilities_eventCompressVoxelSave_Parms
		{
			FVoxelUncompressedWorldSave UncompressedSave;
			FVoxelCompressedWorldSave OutCompressedSave;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutCompressedSave;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UncompressedSave;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave_Statics::NewProp_OutCompressedSave = { UE4CodeGen_Private::EPropertyClass::Struct, "OutCompressedSave", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelSaveUtilities_eventCompressVoxelSave_Parms, OutCompressedSave), Z_Construct_UScriptStruct_FVoxelCompressedWorldSave, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave_Statics::NewProp_UncompressedSave = { UE4CodeGen_Private::EPropertyClass::Struct, "UncompressedSave", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000180, 1, nullptr, STRUCT_OFFSET(VoxelSaveUtilities_eventCompressVoxelSave_Parms, UncompressedSave), Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave_Statics::NewProp_OutCompressedSave,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave_Statics::NewProp_UncompressedSave,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelSave.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelSaveUtilities, "CompressVoxelSave", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(VoxelSaveUtilities_eventCompressVoxelSave_Parms), Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics
	{
		struct VoxelSaveUtilities_eventDecompressVoxelSave_Parms
		{
			FVoxelCompressedWorldSave CompressedSave;
			FVoxelUncompressedWorldSave OutUncompressedSave;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutUncompressedSave;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CompressedSave_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CompressedSave;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VoxelSaveUtilities_eventDecompressVoxelSave_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelSaveUtilities_eventDecompressVoxelSave_Parms), &Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::NewProp_OutUncompressedSave = { UE4CodeGen_Private::EPropertyClass::Struct, "OutUncompressedSave", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelSaveUtilities_eventDecompressVoxelSave_Parms, OutUncompressedSave), Z_Construct_UScriptStruct_FVoxelUncompressedWorldSave, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::NewProp_CompressedSave_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::NewProp_CompressedSave = { UE4CodeGen_Private::EPropertyClass::Struct, "CompressedSave", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelSaveUtilities_eventDecompressVoxelSave_Parms, CompressedSave), Z_Construct_UScriptStruct_FVoxelCompressedWorldSave, METADATA_PARAMS(Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::NewProp_CompressedSave_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::NewProp_CompressedSave_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::NewProp_OutUncompressedSave,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::NewProp_CompressedSave,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelSave.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelSaveUtilities, "DecompressVoxelSave", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(VoxelSaveUtilities_eventDecompressVoxelSave_Parms), Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelSaveUtilities_NoRegister()
	{
		return UVoxelSaveUtilities::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelSaveUtilities_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelSaveUtilities_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelSaveUtilities_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelSaveUtilities_CompressVoxelSave, "CompressVoxelSave" }, // 3393575482
		{ &Z_Construct_UFunction_UVoxelSaveUtilities_DecompressVoxelSave, "DecompressVoxelSave" }, // 2595004234
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelSaveUtilities_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelSave.h" },
		{ "ModuleRelativePath", "Public/VoxelSave.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelSaveUtilities_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelSaveUtilities>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelSaveUtilities_Statics::ClassParams = {
		&UVoxelSaveUtilities::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelSaveUtilities_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelSaveUtilities_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelSaveUtilities()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelSaveUtilities_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelSaveUtilities, 3538513675);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelSaveUtilities(Z_Construct_UClass_UVoxelSaveUtilities, &UVoxelSaveUtilities::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelSaveUtilities"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelSaveUtilities);
	void UVoxelWorldSaveObject::StaticRegisterNativesUVoxelWorldSaveObject()
	{
	}
	UClass* Z_Construct_UClass_UVoxelWorldSaveObject_NoRegister()
	{
		return UVoxelWorldSaveObject::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelWorldSaveObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Save_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Save;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelWorldSaveObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelWorldSaveObject_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Voxel" },
		{ "IncludePath", "VoxelSave.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VoxelSave.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelWorldSaveObject_Statics::NewProp_Save_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelSave.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelWorldSaveObject_Statics::NewProp_Save = { UE4CodeGen_Private::EPropertyClass::Struct, "Save", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UVoxelWorldSaveObject, Save), Z_Construct_UScriptStruct_FVoxelCompressedWorldSave, METADATA_PARAMS(Z_Construct_UClass_UVoxelWorldSaveObject_Statics::NewProp_Save_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelWorldSaveObject_Statics::NewProp_Save_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelWorldSaveObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelWorldSaveObject_Statics::NewProp_Save,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelWorldSaveObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelWorldSaveObject>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelWorldSaveObject_Statics::ClassParams = {
		&UVoxelWorldSaveObject::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelWorldSaveObject_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelWorldSaveObject_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelWorldSaveObject_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelWorldSaveObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelWorldSaveObject()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelWorldSaveObject_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelWorldSaveObject, 1143050855);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelWorldSaveObject(Z_Construct_UClass_UVoxelWorldSaveObject, &UVoxelWorldSaveObject::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelWorldSaveObject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelWorldSaveObject);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
