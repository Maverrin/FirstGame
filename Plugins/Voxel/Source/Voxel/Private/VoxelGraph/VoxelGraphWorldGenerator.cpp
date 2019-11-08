// Copyright 2018 Phyronnaz

#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "EdGraph/EdGraphSchema.h"
#include "VoxelLogStatDefinitions.h"
#include "VoxelWorldGenerators/EmptyWorldGenerator.h"
#include "VoxelDebug/VoxelCrashReporter.h"
#include "Engine/Texture2D.h"
#include "VoxelGraph/VoxelCppConstructor.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelGraph/VoxelGraphMacro.h"
#include "VoxelGraph/VoxelFlowMergePass.h"
#include "VoxelGraph/VoxelCompactPassthroughsPass.h"
#include "VoxelGraph/VoxelMarkDependenciesPass.h"
#include "VoxelGraph/VoxelPortalNode.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"

#if WITH_EDITOR
void UVoxelGraphPreviewSettings::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	ImageResolution = FMath::Clamp(1 << FMath::FloorLog2(ImageResolution), 32, 4096);
	VoxelsPerPixel = FMath::Max(1 << FMath::FloorLog2(VoxelsPerPixel), 1);

	Center.X = FMath::RoundToInt(Center.X / float(VoxelsPerPixel)) * VoxelsPerPixel;
	Center.Y = FMath::RoundToInt(Center.Y / float(VoxelsPerPixel)) * VoxelsPerPixel;
	Center.Z = FMath::RoundToInt(Center.Z / float(VoxelsPerPixel)) * VoxelsPerPixel;
	
	if (!Mesh)
	{
		Mesh = LoadObject<UStaticMesh>(this, TEXT("/Voxel/Preview/SM_Plane"));
	}
	if (!Material)
	{
		Material = LoadObject<UMaterialInterface>(this, TEXT("/Voxel/Preview/M_PreviewMaterial"));
	}

	if (Graph && PropertyChangedEvent.MemberProperty)
	{
		static FName NoRebuild(TEXT("NoRebuild"));
		if (PropertyChangedEvent.MemberProperty->HasMetaData(NoRebuild))
		{
			UVoxelGraphGenerator::GetVoxelGraphEditor()->UpdatePreview(Graph, true, false);
		}
		else if (PropertyChangedEvent.ChangeType != EPropertyChangeType::Interactive)
		{
			UVoxelGraphGenerator::GetVoxelGraphEditor()->UpdatePreview(Graph, true, true);
		}
	}
}

void UVoxelGraphPreviewSettings::PostInitProperties()
{
	Super::PostInitProperties();

	if (!HasAnyFlags(RF_ClassDefaultObject | RF_NeedLoad))
	{
		InitVariables();
	}
}

void UVoxelGraphPreviewSettings::PostLoad()
{
	Super::PostLoad();

	InitVariables();
}

void UVoxelGraphPreviewSettings::InitVariables()
{
	if (!Mesh)
	{
		Mesh = LoadObject<UStaticMesh>(this, TEXT("/Voxel/Preview/SM_Plane"));
	}
	if (!Material)
	{
		Material = LoadObject<UMaterialInterface>(this, TEXT("/Voxel/Preview/M_PreviewMaterial"));
	}
}
#endif

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

#if WITH_EDITORONLY_DATA
UTexture2D* UVoxelGraphGenerator::GetPreviewTexture()
{
	if (!PreviewTexture)
	{
		PreviewTexture = UTexture2D::CreateTransient(VOXEL_PREVIEW_SIZE_SAVE, VOXEL_PREVIEW_SIZE_SAVE);

		PreviewTextureSave.SetNumZeroed(VOXEL_PREVIEW_SIZE_SAVE * VOXEL_PREVIEW_SIZE_SAVE);

		FTexture2DMipMap& Mip = PreviewTexture->PlatformData->Mips[0];

		void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);
		FMemory::Memcpy(Data, PreviewTextureSave.GetData(), PreviewTextureSave.Num() * sizeof(FColor));

		Mip.BulkData.Unlock();
		PreviewTexture->UpdateResource();
	}

	return PreviewTexture;
}

