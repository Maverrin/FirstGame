// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "UObject/GCObject.h"
#include "Toolkits/IToolkitHost.h"
#include "Misc/NotifyHook.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "EditorUndoClient.h"
#include "EditorStyleSet.h"
#include "IVoxelGraphEditorToolkit.h"
#include "Framework/Commands/Commands.h"
#include "Widgets/Docking/SDockTab.h"
#include "AdvancedPreviewScene.h"
#include "UnrealEdMisc.h"
#include "VoxelGraphEditorToolkit.generated.h"

class IDetailsView;
class SDockableTab;
class SGraphEditor;
class SVoxelPalette;
class UEdGraphNode;
struct FPropertyChangedEvent;
struct Rect;
class UStaticMeshComponent;
class UMaterialInstanceDynamic;
class UVoxelGraphNode;
class UTexture2D;

class FVoxelGraphEditorCommands : public TCommands<FVoxelGraphEditorCommands>
{
public:
	/** Constructor */
	FVoxelGraphEditorCommands()
		: TCommands<FVoxelGraphEditorCommands>
		(
		"VoxelGraphEditor", // Context name for icons
		NSLOCTEXT("Contexts", "VoxelGraphEditor", "Voxel Graph Editor"), // Localized context name for displaying
		NAME_None, // Parent
		"VoxelStyle" // Icon Style Set
		)
	{
	}

	/** Compile the graph to C++ */
	TSharedPtr<FUICommandInfo> CompileToCpp;

	/** Compile the nodes */
	TSharedPtr<FUICommandInfo> RecreateNodes;
	
	/** Enable auto preview update */
	TSharedPtr<FUICommandInfo> ToggleAutomaticPreview;

	/** Update preview */
	TSharedPtr<FUICommandInfo> UpdatePreview;
	
	TSharedPtr<FUICommandInfo> ToggleStats;
	TSharedPtr<FUICommandInfo> ToggleShowAxisDependencies;

	/** Breaks the node input/output link */
	TSharedPtr<FUICommandInfo> BreakLink;

	/** Adds an input to the node */
	TSharedPtr<FUICommandInfo> AddInput;

	/** Removes an input from the node */
	TSharedPtr<FUICommandInfo> DeleteInput;

	/** Makes a new be previewed in the viewport */
	TSharedPtr<FUICommandInfo> StartPreviewPin;
	TSharedPtr<FUICommandInfo> StopPreviewPin;

#define LOCTEXT_NAMESPACE "VoxelGraphEditorCommands"
	/** Initialize commands */
	virtual void RegisterCommands() override
	{
		UI_COMMAND(CompileToCpp, "Compile To C++", "Create C++ file from graph", EUserInterfaceActionType::Button, FInputChord());
		UI_COMMAND(RecreateNodes, "Recreate Nodes", "Reconstruct all the nodes", EUserInterfaceActionType::Button, FInputChord());
		UI_COMMAND(ToggleAutomaticPreview, "Automatic Preview", "Enable Automatic Preview", EUserInterfaceActionType::ToggleButton, FInputChord());
		UI_COMMAND(UpdatePreview, "Update preview", "Update preview", EUserInterfaceActionType::Button, FInputChord(EKeys::F5));
		UI_COMMAND(ToggleStats, "Stats", "Enable Stats. Once toggled, generate your world in PIE, stop PIE, go back here and click Update Preview", EUserInterfaceActionType::ToggleButton, FInputChord());
		UI_COMMAND(ToggleShowAxisDependencies, "Show Axis Dependencies", "Show Axis Dependencies", EUserInterfaceActionType::ToggleButton, FInputChord());

		UI_COMMAND(AddInput, "Add Input", "Adds an input to the node", EUserInterfaceActionType::Button, FInputChord());
		UI_COMMAND(DeleteInput, "Delete Input", "Removes an input from the node", EUserInterfaceActionType::Button, FInputChord());

		UI_COMMAND( StartPreviewPin, "Start Previewing Pin", "Makes the preview viewport start previewing this pin", EUserInterfaceActionType::Button, FInputChord() );
		UI_COMMAND( StopPreviewPin, "Stop Previewing Pin", "Stop the preview", EUserInterfaceActionType::Button, FInputChord() );
	}
#undef LOCTEXT_NAMESPACE
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
USTRUCT()
struct FVoxelGraphEditorKeyBinding
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	bool bCtrlDown = false;

