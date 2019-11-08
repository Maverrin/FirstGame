// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelGraph/VoxelPortalNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelPortalNode() {}
// Cross Module References
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelPinCategoryDataOnly();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelPortalNodeSelector();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelPortalNodeInput_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelPortalNodeInput();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelPortalNodeOutput_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelPortalNodeOutput();
// End Cross Module References
	static UEnum* EVoxelPinCategoryDataOnly_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelPinCategoryDataOnly, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelPinCategoryDataOnly"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelPinCategoryDataOnly(EVoxelPinCategoryDataOnly_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelPinCategoryDataOnly"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelPinCategoryDataOnly_CRC() { return 191606119U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelPinCategoryDataOnly()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelPinCategoryDataOnly"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelPinCategoryDataOnly_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelPinCategoryDataOnly::Boolean", (int64)EVoxelPinCategoryDataOnly::Boolean },
				{ "EVoxelPinCategoryDataOnly::Int", (int64)EVoxelPinCategoryDataOnly::Int },
				{ "EVoxelPinCategoryDataOnly::Float", (int64)EVoxelPinCategoryDataOnly::Float },
				{ "EVoxelPinCategoryDataOnly::Material", (int64)EVoxelPinCategoryDataOnly::Material },
				{ "EVoxelPinCategoryDataOnly::Seed", (int64)EVoxelPinCategoryDataOnly::Seed },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/VoxelGraph/VoxelPortalNode.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelPinCategoryDataOnly",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelPinCategoryDataOnly",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FVoxelPortalNodeSelector::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelPortalNodeSelector, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelPortalNodeSelector"), sizeof(FVoxelPortalNodeSelector), Get_Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelPortalNodeSelector(FVoxelPortalNodeSelector::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelPortalNodeSelector"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelPortalNodeSelector
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelPortalNodeSelector()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelPortalNodeSelector")),new UScriptStruct::TCppStructOps<FVoxelPortalNodeSelector>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelPortalNodeSelector;
	struct Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Input_MetaData[];
#endif
		static const UE4CodeGen_Private::FWeakObjectPropertyParams NewProp_Input;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelPortalNode.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelPortalNodeSelector>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::NewProp_Input_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelPortalNode.h" },
	};
#endif
	const UE4CodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::NewProp_Input = { UE4CodeGen_Private::EPropertyClass::WeakObject, "Input", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0014000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelPortalNodeSelector, Input), Z_Construct_UClass_UVoxelPortalNodeInput_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::NewProp_Input_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::NewProp_Input_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::NewProp_Input,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelPortalNodeSelector",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelPortalNodeSelector),
		alignof(FVoxelPortalNodeSelector),
		Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelPortalNodeSelector()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelPortalNodeSelector"), sizeof(FVoxelPortalNodeSelector), Get_Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelPortalNodeSelector_CRC() { return 2441707180U; }
	void UVoxelPortalNodeInput::StaticRegisterNativesUVoxelPortalNodeInput()
	{
	}
	UClass* Z_Construct_UClass_UVoxelPortalNodeInput_NoRegister()
	{
		return UVoxelPortalNodeInput::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelPortalNodeInput_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OutputNodes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OutputNodes;
		static const UE4CodeGen_Private::FWeakObjectPropertyParams NewProp_OutputNodes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Category;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Category_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Name;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelPortalNodeInput_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelPortalNodeInput_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Create Local Variable" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelPortalNode.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelPortalNode.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_OutputNodes_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelPortalNode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_OutputNodes = { UE4CodeGen_Private::EPropertyClass::Array, "OutputNodes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0014000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelPortalNodeInput, OutputNodes), METADATA_PARAMS(Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_OutputNodes_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_OutputNodes_MetaData)) };
	const UE4CodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_OutputNodes_Inner = { UE4CodeGen_Private::EPropertyClass::WeakObject, "OutputNodes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0004000000000000, 1, nullptr, 0, Z_Construct_UClass_UVoxelPortalNodeOutput_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_Category_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelPortalNode.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_Category = { UE4CodeGen_Private::EPropertyClass::Enum, "Category", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelPortalNodeInput, Category), Z_Construct_UEnum_Voxel_EVoxelPinCategoryDataOnly, METADATA_PARAMS(Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_Category_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_Category_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_Category_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelPortalNode.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_Name = { UE4CodeGen_Private::EPropertyClass::Str, "Name", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelPortalNodeInput, Name), METADATA_PARAMS(Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_Name_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_Name_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelPortalNodeInput_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_OutputNodes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_OutputNodes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_Category,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_Category_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelPortalNodeInput_Statics::NewProp_Name,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelPortalNodeInput_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelPortalNodeInput>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelPortalNodeInput_Statics::ClassParams = {
		&UVoxelPortalNodeInput::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelPortalNodeInput_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelPortalNodeInput_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelPortalNodeInput_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelPortalNodeInput_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelPortalNodeInput()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelPortalNodeInput_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelPortalNodeInput, 1797406638);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelPortalNodeInput(Z_Construct_UClass_UVoxelPortalNodeInput, &UVoxelPortalNodeInput::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelPortalNodeInput"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelPortalNodeInput);
	void UVoxelPortalNodeOutput::StaticRegisterNativesUVoxelPortalNodeOutput()
	{
	}
	UClass* Z_Construct_UClass_UVoxelPortalNodeOutput_NoRegister()
	{
		return UVoxelPortalNodeOutput::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelPortalNodeOutput_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Selector_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Selector;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Get Local Variable" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelPortalNode.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelPortalNode.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::NewProp_Selector_MetaData[] = {
		{ "Category", "Voxel" },
		{ "DisplayName", "Input" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelPortalNode.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::NewProp_Selector = { UE4CodeGen_Private::EPropertyClass::Struct, "Selector", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelPortalNodeOutput, Selector), Z_Construct_UScriptStruct_FVoxelPortalNodeSelector, METADATA_PARAMS(Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::NewProp_Selector_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::NewProp_Selector_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::NewProp_Selector,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelPortalNodeOutput>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::ClassParams = {
		&UVoxelPortalNodeOutput::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelPortalNodeOutput()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelPortalNodeOutput_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelPortalNodeOutput, 1791092391);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelPortalNodeOutput(Z_Construct_UClass_UVoxelPortalNodeOutput, &UVoxelPortalNodeOutput::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelPortalNodeOutput"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelPortalNodeOutput);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