void UVoxelGraphGenerator::SetPreviewTexture(const TArray<FColor>& Colors, int Size)
{
	check(Colors.Num() == Size * Size);

	PreviewTextureSave.SetNum(VOXEL_PREVIEW_SIZE_SAVE * VOXEL_PREVIEW_SIZE_SAVE);

	for (int X = 0; X < VOXEL_PREVIEW_SIZE_SAVE; X++)
	{
		for (int Y = 0; Y < VOXEL_PREVIEW_SIZE_SAVE; Y++)
		{
			PreviewTextureSave[X + Y * VOXEL_PREVIEW_SIZE_SAVE] = Colors[X * Size / VOXEL_PREVIEW_SIZE_SAVE + (Y * Size / VOXEL_PREVIEW_SIZE_SAVE) * Size];
		}
	}

	PreviewTexture = nullptr;
}
#endif

UVoxelNode * UVoxelGraphGenerator::ConstructNewNode(UClass* NewNodeClass, bool bSelectNewNode /*= true*/)
{
	UVoxelNode* VoxelNode = NewObject<UVoxelNode>(this, NewNodeClass, NAME_None, RF_Transactional);
#if WITH_EDITOR
	VoxelNode->Graph = this;
	SetupVoxelNode(VoxelNode, bSelectNewNode);
#endif // WITH_EDITORONLY_DATA

	return VoxelNode;
}

bool UVoxelGraphGenerator::CompileToCpp(FString& OutCpp, const FString& Filename, FString& OutErrorMessage)
{
	FVoxelCppConstructor Constructor(Filename, this);
	if (Constructor.Compile(OutErrorMessage))
	{
		OutCpp = Constructor.GetCode();
		return true;
	}
	else
	{
		return false;
	}
}

bool UVoxelGraphGenerator::CreateComputeTrees(FVoxelComputeNodeTreesHolder& OutTree, int32& OutMaxId, TMap<int, FVoxelLocalVariable>& OutLocalVariables, FString& OutError, bool bPreview)
{
	CleanAllNodes();

	if (!FirstNode && !bPreview)
	{
		OutError = TEXT("First node not connected");
		return false;
	}
	
	FVoxelGraphCompiler Compiler(this, AllNodes, FirstNode, FirstNode ? FirstNode->GetInputPinIndex(FirstNodePindId) : 0);
	
	if (bInlineMacros)
	{
		Compiler.ApplyPass<FVoxelGraphInlineMacrosPass>();
	}
	Compiler.ApplyPass<FReplaceVoxelPortalNodesPass>();

	if (bPreview && bInlineMacros)
	{
		UVoxelNode* NodePreviewed = nullptr;
		for (auto& Node : AllNodes)
		{
			if (Node->bIsPreviewing)
			{
				if (!NodePreviewed)
				{
					NodePreviewed = Node;
				}
				else
				{
					Node->bIsPreviewing = false;
				}
			}
		}
		if (NodePreviewed)
		{
			Compiler.SetPreviewedNode(NodePreviewed);
		}
		else if (!FirstNode)
		{
			OutError = TEXT("First node not connected");
			return false;
		}
	}

	if (bReplaceFlowMerges)
	{
		Compiler.ApplyPass<FVoxelFlowMergePass>();
	}
	if (bCompactPassthroughs)
	{
		Compiler.ApplyPass<FVoxelCompactPassthroughsPass>();
	}

	if (bDependenciesAnalysis)
	{
		Compiler.ApplyPass<FVoxelMarkDependenciesPass>();
	}

	if (!bReplaceFlowMerges || !bInlineMacros)
	{
		Compiler.AddError("!bReplaceFlowMerges || !bInlineMacros");
	}

	bool bSuccess = Compiler.Compile(OutTree, OutMaxId, OutLocalVariables, OutError);

	if (bShowAxisDependencies)
	{
		Compiler.ApplyPass<FVoxelDebugDependenciesPass>();
	}

#if WITH_EDITOR
	if (bEnableDebug && IsInEditor())
	{
		GetVoxelGraphEditor()->SetDebugGraph(VoxelDebugGraph, &Compiler);
	}
#endif

	OutTree.ForAll([&](auto& Tree) { Tree.SetEnableStats(bEnableStats); });

	return bSuccess;
}

void UVoxelGraphGenerator::CleanAllNodes()
{
	AllNodes.Remove(nullptr);
	TSet<UVoxelNode*> Nodes;
	for (auto& Node : AllNodes)
	{
		check(!Nodes.Contains(Node));
		check(Node);
		Nodes.Add(Node);
	}
}

