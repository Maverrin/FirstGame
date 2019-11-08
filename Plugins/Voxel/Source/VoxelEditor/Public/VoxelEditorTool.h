// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "EditorViewportClient.h"
#include "Framework/Commands/UIAction.h"
#include "VoxelEditorTool.generated.h"

class AVoxelWorld;
class FEditorViewportClient;
class FViewport;
class HHitProxy;

struct FVoxelEditorToolMode
{
	TSharedPtr<FUICommandInfo> Command;
	FText Label;
	FText ToolTip;
	int ModeId;

	FVoxelEditorToolMode(const TSharedPtr<FUICommandInfo>& Command, const FText& Label, const FText& ToolTip, int ModeId)
		: Command(Command)
		, Label(Label)
		, ToolTip(ToolTip)
		, ModeId(ModeId)
	{
	}
};

UCLASS(abstract)
class VOXELEDITOR_API UVoxelEditorTool : public UObject
{
	GENERATED_BODY()

public:
	inline AVoxelWorld* GetVoxelWorld() const { return World; }
	inline bool SeemsValid() const { return DEADBEEF == 0xDEADBEEF; }

public:
	virtual void Enable() {}
	virtual void Disable() {}
	virtual void SetVoxelWorld(AVoxelWorld* NewWorld) { World = NewWorld; }

public:
	virtual TSharedPtr<FUICommandInfo> GetCommand() const { return TSharedPtr<FUICommandInfo>(); }	
	virtual FText GetLabel() const { return FText(); }
	virtual FText GetToolTip() const { return FText(); }
	
public:
	virtual void GetModeCommands(TArray<FVoxelEditorToolMode>& OutCommands) const {}
	virtual bool IsModePropertyVisible(const UProperty& Property) const { return true; }
	virtual void SetCurrentMode(int NewModeId) { ModeId = NewModeId; }
	int GetMode() const { return ModeId; }

public:
	/** Called when the mouse is moved over the viewport */
	virtual void MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 MouseX, int32 MouseY) {}
	/** Called once per frame */
	virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) {}
	/** Called when clicking on a hit proxy */
	virtual void HandleClick(FEditorViewportClient* ViewportClient, HHitProxy* HitProxy, const FViewportClick& Click) {}
	/** Called when a key is pressed */
	virtual bool InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event) { return false; }
	
	virtual bool InputAxis(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, float Delta, float DeltaTime) { return false; }

protected:
	AVoxelWorld* World = nullptr;

private:
	const uint64 DEADBEEF = 0xDEADBEEF;
	int ModeId = 0;
};
