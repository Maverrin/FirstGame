// Copyright 2018 Phyronnaz

#include "VoxelGraph/VoxelNode.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelGraph/VoxelCompilationNode.h"

const FString FVoxelPinCategory::PC_Exec(TEXT("exec"));
const FString FVoxelPinCategory::PC_Boolean(TEXT("bool"));
const FString FVoxelPinCategory::PC_Int(TEXT("int"));
const FString FVoxelPinCategory::PC_Float(TEXT("float"));
const FString FVoxelPinCategory::PC_Material(TEXT("FVoxelMaterial"));
const FString FVoxelPinCategory::PC_Seed(TEXT("Seed"));
const FString FVoxelPinCategory::PC_Wildcard(TEXT("Wildcard"));

EVoxelPinCategory FVoxelPinCategory::FromString(const FString& String)
{
	if (String == PC_Exec)
	{
		return EVoxelPinCategory::Exec;
	}
	else if (String == PC_Boolean)
	{
		return EVoxelPinCategory::Boolean;
	}
	else if (String == PC_Int)
	{
		return EVoxelPinCategory::Int;
	}
	else if (String == PC_Float)
	{
		return EVoxelPinCategory::Float;
	}
	else if (String == PC_Material)
	{
		return EVoxelPinCategory::Material;
	}
	else if (String == PC_Seed)
	{
		return EVoxelPinCategory::Seed;
	}
	else if (String == PC_Wildcard)
	{
		return EVoxelPinCategory::Wildcard;
	}
	else
	{
		check(false);
		return EVoxelPinCategory::Exec;
	}
}

FString FVoxelPinCategory::ToString(EVoxelPinCategory Category)
{
	switch (Category)
	{
	case EVoxelPinCategory::Exec:
		return PC_Exec;
	case EVoxelPinCategory::Boolean:
		return PC_Boolean;
	case EVoxelPinCategory::Int:
		return PC_Int;
	case EVoxelPinCategory::Float:
		return PC_Float;
	case EVoxelPinCategory::Material:
		return PC_Material;
	case EVoxelPinCategory::Seed:
		return PC_Seed;
	case EVoxelPinCategory::Wildcard:
		return PC_Wildcard;
	default:
		check(false);
		return FString();
	}
}

