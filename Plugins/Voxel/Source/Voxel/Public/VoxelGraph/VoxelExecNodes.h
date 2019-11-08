// Copyright 2018 Phyronnaz

#pragma once


#include "CoreMinimal.h"
#include "VoxelGraph/VoxelNodeHelpers.h"
#include "VoxelGraph/VoxelBaseNodes.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelGraph/VoxelCompilationNode.h"
#include "VoxelExecNodes.generated.h"

#define LOCTEXT_NAMESPACE "VoxelNodes"

// Branch node
UCLASS(meta = (DisplayName = "If", Keywords = "branch"))
class VOXEL_API UVoxelNode_If : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()
public:
	UVoxelNode_If()
	{
		SetInputs(EC::Exec,	EC::Boolean);
		SetOutputs(EC::Exec, "True",
			       EC::Exec, "False");
		SetColor(FLinearColor::Red);
	}

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
		using FVoxelComputeNode::FVoxelComputeNode;
		int32 ComputeExecNode(FVoxelNodeType Inputs[], float& Value, FVoxelMaterial& Material) const override
		{
			return Inputs[0]._bool ? 0 : 1;
		}
		EExecKind ComputeExecNodeCpp(const TArray<FString>& Inputs, FString& BranchResult, FVoxelCppConstructor& Constructor) const override
		{
			BranchResult = Inputs[0];
			return EExecKind::If;
		}
	};
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// Set the density at that position
UCLASS(meta = (DisplayName = "Set Value", Keywords = "density"))
class VOXEL_API UVoxelNode_SetValue : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	bool bDisableClamp;

	UVoxelNode_SetValue()
	{
		SetInputs( EC::Exec , "",
			       EC::Float, "");
		SetOutputs(EC::Exec , "");
		SetColor(FLinearColor::Red);
	}

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_SetValue* Node, const FVoxelCompilationNode* CompilationNode) : FVoxelComputeNode(Node, CompilationNode), bDisableClamp(Node->bDisableClamp) {}
		FLocalVoxelComputeNode(const FVoxelCompilationNode* CompilationNode) : FVoxelComputeNode(nullptr, CompilationNode), bDisableClamp(true) {}

		int32 ComputeExecNode(FVoxelNodeType Inputs[], float& Value, FVoxelMaterial& Material) const override
		{
			Value = bDisableClamp ? Inputs[0]._float : FMath::Clamp(Inputs[0]._float, -1.f, 1.f);
			return 0;
		}
		EExecKind ComputeExecNodeCpp(const TArray<FString>& Inputs, FString& BranchResult, FVoxelCppConstructor& Constructor) const override
		{
			if (bDisableClamp)
			{
				Constructor.AddLine(Constructor.GetValueString() + " = " + Inputs[0] + ";");
			}
			else
			{
				Constructor.AddLine(Constructor.GetValueString() + " = FMath::Clamp<float>(" + Inputs[0] + ", -1.f, 1.f);");
			}
			return EExecKind::Passthrough;
		}

	private:
		const bool bDisableClamp;
	};
};

class FVoxelPreviewSetValueCompilationNode : public FVoxelCompilationNode
{
public:
	using FVoxelCompilationNode::FVoxelCompilationNode;

	FVoxelPreviewSetValueCompilationNode(FVoxelCompilationNode* InputNode, int PinIndex)
		: FVoxelCompilationNode(TEXT("SetValuePreview"), { EC::Exec, EC::Float }, { EC::Exec })
	{
		auto& Pin = InputNode->GetOutputPin(PinIndex);
		check(Pin.PinCategory == EC::Float);
		GetInputPin(1).LinkTo(&Pin);
	}

