// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelWorldGenerators/VoxelSphereWorldGenerator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelSphereWorldGenerator() {}
// Cross Module References
	VOXEL_API UClass* Z_Construct_UClass_UVoxelSphereWorldGenerator_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelSphereWorldGenerator();
	VOXEL_API UClass* Z_Construct_UClass_UVoxelWorldGenerator();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterial();
// End Cross Module References
	void UVoxelSphereWorldGenerator::StaticRegisterNativesUVoxelSphereWorldGenerator()
	{
	}
	UClass* Z_Construct_UClass_UVoxelSphereWorldGenerator_NoRegister()
	{
		return UVoxelSphereWorldGenerator::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InverseOutsideInside_MetaData[];
#endif
		static void NewProp_InverseOutsideInside_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_InverseOutsideInside;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVoxelWorldGenerator,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "VoxelWorldGenerators/VoxelSphereWorldGenerator.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VoxelWorldGenerators/VoxelSphereWorldGenerator.h" },
		{ "ToolTip", "Sphere World" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_InverseOutsideInside_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelWorldGenerators/VoxelSphereWorldGenerator.h" },
		{ "ToolTip", "If true, sphere is a hole in a full world" },
	};
#endif
	void Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_InverseOutsideInside_SetBit(void* Obj)
	{
		((UVoxelSphereWorldGenerator*)Obj)->InverseOutsideInside = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_InverseOutsideInside = { UE4CodeGen_Private::EPropertyClass::Bool, "InverseOutsideInside", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UVoxelSphereWorldGenerator), &Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_InverseOutsideInside_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_InverseOutsideInside_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_InverseOutsideInside_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_Material_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelWorldGenerators/VoxelSphereWorldGenerator.h" },
		{ "ToolTip", "Material of the sphere" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Struct, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelSphereWorldGenerator, Material), Z_Construct_UScriptStruct_FVoxelMaterial, METADATA_PARAMS(Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_Material_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_Material_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelWorldGenerators/VoxelSphereWorldGenerator.h" },
		{ "ToolTip", "Radius of the sphere in voxels" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UVoxelSphereWorldGenerator, Radius), METADATA_PARAMS(Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_Radius_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_Radius_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_InverseOutsideInside,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_Material,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::NewProp_Radius,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelSphereWorldGenerator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::ClassParams = {
		&UVoxelSphereWorldGenerator::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelSphereWorldGenerator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelSphereWorldGenerator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelSphereWorldGenerator, 1331850179);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelSphereWorldGenerator(Z_Construct_UClass_UVoxelSphereWorldGenerator, &UVoxelSphereWorldGenerator::StaticClass, TEXT("/Script/Voxel"), TEXT("UVoxelSphereWorldGenerator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelSphereWorldGenerator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
