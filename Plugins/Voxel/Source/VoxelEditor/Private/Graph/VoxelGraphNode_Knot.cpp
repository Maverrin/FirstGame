// Copyright 2018 Phyronnaz

#include "VoxelGraphNode_Knot.h"
#include "EdGraph/EdGraphPin.h"
#include "Runtime/Launch/Resources/Version.h"
#include "VoxelGraph/VoxelNode.h"

#define LOCTEXT_NAMESPACE "VoxelNode_Knot"

#define WILDCARD TEXT("Wildcard")

/////////////////////////////////////////////////////
// VoxelNode_Knot

void UVoxelGraphNode_Knot::AllocateDefaultPins()
{
	check(WILDCARD == FVoxelPinCategory::PC_Wildcard);

	const FString InputPinName(TEXT("InputPin"));
	const FString OutputPinName(TEXT("OutputPin"));

#if ENGINE_MINOR_VERSION < 19
	UEdGraphPin* MyInputPin = CreatePin(EGPD_Input, WILDCARD, FString(), nullptr, InputPinName);
#else
	UEdGraphPin* MyInputPin = CreatePin(EGPD_Input, WILDCARD, FName(), nullptr, FName(*InputPinName));
#endif
	
	MyInputPin->bDefaultValueIsIgnored = true;
	
#if ENGINE_MINOR_VERSION < 19
	UEdGraphPin* MyOutputPin = CreatePin(EGPD_Output, WILDCARD, FString(), nullptr, OutputPinName);
#else
	UEdGraphPin* MyOutputPin = CreatePin(EGPD_Output, WILDCARD, FName(), nullptr, FName(*OutputPinName));
#endif
}

FText UVoxelGraphNode_Knot::GetTooltipText() const
{
	return LOCTEXT("KnotTooltip", "Reroute Node (reroutes wires)");
}

FText UVoxelGraphNode_Knot::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	if (TitleType == ENodeTitleType::EditableTitle)
	{
		return FText::FromString(NodeComment);
	}
	else if (TitleType == ENodeTitleType::MenuTitle)
	{
		return LOCTEXT("KnotListTitle", "Add Reroute Node...");
	}
	else
	{
		return LOCTEXT("KnotTitle", "Reroute Node");
	}
}

bool UVoxelGraphNode_Knot::CanSplitPin(const UEdGraphPin* Pin) const
{
	return false;
}

void UVoxelGraphNode_Knot::PropagatePinType()
{
	UEdGraphPin* MyInputPin  = GetInputPin();
	UEdGraphPin* MyOutputPin = GetOutputPin();

	for (UEdGraphPin* Inputs : MyInputPin->LinkedTo)
	{
		if (Inputs->PinType.PinCategory != WILDCARD)
		{
			PropagatePinTypeFromInput();
			return;
		}
	}

	for (UEdGraphPin* Outputs : MyOutputPin->LinkedTo)
	{
		if (Outputs->PinType.PinCategory != WILDCARD)
		{
			PropagatePinTypeFromOutput();
			return;
		}
	}

	// if all inputs/outputs are wildcards, still favor the inputs first (propagate array/reference/etc. state)
	if (MyInputPin->LinkedTo.Num() > 0)
	{
		// If we can't mirror from output type, we should at least get the type information from the input connection chain
		PropagatePinTypeFromInput();
	}
	else if (MyOutputPin->LinkedTo.Num() > 0)
	{
		// Try to mirror from output first to make sure we get appropriate member references
		PropagatePinTypeFromOutput();
	}
	else
	{
		// Revert to wildcard
		MyInputPin->BreakAllPinLinks();
		MyInputPin->PinType.ResetToDefaults();
		MyInputPin->PinType.PinCategory = WILDCARD;

		MyOutputPin->BreakAllPinLinks();
		MyOutputPin->PinType.ResetToDefaults();
		MyOutputPin->PinType.PinCategory = WILDCARD;
	}
}

