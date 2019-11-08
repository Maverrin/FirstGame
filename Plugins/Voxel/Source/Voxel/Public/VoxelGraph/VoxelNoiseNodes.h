// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelNode.h"
#include "FastNoise.h"
#include "VoxelGraph/VoxelCppConstructor.h"
#include "VoxelGraph/VoxelNodeHelpers.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelGraph/VoxelCompilationNode.h"
#include "VoxelNoiseNodes.generated.h"

#define LOCTEXT_NAMESPACE "VoxelNoiseNodes"

UENUM(BlueprintType)
enum class EFractalType : uint8
{
	FBM,
	Billow,
	RigidMulti
};

UENUM(BlueprintType)
enum class EInterp : uint8
{
	Linear,
	Hermite,
	Quintic
};

UENUM(BlueprintType)
enum class ECellularDistanceFunction : uint8
{
	Euclidean,
	Manhattan,
	Natural
};

UENUM(BlueprintType)
enum class ECellularReturnType : uint8
{
	CellValue,
	NoiseLookup UMETA(Hidden),
	Distance, 
	Distance2, 
	Distance2Add, 
	Distance2Sub, 
	Distance2Mul,
	Distance2Div
};

FString GetFastNoiseNameFromEInterp(EInterp Interpolation)
{
	switch (Interpolation)
	{
	case EInterp::Linear:
		return "FastNoise::Interp::Linear";
	case EInterp::Hermite:
		return "FastNoise::Interp::Hermite";
	case EInterp::Quintic:
		return "FastNoise::Interp::Quintic";
	default:
		check(false);
		return "";
	}
}

FString GetFastNoiseNameFromEFactalType(EFractalType FractalType)
{
	switch (FractalType)
	{
	case EFractalType::FBM:
		return "FastNoise::FractalType::FBM";
	case EFractalType::Billow:
		return "FastNoise::FractalType::Billow";
	case EFractalType::RigidMulti:
		return "FastNoise::FractalType::RigidMulti";
	default:
		check(false);
		return "";
	}
}

FString GetFastNoiseNameFromECellularDistanceFunction(ECellularDistanceFunction DistanceFunction)
{
	switch (DistanceFunction)
	{
	case ECellularDistanceFunction::Euclidean:
		return "FastNoise::CellularDistanceFunction::Euclidean";
	case ECellularDistanceFunction::Manhattan:
		return "FastNoise::CellularDistanceFunction::Manhattan";
	case ECellularDistanceFunction::Natural:
		return "FastNoise::CellularDistanceFunction::Natural";
	default:
		check(false);
		return "";
	}
}

