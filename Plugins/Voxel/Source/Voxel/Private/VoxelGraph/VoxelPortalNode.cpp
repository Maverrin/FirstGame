// Copyright 2018 Phyronnaz

#include "VoxelGraph/VoxelPortalNode.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelGraph/VoxelCompilationNode.h"
#include "VoxelGraph/VoxelGraphCompilerHelpers.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"

#if WITH_EDITOR

void UVoxelPortalNodeInput::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property)
	{
		if (GraphNode)
		{
			GraphNode->ReconstructNode();
		}
		for (auto& Node : OutputNodes)
		{
			if (Node.IsValid())
			{
				Node->RecreateNodeAndBreakAllLinks();
			}
		}
		if(Graph)
		{
			Graph->CompileVoxelNodesFromGraphNodes();
		}
	}
}

void UVoxelPortalNodeOutput::RecreateNodeAndBreakAllLinks()
{
	if (GraphNode)
	{
		GraphNode->Pins.Empty();
		GraphNode->ReconstructNode();
	}
}

void UVoxelPortalNodeOutput::PostLoad()
{
	Super::PostLoad();

	if (Selector.Input.IsValid())
	{
		auto* Input = Selector.Input.Get();
		TWeakObjectPtr<UVoxelPortalNodeOutput> ThisPtr(this);
		if (!Input->OutputNodes.Contains(ThisPtr))
		{
			Input->OutputNodes.Add(ThisPtr);
		}
	}
}

void UVoxelPortalNodeOutput::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property && Graph)
	{
		Graph->CompileVoxelNodesFromGraphNodes();
	}
}

#endif

void FReplaceVoxelPortalNodesPass::Apply(FVoxelGraphCompiler& Compiler)
{
	TMap<const UVoxelNode*, FVoxelCompilationNode*> Passthroughs;
	TArray<const UVoxelPortalNodeInput*> Inputs;
	TArray<FVoxelCompilationNode*> AllPortalNodes;
	auto AllNodes = Compiler.GetAllNodes(); // Need copy as we are modifying it
	for (auto& CompilationNode : AllNodes)
	{
		auto* VoxelNode = CompilationNode->GetNode();
		if (auto* InputNode = Cast<UVoxelPortalNodeInput>(VoxelNode))
		{
			Inputs.Add(InputNode);
			if (auto** InputCompilationNode = Compiler.Map.Find(InputNode))
			{
				AllPortalNodes.Add(*InputCompilationNode);
				auto* Passthrough = FVoxelGraphCompilerHelpers::AddPassthroughOnInput(Compiler, &(*InputCompilationNode)->GetInputPin(0));
				Passthroughs.Add(VoxelNode, Passthrough);
			}
		}
		else if(auto* OutputNode = Cast<UVoxelPortalNodeOutput>(VoxelNode))
		{
			if (auto** OutputCompilationNode = Compiler.Map.Find(OutputNode))
			{
				AllPortalNodes.Add(*OutputCompilationNode);
				auto* Passthrough = FVoxelGraphCompilerHelpers::AddPassthroughOnOutput(Compiler, &(*OutputCompilationNode)->GetOutputPin(0));
				Passthroughs.Add(VoxelNode, Passthrough);
				check((*OutputCompilationNode)->GetType() == EVoxelCompilationNodeType::PortalOutput);
				static_cast<FVoxelPortalOutputCompilationNode*>(*OutputCompilationNode)->Passthrough = Passthrough;

				auto& SelectorInputNode = OutputNode->Selector.Input;
				if (!SelectorInputNode.IsValid() || !OutputNode->Graph->AllNodes.Contains(SelectorInputNode.Get()))
				{
					Compiler.AddErrorToNode(*OutputCompilationNode, "invalid input", EVoxelGraphNodeErrorType::Warning);
				}
			}
		}
	}

	for (auto& Input : Inputs)
	{
		if (auto* InputPassthrough = Passthroughs.Find(Input))
		{
			for (auto& Output : Input->OutputNodes)
			{
				if (Output.IsValid())
				{
					if (auto* OutputPassthrough = Passthroughs.Find(Output.Get()))
					{
						(*InputPassthrough)->GetOutputPin(0).LinkTo(&(*OutputPassthrough)->GetInputPin(0));
					}
				}
			}
		}
	}

	for (auto& Node : AllPortalNodes)
	{
		Node->BreakAllLinks();
		Compiler.RemoveNode(Node);
	}
}

