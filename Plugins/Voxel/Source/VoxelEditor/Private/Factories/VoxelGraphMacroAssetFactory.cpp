// Copyright 2018 Phyronnaz

#include "VoxelGraphMacroAssetFactory.h"
#include "AssetTypeCategories.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "VoxelGraph/VoxelGraphMacro.h"

UVoxelGraphMacroAssetFactory::UVoxelGraphMacroAssetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UVoxelGraphMacro::StaticClass();
}

UObject* UVoxelGraphMacroAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	auto NewAsset = NewObject<UVoxelGraphMacro>(InParent, Class, Name, Flags);

	return NewAsset;
}