FString GetFastNoiseNameFromECellularReturnType(ECellularReturnType ReturnType)
{
	switch (ReturnType)
	{
	case ECellularReturnType::CellValue:
		return "FastNoise::CellularReturnType::CellValue";
	case ECellularReturnType::NoiseLookup:
		return "FastNoise::CellularReturnType::NoiseLookup";
	case ECellularReturnType::Distance:
		return "FastNoise::CellularReturnType::Distance";
	case ECellularReturnType::Distance2:
		return "FastNoise::CellularReturnType::Distance2";
	case ECellularReturnType::Distance2Add:
		return "FastNoise::CellularReturnType::Distance2Add";
	case ECellularReturnType::Distance2Sub:
		return "FastNoise::CellularReturnType::Distance2Sub";
	case ECellularReturnType::Distance2Mul:
		return "FastNoise::CellularReturnType::Distance2Mul";
	case ECellularReturnType::Distance2Div:
		return "FastNoise::CellularReturnType::Distance2Div";
	default:
		check(false);
		return "";
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

UCLASS(abstract)
class VOXEL_API UVoxelNode_NoiseNode : public UVoxelNode
{
	GENERATED_BODY()

public:
	// Outdated, use frequency instead
	UPROPERTY()
	float Scale_DEPRECATED = 1;

	UPROPERTY(EditAnywhere, Category = "Voxel", meta = (UIMin = 0))
	float Frequency = 0.02;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	EInterp Interpolation = EInterp::Quintic;

	FText GetInputPinName(int32 PinIndex) const override
	{
		if (GetInputPinsCount() == 3)
		{
			if (PinIndex == 0)
			{
				return LOCTEXT("X", "X");
			}
			else if (PinIndex == 1)
			{
				return LOCTEXT("Y", "Y");
			}
			else if (PinIndex == 2)
			{
				return LOCTEXT("Seed", "Seed");
			}
			else
			{
				return LOCTEXT("", "");
			}
		}
		else
		{
			if (PinIndex == 0)
			{
				return LOCTEXT("X", "X");
			}
			else if (PinIndex == 1)
			{
				return LOCTEXT("Y", "Y");
			}
			else if (PinIndex == 2)
			{
				return LOCTEXT("Z", "Z");
			}
			else if (PinIndex == 3)
			{
				return LOCTEXT("Seed", "Seed");
			}
			else
			{
				return LOCTEXT("", "");
			}
		}
	}

	virtual void PostLoad() override
	{
		Super::PostLoad();
		if (Scale_DEPRECATED != 1)
		{
			Frequency = Frequency / Scale_DEPRECATED;
			Scale_DEPRECATED = 1;
		}
	}
	
	template<typename TFunction, int TDimension>
	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_NoiseNode* Node, const FVoxelCompilationNode* CompilationNode)
			: FVoxelComputeNode(Node, CompilationNode)
			, Frequency(Node->Frequency)
			, Interpolation(Node->Interpolation)
			, NoiseVariable(FVoxelVariable("FastNoise", CompilationNode->GetName() + "_Noise"))
		{
			check(TDimension == InputCount - 1);
		}

		void Init(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& InitStruct) override
		{
			Noise.SetSeed(Inputs[TDimension]._Seed);
			Noise.SetFrequency(Frequency);
			Noise.SetInterp((FastNoise::Interp)Interpolation);
		}
		void InitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(NoiseVariable.GetName() + ".SetSeed(" + Inputs[TDimension] + ");");
			Constructor.AddLine(NoiseVariable.GetName() + ".SetFrequency(" + FString::SanitizeFloat(Frequency) + ");");
			Constructor.AddLine(NoiseVariable.GetName() + ".SetInterp(" + GetFastNoiseNameFromEInterp(Interpolation) + ");");
		}
		
		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override
		{
			if (TDimension == 2)
			{
				Outputs[0]._float = TFunction::Apply(Noise, Inputs[0]._float, Inputs[1]._float);
			}
			else
			{
				Outputs[0]._float = TFunction::Apply(Noise, Inputs[0]._float, Inputs[1]._float, Inputs[2]._float);
			}
		}		

		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			FString Line;
			Line += Outputs[0] + " = ";
			Line += NoiseVariable.GetName() + "." + GetFunctionName();
			if (TDimension == 2)
			{
				Line += "(" + Inputs[0] + ", " + Inputs[1] + ");";
			}
			else
			{
				Line += "(" + Inputs[0] + ", " + Inputs[1] + +", " + Inputs[2] + ");";
			}
			Constructor.AddLine(Line);
		}

		void SetupConstructor(FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddInclude("FastNoise.h");
			Constructor.AddPrivateVariable(NoiseVariable);
		}

		virtual FString GetFunctionName() const { return ""; }

	protected:
		const float Frequency;
		const EInterp Interpolation;
		FVoxelVariable const NoiseVariable;
		FastNoise Noise;
	};
};

//////////////////////////////////////////////////////////////////////////////////////

