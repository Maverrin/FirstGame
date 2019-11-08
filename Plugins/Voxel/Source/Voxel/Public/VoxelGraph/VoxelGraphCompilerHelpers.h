// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelCompilationNode.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelGraph/VoxelNodeHelpers.h"

template<typename T, EVoxelPinCategory Category>
class FPassthroughCompilationNode : public FVoxelCompilationNode
{
public:
	using FVoxelCompilationNode::FVoxelCompilationNode;

	FPassthroughCompilationNode(const FString& Name, const UVoxelNode* InSourceNode)
		: FVoxelCompilationNode(Name, TArray<EVoxelPinCategory>({ Category }), TArray<EVoxelPinCategory>({ Category }))
	{
		SourceNode = InSourceNode;
	}

	virtual TSharedPtr<FVoxelCompilationNode> Clone(bool bFixLinks) const override
	{
		return CloneInternalDefault<FPassthroughCompilationNode>(bFixLinks);
	}
	virtual TSharedPtr<FVoxelComputeNode> GetComputeNode() const override
	{
		return MakeShared<T>(nullptr, this);
	}
	virtual EVoxelCompilationNodeType GetType() const override
	{
		return EVoxelCompilationNodeType::Passthrough;
	}
};

namespace FVoxelExecPassthroughComputeNode
{
	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		using FVoxelComputeNode::FVoxelComputeNode;
		int32 ComputeExecNode(FVoxelNodeType Inputs[], float& Value, FVoxelMaterial& Material) const override { return 0; }
		EExecKind ComputeExecNodeCpp(const TArray<FString>& Inputs, FString& BranchResult, FVoxelCppConstructor& Constuctor) const override { return EExecKind::Passthrough; }
	};
}
namespace FVoxelBoolPassthroughComputeNode
{
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(bool),
		DEFINE_OUTPUTS_REVERSED(bool),
		_O0 = _I0;
	)
}
namespace FVoxelIntPassthroughComputeNode
{
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(int),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = _I0;
	)
};
namespace FVoxelFloatPassthroughComputeNode
{
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = _I0;
	)
};
namespace FVoxelMaterialPassthroughComputeNode
{
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(FVoxelMaterial),
		DEFINE_OUTPUTS_REVERSED(FVoxelMaterial),
		_O0 = _I0;
	)
};
namespace FVoxelSeedPassthroughComputeNode
{
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(Seed),
		DEFINE_OUTPUTS_REVERSED(Seed),
		_O0 = _I0;
	)
};
using FVoxelExecPassthrough     = FPassthroughCompilationNode<FVoxelExecPassthroughComputeNode    ::FLocalVoxelComputeNode, EC::Exec>;
using FVoxelBoolPassthrough     = FPassthroughCompilationNode<FVoxelBoolPassthroughComputeNode    ::FLocalVoxelComputeNode, EC::Boolean>;
using FVoxelIntPassthrough      = FPassthroughCompilationNode<FVoxelIntPassthroughComputeNode     ::FLocalVoxelComputeNode, EC::Int>;
using FVoxelFloatPassthrough    = FPassthroughCompilationNode<FVoxelFloatPassthroughComputeNode   ::FLocalVoxelComputeNode, EC::Float>;
using FVoxelMaterialPassthrough = FPassthroughCompilationNode<FVoxelMaterialPassthroughComputeNode::FLocalVoxelComputeNode, EC::Material>;
using FVoxelSeedPassthrough     = FPassthroughCompilationNode<FVoxelSeedPassthroughComputeNode    ::FLocalVoxelComputeNode, EC::Seed>;

inline TSharedPtr<FVoxelCompilationNode> GetVoxelPassthroughNode(EVoxelPinCategory Category, const UVoxelNode* SourceNode)
{
	switch (Category)
	{
	case EVoxelPinCategory::Exec:
		return MakeShared<FVoxelExecPassthrough>("ExecPassthrough", SourceNode);
	case EVoxelPinCategory::Boolean:
		return MakeShared<FVoxelBoolPassthrough>("BoolPassthrough", SourceNode);
	case EVoxelPinCategory::Int:
		return MakeShared<FVoxelIntPassthrough>("IntPassthrough", SourceNode);
	case EVoxelPinCategory::Float:
		return MakeShared<FVoxelFloatPassthrough>("FloatPassthrough", SourceNode);
	case EVoxelPinCategory::Material:
		return MakeShared<FVoxelMaterialPassthrough>("MaterialPassthrough", SourceNode);
	case EVoxelPinCategory::Seed:
		return MakeShared<FVoxelSeedPassthrough>("SeedPassthrough", SourceNode);
	default:
		check(false);
		return TSharedPtr<FVoxelCompilationNode>();
	}
}

