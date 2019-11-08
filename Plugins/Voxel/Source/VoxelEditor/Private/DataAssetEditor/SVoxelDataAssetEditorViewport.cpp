// Copyright 2018 Phyronnaz

#include "SVoxelDataAssetEditorViewport.h"
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
#include "IVoxelDataAssetEditor.h"
#include "AssetViewerSettings.h"
#include "VoxelDataAssetEditorToolkit.h"
#include "VoxelDataAssetEditorViewportClient.h"


#define LOCTEXT_NAMESPACE "VoxelDataAssetEditor"

void SVoxelDataAssetEditorViewportToolBar::Construct(const FArguments& InArgs, TSharedPtr<class SVoxelDataAssetEditorViewport> InViewport)
{
	SCommonEditorViewportToolbarBase::Construct(SCommonEditorViewportToolbarBase::FArguments(), InViewport);
}

TSharedRef<SWidget> SVoxelDataAssetEditorViewportToolBar::GenerateShowMenu() const
{
	GetInfoProvider().OnFloatingButtonClicked();

	TSharedRef<SEditorViewport> ViewportRef = GetInfoProvider().GetViewportWidget();

	const bool bInShouldCloseWindowAfterMenuSelection = true;
	FMenuBuilder ShowMenuBuilder(bInShouldCloseWindowAfterMenuSelection, ViewportRef->GetCommandList());
	{
		auto Commands = FVoxelDataAssetEditorCommands::Get();

		ShowMenuBuilder.AddMenuEntry(Commands.TogglePreviewGrid);
		ShowMenuBuilder.AddMenuEntry(Commands.TogglePreviewBackground);
	}

	return ShowMenuBuilder.MakeWidget();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void SVoxelDataAssetEditorViewport::Construct(const FArguments& InArgs)
{
	VoxelDataAssetEditorPtr = InArgs._VoxelDataAssetEditor;
	AdvancedPreviewScene = VoxelDataAssetEditorPtr.Pin()->GetPreviewScene();
	
	SEditorViewport::Construct( SEditorViewport::FArguments() );
}

SVoxelDataAssetEditorViewport::~SVoxelDataAssetEditorViewport()
{
	UAssetViewerSettings::Get()->OnAssetViewerSettingsChanged().RemoveAll(this);
	
	if (EditorViewportClient.IsValid())
	{
		EditorViewportClient->Viewport = NULL;
	}
}

void SVoxelDataAssetEditorViewport::AddReferencedObjects( FReferenceCollector& Collector )
{

}

void SVoxelDataAssetEditorViewport::RefreshViewport()
{
	SceneViewport->InvalidateDisplay();

	if (EditorViewportClient.IsValid())
	{
		UAssetViewerSettings* Settings = UAssetViewerSettings::Get();
		const int32 ProfileIndex = AdvancedPreviewScene->GetCurrentProfileIndex();
		if (Settings->Profiles.IsValidIndex(ProfileIndex))
		{
			AdvancedPreviewScene->UpdateScene(Settings->Profiles[ProfileIndex]);
			if (Settings->Profiles[ProfileIndex].bRotateLightingRig && !EditorViewportClient->IsRealtime())
			{
				EditorViewportClient->SetRealtime(true);
			}
		}
	}
}

bool SVoxelDataAssetEditorViewport::IsVisible() const
{
	return ViewportWidget.IsValid() && (!ParentTab.IsValid() || ParentTab.Pin()->IsForeground()) && SEditorViewport::IsVisible() ;
}

void SVoxelDataAssetEditorViewport::BindCommands()
{
	SEditorViewport::BindCommands();

	const FVoxelDataAssetEditorCommands& Commands = FVoxelDataAssetEditorCommands::Get();

	check(VoxelDataAssetEditorPtr.IsValid());
	CommandList->Append(VoxelDataAssetEditorPtr.Pin()->GetToolkitCommands());

	// Add the commands to the toolkit command list so that the toolbar buttons can find them
	CommandList->MapAction(
		Commands.TogglePreviewGrid,
		FExecuteAction::CreateSP( EditorViewportClient.Get(), &FVoxelDataAssetEditorViewportClient::ToggleShowGrid ),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP( EditorViewportClient.Get(), &FVoxelDataAssetEditorViewportClient::GetShowGrid ) );

	CommandList->MapAction(
		Commands.TogglePreviewBackground,
		FExecuteAction::CreateSP( this, &SVoxelDataAssetEditorViewport::TogglePreviewBackground ),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP( this, &SVoxelDataAssetEditorViewport::IsTogglePreviewBackgroundChecked ) );
}

void SVoxelDataAssetEditorViewport::OnFocusViewportToSelection()
{

}

void SVoxelDataAssetEditorViewport::TogglePreviewBackground()
{
	UAssetViewerSettings* Settings = UAssetViewerSettings::Get();
	const int32 ProfileIndex = AdvancedPreviewScene->GetCurrentProfileIndex();
	if (Settings->Profiles.IsValidIndex(ProfileIndex))
	{
		AdvancedPreviewScene->SetEnvironmentVisibility(!Settings->Profiles[ProfileIndex].bShowEnvironment);
	}
	RefreshViewport();
}

bool SVoxelDataAssetEditorViewport::IsTogglePreviewBackgroundChecked() const
{
	UAssetViewerSettings* Settings = UAssetViewerSettings::Get();
	const int32 ProfileIndex = AdvancedPreviewScene->GetCurrentProfileIndex();
	if (Settings->Profiles.IsValidIndex(ProfileIndex))
	{
		return Settings->Profiles[ProfileIndex].bShowEnvironment;
	}
	return false;
}

void SVoxelDataAssetEditorViewport::OnAssetViewerSettingsChanged(const FName& InPropertyName)
{
	if (InPropertyName == GET_MEMBER_NAME_CHECKED(FPreviewSceneProfile, bRotateLightingRig) || InPropertyName == NAME_None)
	{
		UAssetViewerSettings* Settings = UAssetViewerSettings::Get();
		const int32 ProfileIndex = AdvancedPreviewScene->GetCurrentProfileIndex();
		if (Settings->Profiles.IsValidIndex(ProfileIndex) &&
			Settings->Profiles[ProfileIndex].bRotateLightingRig
			&& !EditorViewportClient->IsRealtime())
		{
			EditorViewportClient->SetRealtime(true);
		}
	}
}

TSharedRef<class SEditorViewport> SVoxelDataAssetEditorViewport::GetViewportWidget()
{
	return SharedThis(this);
}

TSharedPtr<FExtender> SVoxelDataAssetEditorViewport::GetExtenders() const
{
	TSharedPtr<FExtender> Result(MakeShareable(new FExtender));
	return Result;
}

void SVoxelDataAssetEditorViewport::OnFloatingButtonClicked()
{
}

TSharedRef<FEditorViewportClient> SVoxelDataAssetEditorViewport::MakeEditorViewportClient() 
{
	EditorViewportClient = MakeShareable( new FVoxelDataAssetEditorViewportClient(VoxelDataAssetEditorPtr, AdvancedPreviewScene, SharedThis(this)) );
	UAssetViewerSettings::Get()->OnAssetViewerSettingsChanged().AddRaw(this, &SVoxelDataAssetEditorViewport::OnAssetViewerSettingsChanged);
	EditorViewportClient->SetViewLocation( FVector::ZeroVector );
	EditorViewportClient->SetViewRotation( FRotator(0.0f, -90.0f, 0.0f) );
	EditorViewportClient->SetViewLocationForOrbiting( FVector::ZeroVector );
	EditorViewportClient->bSetListenerPosition = false;
	EditorViewportClient->EngineShowFlags.EnableAdvancedFeatures();
	EditorViewportClient->EngineShowFlags.SetLighting(true);
	EditorViewportClient->EngineShowFlags.SetIndirectLightingCache(true);
	EditorViewportClient->EngineShowFlags.SetPostProcessing(true);
	EditorViewportClient->Invalidate();
	EditorViewportClient->VisibilityDelegate.BindSP( this, &SVoxelDataAssetEditorViewport::IsVisible );

	return EditorViewportClient.ToSharedRef();
}

void SVoxelDataAssetEditorViewport::PopulateViewportOverlays(TSharedRef<class SOverlay> Overlay)
{
	Overlay->AddSlot()
		.VAlign(VAlign_Top)
		[
			SNew(SVoxelDataAssetEditorViewportToolBar, SharedThis(this))
		];
}

EVisibility SVoxelDataAssetEditorViewport::OnGetViewportContentVisibility() const
{
	EVisibility BaseVisibility = SEditorViewport::OnGetViewportContentVisibility();
	if (BaseVisibility != EVisibility::Visible)
	{
		return BaseVisibility;
	}
	return IsVisible() ? EVisibility::Visible : EVisibility::Collapsed;
}
#undef LOCTEXT_NAMESPACE