UCLASS(abstract)
class VOXEL_API UVoxelNode_NoiseNodeFractal : public UVoxelNode_NoiseNode
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Voxel", meta = (UIMin = 1, ClampMin = 1))
	int FractalOctaves = 3;

	// A multiplier that determines how quickly the frequency increases for each successive octave
	// The frequency of each successive octave is equal to the product of the previous octave's frequency and the lacunarity value.
	UPROPERTY(EditAnywhere, Category = "Voxel")
	float FractalLacunarity = 2;

	// A multiplier that determines how quickly the amplitudes diminish for each successive octave
	// The amplitude of each successive octave is equal to the product of the previous octave's amplitude and the gain value. Increasing the gain produces "rougher" Perlin noise.
	UPROPERTY(EditAnywhere, Category = "Voxel")
	float FractalGain = 0.5;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	EFractalType FractalType = EFractalType::FBM;

	template<typename TFunction, int TDimension>
	class FLocalVoxelComputeNode : public UVoxelNode_NoiseNode::FLocalVoxelComputeNode<TFunction, TDimension>
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_NoiseNodeFractal* Node, const FVoxelCompilationNode* CompilationNode)
			: UVoxelNode_NoiseNode::FLocalVoxelComputeNode<TFunction, TDimension>(Node, CompilationNode)
			, FractalOctaves(Node->FractalOctaves)
			, FractalLacunarity(Node->FractalLacunarity)
			, FractalGain(Node->FractalGain)
			, FractalType(Node->FractalType)
		{
		}
		void Init(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& InitStruct) override
		{
			UVoxelNode_NoiseNode::FLocalVoxelComputeNode<TFunction, TDimension>::Init(Inputs, Outputs, InitStruct);

			this->Noise.SetFractalOctaves(FractalOctaves);
			this->Noise.SetFractalLacunarity(FractalLacunarity);
			this->Noise.SetFractalGain(FractalGain);
			this->Noise.SetFractalType((FastNoise::FractalType)FractalType);
		}
		void InitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			UVoxelNode_NoiseNode::FLocalVoxelComputeNode<TFunction, TDimension>::InitCpp(Inputs, Outputs, Constructor);

			Constructor.AddLine(this->NoiseVariable.GetName() + ".SetFractalOctaves(" + FString::FromInt(FractalOctaves) + ");");
			Constructor.AddLine(this->NoiseVariable.GetName() + ".SetFractalLacunarity(" + FString::SanitizeFloat(FractalLacunarity) + ");");
			Constructor.AddLine(this->NoiseVariable.GetName() + ".SetFractalGain(" + FString::SanitizeFloat(FractalGain) + ");");
			Constructor.AddLine(this->NoiseVariable.GetName() + ".SetFractalType(" + GetFastNoiseNameFromEFactalType(FractalType) + ");");
		}

	protected:
		const int FractalOctaves;
		const float FractalLacunarity;
		const float FractalGain;
		const EFractalType FractalType;
	};
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

#define GENERATED_NOISE_COMPUTENODE(Dimension, FunctionName, Parent) \
class FLocalVoxelComputeNode : public Parent::FLocalVoxelComputeNode<FLocalVoxelComputeNode, Dimension> \
{ \
public: \
	using Parent::FLocalVoxelComputeNode<FLocalVoxelComputeNode, Dimension>::FLocalVoxelComputeNode; \
	FString GetFunctionName() const override { return #FunctionName; } \
	inline static float Apply(const FastNoise& Noise, float X, float Y) { return Noise.FunctionName(X, Y); } \
	inline static float Apply(const FastNoise& Noise, float X, float Y, float Z) { return Noise.FunctionName(X, Y, Z); } \
};

#define GENERATED_NOISENODE_BODY_BASIC(Inputs, Outputs) \
public: \
GENERATED_VOXELNODE_BODY() \
int32 GetMinInputPins() const override { return Inputs + 1; } \
int32 GetMaxInputPins() const override { return Inputs + 1; } \
int32 GetOutputPinsCount() const override { return Outputs; } \
EVoxelPinCategory GetInputPinCategory(int32 PinIndex) const override { return PinIndex == Inputs ? EVoxelPinCategory::Seed : EVoxelPinCategory::Float; }

#define GENERATED_NOISENODE_BODY(Dimension, FunctionName) \
GENERATED_NOISENODE_BODY_BASIC(Dimension, 1) \
GENERATED_NOISE_COMPUTENODE(Dimension, FunctionName, UVoxelNode_NoiseNode)

#define GENERATED_NOISENODE_BODY_FRACTAL(Dimension, FunctionName) \
GENERATED_NOISENODE_BODY_BASIC(Dimension, 1) \
GENERATED_NOISE_COMPUTENODE(Dimension, FunctionName, UVoxelNode_NoiseNodeFractal)

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// 2D Value Noise
UCLASS(meta = (DisplayName = "2D Value Noise"))
class VOXEL_API UVoxelNode_2DValueNoise : public UVoxelNode_NoiseNode
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY(2, GetValue)
};

