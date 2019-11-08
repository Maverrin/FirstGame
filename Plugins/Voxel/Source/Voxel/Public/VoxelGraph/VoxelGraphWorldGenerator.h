// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraph.h"
#include "VoxelWorldGenerator.h"
#include "VoxelGraph/VoxelNode.h"
#include "VoxelConfigEnums.h"
#include "VoxelGraphWorldGenerator.generated.h"

#define VOXEL_PREVIEW_SIZE_SAVE 128

class UVoxelGraphGenerator;
class UEdGraphNode;
class FVoxelGraphCompiler;
struct FVoxelComputeNodeTreesHolder;
struct FVoxelLocalVariable;

#if WITH_EDITOR
/** 
 * Interface for voxel graph interaction with the VoxelEditor module.
 */
class IVoxelGraphEditor
{
public:
	virtual ~IVoxelGraphEditor() = default;

	/** Called when creating a new voxel graph. */
	virtual UEdGraph* CreateNewVoxelGraph(UVoxelGraphGenerator* InGenerator) = 0;

	/** Sets up a voxel node. */
	virtual void SetupVoxelNode(UEdGraph* VoxelGraph, UVoxelNode* VoxelNode, bool bSelectNewNode) = 0;

	/** Compiles voxel nodes from graph nodes. */
	virtual void CompileVoxelNodesFromGraphNodes(UVoxelGraphGenerator* WorldGenerator) = 0;

	/** Trigger a preview update if automatic updates are enabled */
	virtual void UpdatePreview(UVoxelGraphGenerator* WorldGenerator, bool bForce, bool bUpdateTextures) = 0;

	/** Creates an input pin on the given voxel graph node. */
	virtual void CreateInputPin(UEdGraphNode* VoxelNode) = 0;
	/** Creates an output pin on the given voxel graph node. */
	virtual void CreateOutputPin(UEdGraphNode* VoxelNode) = 0;

	virtual void SelectNodesAndZoomToFit(UEdGraph* Graph, TArray<UEdGraphNode*>& Nodes) = 0;

	virtual UVoxelGraphGenerator* GetWorldGeneratorFromGraph(UEdGraph* Graph) = 0;

	virtual void SetDebugGraph(UEdGraph* DebugGraph, FVoxelGraphCompiler* Compiler) = 0;

	virtual void RefreshNodesError(UEdGraph* Graph) = 0;
};
#endif

///////////////////////////////////////////////////////////////////////////////

UENUM()
enum class EVoxelGraphPreviewAxes
{
	X,
	Y,
	Z
};

UENUM()
enum class EVoxelGraphPreviewType
{
	Density,
	Material
};