	virtual TSharedPtr<FVoxelComputeNode> GetComputeNode() const override
	{
		return MakeShared<UVoxelNode_SetValue::FLocalVoxelComputeNode>(this);
	}	
	virtual TSharedPtr<FVoxelCompilationNode> Clone(bool bFixLinks) const override
	{
		return CloneInternalDefault<FVoxelPreviewSetValueCompilationNode>(bFixLinks);
	}
	virtual EVoxelCompilationNodeType GetType() const override
	{
		return EVoxelCompilationNodeType::Default;
	}

};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// Set the color at that position. Inputs between 0 and 1
UCLASS(meta = (DisplayName = "Set Color"))
class VOXEL_API UVoxelNode_SetColor : public UVoxelMaterialNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()
public:
	UVoxelNode_SetColor()
	{
		SetInputs(EC::Exec, "",
			      EC::Float, "R",
			      EC::Float, "G",
			      EC::Float, "B",
			      EC::Float, "A");
		SetOutputs(EC::Exec);
		SetBounds(TOptional<float>(), TOptional<float>(),
			      0, 1,
			      0, 1,
			      0, 1,
			      0, 1);
	}

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		using FVoxelComputeNode::FVoxelComputeNode;

		int32 ComputeExecNode(FVoxelNodeType Inputs[], float& Value, FVoxelMaterial& Material) const override
		{
			Material.SetColor(FLinearColor(Inputs[0]._float, Inputs[1]._float, Inputs[2]._float, Inputs[3]._float));
			return 0;
		}
		EExecKind ComputeExecNodeCpp(const TArray<FString>& Inputs, FString& BranchResult, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(Constructor.GetMaterialString() + ".SetColor(FLinearColor(" + Inputs[0] + ", " + Inputs[1] + ", " + Inputs[2] + ", " + Inputs[3] + "));");
			return EExecKind::Passthrough;
		}
	};
};

//////////////////////////////////////////////////////////////////////////////////////

UCLASS(meta = (DisplayName = "Set Double Index"))
class VOXEL_API UVoxelNode_SetDoubleIndex : public UVoxelMaterialNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()
public:
	UVoxelNode_SetDoubleIndex()
	{
		SetInputs(EC::Exec, "",
			      EC::Int, "Index A",
			      EC::Int, "Index B",
			      EC::Float, "Blend");
		SetOutputs(EC::Exec);
		SetBounds(TOptional<float>(), TOptional<float>(),
			      0, 255,
			      0, 255,
			      0, 1);
	}

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		using FVoxelComputeNode::FVoxelComputeNode;

		int32 ComputeExecNode(FVoxelNodeType Inputs[], float& Value, FVoxelMaterial& Material) const override
		{
			Material.SetIndexA(Inputs[0]._int);
			Material.SetIndexB(Inputs[1]._int);
			Material.SetBlend(FMath::Clamp(FMath::FloorToInt(Inputs[2]._float * 255.999f), 0, 255));
			return 0;
		}
		EExecKind ComputeExecNodeCpp(const TArray<FString>& Inputs, FString& BranchResult, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(Constructor.GetMaterialString() + ".SetIndexA(" + Inputs[0] + ");");
			Constructor.AddLine(Constructor.GetMaterialString() + ".SetIndexB(" + Inputs[1] + ");");
			Constructor.AddLine(Constructor.GetMaterialString() + ".SetBlend(FMath::Clamp(FMath::FloorToInt(" + Inputs[2] + " * 255.999f), 0, 255));");
			return EExecKind::Passthrough;
		}
	};
};

//////////////////////////////////////////////////////////////////////////////////////

// Set the Voxel Spawned Actor Id at that position
UCLASS(meta = (DisplayName = "Set Voxel Actor Id"))
class VOXEL_API UVoxelNode_SetVoxelSpawnedActorId : public UVoxelMaterialNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_SetVoxelSpawnedActorId()
	{
		SetInputs(EC::Exec, EC::Int);
		SetOutputs(EC::Exec);
		SetBounds(TOptional<float>(), TOptional<float>(), 0, 255);
	}

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		using FVoxelComputeNode::FVoxelComputeNode;

		int32 ComputeExecNode(FVoxelNodeType Inputs[], float& Value, FVoxelMaterial& Material) const override
		{
#if ENABLE_VOXELACTORS
			Material.SetVoxelActorId(FMath::Clamp(Inputs[0]._int, 0, 255));
#endif
			return 0;
		}
		EExecKind ComputeExecNodeCpp(const TArray<FString>& Inputs, FString& BranchResult, FVoxelCppConstructor& Constructor) const override
		{
#if ENABLE_VOXELACTORS
			Constructor.AddLine(Constructor.GetMaterialString() + ".SetVoxelActorId(FMath::Clamp(" + Inputs[0] + ", 0, 255));");
#endif
			return EExecKind::Passthrough;
		}
	};
};

