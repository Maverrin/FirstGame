// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Voxel/Public/VoxelTools/VoxelPart.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelPart() {}
// Cross Module References
	VOXEL_API UFunction* Z_Construct_UDelegateFunction_Voxel_VoxelPartOnLoaded__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_Voxel();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelPart_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelPart();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelWorld_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelPartSimpleMesh_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelPartSimpleMesh();
	VOXEL_API UScriptStruct* Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelPartCube_NoRegister();
	VOXEL_API UClass* Z_Construct_UClass_AVoxelPartCube();
	VOXEL_API UFunction* Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_Voxel_VoxelPartOnLoaded__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Voxel_VoxelPartOnLoaded__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelPart.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Voxel_VoxelPartOnLoaded__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Voxel, "VoxelPartOnLoaded__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Voxel_VoxelPartOnLoaded__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_Voxel_VoxelPartOnLoaded__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Voxel_VoxelPartOnLoaded__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_Voxel_VoxelPartOnLoaded__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void AVoxelPart::StaticRegisterNativesAVoxelPart()
	{
	}
	UClass* Z_Construct_UClass_AVoxelPart_NoRegister()
	{
		return AVoxelPart::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelPart_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnLoaded_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLoaded;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_World_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelPart_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPart_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelTools/VoxelPart.h" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelPart.h" },
		{ "ToolTip", "Abstract class, DO NOT USE DIRECTLY" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPart_Statics::NewProp_OnLoaded_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelPart.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AVoxelPart_Statics::NewProp_OnLoaded = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnLoaded", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000010080000, 1, nullptr, STRUCT_OFFSET(AVoxelPart, OnLoaded), Z_Construct_UDelegateFunction_Voxel_VoxelPartOnLoaded__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_AVoxelPart_Statics::NewProp_OnLoaded_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPart_Statics::NewProp_OnLoaded_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPart_Statics::NewProp_World_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelPart.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelPart_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000020015, 1, nullptr, STRUCT_OFFSET(AVoxelPart, World), Z_Construct_UClass_AVoxelWorld_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelPart_Statics::NewProp_World_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPart_Statics::NewProp_World_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelPart_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPart_Statics::NewProp_OnLoaded,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPart_Statics::NewProp_World,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelPart_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelPart>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelPart_Statics::ClassParams = {
		&AVoxelPart::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x049002A1u,
		nullptr, 0,
		Z_Construct_UClass_AVoxelPart_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelPart_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelPart_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelPart_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelPart()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelPart_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelPart, 3217957091);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelPart(Z_Construct_UClass_AVoxelPart, &AVoxelPart::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelPart"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelPart);
	void AVoxelPartSimpleMesh::StaticRegisterNativesAVoxelPartSimpleMesh()
	{
	}
	UClass* Z_Construct_UClass_AVoxelPartSimpleMesh_NoRegister()
	{
		return AVoxelPartSimpleMesh::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelPartSimpleMesh_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialsRef_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MaterialsRef;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AVoxelPart,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelTools/VoxelPart.h" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelPart.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::NewProp_MaterialsRef_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelPart.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::NewProp_MaterialsRef = { UE4CodeGen_Private::EPropertyClass::Struct, "MaterialsRef", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(AVoxelPartSimpleMesh, MaterialsRef), Z_Construct_UScriptStruct_FVoxelMaterialsRefHolder, METADATA_PARAMS(Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::NewProp_MaterialsRef_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::NewProp_MaterialsRef_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::NewProp_MaterialsRef,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelPartSimpleMesh>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::ClassParams = {
		&AVoxelPartSimpleMesh::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A0u,
		nullptr, 0,
		Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelPartSimpleMesh()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelPartSimpleMesh_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelPartSimpleMesh, 1274261025);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelPartSimpleMesh(Z_Construct_UClass_AVoxelPartSimpleMesh, &AVoxelPartSimpleMesh::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelPartSimpleMesh"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelPartSimpleMesh);
	static FName NAME_AVoxelPartCube_OnCubesCreated = FName(TEXT("OnCubesCreated"));
	void AVoxelPartCube::OnCubesCreated(TArray<AStaticMeshActor*> const& Cubes)
	{
		VoxelPartCube_eventOnCubesCreated_Parms Parms;
		Parms.Cubes=Cubes;
		ProcessEvent(FindFunctionChecked(NAME_AVoxelPartCube_OnCubesCreated),&Parms);
	}
	void AVoxelPartCube::StaticRegisterNativesAVoxelPartCube()
	{
	}
	struct Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Cubes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Cubes;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Cubes_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::NewProp_Cubes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::NewProp_Cubes = { UE4CodeGen_Private::EPropertyClass::Array, "Cubes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelPartCube_eventOnCubesCreated_Parms, Cubes), METADATA_PARAMS(Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::NewProp_Cubes_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::NewProp_Cubes_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::NewProp_Cubes_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Cubes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_AStaticMeshActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::NewProp_Cubes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::NewProp_Cubes_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelPart.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelPartCube, "OnCubesCreated", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420800, sizeof(VoxelPartCube_eventOnCubesCreated_Parms), Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AVoxelPartCube_NoRegister()
	{
		return AVoxelPartCube::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelPartCube_Statics
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
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelPartCube_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AVoxelPart,
		(UObject* (*)())Z_Construct_UPackage__Script_Voxel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVoxelPartCube_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVoxelPartCube_OnCubesCreated, "OnCubesCreated" }, // 1113871918
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPartCube_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelTools/VoxelPart.h" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelPart.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPartCube_Statics::NewProp_Material_MetaData[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelTools/VoxelPart.h" },
		{ "ToolTip", "Same material as the voxel world, but instead of a vertex color input use a vector parameter named VertexColor" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelPartCube_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Object, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010001, 1, nullptr, STRUCT_OFFSET(AVoxelPartCube, Material), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelPartCube_Statics::NewProp_Material_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPartCube_Statics::NewProp_Material_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelPartCube_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPartCube_Statics::NewProp_Material,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelPartCube_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelPartCube>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelPartCube_Statics::ClassParams = {
		&AVoxelPartCube::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AVoxelPartCube_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelPartCube_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelPartCube_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelPartCube_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelPartCube()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelPartCube_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelPartCube, 3924106271);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelPartCube(Z_Construct_UClass_AVoxelPartCube, &AVoxelPartCube::StaticClass, TEXT("/Script/Voxel"), TEXT("AVoxelPartCube"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelPartCube);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