// 2D Value Noise Fractal
UCLASS(meta = (DisplayName = "2D Value Noise Fractal"))
class VOXEL_API UVoxelNode_2DValueNoiseFractal : public UVoxelNode_NoiseNodeFractal
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_FRACTAL(2, GetValueFractal)
};

//////////////////////////////////////////////////////////////////////////////////////

// 2D Perlin NOise
UCLASS(meta = (DisplayName = "2D Perlin Noise"))
class VOXEL_API UVoxelNode_2DPerlinNoise : public UVoxelNode_NoiseNode
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY(2, GetPerlin)
};

UCLASS(meta = (DisplayName = "2D Perlin Noise Fractal"))
class VOXEL_API UVoxelNode_2DPerlinNoiseFractal : public UVoxelNode_NoiseNodeFractal
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_FRACTAL(2, GetPerlinFractal)
};

//////////////////////////////////////////////////////////////////////////////////////

// 2D Simplex Noise
UCLASS(meta = (DisplayName = "2D Simplex Noise"))
class VOXEL_API UVoxelNode_2DSimplexNoise : public UVoxelNode_NoiseNode
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY(2, GetSimplex)
};

// 2D Simplex Noise Fractal
UCLASS(meta = (DisplayName = "2D Simplex Noise Fractal"))
class VOXEL_API UVoxelNode_2DSimplexNoiseFractal : public UVoxelNode_NoiseNodeFractal
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_FRACTAL(2, GetSimplexFractal)
};

//////////////////////////////////////////////////////////////////////////////////////

// 2D Cubic Noise
UCLASS(meta = (DisplayName = "2D Cubic Noise"))
class VOXEL_API UVoxelNode_2DCubicNoise : public UVoxelNode_NoiseNode
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY(2, GetCubic)
};

// 2D Cubic Noise Fractal
UCLASS(meta = (DisplayName = "2D Cubic Noise Fractal"))
class VOXEL_API UVoxelNode_2DCubicNoiseFractal : public UVoxelNode_NoiseNodeFractal
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_FRACTAL(2, GetCubicFractal)
};

//////////////////////////////////////////////////////////////////////////////////////

// 2D White Noise
UCLASS(meta = (DisplayName = "2D White Noise"))
class VOXEL_API UVoxelNode_2DWhiteNoise : public UVoxelNode_NoiseNode
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY(2, GetWhiteNoise)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// 3D Value Noise
UCLASS(meta = (DisplayName = "3D Value Noise"))
class VOXEL_API UVoxelNode_3DValueNoise : public UVoxelNode_NoiseNode
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY(3, GetValue)
};

// 3D Value Noise Fractal
UCLASS(meta = (DisplayName = "3D Value Noise Fractal"))
class VOXEL_API UVoxelNode_3DValueNoiseFractal : public UVoxelNode_NoiseNodeFractal
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_FRACTAL(3, GetValueFractal)
};

//////////////////////////////////////////////////////////////////////////////////////

// 3D Perlin Noise
UCLASS(meta = (DisplayName = "3D Perlin Noise"))
class VOXEL_API UVoxelNode_3DPerlinNoise : public UVoxelNode_NoiseNode
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY(3, GetPerlin)
};

// 3D Perlin Noise Fractal
UCLASS(meta = (DisplayName = "3D Perlin Noise Fractal"))
class VOXEL_API UVoxelNode_3DPerlinNoiseFractal : public UVoxelNode_NoiseNodeFractal
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_FRACTAL(3, GetPerlinFractal)
};

//////////////////////////////////////////////////////////////////////////////////////

// 3D Simplex Noise
UCLASS(meta = (DisplayName = "3D Simplex Noise"))
class VOXEL_API UVoxelNode_3DSimplexNoise : public UVoxelNode_NoiseNode
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY(3, GetSimplex)
};

// 3D Simplex Noise Fractal
UCLASS(meta = (DisplayName = "3D Simplex Noise Fractal"))
class VOXEL_API UVoxelNode_3DSimplexNoiseFractal : public UVoxelNode_NoiseNodeFractal
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_FRACTAL(3, GetSimplexFractal)
};

//////////////////////////////////////////////////////////////////////////////////////

// 3D Cubic Noise
UCLASS(meta = (DisplayName = "3D Cubic Noise"))
class VOXEL_API UVoxelNode_3DCubicNoise : public UVoxelNode_NoiseNode
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY(3, GetCubic)
};

