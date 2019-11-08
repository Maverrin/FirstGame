// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelGraph/VoxelGraphMacro.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelGraphMacro() {}
// Cross Module References
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelPinNameAndType();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelPinCategory();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphMacroInputOutputNode();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphMacro_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphMacroInputNode_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphMacroInputNode();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphMacroOutputNode_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphMacroOutputNode();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphMacro();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphGenerator();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphMacroNode_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphMacroNode();
// End Cross Module References
class UScriptStruct* FVoxelPinNameAndType::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelPinNameAndType_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelPinNameAndType, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelPinNameAndType"), sizeof(FVoxelPinNameAndType), Get_Z_Construct_UScriptStruct_FVoxelPinNameAndType_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelPinNameAndType(FVoxelPinNameAndType::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelPinNameAndType"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelPinNameAndType
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelPinNameAndType()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelPinNameAndType")),new UScriptStruct::TCppStructOps<FVoxelPinNameAndType>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelPinNameAndType;
	struct Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DefaultValue;
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
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelPinNameAndType>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_DefaultValue_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_DefaultValue = { UE4CodeGen_Private::EPropertyClass::Str, "DefaultValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelPinNameAndType, DefaultValue), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_DefaultValue_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_DefaultValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_Category_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_Category = { UE4CodeGen_Private::EPropertyClass::Enum, "Category", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelPinNameAndType, Category), Z_Construct_UEnum_Voxel_EVoxelPinCategory, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_Category_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_Category_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_Category_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_Name = { UE4CodeGen_Private::EPropertyClass::Str, "Name", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelPinNameAndType, Name), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_Name_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_Name_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_DefaultValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_Category,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_Category_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::NewProp_Name,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelPinNameAndType",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FVoxelPinNameAndType),
		alignof(FVoxelPinNameAndType),
		Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelPinNameAndType()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelPinNameAndType_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelPinNameAndType"), sizeof(FVoxelPinNameAndType), Get_Z_Construct_UScriptStruct_FVoxelPinNameAndType_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelPinNameAndType_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelPinNameAndType_CRC() { return 3862961797U; }
	void UVoxelGraphMacroInputOutputNode::StaticRegisterNativesUVoxelGraphMacroInputOutputNode()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_NoRegister()
	{
		return UVoxelGraphMacroInputOutputNode::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Macro_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Macro;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Pins_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Pins;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Pins_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelGraphMacro.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::NewProp_Macro_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::NewProp_Macro = { UE4CodeGen_Private::EPropertyClass::Object, "Macro", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphMacroInputOutputNode, Macro), Z_Construct_UClass_UVoxelGraphMacro_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::NewProp_Macro_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::NewProp_Macro_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::NewProp_Pins_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::NewProp_Pins = { UE4CodeGen_Private::EPropertyClass::Array, "Pins", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphMacroInputOutputNode, Pins), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::NewProp_Pins_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::NewProp_Pins_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::NewProp_Pins_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Pins", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelPinNameAndType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::NewProp_Macro,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::NewProp_Pins,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::NewProp_Pins_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGraphMacroInputOutputNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::ClassParams = {
		&UVoxelGraphMacroInputOutputNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A1u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGraphMacroInputOutputNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGraphMacroInputOutputNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGraphMacroInputOutputNode, 83482598);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGraphMacroInputOutputNode(Z_Construct_UClass_UVoxelGraphMacroInputOutputNode, &UVoxelGraphMacroInputOutputNode::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelGraphMacroInputOutputNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGraphMacroInputOutputNode);
	void UVoxelGraphMacroInputNode::StaticRegisterNativesUVoxelGraphMacroInputNode()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGraphMacroInputNode_NoRegister()
	{
		return UVoxelGraphMacroInputNode::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGraphMacroInputNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGraphMacroInputNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelGraphMacroInputOutputNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphMacroInputNode_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Input" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelGraphMacro.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGraphMacroInputNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGraphMacroInputNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGraphMacroInputNode_Statics::ClassParams = {
		&UVoxelGraphMacroInputNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001012A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphMacroInputNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacroInputNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGraphMacroInputNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGraphMacroInputNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGraphMacroInputNode, 3340209540);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGraphMacroInputNode(Z_Construct_UClass_UVoxelGraphMacroInputNode, &UVoxelGraphMacroInputNode::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelGraphMacroInputNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGraphMacroInputNode);
	void UVoxelGraphMacroOutputNode::StaticRegisterNativesUVoxelGraphMacroOutputNode()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGraphMacroOutputNode_NoRegister()
	{
		return UVoxelGraphMacroOutputNode::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGraphMacroOutputNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGraphMacroOutputNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelGraphMacroInputOutputNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphMacroOutputNode_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Output" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelGraphMacro.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGraphMacroOutputNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGraphMacroOutputNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGraphMacroOutputNode_Statics::ClassParams = {
		&UVoxelGraphMacroOutputNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001012A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphMacroOutputNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacroOutputNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGraphMacroOutputNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGraphMacroOutputNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGraphMacroOutputNode, 392357215);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGraphMacroOutputNode(Z_Construct_UClass_UVoxelGraphMacroOutputNode, &UVoxelGraphMacroOutputNode::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelGraphMacroOutputNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGraphMacroOutputNode);
	void UVoxelGraphMacro::StaticRegisterNativesUVoxelGraphMacro()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGraphMacro_NoRegister()
	{
		return UVoxelGraphMacro::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGraphMacro_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OutputNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OutputNode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InputNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InputNode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowInContextMenu_MetaData[];
#endif
		static void NewProp_bShowInContextMenu_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowInContextMenu;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tooltip_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Tooltip;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGraphMacro_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelGraphGenerator,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphMacro_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Object Object" },
		{ "IncludePath", "VoxelGraph/VoxelGraphMacro.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
		{ "ToolTip", "A graph macro" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_OutputNode_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_OutputNode = { UE4CodeGen_Private::EPropertyClass::Object, "OutputNode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphMacro, OutputNode), Z_Construct_UClass_UVoxelGraphMacroOutputNode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_OutputNode_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_OutputNode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_InputNode_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_InputNode = { UE4CodeGen_Private::EPropertyClass::Object, "InputNode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelGraphMacro, InputNode), Z_Construct_UClass_UVoxelGraphMacroInputNode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_InputNode_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_InputNode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_bShowInContextMenu_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_bShowInContextMenu_SetBit(void* Obj)
	{
		((UVoxelGraphMacro*)Obj)->bShowInContextMenu = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_bShowInContextMenu = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowInContextMenu", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelGraphMacro), &Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_bShowInContextMenu_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_bShowInContextMenu_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_bShowInContextMenu_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_Tooltip_MetaData[] = {
		{ "Category", "Voxel" },
		{ "DisplayName", "Tooltip (Shift+Enter for new line)" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
		{ "MultiLine", "TRUE" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_Tooltip = { UE4CodeGen_Private::EPropertyClass::Str, "Tooltip", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphMacro, Tooltip), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_Tooltip_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_Tooltip_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelGraphMacro_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_OutputNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_InputNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_bShowInContextMenu,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphMacro_Statics::NewProp_Tooltip,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGraphMacro_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGraphMacro>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGraphMacro_Statics::ClassParams = {
		&UVoxelGraphMacro::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x041000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelGraphMacro_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacro_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphMacro_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacro_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGraphMacro()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGraphMacro_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGraphMacro, 4065907190);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGraphMacro(Z_Construct_UClass_UVoxelGraphMacro, &UVoxelGraphMacro::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelGraphMacro"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGraphMacro);
	void UVoxelGraphMacroNode::StaticRegisterNativesUVoxelGraphMacroNode()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGraphMacroNode_NoRegister()
	{
		return UVoxelGraphMacroNode::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGraphMacroNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Macro_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Macro;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGraphMacroNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphMacroNode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelGraphMacro.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphMacroNode_Statics::NewProp_Macro_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelGraphMacro.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelGraphMacroNode_Statics::NewProp_Macro = { UE4CodeGen_Private::EPropertyClass::Object, "Macro", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphMacroNode, Macro), Z_Construct_UClass_UVoxelGraphMacro_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphMacroNode_Statics::NewProp_Macro_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacroNode_Statics::NewProp_Macro_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelGraphMacroNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphMacroNode_Statics::NewProp_Macro,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGraphMacroNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGraphMacroNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGraphMacroNode_Statics::ClassParams = {
		&UVoxelGraphMacroNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelGraphMacroNode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacroNode_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphMacroNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphMacroNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGraphMacroNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGraphMacroNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGraphMacroNode, 729206279);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGraphMacroNode(Z_Construct_UClass_UVoxelGraphMacroNode, &UVoxelGraphMacroNode::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelGraphMacroNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGraphMacroNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
