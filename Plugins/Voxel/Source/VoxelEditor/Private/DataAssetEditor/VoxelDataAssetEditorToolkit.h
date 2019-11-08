// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "UObject/GCObject.h"
#include "Misc/NotifyHook.h"
#include "EditorUndoClient.h"
#include "Framework/Commands/Commands.h"
#include "Toolkits/IToolkit.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "IVoxelDataAssetEditor.h"

class SVoxelDataAssetEditorViewport;
class UVoxelDataAsset;
class AVoxelDataAssetEditorVoxelWorld;
class FVoxelEditorToolsPanel;
class FAdvancedPreviewScene;

class FVoxelDataAssetEditorCommands : public TCommands<FVoxelDataAssetEditorCommands>
{
public:
	/** Constructor */
	FVoxelDataAssetEditorCommands()
		: TCommands<FVoxelDataAssetEditorCommands>
		(
		"VoxelDataAssetEditor", // Context name for icons
		NSLOCTEXT("Contexts", "VoxelDataAssetEditor", "Voxel Data Asset Editor"), // Localized context name for displaying
		NAME_None, // Parent
		"VoxelStyle" // Icon Style Set
		)
	{
	}
	
	/** Toggles the preview pane's grid */
	TSharedPtr< FUICommandInfo > TogglePreviewGrid;
	
	/** Toggles the preview pane's background */
	TSharedPtr< FUICommandInfo > TogglePreviewBackground;
	
	TSharedPtr< FUICommandInfo > IncreaseWorkArea;

#define LOCTEXT_NAMESPACE "VoxelDataAssetEditorCommands"
	/** Initialize commands */
	virtual void RegisterCommands() override
	{
		UI_COMMAND( TogglePreviewGrid, "Grid", "Toggles the preview pane's grid.", EUserInterfaceActionType::ToggleButton, FInputChord() );
		UI_COMMAND( TogglePreviewBackground, "Background", "Toggles the preview pane's background.", EUserInterfaceActionType::ToggleButton, FInputChord() );
		UI_COMMAND( IncreaseWorkArea, "Increase Work Area", "Recreate a voxel world with a bigger size", EUserInterfaceActionType::Button, FInputChord() );
	}
#undef LOCTEXT_NAMESPACE
};

/*-----------------------------------------------------------------------------
   FVoxelEditor
-----------------------------------------------------------------------------*/

class FVoxelDataAssetEditorToolkit : public IVoxelDataAssetEditor, public FGCObject, public FNotifyHook, public FEditorUndoClient
{
public:
	FVoxelDataAssetEditorToolkit();

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;

	/** Destructor */
	virtual ~FVoxelDataAssetEditorToolkit();

	/** Edits the specified Voxel object */
	void InitVoxelEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, UObject* ObjectToEdit);

public:
	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;

	/** FGCObject interface */
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

	//~ Begin FEditorUndoClient Interface
	virtual void PostUndo(bool bSuccess) override {}
	virtual void PostRedo(bool bSuccess) override { PostUndo(bSuccess); }
	// End of FEditorUndoClient

	void IncreaseWorkArea();

public:
	AVoxelWorld* GetVoxelWorld() const override { return (AVoxelWorld*)World; }
	FAdvancedPreviewScene* GetPreviewScene() const override { return PreviewScene.Get(); }
	FVoxelEditorToolsPanel* GetPanel() const override { return Panel.Get(); }
	
protected:
	virtual void SaveAsset_Execute() override;

private:
	TSharedRef<SDockTab> SpawnTab_EditTools(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_PreviewSettings(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Preview(const FSpawnTabArgs& Args);
	
private:
	/** FNotifyHook interface */
	virtual void NotifyPostChange(const FPropertyChangedEvent& PropertyChangedEvent, UProperty* PropertyThatChanged) override;

	/** Creates all internal widgets for the tabs to point at */
	void CreateInternalWidgets();

	void FillToolbar(FToolBarBuilder& ToolbarBuilder);
	/** Builds the toolbar widget for the Voxel editor */
	void ExtendToolbar();

	/** Binds new graph commands to delegates */
	void BindCommands();

private:
	/** The Voxel asset being inspected */
	UVoxelDataAsset* DataAsset;
	AVoxelDataAssetEditorVoxelWorld* World;

	TSharedPtr<FVoxelEditorToolsPanel> Panel;

	TSharedPtr<FAdvancedPreviewScene> PreviewScene;

	/** List of open tool panels; used to ensure only one exists at any one time */
	TMap< FName, TWeakPtr<SDockableTab> > SpawnedToolPanels;
	
	/** Preview settings tab */
	TSharedPtr<class IDetailsView> PreviewSettings;

	TSharedPtr<SWidget> AdvancedPreviewSettingsWidget;

	/** Preview tab */
	TSharedPtr<class SVoxelDataAssetEditorViewport> Preview;

	/** Command list for this editor */
	TSharedPtr<FUICommandList> DataAssetEditorCommands;
	
	/**	The tab ids for all the tabs used */
	static const FName EditToolsTabId;
	static const FName PreviewSettingsTabId;
	static const FName PreviewTabId;
};
