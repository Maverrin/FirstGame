// Copyright 2018 Phyronnaz

#include "VoxelGraph.h"
#include "EdGraph/EdGraphPin.h"
#include "ScopedTransaction.h"
#include "Engine/Font.h"
#include "Editor/EditorEngine.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "VoxelGraphSchema.h"
#include "VoxelGraphEditorToolkit.h"
#include "EdGraph/EdGraphNode.h"
#include "Framework/Commands/GenericCommands.h"
#include "VoxelGraph/VoxelNode.h"
#include "VoxelGraphNode.h"
#include "VoxelGraphNode_Root.h"
#include "VoxelGraphNode_Knot.h"
#include "Runtime/Launch/Resources/Version.h"
#include "VoxelGraph/VoxelGraphMacro.h"
#include "VoxelGraphEditorUtilities.h"
#include "Graph/SVoxelGraphNode.h"

UVoxelGraph::UVoxelGraph(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	if (!UVoxelGraphGenerator::GetVoxelGraphEditor().IsValid())
	{
		UVoxelGraphGenerator::SetVoxelGraphEditor(TSharedPtr<IVoxelGraphEditor>(new FVoxelGraphEditor()));
	}
}

/////////////////////////////////////////////////////////////////////////

UEdGraph* FVoxelGraphEditor::CreateNewVoxelGraph(UVoxelGraphGenerator* InWorldGenerator)
{
	UVoxelGraph* VoxelGraph = CastChecked<UVoxelGraph>(FBlueprintEditorUtils::CreateNewGraph(InWorldGenerator, NAME_None, UVoxelGraph::StaticClass(), UVoxelGraphSchema::StaticClass()));

	return VoxelGraph;
}

void FVoxelGraphEditor::SetupVoxelNode(UEdGraph* VoxelGraph, UVoxelNode* InVoxelNode, bool bSelectNewNode)
{
	FGraphNodeCreator<UVoxelGraphNode> NodeCreator(*VoxelGraph);
	UVoxelGraphNode* GraphNode = NodeCreator.CreateNode(bSelectNewNode);
	InVoxelNode->GraphNode = GraphNode;
	GraphNode->SetVoxelNode(InVoxelNode);
	NodeCreator.Finalize();
}

inline FVoxelPin CreateVoxelPinFromGraphPin(UEdGraphPin* Pin)
{
	TArray<UVoxelNode*> OtherNodes;
	TArray<FGuid> OtherPinIds;

	if (Pin->LinkedTo.Num() > 0)
	{
		for (UEdGraphPin* OtherPin : Pin->LinkedTo)
		{
			auto Knot = Cast<UVoxelGraphNode_Knot>(OtherPin->GetOwningNode());
			if (Knot)
			{
				auto NewOtherPins = Pin->Direction == EEdGraphPinDirection::EGPD_Input ? Knot->GetAllInputPins() : Knot->GetAllOutputPins();
				for(auto& NewOtherPin : NewOtherPins)
				{
					auto NewOtherNode = Cast<UVoxelGraphNode>(NewOtherPin->GetOwningNode());
					if (NewOtherNode)
					{
						OtherNodes.Add(NewOtherNode->VoxelNode);
						OtherPinIds.Add(NewOtherPin->PinId);
					}
				}
			}
			else
			{
				auto OtherNode = Cast<UVoxelGraphNode>(OtherPin->GetOwningNode());
				if (OtherNode)
				{
					OtherNodes.Add(OtherNode->VoxelNode);
					OtherPinIds.Add(OtherPin->PinId);
				}
			}
		}
	}

	return FVoxelPin(Pin->PinId, Pin->DefaultValue, FVoxelPinCategory::FromString(Pin->PinType.PinCategory), OtherNodes, OtherPinIds);
}

