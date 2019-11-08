// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelNode.h"
#include "Misc/ScopeLock.h"
#include "VoxelGlobals.h"

union FVoxelNodeType;
class FVoxelCppConstructor;
struct FVoxelWorldGeneratorInit;
struct FVoxelContext;
struct FVoxelMaterial;
class FVoxelComputeNode;

enum EVoxelAxisDependencies : int8
{
	Constant = 0,
	X = 1,
	XY = 2,
	XYZ = 3
};

///////////////////////////////////////////////////////////////////////////////

struct FVoxelLocalVariable
{
	EVoxelPinCategory const Type;
	FString const Name;
	EVoxelAxisDependencies const Dependencies;

	FVoxelLocalVariable(EVoxelPinCategory Type, const FString& Name, EVoxelAxisDependencies Dependencies)
		: Type(Type)
		, Name(Name)
		, Dependencies(Dependencies)
	{
	}
	inline FString GetTypeString() const { return FVoxelPinCategory::ToString(Type); }
	inline FString GetInitName() const { return Name + TEXT("_INIT"); }
	inline FString GetDeclaration() const { return GetTypeString() + TEXT(" ") + Name + TEXT(";"); }
	inline FString GetInitDeclaration() const { return GetTypeString() + TEXT(" ") + GetInitName() + TEXT(";"); }
};

///////////////////////////////////////////////////////////////////////////////

struct FVoxelGraphPerfCounter
{
	struct FNodePerf
	{
		uint64 NumCalls = 0;
		uint64 NumCycles = 0;
	};

	~FVoxelGraphPerfCounter()
	{
		if (this != &Singleton)
		{
			FScopeLock Lock(&Section);

			for (auto& PerfIt : PerfMap)
			{
				auto& Perf = Singleton.PerfMap.FindOrAdd(PerfIt.Key);
				Perf.NumCalls += PerfIt.Value.NumCalls;
				Perf.NumCycles += PerfIt.Value.NumCycles;
			}
		}
	}

	inline void LogNode(const UVoxelNode* const Node, uint64 Cycles)
	{
		auto& Perf = PerfMap.FindOrAdd(Node);
		Perf.NumCalls++;
		Perf.NumCycles += Cycles;
	}

public:
	inline static void Reset()
	{
		Singleton.PerfMap.Empty();
	}

	inline static TMap<const UVoxelNode* const, FNodePerf>& GetSingletonMap()
	{
		return Singleton.PerfMap;
	}

private:
	TMap<const UVoxelNode* const, FNodePerf> PerfMap;

	static FVoxelGraphPerfCounter Singleton;
	static FCriticalSection Section;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Tree of the compute nodes. Used to interpret the graph at runtime and to compile it
 */
struct FVoxelComputeNodeTree
{	
	FVoxelComputeNodeTree() = default;

	// Runtime
	void Init(FVoxelNodeType Variables[], FVoxelNodeType InputOutputBuffer[], const FVoxelWorldGeneratorInit& InitStruct) const;
	void Compute(FVoxelNodeType Variables[], FVoxelNodeType InputOutputBuffer[], const FVoxelContext& Context, float& Value, FVoxelMaterial& Material) const;

	// Compilation
	void SetupConstructor(FVoxelCppConstructor& Constructor) const;
	void InitCpp(FVoxelCppConstructor& Constructor) const;
	void ComputeCpp(FVoxelCppConstructor& Constructor);

	inline void SetEnableStats(bool bEnable)
	{
		bEnableStats = bEnable;
		for (auto& Child : Children)
		{
			Child.SetEnableStats(bEnable);
		}
	}

public:
	static inline FVoxelNodeType* GetInputOutputBuffer()
	{
		VOXEL_THREADLOCAL TArray<FVoxelNodeType> Buffer;
		VOXEL_THREADLOCAL FVoxelNodeType* BufferPtr = nullptr;
		if (UNLIKELY(!BufferPtr))
		{
			Buffer.SetNumUninitialized(2 * MAX_PINS);
			BufferPtr = Buffer.GetData();
		}
		return BufferPtr;
	}
	static inline FVoxelNodeType* GetVariablesBuffer()
	{
		VOXEL_THREADLOCAL TArray<FVoxelNodeType> Buffer;
		VOXEL_THREADLOCAL FVoxelNodeType* BufferPtr = nullptr;
		if (UNLIKELY(!BufferPtr))
		{
			Buffer.SetNumUninitialized(MAX_VARIABLES);
			BufferPtr = Buffer.GetData();
		}
		return BufferPtr;
	}

	static inline FVoxelNodeType* GetInputBuffer(FVoxelNodeType* InputOutputBuffer)
	{
		return InputOutputBuffer;
	}
	static inline FVoxelNodeType* GetOutputBuffer(FVoxelNodeType* InputOutputBuffer)
	{
		return InputOutputBuffer + MAX_PINS;
	}

private:
	TArray<TSharedPtr<FVoxelComputeNode>> Nodes;
	TSharedPtr<FVoxelComputeNode> BranchNode;
	TArray<FVoxelComputeNodeTree> Children;
	bool bEnableStats = false;
	
	template<bool bEnableStats> 
	void ComputeInternal(FVoxelNodeType Variables[], FVoxelNodeType InputBuffer[], FVoxelNodeType OutputBuffer[], const FVoxelContext& Context, float& Value, FVoxelMaterial& Material) const;

	friend class FVoxelCompilationNodeTree;
};

///////////////////////////////////////////////////////////////////////////////

struct FVoxelComputeNodeTreesHolder
{	
	FVoxelComputeNodeTree ConstantsTree;
	FVoxelComputeNodeTree XTree;
	FVoxelComputeNodeTree XYTree;
	FVoxelComputeNodeTree XYZTree;

	template<typename F>
	inline void ForAll(F Lambda)
	{
		Lambda(ConstantsTree);
		Lambda(XTree);
		Lambda(XYTree);
		Lambda(XYZTree);
	}
};
