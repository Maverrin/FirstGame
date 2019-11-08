// Copyright 2018 Phyronnaz

#include "VoxelDataAssetImportFactory.h"
#include "AssetTypeCategories.h"
#include "VoxelAssets/VoxelDataAsset.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Misc/MessageDialog.h"
#include "VoxelEditorModule.h"
#include "Importers/MagicaVox.h"
#include "Importers/RawVox.h"

UVoxelDataAssetImportFactory::UVoxelDataAssetImportFactory()
{
	bEditorImport = true;
	SupportedClass = UVoxelDataAsset::StaticClass();
	Formats.Add(TEXT("vox;Magica Voxel Asset"));
	Formats.Add(TEXT("rawvox;3D Coat RawVox"));
}

bool UVoxelDataAssetImportFactory::FactoryCanImport(const FString& Filename)
{
	if (FPaths::GetExtension(Filename) == TEXT("vox"))
	{
		return true;
	}
	if (FPaths::GetExtension(Filename) == TEXT("rawvox"))
	{
		return true;
	}
	return false;
}

UObject* UVoxelDataAssetImportFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName Name, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	FString FileExtension = FPaths::GetExtension(Filename);
	auto NewDataAsset = NewObject<UVoxelDataAsset>(InParent, Name, Flags);

	TSharedRef<FVoxelDataAssetData, ESPMode::ThreadSafe> Data = MakeShared<FVoxelDataAssetData, ESPMode::ThreadSafe>();
		
	if (FileExtension == TEXT("vox"))
	{
		MagicaVox::ImportToAsset(Filename, *Data);
	}
	else if (FileExtension == TEXT("rawvox"))
	{
		RawVox::ImportToAsset(Filename, *Data);
	}
	else
	{
		UE_LOG(LogVoxelEditor, Error, TEXT("Failed to load file '%s' to array"), *Filename);
	}

	NewDataAsset->SetData(Data);

	return NewDataAsset;
}
