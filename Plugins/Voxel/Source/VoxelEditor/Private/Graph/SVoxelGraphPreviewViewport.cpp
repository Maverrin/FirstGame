// Copyright 2018 Phyronnaz

#include "SVoxelGraphPreviewViewport.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SViewport.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SBox.h"
#include "EditorStyleSet.h"
#include "Components/MeshComponent.h"
#include "Engine/SkeletalMesh.h"
#include "Editor/UnrealEdEngine.h"
#include "Engine/StaticMesh.h"
#include "Engine/Selection.h"
#include "Editor.h"
#include "Dialogs/Dialogs.h"
#include "UnrealEdGlobals.h"
#include "Slate/SceneViewport.h"
#include "Widgets/Docking/SDockTab.h"
#include "Engine/TextureCube.h"
#include "ComponentAssetBroker.h"
#include "SlateMaterialBrush.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "AdvancedPreviewScene.h"
#include "AssetViewerSettings.h"
#include "IVoxelGraphEditorToolkit.h"

#define LOCTEXT_NAMESPACE "VoxelGraphPreviewViewport"

/** Viewport Client for the preview viewport */
class FVoxelGraphEditorViewportClient : public FEditorViewportClient
{
public:
	FVoxelGraphEditorViewportClient(FAdvancedPreviewScene* InPreviewScene, const TSharedRef<SVoxelGraphPreviewViewport>& InVoxelGraphEditorViewport);

	// FEditorViewportClient interface
	virtual bool InputKey(FViewport* InViewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed = 1.f, bool bGamepad = false) override;
	virtual bool InputAxis(FViewport* InViewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples/* =1 */, bool bGamepad/* =false */) override;
	virtual FLinearColor GetBackgroundColor() const override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void Draw(FViewport* Viewport, FCanvas* Canvas) override;
	virtual bool ShouldOrbitCamera() const override;

private:

	/** Preview Scene - uses advanced preview settings */
	class FAdvancedPreviewScene* AdvancedPreviewScene;
};

FVoxelGraphEditorViewportClient::FVoxelGraphEditorViewportClient(FAdvancedPreviewScene* InPreviewScene, const TSharedRef<SVoxelGraphPreviewViewport>& InVoxelGraphEditorViewport)
	: FEditorViewportClient(nullptr, InPreviewScene, StaticCastSharedRef<SEditorViewport>(InVoxelGraphEditorViewport))
{
	// Setup defaults for the common draw helper.
	DrawHelper.bDrawPivot = false;
	DrawHelper.bDrawWorldBox = false;
	DrawHelper.bDrawKillZ = false;
	DrawHelper.bDrawGrid = false;
	DrawHelper.GridColorAxis = FColor(80, 80, 80);
	DrawHelper.GridColorMajor = FColor(72, 72, 72);
	DrawHelper.GridColorMinor = FColor(64, 64, 64);
	DrawHelper.PerspectiveGridSize = HALF_WORLD_MAX1;

	SetViewMode(VMI_Lit);

	EngineShowFlags.DisableAdvancedFeatures();
	EngineShowFlags.SetSnap(0);
	EngineShowFlags.SetSeparateTranslucency(true);

	OverrideNearClipPlane(1.0f);
	bUsingOrbitCamera = true;

	// Don't want to display the widget in this viewport
	Widget->SetDefaultVisibility(false);

	AdvancedPreviewScene = InPreviewScene;

}

void FVoxelGraphEditorViewportClient::Tick(float DeltaSeconds)
{
	FEditorViewportClient::Tick(DeltaSeconds);

	// Tick the preview scene world.
	if (!GIntraFrameDebuggingGameThread)
	{
		PreviewScene->GetWorld()->Tick(LEVELTICK_All, DeltaSeconds);
	}
}

void FVoxelGraphEditorViewportClient::Draw(FViewport* InViewport, FCanvas* Canvas)
{
	FEditorViewportClient::Draw(InViewport, Canvas);
}

bool FVoxelGraphEditorViewportClient::ShouldOrbitCamera() const
{
	// Should always orbit around the preview object to keep it in view.
	return true;
}

bool FVoxelGraphEditorViewportClient::InputKey(FViewport* InViewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed, bool bGamepad)
{
	bool bHandled = FEditorViewportClient::InputKey(InViewport, ControllerId, Key, Event, AmountDepressed, false);

	// Handle viewport screenshot.
	bHandled |= InputTakeScreenshot(InViewport, Key, Event);

	bHandled |= AdvancedPreviewScene->HandleInputKey(InViewport, ControllerId, Key, Event, AmountDepressed, bGamepad);

	return bHandled;
}

bool FVoxelGraphEditorViewportClient::InputAxis(FViewport* InViewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples/* =1 */, bool bGamepad/* =false */)
{
	bool bResult = true;

	if (!bDisableInput)
	{
		bResult = AdvancedPreviewScene->HandleViewportInput(InViewport, ControllerId, Key, Delta, DeltaTime, NumSamples, bGamepad);
		if (bResult)
		{
			Invalidate();
		}
		else
		{
			bResult = FEditorViewportClient::InputAxis(InViewport, ControllerId, Key, Delta, DeltaTime, NumSamples, bGamepad);
		}
	}

	return bResult;
}

FLinearColor FVoxelGraphEditorViewportClient::GetBackgroundColor() const
{
	if (AdvancedPreviewScene != nullptr)
	{
		return AdvancedPreviewScene->GetBackgroundColor();
	}
	else
	{
		return FLinearColor::White;
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void SVoxelGraphPreviewViewport::Construct(const FArguments& InArgs)
{
	VoxelGraphEditorToolkit = InArgs._VoxelGraphEditorToolkit;
	AdvancedPreviewScene = VoxelGraphEditorToolkit.Pin()->GetPreviewScene();

	SEditorViewport::Construct(SEditorViewport::FArguments());
}

SVoxelGraphPreviewViewport::~SVoxelGraphPreviewViewport()
{
	UAssetViewerSettings::Get()->OnAssetViewerSettingsChanged().RemoveAll(this);

	if (EditorViewportClient.IsValid())
	{
		EditorViewportClient->Viewport = NULL;
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TSharedRef<class SEditorViewport> SVoxelGraphPreviewViewport::GetViewportWidget()
{
	return SharedThis(this);
}

TSharedPtr<FExtender> SVoxelGraphPreviewViewport::GetExtenders() const
{
	TSharedPtr<FExtender> Result(MakeShareable(new FExtender));
	return Result;
}

void SVoxelGraphPreviewViewport::OnFloatingButtonClicked()
{
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TSharedRef<FEditorViewportClient> SVoxelGraphPreviewViewport::MakeEditorViewportClient()
{
	EditorViewportClient = MakeShareable(new FVoxelGraphEditorViewportClient(AdvancedPreviewScene, SharedThis(this)));
	EditorViewportClient->SetViewLocation(FVector::ZeroVector);
	EditorViewportClient->SetViewRotation(FRotator(0.0f, -90.0f, 0.0f));
	EditorViewportClient->SetViewLocationForOrbiting(FVector::ZeroVector);

	return EditorViewportClient.ToSharedRef();
}
#undef LOCTEXT_NAMESPACE
