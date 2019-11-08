// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "VoxelGraph/VoxelNode.h"
#include "VoxelGraph/VoxelNodeHelpers.h"
#include "VoxelGraph/VoxelCompilationNode.h"
#include "VoxelGraphMacro.generated.h"

class FVoxelMacroCompilationNode : public FVoxelCompilationNode
{
public:
	TArray<FVoxelCompilationPin*> NewInputPins;
	TArray<FVoxelCompilationPin*> NewOutputPins;

	using FVoxelCompilationNode::FVoxelCompilationNode;

	virtual TSharedPtr<FVoxelCompilationNode> Clone(bool bFixLinks) const override
	{
		auto Result = CloneInternalDefault<FVoxelMacroCompilationNode>(bFixLinks);
		Result->NewInputPins = NewInputPins;
		Result->NewOutputPins = NewOutputPins;
		return Result;
	}
	virtual EVoxelCompilationNodeType GetType() const override
	{
		return EVoxelCompilationNodeType::Macro;
	}
	virtual void LogErrors(FVoxelGraphCompiler& Compiler) override;
};

struct FVoxelGraphInlineMacrosPass
{
	static void Apply(FVoxelGraphCompiler& Compiler);
};

USTRUCT()
struct FVoxelPinNameAndType
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Voxel")
	FString Name;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	EVoxelPinCategory Category;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	FString DefaultValue;
};

UCLASS(abstract)
class VOXEL_API UVoxelGraphMacroInputOutputNode : public UVoxelNode
{
	GENERATED_BODY()	
public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	TArray<FVoxelPinNameAndType> Pins;

	UPROPERTY()
	class UVoxelGraphMacro* Macro;

	FLinearColor GetColor() const override { return FLinearColor::Red; }	
	bool CanUserDeleteNode() const override { return false; }
	bool CanDuplicateNode() const override { return false; }

#if WITH_EDITOR
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR
};

UCLASS(DisplayName = "Input", notplaceable)
class VOXEL_API UVoxelGraphMacroInputNode : public UVoxelGraphMacroInputOutputNode
{
	GENERATED_BODY()
	
	int32 GetOutputPinsCount() const override { return Pins.Num(); }
	FText GetOutputPinName(int32 PinIndex) const override { return FText::FromString(Pins[PinIndex].Name); }
	EVoxelPinCategory GetOutputPinCategory(int32 PinIndex) const override { return Pins[PinIndex].Category; }
};

UCLASS(DisplayName = "Output", notplaceable)
class VOXEL_API UVoxelGraphMacroOutputNode : public UVoxelGraphMacroInputOutputNode
{
	GENERATED_BODY()

	int32 GetMaxInputPins() const override { return Pins.Num(); }
	int32 GetMinInputPins() const override { return Pins.Num(); }
	FText GetInputPinName(int32 PinIndex) const override { return FText::FromString(Pins[PinIndex].Name); }
	EVoxelPinCategory GetInputPinCategory(int32 PinIndex) const override { return Pins[PinIndex].Category; }
};

/**
 * A graph macro
 */
UCLASS(BlueprintType, hidecategories = (Object), hidedropdown)
class VOXEL_API UVoxelGraphMacro : public UVoxelGraphGenerator
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Voxel", meta = (MultiLine = true, DisplayName = "Tooltip (Shift+Enter for new line)"))
	FString Tooltip;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	bool bShowInContextMenu = true;

	UPROPERTY()
	UVoxelGraphMacroInputNode* InputNode;

	UPROPERTY()
	UVoxelGraphMacroOutputNode* OutputNode;
};

UCLASS()
class VOXEL_API UVoxelGraphMacroNode : public UVoxelNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	UVoxelGraphMacro* Macro;

	TSharedPtr<FVoxelCompilationNode> GetCompilationNode() const override
	{
		return MakeShared<FVoxelMacroCompilationNode>(GetName(), GetInputCategories(), GetOutputCategories(), this);
	}

#if WITH_EDITOR
	FText GetTitle() const override { return Macro ? FText::FromString(Macro->GetName()) : Super::GetTitle(); }
#endif

	int32 GetMaxInputPins() const override { return Macro && Macro->InputNode ? Macro->InputNode->Pins.Num() : 0; }
	int32 GetMinInputPins() const override { return Macro && Macro->InputNode ? Macro->InputNode->Pins.Num() : 0; }
	int32 GetOutputPinsCount() const override { return Macro && Macro->OutputNode ? Macro->OutputNode->Pins.Num() : 0; }

	FText GetInputPinName(int32 PinIndex) const override { return Macro && Macro->InputNode &&  Macro->InputNode->Pins.IsValidIndex(PinIndex) ? FText::FromString(Macro->InputNode->Pins[PinIndex].Name) : FText(); }
	FText GetOutputPinName(int32 PinIndex) const override { return Macro && Macro->OutputNode && Macro->OutputNode->Pins.IsValidIndex(PinIndex) ? FText::FromString(Macro->OutputNode->Pins[PinIndex].Name) : FText(); }

	EVoxelPinCategory GetInputPinCategory(int32 PinIndex) const override { return  Macro && Macro->InputNode && Macro->InputNode->Pins.IsValidIndex(PinIndex) ? Macro->InputNode->Pins[PinIndex].Category : EVoxelPinCategory::Exec; }
	EVoxelPinCategory GetOutputPinCategory(int32 PinIndex) const override { return Macro && Macro->OutputNode && Macro->OutputNode->Pins.IsValidIndex(PinIndex) ? Macro->OutputNode->Pins[PinIndex].Category : EVoxelPinCategory::Exec; }

	FString GetInputPinDefaultValue(int32 PinIndex) const override { return  Macro && Macro->InputNode && Macro->InputNode->Pins.IsValidIndex(PinIndex) ? Macro->InputNode->Pins[PinIndex].DefaultValue : ""; }

#if WITH_EDITOR
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR
};
