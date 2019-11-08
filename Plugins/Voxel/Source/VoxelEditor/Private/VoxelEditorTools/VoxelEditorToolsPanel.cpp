// Copyright 2018 Phyronnaz

#include "VoxelEditorToolsPanel.h"
#include "VoxelWorld.h"
#include "VoxelData/VoxelData.h"
#include "VoxelEditorTool.h"
#include "VoxelWorldEditor.h"
#include "Editor.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBox.h"
#include "Modules/ModuleManager.h"
#include "AssetRegistryModule.h"
#include "Engine/StreamableManager.h"
#include "VoxelEditorUtilities.h"
#include "EngineUtils.h"

#define LOCTEXT_NAMESPACE "VoxelEditorToolsPanel"

void UVoxelEditorVoxelWorldSelect::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	check(Panel);
	Panel->PostEditWorldSelect();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

FVoxelEditorToolsPanel::FVoxelEditorToolsPanel()
	: CommandList(new FUICommandList())
{
	
}

FVoxelEditorToolsPanel::~FVoxelEditorToolsPanel()
{
	if (IsToolValid(ActiveTool))
	{
		ActiveTool->Disable();
	}
}

void FVoxelEditorToolsPanel::Init(UWorld* Context, AVoxelWorld* WorldToUse)
{
	WorldSelect = NewObject<UVoxelEditorVoxelWorldSelect>(Context, NAME_None, RF_Transient);
	WorldSelect->Panel = this;
	WorldSelect->World = WorldToUse;

	FToolBarBuilder ToolsButtons(CommandList, FMultiBoxCustomization::None);

	for (auto& Tool : GetTools())
	{
		CommandList->MapAction(Tool->GetCommand(), FUIAction(FExecuteAction::CreateRaw(this, &FVoxelEditorToolsPanel::OnChangeTool, Tool), FCanExecuteAction::CreateLambda([]() { return true; }), FIsActionChecked::CreateLambda([=]() { return ActiveTool == Tool; })));
		ToolsButtons.AddToolBarButton(Tool->GetCommand(), NAME_None, Tool->GetLabel(), Tool->GetToolTip());
	}

	// Settings panel
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		FDetailsViewArgs DetailsViewArgs(false, false, false, FDetailsViewArgs::HideNameArea);

		WorldSelectDetailsPanel = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

		ToolGeneralDetailsPanel = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
		ToolGeneralDetailsPanel->SetIsPropertyVisibleDelegate(FIsPropertyVisible::CreateRaw(this, &FVoxelEditorToolsPanel::GetIsPropertyVisibleForGeneral));
		ToolModeDetailsPanel = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
		ToolModeDetailsPanel->SetIsPropertyVisibleDelegate(FIsPropertyVisible::CreateRaw(this, &FVoxelEditorToolsPanel::GetIsPropertyVisibleForMode));

		WorldSelectDetailsPanel->SetObject(GetVoxelWorldSelect(), true);
	}

	SAssignNew(Widget, SScrollBox)
	.IsEnabled(this, &FVoxelEditorToolsPanel::IsEnabled)
	+ SScrollBox::Slot()
	[
		SNew(SVerticalBox)
		.Visibility(WorldToUse? EVisibility::Hidden : EVisibility::Visible)
		+ SVerticalBox::Slot()
		.Padding(0)
		[
			WorldSelectDetailsPanel.ToSharedRef()
		]
	]
	+ SScrollBox::Slot()
	[
		SNew(SHorizontalBox)
		.IsEnabled(this, &FVoxelEditorToolsPanel::IsVoxelWorldValid)
		+ SHorizontalBox::Slot()
		[
			SNew(SButton)
			.ContentPadding(2)
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			.OnClicked(this, &FVoxelEditorToolsPanel::Undo, 1)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Undo", "Undo"))
			]
		]
		+ SHorizontalBox::Slot()
		[
			SNew(SButton)
			.ContentPadding(2)
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			.OnClicked(this, &FVoxelEditorToolsPanel::Redo, 1)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Redo", "Redo"))
			]
		]
	]
	+ SScrollBox::Slot()
	[
		SNew(SHorizontalBox)
		.IsEnabled(this, &FVoxelEditorToolsPanel::IsVoxelWorldValid)
		+ SHorizontalBox::Slot()
		[
			SNew(SButton)
			.ContentPadding(2)
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			.OnClicked(this, &FVoxelEditorToolsPanel::Undo, 10)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Undo x10", "Undo x10"))
			]
		]
		+ SHorizontalBox::Slot()
		[
			SNew(SButton)
			.ContentPadding(2)
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			.OnClicked(this, &FVoxelEditorToolsPanel::Redo, 10)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Redo x10", "Redo x10"))
			]
		]
	]
	+ SScrollBox::Slot()
	[
		SNew(SHorizontalBox)
		.IsEnabled(this, &FVoxelEditorToolsPanel::IsVoxelWorldValid)
		+ SHorizontalBox::Slot()
		[
			SNew(SButton)
			.ContentPadding(2)
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			.OnClicked(this, &FVoxelEditorToolsPanel::Undo, 100)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Undo x100", "Undo x100"))
			]
		]
		+ SHorizontalBox::Slot()
		[
			SNew(SButton)
			.ContentPadding(2)
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			.OnClicked(this, &FVoxelEditorToolsPanel::Redo, 100)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Redo x100", "Redo x100"))
			]
		]
	]
	+ SScrollBox::Slot()
	.Padding(5)
	.HAlign(HAlign_Center)
	[
		SNew(SBox)
		.IsEnabled(this, &FVoxelEditorToolsPanel::IsVoxelWorldValid)
		[
			ToolsButtons.MakeWidget()
		]
	]
	+ SScrollBox::Slot()
	[
		SNew(SVerticalBox)
		.IsEnabled(this, &FVoxelEditorToolsPanel::IsVoxelWorldValid)
		+ SVerticalBox::Slot()
		.Padding(0)
		[
			ToolGeneralDetailsPanel.ToSharedRef()
		]
	]
	+ SScrollBox::Slot()
	.Padding(5)
	.HAlign(HAlign_Center)
	[
		SAssignNew(ToolModeBox, SBox)
		.IsEnabled(this, &FVoxelEditorToolsPanel::IsVoxelWorldValid)
	]
	+ SScrollBox::Slot()
	[
		SNew(SVerticalBox)
		.IsEnabled(this, &FVoxelEditorToolsPanel::IsVoxelWorldValid)
		+ SVerticalBox::Slot()
		.Padding(0)
		[
			ToolModeDetailsPanel.ToSharedRef()
		]
	];

	if (!WorldSelect->World)
	{
		for (TActorIterator<AVoxelWorld> It(Context); It; ++It)
		{
			if (WorldSelect->World)
			{
				// Multiple worlds, so don't select any
				WorldSelect->World = nullptr;
				break;
			}
			WorldSelect->World = *It;
		}
		if (WorldSelect->World && !WorldSelect->World->IsCreated())
		{
			WorldSelect->World->CreateInEditor(AVoxelWorldEditor::StaticClass());
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelEditorToolsPanel::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObjects(Tools);
	Collector.AddReferencedObject(WorldSelect);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelEditorToolsPanel::SetActiveTool(UVoxelEditorTool* Tool)
{
	if (ActiveTool == Tool)
	{
		return;
	}

	if (IsToolValid(ActiveTool))
	{
		ActiveTool->Disable();
	}

	ActiveTool = Tool;

	if (IsToolValid(ActiveTool))
	{
		ActiveTool->SetVoxelWorld(GetVoxelWorld());
		ActiveTool->Enable();

		TArray<FVoxelEditorToolMode> Modes;
		ActiveTool->GetModeCommands(Modes);

		if (Modes.Num() == 0)
		{
			ToolModeBox->SetVisibility(EVisibility::Hidden);
		}
		else
		{
			ToolModeBox->SetVisibility(EVisibility::Visible);

			FToolBarBuilder ToolModeButtons(CommandList, FMultiBoxCustomization::None);

			for (auto& Mode : Modes)
			{
				CommandList->MapAction(Mode.Command,
					FUIAction(
						FExecuteAction::CreateRaw(this, &FVoxelEditorToolsPanel::OnChangeMode, Mode.ModeId),
						FCanExecuteAction::CreateLambda([]() { return true; }),
						FIsActionChecked::CreateRaw(this, &FVoxelEditorToolsPanel::IsModeSelected, Mode.ModeId)
					)
				);
				ToolModeButtons.AddToolBarButton(Mode.Command, NAME_None, Mode.Label, Mode.ToolTip);
			}

			ToolModeBox->SetContent(ToolModeButtons.MakeWidget());
		}
	}
}

void FVoxelEditorToolsPanel::PostEditWorldSelect()
{
	if (IsToolValid(ActiveTool))
	{
		ActiveTool->SetVoxelWorld(GetVoxelWorld());
	}
	AVoxelWorld* World = GetVoxelWorld();
	if (World && !World->IsCreated())
	{
		World->CreateInEditor(AVoxelWorldEditor::StaticClass());
	}
}

FReply FVoxelEditorToolsPanel::Undo(int Times)
{
	AVoxelWorld* World = GetVoxelWorld();

	if (World && World->IsCreated())
	{
		FVoxelEditorUtilities::ModifyWorld(World);

		if (!World->GetData()->CheckIfCurrentFrameIsEmpty())
		{
			World->GetData()->SaveFrame();
		}
		
		TArray<FIntBox> BoundsToUpdate;
		for (int i = 0; i < Times; i++)
		{
			World->GetData()->Undo(BoundsToUpdate);
		}

		for (auto& Bounds : BoundsToUpdate)
		{
			World->UpdateChunksOverlappingBox(Bounds, false);
		}
	}

	return FReply::Handled();
}

FReply FVoxelEditorToolsPanel::Redo(int Times)
{
	AVoxelWorld* World = GetVoxelWorld();

	if (World && World->IsCreated())
	{
		FVoxelEditorUtilities::ModifyWorld(World);

		if (!World->GetData()->CheckIfCurrentFrameIsEmpty())
		{
			World->GetData()->SaveFrame();
		}
		
		TArray<FIntBox> BoundsToUpdate;
		for (int i = 0; i < Times; i++)
		{
			World->GetData()->Redo(BoundsToUpdate);
		}
		
		for (auto& Bounds : BoundsToUpdate)
		{
			World->UpdateChunksOverlappingBox(Bounds, false);
		}
	}
	
	return FReply::Handled();
}

void FVoxelEditorToolsPanel::ClearFrames()
{
	AVoxelWorld* World = GetVoxelWorld();

	if (World && World->IsCreated())
	{
		World->GetData()->ClearFrames();
	}
}

void FVoxelEditorToolsPanel::OnChangeTool(UVoxelEditorTool* NewTool)
{
	SetActiveTool(NewTool); // SetActiveTool checks for validity too. We want to change the tool so that the panel disables itself
	if (IsToolValid(NewTool))
	{
		ToolGeneralDetailsPanel->SetObject(NewTool, true);
		ToolModeDetailsPanel->SetObject(NewTool, true);
	}
}

void FVoxelEditorToolsPanel::OnChangeMode(int NewModeId) const
{
	if(!IsToolValid(ActiveTool))
	{
		return;
	}
	ActiveTool->SetCurrentMode(NewModeId);
	ToolModeDetailsPanel->ForceRefresh();
}

bool FVoxelEditorToolsPanel::IsModeSelected(int ModeId) const
{
	return IsToolValid(ActiveTool) && ActiveTool->GetMode() == ModeId;
}

bool FVoxelEditorToolsPanel::GetIsPropertyVisibleForMode(const FPropertyAndParent& PropertyAndParent) const
{
	if (!IsToolValid(ActiveTool))
	{
		return false;
	}

	const UProperty& Property = PropertyAndParent.Property;

	return !GetIsPropertyVisibleForGeneral(PropertyAndParent) && ActiveTool->IsModePropertyVisible(Property);
}

bool FVoxelEditorToolsPanel::GetIsPropertyVisibleForGeneral(const FPropertyAndParent& PropertyAndParent) const
{
	const UProperty& Property = PropertyAndParent.Property;

	return Property.HasMetaData("ShowForAllModes") || Property.GetToolTipText().ToString().Contains("ShowForAll");
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

bool FVoxelEditorToolsPanel::IsEnabled() const
{
	return !GEditor->PlayWorld && !GEditor->bIsSimulatingInEditor && (ActiveTool == nullptr || IsToolValid(ActiveTool));
}

bool FVoxelEditorToolsPanel::IsVoxelWorldValid() const
{
	return GetVoxelWorld() && GetVoxelWorld()->IsCreated();
}

const TArray<UVoxelEditorTool*> FVoxelEditorToolsPanel::GetTools()
{
	if (Tools.Num() == 0)
	{	
		// Make sure all the tools are loaded
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));

		TArray<FAssetData> AssetDataList;
		AssetRegistryModule.Get().GetAssetsByClass(UBlueprint::StaticClass()->GetFName(), AssetDataList);

		for (const FAssetData& AssetData : AssetDataList)
		{
			auto Path = AssetData.ObjectPath.ToString();
			if (Path.Contains("VoxelEditorTools"))
			{
				FStreamableManager AssetLoader;
				FStringAssetReference AssetRef(Path);
				AssetLoader.LoadSynchronous(AssetRef);
			}
		}

		for (TObjectIterator<UClass> It; It; ++It)
		{
			if (It->IsChildOf(UVoxelEditorTool::StaticClass()) && !It->HasAnyClassFlags(CLASS_Abstract) && !It->GetName().StartsWith(TEXT("SKEL_")) && !It->GetName().StartsWith(TEXT("REINST_")))
			{
				Tools.Add(NewObject<UVoxelEditorTool>((UObject*)GetTransientPackage(), *It));
			}
		}
	}
	return Tools;
}

bool FVoxelEditorToolsPanel::IsToolValid(UVoxelEditorTool* Tool) const
{
	return Tool && Tool->SeemsValid() && IsValid(Tool) && Tool->GetFName().IsValid() && Tool->GetFName() != NAME_None && Tool->IsA(UVoxelEditorTool::StaticClass()) && (!Tool->GetVoxelWorld() || Tool->GetVoxelWorld() == GetVoxelWorld());
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelEditorToolsPanel::MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 MouseX, int32 MouseY)
{
	if (IsToolValid(ActiveTool))
	{
		ActiveTool->MouseMove(ViewportClient, Viewport, MouseX, MouseY);
	}
}

void FVoxelEditorToolsPanel::Tick(FEditorViewportClient* ViewportClient, float DeltaTime)
{
	if (IsToolValid(ActiveTool))
	{
		ActiveTool->Tick(ViewportClient, DeltaTime);
	}

	TimeUntilNextGC -= DeltaTime;
	if (TimeUntilNextGC <= 0)
	{
		TimeUntilNextGC = 1;
		GEngine->ForceGarbageCollection(true);
	}
}

void FVoxelEditorToolsPanel::HandleClick(FEditorViewportClient* ViewportClient, HHitProxy* HitProxy, const FViewportClick& Click)
{
	if (IsToolValid(ActiveTool))
	{
		ActiveTool->HandleClick(ViewportClient, HitProxy, Click);
	}
}

bool FVoxelEditorToolsPanel::InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event)
{
	if (IsToolValid(ActiveTool))
	{
		return ActiveTool->InputKey(ViewportClient, Viewport, Key, Event);
	}
	return false;
}

bool FVoxelEditorToolsPanel::InputAxis(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, float Delta, float DeltaTime)
{
	if (IsToolValid(ActiveTool))
	{
		return ActiveTool->InputAxis(ViewportClient, Viewport, Key, Delta, DeltaTime);
	}
	return false;
}

#undef LOCTEXT_NAMESPACE
