// Copyright 2018 Phyronnaz

#include "VoxelDataAssetEditorToolkit.h"
#include "EditorStyleSet.h"
#include "Widgets/Docking/SDockTab.h"
#include "IDetailsView.h"
#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Editor.h"
#include "VoxelAssets/VoxelDataAsset.h"
#include "SVoxelDataAssetEditorViewport.h"
#include "VoxelDataAssetEditorVoxelWorld.h"
#include "AdvancedPreviewScene.h"
#include "VoxelUtilities.h"
#include "VoxelEditorTools/VoxelEditorToolsPanel.h"
#include "VoxelData/VoxelData.h"
#include "DrawDebugHelpers.h"
#include "AdvancedPreviewSceneModule.h"
#include "Widgets/Layout/SScrollBox.h"
#include "VoxelWorldGenerators/EmptyWorldGenerator.h"
#include "VoxelTools/VoxelTools.h"

#define LOCTEXT_NAMESPACE "VoxelGraphEditor"

const FName FVoxelDataAssetEditorToolkit::EditToolsTabId(TEXT("VoxelDataAssetEditor_EditTools"));
const FName FVoxelDataAssetEditorToolkit::PreviewSettingsTabId(TEXT("VoxelDataAssetEditor_PreviewSettings"));
const FName FVoxelDataAssetEditorToolkit::PreviewTabId(TEXT("VoxelDataAssetEditor_Preview"));

FVoxelDataAssetEditorToolkit::FVoxelDataAssetEditorToolkit()
	: DataAsset(nullptr)
{
	PreviewScene = MakeShareable(new FAdvancedPreviewScene(FPreviewScene::ConstructionValues()));
	PreviewScene->SetFloorVisibility(false);
}

void FVoxelDataAssetEditorToolkit::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_VoxelEditor", "Voxel Editor"));
	auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(EditToolsTabId, FOnSpawnTab::CreateSP(this, &FVoxelDataAssetEditorToolkit::SpawnTab_EditTools))
		.SetDisplayName(LOCTEXT("EditToolsTab", "Edit Tools"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));

	InTabManager->RegisterTabSpawner(PreviewSettingsTabId, FOnSpawnTab::CreateSP(this, &FVoxelDataAssetEditorToolkit::SpawnTab_PreviewSettings))
		.SetDisplayName(LOCTEXT("PreviewSettingsTab", "Preview Settings"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));

	InTabManager->RegisterTabSpawner(PreviewTabId, FOnSpawnTab::CreateSP(this, &FVoxelDataAssetEditorToolkit::SpawnTab_Preview))
		.SetDisplayName(LOCTEXT("PreviewTab", "Preview"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Viewports"));
}

void FVoxelDataAssetEditorToolkit::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(EditToolsTabId);
	InTabManager->UnregisterTabSpawner(PreviewSettingsTabId);
	InTabManager->UnregisterTabSpawner(PreviewTabId);
}

FVoxelDataAssetEditorToolkit::~FVoxelDataAssetEditorToolkit()
{
	GEditor->UnregisterForUndo(this);
	World->DestroyWorld();
}

