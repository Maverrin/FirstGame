// Copyright 2018 Phyronnaz

#include "AssetTypeActions_VoxelGraphMacro.h"
#include "Misc/PackageName.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"
#include "VoxelGraph/VoxelGraphMacro.h"
#include "VoxelEditorModule.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

UClass* FAssetTypeActions_VoxelGraphMacro::GetSupportedClass() const
{
	return UVoxelGraphMacro::StaticClass();
}

void FAssetTypeActions_VoxelGraphMacro::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto VoxelGraphMacro = Cast<UVoxelGraphMacro>(*ObjIt);
		if (VoxelGraphMacro != NULL)
		{
			IVoxelEditorModule* VoxelEditorModule = &FModuleManager::LoadModuleChecked<IVoxelEditorModule>("VoxelEditor");
			VoxelEditorModule->CreateVoxelGraphEditor(Mode, EditWithinLevelEditor, VoxelGraphMacro);
		}
	}
}
uint32 FAssetTypeActions_VoxelGraphMacro::GetCategories()
{
	return MyAssetCategory;
}
#undef LOCTEXT_NAMESPACE
