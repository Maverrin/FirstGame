// Copyright 2018 Phyronnaz

#include "VoxelGraph/VoxelGraphMacro.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelGraph/VoxelGraphCompilerHelpers.h"

inline bool ArePinsArraysSameNameAndCategory(const TArray<FVoxelPin>& A, const TArray<FVoxelPin>& B)
{
	if (A.Num() != B.Num())
	{
		return false;
	}
	for (int Index = 0; Index < A.Num(); Index++)
	{
		if (A[Index].PinCategory != B[Index].PinCategory)
		{
			return false;
		}
	}
	return true;
}

void FVoxelMacroCompilationNode::LogErrors(FVoxelGraphCompiler& Compiler)
{
	const UVoxelGraphMacroNode* const MacroNode = CastChecked<const UVoxelGraphMacroNode>(GetNode());
	UVoxelGraphMacro* const Macro = MacroNode->Macro;

	if (!Macro)
	{
		if (MacroNode->InputPins.Num() != 0 || MacroNode->OutputPins.Num() != 0)
		{
			Compiler.AddError("Macro node without ref in: \n\t" + MacroNode->Graph->GetName() + "\n\nPlease reassign the macro ref in the node detail panel");
			Compiler.AddErrorToNode(MacroNode, "invalid macro ref", EVoxelGraphNodeErrorType::Error);
		}
	}
	else if (!ArePinsArraysSameNameAndCategory(MacroNode->InputPins, Macro->InputNode->OutputPins) || !ArePinsArraysSameNameAndCategory(MacroNode->OutputPins, Macro->OutputNode->InputPins))
	{
		Compiler.AddError("Outdated macro: \n\t" + Macro->GetName() + "\n in: \n\t" + MacroNode->Graph->GetName() + "\n\nPlease press Recreate Nodes in the voxel graph editor toolbar");
		Compiler.AddErrorToNode(MacroNode, "outdated macro", EVoxelGraphNodeErrorType::Error);
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#if WITH_EDITOR
void UVoxelGraphMacroInputOutputNode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	InputPinCount = GetMinInputPins();

	if (GraphNode && PropertyChangedEvent.Property && (PropertyChangedEvent.Property->GetNameCPP() == "Pins" || PropertyChangedEvent.Property->GetNameCPP() == "Name" || PropertyChangedEvent.Property->GetNameCPP() == "Category"))
	{
		GraphNode->ReconstructNode();
		if (Graph)
		{
			Graph->CompileVoxelNodesFromGraphNodes();
		}
	}
}
#endif // WITH_EDITOR

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#if WITH_EDITOR
void UVoxelGraphMacroNode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	InputPinCount = GetMinInputPins();
}
#endif // WITH_EDITOR

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

