// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/Graph/VoxelGraphSchema.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelGraphSchema() {}
// Cross Module References
	VOXELEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FEdGraphSchemaAction();
	VOXELEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment();
	VOXELEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode();
	VOXELEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelPortalNodeInput_NoRegister();
	VOXELEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelGraphMacro_NoRegister();
	VOXELEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGraphSchema_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelGraphSchema();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraphSchema();
// End Cross Module References
class UScriptStruct* FVoxelGraphSchemaAction_Paste::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXELEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste, Z_Construct_UPackage__Script_VoxelEditor(), TEXT("VoxelGraphSchemaAction_Paste"), sizeof(FVoxelGraphSchemaAction_Paste), Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelGraphSchemaAction_Paste(FVoxelGraphSchemaAction_Paste::StaticStruct, TEXT("/Script/VoxelEditor"), TEXT("VoxelGraphSchemaAction_Paste"), false, nullptr, nullptr);
static struct FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_Paste
{
	FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_Paste()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelGraphSchemaAction_Paste")),new UScriptStruct::TCppStructOps<FVoxelGraphSchemaAction_Paste>);
	}
} ScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_Paste;
	struct Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphSchema.h" },
		{ "ToolTip", "Action to paste clipboard contents into the graph" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelGraphSchemaAction_Paste>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
		Z_Construct_UScriptStruct_FEdGraphSchemaAction,
		&NewStructOps,
		"VoxelGraphSchemaAction_Paste",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelGraphSchemaAction_Paste),
		alignof(FVoxelGraphSchemaAction_Paste),
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_VoxelEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelGraphSchemaAction_Paste"), sizeof(FVoxelGraphSchemaAction_Paste), Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_Paste_CRC() { return 638319888U; }
class UScriptStruct* FVoxelGraphSchemaAction_NewComment::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXELEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment, Z_Construct_UPackage__Script_VoxelEditor(), TEXT("VoxelGraphSchemaAction_NewComment"), sizeof(FVoxelGraphSchemaAction_NewComment), Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelGraphSchemaAction_NewComment(FVoxelGraphSchemaAction_NewComment::StaticStruct, TEXT("/Script/VoxelEditor"), TEXT("VoxelGraphSchemaAction_NewComment"), false, nullptr, nullptr);
static struct FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewComment
{
	FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewComment()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelGraphSchemaAction_NewComment")),new UScriptStruct::TCppStructOps<FVoxelGraphSchemaAction_NewComment>);
	}
} ScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewComment;
	struct Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphSchema.h" },
		{ "ToolTip", "Action to create new comment" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelGraphSchemaAction_NewComment>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
		Z_Construct_UScriptStruct_FEdGraphSchemaAction,
		&NewStructOps,
		"VoxelGraphSchemaAction_NewComment",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelGraphSchemaAction_NewComment),
		alignof(FVoxelGraphSchemaAction_NewComment),
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_VoxelEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelGraphSchemaAction_NewComment"), sizeof(FVoxelGraphSchemaAction_NewComment), Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewComment_CRC() { return 3782036399U; }
class UScriptStruct* FVoxelGraphSchemaAction_NewKnotNode::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXELEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode, Z_Construct_UPackage__Script_VoxelEditor(), TEXT("VoxelGraphSchemaAction_NewKnotNode"), sizeof(FVoxelGraphSchemaAction_NewKnotNode), Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode(FVoxelGraphSchemaAction_NewKnotNode::StaticStruct, TEXT("/Script/VoxelEditor"), TEXT("VoxelGraphSchemaAction_NewKnotNode"), false, nullptr, nullptr);
static struct FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewKnotNode
{
	FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewKnotNode()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelGraphSchemaAction_NewKnotNode")),new UScriptStruct::TCppStructOps<FVoxelGraphSchemaAction_NewKnotNode>);
	}
} ScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewKnotNode;
	struct Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphSchema.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelGraphSchemaAction_NewKnotNode>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
		Z_Construct_UScriptStruct_FEdGraphSchemaAction,
		&NewStructOps,
		"VoxelGraphSchemaAction_NewKnotNode",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelGraphSchemaAction_NewKnotNode),
		alignof(FVoxelGraphSchemaAction_NewKnotNode),
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_VoxelEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelGraphSchemaAction_NewKnotNode"), sizeof(FVoxelGraphSchemaAction_NewKnotNode), Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewKnotNode_CRC() { return 360414660U; }
class UScriptStruct* FVoxelGraphSchemaAction_NewPortalNode::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXELEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode, Z_Construct_UPackage__Script_VoxelEditor(), TEXT("VoxelGraphSchemaAction_NewPortalNode"), sizeof(FVoxelGraphSchemaAction_NewPortalNode), Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode(FVoxelGraphSchemaAction_NewPortalNode::StaticStruct, TEXT("/Script/VoxelEditor"), TEXT("VoxelGraphSchemaAction_NewPortalNode"), false, nullptr, nullptr);
static struct FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewPortalNode
{
	FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewPortalNode()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelGraphSchemaAction_NewPortalNode")),new UScriptStruct::TCppStructOps<FVoxelGraphSchemaAction_NewPortalNode>);
	}
} ScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewPortalNode;
	struct Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InputNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InputNode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphSchema.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelGraphSchemaAction_NewPortalNode>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::NewProp_InputNode_MetaData[] = {
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphSchema.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::NewProp_InputNode = { UE4CodeGen_Private::EPropertyClass::Object, "InputNode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FVoxelGraphSchemaAction_NewPortalNode, InputNode), Z_Construct_UClass_UVoxelPortalNodeInput_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::NewProp_InputNode_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::NewProp_InputNode_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::NewProp_InputNode,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
		Z_Construct_UScriptStruct_FEdGraphSchemaAction,
		&NewStructOps,
		"VoxelGraphSchemaAction_NewPortalNode",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelGraphSchemaAction_NewPortalNode),
		alignof(FVoxelGraphSchemaAction_NewPortalNode),
		Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_VoxelEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelGraphSchemaAction_NewPortalNode"), sizeof(FVoxelGraphSchemaAction_NewPortalNode), Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewPortalNode_CRC() { return 1691436212U; }
class UScriptStruct* FVoxelGraphSchemaAction_NewMacroNode::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXELEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode, Z_Construct_UPackage__Script_VoxelEditor(), TEXT("VoxelGraphSchemaAction_NewMacroNode"), sizeof(FVoxelGraphSchemaAction_NewMacroNode), Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode(FVoxelGraphSchemaAction_NewMacroNode::StaticStruct, TEXT("/Script/VoxelEditor"), TEXT("VoxelGraphSchemaAction_NewMacroNode"), false, nullptr, nullptr);
static struct FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewMacroNode
{
	FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewMacroNode()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelGraphSchemaAction_NewMacroNode")),new UScriptStruct::TCppStructOps<FVoxelGraphSchemaAction_NewMacroNode>);
	}
} ScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewMacroNode;
	struct Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Macro_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Macro;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphSchema.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelGraphSchemaAction_NewMacroNode>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::NewProp_Macro_MetaData[] = {
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphSchema.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::NewProp_Macro = { UE4CodeGen_Private::EPropertyClass::Object, "Macro", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FVoxelGraphSchemaAction_NewMacroNode, Macro), Z_Construct_UClass_UVoxelGraphMacro_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::NewProp_Macro_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::NewProp_Macro_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::NewProp_Macro,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
		Z_Construct_UScriptStruct_FEdGraphSchemaAction,
		&NewStructOps,
		"VoxelGraphSchemaAction_NewMacroNode",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelGraphSchemaAction_NewMacroNode),
		alignof(FVoxelGraphSchemaAction_NewMacroNode),
		Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_VoxelEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelGraphSchemaAction_NewMacroNode"), sizeof(FVoxelGraphSchemaAction_NewMacroNode), Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewMacroNode_CRC() { return 3718528325U; }
