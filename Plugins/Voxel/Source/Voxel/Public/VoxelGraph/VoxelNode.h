// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelMaterial.h"
#include "EdGraph/EdGraphNode.h"
#include "VoxelGraph/VoxelNodeDefinitions.h"
#include "VoxelWorldGenerator.h"
#include "VoxelNode.generated.h"

#define MAX_PINS 64
#define MAX_VARIABLES 0xFFFFF

class UVoxelNode;
class FVoxelComputeNode;
class FVoxelCppConstructor;
class FVoxelCompilationNode;

union FVoxelNodeType
{
	float _float;
	int _int;
	int _Seed;
	bool _bool;
	FVoxelMaterial _FVoxelMaterial;

	FVoxelNodeType()
		: _FVoxelMaterial(ENoInit::NoInit)
	{
	}
};

UENUM()
enum class EVoxelPinCategory : uint8
{
	Exec,
	Boolean,
	Int,
	Float,
	Material,
	Seed,
	Wildcard UMETA(Hidden)
};

class VOXEL_API FVoxelPinCategory
{
public:
	static const FString PC_Exec;
	static const FString PC_Boolean;
	static const FString PC_Int;
	static const FString PC_Float;
	static const FString PC_Material;
	static const FString PC_Seed;
	static const FString PC_Wildcard;

	static EVoxelPinCategory FromString(const FString& String);
	static EVoxelPinCategory FromString(const FName& String) { return FromString(String.ToString()); }
	static FString ToString(EVoxelPinCategory Category);
	static FString GetDefaultValueForCategory(EVoxelPinCategory Category);
};

USTRUCT()
struct FVoxelPin
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid PinId;

	UPROPERTY()
	FString DefaultValue;

	UPROPERTY()
	EVoxelPinCategory PinCategory;

	UPROPERTY()
	TArray<UVoxelNode*> OtherNodes;

	UPROPERTY()
	TArray<FGuid> OtherPinIds;

	FVoxelPin()
		: DefaultValue(TEXT(""))
		, PinCategory(EVoxelPinCategory::Exec)
	{
	}

	FVoxelPin(const FGuid& PinId, const FString& DefaultValue, EVoxelPinCategory PinCategory, const TArray<UVoxelNode*>& OtherNodes, const TArray<FGuid>& OtherPinIds)
		: PinId(PinId)
		, DefaultValue(DefaultValue)
		, PinCategory(PinCategory)
		, OtherNodes(OtherNodes)
		, OtherPinIds(OtherPinIds)
	{
	}
};

/**
 * Base class for VoxelNodes
 */
UCLASS(abstract, hidecategories = Object, editinlinenew)
class VOXEL_API UVoxelNode : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FVoxelPin> InputPins;
	
	UPROPERTY()
	TArray<FVoxelPin> OutputPins;

	UPROPERTY(Transient)
	bool bIsPreviewing = false;
	
	UPROPERTY(Transient)
	int PreviewPinIndex = -1;

	UPROPERTY(Transient)
	int LastPreviewPinIndex = -1;

	UPROPERTY()
	class UVoxelGraphGenerator* Graph;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	UEdGraphNode* GraphNode;
#endif

public:
	void CreateStartingConnectors();

	int32 GetInputPinsCount() const { return InputPinCount; }
	void RemoveInputPin();
	void AddInputPin();
	
	int32 GetInputPinIndex(const FGuid& PinId);
	int32 GetOutputPinIndex(const FGuid& PinId);

	bool HasInputPinWithCategory(EVoxelPinCategory Category) const;
	bool HasOutputPinWithCategory(EVoxelPinCategory Category) const;

	TArray<EVoxelPinCategory> GetInputCategories() const;
	TArray<EVoxelPinCategory> GetOutputCategories() const;