	UPROPERTY(EditAnywhere)
	bool bAltDown = false;

	UPROPERTY(EditAnywhere)
	bool bShiftDown = false;

	UPROPERTY(EditAnywhere)
	FKey Key;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UVoxelNode> Class;

	FVoxelGraphEditorKeyBinding() = default;

	FVoxelGraphEditorKeyBinding(FKey Key, TSubclassOf<UVoxelNode> Class)
		: Key(Key)
		, Class(Class)
	{
	}

	inline bool IsSameAs(const FInputChord& Chord)
	{
		return bCtrlDown == Chord.bCtrl && bAltDown == Chord.bAlt && bShiftDown == Chord.bShift && Key == Chord.Key;
	}
};

UCLASS(Config = EditorKeyBindings)
class UVoxelGraphShortcuts : public UObject
{
	GENERATED_BODY()
public:
	UVoxelGraphShortcuts();

	UPROPERTY(Config, EditAnywhere)
	TArray<FVoxelGraphEditorKeyBinding> Shortcuts;
	
	//~ Begin UObject Interface
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override
	{
		Super::PostEditChangeProperty(PropertyChangedEvent);

		if (!FUnrealEdMisc::Get().IsDeletePreferences())
		{
			SaveConfig();
		}
	}
#endif
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class FVoxelGraphEditorToolkit : public IVoxelGraphEditorToolkit, public FGCObject, public FNotifyHook, public FEditorUndoClient
{
public:
	FVoxelGraphEditorToolkit();
	virtual ~FVoxelGraphEditorToolkit();

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;

	/** Edits the specified Voxel object */
	void InitVoxelEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, UObject* ObjectToEdit);

	/** IVoxelEditor interface */
	virtual UVoxelGraphGenerator* GetWorldGenerator() const override;
	virtual void SetSelection(TArray<UObject*> SelectedObjects) override;
	virtual bool GetBoundsForSelectedNodes(class FSlateRect& Rect, float Padding) override;
	virtual int32 GetNumberOfSelectedNodes() const override;
	virtual TSet<UObject*> GetSelectedNodes() const override;
	virtual void SelectNodesAndZoomToFit(TArray<UEdGraphNode*>& Nodes) override;
	virtual FAdvancedPreviewScene* GetPreviewScene() const override { return PreviewScene.Get(); }
	virtual void SetDebugGraph(FVoxelGraphCompiler* Compiler) override;

	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;

	/** FGCObject interface */
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

	//~ Begin FEditorUndoClient Interface
	virtual void PostUndo(bool bSuccess) override;
	virtual void PostRedo(bool bSuccess) override { PostUndo(bSuccess); }
	// End of FEditorUndoClient

