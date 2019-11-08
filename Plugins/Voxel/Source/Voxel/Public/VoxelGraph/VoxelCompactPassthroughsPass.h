// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelGraph/VoxelGraphCompilerHelpers.h"

inline bool RemovePassthroughIfPossible(FVoxelGraphCompiler& Compiler, FVoxelCompilationNode* PassthroughNode)
{
	if (PassthroughNode == Compiler.FirstNode)
	{
		return false;
	}

	auto& InputPin = PassthroughNode->GetInputPin(0);
	auto& OutputPin = PassthroughNode->GetOutputPin(0);
	auto Category = InputPin.PinCategory;
	check(Category == OutputPin.PinCategory);

	if (InputPin.LinkedToNum() == 0)
	{
		if (Category != EVoxelPinCategory::Exec)
		{
			for (auto& LinkedToPin : OutputPin.GetLinkedTo())
			{
				LinkedToPin->SetDefaultValue(InputPin.GetDefaultValue());
			}
		}

		PassthroughNode->BreakAllLinks();
		Compiler.RemoveNode(PassthroughNode);
		return true;
	}
	else if (OutputPin.LinkedToNum() > 0)
	{
		if (InputPin.PinCategory == EVoxelPinCategory::Exec)
		{
			check(OutputPin.LinkedToNum() == 1);
			auto& PinLinkedToOutputPin = OutputPin.GetLinkedTo()[0];

			for (auto& PinLinkedToInputPin : InputPin.GetLinkedTo())
			{
				if (!PinLinkedToInputPin->IsLinkedTo(PinLinkedToOutputPin))
				{
					PinLinkedToInputPin->LinkTo(PinLinkedToOutputPin);
				}
			}
		}
		else
		{
			check(InputPin.LinkedToNum() == 1);
			auto& PinLinkedToInputPin = InputPin.GetLinkedTo()[0];

			for (auto& PinLinkedToOutputPin : OutputPin.GetLinkedTo())
			{
				if (!PinLinkedToOutputPin->IsLinkedTo(PinLinkedToInputPin))
				{
					PinLinkedToOutputPin->LinkTo(PinLinkedToInputPin);
				}
			}
		}

		PassthroughNode->BreakAllLinks();
		Compiler.RemoveNode(PassthroughNode);
		return true;
	}
	else
	{
		return false;
	}
}

struct FVoxelCompactPassthroughsPass
{
	static void Apply(FVoxelGraphCompiler& Compiler)
	{
		bool bContinue = true;
		while (bContinue && !Compiler.HasErrors())
		{
			bContinue = false;
			for (auto& Node : Compiler.GetAllNodes())
			{
				if (Node->GetType() == EVoxelCompilationNodeType::Passthrough && RemovePassthroughIfPossible(Compiler, Node))
				{
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
};

