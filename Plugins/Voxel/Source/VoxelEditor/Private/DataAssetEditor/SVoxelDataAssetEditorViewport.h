// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "SlateFwd.h"
#include "UObject/GCObject.h"
#include "Layout/Visibility.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "PreviewScene.h"
#include "EditorViewportClient.h"
#include "ThumbnailRendering/ThumbnailManager.h"
#include "SEditorViewport.h"
#include "SCommonEditorViewportToolbarBase.h"

class FVoxelDataAssetEditorViewportClient;
class IVoxelDataAssetEditor;

class SVoxelDataAssetEditorViewportToolBar : public SCommonEditorViewportToolbarBase
{
public:
	SLATE_BEGIN_ARGS(SVoxelDataAssetEditorViewportToolBar) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<class SVoxelDataAssetEditorViewport> InViewport);

	// SCommonEditorViewportToolbarBase interface
	virtual TSharedRef<SWidget> GenerateShowMenu() const override;
	// End of SCommonEditorViewportToolbarBase
};

/**
 * Material Editor Preview viewport widget
 */
class SVoxelDataAssetEditorViewport : public SEditorViewport, public FGCObject, public ICommonEditorViewportToolbarInfoProvider
{
public:
	SLATE_BEGIN_ARGS( SVoxelDataAssetEditorViewport ){}
		SLATE_ARGUMENT(TWeakPtr<IVoxelDataAssetEditor>, VoxelDataAssetEditor)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	~SVoxelDataAssetEditorViewport();
	
	virtual void AddReferencedObjects( FReferenceCollector& Collector ) override;

	void RefreshViewport();

	/** Event handlers */
	void TogglePreviewBackground();
	bool IsTogglePreviewBackgroundChecked() const;
	/** Call back for when the user changes preview scene settings in the UI */
	void OnAssetViewerSettingsChanged(const FName& InPropertyName);

	// ICommonEditorViewportToolbarInfoProvider interface
	virtual TSharedRef<class SEditorViewport> GetViewportWidget() override;
	virtual TSharedPtr<FExtender> GetExtenders() const override;
	virtual void OnFloatingButtonClicked() override;
	// End of ICommonEditorViewportToolbarInfoProvider interface

protected:
	/** SEditorViewport interface */
	virtual TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;
	virtual void PopulateViewportOverlays(TSharedRef<class SOverlay> Overlay) override;
	virtual EVisibility OnGetViewportContentVisibility() const override;
	virtual void BindCommands() override;
	virtual void OnFocusViewportToSelection() override;
private:
	/** The parent tab where this viewport resides */
	TWeakPtr<SDockTab> ParentTab;

	/** Pointer back to the material editor tool that owns us */
	TWeakPtr<IVoxelDataAssetEditor> VoxelDataAssetEditorPtr;

	bool IsVisible() const override;

	/** Level viewport client */
	TSharedPtr<class FVoxelDataAssetEditorViewportClient> EditorViewportClient;
	class FAdvancedPreviewScene* AdvancedPreviewScene;
};