///////////////////////////////////////////////////////////////////////////////

namespace FVoxelGraphCompilerHelpers
{
	inline FVoxelCompilationNode* AddPassthroughOnInput(FVoxelGraphCompiler& Compiler, FVoxelCompilationPin* InputPin, FVoxelCompilationNode* SourceNode = nullptr)
	{
		check(InputPin->Direction == EVoxelPinDirection::Input);
		if (!SourceNode)
		{
			SourceNode = InputPin->Node;
		}

		TSharedPtr<FVoxelCompilationNode> Passthrough = GetVoxelPassthroughNode(InputPin->PinCategory, SourceNode->SourceNode);
		Compiler.AddNode(Passthrough);

		auto& PassthroughInputPin = Passthrough->GetInputPin(0);
		auto& PassthroughOutputPin = Passthrough->GetOutputPin(0);
		PassthroughInputPin.SetDefaultValue(InputPin->GetDefaultValue());
		
		auto LinkedTo = InputPin->GetLinkedTo(); // Copy as we are modifying it
		for (auto& LinkedToPin : LinkedTo)
		{
			InputPin->BreakLinkTo(LinkedToPin);
			LinkedToPin->LinkTo(&PassthroughInputPin);
		}
		check(InputPin->LinkedToNum() == 0);

		PassthroughOutputPin.LinkTo(InputPin);

		return Passthrough.Get();
	}
	inline FVoxelCompilationNode* AddPassthroughOnOutput(FVoxelGraphCompiler& Compiler, FVoxelCompilationPin* OutputPin, FVoxelCompilationNode* SourceNode = nullptr)
	{
		check(OutputPin->Direction == EVoxelPinDirection::Output);
		if (!SourceNode)
		{
			SourceNode = OutputPin->Node;
		}

		TSharedPtr<FVoxelCompilationNode> Passthrough = GetVoxelPassthroughNode(OutputPin->PinCategory, SourceNode->SourceNode);
		Compiler.AddNode(Passthrough);

		auto& PassthroughInputPin = Passthrough->GetInputPin(0);
		auto& PassthroughOutputPin = Passthrough->GetOutputPin(0);

		auto LinkedTo = OutputPin->GetLinkedTo(); // Copy as we are modifying it
		for (auto& LinkedToPin : LinkedTo)
		{
			OutputPin->BreakLinkTo(LinkedToPin);
			PassthroughOutputPin.LinkTo(LinkedToPin);
		}
		check(OutputPin->LinkedToNum() == 0);

		OutputPin->LinkTo(&PassthroughInputPin);

		return Passthrough.Get();
	}

	inline void DuplicateNodeAndQueueLinks(FVoxelGraphCompiler& Compiler, FVoxelCompilationNode* Node, TArray<FVoxelCompilationPinLink>& OutLinksToCreate, TMap<FVoxelCompilationPin*, FVoxelCompilationPin*>& OldPinsToNewPins)
	{
		TSharedPtr<FVoxelCompilationNode> NewNode = Node->Clone(true);
		Compiler.AddNode(NewNode);
		NewNode->AddPrefixToName("D-");

		for (auto& Pin : NewNode->CreateAllPinsIterator())
		{
			for (auto& LinkedTo : Pin.GetLinkedTo())
			{
				// From MUST be new pin
				OutLinksToCreate.Emplace(&Pin, LinkedTo);
			}
		}

		for (int Index = 0; Index < NewNode->GetNumPins(); Index++)
		{
			auto& NewPin = NewNode->GetPin(Index);
			auto& OldPin = Node->GetPin(Index);

			OldPinsToNewPins.Add(&OldPin, &NewPin);
		}

		NewNode->BreakAllLinks();
	}
	inline void DuplicateNodesAndLinkThemTogether(FVoxelGraphCompiler& Compiler, const TSet<FVoxelCompilationNode*>& Nodes, TMap<FVoxelCompilationPin*, FVoxelCompilationPin*>& OutOldPinsToNewPins)
	{
		TArray<FVoxelCompilationPinLink> LinksToCreate;

		// Duplicate all nodes
		for (auto& Node : Nodes)
		{
			DuplicateNodeAndQueueLinks(Compiler, Node, LinksToCreate, OutOldPinsToNewPins);
		}

		// Link them back together
		for (auto& LinkToCreate : LinksToCreate)
		{
			auto* From = LinkToCreate.From;
			auto* To = LinkToCreate.To;
			
			check(!OutOldPinsToNewPins.Contains(From));

			auto** NewTo = OutOldPinsToNewPins.Find(To);
			if (NewTo)
			{
				To = *NewTo;
			}

			if (!From->IsLinkedTo(To))
			{
				From->LinkTo(To);
			}
		}
	}

