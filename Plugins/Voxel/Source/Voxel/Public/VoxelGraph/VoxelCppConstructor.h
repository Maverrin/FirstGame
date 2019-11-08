// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelComputeNodeTree.h"

class UVoxelNode;
class UVoxelGraphGenerator;
class UEdGraphNode;

struct FVoxelVariable
{
public:
	static FString SanitizeName(const FString& InName);
public:
	FVoxelVariable() {}
	FVoxelVariable(const FString& InType, const FString& InName)
		: Type(InType)
		, Name(SanitizeName(InName))
	{
	}

	inline FString GetType() const { return Type; }
	inline FString GetName() const { return Name; }
	inline FString GetDeclaration() const { return Type + TEXT(" ") + Name + TEXT(";"); }

protected:
	FString Type;
	FString Name;
};

struct FVoxelExposedVariable : public FVoxelVariable
{
public:
	FVoxelExposedVariable() {}
	FVoxelExposedVariable(const FString& InType, const FString& InName, int InPriority, const FString& InDefaultValue, const UVoxelNode* InNode, const FString& InCategory, const FString& InExposedType = FString(), const TFunction<FString(FString)>& InCustomAccessor = [](auto Name) { return Name; })
		: FVoxelVariable(InType, InName)
	    , Priority(InPriority)
		, DefaultValue(InDefaultValue)
		, Node(InNode)
		, Category(InCategory)
		, ExposedType(InExposedType)
		, CustomAccessor(InCustomAccessor)
	{
		check(Node);
		if (ExposedType.IsEmpty())
		{
			ExposedType = Type;
		}
	}

	inline int GetPriority() const { return Priority; }
	inline FString GetDefaultValue() const { return DefaultValue; }
	inline const UVoxelNode* GetNode() const { return Node; }
	inline FString GetCategory() const { return Category; }
	inline FString GetExposedType() const { return ExposedType; }
	inline FString GetAccessor(const FString& InName) const { return CustomAccessor(InName); }

protected:
	int Priority = 0;
	// Optional
	FString DefaultValue;
	const UVoxelNode* Node;
	FString Category;
	// Optional. For instance, VariableType = FVoxelWorldGeneratorPicker and VariableInstanceType = FVoxelWorldGeneratorInstance*
	FString ExposedType;
	// Optional. For instance if variable name is WorldGenerator, "WorldGenerator.GetWorldGenerator()"
	TFunction<FString(FString)> CustomAccessor;
};

class FVoxelCppConstructor
{
public:
	FVoxelCppConstructor(const FString& ClassName, UVoxelGraphGenerator* Graph);
	
	bool Compile(FString& OutErrorMessage);
	inline FString GetCode() const { return Code; }

public:
	inline void AddInclude(const FString& Filename)
	{
		Includes.AddUnique(Filename);
	}
	inline void AddPrivateVariable(const FVoxelVariable& PrivateVariable)
	{
		PrivateVariables.Add(PrivateVariable);
	}
	void AddExposedVariable(const FVoxelExposedVariable& ExposedVariable);

	inline void AddLine(const FString& Line)
	{
		if (!QueuedComment.IsEmpty())
		{
			AddLineInternal(QueuedComment);
			QueuedComment.Empty();
		}
		AddLineInternal(Line);
	}
	inline void NewLine()
	{
		AddLineInternal("");
	}

	inline void Indent() { CurrentIndent++; check(CurrentIndent >= 0); }
	inline void Unindent() { CurrentIndent--; check(CurrentIndent >= 0); }

	// Queue comment and add it before next AddLine
	inline void QueueComment(const FString& Comment)
	{
		QueuedComment = Comment;
	}
	// Add new line if comment has been done
	inline void EndComment()
	{
		if (QueuedComment.IsEmpty())
		{
			NewLine();
		}
		else
		{
			QueuedComment.Empty();
		}
	}
	inline void AddError(const FString& Error)
	{
		if (!Error.IsEmpty())
		{
			Errors += Error + "\n";
		}
	}

	inline FString GetInitStructString() const { return "InitStruct"; }
	inline FString GetValueString() const { return GetValueStringInternal(CurrentDependencies); }
	inline FString GetMaterialString() const { return GetMaterialStringInternal(CurrentDependencies); }
	inline FString GetContextString() const { return "Context"; }

	inline FString GetLocalVariableName(int Index) const { return bIsInit ? LocalVariables[Index].GetInitName() : LocalVariables[Index].Name; }

private:
	FString const ClassName;
	UVoxelGraphGenerator* const Graph;
	TSharedPtr<FVoxelComputeNodeTreesHolder> const Tree;

	bool bIsInit = false;
	int CurrentIndent = 0;	
	FString Code;
	EVoxelAxisDependencies CurrentDependencies;

	TArray<FString> Includes;
	TArray<FVoxelVariable> PrivateVariables;
	TArray<FVoxelExposedVariable> ExposedVariables;
	TMap<int, FVoxelLocalVariable> LocalVariables;

	FString QueuedComment;
	FString Errors;
	TArray<UEdGraphNode*> NodesToSelect;

	inline void AddLineInternal(const FString& Line)
	{		
		FString Result;
		check(CurrentIndent >= 0);
		for (int I = 0; I < CurrentIndent; I++)
		{
			Result += "\t";
		}
		Result.Append(Line);
		Code.Append(Result + "\n");
	}
	inline FString GetPrefix(EVoxelAxisDependencies Dependencies) const
	{
		if (Dependencies == EVoxelAxisDependencies::Constant)
		{
			return "C_";
		}
		else if (Dependencies == EVoxelAxisDependencies::X)
		{
			return "X_";
		}
		else if (Dependencies == EVoxelAxisDependencies::XY)
		{
			return "XY_";
		}
		else
		{
			check(Dependencies == EVoxelAxisDependencies::XYZ);
			return "XYZ_";
		}
	}
	inline FString GetValueStringInternal(EVoxelAxisDependencies Dependencies) const { return GetPrefix(Dependencies) + "Value"; }
	inline FString GetMaterialStringInternal(EVoxelAxisDependencies Dependencies) const { return GetPrefix(Dependencies) + "Material"; }

	inline void DeclareValueAndMaterialAndLocalVariables(EVoxelAxisDependencies NewDependencies)
	{
		CurrentDependencies = NewDependencies;

		AddLine("float " + GetValueString() + " = 1;");
		AddLine("FVoxelMaterial " + GetMaterialString() + ";");

		for (auto& Variable : LocalVariables)
		{
			if (Variable.Value.Dependencies == NewDependencies)
			{
				AddLine(Variable.Value.GetDeclaration());
			}
		}
	}
};

