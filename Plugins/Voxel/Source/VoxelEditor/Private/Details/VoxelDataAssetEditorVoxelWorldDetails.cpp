// Copyright 2018 Phyronnaz

#include "VoxelDataAssetEditorVoxelWorldDetails.h"
#include "DataAssetEditor/VoxelDataAssetEditorVoxelWorld.h"
#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"

#include "VoxelEditorDetailsUtils.h"

#define LOCTEXT_NAMESPACE "DataAssetEditorVoxelWorldDetails"

TSharedRef<IDetailCustomization> FVoxelDataAssetEditorVoxelWorldDetails::MakeInstance()
{
	return MakeShareable(new FVoxelDataAssetEditorVoxelWorldDetails());
}

FVoxelDataAssetEditorVoxelWorldDetails::FVoxelDataAssetEditorVoxelWorldDetails()
{

}

void FVoxelDataAssetEditorVoxelWorldDetails::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	World = FVoxelEditorDetailsUtils::GetCurrentObjectFromDetails<AVoxelDataAssetEditorVoxelWorld>(DetailLayout);
	World->UpdateCollisionProfile();

	World->PostEditChange();

	DetailLayout.HideCategory("Tick");
	DetailLayout.HideCategory("TransformCommon");
	DetailLayout.HideCategory("Rendering");
	DetailLayout.HideCategory("Replication");
	DetailLayout.HideCategory("Input");
	DetailLayout.HideCategory("Actor");
	DetailLayout.HideCategory("HLOD");
	DetailLayout.HideCategory("LOD");
	DetailLayout.HideCategory("Voxel");
	DetailLayout.HideCategory("Cooking");
	
	ADD_PROPERTY_TO_CATEGORY("Voxel World Config", "VoxelSize", AVoxelWorld);
	ADD_PROPERTY_TO_CATEGORY("Voxel World Config", "RenderType", AVoxelWorld);
	ADD_PROPERTY_TO_CATEGORY("Voxel World Config", "NormalConfig", AVoxelWorld);
	ADD_PROPERTY_TO_CATEGORY("Voxel World Config", "MaterialConfig", AVoxelWorld);
	ADD_PROPERTY_TO_CATEGORY("Voxel World Config", "VoxelMaterial", AVoxelWorld);
	ADD_PROPERTY_TO_CATEGORY("Voxel World Config", "MaterialCollection", AVoxelWorld);
	
	ADD_PROPERTY_TO_CATEGORY("Voxel World Config", "bShowWorldBounds", AVoxelWorld);
	ADD_PROPERTY_TO_CATEGORY("Voxel World Config", "WorldBoundsThickness", AVoxelWorld);
	ADD_PROPERTY_TO_CATEGORY("Voxel World Config", "bShowDirtyDataOctreeLeaves", AVoxelWorld);
	ADD_PROPERTY_TO_CATEGORY("Voxel World Config", "DirtyDataOctreeLeavesThickness", AVoxelWorld);
}

#undef LOCTEXT_NAMESPACE
