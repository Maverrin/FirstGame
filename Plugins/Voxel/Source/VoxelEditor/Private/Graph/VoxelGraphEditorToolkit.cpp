// Copyright 2018 Phyronnaz

#include "VoxelGraphEditorToolkit.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "EdGraph/EdGraphNode.h"
#include "Modules/ModuleManager.h"
#include "EditorStyleSet.h"

#include "ScopedTransaction.h"
#include "GraphEditor.h"
#include "GraphEditorActions.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "EdGraphUtilities.h"
#include "SNodePanel.h"
#include "Editor.h"

#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "Widgets/Docking/SDockTab.h"
#include "Framework/Commands/GenericCommands.h"

#include "SVoxelPalette.h"
#include "HAL/PlatformApplicationMisc.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Framework/Application/SlateApplication.h"
#include "HAL/PlatformFilemanager.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "Misc/FileHelper.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Misc/MessageDialog.h"

#include "VoxelGraph.h"
#include "VoxelGraphSchema.h"
#include "VoxelGraphNode.h"
#include "VoxelGraphNode_Root.h"
#include "VoxelGraph/VoxelGraphMacro.h"
#include "Graph/SVoxelPreview.h"
#include "Graph/SVoxelGraphPreviewViewport.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "EdGraph/EdGraph.h"
#include "Graph/VoxelDebugNode.h"
#include "VoxelGraph/VoxelDefaultNodes.h"
#include "VoxelGraph/VoxelExposedNodes.h"

#define LOCTEXT_NAMESPACE "VoxelGraphEditor"

UVoxelGraphShortcuts::UVoxelGraphShortcuts()
{
	Shortcuts = {
	{EKeys::X, UVoxelNode_XF::StaticClass()},
	{EKeys::Y, UVoxelNode_YF::StaticClass()},
	{EKeys::Z, UVoxelNode_ZF::StaticClass()},
	{EKeys::One, UVoxelNode_FConstant::StaticClass()},

	{EKeys::Multiply, UVoxelNode_FMultiply::StaticClass()},
	{EKeys::Add, UVoxelNode_FAdd::StaticClass()},
	{EKeys::Subtract, UVoxelNode_FSubstract::StaticClass()},
	{EKeys::Divide, UVoxelNode_FDivide::StaticClass()},

	{EKeys::Asterix, UVoxelNode_FMultiply::StaticClass()},
	{EKeys::Slash, UVoxelNode_FDivide::StaticClass()},
	{EKeys::Hyphen, UVoxelNode_FSubstract::StaticClass()}
	};
}

const FName FVoxelGraphEditorToolkit::GraphCanvasTabId(TEXT("VoxelGraphEditor_GraphCanvas"));
const FName FVoxelGraphEditorToolkit::DebugGraphCanvasTabId(TEXT("VoxelGraphEditor_DebugGraphCanvas"));
const FName FVoxelGraphEditorToolkit::PropertiesTabId(TEXT("VoxelGraphEditor_Properties"));
const FName FVoxelGraphEditorToolkit::ShortcutsTabId(TEXT("VoxelGraphEditor_Shortcuts"));
const FName FVoxelGraphEditorToolkit::PreviewSettingsTabId(TEXT("VoxelGraphEditor_PreviewSettings"));
const FName FVoxelGraphEditorToolkit::PaletteTabId(TEXT("VoxelGraphEditor_Palette"));
const FName FVoxelGraphEditorToolkit::PreviewTabId(TEXT("VoxelGraphEditor_Preview"));
const FName FVoxelGraphEditorToolkit::PreviewViewportTabId(TEXT("VoxelGraphEditor_PreviewViewport"));

FVoxelGraphEditorToolkit::FVoxelGraphEditorToolkit()
	: WorldGenerator(nullptr)
	, bAutomaticPreview(false)
{
	PreviewScene = MakeShareable(new FAdvancedPreviewScene(FPreviewScene::ConstructionValues()));
	PreviewScene->SetLightBrightness(0.f);
	PreviewScene->SetFloorVisibility(false);
	PreviewScene->SetEnvironmentVisibility(false);
	PreviewScene->SetSkyBrightness(0.f);
		
	PreviewSceneFloor = NewObject<UStaticMeshComponent>(GetTransientPackage(), NAME_None);

	PreviewScene->AddComponent(PreviewSceneFloor, FTransform::Identity);
}

FVoxelGraphEditorToolkit::~FVoxelGraphEditorToolkit()
{
	GEditor->UnregisterForUndo(this);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelGraphEditorToolkit::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_VoxelEditor", "Voxel Editor"));
	auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(GraphCanvasTabId, FOnSpawnTab::CreateSP(this, &FVoxelGraphEditorToolkit::SpawnTab_GraphCanvas))
		.SetDisplayName(LOCTEXT("GraphCanvasTab", "Main Graph"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "GraphEditor.EventGraph_16x"));

	InTabManager->RegisterTabSpawner(DebugGraphCanvasTabId, FOnSpawnTab::CreateSP(this, &FVoxelGraphEditorToolkit::SpawnTab_DebugGraphCanvas))
		.SetDisplayName(LOCTEXT("DebugGraphCanvasTab", "Debug Graph"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "GraphEditor.EventGraph_16x"));

	InTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FVoxelGraphEditorToolkit::SpawnTab_Properties))
		.SetDisplayName(LOCTEXT("DetailsTab", "Details"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));

	InTabManager->RegisterTabSpawner(ShortcutsTabId, FOnSpawnTab::CreateSP(this, &FVoxelGraphEditorToolkit::SpawnTab_Shortcuts))
		.SetDisplayName(LOCTEXT("ShortcutsTab", "Shortcuts"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));

	InTabManager->RegisterTabSpawner(PreviewSettingsTabId, FOnSpawnTab::CreateSP(this, &FVoxelGraphEditorToolkit::SpawnTab_PreviewSettings))
		.SetDisplayName(LOCTEXT("PreviewSettingsTab", "Preview Settings"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));

	InTabManager->RegisterTabSpawner(PaletteTabId, FOnSpawnTab::CreateSP(this, &FVoxelGraphEditorToolkit::SpawnTab_Palette))
		.SetDisplayName(LOCTEXT("PaletteTab", "Palette"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "Kismet.Tabs.Palette"));

	InTabManager->RegisterTabSpawner(PreviewTabId, FOnSpawnTab::CreateSP(this, &FVoxelGraphEditorToolkit::SpawnTab_Preview))
		.SetDisplayName(LOCTEXT("PreviewTab", "Preview"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Viewports"));

	InTabManager->RegisterTabSpawner(PreviewViewportTabId, FOnSpawnTab::CreateSP(this, &FVoxelGraphEditorToolkit::SpawnTab_PreviewViewport))
		.SetDisplayName(LOCTEXT("PreviewViewportTab", "3D Preview"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Viewports"));
}

void FVoxelGraphEditorToolkit::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(GraphCanvasTabId);
	InTabManager->UnregisterTabSpawner(DebugGraphCanvasTabId);
	InTabManager->UnregisterTabSpawner(PropertiesTabId);
	InTabManager->UnregisterTabSpawner(ShortcutsTabId);
	InTabManager->UnregisterTabSpawner(PreviewSettingsTabId);
	InTabManager->UnregisterTabSpawner(PaletteTabId);
	InTabManager->UnregisterTabSpawner(PreviewTabId);
	InTabManager->UnregisterTabSpawner(PreviewViewportTabId);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelGraphEditorToolkit::InitVoxelEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, UObject* ObjectToEdit)
{
	WorldGenerator = CastChecked<UVoxelGraphGenerator>(ObjectToEdit);

	// Support undo/redo
	WorldGenerator->SetFlags(RF_Transactional);

	GEditor->RegisterForUndo(this);

	FGraphEditorCommands::Register();
	FVoxelGraphEditorCommands::Register();

	BindGraphCommands();

	CreateInternalWidgets();

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_VoxelGraphEditor_Layout_v5")
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
					->AddTab( PaletteTabId, ETabState::OpenedTab )
					->AddTab( PreviewSettingsTabId, ETabState::OpenedTab)
				)
				->Split
				(
					FTabManager::NewStack()
					->AddTab( ShortcutsTabId, ETabState::OpenedTab )
					->AddTab( PropertiesTabId, ETabState::OpenedTab )
				)
			)
			->Split
			(
				FTabManager::NewSplitter() ->SetOrientation( Orient_Vertical )
				->SetSizeCoefficient(0.7f)
				->Split
				(
					FTabManager::NewStack() 
					->SetSizeCoefficient(0.8f)
					->SetHideTabWell( true )
					->AddTab( GraphCanvasTabId, ETabState::OpenedTab )
				)
				
			)
			->Split
			(
				FTabManager::NewSplitter() ->SetOrientation(Orient_Vertical) 
				->SetSizeCoefficient(0.3f)
				->Split
				(
					FTabManager::NewStack()
					->SetHideTabWell( true )
					->AddTab( PreviewTabId, ETabState::OpenedTab )
				)
				->Split
				(
					FTabManager::NewStack()
					->SetHideTabWell( true )
					->AddTab( PreviewViewportTabId, ETabState::OpenedTab )
				)
			)
		)
	);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;
	FAssetEditorToolkit::InitAssetEditor(Mode, InitToolkitHost, TEXT("VoxelGraphEditorApp"), StandaloneDefaultLayout, bCreateDefaultStandaloneMenu, bCreateDefaultToolbar, ObjectToEdit, false);

	ExtendToolbar();
	RegenerateMenusAndToolbars();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

