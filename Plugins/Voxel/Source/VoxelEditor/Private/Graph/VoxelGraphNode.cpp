// Copyright 2018 Phyronnaz

#include "VoxelGraphNode.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraph/EdGraphNode.h"
#include "ScopedTransaction.h"
#include "Engine/Font.h"
#include "Editor/EditorEngine.h"
#include "Framework/Commands/GenericCommands.h"

#include "VoxelGraph.h"
#include "VoxelGraphEditorToolkit.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Runtime/Launch/Resources/Version.h"
#include "VoxelGraph/VoxelGraphMacro.h"
#include "Toolkits/AssetEditorManager.h"


void UVoxelGraphNode::SetVoxelNode(UVoxelNode* InNode)
{
	VoxelNode = InNode;
}

void UVoxelGraphNode::PostCopyNode()
{
	// Make sure the VoxelNode goes back to being owned by the WorldGenerator after copying.
	ResetVoxelNodeOwner();
}

void UVoxelGraphNode::CreateInputPin()
{
	int PinIndex = GetInputCount();

#if ENGINE_MINOR_VERSION < 19
		UEdGraphPin* NewPin = CreatePin(EGPD_Input, FVoxelPinCategory::ToString(VoxelNode->GetInputPinCategory(PinIndex)), FString(), nullptr, VoxelNode->GetInputPinName(PinIndex).ToString());
#else
		UEdGraphPin* NewPin = CreatePin(EGPD_Input, FName(*FVoxelPinCategory::ToString(VoxelNode->GetInputPinCategory(PinIndex))), FName(), nullptr, FName(*VoxelNode->GetInputPinName(PinIndex).ToString()));
#endif	

#if ENGINE_MINOR_VERSION < 19
	if (NewPin->PinName.IsEmpty())
#else
	if (NewPin->PinName.ToString().IsEmpty())
#endif
	{
		// Makes sure pin has a name for lookup purposes but user will never see it
		NewPin->PinName = CreateUniquePinName(TEXT("Input"));
		NewPin->PinFriendlyName = FText::FromString(TEXT(" "));
	}

	NewPin->DefaultValue = VoxelNode->GetInputPinDefaultValue(PinIndex);
	if (NewPin->DefaultValue.IsEmpty())
	{
		NewPin->DefaultValue = FVoxelPinCategory::GetDefaultValueForCategory(VoxelNode->GetInputPinCategory(PinIndex));
	}
}

void UVoxelGraphNode::CreateOutputPin()
{
	int PinIndex = GetOutputCount();

#if ENGINE_MINOR_VERSION < 19
		UEdGraphPin* NewPin = CreatePin(EGPD_Output, FVoxelPinCategory::ToString(VoxelNode->GetOutputPinCategory(PinIndex)), FString(), nullptr, VoxelNode->GetOutputPinName(PinIndex).ToString());
#else
		UEdGraphPin* NewPin = CreatePin(EGPD_Output, FName(*FVoxelPinCategory::ToString(VoxelNode->GetOutputPinCategory(PinIndex))), FName(), nullptr, FName(*VoxelNode->GetOutputPinName(PinIndex).ToString()));
#endif
		
#if ENGINE_MINOR_VERSION < 19
	if (NewPin->PinName.IsEmpty())
#else
	if (NewPin->PinName.ToString().IsEmpty())
#endif
	{
		// Makes sure pin has a name for lookup purposes but user will never see it
		NewPin->PinName = CreateUniquePinName(TEXT("Output"));
		NewPin->PinFriendlyName = FText::FromString(TEXT(" "));
	}

	if (NewPin->DefaultValue.IsEmpty())
	{
		NewPin->DefaultValue = FVoxelPinCategory::GetDefaultValueForCategory(VoxelNode->GetOutputPinCategory(PinIndex));
	}
}

void UVoxelGraphNode::AddInputPin()
{
	const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "VoxelEditorAddInput", "Add Voxel Input"));
	Modify();
	VoxelNode->AddInputPin();
	CreateInputPin();

	UVoxelGraphGenerator* Generator = CastChecked<UVoxelGraph>(GetGraph())->GetWorldGenerator();
	Generator->CompileVoxelNodesFromGraphNodes();
	Generator->MarkPackageDirty();

	// Refresh the current graph, so the pins can be updated
	GetGraph()->NotifyGraphChanged();
}