bool UVoxelGraphGenerator::GetWorldGenerator(bool bPreview, TSharedPtr<FVoxelGraphGeneratorInstance, ESPMode::ThreadSafe>& OutWorldGenerator)
{
	TSharedRef<FVoxelComputeNodeTreesHolder> Tree = MakeShared<FVoxelComputeNodeTreesHolder>();
	int32 MaxId;
	TMap<int, FVoxelLocalVariable> LocalVariables;
	FString CompileError;
	if (!CreateComputeTrees(*Tree, MaxId, LocalVariables, CompileError, bPreview))
	{
		FVoxelCrashReporter::ShowError(CompileError.IsEmpty() ? TEXT("Failed to compile the graph!") : CompileError, false);
		return false;
	}
	else
	{
		OutWorldGenerator = MakeShared<FVoxelGraphGeneratorInstance, ESPMode::ThreadSafe>(MaxId, Tree, WorldKind);
		return true;
	}
}

TSharedRef<FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> UVoxelGraphGenerator::GetWorldGenerator()
{
	TSharedPtr<FVoxelGraphGeneratorInstance, ESPMode::ThreadSafe> GraphWorldGenerator;
	if (GetWorldGenerator(false, GraphWorldGenerator))
	{
		return GraphWorldGenerator.ToSharedRef();
	}
	else
	{
		return MakeShared<FEmptyWorldGeneratorInstance, ESPMode::ThreadSafe>();
	}
}

#if WITH_EDITOR

void UVoxelGraphGenerator::PostInitProperties()
{
	Super::PostInitProperties();
	if (!HasAnyFlags(RF_ClassDefaultObject | RF_NeedLoad))
	{
		CreateGraphs();
	}
}

void UVoxelGraphGenerator::PostLoad()
{
	Super::PostLoad();

	CreateGraphs();
}

void UVoxelGraphGenerator::SetupVoxelNode(UVoxelNode* InVoxelNode, bool bSelectNewNode /*= true*/)
{
	// Create the graph node
	check(InVoxelNode->GraphNode == NULL);
	AllNodes.Add(InVoxelNode); // To have valid list even without compiling
	UVoxelGraphGenerator::GetVoxelGraphEditor()->SetupVoxelNode(VoxelGraph, InVoxelNode, bSelectNewNode);
}

void UVoxelGraphGenerator::CreateGraphs()
{
	if (IsInEditor())
	{
		if (!VoxelGraph)
		{
			VoxelGraph = UVoxelGraphGenerator::GetVoxelGraphEditor()->CreateNewVoxelGraph(this);
			VoxelGraph->bAllowDeletion = false;

			// Give the schema a chance to fill out any required nodes (like the results node)
			const UEdGraphSchema* Schema = VoxelGraph->GetSchema();
			Schema->CreateDefaultNodesForGraph(*VoxelGraph);
		}
		if (!VoxelDebugGraph)
		{
			VoxelDebugGraph = UVoxelGraphGenerator::GetVoxelGraphEditor()->CreateNewVoxelGraph(this);
			VoxelDebugGraph->bAllowDeletion = false;
		}
	}
}

UEdGraph* UVoxelGraphGenerator::GetGraph()
{
	return VoxelGraph;
}

void UVoxelGraphGenerator::CompileVoxelNodesFromGraphNodes()
{
	UVoxelGraphGenerator::GetVoxelGraphEditor()->CompileVoxelNodesFromGraphNodes(this);
	AllNodes.Remove(nullptr);
}

void UVoxelGraphGenerator::SetVoxelGraphEditor(TSharedPtr<IVoxelGraphEditor> InVoxelGraphEditor)
{
	check(!VoxelGraphEditor.IsValid());
	VoxelGraphEditor = InVoxelGraphEditor;
}

TSharedPtr<IVoxelGraphEditor> UVoxelGraphGenerator::GetVoxelGraphEditor()
{
	return VoxelGraphEditor;
}

TSharedPtr<IVoxelGraphEditor> UVoxelGraphGenerator::VoxelGraphEditor = nullptr;

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

FVoxelGraphGeneratorInstance::FVoxelGraphGeneratorInstance(int32 MaxId, TSharedRef<FVoxelComputeNodeTreesHolder> Tree, EVoxelGraphGeneratorWorldKind WorldKind)
	: MaxId(MaxId)
	, Tree(Tree)
	, WorldKind(WorldKind)
{
	check(MaxId < MAX_VARIABLES);
}

void FVoxelGraphGeneratorInstance::GetValuesAndMaterials(FVoxelValue Values[], FVoxelMaterial Materials[], const FIntBox& Bounds, const FIntVector& Offset, int LOD, const FIntVector& ArraySize, int QueryLOD, const FVoxelPlaceableItemHolder& ItemHolder) const
{
	GetValuesAndMaterialsInternal<FVoxelValue>(
		[](FVoxelValue* Values, FVoxelMaterial* Materials, const FIntVector& Offset, int LOD, const FIntVector& ArraySize, const FVoxelPlaceableItemHolder& ItemHolder, int X, int Y, int Z, const FVoxelValue& Value, const FVoxelMaterial& Material)
		{
			SetValueAndMaterial(Values, Materials, Offset, LOD, ArraySize, ItemHolder, X, Y, Z, Value, Material);
		}, 
		Values, Materials, Bounds, Offset, LOD, ArraySize, QueryLOD, ItemHolder);
}

