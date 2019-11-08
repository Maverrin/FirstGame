// Copyright 2018 Phyronnaz

#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelGraph/VoxelExecNodes.h"
#include "VoxelGraph/VoxelGraphMacro.h"
#include "VoxelGraph/VoxelPortalNode.h"
#include "VoxelGraph/VoxelGraphCompilerHelpers.h"

inline void AddPreviousNodesToArrayImpl(FVoxelCompilationNode* Node, TArray<FVoxelCompilationNode*>& Nodes, TSet<FVoxelCompilationNode*>& VisitedNodes)
{
	if (!VisitedNodes.Contains(Node))
	{
		VisitedNodes.Add(Node);

		for (int I = 0; I < Node->GetInputCount(); I++)
		{
			auto& Pin = Node->GetInputPin(I);

			if (Pin.PinCategory != EVoxelPinCategory::Exec)
			{
				for (auto& LinkedToPin : Pin.GetLinkedTo())
				{
					AddPreviousNodesToArrayImpl(LinkedToPin->Node, Nodes, VisitedNodes);
				}
			}
		}
		
		Nodes.Add(Node);
	}
}

inline void AddPreviousNodesToArray(FVoxelCompilationNode* Node, TArray<FVoxelCompilationNode*>& Nodes)
{
	TSet<FVoxelCompilationNode*> VisitedNodes;
	AddPreviousNodesToArrayImpl(Node, Nodes, VisitedNodes);
}

FVoxelCompilationNodeTree::FVoxelCompilationNodeTree(FVoxelCompilationNode* BranchNode)
	: BranchNode(BranchNode)
{
	if (BranchNode)
	{
		AddPreviousNodesToArray(BranchNode, Nodes);

		for (int I = 0; I < BranchNode->GetOutputCount(); I++)
		{
			auto& Pin = BranchNode->GetOutputPin(I);

			if (Pin.PinCategory == EVoxelPinCategory::Exec)
			{
				if (Pin.LinkedToNum() == 0)
				{
					Childs.Emplace(nullptr);
				}
				else
				{
					check(Pin.LinkedToNum() == 1);
					Childs.Emplace(Pin.GetLinkedTo()[0]->Node);
				}
			}
		}
	}
}

void FVoxelCompilationNodeTree::CleanupDependencies(TArray<FVoxelCompilationNodeTree*> Parents)
{
	// Remove all nodes already in parents
	Nodes.RemoveAll([&](FVoxelCompilationNode* Node)
	{
		for (auto& Parent : Parents)
		{
			if (Parent->Nodes.Contains(Node))
			{
				return true;
			}
		}
		return false;
	});

	// Propagate to childs
	Parents.Add(this);
	for (auto& Child : Childs)
	{
		Child.CleanupDependencies(Parents);
	}
}

inline EVoxelAxisDependencies GetDependenciesFromFlag(uint8 Flag)
{
	if (Flag & FVoxelCompilationNode::Z)
	{
		return EVoxelAxisDependencies::XYZ;
	}
	else if (Flag & FVoxelCompilationNode::Y)
	{
		return EVoxelAxisDependencies::XY;
	}
	else if (Flag & FVoxelCompilationNode::X)
	{
		return EVoxelAxisDependencies::X;
	}
	else
	{
		return EVoxelAxisDependencies::Constant;
	}
}

void FVoxelCompilationNodeTree::SetOutputIds(int32 StartId, int32& OutFirstUnusedId)
{
	int32 Id = StartId;
	for (auto& Node : Nodes)
	{
		for (int I = 0; I < Node->GetOutputCount(); I++)
		{
			auto& Pin = Node->GetOutputPin(I);
			if (Pin.PinCategory != EVoxelPinCategory::Exec)
			{
				Node->SetOutputId(I, Id++);
			}
		}
	}
	OutFirstUnusedId = Id;

	for (auto& Child : Childs)
	{
		Child.SetOutputIds(OutFirstUnusedId, OutFirstUnusedId);
	}
}

