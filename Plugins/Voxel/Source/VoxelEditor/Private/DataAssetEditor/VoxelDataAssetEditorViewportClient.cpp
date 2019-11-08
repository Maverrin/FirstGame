// Copyright 2018 Phyronnaz

#include "VoxelDataAssetEditorViewportClient.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h"
#include "CanvasItem.h"
#include "Editor/EditorPerProjectUserSettings.h"
#include "Settings/LevelEditorViewportSettings.h"
#include "Editor/UnrealEdEngine.h"
#include "ThumbnailRendering/SceneThumbnailInfo.h"
#include "ThumbnailRendering/ThumbnailManager.h"
#include "Engine/StaticMesh.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Kismet2/ComponentEditorUtils.h"
#include "EngineUtils.h"
#include "UnrealEdGlobals.h"
#include "SEditorViewport.h"
#include "EngineGlobals.h"
#include "Editor.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "SKismetInspector.h"
#include "ScopedTransaction.h"
#include "CanvasTypes.h"
#include "Engine/TextureCube.h"
#include "SVoxelDataAssetEditorViewport.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "IVoxelDataAssetEditor.h"
#include "VoxelWorld.h"
#include "VoxelEditorTools/VoxelEditorToolsPanel.h"
#include "Components/LineBatchComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogVoxelDataAssetEditorViewport, Log, All);

namespace
{
	/** Automatic translation applied to the camera in the default editor viewport logic when orbit mode is enabled. */
	const float AutoViewportOrbitCameraTranslate = 256.0f;
}

/////////////////////////////////////////////////////////////////////////
// FVoxelDataAssetEditorViewportClient

FVoxelDataAssetEditorViewportClient::FVoxelDataAssetEditorViewportClient(TWeakPtr<IVoxelDataAssetEditor>& InDataAssetEditorPtr, FPreviewScene* InPreviewScene, const TSharedRef<SVoxelDataAssetEditorViewport>& InVoxelDataAssetEditorViewport)
	: FEditorViewportClient(nullptr, InPreviewScene, StaticCastSharedRef<SEditorViewport>(InVoxelDataAssetEditorViewport))
	, DataAssetEditorPtr(InDataAssetEditorPtr)
	, PreviewActorBounds(ForceInitToZero)
	, bIsManipulating(false)
	, ScopedTransaction(NULL)
	, bShowGrid(false)
	, bShowFloor(false)
	, bMousePressed(false)
{
	EngineShowFlags.DisableAdvancedFeatures();

	check(Widget);
	Widget->SetSnapEnabled(true);

	// Selectively set particular show flags that we need
	EngineShowFlags.SetSelectionOutline(GetDefault<ULevelEditorViewportSettings>()->bUseSelectionOutline);

	// Set if the grid will be drawn
	DrawHelper.bDrawGrid = bShowGrid;
	
	// Turn off so that actors added to the world do not have a lifespan (so they will not auto-destroy themselves).
	PreviewScene->GetWorld()->bBegunPlay = false;

	PreviewScene->SetSkyCubemap(GUnrealEd->GetThumbnailManager()->AmbientCubemap);

	SetRealtime(true);
}

void FVoxelDataAssetEditorViewportClient::Tick(float DeltaSeconds)
{
	FEditorViewportClient::Tick(DeltaSeconds);

	//GEditor->SelectNone(false, true);

	GetVoxelWorld()->Tick(DeltaSeconds);

	GetPanel()->Tick(this, DeltaSeconds);

	// For debug lines
	GetVoxelWorld()->GetWorld()->PersistentLineBatcher->TickComponent(DeltaSeconds, ELevelTick::LEVELTICK_All, nullptr);
}

void FVoxelDataAssetEditorViewportClient::Draw(const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	FEditorViewportClient::Draw(View, PDI);
}

bool FVoxelDataAssetEditorViewportClient::InputKey(FViewport* InViewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed, bool bGamepad)
{
	bool bHandled = GUnrealEd->ComponentVisManager.HandleInputKey(this, InViewport, Key, Event);;

	if (Key == EKeys::MouseScrollDown || Key == EKeys::MouseScrollUp)
	{
		bHandled = true;
	}

	if (Key == EKeys::LeftMouseButton && Event != EInputEvent::IE_Repeat)
	{
		bMousePressed = (Event == EInputEvent::IE_Pressed);
	}

	if (Event == IE_Released && (Key == EKeys::LeftMouseButton || Key == EKeys::MiddleMouseButton || Key == EKeys::RightMouseButton))
	{
		//Set the cursor position to that of the slate cursor so it wont snap back
		Viewport->SetPreCaptureMousePosFromSlateCursor();
	}

	bHandled &= GetPanel()->InputKey(this, InViewport, Key, Event);

	if( !bHandled )
	{
		bHandled = FEditorViewportClient::InputKey(InViewport, ControllerId, Key, Event, AmountDepressed, bGamepad);
	}

	return bHandled;
}

