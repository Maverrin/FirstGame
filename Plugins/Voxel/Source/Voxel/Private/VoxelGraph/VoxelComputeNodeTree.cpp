// Copyright 2018 Phyronnaz

#include "VoxelGraph/VoxelComputeNodeTree.h"
#include "VoxelGraph/VoxelNode.h"
#include "VoxelGraph/VoxelCppConstructor.h"
#include "VoxelGraph/VoxelNodeDefinitions.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "VoxelMaterial.h"
#include "VoxelGlobals.h"

FVoxelGraphPerfCounter FVoxelGraphPerfCounter::Singleton;
FCriticalSection FVoxelGraphPerfCounter::Section;

inline FVoxelGraphPerfCounter* GetThreadPerfCounter()
{
	VOXEL_THREADLOCAL FVoxelGraphPerfCounter Counter;
	return &Counter;
};

struct FVoxelScopePerfCounter
{
	FVoxelScopePerfCounter(const TSharedPtr<FVoxelComputeNode>& Node)
		: Start(FPlatformTime::Cycles64())
		, Node(Node->SourceNode)
	{
	}
	~FVoxelScopePerfCounter()
	{
		uint64 Elapsed = FPlatformTime::Cycles64() - Start;
		GetThreadPerfCounter()->LogNode(Node, Elapsed);
	}

private:
	const uint64 Start;
	const UVoxelNode* const Node;
};

#if ENABLE_VOXELGRAPH_CHECKS
#define checkDev(...) check(__VA_ARGS__)
#else
#define checkDev(...)
#endif

inline void CopyVariablesToInputs(const TSharedPtr<FVoxelComputeNode>& Node, FVoxelNodeType Variables[], FVoxelNodeType InputBuffer[])
{
	for (int InputIndex = 0; InputIndex < Node->InputCount; InputIndex++)
	{
		int32 Id = Node->GetInputId(InputIndex);
		if (Id == -1)
		{
			checkDev(0 <= InputIndex && InputIndex < MAX_PINS);
			InputBuffer[InputIndex] = Node->GetDefaultValue(InputIndex);
		}
		else
		{
			checkDev(0 <= InputIndex && InputIndex < MAX_PINS);
			checkDev(0 <= Id && Id < MAX_VARIABLES);
			InputBuffer[InputIndex] = Variables[Id];
		}
	}
}

inline void CopyOutputsToVariables(const TSharedPtr<FVoxelComputeNode>& Node, FVoxelNodeType Variables[], FVoxelNodeType OutputBuffer[])
{
	for (int OutputIndex = 0; OutputIndex < Node->OutputCount; OutputIndex++)
	{
		int Id = Node->GetOutputId(OutputIndex);
		checkDev(0 <= OutputIndex && OutputIndex < MAX_PINS);
		checkDev(0 <= Id && Id < MAX_VARIABLES);
		Variables[Id] = OutputBuffer[OutputIndex];
	}
}

void FVoxelComputeNodeTree::Init(FVoxelNodeType Variables[], FVoxelNodeType InputOutputBuffer[], const FVoxelWorldGeneratorInit& InitStruct) const
{
	FVoxelNodeType* InputBuffer = GetInputBuffer(InputOutputBuffer);
	FVoxelNodeType* OutputBuffer = GetOutputBuffer(InputOutputBuffer);

	for (auto& Node : Nodes)
	{
		if (!Node->IsInit())
		{
			CopyVariablesToInputs(Node, Variables, InputBuffer);
			Node->CallInit(InputBuffer, OutputBuffer, InitStruct);
			CopyOutputsToVariables(Node, Variables, OutputBuffer);
		}
	}

	for (auto& Child : Children)
	{
		Child.Init(Variables, InputOutputBuffer, InitStruct);
	}
}
void FVoxelComputeNodeTree::Compute(FVoxelNodeType Variables[], FVoxelNodeType InputOutputBuffer[], const FVoxelContext& Context, float& Value, FVoxelMaterial& Material) const
{
	FVoxelNodeType* InputBuffer = GetInputBuffer(InputOutputBuffer);
	FVoxelNodeType* OutputBuffer = GetOutputBuffer(InputOutputBuffer);

	if (bEnableStats)
	{
		ComputeInternal<true>(Variables, InputBuffer, OutputBuffer, Context, Value, Material);
	}
	else
	{
		ComputeInternal<false>(Variables, InputBuffer, OutputBuffer, Context, Value, Material);
	}
}

template<bool bTEnableStats>
void FVoxelComputeNodeTree::ComputeInternal(FVoxelNodeType Variables[], FVoxelNodeType InputBuffer[], FVoxelNodeType OutputBuffer[], const FVoxelContext& Context, float& Value, FVoxelMaterial& Material) const
{
	for (auto& Node : Nodes)
	{
		CopyVariablesToInputs(Node, Variables, InputBuffer);
		if (bTEnableStats)
		{
			FVoxelScopePerfCounter Counter(Node);
			Node->Compute(InputBuffer, OutputBuffer, Context);
		}
		else
		{
			Node->Compute(InputBuffer, OutputBuffer, Context);
		}
		CopyOutputsToVariables(Node, Variables, OutputBuffer);
	}

	if (BranchNode.IsValid())
	{
		CopyVariablesToInputs(BranchNode, Variables, InputBuffer);		
		int32 BranchId = BranchNode->ComputeExecNode(InputBuffer, Value, Material);
		Children[BranchId].ComputeInternal<bTEnableStats>(Variables, InputBuffer, OutputBuffer, Context, Value, Material);
	}
}