//////////////////////////////////////////////////////////////////////////////////////

// Set the Voxel Grass Id at that position
UCLASS(meta = (DisplayName = "Set Voxel Grass Id"))
class VOXEL_API UVoxelNode_SetVoxelGrassId : public UVoxelMaterialNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_SetVoxelGrassId()
	{
		SetInputs(EC::Exec,	EC::Int);
		SetOutputs(EC::Exec);
		SetBounds(TOptional<float>(), TOptional<float>(), 0, 255);
	}

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		using FVoxelComputeNode::FVoxelComputeNode;

		int32 ComputeExecNode(FVoxelNodeType Inputs[], float& Value, FVoxelMaterial& Material) const override
		{
#if ENABLE_VOXELGRASS
			Material.SetVoxelGrassId(FMath::Clamp(Inputs[0]._int, 0, 255));
#endif
			return 0;
		}
		EExecKind ComputeExecNodeCpp(const TArray<FString>& Inputs, FString& BranchResult, FVoxelCppConstructor& Constructor) const override
		{
#if ENABLE_VOXELGRASS
			Constructor.AddLine(Constructor.GetMaterialString() + ".SetVoxelGrassId(FMath::Clamp(" + Inputs[0] + ", 0, 255));");
#endif
			return EExecKind::Passthrough;
		}
	};
};

//////////////////////////////////////////////////////////////////////////////////////

// Set the material index at that position. Input clamped between 0 and 255
UCLASS(meta = (DisplayName = "Set Index"))
class VOXEL_API UVoxelNode_SetIndex : public UVoxelMaterialNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_SetIndex()
	{
		SetInputs(EC::Exec,	EC::Int);
		SetOutputs(EC::Exec);
		SetBounds(TOptional<float>(), TOptional<float>(), 0, 255);
	}

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		using FVoxelComputeNode::FVoxelComputeNode;

		int32 ComputeExecNode(FVoxelNodeType Inputs[], float& Value, FVoxelMaterial& Material) const override
		{
			Material.SetIndex(FMath::Clamp(Inputs[0]._int, 0, 255));
			return 0;
		}
		EExecKind ComputeExecNodeCpp(const TArray<FString>& Inputs, FString& BranchResult, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(Constructor.GetMaterialString() + ".SetIndex(FMath::Clamp(" + Inputs[0] + ", 0, 255));");
			return EExecKind::Passthrough;
		}
	};
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

UCLASS(meta = (DisplayName = "Flow Merge"))
class VOXEL_API UVoxelNode_FlowMerge : public UVoxelNodeHelper
{
	GENERATED_BODY()

public:
	UVoxelNode_FlowMerge()
	{
		SetInputs(EC::Exec,	EC::Float, EC::Exec, EC::Float, "Exec A", "Value A", "Exec B", "Value B");
		SetOutputs(EC::Exec, EC::Float);
		SetColor(FLinearColor::White);
	}

	virtual TSharedPtr<FVoxelCompilationNode> GetCompilationNode() const override
	{
		return MakeShared<FLocalCompilationNode>(this);
	}

	class FLocalCompilationNode : public FVoxelCompilationNode
	{
	public:
		using FVoxelCompilationNode::FVoxelCompilationNode;

		FLocalCompilationNode(const UVoxelNode_FlowMerge* Node)
			: FVoxelCompilationNode(Node->GetName(), { EC::Exec,	EC::Float, EC::Exec, EC::Float }, { EC::Exec, EC::Float })
		{
		}

		virtual TSharedPtr<FVoxelCompilationNode> Clone(bool bFixLinks) const override
		{
			return CloneInternalDefault<FLocalCompilationNode>(bFixLinks);
		}
		virtual EVoxelCompilationNodeType GetType() const override { return EVoxelCompilationNodeType::FlowMerge; }
	};
};

#undef LOCTEXT_NAMESPACE