FString FVoxelPinCategory::GetDefaultValueForCategory(EVoxelPinCategory Category)
{
	switch (Category)
	{
	case EVoxelPinCategory::Exec:
		return FString();
	case EVoxelPinCategory::Boolean:
		return FString();
	case EVoxelPinCategory::Int:
		return TEXT("0");
	case EVoxelPinCategory::Float:
		return TEXT("0");
	case EVoxelPinCategory::Material:
		return FString();
	case EVoxelPinCategory::Seed:
		return TEXT("1337");
	case EVoxelPinCategory::Wildcard:
		return FString();
	default:
		check(false);
		return FString();
	}
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void UVoxelNode::CreateStartingConnectors()
{
#if WITH_EDITOR
	InputPinCount = GetMinInputPins();

	// Only add input
	for (int i = 0; i < GetInputPinsCount(); i++)
	{
		UVoxelGraphGenerator::GetVoxelGraphEditor()->CreateInputPin(GraphNode);
	}
#endif //WITH_EDITOR
}

void UVoxelNode::RemoveInputPin()
{
	check(InputPinCount > 0);
	InputPinCount--;
}

void UVoxelNode::AddInputPin()
{
	InputPinCount++;
}

int32 UVoxelNode::GetInputPinIndex(const FGuid& PinId)
{
	for (int I = 0; I < InputPins.Num(); I++)
	{
		if (InputPins[I].PinId == PinId)
		{
			return I;
		}
	}
	return -1;
}

int32 UVoxelNode::GetOutputPinIndex(const FGuid& PinId)
{
	for (int I = 0; I < OutputPins.Num(); I++)
	{
		if (OutputPins[I].PinId == PinId)
		{
			return I;
		}
	}
	return -1;
}

bool UVoxelNode::HasInputPinWithCategory(EVoxelPinCategory Category) const
{
	for (int i = 0; i < GetMinInputPins(); i++)
	{
		if (GetInputPinCategory(i) == Category)
		{
			return true;
		}
	}
	return false;
}

bool UVoxelNode::HasOutputPinWithCategory(EVoxelPinCategory Category) const
{
	for (int i = 0; i < GetOutputPinsCount(); i++)
	{
		if (GetOutputPinCategory(i) == Category)
		{
			return true;
		}
	}
	return false;
}

TArray<EVoxelPinCategory> UVoxelNode::GetInputCategories() const
{
	TArray<EVoxelPinCategory> InputCategories;
	for (auto& Pin : InputPins)
	{
		InputCategories.Add(Pin.PinCategory);
	}
	return InputCategories;
}

TArray<EVoxelPinCategory> UVoxelNode::GetOutputCategories() const
{
	TArray<EVoxelPinCategory> OutputCategories;
	for (auto& Pin : OutputPins)
	{
		OutputCategories.Add(Pin.PinCategory);
	}
	return OutputCategories;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

FText UVoxelNode::GetTitle() const
{
#if WITH_EDITOR
	return GetClass()->GetDisplayNameText();
#else
	return FText::GetEmpty();
#endif
}

TSharedPtr<FVoxelComputeNode> UVoxelNode::GetComputeNode(const FVoxelCompilationNode* CompilationNode) const
{
	check(false);
	return TSharedPtr<FVoxelComputeNode>();
}


TSharedPtr<FVoxelCompilationNode> UVoxelNode::GetCompilationNode() const
{
	return MakeShared<FVoxelDefaultCompilationNode>(GetName(), GetInputCategories(), GetOutputCategories(), this);
}

#if WITH_EDITOR
void UVoxelNode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (Graph && PropertyChangedEvent.Property && PropertyChangedEvent.ChangeType != EPropertyChangeType::Interactive)
	{
		UVoxelGraphGenerator::GetVoxelGraphEditor()->UpdatePreview(Graph, false, true);
	}

	MarkPackageDirty();
}

void UVoxelNode::PostLoad()
{
	Super::PostLoad();
	// Make sure voxel nodes are transactional (so they work with undo system)
	SetFlags(RF_Transactional);
}
#endif

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

FVoxelComputeNode::FVoxelComputeNode(const UVoxelNode* Node, const FVoxelCompilationNode* CompilationNode)
	: Name(CompilationNode->GetName())
	, InputCount(CompilationNode->GetInputCountWithoutExecs())
	, OutputCount(CompilationNode->GetOutputCountWithoutExecs())
	, SourceNode(CompilationNode->SourceNode)
{
	check(InputCount < MAX_PINS);
	check(OutputCount < MAX_PINS);

	check(CompilationNode->GetNode() == Node);

	InputIds.SetNum(InputCount);
	for (int I = 0; I < InputCount; I++)
	{
		InputIds[I] = CompilationNode->GetInputId(I);
	}
	OutputIds.SetNum(OutputCount);
	for (int I = 0; I < OutputCount; I++)
	{
		OutputIds[I] = CompilationNode->GetOutputId(I);
	}

	for (auto& Pin : CompilationNode->CreateInputPinsConstIterator())
	{
		FVoxelNodeType Value;
		FString ValueString;

		const FString& DefaultValue = Pin->GetDefaultValue();

		switch (Pin->PinCategory)
		{
		case EVoxelPinCategory::Exec:
			// Don't consider exec pins
			continue;
		case EVoxelPinCategory::Boolean:
			Value._bool = DefaultValue.ToBool();
			ValueString = Value._bool ? TEXT("true") : TEXT("false");
			break;
		case EVoxelPinCategory::Int:
			Value._int = FCString::Atoi(*DefaultValue);
			ValueString = FString::FromInt(Value._int);
			break;
		case EVoxelPinCategory::Float:
			Value._float = FCString::Atof(*DefaultValue);
			ValueString = FString::SanitizeFloat(Value._float) + "f";
			break;
		case EVoxelPinCategory::Material:
			Value._FVoxelMaterial = FVoxelMaterial();
			ValueString = TEXT("FVoxelMaterial()");
			break;
		case EVoxelPinCategory::Seed:
			Value._Seed = FCString::Atoi(*DefaultValue);
			ValueString = FString::FromInt(Value._int);
			break;
		default:
			Value._bool = false;
			check(false);
		}

		DefaultValues.Add(Value);
		DefaultValueStrings.Add(ValueString);
	}

	for (auto& Pin : CompilationNode->CreateOutputPinsConstIterator())
	{
		if (Pin->PinCategory != EVoxelPinCategory::Exec)
		{
			OutputTypes.Add(Pin->PinCategory);
		}
	}
}