UVoxelGraphGenerator* FVoxelGraphEditorToolkit::GetWorldGenerator() const
{
	return WorldGenerator;
}

void FVoxelGraphEditorToolkit::SetSelection(TArray<UObject*> SelectedObjects)
{
	if (VoxelProperties.IsValid())
	{
		VoxelProperties->SetObjects(SelectedObjects);
	}
}

bool FVoxelGraphEditorToolkit::GetBoundsForSelectedNodes(class FSlateRect& Rect, float Padding)
{
	return VoxelGraphEditor->GetBoundsForSelectedNodes(Rect, Padding);
}

int32 FVoxelGraphEditorToolkit::GetNumberOfSelectedNodes() const
{
	return VoxelGraphEditor->GetSelectedNodes().Num();
}

FGraphPanelSelectionSet FVoxelGraphEditorToolkit::GetSelectedNodes() const
{
	FGraphPanelSelectionSet CurrentSelection;
	if (VoxelGraphEditor.IsValid())
	{
		CurrentSelection = VoxelGraphEditor->GetSelectedNodes();
	}
	return CurrentSelection;
}

void FVoxelGraphEditorToolkit::SelectNodesAndZoomToFit(TArray<UEdGraphNode*>& Nodes)
{
	if (VoxelGraphEditor.IsValid())
	{
		VoxelGraphEditor->ClearSelectionSet();
		for (auto& Node : Nodes)
		{
			VoxelGraphEditor->SetNodeSelection(Node, true);
		}
		VoxelGraphEditor->ZoomToFit(true);
	}
}

void FVoxelGraphEditorToolkit::SetDebugGraph(FVoxelGraphCompiler* Compiler)
{
	struct FVoxelTmpLink
	{
		FVoxelCompilationNode* From;
		int FromIndex;
		FVoxelCompilationNode* To;
		int ToIndex;
	};

	struct FVoxelNodesTmpTree
	{
		FVoxelNodesTmpTree(FVoxelCompilationNode* Node)
			: Node(Node)
		{
		}

		inline void AddChild(FVoxelCompilationNode* ChildNode)
		{
			TmpChildren.AddUnique(ChildNode);
		}

		inline void FixChildren(const TMap<FVoxelCompilationNode*, TSharedPtr<FVoxelNodesTmpTree>>& Map)
		{
			if (Children.Num() == 0)
			{
				for (auto& Child : TmpChildren)
				{
					Children.AddUnique(Map[Child]);
				}
				for (auto& Child : Children)
				{
					if (!Child->Parent)
					{
						Child->Parent = this;
					}
					Child->FixChildren(Map);
				}
			}
		}
		inline void SetPositions(const TMap<FVoxelCompilationNode*, UVoxelGraphNode*>& NodeMap, float StepX, float StepY)
		{
			SetGraphNode(NodeMap);
			SetDepth();
			FixDepth();
			SetWidth();
			SetPositionY();
			SetNodePosition(StepX, StepY);
		}
		inline int GetPositionX() const { return Depth; }
		inline int GetPositionY() const { return PositionY; }

	private:
		int Depth = 0;
		int Width = 0;
		int PositionY = -1;
		
		FVoxelCompilationNode* const Node;
		UVoxelGraphNode* GraphNode = nullptr;

		TArray<TSharedPtr<FVoxelNodesTmpTree>> Children;
		FVoxelNodesTmpTree* Parent = nullptr;
		
		TArray<FVoxelCompilationNode*> TmpChildren;

		inline void SetGraphNode(const TMap<FVoxelCompilationNode*, UVoxelGraphNode*>& NodeMap)
		{
			GraphNode = NodeMap[Node];
			for (auto& Child : Children)
			{
				Child->SetGraphNode(NodeMap);
			}
		}
		inline void SetDepth(int InDepth = 0)
		{
			if (Depth <= InDepth)
			{
				Depth = InDepth;
				for (auto& Child : Children)
				{
					Child->SetDepth(Depth + GraphNode->EstimateNodeWidth());
				}
			}
		}
		inline void FixDepth()
		{
			int MaxDepth = -1;
			for (auto& Child : Children)
			{
				MaxDepth = FMath::Max(MaxDepth, Child->Depth);
			}
			for (auto& Child : Children)
			{
				Child->SetDepth(MaxDepth);
			}
			for (auto& Child : Children)
			{
				Child->FixDepth();
			}
		}
		inline void SetWidth()
		{
			int WidthSum = 0;
			for (auto& Child : Children)
			{
				Child->SetWidth();
				if (Child->Parent == this)
				{
					Width += Child->Width;
				}
			}

			Width = FMath::Max(GraphNode->EstimateNodeHeight(), WidthSum);
		}
		inline void SetPositionY(int InPositionY = 0)
		{
			if (PositionY < 0)
			{
				PositionY = InPositionY;

				int Offset = 0;
				for (auto& Child : Children)
				{
					Child->SetPositionY(PositionY + Offset);
					Offset += Child->Width;
				}
			}
		}
		inline void SetNodePosition(float StepX, float StepY)
		{
			GraphNode->NodePosX = GetPositionX() * StepX;
			GraphNode->NodePosY = GetPositionY() * StepY;
			
			for (auto& Child : Children)
			{
				Child->SetNodePosition(StepX, StepY);
			}
		}
	};

	auto* const Graph = WorldGenerator->VoxelDebugGraph;
	Graph->Modify();
	WorldGenerator->Modify();

	// Delete existing nodes
	{
		auto Nodes = Graph->Nodes; // Copy as we are modifying it
		for (auto& Node : Nodes)
		{
			Graph->RemoveNode(Node);
		}
	}
	WorldGenerator->DebugNodes.Reset();

	FVoxelCompilationNode* FirstNode = Compiler->FirstNode;
	check(FirstNode);

	TMap<FVoxelCompilationNode*, UVoxelGraphNode*> NodeMap;
	TArray<FVoxelTmpLink> LinksToCreate;
	{
		TMap<FVoxelCompilationNode*, TSharedPtr<FVoxelNodesTmpTree>> Trees;
		{
			TArray<FVoxelCompilationNode*> NodesToProcess;
			TSet<FVoxelCompilationNode*> ProcessedNodes;
			NodesToProcess.Add(FirstNode);

			while (NodesToProcess.Num() > 0)
			{
				auto* CompilationNode = NodesToProcess.Pop();
				auto Tree = MakeShared<FVoxelNodesTmpTree>(CompilationNode);
				
				check(!ProcessedNodes.Contains(CompilationNode));
				ProcessedNodes.Add(CompilationNode);
				Trees.Add(CompilationNode, Tree);

				UVoxelDebugNode* VoxelNode = NewObject<UVoxelDebugNode>();
				WorldGenerator->DebugNodes.Add(VoxelNode);
				VoxelNode->CompilationNode = CompilationNode->Clone();
				VoxelNode->bIsFirst = CompilationNode == FirstNode;

				FGraphNodeCreator<UVoxelGraphNode> NodeCreator(*Graph);
				UVoxelGraphNode* GraphNode = NodeCreator.CreateNode();
				VoxelNode->GraphNode = GraphNode;
				GraphNode->SetVoxelNode(VoxelNode);
				NodeCreator.Finalize();

				VoxelNode->CreateStartingConnectors();

				NodeMap.Add(CompilationNode, GraphNode);

				for (int I = 0; I < CompilationNode->GetOutputCount(); I++)
				{
					auto& Pin = CompilationNode->GetOutputPin(I);
					for (auto* LinkedToPin : Pin.GetLinkedTo())
					{
						auto* OtherNode = LinkedToPin->Node;
						if (Pin.PinCategory == EVoxelPinCategory::Exec)
						{
							Tree->AddChild(OtherNode);
						}

						if (Pin.PinCategory == EVoxelPinCategory::Exec || !WorldGenerator->bHideNonExecNodes)
						{
							LinksToCreate.Add({ CompilationNode, I, OtherNode, LinkedToPin->Index });
							if (!ProcessedNodes.Contains(OtherNode))
							{
								NodesToProcess.AddUnique(OtherNode);
							}
						}
					}
				}
				for (int I = 0; I < CompilationNode->GetInputCount(); I++)
				{
					auto& Pin = CompilationNode->GetInputPin(I);
					for (auto* LinkedToPin : Pin.GetLinkedTo())
					{
						auto* OtherNode = LinkedToPin->Node;

						if (Pin.PinCategory == EVoxelPinCategory::Exec || !WorldGenerator->bHideNonExecNodes)
						{
							LinksToCreate.Add({ OtherNode, LinkedToPin->Index, CompilationNode, I });
							if (!ProcessedNodes.Contains(OtherNode))
							{
								NodesToProcess.AddUnique(OtherNode);
							}
						}
					}
				}
			}
		}

		auto FirstTree = Trees[FirstNode];
		FirstTree->FixChildren(Trees);
		FirstTree->SetPositions(NodeMap, WorldGenerator->StepX, WorldGenerator->StepY);
	}

	for (auto& Link : LinksToCreate)
	{
		auto* From = NodeMap[Link.From];
		auto* To = NodeMap[Link.To];

		auto* FromPin = From->GetOutputPin(Link.FromIndex);
		auto* ToPin = To->GetInputPin(Link.ToIndex);

		FromPin->MakeLinkTo(ToPin);
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

FName FVoxelGraphEditorToolkit::GetToolkitFName() const
{
	return FName("VoxelGraphEditor");
}

FText FVoxelGraphEditorToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "Voxel Graph Editor");
}

