// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelNode.h"

enum class EVoxelPinDirection
{
	Input,
	Output
};

struct FVoxelCompilationPin
{
	FVoxelCompilationNode* const Node;
	int32 const Index;
	EVoxelPinDirection const Direction;
	EVoxelPinCategory const PinCategory;
	FString const Name;

	FVoxelCompilationPin(FVoxelCompilationNode* Node, int32 Index, EVoxelPinDirection Direction, EVoxelPinCategory PinCategory, const FString& Name)
		: Node(Node)
		, Index(Index)
		, Direction(Direction)
		, PinCategory(PinCategory)
		, Name(Name)
	{
	}

public:
	inline void BreakLinkTo(FVoxelCompilationPin* Other)
	{
		verify(this->LinkedTo.Remove(Other) == 1);
		verify(Other->LinkedTo.Remove(this) == 1);
	}
	inline bool IsLinkedTo(FVoxelCompilationPin* Other) const
	{
		bool ALinkedToB = this->LinkedTo.Contains(Other);
		bool BLinkedToA = Other->LinkedTo.Contains(this);

		check((ALinkedToB && BLinkedToA) || (!ALinkedToB && !BLinkedToA));

		return ALinkedToB;
	}
	inline void LinkTo(FVoxelCompilationPin* Other)
	{
		check(!IsLinkedTo(Other));
		check(PinCategory == Other->PinCategory);

		this->LinkedTo.Add(Other);
		Other->LinkedTo.Add(this);
	}
	inline void BreakAllLinks()
	{
		auto Copy = LinkedTo;
		for (auto& Pin : Copy)
		{
			BreakLinkTo(Pin);
		}
		check(LinkedTo.Num() == 0);
	}
	inline const TArray<FVoxelCompilationPin*>& GetLinkedTo() const { return LinkedTo; }
	inline int LinkedToNum() const { return LinkedTo.Num(); }

	inline void Check()
	{
		for (auto& LinkedToPin : LinkedTo)
		{
			// Only one occurrence
			{
				int FromStartIndex = LinkedTo.Find(LinkedToPin);
				int FromEndIndex = LinkedTo.FindLast(LinkedToPin);
				check(FromStartIndex == FromEndIndex && FromStartIndex >= 0);
			}			
			{
				auto& OtherLinkedTo = LinkedToPin->LinkedTo;
				int FromStartIndex = OtherLinkedTo.Find(this);
				int FromEndIndex = OtherLinkedTo.FindLast(this);
				check(FromStartIndex == FromEndIndex && FromStartIndex >= 0);
			}
		}

		if (PinCategory == EVoxelPinCategory::Exec)
		{
			if (Direction == EVoxelPinDirection::Output)
			{
				check(LinkedToNum() <= 1);
			}
		}
		else
		{
			if (Direction == EVoxelPinDirection::Input)
			{
				check(LinkedToNum() <= 1);
			}
		}
	}
	
public:
	inline void SetDefaultValue(const FString& String)
	{
		check(Direction == EVoxelPinDirection::Input);
		DefaultValue = String;
	}
	inline FString GetDefaultValue() const
	{
		check(Direction == EVoxelPinDirection::Input);
		return DefaultValue;
	}

private:
	TArray<FVoxelCompilationPin*> LinkedTo;
	FString DefaultValue;

	friend class FVoxelCompilationNode;
};

struct FVoxelCompilationPinLink
{
	FVoxelCompilationPin* From;
	FVoxelCompilationPin* To;

	FVoxelCompilationPinLink(FVoxelCompilationPin* From, FVoxelCompilationPin* To)
		: From(From)
		, To(To)
	{
	}
};

template<typename T>
inline int CountPinsWithoutExecs(const TArray<T>& Pins)
{
	int Count = 0;
	for (auto& Pin : Pins)
	{
		if (Pin.PinCategory != EVoxelPinCategory::Exec)
		{
			Count++;
		}
	}
	return Count;
}

enum class EVoxelCompilationNodeType
{
	Default,
	Macro,
	FlowMerge,
	Passthrough,
	PortalOutput
};

///////////////////////////////////////////////////////////////////////////////

class FVoxelCompilationNode
{
public:
	enum EVoxelAxisDependencies : uint8
	{
		X = 0x1,
		Y = 0x2,
		Z = 0x4
	};

