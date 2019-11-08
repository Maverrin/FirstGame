// Copyright 2018 Phyronnaz

#include "VoxelDefaultEditorTools.h"
#include "VoxelWorld.h"
#include "VoxelData/VoxelData.h"
#include "VoxelTools/VoxelTools.h"
#include "VoxelTools/VoxelMarker.h"
#include "DataAssetEditor/VoxelDataAssetEditorVoxelWorld.h"

#define LOCTEXT_NAMESPACE "VoxelDefaultEditorTools"

inline bool GetVoxelWorldRaycast(int MouseX, int MouseY, FEditorViewportClient* ViewportClient, AVoxelWorld* World, FVector& OutPosition, FVector& OutNormal)
{
	FVector Start, End;
	{
		// Compute a world space ray from the screen space mouse coordinates
		FSceneViewFamilyContext ViewFamily(FSceneViewFamilyContext::ConstructionValues(ViewportClient->Viewport, ViewportClient->GetScene(), ViewportClient->EngineShowFlags)
			.SetRealtimeUpdate(ViewportClient->IsRealtime()));

		FSceneView* View = ViewportClient->CalcSceneView(&ViewFamily);
		FViewportCursorLocation MouseViewportRay(View, ViewportClient, MouseX, MouseY);
		FVector MouseViewportRayDirection = MouseViewportRay.GetDirection();

		Start = MouseViewportRay.GetOrigin();
		End = Start + WORLD_MAX * MouseViewportRayDirection;
		if (ViewportClient->IsOrtho())
		{
			Start -= WORLD_MAX * MouseViewportRayDirection;
		}
	}
	
	TArray<FHitResult> HitResults;
	if (World->GetWorld()->LineTraceMultiByChannel(HitResults, Start, End, ECC_Visibility))
	{
		for (int Index = 0; Index < HitResults.Num(); Index++)
		{
			auto& HitResult = HitResults[Index];

			if (HitResult.Actor.IsValid() && World == HitResult.Actor)
			{
				OutPosition = HitResult.ImpactPoint;
				OutNormal = HitResult.ImpactNormal;
				return true;
			}
		}
	}

	return false;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TSharedPtr<FUICommandInfo> UVoxelEditorTool_SculptPaintBase::GetCommand() const
{
	switch (Icon)
	{
	case EVoxelEditorTool_Icons::Projection:
		return FVoxelDefaultEditorToolsCommands::Get().Projection;
	case EVoxelEditorTool_Icons::Sphere:
		return FVoxelDefaultEditorToolsCommands::Get().Sphere;
	case EVoxelEditorTool_Icons::Box:
		return FVoxelDefaultEditorToolsCommands::Get().Box;
	case EVoxelEditorTool_Icons::Custom0:
		return FVoxelDefaultEditorToolsCommands::Get().Custom0;
	case EVoxelEditorTool_Icons::Custom1:
		return FVoxelDefaultEditorToolsCommands::Get().Custom1;
	case EVoxelEditorTool_Icons::Custom2:
		return FVoxelDefaultEditorToolsCommands::Get().Custom2;
	case EVoxelEditorTool_Icons::Custom3:
		return FVoxelDefaultEditorToolsCommands::Get().Custom3;
	case EVoxelEditorTool_Icons::Custom4:
		return FVoxelDefaultEditorToolsCommands::Get().Custom4;
	case EVoxelEditorTool_Icons::Custom5:
		return FVoxelDefaultEditorToolsCommands::Get().Custom5;
	case EVoxelEditorTool_Icons::Custom6:
		return FVoxelDefaultEditorToolsCommands::Get().Custom6;
	case EVoxelEditorTool_Icons::Custom7:
		return FVoxelDefaultEditorToolsCommands::Get().Custom7;
	case EVoxelEditorTool_Icons::Custom8:
		return FVoxelDefaultEditorToolsCommands::Get().Custom8;
	case EVoxelEditorTool_Icons::Custom9:
	default:
		return FVoxelDefaultEditorToolsCommands::Get().Custom9;
	}
}

///////////////////////////////////////////////////////////////////////////////

void UVoxelEditorTool_SculptPaintBase::Enable()
{
	if (World && !Marker)
	{
		CreateMarker();
	}
}

void UVoxelEditorTool_SculptPaintBase::Disable()
{
	if (Marker)
	{
		DestroyMarker();
	}
}

///////////////////////////////////////////////////////////////////////////////

void UVoxelEditorTool_SculptPaintBase::GetModeCommands(TArray<FVoxelEditorToolMode>& OutCommands) const
{
	OutCommands.Emplace(
		FVoxelDefaultEditorToolsCommands::Get().Paint,
		LOCTEXT("Paint", "Paint"),
		LOCTEXT("PaintMode", "Paint Mode"),
		(int)EVoxelEditorTool_SculptPaint::Paint);
	OutCommands.Emplace(
		FVoxelDefaultEditorToolsCommands::Get().Sculpt,
		LOCTEXT("Sculpt", "Sculpt"),
		LOCTEXT("SculptMode", "Sculpt Mode"),
		(int)EVoxelEditorTool_SculptPaint::Sculpt);
	OutCommands.Emplace(
		FVoxelDefaultEditorToolsCommands::Get().Grass,
		LOCTEXT("Grass", "Grass"),
		LOCTEXT("GrassMode", "Grass Mode"),
		(int)EVoxelEditorTool_SculptPaint::Grass);
}

bool UVoxelEditorTool_SculptPaintBase::IsModePropertyVisible(const UProperty& Property) const
{
	if (!World)
	{
		return false;
	}
	else if (GetMode() == (int)EVoxelEditorTool_SculptPaint::Sculpt)
	{
		return Property.HasMetaData("Sculpt") || Property.GetToolTipText().ToString().Contains("Sculpt");
	}
	else if (GetMode() == (int)EVoxelEditorTool_SculptPaint::Paint)
	{
		switch (World->GetMaterialConfig())
		{
		case EVoxelMaterialConfig::RGB:
			return Property.HasMetaData("PaintColor") || Property.GetToolTipText().ToString().Contains("PaintColor");
		case EVoxelMaterialConfig::IndexWithMultipleMaterials:
			return Property.HasMetaData("PaintIndex") || Property.GetToolTipText().ToString().Contains("PaintIndex");
		case EVoxelMaterialConfig::DoubleIndexWithMultipleMaterials:
			return Property.HasMetaData("PaintDoubleIndex") || Property.GetToolTipText().ToString().Contains("PaintDoubleIndex");
		default:
			check(false);
			return false;
		}
	}
	else
	{
		return Property.HasMetaData("Grass") || Property.GetToolTipText().ToString().Contains("Grass");
	}
}

///////////////////////////////////////////////////////////////////////////////

void UVoxelEditorTool_SculptPaintBase::Tick(FEditorViewportClient* ViewportClient, float DeltaTime)
{
	Viewport = ViewportClient->Viewport;

	if (!Marker)
	{
		CreateMarker();
	}

	bIsMarkerHidden = !GetVoxelWorldRaycast(Viewport->GetMouseX(), Viewport->GetMouseY(), ViewportClient, World, SavedLastPosition, SavedLastNormal);

	Marker->SetIsTemporarilyHiddenInEditor(bIsMarkerHidden);

	K2_Tick(DeltaTime, SavedLastPosition, SavedLastNormal, bIsMarkerHidden);
}

void UVoxelEditorTool_SculptPaintBase::HandleClick(FEditorViewportClient* ViewportClient, HHitProxy* HitProxy, const FViewportClick& Click)
{
	Viewport = ViewportClient->Viewport;

	FVector Position, Normal;
	if (GetVoxelWorldRaycast(Click.GetClickPos().X, Click.GetClickPos().Y, ViewportClient, World, Position, Normal))
	{
		K2_HandleVoxelWorldClick(Position, Normal);
	}
}

bool UVoxelEditorTool_SculptPaintBase::InputKey(FEditorViewportClient* ViewportClient, FViewport* InViewport, FKey Key, EInputEvent Event)
{
	Viewport = ViewportClient->Viewport;

	bool bHandled = false;
	K2_InputKey(Key, Event, bHandled);
	return bHandled;
}

bool UVoxelEditorTool_SculptPaintBase::InputAxis(FEditorViewportClient* ViewportClient, FViewport* InViewport, FKey Key, float Delta, float DeltaTime)
{
	Viewport = ViewportClient->Viewport;
	
	bool bHandled = false;
	K2_InputAxis(Key, Delta, DeltaTime, bHandled);
	return bHandled;
}

///////////////////////////////////////////////////////////////////////////////

void UVoxelEditorTool_SculptPaintBase::CreateMarker()
{
	check(!Marker && World);

	FActorSpawnParameters Parameters;
	Parameters.ObjectFlags |= RF_Transient;

	UClass* Class = MarkerClass;
	if (!Class)
	{
		Class = AVoxelMarker::StaticClass();
	}
	Marker = World->GetWorld()->SpawnActor<AVoxelMarker>(Class, FTransform::Identity, Parameters);
	Marker->SetAsEditorMarker();
}

void UVoxelEditorTool_SculptPaintBase::DestroyMarker()
{
	check(Marker);

	Marker->Destroy();
	Marker = nullptr;
}
#undef LOCTEXT_NAMESPACE 