FString FVoxelGraphEditorToolkit::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "Voxel Graph Editor").ToString();
}

FLinearColor FVoxelGraphEditorToolkit::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.3f, 0.2f, 0.5f, 0.5f);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelGraphEditorToolkit::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(WorldGenerator);
	Collector.AddReferencedObject(PreviewSceneFloor);
	Collector.AddReferencedObject(PreviewSceneMaterial);
	Collector.AddReferencedObject(PreviewTexture);
	Collector.AddReferencedObject(DensitiesTexture);
	Collector.AddReferencedObject(MaterialsTexture);
}

void FVoxelGraphEditorToolkit::PostUndo(bool bSuccess)
{
	if (VoxelGraphEditor.IsValid())
	{
		VoxelGraphEditor->ClearSelectionSet();
		VoxelGraphEditor->NotifyGraphChanged();
	}

}

void FVoxelGraphEditorToolkit::TriggerUpdatePreview(bool bForce, bool bUpdateTextures)
{
	if (bAutomaticPreview || bForce)
	{
		UpdatePreview(bUpdateTextures);
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TSharedRef<SDockTab> FVoxelGraphEditorToolkit::SpawnTab_GraphCanvas(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == GraphCanvasTabId);

	GraphTab = SNew(SDockTab)
		.Label(LOCTEXT("VoxelGraphCanvasTitle", "Main Graph"));

	if (VoxelGraphEditor.IsValid())
	{
		GraphTab->SetContent(VoxelGraphEditor.ToSharedRef());
	}

	return GraphTab.ToSharedRef();
}

TSharedRef<SDockTab> FVoxelGraphEditorToolkit::SpawnTab_DebugGraphCanvas(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == DebugGraphCanvasTabId);

	DebugGraphTab = SNew(SDockTab)
		.Label(LOCTEXT("VoxelDebugGraphCanvasTitle", "Debug Graph"));

	if (VoxelDebugGraphEditor.IsValid())
	{
		DebugGraphTab->SetContent(VoxelDebugGraphEditor.ToSharedRef());
	}

	return DebugGraphTab.ToSharedRef();
}

TSharedRef<SDockTab> FVoxelGraphEditorToolkit::SpawnTab_Properties(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PropertiesTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
		.Label(LOCTEXT("VoxelDetailsTitle", "Details"))
		[
			VoxelProperties.ToSharedRef()
		];
}

TSharedRef<SDockTab> FVoxelGraphEditorToolkit::SpawnTab_Shortcuts(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == ShortcutsTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
		.Label(LOCTEXT("VoxelShortcutsTitle", "Shortcuts"))
		[
			ShortcutsProperties.ToSharedRef()
		];
}

TSharedRef<SDockTab> FVoxelGraphEditorToolkit::SpawnTab_PreviewSettings(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PreviewSettingsTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
		.Label(LOCTEXT("VoxelPreviewSettingsTitle", "Preview Settings"))
		[
			PreviewSettings.ToSharedRef()
		];
}

TSharedRef<SDockTab> FVoxelGraphEditorToolkit::SpawnTab_Palette(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PaletteTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("Kismet.Tabs.Palette"))
		.Label(LOCTEXT("VoxelPaletteTitle", "Palette"))
		[
			Palette.ToSharedRef()
		];
}

TSharedRef<SDockTab> FVoxelGraphEditorToolkit::SpawnTab_Preview(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PreviewTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Viewports"))
		.Label(LOCTEXT("VoxelPreviewTitle", "Preview"))
		[
			Preview.ToSharedRef()
		];
}

TSharedRef<SDockTab> FVoxelGraphEditorToolkit::SpawnTab_PreviewViewport(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PreviewViewportTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Viewports"))
		.Label(LOCTEXT("VoxelPreviewViewportTitle", "3D Preview"))
		[
			PreviewViewport.ToSharedRef()
		];
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelGraphEditorToolkit::OnSelectedNodesChanged(const TSet<class UObject*>& NewSelection)
{
	TArray<UObject*> Selection;

	if (NewSelection.Num())
	{
		for (TSet<class UObject*>::TConstIterator SetIt(NewSelection); SetIt; ++SetIt)
		{
			if (Cast<UVoxelGraphNode_Root>(*SetIt) || Cast<UVoxelGraphMacroInputOutputNode>(*SetIt))
			{
				Selection.Add(GetWorldGenerator());
			}
			else if (UVoxelGraphNode* GraphNode = Cast<UVoxelGraphNode>(*SetIt))
			{
				Selection.Add(GraphNode->VoxelNode);
			}
			else
			{
				Selection.Add(*SetIt);
			}
		}
		//Selection = NewSelection.Array();
	}
	else
	{
		Selection.Add(GetWorldGenerator());
	}

	SetSelection(Selection);
}

void FVoxelGraphEditorToolkit::OnNodeTitleCommitted(const FText& NewText, ETextCommit::Type CommitInfo, UEdGraphNode* NodeBeingChanged)
{
	if (NodeBeingChanged)
	{
		const FScopedTransaction Transaction(LOCTEXT("RenameNode", "Rename Node"));
		NodeBeingChanged->Modify();
		NodeBeingChanged->OnRenameNode(NewText.ToString());
	}
}

void FVoxelGraphEditorToolkit::SelectAllNodes()
{
	VoxelGraphEditor->SelectAllNodes();
}

bool FVoxelGraphEditorToolkit::CanSelectAllNodes() const
{
	return true;
}

void FVoxelGraphEditorToolkit::DeleteSelectedNodes()
{
	const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "VoxelEditorDeleteSelectedNode", "Delete Selected Voxel Node"));

	VoxelGraphEditor->GetCurrentGraph()->Modify();

	const FGraphPanelSelectionSet SelectedNodes = GetSelectedNodes();

	VoxelGraphEditor->ClearSelectionSet();

	for (FGraphPanelSelectionSet::TConstIterator NodeIt(SelectedNodes); NodeIt; ++NodeIt)
	{
		UEdGraphNode* Node = CastChecked<UEdGraphNode>(*NodeIt);

		if (Node->CanUserDeleteNode())
		{
			if (UVoxelGraphNode* VoxelGraphNode = Cast<UVoxelGraphNode>(Node))
			{
				UVoxelNode* DelNode = VoxelGraphNode->VoxelNode;

				FBlueprintEditorUtils::RemoveNode(NULL, VoxelGraphNode, true);

				// Make sure Voxel is updated to match graph
				WorldGenerator->CompileVoxelNodesFromGraphNodes();

				// Remove this node from the Voxel's list of all VoxelNodes
				WorldGenerator->AllNodes.Remove(DelNode);
				WorldGenerator->MarkPackageDirty();
			}
			else
			{
				FBlueprintEditorUtils::RemoveNode(NULL, Node, true);
			}
		}
	}
}