	struct FInputPinIterator
	{
		FVoxelCompilationNode* const Node;
		FInputPinIterator(FVoxelCompilationNode* Node) : Node(Node) {}
	};
	struct FOutputPinIterator
	{
		FVoxelCompilationNode* const Node;
		FOutputPinIterator(FVoxelCompilationNode* Node) : Node(Node) {}
	};
	struct FAllPinIterator
	{
		FVoxelCompilationNode* const Node;
		FAllPinIterator(FVoxelCompilationNode* Node) : Node(Node) {}
	};
	struct FInputPinConstIterator
	{
		const FVoxelCompilationNode* const Node;
		FInputPinConstIterator(const FVoxelCompilationNode* Node) : Node(Node) {}
	};
	struct FOutputPinConstIterator
	{
		const FVoxelCompilationNode* const Node;
		FOutputPinConstIterator(const FVoxelCompilationNode* Node) : Node(Node) {}
	};
	struct FAllPinConstIterator
	{
		const FVoxelCompilationNode* const Node;
		FAllPinConstIterator(const FVoxelCompilationNode* Node) : Node(Node) {}
	};

private:
	FORCEINLINE friend       FVoxelCompilationPin**       begin(FInputPinIterator It)       { return It.Node->InputPins.GetData(); }
	FORCEINLINE friend const FVoxelCompilationPin* const* begin(FInputPinConstIterator It)  { return It.Node->InputPins.GetData(); }
	FORCEINLINE friend       FVoxelCompilationPin**       end(FInputPinIterator It)       { return It.Node->InputPins.GetData() + It.Node->InputPins.Num(); }
	FORCEINLINE friend const FVoxelCompilationPin* const* end(FInputPinConstIterator It)  { return It.Node->InputPins.GetData() + It.Node->InputPins.Num(); }

	FORCEINLINE friend       FVoxelCompilationPin**       begin(FOutputPinIterator It)       { return It.Node->OutputPins.GetData(); }
	FORCEINLINE friend const FVoxelCompilationPin* const* begin(FOutputPinConstIterator It)  { return It.Node->OutputPins.GetData(); }
	FORCEINLINE friend       FVoxelCompilationPin**       end(FOutputPinIterator It)       { return It.Node->OutputPins.GetData() + It.Node->OutputPins.Num(); }
	FORCEINLINE friend const FVoxelCompilationPin* const* end(FOutputPinConstIterator It)  { return It.Node->OutputPins.GetData() + It.Node->OutputPins.Num(); }

	FORCEINLINE friend       FVoxelCompilationPin* begin(FAllPinIterator It)       { return It.Node->Pins.GetData(); }
	FORCEINLINE friend const FVoxelCompilationPin* begin(FAllPinConstIterator It)  { return It.Node->Pins.GetData(); }
	FORCEINLINE friend       FVoxelCompilationPin* end(FAllPinIterator It)       { return It.Node->Pins.GetData() + It.Node->Pins.Num(); }
	FORCEINLINE friend const FVoxelCompilationPin* end(FAllPinConstIterator It)  { return It.Node->Pins.GetData() + It.Node->Pins.Num(); }

public:
	FVoxelCompilationNode(const FString& Name, const TArray<EVoxelPinCategory>& InputCategories, const TArray<EVoxelPinCategory>& OutputCategories, const UVoxelNode* Node = nullptr)
		: SourceNode(Node)
		, Node(Node)
		, Name(Name)
	{
		for (int I = 0; I < InputCategories.Num(); I++)
		{
			Pins.Emplace(this, I, EVoxelPinDirection::Input, InputCategories[I], Node ? Node->GetInputPinName(I).ToString() : FString::FromInt(I));
			if (InputCategories[I] != EVoxelPinCategory::Exec)
			{
				InputIds.Add(-1);
			}
		}
		for (int I = 0; I < OutputCategories.Num(); I++)
		{
			Pins.Emplace(this, I, EVoxelPinDirection::Output, OutputCategories[I], Node ? Node->GetOutputPinName(I).ToString() : FString::FromInt(I));
			if (OutputCategories[I] != EVoxelPinCategory::Exec)
			{
				OutputIds.Add(-1);
			}
		}
		RebuildPinsArray();
	}
	virtual ~FVoxelCompilationNode() {}

	uint8 Dependencies = X | Y | Z;
	uint8 FinalDependencies = 0;
	const UVoxelNode* SourceNode;

public:
	inline FInputPinIterator CreateInputPinsIterator() { return FInputPinIterator(this); }
	inline FOutputPinIterator CreateOutputPinsIterator() { return FOutputPinIterator(this); }
	inline FAllPinIterator CreateAllPinsIterator() { return FAllPinIterator(this); }

	inline FInputPinConstIterator CreateInputPinsConstIterator() const { return FInputPinConstIterator(this); }
	inline FOutputPinConstIterator CreateOutputPinsConstIterator() const { return FOutputPinConstIterator(this); }
	inline FAllPinConstIterator CreateAllPinsConstIterator() { return FAllPinConstIterator(this); }

