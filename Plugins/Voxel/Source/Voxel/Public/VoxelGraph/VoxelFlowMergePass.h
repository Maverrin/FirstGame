// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelGraph/VoxelGraphCompilerHelpers.h"

inline void ReplaceFlowMerge(FVoxelGraphCompiler& Compiler, FVoxelCompilationNode* FlowMergeNode)
{
	const FString& Name = FlowMergeNode->GetName();

	auto& ExecOutput = FlowMergeNode->GetOutputPin(0);
	auto& FloatOutput = FlowMergeNode->GetOutputPin(1);
	
	if (ExecOutput.LinkedToNum() == 0)
	{
		Compiler.AddError("Invalid FlowMerge node " + Name + ": exec output not connected!");
		Compiler.AddNodeToSelect(FlowMergeNode);
		Compiler.AddErrorToNode(FlowMergeNode, "exec output not connected");
		return;
	}
	if (FloatOutput.LinkedToNum() == 0)
	{
		Compiler.AddError("Invalid FlowMerge node " + Name + ": float output not connected!");
		Compiler.AddNodeToSelect(FlowMergeNode);
		Compiler.AddErrorToNode(FlowMergeNode, "float output not connected");
		return;
	}

	for (auto& Pin : FlowMergeNode->CreateInputPinsIterator())
	{
		if (Pin->PinCategory == EVoxelPinCategory::Exec && Pin->LinkedToNum() == 0)
		{
			Compiler.AddError("Invalid FlowMerge node " + Name + ": exec input not connected!");
			Compiler.AddNodeToSelect(FlowMergeNode);
		Compiler.AddErrorToNode(FlowMergeNode, "exec input not connected");
			return;
		}
	}

	check(ExecOutput.LinkedToNum() == 1);
	auto* ExecOutputLinkedToNode = ExecOutput.GetLinkedTo()[0]->Node;	
	
	auto& ExecPinA = FlowMergeNode->GetInputPin(0);
	auto& FloatPinA = FlowMergeNode->GetInputPin(1);
	auto& ExecPinB = FlowMergeNode->GetInputPin(2);
	auto& FloatPinB = FlowMergeNode->GetInputPin(3);
	
	auto* PassthroughExecOutput  = FVoxelGraphCompilerHelpers::AddPassthroughOnOutput(Compiler, &ExecOutput);
	auto* PassthroughFloatOutput = FVoxelGraphCompilerHelpers::AddPassthroughOnOutput(Compiler, &FloatOutput);
	auto* PassthroughExecPinA    = FVoxelGraphCompilerHelpers::AddPassthroughOnInput(Compiler, &ExecPinA);
	auto* PassthroughFloatPinA   = FVoxelGraphCompilerHelpers::AddPassthroughOnInput(Compiler, &FloatPinA);
	auto* PassthroughExecPinB    = FVoxelGraphCompilerHelpers::AddPassthroughOnInput(Compiler, &ExecPinB);
	auto* PassthroughFloatPinB   = FVoxelGraphCompilerHelpers::AddPassthroughOnInput(Compiler, &FloatPinB);
	
	check(ExecOutput.LinkedToNum() == 1);
	check(FloatOutput.LinkedToNum() == 1);
	check(ExecPinA.LinkedToNum() == 1);
	check(FloatPinA.LinkedToNum() == 1);
	check(ExecPinB.LinkedToNum() == 1);
	check(FloatPinB.LinkedToNum() == 1);	

	TSet<FVoxelCompilationNode*> NodesToDuplicate;
	FVoxelGraphCompilerHelpers::GetAllSuccessors(FlowMergeNode, NodesToDuplicate);
	NodesToDuplicate.Remove(FlowMergeNode);

	for (auto& Node : NodesToDuplicate)
	{
		FVoxelCompilationNode* FaultyNode = nullptr;
		if (FVoxelGraphCompilerHelpers::IsNodeExecNode(Node) && !FVoxelGraphCompilerHelpers::AreAllNodePredecessorsChildOfStartNodeExecOnly(Node, FlowMergeNode, FaultyNode))
		{
			Compiler.AddError("Invalid FlowMerge node " + Name + ": child " + Node->GetName() + " has a parent that isn't child of this flow merge node: " + FaultyNode->GetName());
			Compiler.AddNodeToSelect(FlowMergeNode);
			Compiler.AddNodeToSelect(Node);
			Compiler.AddNodeToSelect(FaultyNode);
			Compiler.AddErrorToNode(FlowMergeNode, "flow merge", EVoxelGraphNodeErrorType::Info);
			Compiler.AddErrorToNode(Node, "child", EVoxelGraphNodeErrorType::Info);
			Compiler.AddErrorToNode(FaultyNode, "should be child of flow merge", EVoxelGraphNodeErrorType::Error);
			return;
		}
	}

	TMap<FVoxelCompilationPin*, FVoxelCompilationPin*> OldPinsToNewPins;
	FVoxelGraphCompilerHelpers::DuplicateNodesAndLinkThemTogether(Compiler, NodesToDuplicate, OldPinsToNewPins);

	PassthroughExecPinA->GetOutputPin(0).LinkTo(&PassthroughExecOutput->GetInputPin(0));
	PassthroughFloatPinA->GetOutputPin(0).LinkTo(&PassthroughFloatOutput->GetInputPin(0));

	PassthroughExecPinB->GetOutputPin(0).LinkTo(OldPinsToNewPins[&PassthroughExecOutput->GetInputPin(0)]);
	PassthroughFloatPinB->GetOutputPin(0).LinkTo(OldPinsToNewPins[&PassthroughFloatOutput->GetInputPin(0)]);

	FlowMergeNode->BreakAllLinks();
	Compiler.RemoveNode(FlowMergeNode);

	Compiler.Check();
}

struct FVoxelFlowMergePass
{
	static void Apply(FVoxelGraphCompiler& Compiler)
	{
		bool bContinue = true;
		while (bContinue && !Compiler.HasErrors())
		{
			bContinue = false;

			TArray<FVoxelCompilationNode*> SortedNodes;
			FVoxelGraphCompilerHelpers::GetSortedExecNodes(Compiler.FirstNode, SortedNodes);

			for (auto& Node : SortedNodes)
			{
				if (Node->GetType() == EVoxelCompilationNodeType::FlowMerge)
				{
					ReplaceFlowMerge(Compiler, Node);
					bContinue = true;
					break;
				}
				if (Compiler.HasErrors())
				{
					break;
				}
			}
		}

		if (!Compiler.HasErrors())
		{
			TSet<FVoxelCompilationNode*> Nodes;
			FVoxelGraphCompilerHelpers::GetAllUsedNodes(Compiler.FirstNode, Nodes);
			for (auto& Node : Nodes)
			{
				if (Node->GetType() == EVoxelCompilationNodeType::FlowMerge)
				{
					Compiler.AddErrorToNode(Node, "FlowMerge data output is used but exec output isn't connected");
					break;
				}
			}
		}
	}
};