void FVoxelGraphGeneratorInstance::Init(const FVoxelWorldGeneratorInit& InitStruct)
{
	FVoxelNodeType* Variables = FVoxelComputeNodeTree::GetVariablesBuffer();
	FVoxelNodeType* InputOutputBuffer = FVoxelComputeNodeTree::GetInputOutputBuffer();
	Tree->ConstantsTree.Init(Variables, InputOutputBuffer, InitStruct);
	Tree->XTree.Init(Variables, InputOutputBuffer, InitStruct);
	Tree->XYTree.Init(Variables, InputOutputBuffer, InitStruct);
	Tree->XYZTree.Init(Variables, InputOutputBuffer, InitStruct);
}

FVector FVoxelGraphGeneratorInstance::GetUpVector(int X, int Y, int Z) const
{
	switch (WorldKind)
	{
	case EVoxelGraphGeneratorWorldKind::Sphere:
		return FVector(X, Y, Z).GetSafeNormal();
	case EVoxelGraphGeneratorWorldKind::Flat:
	default:
		return FVector::UpVector;
	}
}

void FVoxelGraphGeneratorInstance::GetValuesAndMaterialsPreview(float Values[], FVoxelMaterial Materials[], const FIntBox& Bounds, const FIntVector& Offset, int LOD, const FIntVector& ArraySize) const
{
	GetValuesAndMaterialsInternal<float>(
		[](float* Values, FVoxelMaterial* Materials, const FIntVector& Offset, int LOD, const FIntVector& ArraySize, const FVoxelPlaceableItemHolder& ItemHolder, int X, int Y, int Z, const float& Value, const FVoxelMaterial& Material)
		{
			int Index = GetIndex(X, Y, Z, Offset, LOD, ArraySize);
			if (Values)
			{
				Values[Index] = Value;
			}
			if (Materials)
			{
				Materials[Index] = Material;
			}
		}, 
		Values, Materials, Bounds, Offset, LOD, ArraySize, 0, FVoxelPlaceableItemHolder());
}

template<typename T, typename F>
void FVoxelGraphGeneratorInstance::GetValuesAndMaterialsInternal(F Lambda, T Values[], FVoxelMaterial Materials[], const FIntBox& Bounds, const FIntVector& Offset, int LOD, const FIntVector& ArraySize, int QueryLOD, const FVoxelPlaceableItemHolder& ItemHolder) const
{
	FVoxelNodeType* Variables = FVoxelComputeNodeTree::GetVariablesBuffer();
	FVoxelNodeType* InputOutputBuffer = FVoxelComputeNodeTree::GetInputOutputBuffer();

	FVoxelContext Context(ItemHolder, QueryLOD);

	const int Step = 1 << LOD;

	check(Bounds.IsMultipleOf(Step));

	{
		float DummyValue = 1;
		FVoxelMaterial DummyMaterial;
		Tree->ConstantsTree.Compute(Variables, InputOutputBuffer, Context, DummyValue, DummyMaterial);
	}
	for (int X = Bounds.Min.X; X < Bounds.Max.X; X += Step)
	{
		Context.X = X;
		{
			float DummyValue = 1;
			FVoxelMaterial DummyMaterial;
			Tree->XTree.Compute(Variables, InputOutputBuffer, Context, DummyValue, DummyMaterial);
		}
		for (int Y = Bounds.Min.Y; Y < Bounds.Max.Y; Y += Step)
		{
			Context.Y = Y;
			{
				float DummyValue = 1;
				FVoxelMaterial DummyMaterial;
				Tree->XYTree.Compute(Variables, InputOutputBuffer, Context, DummyValue, DummyMaterial);
			}
			for (int Z = Bounds.Min.Z; Z < Bounds.Max.Z; Z += Step)
			{				
				Context.Z = Z;
				float Value = 1;
				FVoxelMaterial Material;

				Tree->XYZTree.Compute(Variables, InputOutputBuffer, Context, Value, Material);

				Lambda(Values, Materials, Offset, LOD, ArraySize, ItemHolder, X, Y, Z, Value, Material);
			}
		}
	}
}

