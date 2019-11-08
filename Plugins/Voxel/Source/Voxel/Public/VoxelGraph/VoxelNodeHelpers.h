// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelNode.h"
#include "VoxelUtilities.h"
#include "VoxelGraph/VoxelCppConstructor.h"
#include "VoxelGraph/VoxelCompilationNode.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelNodeHelpers.generated.h"

using EC = EVoxelPinCategory;
using Seed = int;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define GENERATED_VOXELNODE_BODY() \
TSharedPtr<FVoxelComputeNode> GetComputeNode(const FVoxelCompilationNode* CompilationNode) const override \
{ \
	return MakeShared<FLocalVoxelComputeNode>(this, CompilationNode); \
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template<typename T>
void AddToArray(TArray<T>& Array)
{

}
template<typename T>
void AddToArray(TArray<T>& Array, T E)
{
	Array.Add(E);
}
template<typename T, typename... TArgs>
void AddToArray(TArray<T>& Array, T E, TArgs... Args)
{
	Array.Add(E);
	AddToArray<T>(Array, Args...);
}

template<typename T1, typename T2, int T1Count = 0, int T2Count = 0>
void AddToArrays(TArray<T1>& Array1, TArray<T2>& Array2, T1 E)
{
	Array1.Add(E);
	static_assert(T1Count + 1 == T2Count || T1Count == 0 || T2Count == 0, "Invalid AddToArrays arg count");
}

template<typename T1, typename T2, int T1Count = 0, int T2Count = 0>
void AddToArrays(TArray<T1>& Array1, TArray<T2>& Array2, T2 E)
{
	Array2.Add(E);
	static_assert(T1Count == T2Count + 1 || T1Count == 0 || T2Count == 0, "Invalid AddToArrays arg count");
}

template<typename T1, typename T2, int T1Count = 0, int T2Count = 0, typename... TArgs>
void AddToArrays(TArray<T1>& Array1, TArray<T2>& Array2, T1 E, TArgs... Args)
{
	Array1.Add(E);
	AddToArrays<T1, T2, T1Count + 1 , T2Count>(Array1, Array2, Args...);
}

template<typename T1, typename T2, int T1Count = 0, int T2Count = 0, typename... TArgs>
void AddToArrays(TArray<T1>& Array1, TArray<T2>& Array2, T2 E, TArgs... Args)
{
	Array2.Add(E);
	AddToArrays<T1, T2, T1Count, T2Count + 1>(Array1, Array2, Args...);
}

///////////////////////////////////////////////////////////////////////////////

UCLASS(abstract)
class VOXEL_API UVoxelNodeHelper : public UVoxelNode
{
	GENERATED_BODY()
public:
	EVoxelPinCategory GetInputPinCategory(int32 PinIndex) const override { return InputCategories[FMath::Clamp(PinIndex, 0, InputCategories.Num() - 1)]; }
	EVoxelPinCategory GetOutputPinCategory(int32 PinIndex) const override { return OutputCategories[FMath::Clamp(PinIndex, 0, OutputCategories.Num() - 1)]; }
	FText GetInputPinName(int32 PinIndex) const override { return FText::FromString(FString(InputNames[FMath::Clamp(PinIndex, 0, InputNames.Num() - 1)])); }
	FText GetOutputPinName(int32 PinIndex) const override { return FText::FromString(FString(OutputNames[FMath::Clamp(PinIndex, 0, OutputNames.Num() - 1)])); }
	int32 GetMinInputPins() const override { return MinInputCount; }
	int32 GetMaxInputPins() const override { return MaxInputCount; }
	int32 GetOutputPinsCount() const override { return OutputCount; }
	FLinearColor GetColor()	const override { return Color; }
	TOptional<float> GetInputPinDefaultValueMin(int32 PinIndex) const override
	{
		int Index = 2 * PinIndex;
		if (Bounds.IsValidIndex(Index))
		{
			return Bounds[Index];
		}
		else
		{
			return TOptional<float>();
		}
	}
	TOptional<float> GetInputPinDefaultValueMax(int32 PinIndex) const override
	{
		int Index = 2 * PinIndex + 1;
		if (Bounds.IsValidIndex(Index))
		{
			return Bounds[Index];
		}
		else
		{
			return TOptional<float>();
		}
	}
	FString GetInputPinDefaultValue(int32 PinIndex) const override { return DefaultValues.IsValidIndex(PinIndex) ? DefaultValues[PinIndex] : ""; }

protected:
	template<typename... TCategoriesAndNames>
	void SetInputs(TCategoriesAndNames... CategoriesAndNames)
	{
		AddToArrays<EVoxelPinCategory, const char*>(InputCategories, InputNames, CategoriesAndNames...);
		MinInputCount += InputCategories.Num();
		MaxInputCount += InputCategories.Num();

		if (InputNames.Num() == 0)
		{
			InputNames.Add("");
		}
		else
		{
			check(InputCategories.Num() == InputNames.Num());
		}
	}

	template<typename... TCategoriesAndNames>
	void SetInputs(int32 Min, int32 Max, TCategoriesAndNames... CategoriesAndNames)
	{
		Min = FMath::Clamp(Min, 0, MAX_PINS - 1);
		Max = FMath::Clamp(Max, 0, MAX_PINS - 1);
		
		AddToArrays<EVoxelPinCategory, const char*>(InputCategories, InputNames, CategoriesAndNames...);
		check(MinInputCount == 0 && MaxInputCount == 0);
		MinInputCount = Min;
		MaxInputCount = Max;
		
		if (InputNames.Num() == 0)
		{
			InputNames.Add("");
		}
		else
		{
			check(InputCategories.Num() == InputNames.Num());
		}
	}

	template<typename... TCategoriesAndNames>
	void SetOutputs(TCategoriesAndNames... CategoriesAndNames)
	{
		AddToArrays<EVoxelPinCategory, const char*>(OutputCategories, OutputNames, CategoriesAndNames...);
		OutputCount += OutputCategories.Num();
		
		if (OutputNames.Num() == 0)
		{
			OutputNames.Add("");
		}
		else
		{
			check(OutputCategories.Num() == OutputNames.Num());
		}
	}

	template<typename... TBounds>
	void SetBounds(TBounds... InBounds)
	{
		AddToArray(Bounds, InBounds...);
	}

	template<typename... TDefaultValues>
	void SetDefaultValues(TDefaultValues... InDefaultValues)
	{
		AddToArray<const char*>(DefaultValues, InDefaultValues...);
	}

	void SetColor(const FLinearColor& InColor)
	{
		Color = InColor;
	}

private:
	TArray<EVoxelPinCategory> InputCategories;
	TArray<EVoxelPinCategory> OutputCategories;
	TArray<const char*> InputNames;
	TArray<const char*> OutputNames;
	TArray<TOptional<float>> Bounds;
	TArray<const char*> DefaultValues;
	int32 MinInputCount = 0;
	int32 MaxInputCount = 0;
	int32 OutputCount = 0;
	FLinearColor Color = FLinearColor::Black;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template<uint8 InDependencies>
class FVoxelCoordinateInputCompilationNode : public FVoxelCompilationNode
{
public:
	using FVoxelCompilationNode::FVoxelCompilationNode;

	virtual TSharedPtr<FVoxelCompilationNode> Clone(bool bFixLinks) const override
	{
		return CloneInternalDefault<FVoxelCoordinateInputCompilationNode>(bFixLinks);
	}
	virtual uint8 GetDefaultAxisDependencies() const override
	{
		return InDependencies;
	}
	virtual EVoxelCompilationNodeType GetType() const override
	{
		return EVoxelCompilationNodeType::Default;
	}
};

#define SET_NODE_DEPENDENCIES(Dependencies) TSharedPtr<FVoxelCompilationNode> GetCompilationNode() const override { return MakeShared<FVoxelCoordinateInputCompilationNode<Dependencies>>(GetName(), GetInputCategories(), GetOutputCategories(), this); }

template<class TNode>
class FVoxelLogErrorCompilationNode : public FVoxelCompilationNode
{
public:
	FVoxelLogErrorCompilationNode(const FString& Name, const TArray<EVoxelPinCategory>& InputCategories, const TArray<EVoxelPinCategory>& OutputCategories, const UVoxelNode* Node = nullptr)
		: FVoxelCompilationNode(Name, InputCategories, OutputCategories, Node)
		, LogErrorNode(CastChecked<TNode>(Node))
	{
	}

	virtual TSharedPtr<FVoxelCompilationNode> Clone(bool bFixLinks) const override
	{
		return CloneInternalDefault<FVoxelLogErrorCompilationNode>(bFixLinks);
	}
	virtual EVoxelCompilationNodeType GetType() const override
	{
		return EVoxelCompilationNodeType::Default;
	}
	virtual void LogErrors(FVoxelGraphCompiler& Compiler) override
	{
		LogErrorNode->LogErrors(Compiler);
	}

private:
	const TNode* const LogErrorNode;
};

#define ENABLE_LOGERRORS(Class) TSharedPtr<FVoxelCompilationNode> GetCompilationNode() const override { return MakeShared<FVoxelLogErrorCompilationNode<Class>>(GetName(), GetInputCategories(), GetOutputCategories(), this); }

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

inline void ReplaceInputsOutputs(FString& S, const TArray<FString>& Inputs, const TArray<FString>& Outputs, const FString& Context)
{	
	TMap<FString, FString> Args; 
	for (int I = 0; I < Inputs.Num(); I++)
	{
		Args.Add(TEXT("_I") + FString::FromInt(I), Inputs[I]);
	}
	for (int I = 0; I < Outputs.Num(); I++)
	{
		Args.Add(TEXT("_O") + FString::FromInt(I), Outputs[I]);
	}
	Args.Add(TEXT("_C0"), Context);

	TArray<FString> T;
	Args.GenerateKeyArray(T);
	for (auto& Key : T)
	{
		while (S.Contains(Key, ESearchCase::CaseSensitive))
		{
			S = S.Replace(*Key, *Args[Key], ESearchCase::CaseSensitive);
		}
	}
}

#define GENERATED_INIT(InputsDef, OutputsDef, ...) \
void Init(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& _C0) const override \
{ \
	InputsDef \
	OutputsDef \
	__VA_ARGS__ \
} \
void InitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override \
{ \
	FString X = TEXT(#__VA_ARGS__); \
	ReplaceInputsOutputs(X, Inputs, Outputs, Constructor.GetInitStructString()()); \
	Constructor.AddLine(X); \
}

#define GENERATED_COMPUTE(InputsDef, OutputsDef, ...) \
void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& _C0) const override \
{ \
	InputsDef \
	OutputsDef \
	__VA_ARGS__ \
} \
void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override \
{ \
	FString X = TEXT(#__VA_ARGS__); \
	ReplaceInputsOutputs(X, Inputs, Outputs, Constructor.GetContextString()); \
	Constructor.AddLine(X); \
}

#define GENERATED_COMPUTENODE(InputsDef, OutputsDef, ...) \
class FLocalVoxelComputeNode : public FVoxelComputeNode \
{ \
public: \
	using FVoxelComputeNode::FVoxelComputeNode; \
	GENERATED_COMPUTE \
	( \
		InputsDef, \
		OutputsDef, \
		__VA_ARGS__ \
	) \
};

#define COMPACT_VOXELNODE(Text) \
bool IsCompact() const override { return true; } \
FText GetTitle() const override { return LOCTEXT(Text, Text); }

#define SET_VOXELNODE_TITLE(Text) \
FText GetTitle() const override { return LOCTEXT(Text, Text); }

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

inline FString GetPrefixOpLoopString(const TArray<FString>& Inputs, const TArray<FString>& Outputs, int InputCount, const FString& Op)
{
	check(InputCount > 0);

	FString Line;

	Line += Outputs[0] + " = ";
	for (int I = 0; I < InputCount - 1; I++)
	{
		Line += Op + "(" + Inputs[I] + ", ";
	}

	Line += Inputs[InputCount - 1];

	for (int I = 0; I < InputCount - 1; I++)
	{
		Line += ")";
	}

	Line += ";";

	return Line;
}

inline FString GetInfixOpLoopString(const TArray<FString>& Inputs, const TArray<FString>& Outputs, int InputCount, const FString& Op)
{
	check(InputCount > 0);

	FString Line;

	Line += Outputs[0] + " = ";
	for (int I = 0; I < InputCount - 1; I++)
	{
		Line += Inputs[I] + " " + Op + " ";
	}
	Line += Inputs[InputCount - 1];
	Line += ";";

	return Line;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define GENERATED_COMPUTENODE_PREFIXOPLOOP(Op, Type) \
class FLocalVoxelComputeNode : public FVoxelComputeNode \
{ \
public: \
	using FVoxelComputeNode::FVoxelComputeNode; \
	void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override \
	{ \
		Type X = Inputs[0]._##Type; \
		for (int I = 1; I < InputCount; I++) \
		{ \
			X = Op(X, Inputs[I]._##Type); \
		} \
 \
		Outputs[0]._##Type = X; \
	} \
	void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override \
	{ \
		Constructor.AddLine(GetPrefixOpLoopString(Inputs, Outputs, InputCount, #Op)); \
	} \
};

#define GENERATED_COMPUTENODE_INFIXOPLOOP(Op, Type) \
class FLocalVoxelComputeNode : public FVoxelComputeNode \
{ \
public: \
	using FVoxelComputeNode::FVoxelComputeNode; \
	void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override \
	{ \
		Type X = Inputs[0]._##Type; \
		for (int I = 1; I < InputCount; I++) \
		{ \
			X = X Op Inputs[I]._##Type; \
		} \
 \
		Outputs[0]._##Type = X; \
	} \
	void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override \
	{ \
		Constructor.AddLine(GetInfixOpLoopString(Inputs, Outputs, InputCount, #Op)); \
	} \
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define GENERATED_BINARY_VOXELNODE(Op, ECType, RealType) \
{ \
	SetInputs(EC::ECType, EC::ECType); \
	SetOutputs(EC::Boolean); \
} \
GENERATED_VOXELNODE_BODY() \
COMPACT_VOXELNODE(#Op) \
GENERATED_COMPUTENODE \
( \
	DEFINE_INPUTS_REVERSED(RealType, RealType), \
	DEFINE_OUTPUTS_REVERSED(bool), \
	_O0 = _I0 Op _I1; \
)

#define GENERATED_BINARYFLOAT_VOXELNODE(Op) GENERATED_BINARY_VOXELNODE(Op, Float, float)
#define GENERATED_BINARYINT_VOXELNODE(Op) GENERATED_BINARY_VOXELNODE(Op, Int, int)

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define __DEFINE_INPUTS_0(A) A& _I0 = Inputs[0]._##A;
#define __DEFINE_INPUTS_1(A, ...) A& _I1 = Inputs[1]._##A; EXPAND(__DEFINE_INPUTS_0(__VA_ARGS__))
#define __DEFINE_INPUTS_2(A, ...) A& _I2 = Inputs[2]._##A; EXPAND(__DEFINE_INPUTS_1(__VA_ARGS__))
#define __DEFINE_INPUTS_3(A, ...) A& _I3 = Inputs[3]._##A; EXPAND(__DEFINE_INPUTS_2(__VA_ARGS__))
#define __DEFINE_INPUTS_4(A, ...) A& _I4 = Inputs[4]._##A; EXPAND(__DEFINE_INPUTS_3(__VA_ARGS__))
#define __DEFINE_INPUTS_5(A, ...) A& _I5 = Inputs[5]._##A; EXPAND(__DEFINE_INPUTS_4(__VA_ARGS__))
#define __DEFINE_INPUTS_6(A, ...) A& _I6 = Inputs[6]._##A; EXPAND(__DEFINE_INPUTS_5(__VA_ARGS__))
#define __DEFINE_INPUTS_7(A, ...) A& _I7 = Inputs[7]._##A; EXPAND(__DEFINE_INPUTS_6(__VA_ARGS__))
#define __DEFINE_INPUTS_8(A, ...) A& _I8 = Inputs[8]._##A; EXPAND(__DEFINE_INPUTS_7(__VA_ARGS__))
#define __DEFINE_INPUTS_9(A, ...) A& _I9 = Inputs[9]._##A; EXPAND(__DEFINE_INPUTS_8(__VA_ARGS__))
#define __DEFINE_INPUTS_10(A, ...) A& _I10 = Inputs[10]._##A; EXPAND(__DEFINE_INPUTS_9(__VA_ARGS__))
#define __DEFINE_INPUTS_11(A, ...) A& _I11 = Inputs[11]._##A; EXPAND(__DEFINE_INPUTS_10(__VA_ARGS__))
#define __DEFINE_INPUTS_12(A, ...) A& _I12 = Inputs[12]._##A; EXPAND(__DEFINE_INPUTS_11(__VA_ARGS__))
#define __DEFINE_INPUTS_13(A, ...) A& _I13 = Inputs[13]._##A; EXPAND(__DEFINE_INPUTS_12(__VA_ARGS__))
#define __DEFINE_INPUTS_14(A, ...) A& _I14 = Inputs[14]._##A; EXPAND(__DEFINE_INPUTS_13(__VA_ARGS__))
#define __DEFINE_INPUTS_15(A, ...) A& _I15 = Inputs[15]._##A; EXPAND(__DEFINE_INPUTS_14(__VA_ARGS__))
#define __DEFINE_INPUTS_16(A, ...) A& _I16 = Inputs[16]._##A; EXPAND(__DEFINE_INPUTS_15(__VA_ARGS__))
#define __DEFINE_INPUTS_17(A, ...) A& _I17 = Inputs[17]._##A; EXPAND(__DEFINE_INPUTS_16(__VA_ARGS__))
#define __DEFINE_INPUTS_18(A, ...) A& _I18 = Inputs[18]._##A; EXPAND(__DEFINE_INPUTS_17(__VA_ARGS__))
#define __DEFINE_INPUTS_19(A, ...) A& _I19 = Inputs[19]._##A; EXPAND(__DEFINE_INPUTS_18(__VA_ARGS__))
#define __DEFINE_INPUTS_20(A, ...) A& _I20 = Inputs[20]._##A; EXPAND(__DEFINE_INPUTS_19(__VA_ARGS__))
#define __DEFINE_INPUTS_21(A, ...) A& _I21 = Inputs[21]._##A; EXPAND(__DEFINE_INPUTS_20(__VA_ARGS__))
#define __DEFINE_INPUTS_22(A, ...) A& _I22 = Inputs[22]._##A; EXPAND(__DEFINE_INPUTS_21(__VA_ARGS__))
#define __DEFINE_INPUTS_23(A, ...) A& _I23 = Inputs[23]._##A; EXPAND(__DEFINE_INPUTS_22(__VA_ARGS__))
#define __DEFINE_INPUTS_24(A, ...) A& _I24 = Inputs[24]._##A; EXPAND(__DEFINE_INPUTS_23(__VA_ARGS__))
#define __DEFINE_INPUTS_25(A, ...) A& _I25 = Inputs[25]._##A; EXPAND(__DEFINE_INPUTS_24(__VA_ARGS__))
#define __DEFINE_INPUTS_26(A, ...) A& _I26 = Inputs[26]._##A; EXPAND(__DEFINE_INPUTS_25(__VA_ARGS__))
#define __DEFINE_INPUTS_27(A, ...) A& _I27 = Inputs[27]._##A; EXPAND(__DEFINE_INPUTS_26(__VA_ARGS__))
#define __DEFINE_INPUTS_28(A, ...) A& _I28 = Inputs[28]._##A; EXPAND(__DEFINE_INPUTS_27(__VA_ARGS__))
#define __DEFINE_INPUTS_29(A, ...) A& _I29 = Inputs[29]._##A; EXPAND(__DEFINE_INPUTS_28(__VA_ARGS__))
#define __DEFINE_INPUTS_30(A, ...) A& _I30 = Inputs[30]._##A; EXPAND(__DEFINE_INPUTS_29(__VA_ARGS__))
#define __DEFINE_INPUTS_31(A, ...) A& _I31 = Inputs[31]._##A; EXPAND(__DEFINE_INPUTS_30(__VA_ARGS__))
#define __DEFINE_INPUTS_32(A, ...) A& _I32 = Inputs[32]._##A; EXPAND(__DEFINE_INPUTS_31(__VA_ARGS__))

#define __DEFINE_OUTPUTS_0(A) A& _O0 = Outputs[0]._##A;
#define __DEFINE_OUTPUTS_1(A, ...) A& _O1 = Outputs[1]._##A; EXPAND(__DEFINE_OUTPUTS_0(__VA_ARGS__))
#define __DEFINE_OUTPUTS_2(A, ...) A& _O2 = Outputs[2]._##A; EXPAND(__DEFINE_OUTPUTS_1(__VA_ARGS__))
#define __DEFINE_OUTPUTS_3(A, ...) A& _O3 = Outputs[3]._##A; EXPAND(__DEFINE_OUTPUTS_2(__VA_ARGS__))
#define __DEFINE_OUTPUTS_4(A, ...) A& _O4 = Outputs[4]._##A; EXPAND(__DEFINE_OUTPUTS_3(__VA_ARGS__))
#define __DEFINE_OUTPUTS_5(A, ...) A& _O5 = Outputs[5]._##A; EXPAND(__DEFINE_OUTPUTS_4(__VA_ARGS__))
#define __DEFINE_OUTPUTS_6(A, ...) A& _O6 = Outputs[6]._##A; EXPAND(__DEFINE_OUTPUTS_5(__VA_ARGS__))
#define __DEFINE_OUTPUTS_7(A, ...) A& _O7 = Outputs[7]._##A; EXPAND(__DEFINE_OUTPUTS_6(__VA_ARGS__))
#define __DEFINE_OUTPUTS_8(A, ...) A& _O8 = Outputs[8]._##A; EXPAND(__DEFINE_OUTPUTS_7(__VA_ARGS__))
#define __DEFINE_OUTPUTS_9(A, ...) A& _O9 = Outputs[9]._##A; EXPAND(__DEFINE_OUTPUTS_8(__VA_ARGS__))
#define __DEFINE_OUTPUTS_10(A, ...) A& _O10 = Outputs[10]._##A; EXPAND(__DEFINE_OUTPUTS_9(__VA_ARGS__))
#define __DEFINE_OUTPUTS_11(A, ...) A& _O11 = Outputs[11]._##A; EXPAND(__DEFINE_OUTPUTS_10(__VA_ARGS__))
#define __DEFINE_OUTPUTS_12(A, ...) A& _O12 = Outputs[12]._##A; EXPAND(__DEFINE_OUTPUTS_11(__VA_ARGS__))
#define __DEFINE_OUTPUTS_13(A, ...) A& _O13 = Outputs[13]._##A; EXPAND(__DEFINE_OUTPUTS_12(__VA_ARGS__))
#define __DEFINE_OUTPUTS_14(A, ...) A& _O14 = Outputs[14]._##A; EXPAND(__DEFINE_OUTPUTS_13(__VA_ARGS__))
#define __DEFINE_OUTPUTS_15(A, ...) A& _O15 = Outputs[15]._##A; EXPAND(__DEFINE_OUTPUTS_14(__VA_ARGS__))
#define __DEFINE_OUTPUTS_16(A, ...) A& _O16 = Outputs[16]._##A; EXPAND(__DEFINE_OUTPUTS_15(__VA_ARGS__))
#define __DEFINE_OUTPUTS_17(A, ...) A& _O17 = Outputs[17]._##A; EXPAND(__DEFINE_OUTPUTS_16(__VA_ARGS__))
#define __DEFINE_OUTPUTS_18(A, ...) A& _O18 = Outputs[18]._##A; EXPAND(__DEFINE_OUTPUTS_17(__VA_ARGS__))
#define __DEFINE_OUTPUTS_19(A, ...) A& _O19 = Outputs[19]._##A; EXPAND(__DEFINE_OUTPUTS_18(__VA_ARGS__))
#define __DEFINE_OUTPUTS_20(A, ...) A& _O20 = Outputs[20]._##A; EXPAND(__DEFINE_OUTPUTS_19(__VA_ARGS__))
#define __DEFINE_OUTPUTS_21(A, ...) A& _O21 = Outputs[21]._##A; EXPAND(__DEFINE_OUTPUTS_20(__VA_ARGS__))
#define __DEFINE_OUTPUTS_22(A, ...) A& _O22 = Outputs[22]._##A; EXPAND(__DEFINE_OUTPUTS_21(__VA_ARGS__))
#define __DEFINE_OUTPUTS_23(A, ...) A& _O23 = Outputs[23]._##A; EXPAND(__DEFINE_OUTPUTS_22(__VA_ARGS__))
#define __DEFINE_OUTPUTS_24(A, ...) A& _O24 = Outputs[24]._##A; EXPAND(__DEFINE_OUTPUTS_23(__VA_ARGS__))
#define __DEFINE_OUTPUTS_25(A, ...) A& _O25 = Outputs[25]._##A; EXPAND(__DEFINE_OUTPUTS_24(__VA_ARGS__))
#define __DEFINE_OUTPUTS_26(A, ...) A& _O26 = Outputs[26]._##A; EXPAND(__DEFINE_OUTPUTS_25(__VA_ARGS__))
#define __DEFINE_OUTPUTS_27(A, ...) A& _O27 = Outputs[27]._##A; EXPAND(__DEFINE_OUTPUTS_26(__VA_ARGS__))
#define __DEFINE_OUTPUTS_28(A, ...) A& _O28 = Outputs[28]._##A; EXPAND(__DEFINE_OUTPUTS_27(__VA_ARGS__))
#define __DEFINE_OUTPUTS_29(A, ...) A& _O29 = Outputs[29]._##A; EXPAND(__DEFINE_OUTPUTS_28(__VA_ARGS__))
#define __DEFINE_OUTPUTS_30(A, ...) A& _O30 = Outputs[30]._##A; EXPAND(__DEFINE_OUTPUTS_29(__VA_ARGS__))
#define __DEFINE_OUTPUTS_31(A, ...) A& _O31 = Outputs[31]._##A; EXPAND(__DEFINE_OUTPUTS_30(__VA_ARGS__))
#define __DEFINE_OUTPUTS_32(A, ...) A& _O32 = Outputs[32]._##A; EXPAND(__DEFINE_OUTPUTS_31(__VA_ARGS__))

#define _GET_NTH_ARG(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, N, ...) EXPAND(N)

#define EXPAND( x ) x

#define DEFINE_INPUTS_REVERSED(...) \
	EXPAND(_GET_NTH_ARG(__VA_ARGS__, __DEFINE_INPUTS_32, __DEFINE_INPUTS_31, __DEFINE_INPUTS_30, __DEFINE_INPUTS_29, __DEFINE_INPUTS_28, __DEFINE_INPUTS_27, __DEFINE_INPUTS_26, __DEFINE_INPUTS_25, __DEFINE_INPUTS_24, __DEFINE_INPUTS_23, __DEFINE_INPUTS_22, __DEFINE_INPUTS_21, __DEFINE_INPUTS_20, __DEFINE_INPUTS_19, __DEFINE_INPUTS_18, __DEFINE_INPUTS_17, __DEFINE_INPUTS_16, __DEFINE_INPUTS_15, __DEFINE_INPUTS_14, __DEFINE_INPUTS_13, __DEFINE_INPUTS_12, __DEFINE_INPUTS_11, __DEFINE_INPUTS_10, __DEFINE_INPUTS_9, __DEFINE_INPUTS_8, __DEFINE_INPUTS_7, __DEFINE_INPUTS_6, __DEFINE_INPUTS_5, __DEFINE_INPUTS_4, __DEFINE_INPUTS_3, __DEFINE_INPUTS_2, __DEFINE_INPUTS_1, __DEFINE_INPUTS_0)(__VA_ARGS__))

#define DEFINE_OUTPUTS_REVERSED(...) \
	EXPAND(_GET_NTH_ARG(__VA_ARGS__, __DEFINE_OUTPUTS_32, __DEFINE_OUTPUTS_31, __DEFINE_OUTPUTS_30, __DEFINE_OUTPUTS_29, __DEFINE_OUTPUTS_28, __DEFINE_OUTPUTS_27, __DEFINE_OUTPUTS_26, __DEFINE_OUTPUTS_25, __DEFINE_OUTPUTS_24, __DEFINE_OUTPUTS_23, __DEFINE_OUTPUTS_22, __DEFINE_OUTPUTS_21, __DEFINE_OUTPUTS_20, __DEFINE_OUTPUTS_19, __DEFINE_OUTPUTS_18, __DEFINE_OUTPUTS_17, __DEFINE_OUTPUTS_16, __DEFINE_OUTPUTS_15, __DEFINE_OUTPUTS_14, __DEFINE_OUTPUTS_13, __DEFINE_OUTPUTS_12, __DEFINE_OUTPUTS_11, __DEFINE_OUTPUTS_10, __DEFINE_OUTPUTS_9, __DEFINE_OUTPUTS_8, __DEFINE_OUTPUTS_7, __DEFINE_OUTPUTS_6, __DEFINE_OUTPUTS_5, __DEFINE_OUTPUTS_4, __DEFINE_OUTPUTS_3, __DEFINE_OUTPUTS_2, __DEFINE_OUTPUTS_1, __DEFINE_OUTPUTS_0)(__VA_ARGS__))
	

