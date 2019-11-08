// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "EdGraph/EdGraph.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "VoxelGraph.generated.h"

UCLASS(MinimalAPI)
class UVoxelGraph : public UEdGraph
{
	GENERATED_UCLASS_BODY()

public:
	VOXELEDITOR_API class UVoxelGraphGenerator* GetWorldGenerator() const
	{
		return CastChecked<UVoxelGraphGenerator>(GetOuter());
	}
};

/////////////////////////////////////////////////////////////////////////

class FVoxelGraphEditor : public IVoxelGraphEditor
{
public:
	~FVoxelGraphEditor() {}

	UEdGraph* CreateNewVoxelGraph(UVoxelGraphGenerator* InVoxelWorldGenerator) override;

	void SetupVoxelNode(UEdGraph* VoxelGraph, UVoxelNode* InVoxelNode, bool bSelectNewNode) override;

	void CompileVoxelNodesFromGraphNodes(UVoxelGraphGenerator* WorldGenerator) override;
	void UpdatePreview(UVoxelGraphGenerator* WorldGenerator, bool bForce, bool bUpdateTextures) override;

	void CreateInputPin(UEdGraphNode* VoxelNode) override;
	void CreateOutputPin(UEdGraphNode* VoxelNode) override;

	void SelectNodesAndZoomToFit(UEdGraph* Graph, TArray<UEdGraphNode*>& Nodes) override;

	UVoxelGraphGenerator* GetWorldGeneratorFromGraph(UEdGraph* Graph) override;

	void SetDebugGraph(UEdGraph* DebugGraph, FVoxelGraphCompiler* Compiler) override;

	void RefreshNodesError(UEdGraph* Graph) override;

};
