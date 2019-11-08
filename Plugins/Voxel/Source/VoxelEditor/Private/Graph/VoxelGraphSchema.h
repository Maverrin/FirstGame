// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "AssetData.h"
#include "EdGraph/EdGraphSchema.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "VoxelGraphSchema.generated.h"

USTRUCT()
struct VOXELEDITOR_API FVoxelGraphSchemaAction_NewNode : public FEdGraphSchemaAction
{
	GENERATED_BODY();

public:
	/** Class of node we want to create */
	UPROPERTY()
	UClass* VoxelNodeClass = nullptr;
	
	using FEdGraphSchemaAction::FEdGraphSchemaAction;
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
};

USTRUCT()
struct VOXELEDITOR_API FVoxelGraphSchemaAction_NewMacroNode : public FEdGraphSchemaAction
{
	GENERATED_BODY();

public:
	UPROPERTY()
	class UVoxelGraphMacro* Macro = nullptr;

	using FEdGraphSchemaAction::FEdGraphSchemaAction;
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
};

USTRUCT()
struct VOXELEDITOR_API FVoxelGraphSchemaAction_NewPortalNode : public FEdGraphSchemaAction
{
	GENERATED_BODY();

public:
	UPROPERTY()
	class UVoxelPortalNodeInput* InputNode = nullptr;
	
	using FEdGraphSchemaAction::FEdGraphSchemaAction;
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
};

USTRUCT()
struct VOXELEDITOR_API FVoxelGraphSchemaAction_NewKnotNode : public FEdGraphSchemaAction
{
	GENERATED_BODY();

public:
	using FEdGraphSchemaAction::FEdGraphSchemaAction;
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
};

/** Action to create new comment */
USTRUCT()
struct VOXELEDITOR_API FVoxelGraphSchemaAction_NewComment : public FEdGraphSchemaAction
{
	GENERATED_BODY();

public:
	using FEdGraphSchemaAction::FEdGraphSchemaAction;
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
};

/** Action to paste clipboard contents into the graph */
USTRUCT()
struct VOXELEDITOR_API FVoxelGraphSchemaAction_Paste : public FEdGraphSchemaAction
{
	GENERATED_BODY();

public:
	using FEdGraphSchemaAction::FEdGraphSchemaAction;
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
};


UCLASS(MinimalAPI)
class UVoxelGraphSchema : public UEdGraphSchema
{
	GENERATED_UCLASS_BODY()
public:

	bool ConnectionCausesLoop(const UEdGraphPin* InputPin, const UEdGraphPin* OutputPin) const;

	/** Helper method to add items valid to the palette list */
	VOXELEDITOR_API void GetPaletteActions(FGraphActionMenuBuilder& ActionMenuBuilder) const;

	virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;
	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;
	virtual bool TryCreateConnection(UEdGraphPin* A, UEdGraphPin* B) const override;
	virtual void TrySetDefaultValue(UEdGraphPin& Pin, const FString& NewDefaultValue) const override;
	virtual bool CreateAutomaticConversionNodeAndConnections(UEdGraphPin* A, UEdGraphPin* B) const;
	virtual void CreateDefaultNodesForGraph(UEdGraph& Graph) const override;
	virtual void BreakNodeLinks(UEdGraphNode& TargetNode) const override;
	virtual void BreakPinLinks(UEdGraphPin& TargetPin, bool bSendsNodeNotifcation) const override;
	virtual void OnPinConnectionDoubleCicked(UEdGraphPin* PinA, UEdGraphPin* PinB, const FVector2D& GraphPosition) const override;
	virtual FLinearColor GetPinTypeColor(const FEdGraphPinType& PinType) const override;
	virtual TSharedPtr<FEdGraphSchemaAction> GetCreateCommentAction() const override;
	virtual int32 GetNodeSelectionCount(const UEdGraph* Graph) const override;
	virtual void GetContextMenuActions(const UEdGraph* CurrentGraph, const UEdGraphNode* InGraphNode, const UEdGraphPin* InGraphPin, class FMenuBuilder* MenuBuilder, bool bIsDebugging) const override;

private:
	/** Adds actions for creating every type of VoxelNode */
	void GetAllVoxelNodeActions(FGraphActionMenuBuilder& ActionMenuBuilder, const UEdGraph* CurrentGraph = nullptr) const;
	/** Adds action for creating a comment */
	void GetCommentAction(FGraphActionMenuBuilder& ActionMenuBuilder, const UEdGraph* CurrentGraph = nullptr) const;

private:
	static void InitVoxelNodeClasses();
	static TArray<UClass*> VoxelNodeClasses;
	static bool bVoxelNodeClassesInitialized;
};
