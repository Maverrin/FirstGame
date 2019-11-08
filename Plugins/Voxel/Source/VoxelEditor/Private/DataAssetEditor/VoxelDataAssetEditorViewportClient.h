// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "UnrealWidget.h"
#include "EditorViewportClient.h"

class IVoxelDataAssetEditor;
class FCanvas;
class FPreviewScene;
class FScopedTransaction;
class SVoxelDataAssetEditorViewport;
class UStaticMeshComponent;
class AVoxelWorld;
class FVoxelEditorToolsPanel;

/**
 * An editor viewport client subclass
 */
class FVoxelDataAssetEditorViewportClient : public FEditorViewportClient, public TSharedFromThis<FVoxelDataAssetEditorViewportClient>
{
public:
	FVoxelDataAssetEditorViewportClient(TWeakPtr<IVoxelDataAssetEditor>& InVoxelDataAssetEditorPtr, FPreviewScene* InPreviewScene, const TSharedRef<SVoxelDataAssetEditorViewport>& InVoxelDataAssetEditorViewport);

	// FEditorViewportClient interface
	virtual void Tick(float DeltaSeconds) override;
	virtual void Draw(const FSceneView* View,FPrimitiveDrawInterface* PDI) override;
	virtual bool InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed = 1.f, bool bGamepad=false) override;
	virtual bool InputAxis(FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples, bool bGamepad) override;
	virtual void ProcessClick(class FSceneView& View, class HHitProxy* HitProxy, FKey Key, EInputEvent Event, uint32 HitX, uint32 HitY) override;
	virtual int32 GetCameraSpeedSetting() const override;
	virtual void SetCameraSpeedSetting(int32 SpeedSetting) override;
	virtual void MouseMove(FViewport* Viewport, int32 x, int32 y) override;
	virtual void UpdateMouseDelta() override;
	virtual FWidget::EWidgetMode GetWidgetMode() const override { return FWidget::WM_Max; }

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

	/** 
	 * Recreates the preview scene and invalidates the owning viewport.
	 *
	 * @param bResetCamera Whether or not to reset the camera after recreating the preview scene.
	 */
	void InvalidatePreview(bool bResetCamera = true);

	/**
	 * Resets the camera position
	 */
	void ResetCamera();
	
	/**
	 * Returns true if the grid is currently visible in the viewport
	 */
	bool GetShowGrid();

	/**
	 * Will toggle the grid's visibility in the viewport
	 */
	void ToggleShowGrid();

	/**
	 * Gets the current preview actor instance.
	 */
	AVoxelWorld* GetVoxelWorld() const;

	FVoxelEditorToolsPanel* GetPanel() const;

	void RefreshPreviewBounds();

private:
	/** Weak reference to the editor hosting the viewport */
	TWeakPtr<class IVoxelDataAssetEditor> DataAssetEditorPtr;

	/** The full bounds of the preview scene (encompasses all visible components) */
	FBoxSphereBounds PreviewActorBounds;

	/** If true then we are manipulating a specific property or component */
	bool bIsManipulating;

	/** The current transaction for undo/redo */
	FScopedTransaction* ScopedTransaction;

	bool bShowGrid;
	bool bShowFloor;
	bool bMousePressed;
};