bool FVoxelGraphEditorToolkit::CanDeleteNodes() const
{
	const FGraphPanelSelectionSet SelectedNodes = GetSelectedNodes();

	if (SelectedNodes.Num() == 1)
	{
		for (FGraphPanelSelectionSet::TConstIterator NodeIt(SelectedNodes); NodeIt; ++NodeIt)
		{
			UVoxelGraphNode* GraphNode = Cast<UVoxelGraphNode>(*NodeIt);
			if (GraphNode && !GraphNode->CanUserDeleteNode())
			{
				return false;
			}
		}
	}

	return SelectedNodes.Num() > 0;
}

void FVoxelGraphEditorToolkit::DeleteSelectedDuplicatableNodes()
{
	// Cache off the old selection
	const FGraphPanelSelectionSet OldSelectedNodes = GetSelectedNodes();

	// Clear the selection and only select the nodes that can be duplicated
	FGraphPanelSelectionSet RemainingNodes;
	VoxelGraphEditor->ClearSelectionSet();

	for (FGraphPanelSelectionSet::TConstIterator SelectedIter(OldSelectedNodes); SelectedIter; ++SelectedIter)
	{
		UEdGraphNode* Node = Cast<UEdGraphNode>(*SelectedIter);
		if ((Node != NULL) && Node->CanDuplicateNode())
		{
			VoxelGraphEditor->SetNodeSelection(Node, true);
		}
		else
		{
			RemainingNodes.Add(Node);
		}
	}

	// Delete the duplicatable nodes
	DeleteSelectedNodes();

	// Reselect whatever's left from the original selection after the deletion
	VoxelGraphEditor->ClearSelectionSet();

	for (FGraphPanelSelectionSet::TConstIterator SelectedIter(RemainingNodes); SelectedIter; ++SelectedIter)
	{
		if (UEdGraphNode* Node = Cast<UEdGraphNode>(*SelectedIter))
		{
			VoxelGraphEditor->SetNodeSelection(Node, true);
		}
	}
}

void FVoxelGraphEditorToolkit::CutSelectedNodes()
{
	CopySelectedNodes();
	// Cut should only delete nodes that can be duplicated
	DeleteSelectedDuplicatableNodes();
}

bool FVoxelGraphEditorToolkit::CanCutNodes() const
{
	return CanCopyNodes() && CanDeleteNodes();
}

void FVoxelGraphEditorToolkit::CopySelectedNodes()
{
	// Export the selected nodes and place the text on the clipboard
	FGraphPanelSelectionSet SelectedNodes;
	{
		FGraphPanelSelectionSet AllSelectedNodes = GetSelectedNodes();
		for (auto It = AllSelectedNodes.CreateIterator(); It; ++It)
		{
			auto* Node = Cast<UEdGraphNode>(*It);
			if (Node && Node->CanDuplicateNode())
			{
				SelectedNodes.Add(Node);
			}
		}
	}

	FString ExportedText;

	for (auto It = SelectedNodes.CreateIterator(); It; ++It)
	{
		CastChecked<UEdGraphNode>(*It)->PrepareForCopying();
	}

	FEdGraphUtilities::ExportNodesToText(SelectedNodes, /*out*/ ExportedText);
	FPlatformApplicationMisc::ClipboardCopy(*ExportedText);

	// Make sure Voxel remains the owner of the copied nodes
	for (auto It = SelectedNodes.CreateIterator(); It; ++It)
	{
		if (auto* Node = Cast<UVoxelGraphNode>(*It))
		{
			Node->PostCopyNode();
		}
	}
}

bool FVoxelGraphEditorToolkit::CanCopyNodes() const
{
	// If any of the nodes can be duplicated then we should allow copying
	const FGraphPanelSelectionSet SelectedNodes = GetSelectedNodes();
	for (FGraphPanelSelectionSet::TConstIterator SelectedIter(SelectedNodes); SelectedIter; ++SelectedIter)
	{
		UEdGraphNode* Node = Cast<UEdGraphNode>(*SelectedIter);
		if ((Node != NULL) && Node->CanDuplicateNode())
		{
			return true;
		}
	}
	return false;
}

void FVoxelGraphEditorToolkit::PasteNodes()
{
	PasteNodesHere(VoxelGraphEditor->GetPasteLocation());
}

void FVoxelGraphEditorToolkit::PasteNodesHere(const FVector2D& Location)
{
	// Undo/Redo support
	const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "VoxelEditorPaste", "Paste Voxel Node"));
	WorldGenerator->GetGraph()->Modify();
	WorldGenerator->Modify();

	// Clear the selection set (newly pasted stuff will be selected)
	VoxelGraphEditor->ClearSelectionSet();

	// Grab the text to paste from the clipboard.
	FString TextToImport;
	FPlatformApplicationMisc::ClipboardPaste(TextToImport);

	// Import the nodes
	TSet<UEdGraphNode*> PastedNodes;
	FEdGraphUtilities::ImportNodesFromText(WorldGenerator->GetGraph(), TextToImport, /*out*/ PastedNodes);

	//Average position of nodes so we can move them while still maintaining relative distances to each other
	FVector2D AvgNodePosition(0.0f, 0.0f);

	for (TSet<UEdGraphNode*>::TIterator It(PastedNodes); It; ++It)
	{
		UEdGraphNode* Node = *It;
		AvgNodePosition.X += Node->NodePosX;
		AvgNodePosition.Y += Node->NodePosY;
	}

	if (PastedNodes.Num() > 0)
	{
		float InvNumNodes = 1.0f / float(PastedNodes.Num());
		AvgNodePosition.X *= InvNumNodes;
		AvgNodePosition.Y *= InvNumNodes;
	}

	for (TSet<UEdGraphNode*>::TIterator It(PastedNodes); It; ++It)
	{
		UEdGraphNode* Node = *It;

		if (UVoxelGraphNode* VoxelGraphNode = Cast<UVoxelGraphNode>(Node))
		{
			if (auto& LocalNode = VoxelGraphNode->VoxelNode)
			{
				WorldGenerator->AllNodes.Add(LocalNode);
				LocalNode->Graph = WorldGenerator;
				// Fix node if needed (eg portal node)
				LocalNode->PostLoad();
			}
		}

		// Select the newly pasted stuff
		VoxelGraphEditor->SetNodeSelection(Node, true);

		Node->NodePosX = (Node->NodePosX - AvgNodePosition.X) + Location.X;
		Node->NodePosY = (Node->NodePosY - AvgNodePosition.Y) + Location.Y;

		Node->SnapToGrid(SNodePanel::GetSnapGridSize());

		// Give new node a different Guid from the old one
		Node->CreateNewGuid();
	}

	// Force new pasted VoxelNodes to have same connections as graph nodes
	WorldGenerator->CompileVoxelNodesFromGraphNodes();

	// Update UI
	VoxelGraphEditor->NotifyGraphChanged();

	WorldGenerator->PostEditChange();
	WorldGenerator->MarkPackageDirty();
}

bool FVoxelGraphEditorToolkit::CanPasteNodes() const
{
	FString ClipboardContent;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardContent);

	return FEdGraphUtilities::CanImportNodesFromText(WorldGenerator->VoxelGraph, ClipboardContent);
}

void FVoxelGraphEditorToolkit::DuplicateNodes()
{
	// Copy and paste current selection
	CopySelectedNodes();
	PasteNodes();
}