void FVoxelCompilationNodeTree::SetInputIds()
{
	for (auto& Node : Nodes)
	{
		int PinIndexWithoutExecs = 0;
		for (int I = 0; I < Node->GetInputCount(); I++)
		{
			auto& Pin = Node->GetInputPin(I);
			if (Pin.PinCategory != EVoxelPinCategory::Exec)
			{
				int Id;
				if (Pin.LinkedToNum() == 0)
				{
					Id = -1;
				}
				else
				{
					check(Pin.LinkedToNum() == 1);
					auto& OtherPin = Pin.GetLinkedTo()[0];
					Id = OtherPin->Node->GetOutputId(OtherPin->Index);
				}
				Node->SetInputId(PinIndexWithoutExecs++, Id);
			}
		}
	}

	for (auto& Child : Childs)
	{
		Child.SetInputIds();
	}
}

void FVoxelCompilationNodeTree::ConvertToComputeNodeTree(FVoxelComputeNodeTreesHolder& OutTree)
{
	TMap<FVoxelCompilationNode*, TSharedPtr<FVoxelComputeNode>> AlreadyCreatedNodes;
	ConvertToComputeNodeTreeImpl(&OutTree.ConstantsTree, &OutTree.XTree, &OutTree.XYTree, &OutTree.XYZTree, AlreadyCreatedNodes);
}

void FVoxelCompilationNodeTree::GetLocalVariables(TMap<int, FVoxelLocalVariable>& OutLocalVariables)
{
	TSet<FVoxelCompilationNode*> AlreadyParsedNodes;
	GetLocalVariablesImpl(OutLocalVariables, AlreadyParsedNodes);
}

void FVoxelCompilationNodeTree::ConvertToComputeNodeTreeImpl(FVoxelComputeNodeTree* OutConstantsTree, FVoxelComputeNodeTree* OutXTree, FVoxelComputeNodeTree* OutXYTree, FVoxelComputeNodeTree* OutXYZTree, TMap<FVoxelCompilationNode*, TSharedPtr<FVoxelComputeNode>>& AlreadyCreatedNodes)
{
	for (auto& Node : Nodes)
	{
		TSharedPtr<FVoxelComputeNode>& ComputeNode = AlreadyCreatedNodes.FindOrAdd(Node);

		if (!ComputeNode.IsValid() && Node)
		{
			ComputeNode = Node->GetComputeNode();
		}

		FVoxelComputeNodeTree* Tree = nullptr;
		EVoxelAxisDependencies Dependencies = GetDependenciesFromFlag(Node->Dependencies);
		{
			if (OutConstantsTree && Dependencies <= EVoxelAxisDependencies::Constant)
			{
				Tree = OutConstantsTree;
				Node->FinalDependencies |= EVoxelAxisDependencies::Constant;
			}
			else if (OutXTree && Dependencies <= EVoxelAxisDependencies::X)
			{
				Tree = OutXTree;
				Node->FinalDependencies |= FVoxelCompilationNode::X;
			}
			else if (OutXYTree && Dependencies <= EVoxelAxisDependencies::XY)
			{
				Tree = OutXYTree;
				Node->FinalDependencies |= FVoxelCompilationNode::X | FVoxelCompilationNode::Y;
			}
			else
			{
				check(OutXYZTree && Dependencies <= EVoxelAxisDependencies::XYZ);
				Tree = OutXYZTree;
				Node->FinalDependencies |= FVoxelCompilationNode::X | FVoxelCompilationNode::Y | FVoxelCompilationNode::Z;
			}
		}

		if (BranchNode == Node)
		{
			OutXYZTree->BranchNode = ComputeNode;
			if (Dependencies <= EVoxelAxisDependencies::XY)
			{
				OutXYTree->BranchNode = ComputeNode;
			}
			if (Dependencies <= EVoxelAxisDependencies::X)
			{
				OutXTree->BranchNode = ComputeNode;
			}
			if (Dependencies <= EVoxelAxisDependencies::Constant)
			{
				OutConstantsTree->BranchNode = ComputeNode;
			}
		}
		else
		{
			Tree->Nodes.Add(ComputeNode);
		}
	}

	for (auto& Child : Childs)
	{
		FVoxelComputeNodeTree* NewConstantsTree = nullptr;
		FVoxelComputeNodeTree* NewXTree = nullptr;
		FVoxelComputeNodeTree* NewXYTree = nullptr;
		FVoxelComputeNodeTree* NewXYZTree = nullptr;
		if (OutConstantsTree && OutConstantsTree->BranchNode.IsValid())
		{
			OutConstantsTree->Children.Emplace();
			NewConstantsTree = &OutConstantsTree->Children.Last();
		}
		if (OutXTree && OutXTree->BranchNode.IsValid())
		{
			OutXTree->Children.Emplace();
			NewXTree = &OutXTree->Children.Last();
		}
		if (OutXYTree && OutXYTree->BranchNode.IsValid())
		{
			OutXYTree->Children.Emplace();
			NewXYTree = &OutXYTree->Children.Last();
		}
		check(OutXYZTree->BranchNode.IsValid())
		{
			OutXYZTree->Children.Emplace();
			NewXYZTree = &OutXYZTree->Children.Last();
		}

		Child.ConvertToComputeNodeTreeImpl(NewConstantsTree, NewXTree, NewXYTree, NewXYZTree, AlreadyCreatedNodes);
	}
}

