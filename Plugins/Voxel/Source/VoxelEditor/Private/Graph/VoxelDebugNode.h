// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelNode.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelGraph/VoxelCompilationNode.h"
#include "VoxelDebugNode.generated.h"

UCLASS(notplaceable)
class UVoxelDebugNode : public UVoxelNode
{	
	GENERATED_BODY()

public:
	TSharedPtr<FVoxelCompilationNode> CompilationNode;
	bool bIsFirst = false;

public:
	int32 GetMaxInputPins() const override { return CompilationNode->GetInputCount(); }
	int32 GetMinInputPins() const override { return CompilationNode->GetInputCount(); }
	int32 GetOutputPinsCount() const override { return CompilationNode->GetOutputCount(); }

	FLinearColor GetColor() const override { return bIsFirst ? FLinearColor::Red : FLinearColor::Black; }
	FText GetTitle() const override
	{
		FString S = CompilationNode->GetName();
		
		S = S.Replace(TEXT("VoxelNode_"), TEXT(""));
		S = S.Replace(TEXT("VoxelGraphMacroNode_"), TEXT("Macro"));
		
		int Index;
		S.FindLastChar('_', Index);
		if (Index >= 0)
		{
			S.RemoveAt(Index);
		}

		S = S.Replace(TEXT("_"), TEXT("."));

		return FText::FromString(S);
	}
	bool IsCompact() const override { return false; }

	FText GetInputPinName(int32 PinIndex) const override { return FText::FromString(CompilationNode->GetInputPin(PinIndex).Name); }
	FText GetOutputPinName(int32 PinIndex) const override { return FText::FromString(CompilationNode->GetOutputPin(PinIndex).Name); }

	EVoxelPinCategory GetInputPinCategory(int32 PinIndex) const override { return CompilationNode->GetInputPin(PinIndex).PinCategory; }
	EVoxelPinCategory GetOutputPinCategory(int32 PinIndex) const override { return CompilationNode->GetOutputPin(PinIndex).PinCategory; }

	FString GetInputPinDefaultValue(int32 PinIndex) const override { return CompilationNode->GetInputPin(PinIndex).GetDefaultValue(); }
		
	bool CanUserDeleteNode() const override { return false; }
	bool CanDuplicateNode() const override { return false; }
};
