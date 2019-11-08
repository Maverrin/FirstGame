// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelGraph/VoxelGraphCompilerHelpers.h"

inline FString GetDependenciesTextFromFlag(uint8 Flag)
{
	FString String;

	if (Flag & FVoxelCompilationNode::X)
	{
		String += "X";
	}
	if (Flag & FVoxelCompilationNode::Y)
	{
		String += "Y";
	}
	if (Flag & FVoxelCompilationNode::Z)
	{
		String += "Z";
	}
	if (String.IsEmpty())
	{
		String = "Constant";
	}

	return String;
}

struct FVoxelMarkDependenciesPass
{
	static void Apply(FVoxelGraphCompiler& Compiler)
	{
		// Init
		for (auto& Node : Compiler.GetAllNodes())
		{
			Node->Dependencies = 0;
		}

		// Mark
		for (auto& Node : Compiler.GetAllNodes())
		{
			uint8 Flag = Node->GetDefaultAxisDependencies();

			if (Flag != 0)
			{
				TSet<FVoxelCompilationNode*> Successors;
				FVoxelGraphCompilerHelpers::GetAllSuccessors(Node, Successors);
				for (auto& Successor : Successors)
				{
					Successor->Dependencies |= Flag;
				}
			}
		}
	}
};

struct FVoxelDebugDependenciesPass
{
	static void Apply(FVoxelGraphCompiler& Compiler)
	{
		for (auto& Node : Compiler.GetAllNodes())
		{
			Compiler.AddErrorToNode(Node, GetDependenciesTextFromFlag(Node->FinalDependencies), EVoxelGraphNodeErrorType::Dependencies);
		}
		Compiler.RefreshNodesErrors();
	}
};

