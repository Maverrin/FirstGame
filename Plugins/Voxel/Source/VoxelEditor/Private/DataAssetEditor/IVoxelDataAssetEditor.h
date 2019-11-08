// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"

class IVoxelDataAssetEditor : public FAssetEditorToolkit
{
public:
	virtual class AVoxelWorld* GetVoxelWorld() const = 0;
	virtual class FAdvancedPreviewScene* GetPreviewScene() const = 0;
	virtual class FVoxelEditorToolsPanel* GetPanel() const = 0;
};