bool FVoxelGraphEditorToolkit::CanDuplicateNodes() const
{
	return CanCopyNodes();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelGraphEditorToolkit::CompileToCpp()
{
	/*
	 * Get path
	 */
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();

	check(DesktopPlatform);

	const FString DefaultPath = FPaths::GetProjectFilePath();

	// show the file browse dialog
	TSharedPtr<SWindow> ParentWindow = FSlateApplication::Get().FindWidgetWindow(VoxelGraphEditor.ToSharedRef());
	void* ParentWindowHandle = (ParentWindow.IsValid() && ParentWindow->GetNativeWindow().IsValid()) ? ParentWindow->GetNativeWindow()->GetOSWindowHandle() : nullptr;
	
	const FString DirectoryPath(FPaths::GameSourceDir() + TEXT("GeneratedWorldGenerators/"));
	if (!FPaths::DirectoryExists(DirectoryPath))
	{
		FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*DirectoryPath);
		FString Text;

		Text.Append(TEXT("using UnrealBuildTool;\n\n"));
		Text.Append(TEXT("public class GeneratedWorldGenerators : ModuleRules\n"));
		Text.Append(TEXT("{\n"));
		Text.Append(TEXT("	public GeneratedWorldGenerators(ReadOnlyTargetRules Target) : base(Target)\n"));
		Text.Append(TEXT("	{\n"));
		Text.Append(TEXT("		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;\n\n"));

		Text.Append(TEXT("		PublicDependencyModuleNames.AddRange(new string[] { \"Core\", \"CoreUObject\", \"Engine\", \"InputCore\", \"Voxel\" });\n\n"));
		Text.Append(TEXT("	}\n"));
		Text.Append(TEXT("}"));

		FFileHelper::SaveStringToFile(Text, *(DirectoryPath + TEXT("GeneratedWorldGenerators.Build.cs")));

		Text.Reset();
		Text.Append(TEXT("#pragma once\n\n#include \"CoreMinimal.h\"\n"));
		
		FFileHelper::SaveStringToFile(Text, *(DirectoryPath + TEXT("GeneratedWorldGenerators.h")));

		Text.Reset();
		Text.Append(TEXT("#include \"GeneratedWorldGenerators.h\"\n"));
		Text.Append(TEXT("#include \"Modules/ModuleManager.h\"\n\n"));
		Text.Append(TEXT("IMPLEMENT_MODULE( FDefaultGameModuleImpl, GeneratedWorldGenerators );\n"));
		
		FFileHelper::SaveStringToFile(Text, *(DirectoryPath + TEXT("GeneratedWorldGenerators.cpp")));
	}

	{
		IFileManager& FileManager = IFileManager::Get();
		TArray<FString> FoundFiles;
		FileManager.FindFiles(FoundFiles, *FPaths::ProjectDir(), TEXT(".uproject"));

		for (const auto& File : FoundFiles)
		{
			const FString TargetPath(FPaths::ProjectDir() + File);
			FString TargetContent;
			FFileHelper::LoadFileToString(TargetContent, *TargetPath);
			if (!TargetContent.Contains(TEXT("\"GeneratedWorldGenerators\"")))
			{
				auto Result = FMessageDialog::Open(EAppMsgType::YesNoCancel, FText::FromString(File + TEXT(" doesn't have the GeneratedWorldGenerators module dependency. Add it automatically? (You'll have to restart the editor)\n\nChoose Yes if you don't know")));
				switch (Result)
				{
				case EAppReturnType::No:
					continue;
				case EAppReturnType::Yes:
					break;
				case EAppReturnType::Cancel:
					return;
				default:
					check(false);
					break;
				}

				int32 Position = TargetContent.Find(TEXT("\"Modules\": ["));
				if (Position < 0)
				{
					FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("Cannot add the GeneratedWorldGenerators module dependency. Please add a C++ class to your project and restart it")));
				}
				else
				{
					FString Text;
					Text.Append(TEXT("\n"));
					Text.Append(TEXT("\t\t{\n"));
					Text.Append(TEXT("\t\t\t\"Name\": \"GeneratedWorldGenerators\",\n"));
					Text.Append(TEXT("\t\t\t\"Type\": \"Runtime\",\n"));
					Text.Append(TEXT("\t\t\t\"LoadingPhase\": \"Default\",\n"));
					Text.Append(TEXT("\t\t\t\"AdditionalDependencies\": [\n"));
					Text.Append(TEXT("\t\t\t\t\"Engine\",\n"));
					Text.Append(TEXT("\t\t\t\t\"CoreUObject\"\n"));
					Text.Append(TEXT("\t\t\t]\n"));
					Text.Append(TEXT("\t\t},"));

					TargetContent.InsertAt(Position + FString(TEXT("\"Modules\": [")).Len(), Text);

					FileManager.Delete(*TargetPath);
					FFileHelper::SaveStringToFile(TargetContent, *TargetPath);
				}
			}
		}
	}

	{
		IFileManager& FileManager = IFileManager::Get();
		TArray<FString> FoundFiles;
		FileManager.FindFiles(FoundFiles, *FPaths::GameSourceDir(), TEXT(".Target.cs"));

		for (const auto& File : FoundFiles)
		{
			const FString TargetPath(FPaths::GameSourceDir() + File);
			FString TargetContent;
			FFileHelper::LoadFileToString(TargetContent, *TargetPath);
			if (!TargetContent.Contains(TEXT("\"GeneratedWorldGenerators\"")))
			{
				auto Result = FMessageDialog::Open(EAppMsgType::YesNoCancel, FText::FromString(File + TEXT(" doesn't have the GeneratedWorldGenerators module dependency. Add it automatically? (You'll have to restart the editor)\n\nChoose Yes if you don't know")));
				switch (Result)
				{
				case EAppReturnType::No:
					continue;
				case EAppReturnType::Yes:
					break;
				case EAppReturnType::Cancel:
					return;
				default:
					check(false);
					break;
				}
				
				int32 Position = TargetContent.Find(TEXT("ExtraModuleNames.AddRange("));
				if (Position < 0)
				{
					Position = TargetContent.Find(TEXT("ExtraModuleNames.Add("));
				}
				if (Position < 0)
				{
					FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("Cannot add the GeneratedWorldGenerators module dependency. Please add the following code to ") + File + TEXT(": \n\nExtraModuleNames.AddRange( new string[] { \"GeneratedWorldGenerators\" } );")));
				}
				else
				{
					TargetContent.InsertAt(Position, TEXT("ExtraModuleNames.AddRange( new string[] { \"GeneratedWorldGenerators\" } );\n\t\t"));
				
					FileManager.Move(*(TargetPath + TEXT(".bak")), *TargetPath);
					FFileHelper::SaveStringToFile(TargetContent, *TargetPath);
				}
			}
		}
	}

	TArray<FString> OutFiles;
	if (DesktopPlatform->SaveFileDialog(ParentWindowHandle, TEXT("File to create"), DirectoryPath, WorldGenerator->GetName() + TEXT(".h"), TEXT(".h"), EFileDialogFlags::None, OutFiles))
	{
		check(OutFiles.Num() == 1);

		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

		// Get absolute file path
		FString AbsoluteFilePath = OutFiles[0];

		FString CppText;
		FString ErrorMessage;
		bool bCompilationSuccess = WorldGenerator->CompileToCpp(CppText, FPaths::GetBaseFilename(AbsoluteFilePath), ErrorMessage);

		if (!bCompilationSuccess)
		{
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("Compilation failed!\nError: ") + ErrorMessage));
			return;
		}

		bool bSuccess = FFileHelper::SaveStringToFile(CppText, *AbsoluteFilePath);

		if (bSuccess)
		{
			FString Text = AbsoluteFilePath + TEXT(" was successfully created");
			FNotificationInfo Info(FText::FromString(Text));
			Info.ExpireDuration = 10.0f;
			FSlateNotificationManager::Get().AddNotification(Info);
		}
		else
		{
			FString Text = AbsoluteFilePath + TEXT(" was NOT successfully created");
			FNotificationInfo Info(FText::FromString(Text));
			Info.ExpireDuration = 4.0f;
			Info.CheckBoxState = ECheckBoxState::Unchecked;
			FSlateNotificationManager::Get().AddNotification(Info);
		}
	}
}