bool FVoxelDataAssetEditorViewportClient::InputAxis(FViewport* InViewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples, bool bGamepad)
{
	return GetPanel()->InputAxis(this, InViewport, Key, Delta, DeltaTime) || FEditorViewportClient::InputAxis(InViewport, ControllerId, Key, Delta, DeltaTime, NumSamples, bGamepad);
}

void FVoxelDataAssetEditorViewportClient::ProcessClick(class FSceneView& View, class HHitProxy* HitProxy, FKey Key, EInputEvent Event, uint32 HitX, uint32 HitY)
{
	const FViewportClick Click(&View, this, Key, Event, HitX, HitY);
	GUnrealEd->ComponentVisManager.HandleClick(this, HitProxy, Click);
	GetPanel()->HandleClick(this, HitProxy, Click);
}

int32 FVoxelDataAssetEditorViewportClient::GetCameraSpeedSetting() const
{
	return GetDefault<UEditorPerProjectUserSettings>()->SCSViewportCameraSpeed;
}

void FVoxelDataAssetEditorViewportClient::SetCameraSpeedSetting(int32 SpeedSetting)
{
	GetMutableDefault<UEditorPerProjectUserSettings>()->SCSViewportCameraSpeed = SpeedSetting;
}

void FVoxelDataAssetEditorViewportClient::MouseMove(FViewport* InViewport, int32 x, int32 y)
{
	FEditorViewportClient::MouseMove(InViewport, x, y);

	GetPanel()->MouseMove(this, InViewport, x, y);
}

void FVoxelDataAssetEditorViewportClient::UpdateMouseDelta()
{
	if (!bMousePressed)
	{
		FEditorViewportClient::UpdateMouseDelta();
	}
}

void FVoxelDataAssetEditorViewportClient::AddReferencedObjects(FReferenceCollector& Collector)
{
	GetPanel()->AddReferencedObjects(Collector);
}

void FVoxelDataAssetEditorViewportClient::InvalidatePreview(bool bResetCamera)
{
	Invalidate();
	RefreshPreviewBounds();
	
	if( bResetCamera )
	{
		ResetCamera();
	}
}

void FVoxelDataAssetEditorViewportClient::ResetCamera()
{
	USceneThumbnailInfo* ThumbnailInfo = USceneThumbnailInfo::StaticClass()->GetDefaultObject<USceneThumbnailInfo>();

	ToggleOrbitCamera(true);
	{
		float TargetDistance = PreviewActorBounds.SphereRadius;
		if(TargetDistance <= 0.0f)
		{
			TargetDistance = AutoViewportOrbitCameraTranslate;
		}

		FRotator ThumbnailAngle(ThumbnailInfo->OrbitPitch, ThumbnailInfo->OrbitYaw, 0.0f);

		SetViewLocationForOrbiting(PreviewActorBounds.Origin);
		SetViewLocation( GetViewLocation() + FVector(0.0f, TargetDistance * 1.5f + ThumbnailInfo->OrbitZoom - AutoViewportOrbitCameraTranslate, 0.0f) );
		SetViewRotation( ThumbnailAngle );	
	}

	Invalidate();
}

AVoxelWorld* FVoxelDataAssetEditorViewportClient::GetVoxelWorld() const
{
	return DataAssetEditorPtr.Pin()->GetVoxelWorld();
}

FVoxelEditorToolsPanel* FVoxelDataAssetEditorViewportClient::GetPanel() const
{
	return DataAssetEditorPtr.Pin()->GetPanel();
}

bool FVoxelDataAssetEditorViewportClient::GetShowGrid() 
{
	return bShowGrid;
}

void FVoxelDataAssetEditorViewportClient::ToggleShowGrid() 
{
	bShowGrid = !bShowGrid;
	DrawHelper.bDrawGrid = bShowGrid;
	Invalidate();
}

void FVoxelDataAssetEditorViewportClient::RefreshPreviewBounds()
{
	AActor* PreviewActor = GetVoxelWorld();

	if(PreviewActor)
	{
		// Compute actor bounds as the sum of its visible parts
		TInlineComponentArray<UPrimitiveComponent*> PrimitiveComponents;
		PreviewActor->GetComponents(PrimitiveComponents);

		PreviewActorBounds = FBoxSphereBounds(ForceInitToZero);
		for(auto CompIt = PrimitiveComponents.CreateConstIterator(); CompIt; ++CompIt)
		{
			// Aggregate primitive components that either have collision enabled or are otherwise visible components in-game
			UPrimitiveComponent* PrimComp = *CompIt;
			if(PrimComp->IsRegistered() && (!PrimComp->bHiddenInGame || PrimComp->IsCollisionEnabled()) && PrimComp->Bounds.SphereRadius < HALF_WORLD_MAX)
			{
				PreviewActorBounds = PreviewActorBounds + PrimComp->Bounds;
			}
		}
	}
}