UCLASS()
class VOXEL_API UVoxelGraphPreviewSettings : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Preview Settings")
	EVoxelMaterialConfig MaterialConfig = EVoxelMaterialConfig::RGB;

	UPROPERTY(EditAnywhere, Category = "Preview Settings")
	EVoxelGraphPreviewType ImagePreviewType = EVoxelGraphPreviewType::Density;

	UPROPERTY(EditAnywhere, Category = "Preview Settings")
	bool bUseDensityAsColor = true;
	
	UPROPERTY(EditAnywhere, Category = "Preview Settings")
	bool bEnableWater = false;

	UPROPERTY(EditAnywhere, Category = "Preview Settings")
	EVoxelGraphPreviewAxes LeftToRight = EVoxelGraphPreviewAxes::X;

	UPROPERTY(EditAnywhere, Category = "Preview Settings")
	EVoxelGraphPreviewAxes BottomToTop = EVoxelGraphPreviewAxes::Y;

	// Center (multiple of Voxels Per Pixel)
	UPROPERTY(EditAnywhere, Category = "Preview Settings", DisplayName = "Center (multiple of Voxels Per Pixel)")
	FIntVector Center = FIntVector(0, 0, 0);

	// Image Resolution (pow of 2)
	UPROPERTY(EditAnywhere, Category = "Preview Settings", DisplayName = "Image Resolution (pow of 2)")
	int32 ImageResolution = 512;

	// Voxels Per Pixel (pow of 2)
	UPROPERTY(EditAnywhere, Category = "Preview Settings", DisplayName = "Voxels Per Pixel (pow of 2)")
	int32 VoxelsPerPixel = 1;
	
	UPROPERTY(EditAnywhere, Category = "Density Settings", DisplayName = "Min Value (black)")
	float MinValue = -1;

	UPROPERTY(EditAnywhere, Category = "Density Settings", DisplayName = "Max Value (white)")
	float MaxValue = 1;
	
	UPROPERTY(EditAnywhere, Category = "Material Settings")
	TArray<FLinearColor> ColorsForIndexMaterialConfig = { FLinearColor::Green, FLinearColor::Red, FLinearColor::Blue, FLinearColor::White };

	UPROPERTY(EditAnywhere, Category = "3D Preview Settings", meta = (NoRebuild))
	class UStaticMesh* Mesh = nullptr;

	UPROPERTY(EditAnywhere, Category = "3D Preview Settings", meta = (NoRebuild))
	class UMaterialInterface* Material = nullptr;

	UPROPERTY(EditAnywhere, Category = "3D Preview Settings", meta = (NoRebuild))
	FVector MeshScale = FVector(10, 10, 10);

	UPROPERTY(EditAnywhere, Category = "3D Preview Settings", meta = (NoRebuild))
	float Height = 200;

	UPROPERTY(EditAnywhere, Category = "3D Preview Settings", meta = (NoRebuild))
	FVector LightDirection = FVector(1, 1, 1);

	UPROPERTY(EditAnywhere, Category = "3D Preview Settings", meta = (NoRebuild, UIMin = 0, UIMax = 1))
	float Brightness = 1;
	
	UPROPERTY(EditAnywhere, Category = "3D Preview Settings", meta = (NoRebuild, UIMin = 0))
	float ShadowDensity = 8;

	UPROPERTY()
	class UVoxelGraphGenerator* Graph;

protected:
#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostInitProperties() override;
	virtual void PostLoad() override;
	void InitVariables();
#endif
};

UENUM()
enum class EVoxelGraphGeneratorWorldKind
{
	Flat,
	Sphere
};

/**
 * A graph world generator
 */
UCLASS(BlueprintType, hidecategories = (Object), hidedropdown)
class VOXEL_API UVoxelGraphGenerator : public UVoxelWorldGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Generator settings", DisplayName = "World Kind (for grass & actors min/max angle)")
	EVoxelGraphGeneratorWorldKind WorldKind;

	UPROPERTY(EditAnywhere, Category = "Feedback")
	bool bShowAxisDependencies = false;

	UPROPERTY(EditAnywhere, Category = "Feedback")
	bool bEnableStats = false;

	
	UPROPERTY(EditAnywhere, Category = "Compile options")
	bool bInlineMacros = true;

	UPROPERTY(EditAnywhere, Category = "Compile options")
	bool bReplaceFlowMerges = true;

	UPROPERTY(EditAnywhere, Category = "Compile options")
	bool bCompactPassthroughs = true;

	UPROPERTY(EditAnywhere, Category = "Compile options")
	bool bDependenciesAnalysis = true;


	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bEnableDebug = false;
		
	UPROPERTY(EditAnywhere, Category = "Debug", meta = (EditCondition = bEnableDebug))
	float StepX = 1.5;

	UPROPERTY(EditAnywhere, Category = "Debug", meta = (EditCondition = bEnableDebug))
	float StepY = 1.5;
	
	UPROPERTY(EditAnywhere, Category = "Debug", meta = (EditCondition = bEnableDebug))
	bool bHideNonExecNodes = true;

	UPROPERTY()
	TArray<UVoxelNode*> AllNodes;

	UPROPERTY()
	UVoxelNode* FirstNode;

	UPROPERTY()
	FGuid FirstNodePindId;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	UVoxelGraphPreviewSettings* PreviewSettings;

	UPROPERTY()
	class UEdGraph* VoxelGraph;
	UPROPERTY()
	class UEdGraph* VoxelDebugGraph;

	UPROPERTY()
	TArray<UVoxelNode*> DebugNodes;

	class UTexture2D* GetPreviewTexture();
	void SetPreviewTexture(const TArray<FColor>& Colors, int Size);
