// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelTools/VoxelTools.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelTools() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelTools_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelTools();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelTools_AddBox();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FIntBox();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelTools_AddSphere();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelTools_Flatten();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelTools_RemoveBox();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelTools_RemoveSphere();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelTools_RoundVoxels();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelTools_SetMaterialBox();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelPaintMaterial();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelTools_SetMaterialSphere();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelTools_SetValueBox();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelTools_SetValueSphere();
// End Cross Module References
	void UVoxelTools::StaticRegisterNativesUVoxelTools()
	{
		UClass* Class = UVoxelTools::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddBox", &UVoxelTools::execAddBox },
			{ "AddNeighborsToSet", &UVoxelTools::execAddNeighborsToSet },
			{ "AddSphere", &UVoxelTools::execAddSphere },
			{ "Flatten", &UVoxelTools::execFlatten },
			{ "RemoveBox", &UVoxelTools::execRemoveBox },
			{ "RemoveSphere", &UVoxelTools::execRemoveSphere },
			{ "RoundVoxels", &UVoxelTools::execRoundVoxels },
			{ "SetBoxAsDirty", &UVoxelTools::execSetBoxAsDirty },
			{ "SetMaterialBox", &UVoxelTools::execSetMaterialBox },
			{ "SetMaterialSphere", &UVoxelTools::execSetMaterialSphere },
			{ "SetValueBox", &UVoxelTools::execSetValueBox },
			{ "SetValueSphere", &UVoxelTools::execSetValueSphere },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelTools_AddBox_Statics
	{
		struct VoxelTools_eventAddBox_Parms
		{
			AVoxelWorld* World;
			FIntBox Bounds;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Bounds;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_AddBox_Statics::NewProp_Bounds = { UE4CodeGen_Private::EPropertyClass::Struct, "Bounds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventAddBox_Parms, Bounds), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelTools_AddBox_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventAddBox_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelTools_AddBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_AddBox_Statics::NewProp_Bounds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_AddBox_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelTools_AddBox_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelTools.h" },
		{ "ToolTip", "Add a box" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelTools_AddBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelTools, "AddBox", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(VoxelTools_eventAddBox_Parms), Z_Construct_UFunction_UVoxelTools_AddBox_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_AddBox_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelTools_AddBox_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_AddBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelTools_AddBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelTools_AddBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics
	{
		struct VoxelTools_eventAddNeighborsToSet_Parms
		{
			TSet<FIntVector> InSet;
			TSet<FIntVector> OutSet;
		};
		static const UE4CodeGen_Private::FSetPropertyParams NewProp_OutSet;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutSet_ElementProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InSet_MetaData[];
#endif
		static const UE4CodeGen_Private::FSetPropertyParams NewProp_InSet;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_InSet_ElementProp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::NewProp_OutSet = { UE4CodeGen_Private::EPropertyClass::Set, "OutSet", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventAddNeighborsToSet_Parms, OutSet), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::NewProp_OutSet_ElementProp = { UE4CodeGen_Private::EPropertyClass::Struct, "OutSet", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::NewProp_InSet_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::NewProp_InSet = { UE4CodeGen_Private::EPropertyClass::Set, "InSet", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventAddNeighborsToSet_Parms, InSet), METADATA_PARAMS(Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::NewProp_InSet_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::NewProp_InSet_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::NewProp_InSet_ElementProp = { UE4CodeGen_Private::EPropertyClass::Struct, "InSet", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::NewProp_OutSet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::NewProp_OutSet_ElementProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::NewProp_InSet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::NewProp_InSet_ElementProp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelTools, "AddNeighborsToSet", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(VoxelTools_eventAddNeighborsToSet_Parms), Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelTools_AddSphere_Statics
	{
		struct VoxelTools_eventAddSphere_Parms
		{
			AVoxelWorld* World;
			FIntVector Position;
			float Radius;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventAddSphere_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventAddSphere_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventAddSphere_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelTools.h" },
		{ "ToolTip", "Add a sphere\n@param       World           The voxel world\n@param       Position        The voxel position of the center (use GlobalToLocal function of the VoxelWorld to get it)\n@param       Radius          The radius in voxels" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelTools, "AddSphere", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04822401, sizeof(VoxelTools_eventAddSphere_Parms), Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelTools_AddSphere()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelTools_AddSphere_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelTools_Flatten_Statics
	{
		struct VoxelTools_eventFlatten_Parms
		{
			AVoxelWorld* World;
			FVector Position;
			FVector Normal;
			float Radius;
			float Strength;
			bool bDontModifyVoxelsAroundPosition;
			bool bDontModifyEmptyVoxels;
			bool bDontModifyFullVoxels;
			int32 TimeoutInMicroSeconds;
			bool bShowModifiedVoxels;
			bool bShowTestedVoxels;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static void NewProp_bShowTestedVoxels_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowTestedVoxels;
		static void NewProp_bShowModifiedVoxels_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowModifiedVoxels;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_TimeoutInMicroSeconds;
		static void NewProp_bDontModifyFullVoxels_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDontModifyFullVoxels;
		static void NewProp_bDontModifyEmptyVoxels_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDontModifyEmptyVoxels;
		static void NewProp_bDontModifyVoxelsAroundPosition_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDontModifyVoxelsAroundPosition;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Strength;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VoxelTools_eventFlatten_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelTools_eventFlatten_Parms), &Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bShowTestedVoxels_SetBit(void* Obj)
	{
		((VoxelTools_eventFlatten_Parms*)Obj)->bShowTestedVoxels = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bShowTestedVoxels = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowTestedVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelTools_eventFlatten_Parms), &Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bShowTestedVoxels_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bShowModifiedVoxels_SetBit(void* Obj)
	{
		((VoxelTools_eventFlatten_Parms*)Obj)->bShowModifiedVoxels = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bShowModifiedVoxels = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowModifiedVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelTools_eventFlatten_Parms), &Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bShowModifiedVoxels_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_TimeoutInMicroSeconds = { UE4CodeGen_Private::EPropertyClass::Int, "TimeoutInMicroSeconds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventFlatten_Parms, TimeoutInMicroSeconds), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bDontModifyFullVoxels_SetBit(void* Obj)
	{
		((VoxelTools_eventFlatten_Parms*)Obj)->bDontModifyFullVoxels = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bDontModifyFullVoxels = { UE4CodeGen_Private::EPropertyClass::Bool, "bDontModifyFullVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelTools_eventFlatten_Parms), &Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bDontModifyFullVoxels_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bDontModifyEmptyVoxels_SetBit(void* Obj)
	{
		((VoxelTools_eventFlatten_Parms*)Obj)->bDontModifyEmptyVoxels = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bDontModifyEmptyVoxels = { UE4CodeGen_Private::EPropertyClass::Bool, "bDontModifyEmptyVoxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelTools_eventFlatten_Parms), &Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bDontModifyEmptyVoxels_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bDontModifyVoxelsAroundPosition_SetBit(void* Obj)
	{
		((VoxelTools_eventFlatten_Parms*)Obj)->bDontModifyVoxelsAroundPosition = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bDontModifyVoxelsAroundPosition = { UE4CodeGen_Private::EPropertyClass::Bool, "bDontModifyVoxelsAroundPosition", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelTools_eventFlatten_Parms), &Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bDontModifyVoxelsAroundPosition_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_Strength = { UE4CodeGen_Private::EPropertyClass::Float, "Strength", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventFlatten_Parms, Strength), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventFlatten_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_Normal = { UE4CodeGen_Private::EPropertyClass::Struct, "Normal", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventFlatten_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventFlatten_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventFlatten_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelTools_Flatten_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bShowTestedVoxels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bShowModifiedVoxels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_TimeoutInMicroSeconds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bDontModifyFullVoxels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bDontModifyEmptyVoxels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_bDontModifyVoxelsAroundPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_Strength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_Normal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_Flatten_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelTools_Flatten_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "4" },
		{ "Category", "Voxel" },
		{ "CPP_Default_bDontModifyEmptyVoxels", "false" },
		{ "CPP_Default_bDontModifyFullVoxels", "false" },
		{ "CPP_Default_bDontModifyVoxelsAroundPosition", "false" },
		{ "CPP_Default_bShowModifiedVoxels", "false" },
		{ "CPP_Default_bShowTestedVoxels", "false" },
		{ "CPP_Default_Strength", "0.100000" },
		{ "CPP_Default_TimeoutInMicroSeconds", "500" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelTools.h" },
		{ "ToolTip", "Flatten the surface of the world\n@param       World                                                           Voxel World\n@param       Position                                                        Position in world space\n@param       Normal                                                          Normal at Position\n@param       Radius                                                          Radius in world space\n@param       Strength                                                        Speed of the edit\n@param       bDontModifyVoxelsAroundPosition         Don't edit the voxels around Position. Use if the tool is moving when editing\n@param       bDontModifyEmptyVoxels                          Can't add on voxels totally empty\n@param       bDontModifyFullVoxels                           Can't remove on voxels totally full\n@param       bShowModifiedVoxels                                     Draw debug points on modified voxels\n@param       bShowTestedVoxels                                       Draw debug points on voxels tested for validity" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelTools_Flatten_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelTools, "Flatten", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04822401, sizeof(VoxelTools_eventFlatten_Parms), Z_Construct_UFunction_UVoxelTools_Flatten_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_Flatten_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelTools_Flatten_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_Flatten_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelTools_Flatten()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelTools_Flatten_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelTools_RemoveBox_Statics
	{
		struct VoxelTools_eventRemoveBox_Parms
		{
			AVoxelWorld* World;
			FIntBox Bounds;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Bounds;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_RemoveBox_Statics::NewProp_Bounds = { UE4CodeGen_Private::EPropertyClass::Struct, "Bounds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventRemoveBox_Parms, Bounds), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelTools_RemoveBox_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventRemoveBox_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelTools_RemoveBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_RemoveBox_Statics::NewProp_Bounds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_RemoveBox_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelTools_RemoveBox_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelTools.h" },
		{ "ToolTip", "Remove a box" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelTools_RemoveBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelTools, "RemoveBox", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(VoxelTools_eventRemoveBox_Parms), Z_Construct_UFunction_UVoxelTools_RemoveBox_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_RemoveBox_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelTools_RemoveBox_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_RemoveBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelTools_RemoveBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelTools_RemoveBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics
	{
		struct VoxelTools_eventRemoveSphere_Parms
		{
			AVoxelWorld* World;
			FIntVector Position;
			float Radius;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventRemoveSphere_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventRemoveSphere_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventRemoveSphere_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelTools.h" },
		{ "ToolTip", "Remove a sphere\n@param       World           The voxel world\n@param       Position        The voxel position of the center (use GlobalToLocal function of the VoxelWorld to get it)\n@param       Radius          The radius in voxels" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelTools, "RemoveSphere", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04822401, sizeof(VoxelTools_eventRemoveSphere_Parms), Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelTools_RemoveSphere()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelTools_RemoveSphere_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelTools_RoundVoxels_Statics
	{
		struct VoxelTools_eventRoundVoxels_Parms
		{
			AVoxelWorld* World;
			FIntBox Bounds;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Bounds;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_RoundVoxels_Statics::NewProp_Bounds = { UE4CodeGen_Private::EPropertyClass::Struct, "Bounds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventRoundVoxels_Parms, Bounds), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelTools_RoundVoxels_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventRoundVoxels_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelTools_RoundVoxels_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_RoundVoxels_Statics::NewProp_Bounds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_RoundVoxels_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelTools_RoundVoxels_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelTools.h" },
		{ "ToolTip", "Round voxels that don't have an impact on the surface. Same visual result but will lead to better compression" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelTools_RoundVoxels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelTools, "RoundVoxels", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(VoxelTools_eventRoundVoxels_Parms), Z_Construct_UFunction_UVoxelTools_RoundVoxels_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_RoundVoxels_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelTools_RoundVoxels_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_RoundVoxels_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelTools_RoundVoxels()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelTools_RoundVoxels_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics
	{
		struct VoxelTools_eventSetBoxAsDirty_Parms
		{
			AVoxelWorld* World;
			FIntBox Bounds;
			bool bSetValuesAsDirty;
			bool bSetMaterialsAsDirty;
		};
		static void NewProp_bSetMaterialsAsDirty_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSetMaterialsAsDirty;
		static void NewProp_bSetValuesAsDirty_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSetValuesAsDirty;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Bounds;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::NewProp_bSetMaterialsAsDirty_SetBit(void* Obj)
	{
		((VoxelTools_eventSetBoxAsDirty_Parms*)Obj)->bSetMaterialsAsDirty = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::NewProp_bSetMaterialsAsDirty = { UE4CodeGen_Private::EPropertyClass::Bool, "bSetMaterialsAsDirty", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelTools_eventSetBoxAsDirty_Parms), &Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::NewProp_bSetMaterialsAsDirty_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::NewProp_bSetValuesAsDirty_SetBit(void* Obj)
	{
		((VoxelTools_eventSetBoxAsDirty_Parms*)Obj)->bSetValuesAsDirty = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::NewProp_bSetValuesAsDirty = { UE4CodeGen_Private::EPropertyClass::Bool, "bSetValuesAsDirty", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelTools_eventSetBoxAsDirty_Parms), &Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::NewProp_bSetValuesAsDirty_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::NewProp_Bounds = { UE4CodeGen_Private::EPropertyClass::Struct, "Bounds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetBoxAsDirty_Parms, Bounds), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetBoxAsDirty_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::NewProp_bSetMaterialsAsDirty,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::NewProp_bSetValuesAsDirty,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::NewProp_Bounds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "CPP_Default_bSetMaterialsAsDirty", "true" },
		{ "CPP_Default_bSetValuesAsDirty", "true" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelTools, "SetBoxAsDirty", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(VoxelTools_eventSetBoxAsDirty_Parms), Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics
	{
		struct VoxelTools_eventSetMaterialBox_Parms
		{
			AVoxelWorld* World;
			FIntBox Bounds;
			FVoxelPaintMaterial PaintMaterial;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PaintMaterial;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Bounds;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::NewProp_PaintMaterial = { UE4CodeGen_Private::EPropertyClass::Struct, "PaintMaterial", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetMaterialBox_Parms, PaintMaterial), Z_Construct_UScriptStruct_FVoxelPaintMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::NewProp_Bounds = { UE4CodeGen_Private::EPropertyClass::Struct, "Bounds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetMaterialBox_Parms, Bounds), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetMaterialBox_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::NewProp_PaintMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::NewProp_Bounds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelTools.h" },
		{ "ToolTip", "Paint a box\n@param       World                   The voxel world\n@param       Position                The voxel position of the minimal corner (use GlobalToLocal function of the VoxelWorld to get it)\n@param       Size                    The size of the box in voxels\n@param       PaintMaterial   The material to paint" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelTools, "SetMaterialBox", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(VoxelTools_eventSetMaterialBox_Parms), Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelTools_SetMaterialBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelTools_SetMaterialBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics
	{
		struct VoxelTools_eventSetMaterialSphere_Parms
		{
			AVoxelWorld* World;
			FIntVector Position;
			float Radius;
			FVoxelPaintMaterial PaintMaterial;
			UCurveFloat* StrengthCurve;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StrengthCurve;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PaintMaterial;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::NewProp_StrengthCurve = { UE4CodeGen_Private::EPropertyClass::Object, "StrengthCurve", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetMaterialSphere_Parms, StrengthCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::NewProp_PaintMaterial = { UE4CodeGen_Private::EPropertyClass::Struct, "PaintMaterial", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetMaterialSphere_Parms, PaintMaterial), Z_Construct_UScriptStruct_FVoxelPaintMaterial, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetMaterialSphere_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetMaterialSphere_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetMaterialSphere_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::NewProp_StrengthCurve,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::NewProp_PaintMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "CPP_Default_StrengthCurve", "None" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelTools, "SetMaterialSphere", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04822401, sizeof(VoxelTools_eventSetMaterialSphere_Parms), Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelTools_SetMaterialSphere()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelTools_SetMaterialSphere_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics
	{
		struct VoxelTools_eventSetValueBox_Parms
		{
			AVoxelWorld* World;
			FIntBox Bounds;
			float Value;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Bounds;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetValueBox_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::NewProp_Bounds = { UE4CodeGen_Private::EPropertyClass::Struct, "Bounds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetValueBox_Parms, Bounds), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetValueBox_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::NewProp_Bounds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelTools.h" },
		{ "ToolTip", "Set the density in a box" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelTools, "SetValueBox", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(VoxelTools_eventSetValueBox_Parms), Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelTools_SetValueBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelTools_SetValueBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics
	{
		struct VoxelTools_eventSetValueSphere_Parms
		{
			AVoxelWorld* World;
			FIntVector Position;
			float Radius;
			float Value;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetValueSphere_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetValueSphere_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetValueSphere_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelTools_eventSetValueSphere_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelTools.h" },
		{ "ToolTip", "Set the density in a sphere\n@param       World           The voxel world\n@param       Position        The voxel position of the center (use GlobalToLocal function of the VoxelWorld to get it)\n@param       Radius          The radius in voxels\n@param       Value           The density to set" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelTools, "SetValueSphere", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04822401, sizeof(VoxelTools_eventSetValueSphere_Parms), Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelTools_SetValueSphere()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelTools_SetValueSphere_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelTools_NoRegister()
	{
		return UVoxelTools::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelTools_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelTools_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelTools_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelTools_AddBox, "AddBox" }, // 754529477
		{ &Z_Construct_UFunction_UVoxelTools_AddNeighborsToSet, "AddNeighborsToSet" }, // 785953587
		{ &Z_Construct_UFunction_UVoxelTools_AddSphere, "AddSphere" }, // 241792981
		{ &Z_Construct_UFunction_UVoxelTools_Flatten, "Flatten" }, // 3754815350
		{ &Z_Construct_UFunction_UVoxelTools_RemoveBox, "RemoveBox" }, // 1533114742
		{ &Z_Construct_UFunction_UVoxelTools_RemoveSphere, "RemoveSphere" }, // 1722552493
		{ &Z_Construct_UFunction_UVoxelTools_RoundVoxels, "RoundVoxels" }, // 4283580961
		{ &Z_Construct_UFunction_UVoxelTools_SetBoxAsDirty, "SetBoxAsDirty" }, // 1224973155
		{ &Z_Construct_UFunction_UVoxelTools_SetMaterialBox, "SetMaterialBox" }, // 3908198170
		{ &Z_Construct_UFunction_UVoxelTools_SetMaterialSphere, "SetMaterialSphere" }, // 3408518493
		{ &Z_Construct_UFunction_UVoxelTools_SetValueBox, "SetValueBox" }, // 1285141078
		{ &Z_Construct_UFunction_UVoxelTools_SetValueSphere, "SetValueSphere" }, // 4269711108
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelTools_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelTools/VoxelTools.h" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelTools.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelTools_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelTools>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelTools_Statics::ClassParams = {
		&UVoxelTools::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelTools_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelTools_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelTools()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelTools_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelTools, 1296728924);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelTools(Z_Construct_UClass_UVoxelTools, &UVoxelTools::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelTools"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelTools);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
