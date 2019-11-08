// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelEditor/Private/VoxelEditorTools/VoxelDefaultEditorTools.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelDefaultEditorTools() {}
// Cross Module References
	VOXELEDITOR_API UEnum* Z_Construct_UEnum_VoxelEditor_EVoxelEditorTool_Icons();
	UPackage* Z_Construct_UPackage__Script_VoxelEditor();
	VOXELEDITOR_API UEnum* Z_Construct_UEnum_VoxelEditor_EVoxelEditorTool_SculptPaint();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_NoRegister();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase();
	VOXELEDITOR_API UClass* Z_Construct_UClass_UVoxelEditorTool();
	VOXELEDITOR_API UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_EndEdit();
	VOXELEDITOR_API UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode();
	VOXELEDITOR_API UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
	VOXELEDITOR_API UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelMarker_NoRegister();
	VOXELEDITOR_API UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	VOXELEDITOR_API UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	VOXELEDITOR_API UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis();
	VOXELEDITOR_API UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EInputEvent();
	VOXELEDITOR_API UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
// End Cross Module References
	static UEnum* EVoxelEditorTool_Icons_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_VoxelEditor_EVoxelEditorTool_Icons, Z_Construct_UPackage__Script_VoxelEditor(), TEXT("EVoxelEditorTool_Icons"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelEditorTool_Icons(EVoxelEditorTool_Icons_StaticEnum, TEXT("/Script/VoxelEditor"), TEXT("EVoxelEditorTool_Icons"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_VoxelEditor_EVoxelEditorTool_Icons_CRC() { return 2715110580U; }
	UEnum* Z_Construct_UEnum_VoxelEditor_EVoxelEditorTool_Icons()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_VoxelEditor();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelEditorTool_Icons"), 0, Get_Z_Construct_UEnum_VoxelEditor_EVoxelEditorTool_Icons_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelEditorTool_Icons::Projection", (int64)EVoxelEditorTool_Icons::Projection },
				{ "EVoxelEditorTool_Icons::Sphere", (int64)EVoxelEditorTool_Icons::Sphere },
				{ "EVoxelEditorTool_Icons::Box", (int64)EVoxelEditorTool_Icons::Box },
				{ "EVoxelEditorTool_Icons::Custom0", (int64)EVoxelEditorTool_Icons::Custom0 },
				{ "EVoxelEditorTool_Icons::Custom1", (int64)EVoxelEditorTool_Icons::Custom1 },
				{ "EVoxelEditorTool_Icons::Custom2", (int64)EVoxelEditorTool_Icons::Custom2 },
				{ "EVoxelEditorTool_Icons::Custom3", (int64)EVoxelEditorTool_Icons::Custom3 },
				{ "EVoxelEditorTool_Icons::Custom4", (int64)EVoxelEditorTool_Icons::Custom4 },
				{ "EVoxelEditorTool_Icons::Custom5", (int64)EVoxelEditorTool_Icons::Custom5 },
				{ "EVoxelEditorTool_Icons::Custom6", (int64)EVoxelEditorTool_Icons::Custom6 },
				{ "EVoxelEditorTool_Icons::Custom7", (int64)EVoxelEditorTool_Icons::Custom7 },
				{ "EVoxelEditorTool_Icons::Custom8", (int64)EVoxelEditorTool_Icons::Custom8 },
				{ "EVoxelEditorTool_Icons::Custom9", (int64)EVoxelEditorTool_Icons::Custom9 },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_VoxelEditor,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelEditorTool_Icons",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelEditorTool_Icons",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EVoxelEditorTool_SculptPaint_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_VoxelEditor_EVoxelEditorTool_SculptPaint, Z_Construct_UPackage__Script_VoxelEditor(), TEXT("EVoxelEditorTool_SculptPaint"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelEditorTool_SculptPaint(EVoxelEditorTool_SculptPaint_StaticEnum, TEXT("/Script/VoxelEditor"), TEXT("EVoxelEditorTool_SculptPaint"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_VoxelEditor_EVoxelEditorTool_SculptPaint_CRC() { return 1902076495U; }
	UEnum* Z_Construct_UEnum_VoxelEditor_EVoxelEditorTool_SculptPaint()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_VoxelEditor();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelEditorTool_SculptPaint"), 0, Get_Z_Construct_UEnum_VoxelEditor_EVoxelEditorTool_SculptPaint_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelEditorTool_SculptPaint::Sculpt", (int64)EVoxelEditorTool_SculptPaint::Sculpt },
				{ "EVoxelEditorTool_SculptPaint::Paint", (int64)EVoxelEditorTool_SculptPaint::Paint },
				{ "EVoxelEditorTool_SculptPaint::Grass", (int64)EVoxelEditorTool_SculptPaint::Grass },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_VoxelEditor,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelEditorTool_SculptPaint",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelEditorTool_SculptPaint",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static FName NAME_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick = FName(TEXT("K2_HandleVoxelWorldClick"));
	void UVoxelEditorTool_SculptPaintBase::K2_HandleVoxelWorldClick(FVector Position, FVector Normal)
	{
		VoxelEditorTool_SculptPaintBase_eventK2_HandleVoxelWorldClick_Parms Parms;
		Parms.Position=Position;
		Parms.Normal=Normal;
		ProcessEvent(FindFunctionChecked(NAME_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick),&Parms);
	}
	static FName NAME_UVoxelEditorTool_SculptPaintBase_K2_InputAxis = FName(TEXT("K2_InputAxis"));
	void UVoxelEditorTool_SculptPaintBase::K2_InputAxis(FKey Key, float Delta, float DeltaTime, bool& Handled)
	{
		VoxelEditorTool_SculptPaintBase_eventK2_InputAxis_Parms Parms;
		Parms.Key=Key;
		Parms.Delta=Delta;
		Parms.DeltaTime=DeltaTime;
		Parms.Handled=Handled ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UVoxelEditorTool_SculptPaintBase_K2_InputAxis),&Parms);
		Handled=Parms.Handled;
	}
	static FName NAME_UVoxelEditorTool_SculptPaintBase_K2_InputKey = FName(TEXT("K2_InputKey"));
	void UVoxelEditorTool_SculptPaintBase::K2_InputKey(FKey Key, EInputEvent Event, bool& Handled)
	{
		VoxelEditorTool_SculptPaintBase_eventK2_InputKey_Parms Parms;
		Parms.Key=Key;
		Parms.Event=Event;
		Parms.Handled=Handled ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UVoxelEditorTool_SculptPaintBase_K2_InputKey),&Parms);
		Handled=Parms.Handled;
	}
	static FName NAME_UVoxelEditorTool_SculptPaintBase_K2_Tick = FName(TEXT("K2_Tick"));
	void UVoxelEditorTool_SculptPaintBase::K2_Tick(float DeltaTime, FVector LastPosition, FVector LastNormal, bool bHidden)
	{
		VoxelEditorTool_SculptPaintBase_eventK2_Tick_Parms Parms;
		Parms.DeltaTime=DeltaTime;
		Parms.LastPosition=LastPosition;
		Parms.LastNormal=LastNormal;
		Parms.bHidden=bHidden ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UVoxelEditorTool_SculptPaintBase_K2_Tick),&Parms);
	}
	void UVoxelEditorTool_SculptPaintBase::StaticRegisterNativesUVoxelEditorTool_SculptPaintBase()
	{
		UClass* Class = UVoxelEditorTool_SculptPaintBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EndEdit", &UVoxelEditorTool_SculptPaintBase::execEndEdit },
			{ "GetCurrentMode", &UVoxelEditorTool_SculptPaintBase::execGetCurrentMode },
			{ "GetCurrentVoxelWorld", &UVoxelEditorTool_SculptPaintBase::execGetCurrentVoxelWorld },
			{ "GetMarker", &UVoxelEditorTool_SculptPaintBase::execGetMarker },
			{ "IsKeyDown", &UVoxelEditorTool_SculptPaintBase::execIsKeyDown },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_EndEdit_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_EndEdit_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel Editor Tools" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_EndEdit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase, "EndEdit", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_EndEdit_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_EndEdit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_EndEdit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_EndEdit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode_Statics
	{
		struct VoxelEditorTool_SculptPaintBase_eventGetCurrentMode_Parms
		{
			EVoxelEditorTool_SculptPaint ReturnValue;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Enum, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventGetCurrentMode_Parms, ReturnValue), Z_Construct_UEnum_VoxelEditor_EVoxelEditorTool_SculptPaint, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode_Statics::NewProp_ReturnValue_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode_Statics::NewProp_ReturnValue_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel Editor Tools" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase, "GetCurrentMode", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(VoxelEditorTool_SculptPaintBase_eventGetCurrentMode_Parms), Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld_Statics
	{
		struct VoxelEditorTool_SculptPaintBase_eventGetCurrentVoxelWorld_Parms
		{
			AVoxelWorld* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventGetCurrentVoxelWorld_Parms, ReturnValue), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel Editor Tools" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase, "GetCurrentVoxelWorld", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(VoxelEditorTool_SculptPaintBase_eventGetCurrentVoxelWorld_Parms), Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker_Statics
	{
		struct VoxelEditorTool_SculptPaintBase_eventGetMarker_Parms
		{
			AVoxelMarker* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventGetMarker_Parms, ReturnValue), Z_Construct_UClass_AVoxelMarker_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel Editor Tools" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase, "GetMarker", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(VoxelEditorTool_SculptPaintBase_eventGetMarker_Parms), Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics
	{
		struct VoxelEditorTool_SculptPaintBase_eventIsKeyDown_Parms
		{
			FKey Key;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Key;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VoxelEditorTool_SculptPaintBase_eventIsKeyDown_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelEditorTool_SculptPaintBase_eventIsKeyDown_Parms), &Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::NewProp_Key = { UE4CodeGen_Private::EPropertyClass::Struct, "Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventIsKeyDown_Parms, Key), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::NewProp_Key,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel Editor Tools" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase, "IsKeyDown", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(VoxelEditorTool_SculptPaintBase_eventIsKeyDown_Parms), Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick_Statics
	{
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick_Statics::NewProp_Normal = { UE4CodeGen_Private::EPropertyClass::Struct, "Normal", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventK2_HandleVoxelWorldClick_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventK2_HandleVoxelWorldClick_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick_Statics::NewProp_Normal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick_Statics::NewProp_Position,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel Editor Tools" },
		{ "DisplayName", "Handle Voxel World Click" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase, "K2_HandleVoxelWorldClick", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08820800, sizeof(VoxelEditorTool_SculptPaintBase_eventK2_HandleVoxelWorldClick_Parms), Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics
	{
		static void NewProp_Handled_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Handled;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Delta;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Key;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::NewProp_Handled_SetBit(void* Obj)
	{
		((VoxelEditorTool_SculptPaintBase_eventK2_InputAxis_Parms*)Obj)->Handled = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::NewProp_Handled = { UE4CodeGen_Private::EPropertyClass::Bool, "Handled", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelEditorTool_SculptPaintBase_eventK2_InputAxis_Parms), &Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::NewProp_Handled_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::NewProp_DeltaTime = { UE4CodeGen_Private::EPropertyClass::Float, "DeltaTime", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventK2_InputAxis_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::NewProp_Delta = { UE4CodeGen_Private::EPropertyClass::Float, "Delta", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventK2_InputAxis_Parms, Delta), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::NewProp_Key = { UE4CodeGen_Private::EPropertyClass::Struct, "Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventK2_InputAxis_Parms, Key), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::NewProp_Handled,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::NewProp_DeltaTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::NewProp_Delta,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::NewProp_Key,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel Editor Tools" },
		{ "DisplayName", "Input Axis" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase, "K2_InputAxis", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420800, sizeof(VoxelEditorTool_SculptPaintBase_eventK2_InputAxis_Parms), Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics
	{
		static void NewProp_Handled_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Handled;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Event;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Key;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::NewProp_Handled_SetBit(void* Obj)
	{
		((VoxelEditorTool_SculptPaintBase_eventK2_InputKey_Parms*)Obj)->Handled = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::NewProp_Handled = { UE4CodeGen_Private::EPropertyClass::Bool, "Handled", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelEditorTool_SculptPaintBase_eventK2_InputKey_Parms), &Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::NewProp_Handled_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::NewProp_Event = { UE4CodeGen_Private::EPropertyClass::Byte, "Event", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventK2_InputKey_Parms, Event), Z_Construct_UEnum_Engine_EInputEvent, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::NewProp_Key = { UE4CodeGen_Private::EPropertyClass::Struct, "Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventK2_InputKey_Parms, Key), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::NewProp_Handled,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::NewProp_Event,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::NewProp_Key,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel Editor Tools" },
		{ "DisplayName", "Input Key" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase, "K2_InputKey", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420800, sizeof(VoxelEditorTool_SculptPaintBase_eventK2_InputKey_Parms), Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics
	{
		static void NewProp_bHidden_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHidden;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LastNormal;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LastPosition;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::NewProp_bHidden_SetBit(void* Obj)
	{
		((VoxelEditorTool_SculptPaintBase_eventK2_Tick_Parms*)Obj)->bHidden = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::NewProp_bHidden = { UE4CodeGen_Private::EPropertyClass::Bool, "bHidden", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelEditorTool_SculptPaintBase_eventK2_Tick_Parms), &Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::NewProp_bHidden_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::NewProp_LastNormal = { UE4CodeGen_Private::EPropertyClass::Struct, "LastNormal", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventK2_Tick_Parms, LastNormal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::NewProp_LastPosition = { UE4CodeGen_Private::EPropertyClass::Struct, "LastPosition", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventK2_Tick_Parms, LastPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::NewProp_DeltaTime = { UE4CodeGen_Private::EPropertyClass::Float, "DeltaTime", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelEditorTool_SculptPaintBase_eventK2_Tick_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::NewProp_bHidden,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::NewProp_LastNormal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::NewProp_LastPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::NewProp_DeltaTime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel Editor Tools" },
		{ "DisplayName", "Tick" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase, "K2_Tick", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08820800, sizeof(VoxelEditorTool_SculptPaintBase_eventK2_Tick_Parms), Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_NoRegister()
	{
		return UVoxelEditorTool_SculptPaintBase::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Marker_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Marker;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tooltip_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Tooltip;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Label_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Label;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Icon;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Icon_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MarkerClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_MarkerClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelEditorTool,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelEditor,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_EndEdit, "EndEdit" }, // 4062247838
		{ &Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentMode, "GetCurrentMode" }, // 2467110573
		{ &Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetCurrentVoxelWorld, "GetCurrentVoxelWorld" }, // 2208864429
		{ &Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_GetMarker, "GetMarker" }, // 2972149485
		{ &Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_IsKeyDown, "IsKeyDown" }, // 2728540835
		{ &Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_HandleVoxelWorldClick, "K2_HandleVoxelWorldClick" }, // 2229411957
		{ &Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputAxis, "K2_InputAxis" }, // 3481085415
		{ &Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_InputKey, "K2_InputKey" }, // 3645910152
		{ &Z_Construct_UFunction_UVoxelEditorTool_SculptPaintBase_K2_Tick, "K2_Tick" }, // 990766455
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "VoxelEditorTools/VoxelDefaultEditorTools.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Marker_MetaData[] = {
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Marker = { UE4CodeGen_Private::EPropertyClass::Object, "Marker", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(UVoxelEditorTool_SculptPaintBase, Marker), Z_Construct_UClass_AVoxelMarker_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Marker_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Marker_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Tooltip_MetaData[] = {
		{ "Category", "Voxel Editor Tools" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Tooltip = { UE4CodeGen_Private::EPropertyClass::Text, "Tooltip", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010005, 1, nullptr, STRUCT_OFFSET(UVoxelEditorTool_SculptPaintBase, Tooltip), METADATA_PARAMS(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Tooltip_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Tooltip_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Label_MetaData[] = {
		{ "Category", "Voxel Editor Tools" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Label = { UE4CodeGen_Private::EPropertyClass::Text, "Label", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010001, 1, nullptr, STRUCT_OFFSET(UVoxelEditorTool_SculptPaintBase, Label), METADATA_PARAMS(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Label_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Label_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Icon_MetaData[] = {
		{ "Category", "Voxel Editor Tools" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Icon = { UE4CodeGen_Private::EPropertyClass::Enum, "Icon", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010001, 1, nullptr, STRUCT_OFFSET(UVoxelEditorTool_SculptPaintBase, Icon), Z_Construct_UEnum_VoxelEditor_EVoxelEditorTool_Icons, METADATA_PARAMS(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Icon_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Icon_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Icon_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_MarkerClass_MetaData[] = {
		{ "Category", "Voxel Editor Tools" },
		{ "ModuleRelativePath", "Private/VoxelEditorTools/VoxelDefaultEditorTools.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_MarkerClass = { UE4CodeGen_Private::EPropertyClass::Class, "MarkerClass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0014000000010001, 1, nullptr, STRUCT_OFFSET(UVoxelEditorTool_SculptPaintBase, MarkerClass), Z_Construct_UClass_AVoxelMarker_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_MarkerClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_MarkerClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Marker,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Tooltip,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Label,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Icon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_Icon_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::NewProp_MarkerClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelEditorTool_SculptPaintBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::ClassParams = {
		&UVoxelEditorTool_SculptPaintBase::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A1u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelEditorTool_SculptPaintBase, 867618027);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelEditorTool_SculptPaintBase(Z_Construct_UClass_UVoxelEditorTool_SculptPaintBase, &UVoxelEditorTool_SculptPaintBase::StaticClass, TEXT("/Script/VoxelEditor"), TEXT("UVoxelEditorTool_SculptPaintBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelEditorTool_SculptPaintBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