void FVoxelGraphEditor::CompileVoxelNodesFromGraphNodes(UVoxelGraphGenerator* WorldGenerator)
{
	WorldGenerator->Modify();
	{
		WorldGenerator->FirstNode = nullptr;
		WorldGenerator->AllNodes.Empty();

		TArray<UVoxelNode*> AllNodes;
		for (auto& Node : WorldGenerator->VoxelGraph->Nodes)
		{
			UVoxelGraphNode* GraphNode = Cast<UVoxelGraphNode>(Node);
			if (GraphNode && GraphNode->VoxelNode)
			{
				UVoxelNode* VoxelNode = GraphNode->VoxelNode;
				check(VoxelNode);

				check(!AllNodes.Contains(VoxelNode));
				AllNodes.Add(VoxelNode);

				TArray<FVoxelPin> InputVoxelPins;
				{
					TArray<UEdGraphPin*> InputPins;
					GraphNode->GetInputPins(InputPins);
					for (auto& InputPin : InputPins)
					{
						InputVoxelPins.Add(CreateVoxelPinFromGraphPin(InputPin));
					}
				}

				TArray<FVoxelPin> OutputVoxelPins;
				{
					TArray<UEdGraphPin*> OutputPins;
					GraphNode->GetOutputPins(OutputPins);
					for (auto& OutputPin : OutputPins)
					{
						OutputVoxelPins.Add(CreateVoxelPinFromGraphPin(OutputPin));
					}
				}

				VoxelNode->SetFlags(RF_Transactional);
				VoxelNode->Modify();
				VoxelNode->InputPins = InputVoxelPins;
				VoxelNode->OutputPins = OutputVoxelPins;
				VoxelNode->PostEditChange();
			}
			else
			{
				UVoxelGraphNode_Root* GraphNodeRoot = Cast<UVoxelGraphNode_Root>(Node);
				if (GraphNodeRoot)
				{
					TArray<UEdGraphPin*> OutputPins;
					GraphNodeRoot->GetOutputPins(OutputPins);

					check(OutputPins.Num() == 1);
					check(OutputPins[0]->LinkedTo.Num() <= 1);
					if (OutputPins[0]->LinkedTo.Num() == 1)
					{
						UEdGraphPin* OtherPin = OutputPins[0]->LinkedTo[0];

						auto Knot = Cast<UVoxelGraphNode_Knot>(OtherPin->GetOwningNode());

						if (Knot)
						{
							auto NewOtherPins = Knot->GetAllOutputPins();
							if (NewOtherPins.Num() > 0)
							{
								check(NewOtherPins.Num() == 1);
								auto NewOtherPin = NewOtherPins[0];
								WorldGenerator->FirstNode = CastChecked<UVoxelGraphNode>(NewOtherPin->GetOwningNode())->VoxelNode;
								WorldGenerator->FirstNodePindId = NewOtherPin->PinId;
							}
						}
						else
						{
							WorldGenerator->FirstNode = CastChecked<UVoxelGraphNode>(OtherPin->GetOwningNode())->VoxelNode;
							WorldGenerator->FirstNodePindId = OtherPin->PinId;
						}
					}
				}
			}
		}

		WorldGenerator->AllNodes = AllNodes;
	}
	WorldGenerator->PostEditChange();

	UpdatePreview(WorldGenerator, false, true);
}

void FVoxelGraphEditor::UpdatePreview(UVoxelGraphGenerator* WorldGenerator, bool bForce, bool bUpdateTextures)
{
	auto Editor = FVoxelGraphEditorUtilities::GetIVoxelEditorForObject(WorldGenerator->VoxelGraph);
	Editor->TriggerUpdatePreview(bForce, bUpdateTextures);
}

void FVoxelGraphEditor::CreateInputPin(UEdGraphNode* VoxelNode)
{
	CastChecked<UVoxelGraphNode>(VoxelNode)->CreateInputPin();
}

void FVoxelGraphEditor::CreateOutputPin(UEdGraphNode* VoxelNode)
{
	CastChecked<UVoxelGraphNode>(VoxelNode)->CreateOutputPin();
}

void FVoxelGraphEditor::SelectNodesAndZoomToFit(UEdGraph* Graph, TArray<UEdGraphNode*>& Nodes)
{	
	TSharedPtr<class IVoxelGraphEditorToolkit> VoxelEditor = FVoxelGraphEditorUtilities::GetIVoxelEditorForObject(Graph);
	VoxelEditor->SelectNodesAndZoomToFit(Nodes);
}

UVoxelGraphGenerator* FVoxelGraphEditor::GetWorldGeneratorFromGraph(UEdGraph* Graph)
{
	if (UVoxelGraph* VoxelGraph = Cast<UVoxelGraph>(Graph))
	{
		return VoxelGraph->GetWorldGenerator();
	}
	else
	{
		return nullptr;
	}
}

void FVoxelGraphEditor::SetDebugGraph(UEdGraph* DebugGraph, FVoxelGraphCompiler* Compiler)
{
	TSharedPtr<class IVoxelGraphEditorToolkit> VoxelEditor = FVoxelGraphEditorUtilities::GetIVoxelEditorForObject(DebugGraph);
	if (VoxelEditor.IsValid())
	{
		VoxelEditor->SetDebugGraph(Compiler);
	}
}

void FVoxelGraphEditor::RefreshNodesError(UEdGraph* Graph)
{
	for (const UEdGraphNode* Node : Graph->Nodes)
	{
		if (Node)
		{
			TSharedPtr<SGraphNode> Widget = Node->DEPRECATED_NodeWidget.Pin();
			if (Widget.IsValid())
			{
				static_cast<SVoxelGraphNode*>(Widget.Get())->RefreshErrorInfo();
			}
		}
	}
}

