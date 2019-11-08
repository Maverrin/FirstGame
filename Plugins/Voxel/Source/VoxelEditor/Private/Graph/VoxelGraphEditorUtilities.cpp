// Copyright 2018 Phyronnaz

#include "VoxelGraphEditorUtilities.h"
#include "VoxelGraph.h"
#include "VoxelGraphNode.h"

#include "IVoxelGraphEditorToolkit.h"
#include "Toolkits/ToolkitManager.h"

#include "GraphEditor.h"

bool FVoxelGraphEditorUtilities::CanPasteNodes(const class UEdGraph* Graph)
{
	bool bCanPaste = false;
	TSharedPtr<class IVoxelGraphEditorToolkit> VoxelEditor = GetIVoxelEditorForObject(Graph);
	if (VoxelEditor.IsValid())
	{
		bCanPaste = VoxelEditor->CanPasteNodes();
	}
	return bCanPaste;
}

void FVoxelGraphEditorUtilities::PasteNodesHere(class UEdGraph* Graph, const FVector2D& Location)
{
	TSharedPtr<class IVoxelGraphEditorToolkit> VoxelEditor = GetIVoxelEditorForObject(Graph);
	if (VoxelEditor.IsValid())
	{
		VoxelEditor->PasteNodesHere(Location);
	}
}

bool FVoxelGraphEditorUtilities::GetBoundsForSelectedNodes(const UEdGraph* Graph, class FSlateRect& Rect, float Padding)
{
	TSharedPtr<class IVoxelGraphEditorToolkit> VoxelEditor = GetIVoxelEditorForObject(Graph);
	if (VoxelEditor.IsValid())
	{
		return VoxelEditor->GetBoundsForSelectedNodes(Rect, Padding);
	}
	return false;
}

int32 FVoxelGraphEditorUtilities::GetNumberOfSelectedNodes(const UEdGraph* Graph)
{
	TSharedPtr<class IVoxelGraphEditorToolkit> VoxelEditor = GetIVoxelEditorForObject(Graph);
	if (VoxelEditor.IsValid())
	{
		return VoxelEditor->GetNumberOfSelectedNodes();
	}
	return 0;
}

TSet<UObject*> FVoxelGraphEditorUtilities::GetSelectedNodes(const UEdGraph* Graph)
{
	TSharedPtr<class IVoxelGraphEditorToolkit> VoxelEditor = GetIVoxelEditorForObject(Graph);
	if (VoxelEditor.IsValid())
	{
		return VoxelEditor->GetSelectedNodes();
	}
	return TSet<UObject*>();
}

TSharedPtr<class IVoxelGraphEditorToolkit> FVoxelGraphEditorUtilities::GetIVoxelEditorForObject(const UObject* ObjectToFocusOn)
{
	check(ObjectToFocusOn);

	// Find the associated Voxel
	UVoxelGraphGenerator* Voxel = Cast<const UVoxelGraph>(ObjectToFocusOn)->GetWorldGenerator();

	TSharedPtr<IVoxelGraphEditorToolkit> VoxelEditor;
	if (Voxel != NULL)
	{
		TSharedPtr< IToolkit > FoundAssetEditor = FToolkitManager::Get().FindEditorForAsset(Voxel);
		if (FoundAssetEditor.IsValid())
		{
			VoxelEditor = StaticCastSharedPtr<IVoxelGraphEditorToolkit>(FoundAssetEditor);
		}
	}
	return VoxelEditor;
}