	inline void GetSortedExecNodesImpl(FVoxelCompilationNode* Node, TArray<FVoxelCompilationNode*>& Nodes, TSet<FVoxelCompilationNode*>& VisitedNodes)
	{
		if (!VisitedNodes.Contains(Node))
		{
			VisitedNodes.Add(Node);

			for (auto& Pin : Node->CreateOutputPinsIterator())
			{
				if (Pin->PinCategory == EVoxelPinCategory::Exec)
				{
					for (auto& LinkedToPin : Pin->GetLinkedTo())
					{
						GetSortedExecNodesImpl(LinkedToPin->Node, Nodes, VisitedNodes);
					}
				}
			}

			Nodes.Add(Node);
		}
	}
	inline void GetSortedExecNodes(FVoxelCompilationNode* FirstNode, TArray<FVoxelCompilationNode*>& OutNodes)
	{
		TSet<FVoxelCompilationNode*> VisitedNodes;
		GetSortedExecNodesImpl(FirstNode, OutNodes, VisitedNodes);
	}

	inline void GetAllSuccessors(FVoxelCompilationNode* Node, TSet<FVoxelCompilationNode*>& OutNodes)
	{
		if (OutNodes.Contains(Node))
		{
			return;
		}
		OutNodes.Add(Node);

		for (auto& Pin : Node->CreateOutputPinsIterator())
		{
			for (auto& LinkedToPin : Pin->GetLinkedTo())
			{
				GetAllSuccessors(LinkedToPin->Node, OutNodes);
			}
		}
	}

	inline void GetAllUsedNodes(FVoxelCompilationNode* Node, TSet<FVoxelCompilationNode*>& OutNodes)
	{
		if (OutNodes.Contains(Node))
		{
			return;
		}
		OutNodes.Add(Node);

		for (auto& Pin : Node->CreateInputPinsIterator())
		{
			if (Pin->PinCategory != EVoxelPinCategory::Exec)
			{
				for (auto& LinkedToPin : Pin->GetLinkedTo())
				{
					GetAllUsedNodes(LinkedToPin->Node, OutNodes);
				}
			}
		}
		for (auto& Pin : Node->CreateOutputPinsIterator())
		{
			if (Pin->PinCategory == EVoxelPinCategory::Exec)
			{
				for (auto& LinkedToPin : Pin->GetLinkedTo())
				{
					GetAllUsedNodes(LinkedToPin->Node, OutNodes);
				}
			}
		}
	}

	inline bool IsNodeExecNode(FVoxelCompilationNode* Node)
	{
		for (auto& Pin : Node->CreateAllPinsIterator())
		{
			if (Pin.PinCategory == EVoxelPinCategory::Exec)
			{
				return true;
			}
		}
		return false;
	}

	inline bool AreAllNodePredecessorsChildOfStartNodeExecOnly(FVoxelCompilationNode* Node, FVoxelCompilationNode* StartNode, FVoxelCompilationNode*& FaultyNode)
	{
		if (Node == StartNode)
		{
			return true;
		}

		bool bIsChild = false;

		for (auto& Pin : Node->CreateInputPinsIterator())
		{
			if (Pin->PinCategory == EVoxelPinCategory::Exec)
			{
				for (auto& LinkedToPin : Pin->GetLinkedTo())
				{
					if (AreAllNodePredecessorsChildOfStartNodeExecOnly(LinkedToPin->Node, StartNode, FaultyNode))
					{
						bIsChild = true;
					}
					else
					{
						return false;
					}
				}
			}
		}

		if (!bIsChild)
		{
			FaultyNode = Node;
		}

		return bIsChild;
	}
}