TArray<UEdGraphPin*> UVoxelGraphNode_Knot::GetAllInputPins()
{
	TArray<UEdGraphPin*> KnotRecursiveInputPins;
	{
		TArray<UVoxelGraphNode_Knot*> KnotsToProcess;
		KnotsToProcess.Add(this);

		while (KnotsToProcess.Num() > 0)
		{
			auto CurrentKnot = KnotsToProcess.Pop();
			auto InputPin = CurrentKnot->GetInputPin();
			for (auto& Pin : InputPin->LinkedTo)
			{
				auto Knot = Cast<UVoxelGraphNode_Knot>(Pin->GetOwningNode());
				if (Knot)
				{
					KnotsToProcess.Add(Knot);
				}
				else
				{
					KnotRecursiveInputPins.Add(Pin);
				}
			}
		}
	}
	return KnotRecursiveInputPins;
}

TArray<UEdGraphPin*> UVoxelGraphNode_Knot::GetAllOutputPins()
{
	TArray<UEdGraphPin*> KnotRecursiveOutputPins;
	{
		TArray<UVoxelGraphNode_Knot*> KnotsToProcess;
		KnotsToProcess.Add(this);

		while (KnotsToProcess.Num() > 0)
		{
			auto CurrentKnot = KnotsToProcess.Pop();
			auto OutputPin = CurrentKnot->GetOutputPin();
			for (auto& Pin : OutputPin->LinkedTo)
			{
				auto Knot = Cast<UVoxelGraphNode_Knot>(Pin->GetOwningNode());
				if (Knot)
				{
					KnotsToProcess.Add(Knot);
				}
				else
				{
					KnotRecursiveOutputPins.Add(Pin);
				}
			}
		}
	}
	return KnotRecursiveOutputPins;
}

void UVoxelGraphNode_Knot::PropagatePinTypeFromInput()
{
	if (bRecursionGuard)
	{
		return;
	}
	// Set the type of the pin based on input connections.
	// We have to move up the chain of linked reroute nodes until we reach a node
	// with type information before percolating that information down.
	UEdGraphPin* MyInputPin = GetInputPin();
	UEdGraphPin* MyOutputPin = GetOutputPin();

	TGuardValue<bool> RecursionGuard(bRecursionGuard, true);

	for (UEdGraphPin* InPin : MyInputPin->LinkedTo)
	{
		if (UVoxelGraphNode_Knot* KnotNode = Cast<UVoxelGraphNode_Knot>(InPin->GetOwningNode()))
		{
			KnotNode->PropagatePinTypeFromInput();
		}
	}

	UEdGraphPin* TypeSource = MyInputPin->LinkedTo.Num() ? MyInputPin->LinkedTo[0] : nullptr;
	if (TypeSource)
	{
		MyInputPin->PinType = TypeSource->PinType;
		MyOutputPin->PinType = TypeSource->PinType;
	}
}

void UVoxelGraphNode_Knot::PropagatePinTypeFromOutput()
{
	if (bRecursionGuard)
	{
		return;
	}
	// Set the type of the pin based on the output connection, and then percolate
	// that type information up until we no longer reach another Reroute node
	UEdGraphPin* MyInputPin = GetInputPin();
	UEdGraphPin* MyOutputPin = GetOutputPin();

	TGuardValue<bool> RecursionGuard(bRecursionGuard, true);

	for (UEdGraphPin* InPin : MyOutputPin->LinkedTo)
	{
		if (UVoxelGraphNode_Knot* KnotNode = Cast<UVoxelGraphNode_Knot>(InPin->GetOwningNode()))
		{
			KnotNode->PropagatePinTypeFromOutput();
		}
	}

	UEdGraphPin* TypeSource = MyOutputPin->LinkedTo.Num() ? MyOutputPin->LinkedTo[0] : nullptr;
	if (TypeSource)
	{
		MyInputPin->PinType = TypeSource->PinType;
		MyOutputPin->PinType = TypeSource->PinType;
	}
}

bool UVoxelGraphNode_Knot::ShouldOverridePinNames() const
{
	return true;
}

FText UVoxelGraphNode_Knot::GetPinNameOverride(const UEdGraphPin& Pin) const
{
	// Keep the pin size tiny
	return FText::GetEmpty();
}

void UVoxelGraphNode_Knot::OnRenameNode(const FString& NewName)
{
	NodeComment = NewName;
}

UEdGraphPin* UVoxelGraphNode_Knot::GetPassThroughPin(const UEdGraphPin* FromPin) const
{
	if (FromPin && Pins.Contains(FromPin))
	{
		return FromPin == Pins[0] ? Pins[1] : Pins[0];
	}

	return nullptr;
}

#undef LOCTEXT_NAMESPACE
