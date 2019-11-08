// Copyright 2018 Phyronnaz

#include "AssetTypeActions_VoxelDataAsset.h"
#include "VoxelEditorModule.h"

void FAssetTypeActions_VoxelDataAsset::OpenAssetEditor(const TArray<UObject *>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto DataAsset = Cast<UVoxelDataAsset>(*ObjIt);
		if (DataAsset != NULL)
		{
			IVoxelEditorModule* VoxelEditorModule = &FModuleManager::LoadModuleChecked<IVoxelEditorModule>("VoxelEditor");
			VoxelEditorModule->CreateVoxelDataAssetEditor(Mode, EditWithinLevelEditor, DataAsset);
		}
	}
}
