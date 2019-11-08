// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "EdGraph/EdGraphNode.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "VoxelGraphNode_Base.h"
#include "VoxelGraphNode.generated.h"

UCLASS(MinimalAPI)
class UVoxelGraphNode : public UVoxelGraphNode_Base
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UVoxelNode* VoxelNode;

	/** Set the VoxelNode this represents (also assigns this to the VoxelNode in Editor)*/
	VOXELEDITOR_API void SetVoxelNode(UVoxelNode* InVoxelNode);
	/** Create a new input pin for this node */
	VOXELEDITOR_API void CreateInputPin();
	/** Create a new output pin for this node */
	VOXELEDITOR_API void CreateOutputPin();
	/** Remove a specific input pin from this node and recompile the WorldGenerator */
	VOXELEDITOR_API void RemoveInputPin(UEdGraphPin* InGraphPin);
	/** Estimate the width of this Node from the length of its title */
	VOXELEDITOR_API int32 EstimateNodeWidth() const;
	VOXELEDITOR_API int32 EstimateNodeHeight() const;
	/** Fix up the node's owner after being copied */
	VOXELEDITOR_API void PostCopyNode();


	// UVoxelGraphNode_Base interface
	virtual void CreateInputPins() override;
	virtual void CreateOutputPins() override;
	virtual bool IsCompact() const override;
	virtual bool IsPreviewing() const override;
	virtual void AddInputPin() override;
	virtual bool CanAddInputPin() const override;
	// End of UVoxelGraphNode_Base interface

	// UEdGraphNode interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual void PrepareForCopying() override;
	virtual void GetContextMenuActions(const FGraphNodeContextMenuBuilder& Context) const override;
	virtual FText GetTooltipText() const override;
	virtual FString GetDocumentationExcerptName() const override;
	virtual bool CanUserDeleteNode() const override;
	virtual bool CanDuplicateNode() const override;
	virtual bool CanJumpToDefinition() const override;
	virtual void JumpToDefinition() const override;
	// End of UEdGraphNode interface

	// UObject interface
	virtual void PostLoad() override;
	virtual void PostEditImport() override;
	virtual void PostDuplicate(bool bDuplicateForPIE) override;
	// End of UObject interface

private:
	/** Make sure the voxel node is owned by the World Generator */
	void ResetVoxelNodeOwner();

};
