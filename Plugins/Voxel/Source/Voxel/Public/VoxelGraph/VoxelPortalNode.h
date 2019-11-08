// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelNode.h"
#include "VoxelGraph/VoxelCompilationNode.h"
#include "VoxelPortalNode.generated.h"

UENUM()
enum class EVoxelPinCategoryDataOnly : uint8
{
	Boolean,
	Int,
	Float,
	Material,
	Seed
};

inline EVoxelPinCategory GetPinCategoryFromDataOnlyCategory(EVoxelPinCategoryDataOnly Category)
{
	switch (Category)
	{
	case EVoxelPinCategoryDataOnly::Boolean:
		return EVoxelPinCategory::Boolean;
	case EVoxelPinCategoryDataOnly::Int:
		return EVoxelPinCategory::Int;
	case EVoxelPinCategoryDataOnly::Float:
		return EVoxelPinCategory::Float;
	case EVoxelPinCategoryDataOnly::Material:
		return EVoxelPinCategory::Material;
	case EVoxelPinCategoryDataOnly::Seed:
		return EVoxelPinCategory::Seed;
	default:
		check(false);
		return EVoxelPinCategory::Wildcard;
	}
}

USTRUCT()
struct VOXEL_API FVoxelPortalNodeSelector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Voxel")
	TWeakObjectPtr<class UVoxelPortalNodeInput> Input;
};

UCLASS(DisplayName = "Create Local Variable")
class VOXEL_API UVoxelPortalNodeInput : public UVoxelNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	FString Name = TEXT("Name");

	UPROPERTY(EditAnywhere, Category = "Voxel")
	EVoxelPinCategoryDataOnly Category = EVoxelPinCategoryDataOnly::Float;

	UPROPERTY()
	TArray<TWeakObjectPtr<class UVoxelPortalNodeOutput>> OutputNodes;

	inline EVoxelPinCategory GetCategory() const { return GetPinCategoryFromDataOnlyCategory(Category); }

public:
	int32 GetMinInputPins() const override { return 1; }
	int32 GetMaxInputPins() const override { return 1; }
	EVoxelPinCategory GetInputPinCategory(int32 PinIndex) const override { return GetCategory(); }
	FText GetTitle() const override { return FText::FromString(Name); }

protected:
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};

class FVoxelPortalOutputCompilationNode : public FVoxelCompilationNode
{
public:
	FVoxelCompilationNode* Passthrough = nullptr; // For preview

	using FVoxelCompilationNode::FVoxelCompilationNode;

	virtual TSharedPtr<FVoxelCompilationNode> Clone(bool bFixLinks = false) const override
	{
		auto Result = CloneInternalDefault<FVoxelPortalOutputCompilationNode>(bFixLinks);
		Result->Passthrough = Passthrough;
		return Result;
	}

	virtual EVoxelCompilationNodeType GetType() const override
	{
		return EVoxelCompilationNodeType::PortalOutput;
	}

};

UCLASS(DisplayName = "Get Local Variable")
class VOXEL_API UVoxelPortalNodeOutput : public UVoxelNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Voxel", meta = (DisplayName = "Input"))
	FVoxelPortalNodeSelector Selector;

public:
	int32 GetOutputPinsCount() const override { return 1; }	
	EVoxelPinCategory GetOutputPinCategory(int32 PinIndex) const override { return Selector.Input.IsValid() ? Selector.Input->GetCategory() : EVoxelPinCategory::Wildcard; }
	FText GetTitle() const override { return FText::FromString(Selector.Input.IsValid() ? Selector.Input->Name : ""); }

	TSharedPtr<FVoxelCompilationNode> GetCompilationNode() const override
	{
		return MakeShared<FVoxelPortalOutputCompilationNode>(GetName(), GetInputCategories(), GetOutputCategories(), this);
	}

#if WITH_EDITOR
	void RecreateNodeAndBreakAllLinks();
#endif

protected:
#if WITH_EDITOR
	virtual void PostLoad() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};

struct FReplaceVoxelPortalNodesPass
{
	static void Apply(class FVoxelGraphCompiler& Compiler);
};
