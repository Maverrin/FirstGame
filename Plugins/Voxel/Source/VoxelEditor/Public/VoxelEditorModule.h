// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "IVoxelGraphEditorToolkit.h"

class UVoxelDataAsset;

/** Voxel class editor module interface */
class IVoxelEditorModule : public IModuleInterface
{
public:
	virtual TSharedRef<IVoxelGraphEditorToolkit> CreateVoxelGraphEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UVoxelGraphGenerator* WorldGenerator) = 0;
	virtual void						     CreateVoxelDataAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UVoxelDataAsset*      DataAsset     ) = 0;
};

DECLARE_LOG_CATEGORY_EXTERN(LogVoxelEditor, Verbose, All);