inline void ReplaceMacro(FVoxelGraphCompiler& Compiler, FVoxelMacroCompilationNode* MacroCompilationNode)
{	
	const UVoxelGraphMacroNode* const MacroNode = CastChecked<const UVoxelGraphMacroNode>(MacroCompilationNode->GetNode());
	UVoxelGraphMacro* const Macro = MacroNode->Macro;
	
	const FString& Prefix = MacroCompilationNode->GetName() + "(" + Macro->GetName() + ")_";

	check(Macro);
	check(Macro->InputNode && Macro->OutputNode);
	check(MacroNode->InputPins.Num() == Macro->InputNode->OutputPins.Num() && MacroNode->OutputPins.Num() == Macro->OutputNode->InputPins.Num());

	static TSet<const UVoxelGraphMacroNode*> StackMacros;

	if (StackMacros.Contains(MacroNode))
	{
		FString Error;
		Error += "Recursive macros detected! Macros in stack: ";
		bool bFirst = true;
		for (auto& StackMacro : StackMacros)
		{
			if (bFirst)
			{
				bFirst = false;
			}
			else
			{
				Error += ", ";
			}
			Error += StackMacro->Macro->GetName();
		}
		Compiler.AddError(Error);
		Compiler.AddNodeToSelect(MacroCompilationNode);
		Compiler.AddErrorToNode(MacroCompilationNode, "recursive macros detected");
		return;
	}
	
	StackMacros.Add(MacroNode);	
	{
		TArray<FVoxelCompilationNode*> InputPassthroughs;

		// Merge macro nodes
		{
			Macro->CleanAllNodes();
			FVoxelGraphCompiler LocalCompiler(nullptr, Macro->AllNodes, nullptr);
			for (auto& Node : LocalCompiler.GetAllNodes())
			{
				Node->AddPrefixToName(Prefix);
				Node->SourceNode = MacroCompilationNode->SourceNode;
			}
			LocalCompiler.ApplyPass<FVoxelGraphInlineMacrosPass>(); // Apply pass AFTER rename/SourceNode
			Compiler.Merge(LocalCompiler);
		}
		if (Compiler.HasErrors())
		{
			StackMacros.Remove(MacroNode);
			return;
		}

		FVoxelCompilationNode* const InputNode = Compiler.Map.FindChecked(Macro->InputNode);
		FVoxelCompilationNode* const OutputNode = Compiler.Map.FindChecked(Macro->OutputNode);
	
		// Link inputs
		for (int PinIndex = 0; PinIndex < MacroCompilationNode->GetInputCount(); PinIndex++)
		{
			auto& MacroInputPin = MacroCompilationNode->GetInputPin(PinIndex);
			auto& MacroInputNodeOutputPin = InputNode->GetOutputPin(PinIndex);

			auto* PassthroughNode = FVoxelGraphCompilerHelpers::AddPassthroughOnOutput(Compiler, &MacroInputNodeOutputPin, MacroCompilationNode);
			PassthroughNode->AddPrefixToName(Prefix);
			PassthroughNode->SourceNode = MacroCompilationNode->SourceNode;
			auto& PassthroughInputPin = PassthroughNode->GetInputPin(0);
			
			PassthroughInputPin.BreakLinkTo(&MacroInputNodeOutputPin);
			PassthroughInputPin.SetDefaultValue(MacroInputPin.GetDefaultValue());

			auto LinkedTo = MacroInputPin.GetLinkedTo(); // Copy as we are modifying it
			for (auto& PinConnectedToMacroInputPin : LinkedTo)
			{
				MacroInputPin.BreakLinkTo(PinConnectedToMacroInputPin);
				PassthroughInputPin.LinkTo(PinConnectedToMacroInputPin);
			}
		
			InputPassthroughs.Add(PassthroughNode);
			MacroCompilationNode->NewInputPins.Add(&PassthroughInputPin);
		}

		// Link outputs
		for (int PinIndex = 0; PinIndex < MacroCompilationNode->GetOutputCount(); PinIndex++)
		{
			auto& MacroOutputPin = MacroCompilationNode->GetOutputPin(PinIndex);
			auto& MacroOutputNodeInputPin = OutputNode->GetInputPin(PinIndex);

			auto* PassthroughNode = FVoxelGraphCompilerHelpers::AddPassthroughOnInput(Compiler, &MacroOutputNodeInputPin, MacroCompilationNode);
			PassthroughNode->AddPrefixToName(Prefix);
			auto& PassthroughOutputPin = PassthroughNode->GetOutputPin(0);
			
			PassthroughOutputPin.BreakLinkTo(&MacroOutputNodeInputPin);
			
			auto LinkedTo = MacroOutputPin.GetLinkedTo(); // Copy as we are modifying it
			for (auto& PinConnectedToMacroOutputPin : LinkedTo)
			{
				MacroOutputPin.BreakLinkTo(PinConnectedToMacroOutputPin);
				PassthroughOutputPin.LinkTo(PinConnectedToMacroOutputPin);
			}
		
			MacroCompilationNode->NewOutputPins.Add(&PassthroughOutputPin);
		}

		Compiler.RemoveNode(MacroCompilationNode);
		Compiler.RemoveNode(InputNode);
		Compiler.RemoveNode(OutputNode);

		if (Compiler.FirstNode == MacroCompilationNode)
		{
			Compiler.FirstNode = InputPassthroughs[Compiler.FirstNodePinIndex];
			Compiler.FirstNodePinIndex = 0; // Always 1 input on a passthrough
			check(Compiler.FirstNode->GetInputPin(0).PinCategory == EVoxelPinCategory::Exec);
		}
	}
	StackMacros.Remove(MacroNode);
}

void FVoxelGraphInlineMacrosPass::Apply(FVoxelGraphCompiler& Compiler)
{
	bool bContinue = true;
	while (bContinue && !Compiler.HasErrors())
	{
		bContinue = false;
		for (auto& Node : Compiler.GetAllNodes())
		{
			if (Node->GetType() == EVoxelCompilationNodeType::Macro)
			{
				auto* MacroNode = static_cast<FVoxelMacroCompilationNode*>(Node);
				ReplaceMacro(Compiler, MacroNode);
				bContinue = true;
				break;
			}
			if (Compiler.HasErrors())
			{
				break;
			}
		}
	}
}

