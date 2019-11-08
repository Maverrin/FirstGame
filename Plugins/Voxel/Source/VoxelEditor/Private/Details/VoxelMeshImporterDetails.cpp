// Copyright 2018 Phyronnaz

#include "VoxelMeshImporterDetails.h"
#include "VoxelImporters/VoxelMeshImporter.h"

#include "Factories/VoxelDataAssetFactory.h"
#include "VoxelAssets/VoxelDataAsset.h"

#include "Misc/MessageDialog.h"

#include "VoxelEditorDetailsUtils.h"

#define LOCTEXT_NAMESPACE "VoxelMeshImporterDetails"

TSharedRef<IDetailCustomization> FVoxelMeshImporterDetails::MakeInstance()
{
	return MakeShareable(new FVoxelMeshImporterDetails());
}

void FVoxelMeshImporterDetails::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	MeshImporter = FVoxelEditorDetailsUtils::GetCurrentObjectFromDetails<AVoxelMeshImporter>(DetailLayout);

	ADD_BUTTON_TO_CATEGORY(DetailLayout,
		"Create VoxelDataAsset from Mesh",
		LOCTEXT("Create", "Create"),
		LOCTEXT("CreateFromMesh", "Create From Mesh"),
		LOCTEXT("Create", "Create"),
		this,
		&FVoxelMeshImporterDetails::OnCreateFromMesh)
}

FReply FVoxelMeshImporterDetails::OnCreateFromMesh()
{
	if (MeshImporter.IsValid())
	{
		if (!MeshImporter->StaticMesh)
		{
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("Invalid Mesh")));
		}
		else
		{
			FVoxelEditorDetailsUtils::CreateAsset<UVoxelDataAsset, UVoxelDataAssetFactory>([&](UVoxelDataAsset* DataAsset)
			{
				TSharedRef<FVoxelDataAssetData, ESPMode::ThreadSafe> Data = MakeShared<FVoxelDataAssetData, ESPMode::ThreadSafe>();
				MeshImporter->ImportToAsset(*Data, DataAsset->Offset);
				DataAsset->SetData(Data);
				return true;
			});
		}
	}
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