void FVoxelGraphEditorToolkit::RecreateNodes()
{
	for (int I = 0; I < 4; I++)
	{
		TArray<UVoxelGraphNode*> AllNodes;
		VoxelGraphEditor->GetCurrentGraph()->GetNodesOfClass<UVoxelGraphNode>(AllNodes);

		for (TArray<UVoxelGraphNode*>::TIterator NodeIt(AllNodes); NodeIt; ++NodeIt)
		{
			UVoxelGraphNode* CurrentNode = *NodeIt;
			CurrentNode->ReconstructNode();
		}

		WorldGenerator->CompileVoxelNodesFromGraphNodes();

		GraphTab->ClearContent();
		VoxelGraphEditor = CreateGraphEditorWidget(false);
		GraphTab->SetContent(VoxelGraphEditor.ToSharedRef());
	}
}

void FVoxelGraphEditorToolkit::ToggleAutomaticPreview()
{
	bAutomaticPreview = !bAutomaticPreview;
}

bool FVoxelGraphEditorToolkit::IsToggleAutomaticPreviewChecked() const
{
	return bAutomaticPreview;
}

void FVoxelGraphEditorToolkit::UpdatePreview(bool bUpdateTextures)
{
	if (Cast<UVoxelGraphMacro>(WorldGenerator))
	{
		return;
	}

	UVoxelGraphPreviewSettings* WGPreviewSettings = WorldGenerator->PreviewSettings;

	if (bUpdateTextures)
	{
		TSharedPtr<FVoxelGraphGeneratorInstance, ESPMode::ThreadSafe> WorldGeneratorInstance;
		if(!WorldGenerator->GetWorldGenerator(true, WorldGeneratorInstance))
		{
			return;
		}

		FVoxelWorldGeneratorInit Init(TMap<FString, int>(), 100);
		WorldGeneratorInstance->InitPreview(Init);

		const int SizeInVoxels = WGPreviewSettings->ImageResolution;
		const int VoxelsPerPixel = WGPreviewSettings->VoxelsPerPixel;

		TArray<float> Values;
		TArray<FVoxelMaterial> Materials;
		Values.SetNumUninitialized(SizeInVoxels * SizeInVoxels);
		Materials.SetNumUninitialized(SizeInVoxels * SizeInVoxels);

		const int Offset = SizeInVoxels / 2 * VoxelsPerPixel;
		FIntVector Start = WGPreviewSettings->Center;
		FIntVector Size(1);
		switch (WGPreviewSettings->LeftToRight)
		{
		case EVoxelGraphPreviewAxes::X:
			Size.X = SizeInVoxels;
			Start.X -= Offset;
			break;
		case EVoxelGraphPreviewAxes::Y:
			Size.Y = SizeInVoxels;
			Start.Y -= Offset;
			break;
		case EVoxelGraphPreviewAxes::Z:
			Size.Z = SizeInVoxels;
			Start.Z -= Offset;
			break;
		}
		switch (WGPreviewSettings->BottomToTop)
		{
		case EVoxelGraphPreviewAxes::X:
			Size.X = SizeInVoxels;
			Start.X -= Offset;
			break;
		case EVoxelGraphPreviewAxes::Y:
			Size.Y = SizeInVoxels;
			Start.Y -= Offset;
			break;
		case EVoxelGraphPreviewAxes::Z:
			Size.Z = SizeInVoxels;
			Start.Z -= Offset;
			break;
		}

		WorldGeneratorInstance->GetValuesAndMaterialsPreview(Values.GetData(), Materials.GetData(), FIntBox(Start, Start + Size * VoxelsPerPixel), Start, FMath::FloorLog2(WGPreviewSettings->VoxelsPerPixel), Size);

		TArray<FColor> NewDensities;
		TArray<FColor> NewMaterials;
		NewDensities.SetNumUninitialized(SizeInVoxels * SizeInVoxels);
		NewMaterials.SetNumUninitialized(SizeInVoxels * SizeInVoxels);
		
		for (int X = 0; X < SizeInVoxels; X++)
		{
			for (int Y = 0; Y < SizeInVoxels; Y++)
			{
				FIntVector Position(0, 0, 0);
				switch (WGPreviewSettings->LeftToRight)
				{
				case EVoxelGraphPreviewAxes::X:
					Position.X = X;
					break;
				case EVoxelGraphPreviewAxes::Y:
					Position.Y = X;
					break;
				case EVoxelGraphPreviewAxes::Z:
					Position.Z = X;
					break;
				}
				switch (WGPreviewSettings->BottomToTop)
				{
				case EVoxelGraphPreviewAxes::X:
					Position.X = SizeInVoxels - 1 - Y;
					break;
				case EVoxelGraphPreviewAxes::Y:
					Position.Y = SizeInVoxels - 1 - Y;
					break;
				case EVoxelGraphPreviewAxes::Z:
					Position.Z = SizeInVoxels - 1 - Y;
					break;
				}

				{
					const int TextureIndex = X + SizeInVoxels * Y;
					const int DataIndex = Position.X + Position.Y * Size.X + Position.Z * Size.X * Size.Y;

					{
						float Alpha = (Values[DataIndex] - WGPreviewSettings->MinValue) / (WGPreviewSettings->MaxValue - WGPreviewSettings->MinValue);
						uint8 IntAlpha = FMath::Clamp(FMath::RoundToInt(Alpha * 255.f), 0, 255);
						NewDensities[TextureIndex] = FColor(IntAlpha, IntAlpha, IntAlpha, 255);
					}

					{
						FVoxelMaterial& Material = Materials[DataIndex];
						FColor Color;

						if (WGPreviewSettings->MaterialConfig == EVoxelMaterialConfig::RGB)
						{
							Color = Material.GetColor();
						}
						else
						{
							if (WGPreviewSettings->ColorsForIndexMaterialConfig.Num() == 0)
							{
								WGPreviewSettings->ColorsForIndexMaterialConfig = { FLinearColor::Green, FLinearColor::Red, FLinearColor::Blue, FLinearColor::White };
							}
							Color = WGPreviewSettings->ColorsForIndexMaterialConfig[FMath::Clamp<int>(Material.GetIndex(), 0, WGPreviewSettings->ColorsForIndexMaterialConfig.Num() - 1)].ToFColor(false);
						}

						NewMaterials[TextureIndex] = Color;
					}
				}
			}
		}

		{
			if (!PreviewTexture || PreviewTexture->GetSizeX() != SizeInVoxels || PreviewTexture->GetSizeY() != SizeInVoxels)
			{
				PreviewTexture = UTexture2D::CreateTransient(SizeInVoxels, SizeInVoxels);;
			}
			FTexture2DMipMap& Mip = PreviewTexture->PlatformData->Mips[0];
			{
				auto& NewData = WGPreviewSettings->ImagePreviewType == EVoxelGraphPreviewType::Density ? NewDensities : NewMaterials;
				void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);
				FMemory::Memcpy(Data, NewData.GetData(), NewData.Num() * sizeof(FColor));
			}
			Mip.BulkData.Unlock();
			PreviewTexture->UpdateResource();
			Preview->SetTexture(PreviewTexture);
		}

		{
			if (!DensitiesTexture || DensitiesTexture->GetSizeX() != SizeInVoxels || DensitiesTexture->GetSizeY() != SizeInVoxels)
			{
				DensitiesTexture = UTexture2D::CreateTransient(SizeInVoxels, SizeInVoxels);;
			}
			FTexture2DMipMap& Mip = DensitiesTexture->PlatformData->Mips[0];
			void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);
			FMemory::Memcpy(Data, NewDensities.GetData(), NewDensities.Num() * sizeof(FColor));
			Mip.BulkData.Unlock();
			DensitiesTexture->UpdateResource();
		}
		{
			if (!MaterialsTexture || MaterialsTexture->GetSizeX() != SizeInVoxels || MaterialsTexture->GetSizeY() != SizeInVoxels)
			{
				MaterialsTexture = UTexture2D::CreateTransient(SizeInVoxels, SizeInVoxels);;
			}
			FTexture2DMipMap& Mip = MaterialsTexture->PlatformData->Mips[0];
			void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);
			FMemory::Memcpy(Data, NewMaterials.GetData(), NewMaterials.Num() * sizeof(FColor));
			Mip.BulkData.Unlock();
			MaterialsTexture->UpdateResource();
		}

		WorldGenerator->SetPreviewTexture(NewDensities, SizeInVoxels);
	}

	if (!PreviewSceneMaterial || PreviewSceneMaterial->Parent != WGPreviewSettings->Material)
	{
		PreviewSceneMaterial = UMaterialInstanceDynamic::Create(WGPreviewSettings->Material, GetTransientPackage(), TEXT("PreviewSceneMaterial"));
	}
	PreviewSceneMaterial->SetTextureParameterValue(TEXT("Color"), MaterialsTexture);
	PreviewSceneMaterial->SetTextureParameterValue(TEXT("Height"), DensitiesTexture);
	PreviewSceneMaterial->SetScalarParameterValue(TEXT("Height"), WGPreviewSettings->Height);
	PreviewSceneMaterial->SetScalarParameterValue(TEXT("UseHeightAsColor"), WGPreviewSettings->bUseDensityAsColor ? 1.f : 0.f);
	PreviewSceneMaterial->SetScalarParameterValue(TEXT("UseWater"), WGPreviewSettings->bEnableWater ? 1.f : 0.f);
	PreviewSceneMaterial->SetVectorParameterValue(TEXT("LightDirection"), WGPreviewSettings->LightDirection);
	PreviewSceneMaterial->SetScalarParameterValue(TEXT("Brightness"), WGPreviewSettings->Brightness);
	PreviewSceneMaterial->SetScalarParameterValue(TEXT("ShadowDensity"), WGPreviewSettings->ShadowDensity);

	if (PreviewSceneFloor->GetStaticMesh() != WGPreviewSettings->Mesh)
	{
		PreviewSceneFloor->SetStaticMesh(WGPreviewSettings->Mesh);
	}
	PreviewSceneFloor->SetMaterial(0, PreviewSceneMaterial);
	PreviewSceneFloor->SetWorldScale3D(WGPreviewSettings->MeshScale);
	PreviewSceneFloor->SetBoundsScale(1e6f);

	PreviewViewport->RefreshViewport();
}

