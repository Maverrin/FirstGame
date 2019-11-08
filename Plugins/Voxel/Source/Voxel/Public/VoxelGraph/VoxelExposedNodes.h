// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelCppConstructor.h"
#include "VoxelGraph/VoxelNodeHelpers.h"
#include "VoxelWorldGeneratorPicker.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "VoxelWorldGenerators/VoxelFlatWorldGenerator.h"
#include "Curves/RichCurve.h"
#include "Curves/CurveFloat.h"
#include "Curves/CurveLinearColor.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelExposedNodes.generated.h"

#define LOCTEXT_NAMESPACE "VoxelExposedNodes"

UCLASS(abstract)
class VOXEL_API UVoxelExposedNode : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:	
	UPROPERTY(EditAnywhere, Category = "Parameter")
	FString UniqueName = "UniqueName";
	UPROPERTY(EditAnywhere, Category = "Parameter")
	FString Category;
	UPROPERTY(EditAnywhere, Category = "Parameter")
	int Priority;

#if WITH_EDITOR
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override
	{
		Super::PostEditChangeProperty(PropertyChangedEvent);

		if (PropertyChangedEvent.Property && PropertyChangedEvent.ChangeType != EPropertyChangeType::Interactive)
		{
			UniqueName = FVoxelVariable::SanitizeName(UniqueName);
		}
	}
#endif
};

// Float constant
UCLASS(meta = (DisplayName = "Constant (float)"))
class VOXEL_API UVoxelNode_FConstant : public UVoxelExposedNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	float Value;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	bool bExposeToBP;
	
	UVoxelNode_FConstant()
	{
		SetOutputs(EC::Float);
	}

	FText GetTitle() const override { return FText::FromString((bExposeToBP ? UniqueName.Replace(TEXT("_"), TEXT(" ")) + TEXT(" = ") : TEXT("")) + FString::SanitizeFloat(Value)); }
	FLinearColor GetColor()	const override { return bExposeToBP ? FLinearColor::Yellow : FLinearColor::Green; }

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_FConstant* Node, const FVoxelCompilationNode* CompilationNode)
			: FVoxelComputeNode(Node, CompilationNode)
			, Value(Node->Value)
			, bExposeToBP(Node->bExposeToBP)
			, Variable("float", Node->UniqueName, Node->Priority, FString::SanitizeFloat(Node->Value), Node, Node->Category)
		{
		}

		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override
		{
			Outputs[0]._float = Value;
		}
		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			if (bExposeToBP)
			{
				Constructor.AddLine(Outputs[0] + " = " + Variable.GetName() + ";");
			}
			else
			{
				Constructor.AddLine(Outputs[0] + " = " + FString::SanitizeFloat(Value) + ";");
			}
		}
		void SetupConstructor(FVoxelCppConstructor& Constructor) const override
		{
			if (bExposeToBP)
			{
				Constructor.AddExposedVariable(Variable);
			}
		}

	private:
		const float Value;
		const bool bExposeToBP;
		const FVoxelExposedVariable Variable;
	};
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// Int constant
UCLASS(meta = (DisplayName = "Constant (int)"))
class VOXEL_API UVoxelNode_IConstant : public UVoxelExposedNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	int32 Value;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	bool bExposeToBP;
	
	UVoxelNode_IConstant()
	{
		SetOutputs(EC::Int);
	}
	
	FText GetTitle() const override { return FText::FromString((bExposeToBP ? UniqueName.Replace(TEXT("_"), TEXT(" ")) + TEXT(" = ") : TEXT("")) + FString::FromInt(Value)); }
	FLinearColor GetColor()	const override { return bExposeToBP ? FLinearColor::Yellow : FLinearColor::Blue; }

#if WITH_EDITOR
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override
	{
		if (PropertyChangedEvent.Property && PropertyChangedEvent.ChangeType != EPropertyChangeType::Interactive)
		{
			UniqueName = FVoxelVariable::SanitizeName(UniqueName);
		}
	}
#endif
	
	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_IConstant* Node, const FVoxelCompilationNode* CompilationNode)
			: FVoxelComputeNode(Node, CompilationNode)
			, Value(Node->Value)
			, bExposeToBP(Node->bExposeToBP)
			, Variable("int", Node->UniqueName, Node->Priority, FString::FromInt(Node->Value), Node, Node->Category)
		{
		}

		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override
		{
			Outputs[0]._int = Value;
		}
		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			if (bExposeToBP)
			{
				Constructor.AddLine(Outputs[0] + " = " + Variable.GetName() + ";");
			}
			else
			{
				Constructor.AddLine(Outputs[0] + " = " + FString::FromInt(Value) + ";");
			}
		}
		void SetupConstructor(FVoxelCppConstructor& Constructor) const override
		{
			if (bExposeToBP)
			{
				Constructor.AddExposedVariable(Variable);
			}
		}

	private:
		const int32 Value;
		const bool bExposeToBP;
		const FVoxelExposedVariable Variable;
	};
};

