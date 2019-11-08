// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "EditorViewportClient.h"
#include "Framework/Commands/UICommandList.h"
#include "VoxelEditorToolsPanel.generated.h"

class UVoxelEditorTool;
class AVoxelWorld;
class FEditorViewportClient;
class FViewport;
class HHitProxy;
class IDetailsView;
class SBox;
struct FPropertyAndParent;

UCLASS()
class UVoxelEditorVoxelWorldSelect : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "World to edit")
	AVoxelWorld* World;

	class FVoxelEditorToolsPanel* Panel = nullptr;

	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};

class FVoxelEditorToolsPanel : public TSharedFromThis<FVoxelEditorToolsPanel>
{	
public:
	FVoxelEditorToolsPanel();
	~FVoxelEditorToolsPanel();

	void Init(UWorld* Context, AVoxelWorld* WorldToUse = nullptr);

public:
	void AddReferencedObjects(FReferenceCollector& Collector);

public:
	const TArray<UVoxelEditorTool*> GetTools();
	void SetActiveTool(UVoxelEditorTool* Tool);
	void PostEditWorldSelect();
	
public:
	FReply Undo(int Times);
	FReply Redo(int Times);
	void ClearFrames();
	
	void OnChangeTool(UVoxelEditorTool* NewTool);
	void OnChangeMode(int NewModeId) const;
	bool IsModeSelected(int ModeId) const;

	bool GetIsPropertyVisibleForMode(const FPropertyAndParent& PropertyAndParent) const;
	bool GetIsPropertyVisibleForGeneral(const FPropertyAndParent& PropertyAndParent) const;
	
public:	
	bool IsEnabled() const;
	bool IsVoxelWorldValid() const;

	UVoxelEditorVoxelWorldSelect* GetVoxelWorldSelect() const { return WorldSelect; }
	AVoxelWorld* GetVoxelWorld() const { return WorldSelect ? WorldSelect->World : nullptr; }
	bool IsToolValid(UVoxelEditorTool* Tool) const;

	TSharedPtr<SWidget> GetWidget() const { return Widget; }

public:
	void MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 MouseX, int32 MouseY);
	void Tick(FEditorViewportClient* ViewportClient, float DeltaTime);
	void HandleClick(FEditorViewportClient* ViewportClient, HHitProxy* HitProxy, const FViewportClick& Click);
	bool InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event);
	bool InputAxis(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, float Delta, float DeltaTime);

private:
	UVoxelEditorVoxelWorldSelect* WorldSelect = nullptr;
	UVoxelEditorTool* ActiveTool = nullptr;

	float TimeUntilNextGC = 0;

	TArray<UVoxelEditorTool*> Tools;

	TSharedRef<FUICommandList> CommandList;
	TSharedPtr<SWidget> Widget;
	TSharedPtr<IDetailsView> WorldSelectDetailsPanel;
	TSharedPtr<IDetailsView> ToolGeneralDetailsPanel;
	TSharedPtr<IDetailsView> ToolModeDetailsPanel;
	TSharedPtr<SBox> ToolModeBox;
};
