// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelTools/VoxelMarker.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelMarker() {}
// Cross Module References
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelTool();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelMode();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelMarker_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelMarker();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelProjectionMarker_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelProjectionMarker();
	VOXEL_API UFunction* Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UDecalComponent_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelSphereMarker_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelSphereMarker();
	VOXEL_API UFunction* Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelBoxMarker_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelBoxMarker();
	VOXEL_API UFunction* Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FIntBox();
// End Cross Module References
	static UEnum* EVoxelTool_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelTool, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelTool"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelTool(EVoxelTool_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelTool"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelTool_CRC() { return 3670323803U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelTool()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelTool"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelTool_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelTool::Projection", (int64)EVoxelTool::Projection },
				{ "EVoxelTool::Sphere", (int64)EVoxelTool::Sphere },
				{ "EVoxelTool::Box", (int64)EVoxelTool::Box },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelTool",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelTool",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EVoxelMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelMode, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelMode"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelMode(EVoxelMode_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelMode_CRC() { return 3323205347U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelMode"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelMode_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelMode::Add", (int64)EVoxelMode::Add },
				{ "EVoxelMode::Remove", (int64)EVoxelMode::Remove },
				{ "EVoxelMode::Flatten", (int64)EVoxelMode::Flatten },
				{ "EVoxelMode::Paint", (int64)EVoxelMode::Paint },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelMode",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelMode",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void AVoxelMarker::StaticRegisterNativesAVoxelMarker()
	{
	}
	UClass* Z_Construct_UClass_AVoxelMarker_NoRegister()
	{
		return AVoxelMarker::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelMarker_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelMarker_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelMarker_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelTools/VoxelMarker.h" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelMarker_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelMarker>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelMarker_Statics::ClassParams = {
		&AVoxelMarker::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelMarker_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelMarker_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelMarker()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelMarker_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelMarker, 2488222109);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelMarker(Z_Construct_UClass_AVoxelMarker, &AVoxelMarker::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelMarker"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelMarker);
	void AVoxelProjectionMarker::StaticRegisterNativesAVoxelProjectionMarker()
	{
		UClass* Class = AVoxelProjectionMarker::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UpdateProjectionMarker", &AVoxelProjectionMarker::execUpdateProjectionMarker },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics
	{
		struct VoxelProjectionMarker_eventUpdateProjectionMarker_Parms
		{
			AVoxelWorld* World;
			EVoxelMode Mode;
			FVector Position;
			FVector Normal;
			float Radius;
			float EditDistance;
			float HeightOffset;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HeightOffset;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_EditDistance;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Mode;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_HeightOffset = { UE4CodeGen_Private::EPropertyClass::Float, "HeightOffset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionMarker_eventUpdateProjectionMarker_Parms, HeightOffset), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_EditDistance = { UE4CodeGen_Private::EPropertyClass::Float, "EditDistance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionMarker_eventUpdateProjectionMarker_Parms, EditDistance), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionMarker_eventUpdateProjectionMarker_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_Normal = { UE4CodeGen_Private::EPropertyClass::Struct, "Normal", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionMarker_eventUpdateProjectionMarker_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionMarker_eventUpdateProjectionMarker_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_Mode = { UE4CodeGen_Private::EPropertyClass::Enum, "Mode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionMarker_eventUpdateProjectionMarker_Parms, Mode), Z_Construct_UEnum_Voxel_EVoxelMode, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_Mode_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelProjectionMarker_eventUpdateProjectionMarker_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_HeightOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_EditDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_Normal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_Mode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_Mode_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelProjectionMarker, "UpdateProjectionMarker", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04820401, sizeof(VoxelProjectionMarker_eventUpdateProjectionMarker_Parms), Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AVoxelProjectionMarker_NoRegister()
	{
		return AVoxelProjectionMarker::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelProjectionMarker_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MaterialInstance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Decal_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Decal;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelProjectionMarker_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AVoxelMarker,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVoxelProjectionMarker_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVoxelProjectionMarker_UpdateProjectionMarker, "UpdateProjectionMarker" }, // 1041044202
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelProjectionMarker_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "VoxelTools/VoxelMarker.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelProjectionMarker_Statics::NewProp_MaterialInstance_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelProjectionMarker_Statics::NewProp_MaterialInstance = { UE4CodeGen_Private::EPropertyClass::Object, "MaterialInstance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000004, 1, nullptr, STRUCT_OFFSET(AVoxelProjectionMarker, MaterialInstance), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelProjectionMarker_Statics::NewProp_MaterialInstance_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelProjectionMarker_Statics::NewProp_MaterialInstance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelProjectionMarker_Statics::NewProp_Decal_MetaData[] = {
		{ "Category", "Voxel" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelProjectionMarker_Statics::NewProp_Decal = { UE4CodeGen_Private::EPropertyClass::Object, "Decal", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x001000000008000c, 1, nullptr, STRUCT_OFFSET(AVoxelProjectionMarker, Decal), Z_Construct_UClass_UDecalComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelProjectionMarker_Statics::NewProp_Decal_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelProjectionMarker_Statics::NewProp_Decal_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelProjectionMarker_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelProjectionMarker_Statics::NewProp_MaterialInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelProjectionMarker_Statics::NewProp_Decal,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelProjectionMarker_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelProjectionMarker>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelProjectionMarker_Statics::ClassParams = {
		&AVoxelProjectionMarker::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AVoxelProjectionMarker_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelProjectionMarker_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelProjectionMarker_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelProjectionMarker_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelProjectionMarker()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelProjectionMarker_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelProjectionMarker, 644119080);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelProjectionMarker(Z_Construct_UClass_AVoxelProjectionMarker, &AVoxelProjectionMarker::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelProjectionMarker"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelProjectionMarker);
	void AVoxelSphereMarker::StaticRegisterNativesAVoxelSphereMarker()
	{
		UClass* Class = AVoxelSphereMarker::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UpdateSphereMarker", &AVoxelSphereMarker::execUpdateSphereMarker },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics
	{
		struct VoxelSphereMarker_eventUpdateSphereMarker_Parms
		{
			AVoxelWorld* World;
			EVoxelMode Mode;
			FIntVector Position;
			float Radius;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Mode;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelSphereMarker_eventUpdateSphereMarker_Parms, Radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Struct, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelSphereMarker_eventUpdateSphereMarker_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::NewProp_Mode = { UE4CodeGen_Private::EPropertyClass::Enum, "Mode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelSphereMarker_eventUpdateSphereMarker_Parms, Mode), Z_Construct_UEnum_Voxel_EVoxelMode, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::NewProp_Mode_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelSphereMarker_eventUpdateSphereMarker_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::NewProp_Mode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::NewProp_Mode_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelSphereMarker, "UpdateSphereMarker", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04820401, sizeof(VoxelSphereMarker_eventUpdateSphereMarker_Parms), Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AVoxelSphereMarker_NoRegister()
	{
		return AVoxelSphereMarker::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelSphereMarker_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Material;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialParent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MaterialParent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StaticMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelSphereMarker_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AVoxelMarker,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVoxelSphereMarker_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVoxelSphereMarker_UpdateSphereMarker, "UpdateSphereMarker" }, // 1906510341
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelSphereMarker_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "VoxelTools/VoxelMarker.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_Material_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Object, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000004, 1, nullptr, STRUCT_OFFSET(AVoxelSphereMarker, Material), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_Material_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_Material_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_MaterialParent_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_MaterialParent = { UE4CodeGen_Private::EPropertyClass::Object, "MaterialParent", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000004, 1, nullptr, STRUCT_OFFSET(AVoxelSphereMarker, MaterialParent), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_MaterialParent_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_MaterialParent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_StaticMesh_MetaData[] = {
		{ "Category", "Voxel" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_StaticMesh = { UE4CodeGen_Private::EPropertyClass::Object, "StaticMesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x001000000008000c, 1, nullptr, STRUCT_OFFSET(AVoxelSphereMarker, StaticMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_StaticMesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_StaticMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelSphereMarker_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_Material,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_MaterialParent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelSphereMarker_Statics::NewProp_StaticMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelSphereMarker_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelSphereMarker>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelSphereMarker_Statics::ClassParams = {
		&AVoxelSphereMarker::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AVoxelSphereMarker_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelSphereMarker_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelSphereMarker_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelSphereMarker_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelSphereMarker()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelSphereMarker_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelSphereMarker, 990238800);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelSphereMarker(Z_Construct_UClass_AVoxelSphereMarker, &AVoxelSphereMarker::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelSphereMarker"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelSphereMarker);
	void AVoxelBoxMarker::StaticRegisterNativesAVoxelBoxMarker()
	{
		UClass* Class = AVoxelBoxMarker::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UpdateBoxMarker", &AVoxelBoxMarker::execUpdateBoxMarker },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics
	{
		struct VoxelBoxMarker_eventUpdateBoxMarker_Parms
		{
			AVoxelWorld* World;
			EVoxelMode Mode;
			FIntBox Bounds;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Bounds;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Mode;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::NewProp_Bounds = { UE4CodeGen_Private::EPropertyClass::Struct, "Bounds", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBoxMarker_eventUpdateBoxMarker_Parms, Bounds), Z_Construct_UScriptStruct_FIntBox, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::NewProp_Mode = { UE4CodeGen_Private::EPropertyClass::Enum, "Mode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBoxMarker_eventUpdateBoxMarker_Parms, Mode), Z_Construct_UEnum_Voxel_EVoxelMode, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::NewProp_Mode_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelBoxMarker_eventUpdateBoxMarker_Parms, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::NewProp_Bounds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::NewProp_Mode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::NewProp_Mode_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelBoxMarker, "UpdateBoxMarker", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VoxelBoxMarker_eventUpdateBoxMarker_Parms), Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AVoxelBoxMarker_NoRegister()
	{
		return AVoxelBoxMarker::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelBoxMarker_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Material;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialParent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MaterialParent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StaticMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelBoxMarker_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AVoxelMarker,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVoxelBoxMarker_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVoxelBoxMarker_UpdateBoxMarker, "UpdateBoxMarker" }, // 3828330032
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelBoxMarker_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "VoxelTools/VoxelMarker.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_Material_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Object, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000004, 1, nullptr, STRUCT_OFFSET(AVoxelBoxMarker, Material), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_Material_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_Material_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_MaterialParent_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_MaterialParent = { UE4CodeGen_Private::EPropertyClass::Object, "MaterialParent", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000004, 1, nullptr, STRUCT_OFFSET(AVoxelBoxMarker, MaterialParent), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_MaterialParent_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_MaterialParent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_StaticMesh_MetaData[] = {
		{ "Category", "Voxel" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelMarker.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_StaticMesh = { UE4CodeGen_Private::EPropertyClass::Object, "StaticMesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x001000000008000c, 1, nullptr, STRUCT_OFFSET(AVoxelBoxMarker, StaticMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_StaticMesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_StaticMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelBoxMarker_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_Material,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_MaterialParent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelBoxMarker_Statics::NewProp_StaticMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelBoxMarker_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelBoxMarker>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelBoxMarker_Statics::ClassParams = {
		&AVoxelBoxMarker::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AVoxelBoxMarker_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelBoxMarker_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelBoxMarker_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelBoxMarker_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelBoxMarker()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelBoxMarker_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelBoxMarker, 3581333431);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelBoxMarker(Z_Construct_UClass_AVoxelBoxMarker, &AVoxelBoxMarker::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelBoxMarker"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelBoxMarker);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