	inline FVoxelCompilationPin& GetInputPin(int I) { return *InputPins[I]; }
	inline FVoxelCompilationPin& GetOutputPin(int I) { return *OutputPins[I]; }
	inline const FVoxelCompilationPin& GetInputPin(int I) const { return *InputPins[I]; }
	inline const FVoxelCompilationPin& GetOutputPin(int I) const { return *OutputPins[I]; }
	inline FVoxelCompilationPin& GetPin(int I) { return Pins[I]; }
	inline const FVoxelCompilationPin& GetPin(int I) const { return Pins[I]; }

	inline int32 GetInputId(int I) const { return InputIds[I]; }
	inline int32 GetOutputId(int I) const { return OutputIds[I]; }

	inline void SetInputId(int I, int32 Id) { InputIds[I] = Id; }
	inline void SetOutputId(int I, int32 Id) { OutputIds[I] = Id; }

	inline int32 GetInputCount() const { return InputPins.Num(); }
	inline int32 GetOutputCount() const { return OutputPins.Num(); }
	inline int32 GetNumPins() const { return Pins.Num(); }

	inline int32 GetInputCountWithoutExecs() const { return InputIds.Num(); }
	inline int32 GetOutputCountWithoutExecs() const { return OutputIds.Num(); }

public:
	inline void BreakAllLinks()
	{
		for (auto& Pin : CreateAllPinsIterator())
		{
			Pin.BreakAllLinks();
		}
	}

public:
	//~ Begin FVoxelCompilationNode Interface
	virtual TSharedPtr<FVoxelCompilationNode> Clone(bool bFixLinks = false) const = 0;
	virtual TSharedPtr<FVoxelComputeNode> GetComputeNode() const
	{
		check(Node);
		return Node->GetComputeNode(this);
	}
	virtual EVoxelCompilationNodeType GetType() const = 0;
	virtual uint8 GetDefaultAxisDependencies() const { return 0; }
	virtual void LogErrors(class FVoxelGraphCompiler& Compiler) {}
	//~ End FVoxelCompilationNode Interface

public:
	inline const UVoxelNode* GetNode() const { return Node; }
	inline FString GetName() const { return Name; }
	inline void AddPrefixToName(const FString& Prefix) { Name = Prefix + Name; }

protected:
	template<typename T, typename... TArgs>
	TSharedPtr<T> CloneInternal(bool bFixLinks, TArgs... Args) const
	{		
		TSharedPtr<T> NewNode = MakeShareable(new T(Args...));
		NewNode->Dependencies = Dependencies;
		NewNode->SourceNode = SourceNode;
		for (auto& Pin : Pins)
		{
			int Index = NewNode->Pins.Emplace(NewNode.Get(), Pin.Index, Pin.Direction, Pin.PinCategory, Pin.Name);
			auto& NewPin = NewNode->Pins[Index];
			NewPin.DefaultValue = Pin.DefaultValue;
			NewPin.LinkedTo = Pin.LinkedTo;
		}
		NewNode->RebuildPinsArray();
		NewNode->InputIds = InputIds;
		NewNode->OutputIds = OutputIds;

		if (bFixLinks)
		{
			for (auto& Pin : NewNode->Pins)
			{
				for (auto& LinkedToPin : Pin.LinkedTo)
				{
					LinkedToPin->LinkedTo.Add(&Pin);
				}
			}
		}

		return NewNode;
	}
	template<typename T>
	TSharedPtr<T> CloneInternalDefault(bool bFixLinks) const
	{
		return CloneInternal<T>(bFixLinks, GetName(), TArray<EVoxelPinCategory>(), TArray<EVoxelPinCategory>(), Node);
	}
	
private:
	const UVoxelNode* const Node;

	TArray<FVoxelCompilationPin> Pins;
	TArray<FVoxelCompilationPin*> InputPins;
	TArray<FVoxelCompilationPin*> OutputPins;

	TArray<int32> InputIds;
	TArray<int32> OutputIds;

	FString Name;

	inline void RebuildPinsArray()
	{
		InputPins.Empty();
		OutputPins.Empty();
		for (auto& Pin : Pins)
		{
			if (Pin.Direction == EVoxelPinDirection::Input)
			{
				InputPins.Add(&Pin);
			}
			else
			{
				OutputPins.Add(&Pin);
			}
		}
	}
};

///////////////////////////////////////////////////////////////////////////////

class FVoxelDefaultCompilationNode : public FVoxelCompilationNode
{
public:
	using FVoxelCompilationNode::FVoxelCompilationNode;

	virtual TSharedPtr<FVoxelCompilationNode> Clone(bool bFixLinks) const override
	{
		return CloneInternalDefault<FVoxelDefaultCompilationNode>(bFixLinks);
	}
	virtual EVoxelCompilationNodeType GetType() const override
	{
		return EVoxelCompilationNodeType::Default;
	}

};