	void TriggerUpdatePreview(bool bForce, bool bUpdateTextures) override;

private:
	TSharedRef<SDockTab> SpawnTab_GraphCanvas(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_DebugGraphCanvas(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Properties(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Shortcuts(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_PreviewSettings(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Palette(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Preview(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_PreviewViewport(const FSpawnTabArgs& Args);

protected:
	/** Called when the selection changes in the GraphEditor */
	void OnSelectedNodesChanged(const TSet<class UObject*>& NewSelection);

	/**
	 * Called when a node's title is committed for a rename
	 *
	 * @param	NewText				New title text
	 * @param	CommitInfo			How text was committed
	 * @param	NodeBeingChanged	The node being changed
	 */
	void OnNodeTitleCommitted(const FText& NewText, ETextCommit::Type CommitInfo, UEdGraphNode* NodeBeingChanged);

	/** Select every node in the graph */
	void SelectAllNodes();
	/** Whether we can select every node */
	bool CanSelectAllNodes() const;

	/** Delete the currently selected nodes */
	void DeleteSelectedNodes();
	/** Whether we are able to delete the currently selected nodes */
	bool CanDeleteNodes() const;
	/** Delete only the currently selected nodes that can be duplicated */
	void DeleteSelectedDuplicatableNodes();

	/** Cut the currently selected nodes */
	void CutSelectedNodes();
	/** Whether we are able to cut the currently selected nodes */
	bool CanCutNodes() const;

	/** Copy the currently selected nodes */
	void CopySelectedNodes();
	/** Whether we are able to copy the currently selected nodes */
	bool CanCopyNodes() const;

	/** Paste the contents of the clipboard */
	void PasteNodes();
	/** Paste the contents of the clipboard at a specific location */
	virtual void PasteNodesHere(const FVector2D& Location) override;
	/** Whether we are able to paste the contents of the clipboard */
	virtual bool CanPasteNodes() const override;

	/** Duplicate the currently selected nodes */
	void DuplicateNodes();
	/** Whether we are able to duplicate the currently selected nodes */
	bool CanDuplicateNodes() const;

	void CompileToCpp();
	void RecreateNodes();
	void ToggleAutomaticPreview();
	bool IsToggleAutomaticPreviewChecked() const;
	void UpdatePreview(bool bUpdateTextures);
	void ToggleStats();
	bool IsToggleStatsChecked() const;
	void ToggleShowAxisDependencies();
	bool IsToggleShowAxisDependenciesChecked() const;

	/** Called to undo the last action */
	void UndoGraphAction();

	/** Called to redo the last undone action */
	void RedoGraphAction();

	void OnStartPreviewPin();
	void OnStopPreviewPin();

	void OnNodeDoubleClicked(UEdGraphNode* Node);

	FReply OnSpawnGraphNodeByShortcut(FInputChord InChord, const FVector2D& InPosition);

private:
	/** FNotifyHook interface */
	virtual void NotifyPostChange(const FPropertyChangedEvent& PropertyChangedEvent, UProperty* PropertyThatChanged) override;

	/** Creates all internal widgets for the tabs to point at */
	void CreateInternalWidgets();

	void FillToolbar(FToolBarBuilder& ToolbarBuilder);
	/** Builds the toolbar widget for the Voxel editor */
	void ExtendToolbar();

	/** Binds new graph commands to delegates */
	void BindGraphCommands();
	
	/** Add an input to the currently selected node */
	void AddInput();
	/** Whether we can add an input to the currently selected node */
	bool CanAddInput() const;

	/** Delete an input from the currently selected node */
	void DeleteInput();
	/** Whether we can delete an input from the currently selected node */
	bool CanDeleteInput() const;

	/* Create comment node on graph */
	void OnCreateComment();

	/** Create new graph editor widget */
	TSharedRef<SGraphEditor> CreateGraphEditorWidget(bool bDebug);

private:
	/** The Voxel asset being inspected */
	UVoxelGraphGenerator* WorldGenerator;
	TWeakObjectPtr<UVoxelGraphNode> CurrentPreviewedNode;

	/** List of open tool panels; used to ensure only one exists at any one time */
	TMap< FName, TWeakPtr<SDockableTab> > SpawnedToolPanels;
	/** Main Graph Editor */
	TSharedPtr<SGraphEditor> VoxelGraphEditor;
	/** Debug one */
	TSharedPtr<SGraphEditor> VoxelDebugGraphEditor;

	/** Properties tab */
	TSharedPtr<class IDetailsView> VoxelProperties;
	TSharedPtr<class IDetailsView> ShortcutsProperties;
	/** Preview settings tab */
	TSharedPtr<class IDetailsView> PreviewSettings;
	/** Palette of Voxel Node types */
	TSharedPtr<class SVoxelPalette> Palette;
	/** Preview tab */
	TSharedPtr<class SVoxelPreview> Preview;
	/** 3D Preview */
	TSharedPtr<class SVoxelGraphPreviewViewport> PreviewViewport;
	TSharedPtr<SDockTab> GraphTab;
	TSharedPtr<SDockTab> DebugGraphTab;

	/** Command list for this editor */
	TSharedPtr<FUICommandList> GraphEditorCommands;

	bool bAutomaticPreview;

	/**	The tab ids for all the tabs used */
	static const FName GraphCanvasTabId;
	static const FName DebugGraphCanvasTabId;
	static const FName PropertiesTabId;
	static const FName ShortcutsTabId;
	static const FName PreviewSettingsTabId;
	static const FName PaletteTabId;
	static const FName PreviewTabId;
	static const FName PreviewViewportTabId;
	
	TSharedPtr<FAdvancedPreviewScene> PreviewScene;
	UStaticMeshComponent* PreviewSceneFloor = nullptr;
	UMaterialInstanceDynamic* PreviewSceneMaterial = nullptr;
	UTexture2D* PreviewTexture = nullptr;
	UTexture2D* DensitiesTexture = nullptr;
	UTexture2D* MaterialsTexture = nullptr;
};