void UVoxelGraphNode::RemoveInputPin(UEdGraphPin* InGraphPin)
{
	const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "VoxelEditorAddInput", "Delete Voxel Input"));
	Modify();

	TArray<UEdGraphPin*> InputPins;
	GetInputPins(InputPins);

	for (int32 InputIndex = 0; InputIndex < InputPins.Num(); InputIndex++)
	{
		if (InGraphPin == InputPins[InputIndex])
		{
			InGraphPin->MarkPendingKill();
			Pins.Remove(InGraphPin);
			// also remove the VoxelNode child node so ordering matches
			VoxelNode->Modify();
			VoxelNode->RemoveInputPin();
			break;
		}
	}

	UVoxelGraphGenerator* Generator = CastChecked<UVoxelGraph>(GetGraph())->GetWorldGenerator();
	Generator->CompileVoxelNodesFromGraphNodes();
	Generator->MarkPackageDirty();

	// Refresh the current graph, so the pins can be updated
	GetGraph()->NotifyGraphChanged();
}

int32 UVoxelGraphNode::EstimateNodeWidth() const
{
	const int32 EstimatedCharWidth = 6;
	FString NodeTitle = GetNodeTitle(ENodeTitleType::FullTitle).ToString();
	UFont* Font = GetDefault<UEditorEngine>()->EditorFont;
	int32 Result = NodeTitle.Len()*EstimatedCharWidth;

	if (Font)
	{
		Result = Font->GetStringSize(*NodeTitle);
	}

	return Result;
}

int32 UVoxelGraphNode::EstimateNodeHeight() const
{
	float HeightEstimate = 0.0f;

	float BaseNodeHeight = 48.0f;
	bool bConsiderNodePins = true;
	float HeightPerPin = 18.0f;

	HeightEstimate = BaseNodeHeight;

	if (bConsiderNodePins)
	{
		int32 NumInputPins = 0;
		int32 NumOutputPins = 0;

		for (int32 PinIndex = 0; PinIndex < Pins.Num(); PinIndex++)
		{
			UEdGraphPin* CurrentPin = Pins[PinIndex];
			if (CurrentPin != NULL && !CurrentPin->bHidden)
			{
				switch (CurrentPin->Direction)
				{
				case EGPD_Input:
				{
					NumInputPins++;
				}
				break;
				case EGPD_Output:
				{
					NumOutputPins++;
				}
				break;
				}
			}
		}

		float MaxNumPins = float(FMath::Max<int32>(NumInputPins, NumOutputPins));

		HeightEstimate += MaxNumPins * HeightPerPin;
	}

	return HeightEstimate;
}

bool UVoxelGraphNode::CanAddInputPin() const
{
	if (VoxelNode)
	{
		// Check if adding another input would exceed max child nodes.
		return GetInputCount() < VoxelNode->GetMaxInputPins();
	}
	else
	{
		return false;
	}
}

bool UVoxelGraphNode::IsCompact() const
{
	return VoxelNode && VoxelNode->IsCompact();
}

bool UVoxelGraphNode::IsPreviewing() const
{
	return VoxelNode && VoxelNode->bIsPreviewing;
}

void UVoxelGraphNode::CreateInputPins()
{
	if (VoxelNode)
	{
		while (GetInputCount() < VoxelNode->GetInputPinsCount())
		{
			CreateInputPin();
		}
	}
}

void UVoxelGraphNode::CreateOutputPins()
{
	if (VoxelNode)
	{
		while (GetOutputCount() < VoxelNode->GetOutputPinsCount())
		{
			CreateOutputPin();
		}
	}
}

FText UVoxelGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	if (VoxelNode)
	{
		return VoxelNode->GetTitle();
	}
	else
	{
		return Super::GetNodeTitle(TitleType);
	}
}

FLinearColor UVoxelGraphNode::GetNodeTitleColor() const
{
	if (VoxelNode)
	{
		return VoxelNode->GetColor();
	}
	else
	{
		return FLinearColor::Gray;
	}
}

void UVoxelGraphNode::PrepareForCopying()
{
	if (VoxelNode)
	{
		// Temporarily take ownership of the VoxelNode, so that it is not deleted when cutting
		VoxelNode->Rename(NULL, this, REN_DontCreateRedirectors);
	}
}