void FVoxelGraphEditorToolkit::ToggleStats()
{
	WorldGenerator->bEnableStats = !WorldGenerator->bEnableStats;
	WorldGenerator->GetWorldGenerator(); // Update nodes
}

bool FVoxelGraphEditorToolkit::IsToggleStatsChecked() const
{
	return WorldGenerator->bEnableStats;
}

void FVoxelGraphEditorToolkit::ToggleShowAxisDependencies()
{
	WorldGenerator->bShowAxisDependencies = !WorldGenerator->bShowAxisDependencies;
	WorldGenerator->GetWorldGenerator(); // Update nodes
}

bool FVoxelGraphEditorToolkit::IsToggleShowAxisDependenciesChecked() const
{
	return WorldGenerator->bShowAxisDependencies;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelGraphEditorToolkit::UndoGraphAction()
{
	GEditor->UndoTransaction();
}

void FVoxelGraphEditorToolkit::RedoGraphAction()
{
	// Clear selection, to avoid holding refs to nodes that go away
	VoxelGraphEditor->ClearSelectionSet();

	GEditor->RedoTransaction();
}

void FVoxelGraphEditorToolkit::OnStartPreviewPin()
{	
	const FGraphPanelSelectionSet SelectedNodes = VoxelGraphEditor->GetSelectedNodes();
	if (SelectedNodes.Num() == 1)
	{
		for (FGraphPanelSelectionSet::TConstIterator NodeIt(SelectedNodes); NodeIt; ++NodeIt)
		{
			UVoxelGraphNode* GraphNode = Cast<UVoxelGraphNode>(*NodeIt);
			if (GraphNode && GraphNode->VoxelNode)
			{
				VoxelGraphEditor->NotifyGraphChanged();
				if (CurrentPreviewedNode.IsValid())
				{
					CurrentPreviewedNode->VoxelNode->bIsPreviewing = false;
					CurrentPreviewedNode->GetOutputPin(CurrentPreviewedNode->VoxelNode->PreviewPinIndex)->PinType.ContainerType = EPinContainerType::None;
				}
				GraphNode->VoxelNode->bIsPreviewing = true;
				GraphNode->VoxelNode->PreviewPinIndex = GraphNode->VoxelNode->LastPreviewPinIndex;
				GraphNode->GetOutputPin(GraphNode->VoxelNode->PreviewPinIndex)->PinType.ContainerType = EPinContainerType::Array;
				CurrentPreviewedNode = GraphNode;
				UpdatePreview(true);
			}
		}
	}
}

void FVoxelGraphEditorToolkit::OnStopPreviewPin()
{
	const FGraphPanelSelectionSet SelectedNodes = VoxelGraphEditor->GetSelectedNodes();
	if (SelectedNodes.Num() == 1)
	{
		for (FGraphPanelSelectionSet::TConstIterator NodeIt(SelectedNodes); NodeIt; ++NodeIt)
		{
			UVoxelGraphNode* GraphNode = Cast<UVoxelGraphNode>(*NodeIt);
			if (GraphNode && GraphNode->VoxelNode)
			{
				VoxelGraphEditor->NotifyGraphChanged();
				if (CurrentPreviewedNode.IsValid())
				{
					check(CurrentPreviewedNode == GraphNode);
				}
				GraphNode->VoxelNode->bIsPreviewing = false;
				GraphNode->GetOutputPin(GraphNode->VoxelNode->PreviewPinIndex)->PinType.ContainerType = EPinContainerType::None;
				CurrentPreviewedNode = nullptr;
				UpdatePreview(true);
			}
		}
	}
}

void FVoxelGraphEditorToolkit::OnNodeDoubleClicked(UEdGraphNode* Node)
{
	if (Node->CanJumpToDefinition())
	{
		Node->JumpToDefinition();
	}
}

FReply FVoxelGraphEditorToolkit::OnSpawnGraphNodeByShortcut(FInputChord InChord, const FVector2D& InPosition)
{
	auto* Ptr = CastChecked<UVoxelGraphShortcuts>(ShortcutsProperties->GetSelectedObjects()[0])->Shortcuts.FindByPredicate([&](auto& Key) { return Key.IsSameAs(InChord); });
	UClass* ClassToSpawn = Ptr ? Ptr->Class : nullptr;
	if (ClassToSpawn)
	{
		FVoxelGraphSchemaAction_NewNode Action(FText(), FText(), FText(), 0);
		Action.VoxelNodeClass = ClassToSpawn;
		Action.PerformAction(WorldGenerator->GetGraph(), nullptr, InPosition);
	}

	return FReply::Handled();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelGraphEditorToolkit::NotifyPostChange(const FPropertyChangedEvent& PropertyChangedEvent, class UProperty* PropertyThatChanged)
{
	if (VoxelGraphEditor.IsValid() && PropertyChangedEvent.ChangeType != EPropertyChangeType::Interactive)
	{
		VoxelGraphEditor->NotifyGraphChanged();
	}
}

void FVoxelGraphEditorToolkit::CreateInternalWidgets()
{
	VoxelGraphEditor = CreateGraphEditorWidget(false);
	VoxelDebugGraphEditor = CreateGraphEditorWidget(true);

	FDetailsViewArgs Args;
	Args.bHideSelectionTip = true;
	Args.NotifyHook = this;

	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	VoxelProperties = PropertyModule.CreateDetailView(Args);
	VoxelProperties->SetObject(WorldGenerator);

	ShortcutsProperties = PropertyModule.CreateDetailView(Args);
	ShortcutsProperties->SetObject(GetMutableDefault<UVoxelGraphShortcuts>());

	if (!WorldGenerator->PreviewSettings)
	{
		WorldGenerator->PreviewSettings = NewObject<UVoxelGraphPreviewSettings>(WorldGenerator);
		WorldGenerator->PreviewSettings->Graph = WorldGenerator;
	}

	PreviewSettings = PropertyModule.CreateDetailView(Args);
	PreviewSettings->SetObject(WorldGenerator->PreviewSettings);

	Palette = SNew(SVoxelPalette);
	Preview = SNew(SVoxelPreview);
	PreviewViewport = SNew(SVoxelGraphPreviewViewport).VoxelGraphEditorToolkit(SharedThis(this));

	Preview->SetTexture(WorldGenerator->GetPreviewTexture());
}

void FVoxelGraphEditorToolkit::FillToolbar(FToolBarBuilder& ToolbarBuilder)
{
	ToolbarBuilder.BeginSection("Toolbar");
	
	ToolbarBuilder.AddToolBarButton(FVoxelGraphEditorCommands::Get().RecreateNodes);
	if (!WorldGenerator->IsA(UVoxelGraphMacro::StaticClass()))
	{
		ToolbarBuilder.AddToolBarButton(FVoxelGraphEditorCommands::Get().CompileToCpp);
		ToolbarBuilder.AddToolBarButton(FVoxelGraphEditorCommands::Get().ToggleAutomaticPreview);
		ToolbarBuilder.AddToolBarButton(FVoxelGraphEditorCommands::Get().UpdatePreview);
		ToolbarBuilder.AddToolBarButton(FVoxelGraphEditorCommands::Get().ToggleStats);
		ToolbarBuilder.AddToolBarButton(FVoxelGraphEditorCommands::Get().ToggleShowAxisDependencies);
	}

	ToolbarBuilder.EndSection();
}

void FVoxelGraphEditorToolkit::ExtendToolbar()
{
	TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);


	ToolbarExtender->AddToolBarExtension(
		"Asset",
		EExtensionHook::After,
		GetToolkitCommands(),
		FToolBarExtensionDelegate::CreateRaw(this, &FVoxelGraphEditorToolkit::FillToolbar)
	);

	AddToolbarExtender(ToolbarExtender);
}

void FVoxelGraphEditorToolkit::BindGraphCommands()
{
	const FVoxelGraphEditorCommands& Commands = FVoxelGraphEditorCommands::Get();

	ToolkitCommands->MapAction(
		Commands.CompileToCpp,
		FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::CompileToCpp));

	ToolkitCommands->MapAction(
		Commands.RecreateNodes,
		FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::RecreateNodes));
	
	ToolkitCommands->MapAction(
		Commands.ToggleAutomaticPreview,
		FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::ToggleAutomaticPreview),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FVoxelGraphEditorToolkit::IsToggleAutomaticPreviewChecked));

	ToolkitCommands->MapAction(
		Commands.UpdatePreview,
		FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::UpdatePreview, true));
	
	ToolkitCommands->MapAction(
		Commands.ToggleStats,
		FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::ToggleStats),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FVoxelGraphEditorToolkit::IsToggleStatsChecked));
	
	ToolkitCommands->MapAction(
		Commands.ToggleShowAxisDependencies,
		FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::ToggleShowAxisDependencies),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FVoxelGraphEditorToolkit::IsToggleShowAxisDependenciesChecked));

	ToolkitCommands->MapAction(
		FGenericCommands::Get().Undo,
		FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::UndoGraphAction));

	ToolkitCommands->MapAction(
		FGenericCommands::Get().Redo,
		FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::RedoGraphAction));
}