class UScriptStruct* FVoxelGraphSchemaAction_NewNode::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXELEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode, Z_Construct_UPackage__Script_VoxelEditor(), TEXT("VoxelGraphSchemaAction_NewNode"), sizeof(FVoxelGraphSchemaAction_NewNode), Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVoxelGraphSchemaAction_NewNode(FVoxelGraphSchemaAction_NewNode::StaticStruct, TEXT("/Script/VoxelEditor"), TEXT("VoxelGraphSchemaAction_NewNode"), false, nullptr, nullptr);
static struct FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewNode
{
	FScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewNode()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VoxelGraphSchemaAction_NewNode")),new UScriptStruct::TCppStructOps<FVoxelGraphSchemaAction_NewNode>);
	}
} ScriptStruct_VoxelEditor_StaticRegisterNativesFVoxelGraphSchemaAction_NewNode;
	struct Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VoxelNodeClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_VoxelNodeClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphSchema.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVoxelGraphSchemaAction_NewNode>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::NewProp_VoxelNodeClass_MetaData[] = {
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphSchema.h" },
		{ "ToolTip", "Class of node we want to create" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::NewProp_VoxelNodeClass = { UE4CodeGen_Private::EPropertyClass::Class, "VoxelNodeClass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FVoxelGraphSchemaAction_NewNode, VoxelNodeClass), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::NewProp_VoxelNodeClass_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::NewProp_VoxelNodeClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::NewProp_VoxelNodeClass,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
		Z_Construct_UScriptStruct_FEdGraphSchemaAction,
		&NewStructOps,
		"VoxelGraphSchemaAction_NewNode",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FVoxelGraphSchemaAction_NewNode),
		alignof(FVoxelGraphSchemaAction_NewNode),
		Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_VoxelEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VoxelGraphSchemaAction_NewNode"), sizeof(FVoxelGraphSchemaAction_NewNode), Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVoxelGraphSchemaAction_NewNode_CRC() { return 4030700650U; }
	void UVoxelGraphSchema::StaticRegisterNativesUVoxelGraphSchema()
	{
	}
	UClass* Z_Construct_UClass_UVoxelGraphSchema_NoRegister()
	{
		return UVoxelGraphSchema::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelGraphSchema_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelGraphSchema_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEdGraphSchema,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelGraphSchema_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/VoxelGraphSchema.h" },
		{ "ModuleRelativePath", "Private/Graph/VoxelGraphSchema.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelGraphSchema_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelGraphSchema>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelGraphSchema_Statics::ClassParams = {
		&UVoxelGraphSchema::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000800A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelGraphSchema_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelGraphSchema_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelGraphSchema()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelGraphSchema_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelGraphSchema, 676626901);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelGraphSchema(Z_Construct_UClass_UVoxelGraphSchema, &UVoxelGraphSchema::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelGraphSchema"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelGraphSchema);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