public:
	//~ Begin UVoxelNode Interface
	virtual int32 GetMaxInputPins() const { return 0; }
	virtual int32 GetMinInputPins() const { return 0; }
	virtual int32 GetOutputPinsCount() const { return 0; }

	virtual FLinearColor GetColor() const { return FLinearColor::Black; }
	virtual FText GetTitle() const;
	virtual bool IsCompact() const { return false; }

	virtual FText GetInputPinName(int32 PinIndex) const { return FText::GetEmpty(); }
	virtual FText GetOutputPinName(int32 PinIndex) const { return FText::GetEmpty(); }

	virtual EVoxelPinCategory GetInputPinCategory(int32 PinIndex) const { return EVoxelPinCategory::Float; }
	virtual EVoxelPinCategory GetOutputPinCategory(int32 PinIndex) const { return EVoxelPinCategory::Float; }

	virtual TOptional<float> GetInputPinDefaultValueMin(int32 PinIndex) const { return TOptional<float>(); }
	virtual TOptional<float> GetInputPinDefaultValueMax(int32 PinIndex) const { return TOptional<float>(); }
	virtual FString GetInputPinDefaultValue(int32 PinIndex) const { return ""; }

	virtual TSharedPtr<FVoxelComputeNode> GetComputeNode(const FVoxelCompilationNode* CompilationNode) const;
	virtual TSharedPtr<FVoxelCompilationNode> GetCompilationNode() const;
	
	virtual bool CanUserDeleteNode() const { return true; }
	virtual bool CanDuplicateNode() const { return true; }
	//~ End UVoxelNode Interface

#if WITH_EDITOR
	//~ Begin UObject Interface
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	void PostLoad() override;
	//~ End UObject Interface
#endif //WITH_EDITOR

protected:
	UPROPERTY()
	int32 InputPinCount;
};

class FVoxelComputeNode
{
public:
	enum class EExecKind
	{
		Passthrough,
		If
	};
	
	const FString Name;
	const int InputCount;
	const int OutputCount;
	const UVoxelNode* const SourceNode;

	FVoxelComputeNode(const UVoxelNode* Node, const FVoxelCompilationNode* CompilationNode);
	virtual ~FVoxelComputeNode() = default;

	inline bool IsInit() const { return bIsInit; }
	inline bool IsConstructorSetup() const { return bIsConstructorSetup; }

public:
	inline FVoxelNodeType GetDefaultValue(int32 Index) { return DefaultValues[Index]; }
	inline int32 GetInputId(int32 Index) { return InputIds[Index]; }
	inline int32 GetOutputId(int32 Index) { return OutputIds[Index]; }
	
	void CallInit(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& InitStruct) { check(!bIsInit); bIsInit = true; Init(Inputs, Outputs, InitStruct); }

	virtual void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const { check(false); }
	virtual int32 ComputeExecNode(FVoxelNodeType Inputs[], float& Value, FVoxelMaterial& Material) const { check(false); return 0; }

protected:	
	virtual void Init(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& InitStruct) {};
	
public:
	inline FString GetDefaultValueString(int32 Index) { return DefaultValueStrings[Index]; }
	inline EVoxelPinCategory GetOutputType(int32 Index) { return OutputTypes[Index]; }

	void CallInitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) { check(!bIsInit); bIsInit = true; InitCpp(Inputs, Outputs, Constructor); }
	void CallSetupConstructor(FVoxelCppConstructor& Constructor) { check(!bIsConstructorSetup); bIsConstructorSetup = true; SetupConstructor(Constructor); }

	virtual void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const { check(false); }
	virtual EExecKind ComputeExecNodeCpp(const TArray<FString>& Inputs, FString& BranchResult, FVoxelCppConstructor& Constructor) const { check(false); return EExecKind::Passthrough; }

protected:
	virtual void InitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const {}
	virtual void SetupConstructor(FVoxelCppConstructor& Constructor) const {}

private:
	TArray<FVoxelNodeType> DefaultValues;
	
	TArray<int32> InputIds;
	TArray<int32> OutputIds;
	
private:
	TArray<FString> DefaultValueStrings;
	TArray<EVoxelPinCategory> OutputTypes;
	
	bool bIsInit = false;
	bool bIsConstructorSetup = false;
};
