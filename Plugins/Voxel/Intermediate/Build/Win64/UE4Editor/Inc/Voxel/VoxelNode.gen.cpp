// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelGraph/VoxelNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelNode() {}
// Cross Module References
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelPinCategory();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelPin();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraphNode_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphGenerator_NoRegister();
// End Cross Module References
	static UEnum* EVoxelPinCategory_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelPinCategory, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelPinCategory"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelPinCategory(EVoxelPinCategory_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelPinCategory"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelPinCategory_CRC() { return 331033931U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelPinCategory()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelPinCategory"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelPinCategory_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelPinCategory::Exec", (int64)EVoxelPinCategory::Exec },
				{ "EVoxelPinCategory::Boolean", (int64)EVoxelPinCategory::Boolean },
				{ "EVoxelPinCategory::Int", (int64)EVoxelPinCategory::Int },
				{ "EVoxelPinCategory::Float", (int64)EVoxelPinCategory::Float },
				{ "EVoxelPinCategory::Material", (int64)EVoxelPinCategory::Material },
				{ "EVoxelPinCategory::Seed", (int64)EVoxelPinCategory::Seed },
				{ "EVoxelPinCategory::Wildcard", (int64)EVoxelPinCategory::Wildcard },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
				{ "Wildcard.Hidden", "" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelPinCategory",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelPinCategory",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FVoxelPin::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXEL_API uint32 Get_Z_Construct_UScriptStruct_FVoxelPin_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelPin, Z_Construct_UPackage__Script_Voxel(), TEXT("VoxelPin"), sizeof(FVoxelPin), Get_Z_Construct_UScriptStruct_FVoxelPin_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelPin(FVoxelPin::StaticStruct, TEXT("/Script/Voxel"), TEXT("VoxelPin"), false, nullptr, nullptr);
static struct FScriptStruct_Voxel_StaticRegisterNativesFVoxelPin
{
	FScriptStruct_Voxel_StaticRegisterNativesFVoxelPin()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelPin")),new UScriptStruct::TCppStructOps<FVoxelPin>);
	}
} ScriptStruct_Voxel_StaticRegisterNativesFVoxelPin;
	struct Z_Construct_UScriptStruct_FVoxelPin_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherPinIds_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OtherPinIds;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OtherPinIds_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherNodes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OtherNodes;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherNodes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PinCategory_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_PinCategory;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_PinCategory_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DefaultValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PinId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PinId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPin_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelPin_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelPin>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherPinIds_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherPinIds = { UE4CodeGen_Private::EPropertyClass::Array, "OtherPinIds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FVoxelPin, OtherPinIds), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherPinIds_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherPinIds_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherPinIds_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "OtherPinIds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherNodes_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherNodes = { UE4CodeGen_Private::EPropertyClass::Array, "OtherNodes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FVoxelPin, OtherNodes), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherNodes_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherNodes_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherNodes_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "OtherNodes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UVoxelNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_PinCategory_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_PinCategory = { UE4CodeGen_Private::EPropertyClass::Enum, "PinCategory", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FVoxelPin, PinCategory), Z_Construct_UEnum_Voxel_EVoxelPinCategory, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_PinCategory_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_PinCategory_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_PinCategory_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_DefaultValue_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_DefaultValue = { UE4CodeGen_Private::EPropertyClass::Str, "DefaultValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FVoxelPin, DefaultValue), METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_DefaultValue_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_DefaultValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_PinId_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_PinId = { UE4CodeGen_Private::EPropertyClass::Struct, "PinId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FVoxelPin, PinId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_PinId_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_PinId_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelPin_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherPinIds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherPinIds_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherNodes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_OtherNodes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_PinCategory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_PinCategory_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_DefaultValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelPin_Statics::NewProp_PinId,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelPin_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
		nullptr,
		&NewStructOps,
		"VoxelPin",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FVoxelPin),
		alignof(FVoxelPin),
		Z_Construct_UScriptStruct_FVoxelPin_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPin_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelPin_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelPin_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelPin()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelPin_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelPin"), sizeof(FVoxelPin), Get_Z_Construct_UScriptStruct_FVoxelPin_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelPin_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelPin_CRC() { return 630642211U; }
	void UVoxelNode::StaticRegisterNativesUVoxelNode()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_NoRegister()
	{
		return UVoxelNode::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InputPinCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_InputPinCount;
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GraphNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GraphNode;
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Graph_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Graph;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LastPreviewPinIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_LastPreviewPinIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PreviewPinIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_PreviewPinIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsPreviewing_MetaData[];
#endif
		static void NewProp_bIsPreviewing_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsPreviewing;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OutputPins_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OutputPins;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutputPins_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InputPins_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_InputPins;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_InputPins_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelNode.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
		{ "ToolTip", "Base class for VoxelNodes" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_Statics::NewProp_InputPinCount_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UVoxelNode_Statics::NewProp_InputPinCount = { UE4CodeGen_Private::EPropertyClass::Int, "InputPinCount", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000000, 1, nullptr, STRUCT_OFFSET(UVoxelNode, InputPinCount), METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_Statics::NewProp_InputPinCount_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_Statics::NewProp_InputPinCount_MetaData)) };
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_Statics::NewProp_GraphNode_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelNode_Statics::NewProp_GraphNode = { UE4CodeGen_Private::EPropertyClass::Object, "GraphNode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000800000000, 1, nullptr, STRUCT_OFFSET(UVoxelNode, GraphNode), Z_Construct_UClass_UEdGraphNode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_Statics::NewProp_GraphNode_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_Statics::NewProp_GraphNode_MetaData)) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_Statics::NewProp_Graph_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelNode_Statics::NewProp_Graph = { UE4CodeGen_Private::EPropertyClass::Object, "Graph", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelNode, Graph), Z_Construct_UClass_UVoxelGraphGenerator_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_Statics::NewProp_Graph_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_Statics::NewProp_Graph_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_Statics::NewProp_LastPreviewPinIndex_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UVoxelNode_Statics::NewProp_LastPreviewPinIndex = { UE4CodeGen_Private::EPropertyClass::Int, "LastPreviewPinIndex", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000002000, 1, nullptr, STRUCT_OFFSET(UVoxelNode, LastPreviewPinIndex), METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_Statics::NewProp_LastPreviewPinIndex_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_Statics::NewProp_LastPreviewPinIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_Statics::NewProp_PreviewPinIndex_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UVoxelNode_Statics::NewProp_PreviewPinIndex = { UE4CodeGen_Private::EPropertyClass::Int, "PreviewPinIndex", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000002000, 1, nullptr, STRUCT_OFFSET(UVoxelNode, PreviewPinIndex), METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_Statics::NewProp_PreviewPinIndex_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_Statics::NewProp_PreviewPinIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_Statics::NewProp_bIsPreviewing_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelNode_Statics::NewProp_bIsPreviewing_SetBit(void* Obj)
	{
		((UVoxelNode*)Obj)->bIsPreviewing = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelNode_Statics::NewProp_bIsPreviewing = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsPreviewing", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000002000, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelNode), &Z_Construct_UClass_UVoxelNode_Statics::NewProp_bIsPreviewing_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_Statics::NewProp_bIsPreviewing_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_Statics::NewProp_bIsPreviewing_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_Statics::NewProp_OutputPins_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelNode_Statics::NewProp_OutputPins = { UE4CodeGen_Private::EPropertyClass::Array, "OutputPins", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelNode, OutputPins), METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_Statics::NewProp_OutputPins_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_Statics::NewProp_OutputPins_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelNode_Statics::NewProp_OutputPins_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "OutputPins", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelPin, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_Statics::NewProp_InputPins_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelNode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelNode_Statics::NewProp_InputPins = { UE4CodeGen_Private::EPropertyClass::Array, "InputPins", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelNode, InputPins), METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_Statics::NewProp_InputPins_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_Statics::NewProp_InputPins_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelNode_Statics::NewProp_InputPins_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "InputPins", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelPin, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_Statics::NewProp_InputPinCount,
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_Statics::NewProp_GraphNode,
#endif // WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_Statics::NewProp_Graph,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_Statics::NewProp_LastPreviewPinIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_Statics::NewProp_PreviewPinIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_Statics::NewProp_bIsPreviewing,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_Statics::NewProp_OutputPins,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_Statics::NewProp_OutputPins_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_Statics::NewProp_InputPins,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_Statics::NewProp_InputPins_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_Statics::ClassParams = {
		&UVoxelNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A1u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelNode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode, 60893927);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode(Z_Construct_UClass_UVoxelNode, &UVoxelNode::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