void FVoxelDataAssetEditorToolkit::InitVoxelEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, UObject* ObjectToEdit)
{
	DataAsset = CastChecked<UVoxelDataAsset>(ObjectToEdit);
	DataAsset->Position = -DataAsset->GetSize() / 2;
	DataAsset->Offset = FIntVector::ZeroValue;

	World = PreviewScene->GetWorld()->SpawnActor<AVoxelDataAssetEditorVoxelWorld>();
	World->LoadFromDefaults();
	World->SetWorldGeneratorObject(DataAsset);
	World->SetOctreeDepth(FVoxelUtilities::GetDepthFromSize<CHUNK_SIZE>(DataAsset->GetSize().GetMax()) + 1);
	World->SetLODLimit(0);
	World->SetEnableUndoRedo(true);
	World->SetMeshThreadCount(4);
	World->CreateWorld();
	UVoxelTools::SetBoxAsDirty(World, ((FVoxelDataAssetInstance*)&World->GetData()->WorldGenerator.Get())->GetWorldBounds(), true, DataAsset->GetData()->HasMaterials());

	Panel = MakeShareable(new FVoxelEditorToolsPanel());
	Panel->Init(World->GetWorld(), World);

	// Support undo/redo
	DataAsset->SetFlags(RF_Transactional);

	GEditor->RegisterForUndo(this);

	FVoxelDataAssetEditorCommands::Register();

	BindCommands();

	CreateInternalWidgets();

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_VoxelDataAssetEditor_Layout_v1")
	->AddArea
	(
		FTabManager::NewPrimaryArea() ->SetOrientation(Orient_Vertical)
		->Split
		(
			FTabManager::NewStack()
			->SetSizeCoefficient(0.1f)
			->SetHideTabWell( true )
			->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
		)
		->Split
		(
			FTabManager::NewSplitter() ->SetOrientation(Orient_Horizontal) ->SetSizeCoefficient(0.9f)
			->Split
			(
				FTabManager::NewSplitter() ->SetOrientation(Orient_Vertical) ->SetSizeCoefficient(0.2f)
				->Split
				(
					FTabManager::NewStack()
					->AddTab( PreviewSettingsTabId, ETabState::OpenedTab)
					->AddTab( EditToolsTabId, ETabState::OpenedTab )
				)
			)
			->Split
			(
				FTabManager::NewSplitter() ->SetOrientation( Orient_Vertical )
				->SetSizeCoefficient(0.80f)
				->Split
				(
					FTabManager::NewStack() 
					->SetSizeCoefficient(0.8f)
					->SetHideTabWell( true )
					->AddTab( PreviewTabId, ETabState::OpenedTab )
				)
				
			)
		)
	);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;
	FAssetEditorToolkit::InitAssetEditor(Mode, InitToolkitHost, TEXT("VoxelDataAssetEditorApp"), StandaloneDefaultLayout, bCreateDefaultStandaloneMenu, bCreateDefaultToolbar, ObjectToEdit, false);

	ExtendToolbar();
	RegenerateMenusAndToolbars();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

FName FVoxelDataAssetEditorToolkit::GetToolkitFName() const
{
	return FName("VoxelDataAssetEditor");
}

FText FVoxelDataAssetEditorToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "Voxel Data Asset Editor");
}

FString FVoxelDataAssetEditorToolkit::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "Voxel Data Asset Editor").ToString();
}

FLinearColor FVoxelDataAssetEditorToolkit::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.3f, 0.2f, 0.5f, 0.5f);
}

