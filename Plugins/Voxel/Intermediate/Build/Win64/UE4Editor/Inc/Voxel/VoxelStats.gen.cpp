// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelDebug/VoxelStats.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelStats() {}
// Cross Module References
	VOXEL_API UEnum* Z_Construct_UEnum_Voxel_EVoxelStatsType();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelStatsHelper_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelStatsHelper();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelStatsHelper_StartRecordingStats();
	VOXEL_API UFunction* Z_Construct_UFunction_UVoxelStatsHelper_StopRecordingStatsAndSaveStatsFile();
// End Cross Module References
	static UEnum* EVoxelStatsType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Voxel_EVoxelStatsType, Z_Construct_UPackage__Script_Voxel(), TEXT("EVoxelStatsType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelStatsType(EVoxelStatsType_StaticEnum, TEXT("/Script/Voxel"), TEXT("EVoxelStatsType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Voxel_EVoxelStatsType_CRC() { return 1956733109U; }
	UEnum* Z_Construct_UEnum_Voxel_EVoxelStatsType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Voxel();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelStatsType"), 0, Get_Z_Construct_UEnum_Voxel_EVoxelStatsType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVoxelStatsType::NormalMarchingCubes", (int64)EVoxelStatsType::NormalMarchingCubes },
				{ "EVoxelStatsType::TransitionsMarchingCubes", (int64)EVoxelStatsType::TransitionsMarchingCubes },
				{ "EVoxelStatsType::NormalCubic", (int64)EVoxelStatsType::NormalCubic },
				{ "EVoxelStatsType::TransitionsCubic", (int64)EVoxelStatsType::TransitionsCubic },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/VoxelDebug/VoxelStats.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Voxel,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVoxelStatsType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVoxelStatsType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void UVoxelStatsHelper::StaticRegisterNativesUVoxelStatsHelper()
	{
		UClass* Class = UVoxelStatsHelper::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "StartRecordingStats", &UVoxelStatsHelper::execStartRecordingStats },
			{ "StopRecordingStatsAndSaveStatsFile", &UVoxelStatsHelper::execStopRecordingStatsAndSaveStatsFile },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelStatsHelper_StartRecordingStats_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelStatsHelper_StartRecordingStats_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelDebug/VoxelStats.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelStatsHelper_StartRecordingStats_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelStatsHelper, "StartRecordingStats", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelStatsHelper_StartRecordingStats_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelStatsHelper_StartRecordingStats_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelStatsHelper_StartRecordingStats()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelStatsHelper_StartRecordingStats_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelStatsHelper_StopRecordingStatsAndSaveStatsFile_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelStatsHelper_StopRecordingStatsAndSaveStatsFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelDebug/VoxelStats.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelStatsHelper_StopRecordingStatsAndSaveStatsFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelStatsHelper, "StopRecordingStatsAndSaveStatsFile", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelStatsHelper_StopRecordingStatsAndSaveStatsFile_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelStatsHelper_StopRecordingStatsAndSaveStatsFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelStatsHelper_StopRecordingStatsAndSaveStatsFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelStatsHelper_StopRecordingStatsAndSaveStatsFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelStatsHelper_NoRegister()
	{
		return UVoxelStatsHelper::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelStatsHelper_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelStatsHelper_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelStatsHelper_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelStatsHelper_StartRecordingStats, "StartRecordingStats" }, // 2819775434
		{ &Z_Construct_UFunction_UVoxelStatsHelper_StopRecordingStatsAndSaveStatsFile, "StopRecordingStatsAndSaveStatsFile" }, // 1644473243
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelStatsHelper_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelDebug/VoxelStats.h" },
		{ "ModuleRelativePath", "Public/VoxelDebug/VoxelStats.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelStatsHelper_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelStatsHelper>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelStatsHelper_Statics::ClassParams = {
		&UVoxelStatsHelper::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelStatsHelper_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelStatsHelper_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelStatsHelper()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelStatsHelper_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelStatsHelper, 1319219394);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelStatsHelper(Z_Construct_UClass_UVoxelStatsHelper, &UVoxelStatsHelper::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelStatsHelper"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelStatsHelper);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
