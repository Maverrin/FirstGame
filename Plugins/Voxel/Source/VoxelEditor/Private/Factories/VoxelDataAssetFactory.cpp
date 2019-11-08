// Copyright 2018 Phyronnaz

#include "VoxelDataAssetFactory.h"
#include "AssetTypeCategories.h"
#include "VoxelAssets/VoxelDataAsset.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Misc/MessageDialog.h"
#include "VoxelEditorModule.h"

UVoxelDataAssetFactory::UVoxelDataAssetFactory()
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UVoxelDataAsset::StaticClass();
}

UObject* UVoxelDataAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	auto NewDataAsset = NewObject<UVoxelDataAsset>(InParent, Class, Name, Flags);

	TSharedRef<FVoxelDataAssetData, ESPMode::ThreadSafe> Data = MakeShared<FVoxelDataAssetData, ESPMode::ThreadSafe>();
	Data->SetSize(FIntVector(1, 1, 1), false);
	Data->SetValue(0, 0, 0, FVoxelValue::Full);
	NewDataAsset->SetData(Data);

	return NewDataAsset;
}