void FVoxelDataAssetEditorToolkit::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(DataAsset);
	Collector.AddReferencedObject(World);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelDataAssetEditorToolkit::IncreaseWorkArea()
{
	FVoxelUncompressedWorldSave Save;
	World->GetSave(Save);
	
	World->DestroyWorld();
	World->SetWorldGeneratorClass(UEmptyWorldGenerator::StaticClass());
	World->SetOctreeDepth(World->GetOctreeDepth() + 1);
	World->CreateWorld();

	World->LoadFromSave(Save);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelDataAssetEditorToolkit::SaveAsset_Execute()
{
	FIntBox DirtyChunksBounds;
	World->GetData()->GetOctree()->ApplyLambda([&](auto* Octree)
	{
		if (Octree->LOD == 0 && Octree->IsCreated())
		{
			if (!DirtyChunksBounds.IsValid())
			{
				DirtyChunksBounds = Octree->GetBounds();
			}
			else
			{
				DirtyChunksBounds += Octree->GetBounds();
			}
		}
	});
	UVoxelTools::RoundVoxels(World, DirtyChunksBounds);

	FIntBox Bounds;
	TArray<FIntVector> PointsAlone;
	World->GetData()->CallLambdaOnValuesInBounds<true>(DirtyChunksBounds, [&](int X, int Y, int Z, const FVoxelValue& Value, const FVoxelMaterial& Material)
	{
		if (!Value.IsTotallyEmpty())
		{
			if (!Bounds.IsValid())
			{
				Bounds = FIntBox(X, Y, Z);
			}
			else if(!Bounds.IsInside(X, Y, Z))
			{
				Bounds += FIntVector(X, Y, Z);
				PointsAlone.Emplace(X, Y, Z);
			}
		}
	});

	TSharedRef<FVoxelDataAssetData, ESPMode::ThreadSafe> Data = MakeShared<FVoxelDataAssetData, ESPMode::ThreadSafe>();
	Data->SetSize(Bounds.Size(), true);

	World->GetData()->CallLambdaOnValuesInBounds<false>(Bounds, [&](int X, int Y, int Z, const FVoxelValue& Value, const FVoxelMaterial& Material)
	{
		int LX = X - Bounds.Min.X;
		int LY = Y - Bounds.Min.Y;
		int LZ = Z - Bounds.Min.Z;
		check(Data->IsValidIndex(LX, LY, LZ));

		int Index = Data->GetIndex(LX, LY, LZ);
		Data->Materials[Index] = Material;
		Data->Values[Index] = Value;
	});

	DataAsset->SetData(Data);


	FVector Min = World->LocalToGlobal(Bounds.Min);
	FVector Max = World->LocalToGlobal(Bounds.Max);

	FBox Box(Min, Max);

	DrawDebugBox(World->GetWorld(), Box.GetCenter(), Box.GetExtent(), FColor::Red, false, 10, 0, 100);

	for (auto& Point : PointsAlone)
	{
		DrawDebugPoint(World->GetWorld(), World->LocalToGlobal(Point), 10, FColor::Magenta, false, 10);
	}

	FAssetEditorToolkit::SaveAsset_Execute();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TSharedRef<SDockTab> FVoxelDataAssetEditorToolkit::SpawnTab_EditTools(const FSpawnTabArgs& Args)
{	
	check(Args.GetTabId() == EditToolsTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
		.Label(LOCTEXT("VoxelEditToolsTitle", "Edit Tools"))
		[
			Panel->GetWidget().ToSharedRef()
		];
}

TSharedRef<SDockTab> FVoxelDataAssetEditorToolkit::SpawnTab_PreviewSettings(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PreviewSettingsTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
		.Label(LOCTEXT("VoxelPreviewSettingsTitle", "Preview Settings"))
		[
			SNew(SScrollBox)
			+ SScrollBox::Slot()
			[
				PreviewSettings.ToSharedRef()
			]
			+SScrollBox::Slot()
			[
				AdvancedPreviewSettingsWidget.ToSharedRef()
			]
		];
}

TSharedRef<SDockTab> FVoxelDataAssetEditorToolkit::SpawnTab_Preview(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PreviewTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Viewports"))
		.Label(LOCTEXT("VoxelPreviewTitle", "Preview"))
		[
			Preview.ToSharedRef()
		];
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelDataAssetEditorToolkit::NotifyPostChange(const FPropertyChangedEvent& PropertyChangedEvent, UProperty* PropertyThatChanged)
{
	World->SaveToDefaults();
}

void FVoxelDataAssetEditorToolkit::CreateInternalWidgets()
{
	FDetailsViewArgs Args;
	Args.bHideSelectionTip = true;
	Args.NotifyHook = this;
	Args.bShowOptions = false;
	Args.bShowActorLabel = false;

	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PreviewSettings = PropertyModule.CreateDetailView(Args);
	PreviewSettings->SetObject(World);
	
	FAdvancedPreviewSceneModule& AdvancedPreviewSceneModule = FModuleManager::LoadModuleChecked<FAdvancedPreviewSceneModule>("AdvancedPreviewScene");
	AdvancedPreviewSettingsWidget = AdvancedPreviewSceneModule.CreateAdvancedPreviewSceneSettingsWidget(PreviewScene.ToSharedRef());

	Preview = SNew(SVoxelDataAssetEditorViewport).VoxelDataAssetEditor(SharedThis(this));
}

void FVoxelDataAssetEditorToolkit::FillToolbar(FToolBarBuilder& ToolbarBuilder)
{
	ToolbarBuilder.BeginSection("Toolbar");
	
	ToolbarBuilder.AddToolBarButton(FVoxelDataAssetEditorCommands::Get().IncreaseWorkArea);

	ToolbarBuilder.EndSection();
}

void FVoxelDataAssetEditorToolkit::ExtendToolbar()
{
	TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
	
	ToolbarExtender->AddToolBarExtension(
		"Asset",
		EExtensionHook::After,
		GetToolkitCommands(),
		FToolBarExtensionDelegate::CreateRaw(this, &FVoxelDataAssetEditorToolkit::FillToolbar)
	);

	AddToolbarExtender(ToolbarExtender);
}

void FVoxelDataAssetEditorToolkit::BindCommands()
{
	const FVoxelDataAssetEditorCommands& Commands = FVoxelDataAssetEditorCommands::Get();

	ToolkitCommands->MapAction(
		Commands.IncreaseWorkArea,
		FExecuteAction::CreateSP(this, &FVoxelDataAssetEditorToolkit::IncreaseWorkArea));
}

#undef LOCTEXT_NAMESPACE

