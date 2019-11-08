// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Input/Reply.h"
#include "IDetailCustomization.h"
#include "Widgets/Input/SButton.h"

class AVoxelDataAssetEditorVoxelWorld;

class FVoxelDataAssetEditorVoxelWorldDetails : public IDetailCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IDetailCustomization> MakeInstance();

	FVoxelDataAssetEditorVoxelWorldDetails();

private:
	/** IDetailCustomization interface */
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;

private:
	TWeakObjectPtr<AVoxelDataAssetEditorVoxelWorld> World;
};
