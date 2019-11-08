// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/Graph/VoxelGraphEditorToolkit.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelGraphEditorToolkit() {}
// Cross Module References
	VOXELEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_NoRegister();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGraphShortcuts_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGraphShortcuts();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
class UScriptStruct* FVoxelGraphEditorKeyBinding::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXELEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding, Z_Construct_UPackage__Script_VoxelEditor(), TEXT("VoxelGraphEditorKeyBinding"), sizeof(FVoxelGraphEditorKeyBinding), Get_Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelGraphEditorKeyBinding(FVoxelGraphEditorKeyBinding::StaticStruct, TEXT("/Script/VoxelEditor"), TEXT("VoxelGraphEditorKeyBinding"), false, nullptr, nullptr);
static struct FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphEditorKeyBinding
{
	FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphEditorKeyBinding()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelGraphEditorKeyBinding")),new UScriptStruct::TCppStructOps<FVoxelGraphEditorKeyBinding>);
	}
} ScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphEditorKeyBinding;
	struct Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Class_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Class;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Key;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShiftDown_MetaData[];
#endif
		static void NewProp_bShiftDown_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShiftDown;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAltDown_MetaData[];
#endif
		static void NewProp_bAltDown_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAltDown;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCtrlDown_MetaData[];
#endif
		static void NewProp_bCtrlDown_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCtrlDown;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphEditorToolkit.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelGraphEditorKeyBinding>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_Class_MetaData[] = {
		{ "Category", "VoxelGraphEditorKeyBinding" },
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphEditorToolkit.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_Class = { UE4CodeGen_Private::EPropertyClass::Class, "Class", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0014000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelGraphEditorKeyBinding, Class), Z_Construct_UClass_UVoxelNode_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_Class_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_Class_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_Key_MetaData[] = {
		{ "Category", "VoxelGraphEditorKeyBinding" },
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphEditorToolkit.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_Key = { UE4CodeGen_Private::EPropertyClass::Struct, "Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVoxelGraphEditorKeyBinding, Key), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_Key_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_Key_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bShiftDown_MetaData[] = {
		{ "Category", "VoxelGraphEditorKeyBinding" },
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphEditorToolkit.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bShiftDown_SetBit(void* Obj)
	{
		((FVoxelGraphEditorKeyBinding*)Obj)->bShiftDown = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bShiftDown = { UE4CodeGen_Private::EPropertyClass::Bool, "bShiftDown", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FVoxelGraphEditorKeyBinding), &Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bShiftDown_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bShiftDown_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bShiftDown_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bAltDown_MetaData[] = {
		{ "Category", "VoxelGraphEditorKeyBinding" },
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphEditorToolkit.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bAltDown_SetBit(void* Obj)
	{
		((FVoxelGraphEditorKeyBinding*)Obj)->bAltDown = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bAltDown = { UE4CodeGen_Private::EPropertyClass::Bool, "bAltDown", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FVoxelGraphEditorKeyBinding), &Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bAltDown_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bAltDown_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bAltDown_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bCtrlDown_MetaData[] = {
		{ "Category", "VoxelGraphEditorKeyBinding" },
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphEditorToolkit.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bCtrlDown_SetBit(void* Obj)
	{
		((FVoxelGraphEditorKeyBinding*)Obj)->bCtrlDown = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bCtrlDown = { UE4CodeGen_Private::EPropertyClass::Bool, "bCtrlDown", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FVoxelGraphEditorKeyBinding), &Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bCtrlDown_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bCtrlDown_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bCtrlDown_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_Class,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_Key,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bShiftDown,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bAltDown,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::NewProp_bCtrlDown,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
		nullptr,
		&NewStructOps,
		"VoxelGraphEditorKeyBinding",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FVoxelGraphEditorKeyBinding),
		alignof(FVoxelGraphEditorKeyBinding),
		Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_VoxelEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelGraphEditorKeyBinding"), sizeof(FVoxelGraphEditorKeyBinding), Get_Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding_CRC() { return 402748519U; }
	void UVoxelGraphShortcuts::StaticRegisterNativesUVoxelGraphShortcuts()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGraphShortcuts_NoRegister()
	{
		return UVoxelGraphShortcuts::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGraphShortcuts_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Shortcuts_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Shortcuts;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Shortcuts_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGraphShortcuts_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphShortcuts_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/VoxelGraphEditorToolkit.h" },
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphEditorToolkit.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphShortcuts_Statics::NewProp_Shortcuts_MetaData[] = {
		{ "Category", "VoxelGraphShortcuts" },
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphEditorToolkit.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVoxelGraphShortcuts_Statics::NewProp_Shortcuts = { UE4CodeGen_Private::EPropertyClass::Array, "Shortcuts", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UVoxelGraphShortcuts, Shortcuts), METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphShortcuts_Statics::NewProp_Shortcuts_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphShortcuts_Statics::NewProp_Shortcuts_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelGraphShortcuts_Statics::NewProp_Shortcuts_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Shortcuts", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000004000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVoxelGraphEditorKeyBinding, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelGraphShortcuts_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphShortcuts_Statics::NewProp_Shortcuts,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelGraphShortcuts_Statics::NewProp_Shortcuts_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGraphShortcuts_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGraphShortcuts>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGraphShortcuts_Statics::ClassParams = {
		&UVoxelGraphShortcuts::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A4u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelGraphShortcuts_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphShortcuts_Statics::PropPointers),
		"EditorKeyBindings",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphShortcuts_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphShortcuts_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGraphShortcuts()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGraphShortcuts_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGraphShortcuts, 513633501);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGraphShortcuts(Z_Construct_UClass_UVoxelGraphShortcuts, &UVoxelGraphShortcuts::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelGraphShortcuts"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGraphShortcuts);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