void FVoxelGraphEditorToolkit::AddInput()
{
	const FGraphPanelSelectionSet SelectedNodes = GetSelectedNodes();

	// Iterator used but should only contain one node
	for (FGraphPanelSelectionSet::TConstIterator NodeIt(SelectedNodes); NodeIt; ++NodeIt)
	{
		UVoxelGraphNode* SelectedNode = Cast<UVoxelGraphNode>(*NodeIt);

		if (SelectedNode)
		{
			SelectedNode->AddInputPin();
			break;
		}
	}
}

bool FVoxelGraphEditorToolkit::CanAddInput() const
{
	return GetSelectedNodes().Num() == 1;
}

void FVoxelGraphEditorToolkit::DeleteInput()
{
	UEdGraphPin* SelectedPin = VoxelGraphEditor->GetGraphPinForMenu();

	UVoxelGraphNode* SelectedNode = Cast<UVoxelGraphNode>(SelectedPin->GetOwningNode());

	if (SelectedNode && SelectedNode == SelectedPin->GetOwningNode())
	{
		SelectedNode->RemoveInputPin(SelectedPin);
	}
}

bool FVoxelGraphEditorToolkit::CanDeleteInput() const
{
	return true;
}

void FVoxelGraphEditorToolkit::OnCreateComment()
{
	FVoxelGraphSchemaAction_NewComment CommentAction;
	CommentAction.PerformAction(WorldGenerator->VoxelGraph, NULL, VoxelGraphEditor->GetPasteLocation());
}

TSharedRef<SGraphEditor> FVoxelGraphEditorToolkit::CreateGraphEditorWidget(bool bDebug)
{
	if (!GraphEditorCommands.IsValid())
	{
		GraphEditorCommands = MakeShareable(new FUICommandList);

		GraphEditorCommands->MapAction(FVoxelGraphEditorCommands::Get().AddInput,
			FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::AddInput),
			FCanExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::CanAddInput));

		GraphEditorCommands->MapAction(FVoxelGraphEditorCommands::Get().DeleteInput,
			FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::DeleteInput),
			FCanExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::CanDeleteInput));

		GraphEditorCommands->MapAction(FVoxelGraphEditorCommands::Get().StartPreviewPin,
			FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::OnStartPreviewPin));

		GraphEditorCommands->MapAction(FVoxelGraphEditorCommands::Get().StopPreviewPin,
			FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::OnStopPreviewPin));

		// Graph Editor Commands
		GraphEditorCommands->MapAction(FGraphEditorCommands::Get().CreateComment,
			FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::OnCreateComment)
		);

		// Editing commands
		GraphEditorCommands->MapAction(FGenericCommands::Get().SelectAll,
			FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::SelectAllNodes),
			FCanExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::CanSelectAllNodes)
		);

		GraphEditorCommands->MapAction(FGenericCommands::Get().Delete,
			FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::DeleteSelectedNodes),
			FCanExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::CanDeleteNodes)
		);

		GraphEditorCommands->MapAction(FGenericCommands::Get().Copy,
			FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::CopySelectedNodes),
			FCanExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::CanCopyNodes)
		);

		GraphEditorCommands->MapAction(FGenericCommands::Get().Cut,
			FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::CutSelectedNodes),
			FCanExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::CanCutNodes)
		);

		GraphEditorCommands->MapAction(FGenericCommands::Get().Paste,
			FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::PasteNodes),
			FCanExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::CanPasteNodes)
		);

		GraphEditorCommands->MapAction(FGenericCommands::Get().Duplicate,
			FExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::DuplicateNodes),
			FCanExecuteAction::CreateSP(this, &FVoxelGraphEditorToolkit::CanDuplicateNodes)
		);
	}

	if (bDebug)
	{
		FGraphAppearanceInfo AppearanceInfo;
		AppearanceInfo.CornerText = LOCTEXT("AppearanceCornerText_VoxelDebug", "VOXEL DEBUG");

		return SNew(SGraphEditor)
			.IsEditable(true)
			.Appearance(AppearanceInfo)
			.GraphToEdit(WorldGenerator->VoxelDebugGraph)
			.AutoExpandActionMenu(true)
			.ShowGraphStateOverlay(false);
	}
	else
	{
		FGraphAppearanceInfo AppearanceInfo;
		AppearanceInfo.CornerText = LOCTEXT("AppearanceCornerText_Voxel", "VOXEL");

		SGraphEditor::FGraphEditorEvents InEvents;
		InEvents.OnSelectionChanged = SGraphEditor::FOnSelectionChanged::CreateSP(this, &FVoxelGraphEditorToolkit::OnSelectedNodesChanged);
		InEvents.OnTextCommitted = FOnNodeTextCommitted::CreateSP(this, &FVoxelGraphEditorToolkit::OnNodeTitleCommitted);
		InEvents.OnNodeDoubleClicked = FSingleNodeEvent::CreateSP(this, &FVoxelGraphEditorToolkit::OnNodeDoubleClicked);
		InEvents.OnSpawnNodeByShortcut = SGraphEditor::FOnSpawnNodeByShortcut::CreateSP(this, &FVoxelGraphEditorToolkit::OnSpawnGraphNodeByShortcut);

		return SNew(SGraphEditor)
			.AdditionalCommands(GraphEditorCommands)
			.IsEditable(true)
			.Appearance(AppearanceInfo)
			.GraphToEdit(WorldGenerator->GetGraph())
			.GraphEvents(InEvents)
			.AutoExpandActionMenu(true)
			.ShowGraphStateOverlay(false);
	}
}

#undef LOCTEXT_NAMESPACE