void FVoxelComputeNodeTree::SetupConstructor(FVoxelCppConstructor& Constructor) const
{	
	for (auto& Node : Nodes)
	{
		if (!Node->IsConstructorSetup())
		{
			Node->CallSetupConstructor(Constructor);
		}
	}

	for (auto& Child : Children)
	{
		Child.SetupConstructor(Constructor);
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

inline void SetComputeNodeInputsCpp(const TSharedPtr<FVoxelComputeNode>& Node, FVoxelCppConstructor& Constructor, TArray<FString>& Inputs)
{
	for (int InputIndex = 0; InputIndex < Node->InputCount; InputIndex++)
	{
		int32 Id = Node->GetInputId(InputIndex);
		if (Id == -1)
		{
			Inputs[InputIndex] = Node->GetDefaultValueString(InputIndex);
		}
		else
		{
			Inputs[InputIndex] = Constructor.GetLocalVariableName(Id);
		}
	}
}
inline void SetComputeNodeOutputsCpp(const TSharedPtr<FVoxelComputeNode>& Node, FVoxelCppConstructor& Constructor, TArray<FString>& Outputs)
{
	for (int OutputIndex = 0; OutputIndex < Node->OutputCount; OutputIndex++)
	{
		Outputs[OutputIndex] = Constructor.GetLocalVariableName(Node->GetOutputId(OutputIndex));
	}
}

void FVoxelComputeNodeTree::InitCpp(FVoxelCppConstructor& Constructor) const
{
	TArray<FString> Inputs;
	TArray<FString> Outputs;
	Inputs.SetNum(MAX_PINS);
	Outputs.SetNum(MAX_PINS);

	for (auto& Node : Nodes)
	{
		if (!Node->IsInit())
		{
			Constructor.QueueComment("// Init of " + Node->Name);
			{
				SetComputeNodeInputsCpp(Node, Constructor, Inputs);
				SetComputeNodeOutputsCpp(Node, Constructor, Outputs);
				Node->CallInitCpp(Inputs, Outputs, Constructor);
			}
			Constructor.EndComment();
		}
	}

	for (auto& Child : Children)
	{
		Child.InitCpp(Constructor);
	}
}

void FVoxelComputeNodeTree::ComputeCpp(FVoxelCppConstructor& Constructor)
{
	for (auto& Node : Nodes)
	{
		TArray<FString> Inputs;
		TArray<FString> Outputs;
		Inputs.SetNum(Node->InputCount);
		Outputs.SetNum(Node->OutputCount);

		Constructor.QueueComment("// " + Node->Name);
		{
			SetComputeNodeInputsCpp(Node, Constructor, Inputs);
			SetComputeNodeOutputsCpp(Node, Constructor, Outputs);
			Node->ComputeCpp(Inputs, Outputs, Constructor);
		}
		Constructor.EndComment();
	}

	if (BranchNode.IsValid())
	{
		TArray<FString> Inputs;
		TArray<FString> Outputs;
		Inputs.SetNum(BranchNode->InputCount);
		Outputs.SetNum(BranchNode->OutputCount);
		
		Constructor.QueueComment("// " + BranchNode->Name);
		SetComputeNodeInputsCpp(BranchNode, Constructor, Inputs);
		FString BranchResult;
		FVoxelComputeNode::EExecKind Kind = BranchNode->ComputeExecNodeCpp(Inputs, BranchResult, Constructor);
		Constructor.EndComment();

		bool bIsIf = Kind == FVoxelComputeNode::EExecKind::If;
		check(bIsIf || Kind == FVoxelComputeNode::EExecKind::Passthrough);
		check((bIsIf && Children.Num() == 2) || (!bIsIf && Children.Num() == 1));

		if (bIsIf)
		{
			Constructor.AddLine("if(" + BranchResult + ")");
			Constructor.AddLine("{");
			Constructor.Indent();
			Children[0].ComputeCpp(Constructor);
			Constructor.Unindent();
			Constructor.AddLine("}");
			Constructor.AddLine("else");
			Constructor.AddLine("{");
			Constructor.Indent();
			Children[1].ComputeCpp(Constructor);
			Constructor.Unindent();
			Constructor.AddLine("}");
		}
		else if (Children[0].BranchNode.IsValid())
		{
			Constructor.AddLine("{");
			Constructor.Indent();
			Children[0].ComputeCpp(Constructor);
			Constructor.Unindent();
			Constructor.AddLine("}");
		}
	}
}

#undef checkDev
