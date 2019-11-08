// Copyright 2018 Phyronnaz

#include "VoxelAssetActorDetails.h"
#include "VoxelPlaceableItems/VoxelAssetActor.h"

#include "VoxelEditorDetailsUtils.h"

#define LOCTEXT_NAMESPACE "VoxelAssetActorDetails"

TSharedRef<IDetailCustomization> FVoxelAssetActorDetails::MakeInstance()
{
	return MakeShareable(new FVoxelAssetActorDetails());
}

FVoxelAssetActorDetails::FVoxelAssetActorDetails()
{

}

void FVoxelAssetActorDetails::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	AssetActor = FVoxelEditorDetailsUtils::GetCurrentObjectFromDetails<AVoxelAssetActor>(DetailLayout);

	DetailLayout.EditCategory("Preview Settings")
			.AddCustomRow(LOCTEXT("AssetUpdate", "Voxel Asset Update"))
			.NameContent()
			[
				SNew(STextBlock)
				.Font(IDetailLayoutBuilder::GetDetailFont())
				.Text(LOCTEXT("UpdateRender", "Update Render"))
			]
			.ValueContent()
			.MaxDesiredWidth(125.f)
			.MinDesiredWidth(125.f)
			[
				SNew(SButton)
				.ContentPadding(2)
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				.OnClicked(this, &FVoxelAssetActorDetails::OnUpdate)
				[
					SNew(STextBlock)
					.Font(IDetailLayoutBuilder::GetDetailFont())
					.Text(LOCTEXT("Update", "Update"))
				]
				.IsEnabled(this, &FVoxelAssetActorDetails::IsEnabled)
			];
}

FReply FVoxelAssetActorDetails::OnUpdate()
{
	if (AssetActor.IsValid())
	{
		if (!AssetActor->World)
		{
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("", "Invalid Voxel World"));
		}
		else if (!AssetActor->Asset)
		{
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("", "Invalid Voxel Asset"));
		}
		else
		{
			AssetActor->Update();
		}
	}

	return FReply::Handled();
}

bool FVoxelAssetActorDetails::IsEnabled() const
{
	return AssetActor.IsValid() && AssetActor->GetWorld()->WorldType == EWorldType::Editor;
}

#undef LOCTEXT_NAMESPACE
