// Copyright 2018 Phyronnaz

#include "VoxelSplineImporterDetails.h"
#include "VoxelImporters/VoxelSplineImporter.h"

#include "Factories/VoxelDataAssetFactory.h"
#include "VoxelAssets/VoxelDataAsset.h"

#include "VoxelEditorDetailsUtils.h"

#define LOCTEXT_NAMESPACE "VoxelSplineImporterDetails"

TSharedRef<IDetailCustomization> FVoxelSplineImporterDetails::MakeInstance()
{
	return MakeShareable(new FVoxelSplineImporterDetails());
}

void FVoxelSplineImporterDetails::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	SplineImporter = FVoxelEditorDetailsUtils::GetCurrentObjectFromDetails<AVoxelSplineImporter>(DetailLayout);

	ADD_BUTTON_TO_CATEGORY(DetailLayout,
		"Create VoxelDataAsset from Splines",
		LOCTEXT("Create", "Create"),
		LOCTEXT("CreateFromSplines", "Create From Splines"),
		LOCTEXT("Create", "Create"),
		this,
		&FVoxelSplineImporterDetails::OnCreateFromSplines)
}

FReply FVoxelSplineImporterDetails::OnCreateFromSplines()
{
	if (SplineImporter.IsValid())
	{
		if (SplineImporter->Splines.Num() == 0)
		{
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("No splines")));
		}
		else
		{
			FVoxelEditorDetailsUtils::CreateAsset<UVoxelDataAsset, UVoxelDataAssetFactory>([&](UVoxelDataAsset* DataAsset)
			{
				TSharedRef<FVoxelDataAssetData, ESPMode::ThreadSafe> Data = MakeShared<FVoxelDataAssetData, ESPMode::ThreadSafe>();
				SplineImporter->ImportToAsset(*Data);
				DataAsset->SetData(Data);
				return true;
			});
		}
	}

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