// 3D Cubic Noise Fractal
UCLASS(meta = (DisplayName = "3D Cubic Noise Fractal"))
class VOXEL_API UVoxelNode_3DCubicNoiseFractal : public UVoxelNode_NoiseNodeFractal
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_FRACTAL(3, GetCubicFractal)
};

//////////////////////////////////////////////////////////////////////////////////////

// 3D White Noise
UCLASS(meta = (DisplayName = "3D White Noise"))
class VOXEL_API UVoxelNode_3DWhiteNoise : public UVoxelNode_NoiseNode
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY(3, GetWhiteNoise)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

UCLASS(abstract)
class VOXEL_API UVoxelNode_CellularNoise : public UVoxelNode_NoiseNode
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
		ECellularDistanceFunction DistanceFunction;

	UPROPERTY(EditAnywhere, Category = "Voxel")
		ECellularReturnType ReturnType;

	UPROPERTY(EditAnywhere, Category = "Voxel")
		float Jitter = 0.45;

	template<typename TFunction, int TDimension>
	class FLocalVoxelComputeNode : public UVoxelNode_NoiseNode::FLocalVoxelComputeNode<TFunction, TDimension>
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_CellularNoise* Node, const FVoxelCompilationNode* CompilationNode)
			: UVoxelNode_NoiseNode::FLocalVoxelComputeNode<TFunction, TDimension>(Node, CompilationNode)
			, DistanceFunction(Node->DistanceFunction)
			, ReturnType(Node->ReturnType)
			, Jitter(Node->Jitter)
		{
		}

		void Init(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& InitStruct) override
		{
			UVoxelNode_NoiseNode::FLocalVoxelComputeNode<TFunction, TDimension>::Init(Inputs, Outputs, InitStruct);

			this->Noise.SetCellularJitter(Jitter);
			this->Noise.SetCellularDistanceFunction((FastNoise::CellularDistanceFunction)DistanceFunction);
			this->Noise.SetCellularReturnType((FastNoise::CellularReturnType)ReturnType);
		}
		void InitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			UVoxelNode_NoiseNode::FLocalVoxelComputeNode<TFunction, TDimension>::InitCpp(Inputs, Outputs, Constructor);

			Constructor.AddLine(this->NoiseVariable.GetName() + ".SetCellularJitter(" + FString::SanitizeFloat(Jitter) + ");");
			Constructor.AddLine(this->NoiseVariable.GetName() + ".SetCellularDistanceFunction(" + GetFastNoiseNameFromECellularDistanceFunction(DistanceFunction) + ");");
			Constructor.AddLine(this->NoiseVariable.GetName() + ".SetCellularReturnType((FastNoise::CellularReturnType)" + GetFastNoiseNameFromECellularReturnType(ReturnType) + ");");
		}

	protected:
		const ECellularDistanceFunction DistanceFunction;
		const ECellularReturnType ReturnType;
		const float Jitter;
	};
};

// 2D Cellular Noise
UCLASS(meta = (DisplayName = "2D Cellular Noise"))
class VOXEL_API UVoxelNode_2DCellularNoise : public UVoxelNode_CellularNoise
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_BASIC(2, 1)
	GENERATED_NOISE_COMPUTENODE(2, GetCellular, UVoxelNode_CellularNoise)
};

// 3D Cellular Noise
UCLASS(meta = (DisplayName = "3D Cellular Noise"))
class VOXEL_API UVoxelNode_3DCellularNoise : public UVoxelNode_CellularNoise
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_BASIC(3, 1)
	GENERATED_NOISE_COMPUTENODE(3, GetCellular, UVoxelNode_CellularNoise)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

