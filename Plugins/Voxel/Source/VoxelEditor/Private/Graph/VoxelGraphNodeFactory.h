// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "EdGraphUtilities.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "SGraphNode.h"
#include "SVoxelGraphNode.h"

#include "VoxelGraphNode_Base.h"
#include "VoxelGraph.h"
#include "VoxelGraphNode_Knot.h"
#include "Runtime/Launch/Resources/Version.h"
#if ENGINE_MINOR_VERSION < 20
#include "SGraphNodeKnot_419.h"
#else
#include "SGraphNodeKnot.h"
#endif

class FVoxelGraphNodeFactory : public FGraphPanelNodeFactory
{
	virtual TSharedPtr<class SGraphNode> CreateNode(class UEdGraphNode* InNode) const override
	{
		if (UVoxelGraphNode_Knot* Knot = Cast<UVoxelGraphNode_Knot>(InNode))
		{
			return SNew(SGraphNodeKnot, Knot);
		}
		else if (UVoxelGraphNode_Base* VoxelNode = Cast<UVoxelGraphNode_Base>(InNode))
		{
			return SNew(SVoxelGraphNode, VoxelNode);
		}
		return nullptr;
	}
};
