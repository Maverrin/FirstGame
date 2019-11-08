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
#include "Slate/SceneViewport.h"

class FVoxelGraphPreviewViewportClient;
class IVoxelGraphEditorToolkit;

/**
 * Material Editor Preview viewport widget
 */
class SVoxelGraphPreviewViewport : public SEditorViewport, public FGCObject, public ICommonEditorViewportToolbarInfoProvider
{
public:
	SLATE_BEGIN_ARGS( SVoxelGraphPreviewViewport ){}
		SLATE_ARGUMENT(TWeakPtr<IVoxelGraphEditorToolkit>, VoxelGraphEditorToolkit)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	~SVoxelGraphPreviewViewport();
	
	// ICommonEditorViewportToolbarInfoProvider interface
	virtual TSharedRef<class SEditorViewport> GetViewportWidget() override;
	virtual TSharedPtr<FExtender> GetExtenders() const override;
	virtual void OnFloatingButtonClicked() override;
	// End of ICommonEditorViewportToolbarInfoProvider interface

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override {}
	void RefreshViewport() { SceneViewport->InvalidateDisplay(); }

protected:
	/** SEditorViewport interface */
	virtual TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;

private:
	/** The parent tab where this viewport resides */
	TWeakPtr<SDockTab> ParentTab;

	/** Pointer back to the material editor tool that owns us */
	TWeakPtr<IVoxelGraphEditorToolkit> VoxelGraphEditorToolkit;

	/** Level viewport client */
	TSharedPtr<class FEditorViewportClient> EditorViewportClient;
	class FAdvancedPreviewScene* AdvancedPreviewScene;
};
