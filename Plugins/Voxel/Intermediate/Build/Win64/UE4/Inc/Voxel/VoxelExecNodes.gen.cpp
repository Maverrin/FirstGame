// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelGraph/VoxelExecNodes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelExecNodes() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_If_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_If();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNodeHelper();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_SetValue_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_SetValue();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_SetColor_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_SetColor();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelMaterialNode();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_SetDoubleIndex_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_SetDoubleIndex();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_SetVoxelSpawnedActorId_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_SetVoxelSpawnedActorId();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_SetVoxelGrassId_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_SetVoxelGrassId();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_SetIndex_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_SetIndex();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_FlowMerge_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelNode_FlowMerge();
// End Cross Module References
	void UVoxelNode_If::StaticRegisterNativesUVoxelNode_If()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_If_NoRegister()
	{
		return UVoxelNode_If::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_If_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_If_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNodeHelper,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_If_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "If" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExecNodes.h" },
		{ "Keywords", "branch" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExecNodes.h" },
		{ "ToolTip", "Branch node" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_If_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode_If>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_If_Statics::ClassParams = {
		&UVoxelNode_If::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_If_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_If_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode_If()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_If_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode_If, 3439149354);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode_If(Z_Construct_UClass_UVoxelNode_If, &UVoxelNode_If::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode_If"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode_If);
	void UVoxelNode_SetValue::StaticRegisterNativesUVoxelNode_SetValue()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_SetValue_NoRegister()
	{
		return UVoxelNode_SetValue::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_SetValue_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDisableClamp_MetaData[];
#endif
		static void NewProp_bDisableClamp_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDisableClamp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_SetValue_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNodeHelper,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_SetValue_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Set Value" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExecNodes.h" },
		{ "Keywords", "density" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExecNodes.h" },
		{ "ToolTip", "Set the density at that position" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_SetValue_Statics::NewProp_bDisableClamp_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExecNodes.h" },
	};
#endif
	void Z_Construct_UClass_UVoxelNode_SetValue_Statics::NewProp_bDisableClamp_SetBit(void* Obj)
	{
		((UVoxelNode_SetValue*)Obj)->bDisableClamp = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelNode_SetValue_Statics::NewProp_bDisableClamp = { UE4CodeGen_Private::EPropertyClass::Bool, "bDisableClamp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelNode_SetValue), &Z_Construct_UClass_UVoxelNode_SetValue_Statics::NewProp_bDisableClamp_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_SetValue_Statics::NewProp_bDisableClamp_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_SetValue_Statics::NewProp_bDisableClamp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelNode_SetValue_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelNode_SetValue_Statics::NewProp_bDisableClamp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_SetValue_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode_SetValue>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_SetValue_Statics::ClassParams = {
		&UVoxelNode_SetValue::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelNode_SetValue_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_SetValue_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_SetValue_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_SetValue_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode_SetValue()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_SetValue_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode_SetValue, 380023856);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode_SetValue(Z_Construct_UClass_UVoxelNode_SetValue, &UVoxelNode_SetValue::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode_SetValue"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode_SetValue);
	void UVoxelNode_SetColor::StaticRegisterNativesUVoxelNode_SetColor()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_SetColor_NoRegister()
	{
		return UVoxelNode_SetColor::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_SetColor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_SetColor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelMaterialNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_SetColor_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Set Color" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExecNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExecNodes.h" },
		{ "ToolTip", "Set the color at that position. Inputs between 0 and 1" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_SetColor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode_SetColor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_SetColor_Statics::ClassParams = {
		&UVoxelNode_SetColor::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_SetColor_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_SetColor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode_SetColor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_SetColor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode_SetColor, 2401534925);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode_SetColor(Z_Construct_UClass_UVoxelNode_SetColor, &UVoxelNode_SetColor::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode_SetColor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode_SetColor);
	void UVoxelNode_SetDoubleIndex::StaticRegisterNativesUVoxelNode_SetDoubleIndex()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_SetDoubleIndex_NoRegister()
	{
		return UVoxelNode_SetDoubleIndex::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_SetDoubleIndex_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_SetDoubleIndex_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelMaterialNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_SetDoubleIndex_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Set Double Index" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExecNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExecNodes.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_SetDoubleIndex_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode_SetDoubleIndex>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_SetDoubleIndex_Statics::ClassParams = {
		&UVoxelNode_SetDoubleIndex::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_SetDoubleIndex_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_SetDoubleIndex_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode_SetDoubleIndex()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_SetDoubleIndex_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode_SetDoubleIndex, 291682212);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode_SetDoubleIndex(Z_Construct_UClass_UVoxelNode_SetDoubleIndex, &UVoxelNode_SetDoubleIndex::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode_SetDoubleIndex"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode_SetDoubleIndex);
	void UVoxelNode_SetVoxelSpawnedActorId::StaticRegisterNativesUVoxelNode_SetVoxelSpawnedActorId()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_SetVoxelSpawnedActorId_NoRegister()
	{
		return UVoxelNode_SetVoxelSpawnedActorId::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_SetVoxelSpawnedActorId_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_SetVoxelSpawnedActorId_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelMaterialNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_SetVoxelSpawnedActorId_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Set Voxel Actor Id" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExecNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExecNodes.h" },
		{ "ToolTip", "Set the Voxel Spawned Actor Id at that position" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_SetVoxelSpawnedActorId_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode_SetVoxelSpawnedActorId>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_SetVoxelSpawnedActorId_Statics::ClassParams = {
		&UVoxelNode_SetVoxelSpawnedActorId::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_SetVoxelSpawnedActorId_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_SetVoxelSpawnedActorId_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode_SetVoxelSpawnedActorId()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_SetVoxelSpawnedActorId_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode_SetVoxelSpawnedActorId, 466625525);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode_SetVoxelSpawnedActorId(Z_Construct_UClass_UVoxelNode_SetVoxelSpawnedActorId, &UVoxelNode_SetVoxelSpawnedActorId::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode_SetVoxelSpawnedActorId"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode_SetVoxelSpawnedActorId);
	void UVoxelNode_SetVoxelGrassId::StaticRegisterNativesUVoxelNode_SetVoxelGrassId()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_SetVoxelGrassId_NoRegister()
	{
		return UVoxelNode_SetVoxelGrassId::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_SetVoxelGrassId_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_SetVoxelGrassId_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelMaterialNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_SetVoxelGrassId_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Set Voxel Grass Id" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExecNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExecNodes.h" },
		{ "ToolTip", "Set the Voxel Grass Id at that position" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_SetVoxelGrassId_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode_SetVoxelGrassId>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_SetVoxelGrassId_Statics::ClassParams = {
		&UVoxelNode_SetVoxelGrassId::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_SetVoxelGrassId_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_SetVoxelGrassId_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode_SetVoxelGrassId()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_SetVoxelGrassId_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode_SetVoxelGrassId, 2705850638);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode_SetVoxelGrassId(Z_Construct_UClass_UVoxelNode_SetVoxelGrassId, &UVoxelNode_SetVoxelGrassId::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode_SetVoxelGrassId"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode_SetVoxelGrassId);
	void UVoxelNode_SetIndex::StaticRegisterNativesUVoxelNode_SetIndex()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_SetIndex_NoRegister()
	{
		return UVoxelNode_SetIndex::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_SetIndex_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_SetIndex_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelMaterialNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_SetIndex_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Set Index" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExecNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExecNodes.h" },
		{ "ToolTip", "Set the material index at that position. Input clamped between 0 and 255" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_SetIndex_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode_SetIndex>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_SetIndex_Statics::ClassParams = {
		&UVoxelNode_SetIndex::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_SetIndex_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_SetIndex_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode_SetIndex()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_SetIndex_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode_SetIndex, 3503314666);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode_SetIndex(Z_Construct_UClass_UVoxelNode_SetIndex, &UVoxelNode_SetIndex::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode_SetIndex"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode_SetIndex);
	void UVoxelNode_FlowMerge::StaticRegisterNativesUVoxelNode_FlowMerge()
	{
	}
	UClass* Z_Construct_UClass_UVoxelNode_FlowMerge_NoRegister()
	{
		return UVoxelNode_FlowMerge::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelNode_FlowMerge_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelNode_FlowMerge_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelNodeHelper,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelNode_FlowMerge_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Flow Merge" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "VoxelGraph/VoxelExecNodes.h" },
		{ "ModuleRelativePath", "Public/VoxelGraph/VoxelExecNodes.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelNode_FlowMerge_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelNode_FlowMerge>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelNode_FlowMerge_Statics::ClassParams = {
		&UVoxelNode_FlowMerge::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelNode_FlowMerge_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelNode_FlowMerge_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelNode_FlowMerge()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelNode_FlowMerge_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelNode_FlowMerge, 3315941708);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelNode_FlowMerge(Z_Construct_UClass_UVoxelNode_FlowMerge, &UVoxelNode_FlowMerge::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelNode_FlowMerge"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelNode_FlowMerge);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
