// Copyright 2018 Phyronnaz

#include "VoxelEdMode.h"
#include "Toolkits/ToolkitManager.h"
#include "VoxelEdModeToolkit.h"
#include "VoxelEditorTools/VoxelEditorToolsPanel.h"
#include "EditorModeManager.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

const FEditorModeID FEdModeVoxel::EM_Voxel = TEXT("EM_Voxel");

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FEdModeVoxel::AddReferencedObjects(FReferenceCollector& Collector)
{
	FEdMode::AddReferencedObjects(Collector);

	if (Panel.IsValid())
	{
		Panel->AddReferencedObjects(Collector);
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FEdModeVoxel::Enter()
{
	FEdMode::Enter();

	if (!Panel.IsValid())
	{
		Panel = MakeShareable(new FVoxelEditorToolsPanel());
		Panel->Init(GetWorld());
	}

	if (!Toolkit.IsValid())
	{
		Toolkit = MakeShareable(new FVoxelEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FEdModeVoxel::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	if (Panel.IsValid())
	{
		Panel.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

bool FEdModeVoxel::MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 MouseX, int32 MouseY)
{
	if (!Panel.IsValid() || !Panel->IsEnabled() || !Panel->IsVoxelWorldValid())
	{
		return false;
	}

	if (Panel.IsValid())
	{
		Panel->MouseMove(ViewportClient, Viewport, MouseX, MouseY);
	}

	ViewportClient->Invalidate(false, false);

	return bMousePressed;
}

void FEdModeVoxel::Tick(FEditorViewportClient* ViewportClient, float DeltaTime)
{
	if (!Panel.IsValid() || !Panel->IsEnabled() || !Panel->IsVoxelWorldValid())
	{
		return;
	}

	if (Panel.IsValid())
	{
		Panel->Tick(ViewportClient, DeltaTime);
	}

	ViewportClient->Viewport->CaptureMouse(true);
}

bool FEdModeVoxel::HandleClick(FEditorViewportClient* ViewportClient, HHitProxy* HitProxy, const FViewportClick& Click)
{
	if (!Panel.IsValid() || !Panel->IsEnabled() || !Panel->IsVoxelWorldValid())
	{
		return false;
	}

	if (Panel.IsValid())
	{
		Panel->HandleClick(ViewportClient, HitProxy, Click);
	}

	return true;
}

bool FEdModeVoxel::InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event)
{
	if (!Panel.IsValid() || !Panel->IsEnabled() || !Panel->IsVoxelWorldValid())
	{
		return false;
	}

	if (Event == IE_Released && (Key == EKeys::LeftMouseButton || Key == EKeys::MiddleMouseButton || Key == EKeys::RightMouseButton))
	{
		//Set the cursor position to that of the slate cursor so it wont snap back
		Viewport->SetPreCaptureMousePosFromSlateCursor();
	}
	if (Key == EKeys::LeftMouseButton && Event != EInputEvent::IE_Repeat)
	{
		bMousePressed = (Event == EInputEvent::IE_Pressed);
	}

	if (Panel.IsValid())
	{
		return Panel->InputKey(ViewportClient, Viewport, Key, Event);
	}

	return false;
}

bool FEdModeVoxel::InputAxis(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime)
{
	if (Panel.IsValid())
	{
		return Panel->InputAxis(ViewportClient, Viewport, Key, Delta, DeltaTime);
	}
	
	return false;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

bool FEdModeVoxel::CapturedMouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 MouseX, int32 MouseY)
{
	return MouseMove(ViewportClient, Viewport, MouseX, MouseY);
}

bool FEdModeVoxel::DisallowMouseDeltaTracking() const
{
	// We never want to use the mouse delta tracker while painting
	return bMousePressed;
}

bool FEdModeVoxel::IsSelectionAllowed(AActor* InActor, bool bInSelection) const
{
	return true;
}

bool FEdModeVoxel::GetCursor(EMouseCursor::Type& OutCursor) const
{
	if (Panel.IsValid() && Panel->IsEnabled())
	{
		OutCursor = EMouseCursor::Crosshairs;
		return true;
	}
	else
	{
		return false;
	}
}
