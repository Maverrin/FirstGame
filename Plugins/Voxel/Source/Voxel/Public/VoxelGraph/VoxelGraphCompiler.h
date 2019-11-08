// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelNode.h"
#include "VoxelGraph/VoxelComputeNodeTree.h"

class FVoxelGraphCompiler;
class UVoxelGraphGenerator;
class FVoxelCompilationNode;

/**
 * Tree used to create the compute tree
 */
class FVoxelCompilationNodeTree
{
public:
	FVoxelCompilationNodeTree(FVoxelCompilationNode* BranchNode);

	/**
	 * Remove the nodes of this tree that are in parents trees
	 */
	void CleanupDependencies(TArray<FVoxelCompilationNodeTree*> Parents = TArray<FVoxelCompilationNodeTree*>()); // No & intentional

	/**
	 * Set the output ids of the VoxelNodes
	 */
	void SetOutputIds(int32 StartId, int32& OutFirstUnusedId);
	/**
	 * Set the input ids of the VoxelNodes. Must be called after SetOutputIds
	 */
	void SetInputIds();

	/**
	 * Create the ComputeNodeTree
	 */
	void ConvertToComputeNodeTree(FVoxelComputeNodeTreesHolder& OutTree);

	void GetLocalVariables(TMap<int, FVoxelLocalVariable>& OutLocalVariables);

private:
	TArray<FVoxelCompilationNodeTree> Childs;

	TArray<FVoxelCompilationNode*> Nodes;
	FVoxelCompilationNode* const BranchNode;

	void ConvertToComputeNodeTreeImpl(FVoxelComputeNodeTree* OutConstantsTree, FVoxelComputeNodeTree* OutXTree, FVoxelComputeNodeTree* OutXYTree, FVoxelComputeNodeTree* OutXYZTree, TMap<FVoxelCompilationNode*, TSharedPtr<FVoxelComputeNode>>& AlreadyCreatedNodes);
	void GetLocalVariablesImpl(TMap<int, FVoxelLocalVariable>& OutLocalVariables, TSet<FVoxelCompilationNode*>& AlreadyParsedNodes);
};

enum class EVoxelGraphNodeErrorType : int32
{
	Error = 0,
	Warning = 1,
	Info = 2,
	Dependencies = 3,
	None = 4
};

class FVoxelGraphCompiler
{
public:
	UVoxelGraphGenerator* const Graph;
	FVoxelCompilationNode* FirstNode;
	int32 FirstNodePinIndex;
	TMap<UVoxelNode*, FVoxelCompilationNode*> Map;

	FVoxelGraphCompiler(UVoxelGraphGenerator* Graph, const TArray<UVoxelNode*>& InNodes, UVoxelNode* InFirstNode = nullptr, int32 InFirstNodePinIndex = 0);

	inline void AddNode(TSharedPtr<FVoxelCompilationNode> Ref)
	{
		NodesRefs.Add(Ref);
		Nodes.Add(Ref.Get());
	}
	inline void RemoveNode(FVoxelCompilationNode* Node)
	{
		Nodes.Remove(Node);
	}
	inline void AddError(const FString& Error)
	{
		if (!Error.IsEmpty())
		{
			Errors.Append(Error);
			Errors += "\n";
			bHasErrors = true;
		}
	}
	inline bool HasErrors() const { return bHasErrors; }
	inline void Merge(const FVoxelGraphCompiler& Other)
	{
		if (!Other.bHasErrors)
		{
			Map.Append(Other.Map);
			NodesRefs.Append(Other.NodesRefs);
			Nodes.Append(Other.Nodes);
			NodesToSelect.Append(Other.NodesToSelect);
		}
		else
		{
			Errors.Append(Other.Errors);
			bHasErrors = true;
		}
	}

	void Check() const;
	bool Compile(FVoxelComputeNodeTreesHolder& OutTree, int32& OutMaxId, TMap<int, FVoxelLocalVariable>& OutLocalVariables, FString& OutError);
	void SetPreviewedNode(UVoxelNode* Node);

	inline const TSet<FVoxelCompilationNode*>& GetAllNodes() const { return Nodes; }

	template<typename T>
	inline void ApplyPass()
	{
		if (!HasErrors())
		{
			T::Apply(*this);
		}
	}
	
	void AddErrorToNode(FVoxelCompilationNode* Node, const FString& Error, EVoxelGraphNodeErrorType Severity = EVoxelGraphNodeErrorType::Error, bool bSelectNode = true);
	void AddErrorToNode(const UVoxelNode* Node, const FString& Error, EVoxelGraphNodeErrorType Severity, bool bSelectNode = true);
	
	void RefreshNodesErrors();
	void RemoveNodeError(const UVoxelNode* Node);

	void AddNodeToSelect(FVoxelCompilationNode* Node);
	void AddNodeToSelect(const UVoxelNode* Node);

private:
	bool bHasErrors = false;
	TArray<TSharedPtr<FVoxelCompilationNode>> NodesRefs;
	TSet<FVoxelCompilationNode*> Nodes;
	FString Errors;
	TArray<UEdGraphNode*> NodesToSelect;
};