#endif

	/**
	 * Create a new node of NewNodeClass
	 */
	UVoxelNode* ConstructNewNode(UClass* NewNodeClass, bool bSelectNewNode = true);

	/**
	 * Create the cpp file of this graph
	 */
	bool CompileToCpp(FString& OutCppText, const FString& Filename, FString& OutErrorMessage);
	/**
	 * Create the ComputeNodeTree of this graph
	 */
	bool CreateComputeTrees(FVoxelComputeNodeTreesHolder& OutTree, int32& OutMaxId, TMap<int, FVoxelLocalVariable>& OutLocalVariables, FString& OutError, bool bPreview);
	void CleanAllNodes();
	
	bool GetWorldGenerator(bool bPreview, TSharedPtr<class FVoxelGraphGeneratorInstance, ESPMode::ThreadSafe>& OutWorldGenerator);

	//~ Begin UVoxelWorldGenerator Interface
	TSharedRef<FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> GetWorldGenerator() override;
	//~ End UVoxelWorldGenerator Interface

#if WITH_EDITOR
	//~ Begin UObject Interface 
	void PostInitProperties() override;
	void PostLoad() override;
	//~ End UObject Interface
	
	/** Set up EdGraph parts of a VoxelNode */
	void SetupVoxelNode(UVoxelNode* InVoxelNode, bool bSelectNewNode = true);
	/** Create the basic voxel graph */
	void CreateGraphs();
	/** Get the EdGraph of VoxelNodes */
	class UEdGraph* GetGraph();
	/** Use the EdGraph representation to compile the VoxelNodes */
	void CompileVoxelNodesFromGraphNodes();


	/** Sets the voxel graph editor implementation.* */
	static void SetVoxelGraphEditor(TSharedPtr<IVoxelGraphEditor> InVoxelGraphEditor);
	/** Gets the voxel graph editor implementation. */
	static TSharedPtr<IVoxelGraphEditor> GetVoxelGraphEditor();

	inline static bool IsInEditor() { return GetVoxelGraphEditor().IsValid(); }

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TArray<FColor> PreviewTextureSave;

	UPROPERTY(Transient)
	class UTexture2D* PreviewTexture;
#endif

	/** Ptr to interface to voxel editor operations. */
	static TSharedPtr<IVoxelGraphEditor> VoxelGraphEditor;
#endif
};

class VOXEL_API FVoxelGraphGeneratorInstance : public FVoxelWorldGeneratorInstance
{
public:

	FVoxelGraphGeneratorInstance(int32 MaxId, TSharedRef<FVoxelComputeNodeTreesHolder> Tree, EVoxelGraphGeneratorWorldKind WorldKind);

	//~ Begin FVoxelWorldGeneratorInstance Interface
	void GetValuesAndMaterials(FVoxelValue Values[], FVoxelMaterial Materials[], const FIntBox& Bounds, const FIntVector& Offset, int LOD, const FIntVector& ArraySize, int QueryLOD, const FVoxelPlaceableItemHolder& ItemHolder) const override;
	void Init(const FVoxelWorldGeneratorInit& InitStruct) override;
	virtual FVector GetUpVector(int X, int Y, int Z) const override;
	//~ End FVoxelWorldGeneratorInstance Interface
	
	void InitPreview(const FVoxelWorldGeneratorInit& InitStruct) { Init(InitStruct); }
	void GetValuesAndMaterialsPreview(float Values[], FVoxelMaterial Materials[], const FIntBox& Bounds, const FIntVector& Offset, int LOD, const FIntVector& ArraySize) const;

private:
	const int32 MaxId; // Exclusive
	const TSharedRef<FVoxelComputeNodeTreesHolder> Tree;
	const EVoxelGraphGeneratorWorldKind WorldKind;

	template<typename T, typename F>
	void GetValuesAndMaterialsInternal(F Lambda, T Values[], FVoxelMaterial Materials[], const FIntBox& Bounds, const FIntVector& Offset, int LOD, const FIntVector& ArraySize, int QueryLOD, const FVoxelPlaceableItemHolder& ItemHolder) const;
};