void UVoxelGraphNode::GetContextMenuActions(const FGraphNodeContextMenuBuilder& Context) const
{
	if (!VoxelNode)
	{
		return;
	}

	if (Context.Pin)
	{
		// If on an input that can be deleted, show option
		if (Context.Pin->Direction == EGPD_Input && VoxelNode->GetInputPinsCount() > VoxelNode->GetMinInputPins())
		{
			Context.MenuBuilder->AddMenuEntry(FVoxelGraphEditorCommands::Get().DeleteInput);
		}
		if (Context.Pin->Direction == EGPD_Output && FVoxelPinCategory::FromString(Context.Pin->PinType.PinCategory) == EVoxelPinCategory::Float)
		{
			VoxelNode->LastPreviewPinIndex = GetOutputPinIndex(Context.Pin);
			if (VoxelNode->bIsPreviewing)
			{
				Context.MenuBuilder->AddMenuEntry(FVoxelGraphEditorCommands::Get().StopPreviewPin);
			}
			else
			{
				Context.MenuBuilder->AddMenuEntry(FVoxelGraphEditorCommands::Get().StartPreviewPin);
			}
		}
	}
	else if (Context.Node)
	{
		Context.MenuBuilder->BeginSection("VoxelGraphNodeEdit");
		{
			Context.MenuBuilder->AddMenuEntry(FGenericCommands::Get().Delete);
			Context.MenuBuilder->AddMenuEntry(FGenericCommands::Get().Cut);
			Context.MenuBuilder->AddMenuEntry(FGenericCommands::Get().Copy);
			Context.MenuBuilder->AddMenuEntry(FGenericCommands::Get().Duplicate);
		}
		Context.MenuBuilder->EndSection();
	}
}

FText UVoxelGraphNode::GetTooltipText() const
{
	FText Tooltip;

	auto* MacroNode = Cast<UVoxelGraphMacroNode>(VoxelNode);
	if (MacroNode && MacroNode->Macro)
	{
		Tooltip = FText::FromString(MacroNode->Macro->Tooltip);
	}
	else if (VoxelNode)
	{
		Tooltip = VoxelNode->GetClass()->GetToolTipText();
	}

	if (Tooltip.IsEmpty())
	{
		Tooltip = GetNodeTitle(ENodeTitleType::ListView);
	}

	return Tooltip;
}

FString UVoxelGraphNode::GetDocumentationExcerptName() const
{
	// Default the node to searching for an excerpt named for the C++ node class name, including the U prefix.
	// This is done so that the excerpt name in the doc file can be found by find-in-files when searching for the full class name.
	UClass* MyClass = (VoxelNode != NULL) ? VoxelNode->GetClass() : this->GetClass();
	return FString::Printf(TEXT("%s%s"), MyClass->GetPrefixCPP(), *MyClass->GetName());
}

bool UVoxelGraphNode::CanUserDeleteNode() const
{
	return !VoxelNode || VoxelNode->CanUserDeleteNode();
}

bool UVoxelGraphNode::CanDuplicateNode() const
{
	return !VoxelNode || VoxelNode->CanDuplicateNode();
}

bool UVoxelGraphNode::CanJumpToDefinition() const
{
	return VoxelNode && VoxelNode->IsA(UVoxelGraphMacroNode::StaticClass()) && CastChecked<UVoxelGraphMacroNode>(VoxelNode)->Macro;
}

void UVoxelGraphNode::JumpToDefinition() const
{
	FAssetEditorManager::Get().OpenEditorForAsset(CastChecked<UVoxelGraphMacroNode>(VoxelNode)->Macro);
}

void UVoxelGraphNode::PostLoad()
{
	Super::PostLoad();

	// Fixup any VoxelNode back pointers that may be out of date
	if (VoxelNode)
	{
		VoxelNode->GraphNode = this;
	}

	for (int32 Index = 0; Index < Pins.Num(); ++Index)
	{
		UEdGraphPin* Pin = Pins[Index];
		Pin->PinType.bIsConst = false;
#if ENGINE_MINOR_VERSION < 19
		if (Pin->PinName.IsEmpty())
#else
		if (Pin->PinName.ToString().IsEmpty())
#endif
		{
			// Makes sure pin has a name for lookup purposes but user will never see it
			if (Pin->Direction == EGPD_Input)
			{
				Pin->PinName = CreateUniquePinName(TEXT("Input"));
			}
			else
			{
				Pin->PinName = CreateUniquePinName(TEXT("Output"));
			}
			Pin->PinFriendlyName = FText::FromString(TEXT(" "));
		}
	}
}

void UVoxelGraphNode::PostEditImport()
{
	// Make sure this VoxelNode is owned by the WorldGenerator it's being pasted into.
	ResetVoxelNodeOwner();
}

void UVoxelGraphNode::PostDuplicate(bool bDuplicateForPIE)
{
	Super::PostDuplicate(bDuplicateForPIE);

	if (!bDuplicateForPIE)
	{
		CreateNewGuid();
	}
}

void UVoxelGraphNode::ResetVoxelNodeOwner()
{
	if (VoxelNode)
	{
		UVoxelGraphGenerator* Generator = CastChecked<UVoxelGraph>(GetGraph())->GetWorldGenerator();

		if (VoxelNode->GetOuter() != Generator)
		{
			// Ensures VoxelNode is owned by the WorldGenerator
			VoxelNode->Rename(NULL, Generator, REN_DontCreateRedirectors);
		}

		// Set up the back pointer for newly created voxel nodes
		VoxelNode->GraphNode = this;
	}
}