UCLASS(abstract)
class VOXEL_API UVoxelNode_GradientPerturb : public UVoxelNode_NoiseNode
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	float GradientPerturbAmplitude = 1;
	
	template<typename TFunction, int TDimension>
	class FLocalVoxelComputeNode : public UVoxelNode_NoiseNode::FLocalVoxelComputeNode<TFunction, TDimension>
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_GradientPerturb* Node, const FVoxelCompilationNode* CompilationNode)
			: UVoxelNode_NoiseNode::FLocalVoxelComputeNode<TFunction, TDimension>(Node, CompilationNode)
			, GradientPerturbAmplitude(Node->GradientPerturbAmplitude)
		{
		}
		void Init(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& InitStruct) override
		{
			UVoxelNode_NoiseNode::FLocalVoxelComputeNode<TFunction, TDimension>::Init(Inputs, Outputs, InitStruct);
			this->Noise.SetGradientPerturbAmp(GradientPerturbAmplitude);
		}
		void InitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			UVoxelNode_NoiseNode::FLocalVoxelComputeNode<TFunction, TDimension>::InitCpp(Inputs, Outputs, Constructor);
			Constructor.AddLine(this->NoiseVariable.GetName() + ".SetGradientPerturbAmp(" + FString::SanitizeFloat(GradientPerturbAmplitude) + ");");
		}

	protected:
		const float GradientPerturbAmplitude;
	};
};

//////////////////////////////////////////////////////////////////////////////////////

UCLASS(abstract)
class VOXEL_API UVoxelNode_GradientPerturbFractal : public UVoxelNode_NoiseNodeFractal
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	float GradientPerturbAmplitude = 1;
	
	template<typename TFunction, int TDimension>
	class FLocalVoxelComputeNode : public UVoxelNode_NoiseNodeFractal::FLocalVoxelComputeNode<TFunction, TDimension>
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_GradientPerturbFractal* Node, const FVoxelCompilationNode* CompilationNode)
			: UVoxelNode_NoiseNodeFractal::FLocalVoxelComputeNode<TFunction, TDimension>(Node, CompilationNode)
			, GradientPerturbAmplitude(Node->GradientPerturbAmplitude)
		{
		}
		void Init(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& InitStruct) override
		{
			UVoxelNode_NoiseNodeFractal::FLocalVoxelComputeNode<TFunction, TDimension>::Init(Inputs, Outputs, InitStruct);
			this->Noise.SetGradientPerturbAmp(GradientPerturbAmplitude);
		}
		void InitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			UVoxelNode_NoiseNodeFractal::FLocalVoxelComputeNode<TFunction, TDimension>::InitCpp(Inputs, Outputs, Constructor);
			Constructor.AddLine(this->NoiseVariable.GetName() + ".SetGradientPerturbAmp(" + FString::SanitizeFloat(GradientPerturbAmplitude) + ");");
		}

	protected:
		const float GradientPerturbAmplitude;
	};
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// 2D Gradient Perturb
UCLASS(meta = (DisplayName = "2D Gradient Perturb"))
class VOXEL_API UVoxelNode_2DGradientPerturb : public UVoxelNode_GradientPerturb
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_BASIC(2, 2)

	class FLocalVoxelComputeNode : public UVoxelNode_GradientPerturb::FLocalVoxelComputeNode<FLocalVoxelComputeNode, 2>
	{
	public:
		using UVoxelNode_GradientPerturb::FLocalVoxelComputeNode<FLocalVoxelComputeNode, 2>::FLocalVoxelComputeNode;

		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override
		{
			Outputs[0]._float = Inputs[0]._float;
			Outputs[1]._float = Inputs[1]._float;
			Noise.GradientPerturb(Outputs[0]._float, Outputs[1]._float);
		}
		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(Outputs[0] + " = " + Inputs[0] + ";");
			Constructor.AddLine(Outputs[1] + " = " + Inputs[1] + ";");
			Constructor.AddLine(NoiseVariable.GetName() + ".GradientPerturb(" + Outputs[0] + ", " + Outputs[1] + ");");
		}

		static float Apply(const FastNoise& Noise, float X, float Y) { return 0; }
		static float Apply(const FastNoise& Noise, float X, float Y, float Z) { return 0; }
	};
};

//////////////////////////////////////////////////////////////////////////////////////