void FVoxelCompilationNodeTree::GetLocalVariablesImpl(TMap<int, FVoxelLocalVariable>& OutLocalVariables, TSet<FVoxelCompilationNode*>& AlreadyParsedNodes)
{	
	for (auto& Node : Nodes)
	{
		if (AlreadyParsedNodes.Contains(Node))
		{
			continue;
		}
		AlreadyParsedNodes.Add(Node);
		for (int I = 0; I < Node->GetOutputCount(); I++)
		{
			auto& Pin = Node->GetOutputPin(I);
			if (Pin.PinCategory != EVoxelPinCategory::Exec)
			{
				int Id = Node->GetOutputId(I);
				OutLocalVariables.Add(Id,  FVoxelLocalVariable(Pin.PinCategory, "LocalVariable_" + FString::FromInt(Id), GetDependenciesFromFlag(Node->FinalDependencies)));
			}
		}
	}

	for (auto& Child : Childs)
	{
		Child.GetLocalVariablesImpl(OutLocalVariables, AlreadyParsedNodes);
	}
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

FVoxelGraphCompiler::FVoxelGraphCompiler(UVoxelGraphGenerator* Graph, const TArray<UVoxelNode*>& InNodes, UVoxelNode* InFirstNode, int32 InFirstNodePinIndex)
	: Graph(Graph)
{
	for (auto& Node : InNodes)
	{
		TSharedPtr<FVoxelCompilationNode> CompilationNode = Node->GetCompilationNode();
		Map.Add(Node, CompilationNode.Get());
		AddNode(CompilationNode);
		RemoveNodeError(Node);
	}
	FirstNode = InFirstNode ? Map.FindChecked(InFirstNode) : nullptr;
	FirstNodePinIndex = InFirstNodePinIndex;

	// Set default values
	for (auto& Node : InNodes)
	{
		FVoxelCompilationNode* CompilationNode = Map.FindChecked(Node);
		for (int I = 0; I < Node->InputPins.Num(); I++)
		{
			CompilationNode->GetInputPin(I).SetDefaultValue(Node->InputPins[I].DefaultValue);
		}
	}

	// Fix links
	for (auto& Node : InNodes)
	{
		FVoxelCompilationNode* CompilationNode = Map.FindChecked(Node);

		for (int PinIndex = 0; PinIndex < Node->InputPins.Num(); PinIndex++)
		{
			auto& NodeInputPin = Node->InputPins[PinIndex];
			auto& CompilationNodeInputPin = CompilationNode->GetInputPin(PinIndex);

			check(NodeInputPin.OtherNodes.Num() == NodeInputPin.OtherPinIds.Num());
			for (int I = 0; I < NodeInputPin.OtherNodes.Num(); I++)
			{
				auto OtherNode = NodeInputPin.OtherNodes[I];
				auto OtherPinId = NodeInputPin.OtherPinIds[I];
				if (!OtherNode)
				{
					AddError("Invalid node, please click Recreate Nodes in this graph & all the macros used in it");
					AddNodeToSelect(CompilationNode);
					return;
				}

				int32 OtherPinIndex = OtherNode->GetOutputPinIndex(OtherPinId);
				check(OtherPinIndex >= 0);

				FVoxelCompilationNode* OtherCompilationNode = Map.FindChecked(OtherNode);
				auto& OtherPin = OtherCompilationNode->GetOutputPin(OtherPinIndex);

				if (!CompilationNodeInputPin.IsLinkedTo(&OtherPin))
				{
					CompilationNodeInputPin.LinkTo(&OtherPin);
				}
			}
		}

		for (int PinIndex = 0; PinIndex < Node->OutputPins.Num(); PinIndex++)
		{
			auto& NodeOutputPin = Node->OutputPins[PinIndex];
			auto& CompilationNodeOutputPin = CompilationNode->GetOutputPin(PinIndex);

			check(NodeOutputPin.OtherNodes.Num() == NodeOutputPin.OtherPinIds.Num());
			for (int I = 0; I < NodeOutputPin.OtherNodes.Num(); I++)
			{
				auto OtherNode = NodeOutputPin.OtherNodes[I];
				auto OtherPinId = NodeOutputPin.OtherPinIds[I];
				if (!OtherNode)
				{
					AddError("Invalid node, please click Recreate Nodes in this graph & all the macros used in it");
					return;
				}

				int32 OtherPinIndex = OtherNode->GetInputPinIndex(OtherPinId);
				check(OtherPinIndex >= 0);

				FVoxelCompilationNode* OtherCompilationNode = Map.FindChecked(OtherNode);
				auto& OtherPin = OtherCompilationNode->GetInputPin(OtherPinIndex);

				if (!CompilationNodeOutputPin.IsLinkedTo(&OtherPin))
				{
					CompilationNodeOutputPin.LinkTo(&OtherPin);
				}
			}
		}
	}

	for (auto& Node : Nodes)
	{
		Node->LogErrors(*this);
	}

	// Check validity
	Check();
}

void FVoxelGraphCompiler::Check() const
{
	if (HasErrors())
	{
		return;
	}
	for (auto& Node : Nodes)
	{
		for (auto& Pin : Node->CreateAllPinsIterator())
		{
			Pin.Check();
			for (auto& LinkedToPin : Pin.GetLinkedTo())
			{
				check(Nodes.Contains(LinkedToPin->Node));
			}
		}
	}
}

void FVoxelGraphCompiler::AddErrorToNode(FVoxelCompilationNode* Node, const FString& Error, EVoxelGraphNodeErrorType Severity, bool bSelectNode)
{
	AddErrorToNode(Node->SourceNode, Error, Severity, bSelectNode);
}

void FVoxelGraphCompiler::AddErrorToNode(const UVoxelNode* Node, const FString& Error, EVoxelGraphNodeErrorType Severity, bool bSelectNode)
{
	if (Severity == EVoxelGraphNodeErrorType::Error)
	{
		bHasErrors = true;
	}

#if WITH_EDITORONLY_DATA
	if (Graph->IsInEditor() && Node && Node->GraphNode)
	{
		auto& GraphNode = Node->GraphNode;

		if (GraphNode->bHasCompilerMessage)
		{
			GraphNode->ErrorMsg += TEXT("\n") + Error;
			GraphNode->ErrorType = int32(Severity);
		}
		else
		{
			GraphNode->ErrorMsg = Error;
			GraphNode->ErrorType = FMath::Min(int32(Severity), GraphNode->ErrorType);
			GraphNode->bHasCompilerMessage = true;
		}
	}
#endif

	if (bSelectNode)
	{
		AddNodeToSelect(Node);
	}
}

void FVoxelGraphCompiler::RefreshNodesErrors()
{
#if WITH_EDITOR
	if (Graph->IsInEditor())
	{
		Graph->GetVoxelGraphEditor()->RefreshNodesError(Graph->VoxelGraph);
	}
#endif
}

void FVoxelGraphCompiler::RemoveNodeError(const UVoxelNode* Node)
{
#if WITH_EDITORONLY_DATA
	if (Node && Node->GraphNode)
	{
		auto& GraphNode = Node->GraphNode;
		GraphNode->ErrorMsg.Empty();
		GraphNode->ErrorType = int32(EVoxelGraphNodeErrorType::None);
		GraphNode->bHasCompilerMessage = false;
	}
#endif
}

void FVoxelGraphCompiler::AddNodeToSelect(FVoxelCompilationNode* Node)
{
	AddNodeToSelect(Node->SourceNode);
}

void FVoxelGraphCompiler::AddNodeToSelect(const UVoxelNode* Node)
{
#if WITH_EDITORONLY_DATA
	if (Node && Node->GraphNode)
	{
		NodesToSelect.Add(Node->GraphNode);
	}
#endif
}

bool FVoxelGraphCompiler::Compile(FVoxelComputeNodeTreesHolder& OutTree, int32& OutMaxId, TMap<int, FVoxelLocalVariable>& OutLocalVariables, FString& OutError)
{
	if (HasErrors())
	{
		if (!Errors.IsEmpty())
		{
			OutError.Append(Errors);
		}
		return false;
	}

	check(FirstNode);

#if WITH_EDITOR
	// Add the perf counters
	if (Graph->bEnableStats)
	{
		auto GraphNodesSet = TSet<const UVoxelNode*>();
		for (auto& Node : Graph->AllNodes)
		{
			GraphNodesSet.Add(Node);
		}
		auto& PerfMap = FVoxelGraphPerfCounter::GetSingletonMap();
		for (auto& It : PerfMap)
		{
			auto* Node = It.Key;
			auto& Perf = It.Value;
			if (GraphNodesSet.Contains(Node))
			{
				AddErrorToNode(Node, TEXT("C: ") + FString::FromInt(Perf.NumCalls), EVoxelGraphNodeErrorType::Info, false);
				AddErrorToNode(Node, TEXT("T: ") + FString::SanitizeFloat(double(Perf.NumCycles) / double(Perf.NumCalls) * FPlatformTime::GetSecondsPerCycle64() * 1000000) + TEXT("\u00B5s"), EVoxelGraphNodeErrorType::Info, false);
			}
		}
	}
#endif
	RefreshNodesErrors();
#if WITH_EDITOR
	if (NodesToSelect.Num() > 0 && Graph->IsInEditor())
	{
		Graph->GetVoxelGraphEditor()->SelectNodesAndZoomToFit(Graph->VoxelGraph, NodesToSelect);
	}
#endif

	Check();

	if (HasErrors())
	{
		if (!Errors.IsEmpty())
		{
			OutError.Append(Errors);
		}
		return false;
	}

	TSharedPtr<FVoxelCompilationNodeTree> MainTree = MakeShared<FVoxelCompilationNodeTree>(FirstNode);
	MainTree->CleanupDependencies();
	
	OutMaxId = 0;
	MainTree->SetOutputIds(0, OutMaxId);
	MainTree->SetInputIds();

	MainTree->ConvertToComputeNodeTree(OutTree);
	MainTree->GetLocalVariables(OutLocalVariables);

	return true;
}

void FVoxelGraphCompiler::SetPreviewedNode(UVoxelNode* Node)
{
	check(Node->bIsPreviewing);
	check(Node->PreviewPinIndex >= 0);

	FVoxelCompilationNode* CompileNode = Map.FindChecked(Node);
	int PinIndex = Node->PreviewPinIndex;
	while (CompileNode->GetType() == EVoxelCompilationNodeType::Macro)
	{
		auto* MacroNode = static_cast<FVoxelMacroCompilationNode*>(CompileNode);
		auto* NewPin = MacroNode->NewOutputPins[PinIndex];
		PinIndex = NewPin->Index;
		CompileNode = NewPin->Node;
	}

	if (CompileNode->GetType() == EVoxelCompilationNodeType::PortalOutput)
	{
		check(PinIndex == 0);
		auto* PortalNode = static_cast<FVoxelPortalOutputCompilationNode*>(CompileNode);
		CompileNode = PortalNode->Passthrough;
		if (!CompileNode)
		{
			AddError("Invalid local variable!");
			return;
		}
	}

	TSet<FVoxelCompilationNode*> TmpNodes;
	FVoxelGraphCompilerHelpers::GetAllUsedNodes(CompileNode, TmpNodes);
	for (auto& TmpNode : TmpNodes)
	{
		if (TmpNode->GetType() == EVoxelCompilationNodeType::FlowMerge)
		{
			AddError("Can't preview a FlowMerge node!");
			return;
		}
	}

	TSharedPtr<FVoxelCompilationNode> SetValueNode = MakeShared<FVoxelPreviewSetValueCompilationNode>(CompileNode, PinIndex);
	AddNode(SetValueNode);

	FirstNode = SetValueNode.Get();
}