// Sample another world generator. Expensive
UCLASS(meta = (DisplayName = "World Generator Sampler"))
class VOXEL_API UVoxelNode_WorldGeneratorSampler : public UVoxelExposedNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	FVoxelWorldGeneratorPicker WorldGenerator;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	TArray<FString> Seeds;

	UVoxelNode_WorldGeneratorSampler()
	{
		WorldGenerator.Type = EVoxelWorldGeneratorPickerType::Class;
		WorldGenerator.WorldGeneratorClass = UVoxelFlatWorldGenerator::StaticClass();
	}

	EVoxelPinCategory GetInputPinCategory(int32 PinIndex) const override { return PinIndex < 3 ? EC::Float : EC::Seed; }
	EVoxelPinCategory GetOutputPinCategory(int32 PinIndex) const override { return PinIndex == 0 ? EC::Float : EC::Material; }
	FText GetInputPinName(int32 PinIndex) const override
	{
		if (PinIndex == 0)
		{
			return LOCTEXT("X", "X");
		} else if (PinIndex == 1)
		{
			return LOCTEXT("Y", "Y");
		} else if (PinIndex == 2)
		{
			return LOCTEXT("Z", "Z");
		}
		else if(Seeds.IsValidIndex(PinIndex - 3))
		{
			return FText::FromString(Seeds[PinIndex - 3]);
		}
		else
		{
			return FText();
		}
	}
	FText GetOutputPinName(int32 PinIndex) const override { return PinIndex == 0 ? LOCTEXT("Value", "Value") : LOCTEXT("Material", "Material"); }
	int32 GetMinInputPins() const override { return 3 + Seeds.Num(); }
	int32 GetMaxInputPins() const override { return 3 + Seeds.Num(); }
	int32 GetOutputPinsCount() const override { return 2; }

	FText GetTitle() const override { return FText::FromString(WorldGenerator.GetName()); }

#if WITH_EDITOR
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override
	{
		Super::PostEditChangeProperty(PropertyChangedEvent);

		if (GraphNode && PropertyChangedEvent.Property && PropertyChangedEvent.ChangeType != EPropertyChangeType::Interactive)
		{
			InputPinCount = GetMinInputPins();

			GraphNode->ReconstructNode();
			if (Graph)
			{
				Graph->CompileVoxelNodesFromGraphNodes();
			}
		}
	}
#endif

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_WorldGeneratorSampler* Node, const FVoxelCompilationNode* CompilationNode)
			: FVoxelComputeNode(Node, CompilationNode)
			, WorldGenerator(Node->WorldGenerator.GetWorldGenerator())
			, SeedsNames(Node->Seeds)
			, Variable("TSharedRef<FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe>", Node->UniqueName, Node->Priority, "", Node, Node->Category, "FVoxelWorldGeneratorPicker", [](auto Name) { return Name + ".GetWorldGenerator()"; })
		{
		}
		
		void Init(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& InitStruct) override
		{
			FVoxelWorldGeneratorInit InitStructCopy = InitStruct;
			
			for (int I = 0; I < SeedsNames.Num(); I++)
			{
				InitStructCopy.Seeds.Add(SeedsNames[I], Inputs[I + 3]._int);
			}

			WorldGenerator->Init(InitStructCopy);
		}
		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override
		{
			FVoxelValue Value;
			FVoxelMaterial Material;
			WorldGenerator->GetValueAndMaterial(Inputs[0]._float, Inputs[1]._float, Inputs[2]._float, Value, Material);
			Outputs[0]._float = Value.ToFloat();
			Outputs[1]._FVoxelMaterial = Material;
		}

		void InitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine("{");
			Constructor.Indent();
			Constructor.AddLine("FVoxelWorldGeneratorInit InitCopy = " + Constructor.GetInitStructString() + ";");
			for (int I = 0; I < SeedsNames.Num(); I++)
			{
				Constructor.AddLine("InitCopy.Seeds.Add(\"" + SeedsNames[I] + "\"," + Inputs[I + 3] + ");");
			}
			Constructor.AddLine(Variable.GetName() + "->Init(InitCopy);");
			Constructor.Unindent();
			Constructor.AddLine("}");
		}
		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine("{");
			Constructor.Indent();
			Constructor.AddLine("FVoxelValue WorldGeneratorSamplerTmpValue;");
			Constructor.AddLine(Variable.GetName() + "->GetValueAndMaterial(" + Inputs[0] + ", " + Inputs[1] + ", " + Inputs[2] + ", " + "WorldGeneratorSamplerTmpValue" + ", " + Outputs[1] + ");");
			Constructor.AddLine(Outputs[0] + " = WorldGeneratorSamplerTmpValue.ToFloat();");
			Constructor.Unindent();
			Constructor.AddLine("}");
		}
		void SetupConstructor(FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddExposedVariable(Variable);
		}

	private:
		TSharedRef<FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> const WorldGenerator;
		const TArray<FString> SeedsNames;
		const FVoxelExposedVariable Variable;
	};
};