// 2D Gradient Perturb Fractal
UCLASS(meta = (DisplayName = "2D Gradient Perturb Fractal"))
class VOXEL_API UVoxelNode_2DGradientPerturbFractal : public UVoxelNode_GradientPerturbFractal
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_BASIC(2, 2)

	class FLocalVoxelComputeNode : public UVoxelNode_GradientPerturbFractal::FLocalVoxelComputeNode<FLocalVoxelComputeNode, 2>
	{
	public:
		using UVoxelNode_GradientPerturbFractal::FLocalVoxelComputeNode<FLocalVoxelComputeNode, 2>::FLocalVoxelComputeNode;

		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override
		{
			Outputs[0]._float = Inputs[0]._float;
			Outputs[1]._float = Inputs[1]._float;
			Noise.GradientPerturbFractal(Outputs[0]._float, Outputs[1]._float);
		}
		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(Outputs[0] + " = " + Inputs[0] + ";");
			Constructor.AddLine(Outputs[1] + " = " + Inputs[1] + ";");
			Constructor.AddLine(NoiseVariable.GetName() + ".GradientPerturbFractal(" + Outputs[0] + ", " + Outputs[1] + ");");
		}

		static float Apply(const FastNoise& Noise, float X, float Y) { return 0; }
		static float Apply(const FastNoise& Noise, float X, float Y, float Z) { return 0; }
	};
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// 3D Gradient Perturb
UCLASS(meta = (DisplayName = "3D Gradient Perturb"))
class VOXEL_API UVoxelNode_3DGradientPerturb : public UVoxelNode_GradientPerturb
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_BASIC(3, 3)

	class FLocalVoxelComputeNode : public UVoxelNode_GradientPerturb::FLocalVoxelComputeNode<FLocalVoxelComputeNode, 3>
	{
	public:
		using UVoxelNode_GradientPerturb::FLocalVoxelComputeNode<FLocalVoxelComputeNode, 3>::FLocalVoxelComputeNode;

		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override
		{
			Outputs[0]._float = Inputs[0]._float;
			Outputs[1]._float = Inputs[1]._float;
			Outputs[2]._float = Inputs[2]._float;
			Noise.GradientPerturb(Outputs[0]._float, Outputs[1]._float, Outputs[2]._float);
		}
		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(Outputs[0] + " = " + Inputs[0] + ";");
			Constructor.AddLine(Outputs[1] + " = " + Inputs[1] + ";");
			Constructor.AddLine(Outputs[2] + " = " + Inputs[2] + ";");
			Constructor.AddLine(NoiseVariable.GetName() + ".GradientPerturb(" + Outputs[0] + ", " + Outputs[1] + ", " + Outputs[2] + ");");
		}

		static float Apply(const FastNoise& Noise, float X, float Y) { return 0; }
		static float Apply(const FastNoise& Noise, float X, float Y, float Z) { return 0; }
	};
};

//////////////////////////////////////////////////////////////////////////////////////

// 3D Gradient Perturb Fractal
UCLASS(meta = (DisplayName = "3D Gradient Perturb Fractal"))
class VOXEL_API UVoxelNode_3DGradientPerturbFractal : public UVoxelNode_GradientPerturbFractal
{
	GENERATED_BODY()
	GENERATED_NOISENODE_BODY_BASIC(3, 3)

	class FLocalVoxelComputeNode : public UVoxelNode_GradientPerturbFractal::FLocalVoxelComputeNode<FLocalVoxelComputeNode, 3>
	{
	public:
		using UVoxelNode_GradientPerturbFractal::FLocalVoxelComputeNode<FLocalVoxelComputeNode, 3>::FLocalVoxelComputeNode;

		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override
		{
			Outputs[0]._float = Inputs[0]._float;
			Outputs[1]._float = Inputs[1]._float;
			Outputs[2]._float = Inputs[2]._float;
			Noise.GradientPerturbFractal(Outputs[0]._float, Outputs[1]._float, Outputs[2]._float);
		}
		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(Outputs[0] + " = " + Inputs[0] + ";");
			Constructor.AddLine(Outputs[1] + " = " + Inputs[1] + ";");
			Constructor.AddLine(Outputs[2] + " = " + Inputs[2] + ";");
			Constructor.AddLine(NoiseVariable.GetName() + ".GradientPerturbFractal(" + Outputs[0] + ", " + Outputs[1] + ", " + Outputs[2] + ");");
		}

		static float Apply(const FastNoise& Noise, float X, float Y) { return 0; }
		static float Apply(const FastNoise& Noise, float X, float Y, float Z) { return 0; }
	};
};

#undef LOCTEXT_NAMESPACE