// Apply a float curve
UCLASS(meta = (DisplayName = "Curve"))
class VOXEL_API UVoxelNode_Curve : public UVoxelExposedNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	UCurveFloat* Curve;

	UVoxelNode_Curve()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}

	ENABLE_LOGERRORS(UVoxelNode_Curve)

	void LogErrors(FVoxelGraphCompiler& Compiler) const
	{
		if (!Curve)
		{
			Compiler.AddError("Invalid Curve in " + GetName());
			Compiler.AddErrorToNode(this, "invalid curve", EVoxelGraphNodeErrorType::Error);
		}
	}

	virtual FText GetTitle() const override
	{
		if (Curve)
		{
			return FText::FromString(Curve->GetName());
		}
		else
		{
			return LOCTEXT("Curve", "Curve");
		}
	}

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_Curve* Node, const FVoxelCompilationNode* CompilationNode)
			: FVoxelComputeNode(Node, CompilationNode)
			, Curve(Node->Curve->FloatCurve)
			, Variable("FRichCurve", Node->UniqueName, Node->Priority, "", Node, Node->Category, "UCurveFloat*", [=](FString InName) { return "(" + InName + " ? " + InName + "->FloatCurve : FRichCurve())"; })
		{
		}
		
		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override
		{
			Outputs[0]._float = Curve.Eval(Inputs[0]._float);
		}

		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(Outputs[0] + " = " + Variable.GetName() + ".Eval(" + Inputs[0] + ");");
		}
		void SetupConstructor(FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddExposedVariable(Variable);
			Constructor.AddInclude("Curves/RichCurve.h");
			Constructor.AddInclude("Curves/CurveFloat.h");
		}

	private:
		FRichCurve const Curve;
		const TArray<FString> SeedsNames;
		const FVoxelExposedVariable Variable;
	};
};

// Apply a color curve
UCLASS(meta = (DisplayName = "Curve Color"))
class VOXEL_API UVoxelNode_CurveColor : public UVoxelExposedNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	UCurveLinearColor* Curve;

	UVoxelNode_CurveColor()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float, EC::Float, EC::Float, EC::Float, "R", "G", "B", "A");
	}

	ENABLE_LOGERRORS(UVoxelNode_CurveColor)

	void LogErrors(FVoxelGraphCompiler& Compiler) const
	{
		if (!Curve)
		{
			Compiler.AddError("Invalid Curve in " + GetName());
			Compiler.AddErrorToNode(this, "invalid curve", EVoxelGraphNodeErrorType::Error);
		}
	}

	virtual FText GetTitle() const override
	{
		if (Curve)
		{
			return FText::FromString(Curve->GetName());
		}
		else
		{
			return LOCTEXT("CurveColor", "Curve Color");
		}
	}

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_CurveColor* Node, const FVoxelCompilationNode* CompilationNode)
			: FVoxelComputeNode(Node, CompilationNode)
		{
			for (int I = 0; I < 4; I++)
			{
				Curves[I] = Node->Curve->FloatCurves[I];
			}
		}
		
		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override
		{
			Outputs[0]._float = Curves[0].Eval(Inputs[0]._float);
			Outputs[1]._float = Curves[1].Eval(Inputs[0]._float);
			Outputs[2]._float = Curves[2].Eval(Inputs[0]._float);
			Outputs[3]._float = Curves[3].Eval(Inputs[0]._float);
		}

		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{

		}
		void SetupConstructor(FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddError("Color curves are not supported in C++ for now");
			Constructor.AddInclude("Curves/RichCurve.h");
		}

	private:
		FRichCurve Curves[4];
		const TArray<FString> SeedsNames;
		const FVoxelExposedVariable Variable;
	};
};
#undef LOCTEXT_NAMESPACE
