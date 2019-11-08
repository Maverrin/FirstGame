// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
struct FIntVector;
struct FIntBox;
struct FLinearColor;
struct FVoxelCompressedWorldSave;
struct FVoxelUncompressedWorldSave;
struct FVoxelMaterial;
class UCurveFloat;
struct FBodyInstance;
struct FLightingChannels;
class UVoxelActorSpawner;
class UVoxelGrassSpawner;
class UVoxelMaterialCollection;
class UMaterialInterface;
enum class EVoxelMaterialConfig : uint8;
enum class EVoxelNormalConfig : uint8;
enum class EVoxelUVConfig : uint8;
enum class EVoxelRenderType : uint8;
 
class UVoxelWorldSaveObject;
class UVoxelWorldGenerator;
class UTexture;
class UHierarchicalInstancedStaticMeshComponent;
class AVoxelActor;
struct FTransform;
class UObject;
#ifdef VOXEL_VoxelWorld_generated_h
#error "VoxelWorld.generated.h already included, missing '#pragma once' in VoxelWorld.h"
#endif
#define VOXEL_VoxelWorld_generated_h

#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_43_DELEGATE \
static inline void FOnWorldLoaded_DelegateWrapper(const FMulticastScriptDelegate& OnWorldLoaded) \
{ \
	OnWorldLoaded.ProcessMulticastDelegate<UObject>(NULL); \
}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_42_DELEGATE \
static inline void FOnClientConnection_DelegateWrapper(const FMulticastScriptDelegate& OnClientConnection) \
{ \
	OnClientConnection.ProcessMulticastDelegate<UObject>(NULL); \
}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAddWorms) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Seed); \
		P_GET_STRUCT(FVector,Z_Param_RotationAmplitude); \
		P_GET_STRUCT(FVector,Z_Param_NoiseDir); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NoiseSegmentLength); \
		P_GET_STRUCT(FVector,Z_Param_Start); \
		P_GET_STRUCT(FVector,Z_Param_InitialDir); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VoxelSegmentLength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_NumSegments); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_SplitProbability); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_SplitProbabilityGain); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BranchMeanSize); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BranchSizeVariation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddWorms(Z_Param_Radius,Z_Param_Seed,Z_Param_RotationAmplitude,Z_Param_NoiseDir,Z_Param_NoiseSegmentLength,Z_Param_Start,Z_Param_InitialDir,Z_Param_VoxelSegmentLength,Z_Param_NumSegments,Z_Param_SplitProbability,Z_Param_SplitProbabilityGain,Z_Param_BranchMeanSize,Z_Param_BranchSizeVariation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddOffset) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_OffsetInVoxels); \
		P_GET_UBOOL(Z_Param_bMoveActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddOffset(Z_Param_Out_OffsetInVoxels,Z_Param_bMoveActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCache) \
	{ \
		P_GET_TARRAY_REF(FIntBox,Z_Param_Out_BoundsToCache); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Cache(Z_Param_Out_BoundsToCache); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearCache) \
	{ \
		P_GET_TARRAY_REF(FIntBox,Z_Param_Out_BoundsToKeepCached); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ClearCache(Z_Param_Out_BoundsToKeepCached); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDebugVoxelsInsideBox) \
	{ \
		P_GET_STRUCT(FIntBox,Z_Param_Box); \
		P_GET_STRUCT(FLinearColor,Z_Param_Color); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Lifetime); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Thickness); \
		P_GET_UBOOL(Z_Param_bDebugDensities); \
		P_GET_STRUCT(FLinearColor,Z_Param_TextColor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DebugVoxelsInsideBox(Z_Param_Box,Z_Param_Color,Z_Param_Lifetime,Z_Param_Thickness,Z_Param_bDebugDensities,Z_Param_TextColor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDrawDebugIntBox) \
	{ \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Box); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Lifetime); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Thickness); \
		P_GET_STRUCT(FLinearColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DrawDebugIntBox(Z_Param_Out_Box,Z_Param_Lifetime,Z_Param_Thickness,Z_Param_Color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearFrames) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ClearFrames(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveFrame) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SaveFrame(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRedo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Redo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUndo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Undo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartServer) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Ip); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Port); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StartServer(Z_Param_Ip,Z_Param_Port); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConnectClient) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Ip); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Port); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ConnectClient(Z_Param_Ip,Z_Param_Port); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadFromCompressedSave) \
	{ \
		P_GET_STRUCT_REF(FVoxelCompressedWorldSave,Z_Param_Out_Save); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadFromCompressedSave(Z_Param_Out_Save); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadFromSave) \
	{ \
		P_GET_STRUCT_REF(FVoxelUncompressedWorldSave,Z_Param_Out_Save); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadFromSave(Z_Param_Out_Save); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCompressedSave) \
	{ \
		P_GET_STRUCT_REF(FVoxelCompressedWorldSave,Z_Param_Out_OutSave); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetCompressedSave(Z_Param_Out_OutSave); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSave) \
	{ \
		P_GET_STRUCT_REF(FVoxelUncompressedWorldSave,Z_Param_Out_OutSave); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetSave(Z_Param_Out_OutSave); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterial) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_GET_STRUCT_REF(FVoxelMaterial,Z_Param_Out_Material); \
		P_GET_UBOOL(Z_Param_bUpdateRender); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMaterial(Z_Param_Out_Position,Z_Param_Out_Material,Z_Param_bUpdateRender); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaterial) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=P_THIS->GetMaterial(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetValue) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_GET_UBOOL(Z_Param_bUpdateRender); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetValue(Z_Param_Out_Position,Z_Param_Value,Z_Param_bUpdateRender); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetValue) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetValue(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNormal) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetNormal(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntersection) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Start); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_End); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_GlobalPosition); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_VoxelPosition); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIntersection(Z_Param_Out_Start,Z_Param_Out_End,Z_Param_Out_GlobalPosition,Z_Param_Out_VoxelPosition); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsInside) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsInside(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsInWorld) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsInWorld(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLODAt) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetLODAt(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateAll) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateAll(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateChunksOverlappingBox) \
	{ \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Box); \
		P_GET_UBOOL(Z_Param_bRemoveHoles); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateChunksOverlappingBox(Z_Param_Out_Box,Z_Param_bRemoveHoles); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateChunksAtPosition) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateChunksAtPosition(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNeighboringPositions) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_GlobalPosition); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FIntVector>*)Z_Param__Result=P_THIS->GetNeighboringPositions(Z_Param_Out_GlobalPosition); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLocalToGlobalFloat) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->LocalToGlobalFloat(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLocalToGlobal) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->LocalToGlobal(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGlobalToLocalFloat) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GlobalToLocalFloat(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGlobalToLocal) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=P_THIS->GlobalToLocal(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTaskCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetTaskCount(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBounds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntBox*)Z_Param__Result=P_THIS->GetBounds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsCreated) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsCreated(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMultiplayerSyncRate) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetMultiplayerSyncRate(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMultiplayerSyncRate) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewMultiplayerSyncRate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMultiplayerSyncRate(Z_Param_NewMultiplayerSyncRate); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMultiplayer) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetMultiplayer(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMultiplayer) \
	{ \
		P_GET_UBOOL(Z_Param_bNewMultiplayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMultiplayer(Z_Param_bNewMultiplayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetOptimizeIndices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetOptimizeIndices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetOptimizeIndices) \
	{ \
		P_GET_UBOOL(Z_Param_bNewOptimizeIndices); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetOptimizeIndices(Z_Param_bNewOptimizeIndices); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLODCurve) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UCurveFloat**)Z_Param__Result=P_THIS->GetLODCurve(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLODCurve) \
	{ \
		P_GET_OBJECT(UCurveFloat,Z_Param_NewCurve); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetLODCurve(Z_Param_NewCurve); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMeshThreadCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetMeshThreadCount(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMeshThreadCount) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewMeshThreadCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMeshThreadCount(Z_Param_NewMeshThreadCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetDontUseGlobalPool) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetDontUseGlobalPool(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDontUseGlobalPool) \
	{ \
		P_GET_UBOOL(Z_Param_bNewDontUseGlobalPool); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetDontUseGlobalPool(Z_Param_bNewDontUseGlobalPool); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorCullingUpdateRate) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetActorCullingUpdateRate(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetActorCullingUpdateRate) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewActorCullingUpdateRate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetActorCullingUpdateRate(Z_Param_NewActorCullingUpdateRate); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLODUpdateRate) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetLODUpdateRate(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLODUpdateRate) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewLODUpdateRate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetLODUpdateRate(Z_Param_NewLODUpdateRate); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCollisionPresets) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FBodyInstance*)Z_Param__Result=P_THIS->GetCollisionPresets(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCollisionPresets) \
	{ \
		P_GET_STRUCT(FBodyInstance,Z_Param_NewCollisionPresets); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetCollisionPresets(Z_Param_NewCollisionPresets); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaxCollisionsLOD) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetMaxCollisionsLOD(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaxCollisionsLOD) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewMaxCollisionsLOD); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMaxCollisionsLOD(Z_Param_NewMaxCollisionsLOD); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLightingChannels) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FLightingChannels*)Z_Param__Result=P_THIS->GetLightingChannels(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLightingChannels) \
	{ \
		P_GET_STRUCT(FLightingChannels,Z_Param_NewLightingChannels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetLightingChannels(Z_Param_NewLightingChannels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetDistanceBetweenActorHISMInVoxels) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetDistanceBetweenActorHISMInVoxels(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDistanceBetweenActorHISMInVoxels) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewDistanceBetweenActorHISMInVoxels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetDistanceBetweenActorHISMInVoxels(Z_Param_NewDistanceBetweenActorHISMInVoxels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEnableGrassWhenEditing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetEnableGrassWhenEditing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEnableGrassWhenEditing) \
	{ \
		P_GET_UBOOL(Z_Param_bNewEnableGrassWhenEditing); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEnableGrassWhenEditing(Z_Param_bNewEnableGrassWhenEditing); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaxActorChunkLOD) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetMaxActorChunkLOD(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaxActorChunkLOD) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewMaxActorChunkLOD); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMaxActorChunkLOD(Z_Param_NewMaxActorChunkLOD); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaxGrassChunkLOD) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetMaxGrassChunkLOD(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaxGrassChunkLOD) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewMaxGrassChunkLOD); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMaxGrassChunkLOD(Z_Param_NewMaxGrassChunkLOD); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorSpawner) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UVoxelActorSpawner**)Z_Param__Result=P_THIS->GetActorSpawner(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetActorSpawner) \
	{ \
		P_GET_OBJECT(UVoxelActorSpawner,Z_Param_Spawner); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetActorSpawner(Z_Param_Spawner); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGrassSpawner) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UVoxelGrassSpawner**)Z_Param__Result=P_THIS->GetGrassSpawner(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetGrassSpawner) \
	{ \
		P_GET_OBJECT(UVoxelGrassSpawner,Z_Param_Spawner); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetGrassSpawner(Z_Param_Spawner); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTessellationMaxLOD) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetTessellationMaxLOD(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetTessellationMaxLOD) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewTessellationMaxLOD); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetTessellationMaxLOD(Z_Param_NewTessellationMaxLOD); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBoundsExtension) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetBoundsExtension(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBoundsExtension) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewBoundsExtension); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBoundsExtension(Z_Param_NewBoundsExtension); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEnableTessellation) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetEnableTessellation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEnableTessellation) \
	{ \
		P_GET_UBOOL(Z_Param_NewEnableTessellation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEnableTessellation(Z_Param_NewEnableTessellation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetChunksFadeDuration) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetChunksFadeDuration(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetChunksFadeDuration) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewChunksFadeDuration); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetChunksFadeDuration(Z_Param_NewChunksFadeDuration); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaterialCollection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UVoxelMaterialCollection**)Z_Param__Result=P_THIS->GetMaterialCollection(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterialCollection) \
	{ \
		P_GET_OBJECT(UVoxelMaterialCollection,Z_Param_NewMaterialCollection); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMaterialCollection(Z_Param_NewMaterialCollection); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelMaterialWithTessellation) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UMaterialInterface**)Z_Param__Result=P_THIS->GetVoxelMaterialWithTessellation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVoxelMaterialWithTessellation) \
	{ \
		P_GET_OBJECT(UMaterialInterface,Z_Param_NewMaterial); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVoxelMaterialWithTessellation(Z_Param_NewMaterial); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelMaterial) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UMaterialInterface**)Z_Param__Result=P_THIS->GetVoxelMaterial(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVoxelMaterial) \
	{ \
		P_GET_OBJECT(UMaterialInterface,Z_Param_NewMaterial); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVoxelMaterial(Z_Param_NewMaterial); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaterialConfig) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EVoxelMaterialConfig*)Z_Param__Result=P_THIS->GetMaterialConfig(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterialConfig) \
	{ \
		P_GET_ENUM(EVoxelMaterialConfig,Z_Param_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMaterialConfig(EVoxelMaterialConfig(Z_Param_Config)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNormalConfig) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EVoxelNormalConfig*)Z_Param__Result=P_THIS->GetNormalConfig(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetNormalConfig) \
	{ \
		P_GET_ENUM(EVoxelNormalConfig,Z_Param_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetNormalConfig(EVoxelNormalConfig(Z_Param_Config)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUVConfig) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EVoxelUVConfig*)Z_Param__Result=P_THIS->GetUVConfig(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetUVConfig) \
	{ \
		P_GET_ENUM(EVoxelUVConfig,Z_Param_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetUVConfig(EVoxelUVConfig(Z_Param_Config)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetRenderType) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EVoxelRenderType*)Z_Param__Result=P_THIS->GetRenderType(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRenderType) \
	{ \
		P_GET_ENUM(EVoxelRenderType,Z_Param_Type); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetRenderType(EVoxelRenderType(Z_Param_Type)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEnableWorldRebasing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetEnableWorldRebasing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEnableWorldRebasing) \
	{ \
		P_GET_UBOOL(Z_Param_bNewEnableWorldRebasing); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEnableWorldRebasing(Z_Param_bNewEnableWorldRebasing); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSeeds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TMap<FString,int32>*)Z_Param__Result=P_THIS->GetSeeds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearSeeds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ClearSeeds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddSeed) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddSeed(Z_Param_Name,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddSeeds) \
	{ \
		P_GET_TMAP_REF(FString,int32,Z_Param_Out_NewSeeds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddSeeds(Z_Param_Out_NewSeeds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWaitForOtherChunksToAvoidHoles) \
	{ \
		P_GET_UBOOL(Z_Param_bNewWaitForOtherChunksToAvoidHoles); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetWaitForOtherChunksToAvoidHoles(Z_Param_bNewWaitForOtherChunksToAvoidHoles); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEnableUndoRedo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetEnableUndoRedo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEnableUndoRedo) \
	{ \
		P_GET_UBOOL(Z_Param_bNewEnableUndoRedo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEnableUndoRedo(Z_Param_bNewEnableUndoRedo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCreateWorldAutomatically) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetCreateWorldAutomatically(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCreateWorldAutomatically) \
	{ \
		P_GET_UBOOL(Z_Param_bNewCreateWorldAutomatically); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetCreateWorldAutomatically(Z_Param_bNewCreateWorldAutomatically); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSaveObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UVoxelWorldSaveObject**)Z_Param__Result=P_THIS->GetSaveObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSaveObject) \
	{ \
		P_GET_OBJECT(UVoxelWorldSaveObject,Z_Param_NewSaveObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetSaveObject(Z_Param_NewSaveObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWorldGeneratorClass) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_NewGeneratorClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetWorldGeneratorClass(Z_Param_NewGeneratorClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWorldGeneratorObject) \
	{ \
		P_GET_OBJECT(UVoxelWorldGenerator,Z_Param_NewGenerator); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetWorldGeneratorObject(Z_Param_NewGenerator); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelMassMultiplierInKg) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetVoxelMassMultiplierInKg(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVoxelMassMultiplierInKg) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewVoxelMassMultiplierInKg); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVoxelMassMultiplierInKg(Z_Param_NewVoxelMassMultiplierInKg); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelSize) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetVoxelSize(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVoxelSize) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewSize); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVoxelSize(Z_Param_NewSize); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetChunkCullingLOD) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetChunkCullingLOD(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetChunkCullingLOD) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewChunkCullingLOD); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetChunkCullingLOD(Z_Param_NewChunkCullingLOD); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLODLimit) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetLODLimit(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLODLimit) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewLODLimit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetLODLimit(Z_Param_NewLODLimit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWorldBounds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntBox*)Z_Param__Result=P_THIS->GetWorldBounds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWorldBounds) \
	{ \
		P_GET_STRUCT(FIntBox,Z_Param_NewWorldBounds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetWorldBounds(Z_Param_NewWorldBounds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetOverrideBounds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetOverrideBounds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetOverrideBounds) \
	{ \
		P_GET_UBOOL(Z_Param_bNewOverrideBounds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetOverrideBounds(Z_Param_bNewOverrideBounds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetOctreeDepth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetOctreeDepth(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetOctreeDepth) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewDepth); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetOctreeDepth(Z_Param_NewDepth); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVectorParameterValue) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ParameterName); \
		P_GET_STRUCT(FLinearColor,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVectorParameterValue(Z_Param_ParameterName,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetTextureParameterValue) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ParameterName); \
		P_GET_OBJECT(UTexture,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetTextureParameterValue(Z_Param_ParameterName,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetScalarParameterValue) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ParameterName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetScalarParameterValue(Z_Param_ParameterName,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDestroyWorld) \
	{ \
		P_GET_UBOOL(Z_Param_bClearMeshes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DestroyWorld(Z_Param_bClearMeshes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateWorld) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->CreateWorld(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveInstance) \
	{ \
		P_GET_OBJECT(UHierarchicalInstancedStaticMeshComponent,Z_Param_Component); \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Bounds); \
		P_GET_PROPERTY(UIntProperty,Z_Param_InstanceIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RemoveInstance(Z_Param_Component,Z_Param_Out_Bounds,Z_Param_InstanceIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddInstance) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_VoxelActorClass); \
		P_GET_STRUCT(FTransform,Z_Param_Transform); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddInstance(Z_Param_VoxelActorClass,Z_Param_Transform); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorClassFromHISM) \
	{ \
		P_GET_OBJECT(UHierarchicalInstancedStaticMeshComponent,Z_Param_Component); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UClass**)Z_Param__Result=P_THIS->GetActorClassFromHISM(Z_Param_Component); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableInstanceInArea) \
	{ \
		P_GET_OBJECT(UHierarchicalInstancedStaticMeshComponent,Z_Param_Component); \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Bounds); \
		P_GET_PROPERTY(UIntProperty,Z_Param_InstanceIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AVoxelActor**)Z_Param__Result=P_THIS->EnableInstanceInArea(Z_Param_Component,Z_Param_Out_Bounds,Z_Param_InstanceIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableActorsInArea) \
	{ \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Bounds); \
		P_GET_TARRAY_REF(AVoxelActor*,Z_Param_Out_OutActors); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EnableActorsInArea(Z_Param_Out_Bounds,Z_Param_Out_OutActors); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableFloatingActorsInArea) \
	{ \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Bounds); \
		P_GET_TARRAY_REF(AVoxelActor*,Z_Param_Out_OutActors); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EnableFloatingActorsInArea(Z_Param_Out_Bounds,Z_Param_Out_OutActors); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAddWorms) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Radius); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Seed); \
		P_GET_STRUCT(FVector,Z_Param_RotationAmplitude); \
		P_GET_STRUCT(FVector,Z_Param_NoiseDir); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NoiseSegmentLength); \
		P_GET_STRUCT(FVector,Z_Param_Start); \
		P_GET_STRUCT(FVector,Z_Param_InitialDir); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VoxelSegmentLength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_NumSegments); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_SplitProbability); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_SplitProbabilityGain); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BranchMeanSize); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BranchSizeVariation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddWorms(Z_Param_Radius,Z_Param_Seed,Z_Param_RotationAmplitude,Z_Param_NoiseDir,Z_Param_NoiseSegmentLength,Z_Param_Start,Z_Param_InitialDir,Z_Param_VoxelSegmentLength,Z_Param_NumSegments,Z_Param_SplitProbability,Z_Param_SplitProbabilityGain,Z_Param_BranchMeanSize,Z_Param_BranchSizeVariation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddOffset) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_OffsetInVoxels); \
		P_GET_UBOOL(Z_Param_bMoveActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddOffset(Z_Param_Out_OffsetInVoxels,Z_Param_bMoveActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCache) \
	{ \
		P_GET_TARRAY_REF(FIntBox,Z_Param_Out_BoundsToCache); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Cache(Z_Param_Out_BoundsToCache); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearCache) \
	{ \
		P_GET_TARRAY_REF(FIntBox,Z_Param_Out_BoundsToKeepCached); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ClearCache(Z_Param_Out_BoundsToKeepCached); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDebugVoxelsInsideBox) \
	{ \
		P_GET_STRUCT(FIntBox,Z_Param_Box); \
		P_GET_STRUCT(FLinearColor,Z_Param_Color); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Lifetime); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Thickness); \
		P_GET_UBOOL(Z_Param_bDebugDensities); \
		P_GET_STRUCT(FLinearColor,Z_Param_TextColor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DebugVoxelsInsideBox(Z_Param_Box,Z_Param_Color,Z_Param_Lifetime,Z_Param_Thickness,Z_Param_bDebugDensities,Z_Param_TextColor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDrawDebugIntBox) \
	{ \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Box); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Lifetime); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Thickness); \
		P_GET_STRUCT(FLinearColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DrawDebugIntBox(Z_Param_Out_Box,Z_Param_Lifetime,Z_Param_Thickness,Z_Param_Color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearFrames) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ClearFrames(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveFrame) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SaveFrame(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRedo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Redo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUndo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Undo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartServer) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Ip); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Port); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StartServer(Z_Param_Ip,Z_Param_Port); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConnectClient) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Ip); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Port); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ConnectClient(Z_Param_Ip,Z_Param_Port); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadFromCompressedSave) \
	{ \
		P_GET_STRUCT_REF(FVoxelCompressedWorldSave,Z_Param_Out_Save); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadFromCompressedSave(Z_Param_Out_Save); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadFromSave) \
	{ \
		P_GET_STRUCT_REF(FVoxelUncompressedWorldSave,Z_Param_Out_Save); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadFromSave(Z_Param_Out_Save); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCompressedSave) \
	{ \
		P_GET_STRUCT_REF(FVoxelCompressedWorldSave,Z_Param_Out_OutSave); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetCompressedSave(Z_Param_Out_OutSave); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSave) \
	{ \
		P_GET_STRUCT_REF(FVoxelUncompressedWorldSave,Z_Param_Out_OutSave); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetSave(Z_Param_Out_OutSave); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterial) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_GET_STRUCT_REF(FVoxelMaterial,Z_Param_Out_Material); \
		P_GET_UBOOL(Z_Param_bUpdateRender); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMaterial(Z_Param_Out_Position,Z_Param_Out_Material,Z_Param_bUpdateRender); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaterial) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVoxelMaterial*)Z_Param__Result=P_THIS->GetMaterial(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetValue) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_GET_UBOOL(Z_Param_bUpdateRender); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetValue(Z_Param_Out_Position,Z_Param_Value,Z_Param_bUpdateRender); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetValue) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetValue(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNormal) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetNormal(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntersection) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Start); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_End); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_GlobalPosition); \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_VoxelPosition); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIntersection(Z_Param_Out_Start,Z_Param_Out_End,Z_Param_Out_GlobalPosition,Z_Param_Out_VoxelPosition); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsInside) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsInside(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsInWorld) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsInWorld(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLODAt) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetLODAt(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateAll) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateAll(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateChunksOverlappingBox) \
	{ \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Box); \
		P_GET_UBOOL(Z_Param_bRemoveHoles); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateChunksOverlappingBox(Z_Param_Out_Box,Z_Param_bRemoveHoles); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateChunksAtPosition) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateChunksAtPosition(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNeighboringPositions) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_GlobalPosition); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FIntVector>*)Z_Param__Result=P_THIS->GetNeighboringPositions(Z_Param_Out_GlobalPosition); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLocalToGlobalFloat) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->LocalToGlobalFloat(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLocalToGlobal) \
	{ \
		P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->LocalToGlobal(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGlobalToLocalFloat) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GlobalToLocalFloat(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGlobalToLocal) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Position); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntVector*)Z_Param__Result=P_THIS->GlobalToLocal(Z_Param_Out_Position); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTaskCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetTaskCount(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBounds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntBox*)Z_Param__Result=P_THIS->GetBounds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsCreated) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsCreated(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMultiplayerSyncRate) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetMultiplayerSyncRate(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMultiplayerSyncRate) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewMultiplayerSyncRate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMultiplayerSyncRate(Z_Param_NewMultiplayerSyncRate); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMultiplayer) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetMultiplayer(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMultiplayer) \
	{ \
		P_GET_UBOOL(Z_Param_bNewMultiplayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMultiplayer(Z_Param_bNewMultiplayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetOptimizeIndices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetOptimizeIndices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetOptimizeIndices) \
	{ \
		P_GET_UBOOL(Z_Param_bNewOptimizeIndices); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetOptimizeIndices(Z_Param_bNewOptimizeIndices); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLODCurve) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UCurveFloat**)Z_Param__Result=P_THIS->GetLODCurve(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLODCurve) \
	{ \
		P_GET_OBJECT(UCurveFloat,Z_Param_NewCurve); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetLODCurve(Z_Param_NewCurve); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMeshThreadCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetMeshThreadCount(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMeshThreadCount) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewMeshThreadCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMeshThreadCount(Z_Param_NewMeshThreadCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetDontUseGlobalPool) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetDontUseGlobalPool(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDontUseGlobalPool) \
	{ \
		P_GET_UBOOL(Z_Param_bNewDontUseGlobalPool); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetDontUseGlobalPool(Z_Param_bNewDontUseGlobalPool); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorCullingUpdateRate) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetActorCullingUpdateRate(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetActorCullingUpdateRate) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewActorCullingUpdateRate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetActorCullingUpdateRate(Z_Param_NewActorCullingUpdateRate); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLODUpdateRate) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetLODUpdateRate(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLODUpdateRate) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewLODUpdateRate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetLODUpdateRate(Z_Param_NewLODUpdateRate); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCollisionPresets) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FBodyInstance*)Z_Param__Result=P_THIS->GetCollisionPresets(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCollisionPresets) \
	{ \
		P_GET_STRUCT(FBodyInstance,Z_Param_NewCollisionPresets); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetCollisionPresets(Z_Param_NewCollisionPresets); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaxCollisionsLOD) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetMaxCollisionsLOD(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaxCollisionsLOD) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewMaxCollisionsLOD); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMaxCollisionsLOD(Z_Param_NewMaxCollisionsLOD); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLightingChannels) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FLightingChannels*)Z_Param__Result=P_THIS->GetLightingChannels(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLightingChannels) \
	{ \
		P_GET_STRUCT(FLightingChannels,Z_Param_NewLightingChannels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetLightingChannels(Z_Param_NewLightingChannels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetDistanceBetweenActorHISMInVoxels) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetDistanceBetweenActorHISMInVoxels(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDistanceBetweenActorHISMInVoxels) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewDistanceBetweenActorHISMInVoxels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetDistanceBetweenActorHISMInVoxels(Z_Param_NewDistanceBetweenActorHISMInVoxels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEnableGrassWhenEditing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetEnableGrassWhenEditing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEnableGrassWhenEditing) \
	{ \
		P_GET_UBOOL(Z_Param_bNewEnableGrassWhenEditing); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEnableGrassWhenEditing(Z_Param_bNewEnableGrassWhenEditing); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaxActorChunkLOD) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetMaxActorChunkLOD(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaxActorChunkLOD) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewMaxActorChunkLOD); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMaxActorChunkLOD(Z_Param_NewMaxActorChunkLOD); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaxGrassChunkLOD) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetMaxGrassChunkLOD(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaxGrassChunkLOD) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewMaxGrassChunkLOD); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMaxGrassChunkLOD(Z_Param_NewMaxGrassChunkLOD); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorSpawner) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UVoxelActorSpawner**)Z_Param__Result=P_THIS->GetActorSpawner(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetActorSpawner) \
	{ \
		P_GET_OBJECT(UVoxelActorSpawner,Z_Param_Spawner); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetActorSpawner(Z_Param_Spawner); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGrassSpawner) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UVoxelGrassSpawner**)Z_Param__Result=P_THIS->GetGrassSpawner(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetGrassSpawner) \
	{ \
		P_GET_OBJECT(UVoxelGrassSpawner,Z_Param_Spawner); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetGrassSpawner(Z_Param_Spawner); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTessellationMaxLOD) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetTessellationMaxLOD(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetTessellationMaxLOD) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewTessellationMaxLOD); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetTessellationMaxLOD(Z_Param_NewTessellationMaxLOD); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBoundsExtension) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetBoundsExtension(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBoundsExtension) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewBoundsExtension); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBoundsExtension(Z_Param_NewBoundsExtension); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEnableTessellation) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetEnableTessellation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEnableTessellation) \
	{ \
		P_GET_UBOOL(Z_Param_NewEnableTessellation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEnableTessellation(Z_Param_NewEnableTessellation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetChunksFadeDuration) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetChunksFadeDuration(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetChunksFadeDuration) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewChunksFadeDuration); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetChunksFadeDuration(Z_Param_NewChunksFadeDuration); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaterialCollection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UVoxelMaterialCollection**)Z_Param__Result=P_THIS->GetMaterialCollection(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterialCollection) \
	{ \
		P_GET_OBJECT(UVoxelMaterialCollection,Z_Param_NewMaterialCollection); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMaterialCollection(Z_Param_NewMaterialCollection); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelMaterialWithTessellation) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UMaterialInterface**)Z_Param__Result=P_THIS->GetVoxelMaterialWithTessellation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVoxelMaterialWithTessellation) \
	{ \
		P_GET_OBJECT(UMaterialInterface,Z_Param_NewMaterial); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVoxelMaterialWithTessellation(Z_Param_NewMaterial); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelMaterial) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UMaterialInterface**)Z_Param__Result=P_THIS->GetVoxelMaterial(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVoxelMaterial) \
	{ \
		P_GET_OBJECT(UMaterialInterface,Z_Param_NewMaterial); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVoxelMaterial(Z_Param_NewMaterial); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaterialConfig) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EVoxelMaterialConfig*)Z_Param__Result=P_THIS->GetMaterialConfig(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMaterialConfig) \
	{ \
		P_GET_ENUM(EVoxelMaterialConfig,Z_Param_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMaterialConfig(EVoxelMaterialConfig(Z_Param_Config)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNormalConfig) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EVoxelNormalConfig*)Z_Param__Result=P_THIS->GetNormalConfig(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetNormalConfig) \
	{ \
		P_GET_ENUM(EVoxelNormalConfig,Z_Param_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetNormalConfig(EVoxelNormalConfig(Z_Param_Config)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUVConfig) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EVoxelUVConfig*)Z_Param__Result=P_THIS->GetUVConfig(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetUVConfig) \
	{ \
		P_GET_ENUM(EVoxelUVConfig,Z_Param_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetUVConfig(EVoxelUVConfig(Z_Param_Config)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetRenderType) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EVoxelRenderType*)Z_Param__Result=P_THIS->GetRenderType(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRenderType) \
	{ \
		P_GET_ENUM(EVoxelRenderType,Z_Param_Type); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetRenderType(EVoxelRenderType(Z_Param_Type)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEnableWorldRebasing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetEnableWorldRebasing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEnableWorldRebasing) \
	{ \
		P_GET_UBOOL(Z_Param_bNewEnableWorldRebasing); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEnableWorldRebasing(Z_Param_bNewEnableWorldRebasing); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSeeds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TMap<FString,int32>*)Z_Param__Result=P_THIS->GetSeeds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearSeeds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ClearSeeds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddSeed) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddSeed(Z_Param_Name,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddSeeds) \
	{ \
		P_GET_TMAP_REF(FString,int32,Z_Param_Out_NewSeeds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddSeeds(Z_Param_Out_NewSeeds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWaitForOtherChunksToAvoidHoles) \
	{ \
		P_GET_UBOOL(Z_Param_bNewWaitForOtherChunksToAvoidHoles); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetWaitForOtherChunksToAvoidHoles(Z_Param_bNewWaitForOtherChunksToAvoidHoles); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEnableUndoRedo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetEnableUndoRedo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEnableUndoRedo) \
	{ \
		P_GET_UBOOL(Z_Param_bNewEnableUndoRedo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEnableUndoRedo(Z_Param_bNewEnableUndoRedo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCreateWorldAutomatically) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetCreateWorldAutomatically(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCreateWorldAutomatically) \
	{ \
		P_GET_UBOOL(Z_Param_bNewCreateWorldAutomatically); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetCreateWorldAutomatically(Z_Param_bNewCreateWorldAutomatically); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSaveObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UVoxelWorldSaveObject**)Z_Param__Result=P_THIS->GetSaveObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSaveObject) \
	{ \
		P_GET_OBJECT(UVoxelWorldSaveObject,Z_Param_NewSaveObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetSaveObject(Z_Param_NewSaveObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWorldGeneratorClass) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_NewGeneratorClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetWorldGeneratorClass(Z_Param_NewGeneratorClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWorldGeneratorObject) \
	{ \
		P_GET_OBJECT(UVoxelWorldGenerator,Z_Param_NewGenerator); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetWorldGeneratorObject(Z_Param_NewGenerator); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelMassMultiplierInKg) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetVoxelMassMultiplierInKg(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVoxelMassMultiplierInKg) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewVoxelMassMultiplierInKg); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVoxelMassMultiplierInKg(Z_Param_NewVoxelMassMultiplierInKg); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelSize) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetVoxelSize(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVoxelSize) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewSize); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVoxelSize(Z_Param_NewSize); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetChunkCullingLOD) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetChunkCullingLOD(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetChunkCullingLOD) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewChunkCullingLOD); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetChunkCullingLOD(Z_Param_NewChunkCullingLOD); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLODLimit) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetLODLimit(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLODLimit) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewLODLimit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetLODLimit(Z_Param_NewLODLimit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWorldBounds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FIntBox*)Z_Param__Result=P_THIS->GetWorldBounds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWorldBounds) \
	{ \
		P_GET_STRUCT(FIntBox,Z_Param_NewWorldBounds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetWorldBounds(Z_Param_NewWorldBounds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetOverrideBounds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetOverrideBounds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetOverrideBounds) \
	{ \
		P_GET_UBOOL(Z_Param_bNewOverrideBounds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetOverrideBounds(Z_Param_bNewOverrideBounds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetOctreeDepth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetOctreeDepth(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetOctreeDepth) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewDepth); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetOctreeDepth(Z_Param_NewDepth); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVectorParameterValue) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ParameterName); \
		P_GET_STRUCT(FLinearColor,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVectorParameterValue(Z_Param_ParameterName,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetTextureParameterValue) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ParameterName); \
		P_GET_OBJECT(UTexture,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetTextureParameterValue(Z_Param_ParameterName,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetScalarParameterValue) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ParameterName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetScalarParameterValue(Z_Param_ParameterName,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDestroyWorld) \
	{ \
		P_GET_UBOOL(Z_Param_bClearMeshes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DestroyWorld(Z_Param_bClearMeshes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateWorld) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->CreateWorld(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveInstance) \
	{ \
		P_GET_OBJECT(UHierarchicalInstancedStaticMeshComponent,Z_Param_Component); \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Bounds); \
		P_GET_PROPERTY(UIntProperty,Z_Param_InstanceIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RemoveInstance(Z_Param_Component,Z_Param_Out_Bounds,Z_Param_InstanceIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddInstance) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_VoxelActorClass); \
		P_GET_STRUCT(FTransform,Z_Param_Transform); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddInstance(Z_Param_VoxelActorClass,Z_Param_Transform); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorClassFromHISM) \
	{ \
		P_GET_OBJECT(UHierarchicalInstancedStaticMeshComponent,Z_Param_Component); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UClass**)Z_Param__Result=P_THIS->GetActorClassFromHISM(Z_Param_Component); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableInstanceInArea) \
	{ \
		P_GET_OBJECT(UHierarchicalInstancedStaticMeshComponent,Z_Param_Component); \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Bounds); \
		P_GET_PROPERTY(UIntProperty,Z_Param_InstanceIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AVoxelActor**)Z_Param__Result=P_THIS->EnableInstanceInArea(Z_Param_Component,Z_Param_Out_Bounds,Z_Param_InstanceIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableActorsInArea) \
	{ \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Bounds); \
		P_GET_TARRAY_REF(AVoxelActor*,Z_Param_Out_OutActors); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EnableActorsInArea(Z_Param_Out_Bounds,Z_Param_Out_OutActors); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableFloatingActorsInArea) \
	{ \
		P_GET_STRUCT_REF(FIntBox,Z_Param_Out_Bounds); \
		P_GET_TARRAY_REF(AVoxelActor*,Z_Param_Out_OutActors); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EnableFloatingActorsInArea(Z_Param_Out_Bounds,Z_Param_Out_OutActors); \
		P_NATIVE_END; \
	}


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(AVoxelWorld, NO_API)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVoxelWorld(); \
	friend struct Z_Construct_UClass_AVoxelWorld_Statics; \
public: \
	DECLARE_CLASS(AVoxelWorld, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelWorld) \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_ARCHIVESERIALIZER


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_INCLASS \
private: \
	static void StaticRegisterNativesAVoxelWorld(); \
	friend struct Z_Construct_UClass_AVoxelWorld_Statics; \
public: \
	DECLARE_CLASS(AVoxelWorld, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelWorld) \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_ARCHIVESERIALIZER


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelWorld(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelWorld) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelWorld); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelWorld); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelWorld(AVoxelWorld&&); \
	NO_API AVoxelWorld(const AVoxelWorld&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelWorld(AVoxelWorld&&); \
	NO_API AVoxelWorld(const AVoxelWorld&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelWorld); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelWorld); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVoxelWorld)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__OctreeDepth() { return STRUCT_OFFSET(AVoxelWorld, OctreeDepth); } \
	FORCEINLINE static uint32 __PPO__LOD_DEPRECATED() { return STRUCT_OFFSET(AVoxelWorld, LOD_DEPRECATED); } \
	FORCEINLINE static uint32 __PPO__WorldSizeInVoxel() { return STRUCT_OFFSET(AVoxelWorld, WorldSizeInVoxel); } \
	FORCEINLINE static uint32 __PPO__bOverrideBounds() { return STRUCT_OFFSET(AVoxelWorld, bOverrideBounds); } \
	FORCEINLINE static uint32 __PPO__WorldBounds() { return STRUCT_OFFSET(AVoxelWorld, WorldBounds); } \
	FORCEINLINE static uint32 __PPO__LODLimit() { return STRUCT_OFFSET(AVoxelWorld, LODLimit); } \
	FORCEINLINE static uint32 __PPO__ChunkCullingLOD() { return STRUCT_OFFSET(AVoxelWorld, ChunkCullingLOD); } \
	FORCEINLINE static uint32 __PPO__VoxelSize() { return STRUCT_OFFSET(AVoxelWorld, VoxelSize); } \
	FORCEINLINE static uint32 __PPO__VoxelMassMultiplierInKg() { return STRUCT_OFFSET(AVoxelWorld, VoxelMassMultiplierInKg); } \
	FORCEINLINE static uint32 __PPO__WorldGenerator() { return STRUCT_OFFSET(AVoxelWorld, WorldGenerator); } \
	FORCEINLINE static uint32 __PPO__SaveObject() { return STRUCT_OFFSET(AVoxelWorld, SaveObject); } \
	FORCEINLINE static uint32 __PPO__bCreateWorldAutomatically() { return STRUCT_OFFSET(AVoxelWorld, bCreateWorldAutomatically); } \
	FORCEINLINE static uint32 __PPO__bEnableUndoRedo() { return STRUCT_OFFSET(AVoxelWorld, bEnableUndoRedo); } \
	FORCEINLINE static uint32 __PPO__bWaitForOtherChunksToAvoidHoles() { return STRUCT_OFFSET(AVoxelWorld, bWaitForOtherChunksToAvoidHoles); } \
	FORCEINLINE static uint32 __PPO__Seeds() { return STRUCT_OFFSET(AVoxelWorld, Seeds); } \
	FORCEINLINE static uint32 __PPO__bEnableWorldRebasing() { return STRUCT_OFFSET(AVoxelWorld, bEnableWorldRebasing); } \
	FORCEINLINE static uint32 __PPO__RenderType() { return STRUCT_OFFSET(AVoxelWorld, RenderType); } \
	FORCEINLINE static uint32 __PPO__UVConfig() { return STRUCT_OFFSET(AVoxelWorld, UVConfig); } \
	FORCEINLINE static uint32 __PPO__NormalConfig() { return STRUCT_OFFSET(AVoxelWorld, NormalConfig); } \
	FORCEINLINE static uint32 __PPO__MaterialConfig() { return STRUCT_OFFSET(AVoxelWorld, MaterialConfig); } \
	FORCEINLINE static uint32 __PPO__VoxelMaterial() { return STRUCT_OFFSET(AVoxelWorld, VoxelMaterial); } \
	FORCEINLINE static uint32 __PPO__VoxelMaterialWithTessellation() { return STRUCT_OFFSET(AVoxelWorld, VoxelMaterialWithTessellation); } \
	FORCEINLINE static uint32 __PPO__MaterialCollection() { return STRUCT_OFFSET(AVoxelWorld, MaterialCollection); } \
	FORCEINLINE static uint32 __PPO__bEnableTessellation() { return STRUCT_OFFSET(AVoxelWorld, bEnableTessellation); } \
	FORCEINLINE static uint32 __PPO__BoundsExtension() { return STRUCT_OFFSET(AVoxelWorld, BoundsExtension); } \
	FORCEINLINE static uint32 __PPO__TessellationMaxLOD() { return STRUCT_OFFSET(AVoxelWorld, TessellationMaxLOD); } \
	FORCEINLINE static uint32 __PPO__ChunksFadeDuration() { return STRUCT_OFFSET(AVoxelWorld, ChunksFadeDuration); } \
	FORCEINLINE static uint32 __PPO__GrassSpawner() { return STRUCT_OFFSET(AVoxelWorld, GrassSpawner); } \
	FORCEINLINE static uint32 __PPO__ActorSpawner() { return STRUCT_OFFSET(AVoxelWorld, ActorSpawner); } \
	FORCEINLINE static uint32 __PPO__MaxGrassChunkLOD() { return STRUCT_OFFSET(AVoxelWorld, MaxGrassChunkLOD); } \
	FORCEINLINE static uint32 __PPO__MaxActorChunkLOD() { return STRUCT_OFFSET(AVoxelWorld, MaxActorChunkLOD); } \
	FORCEINLINE static uint32 __PPO__bEnableGrassWhenEditing() { return STRUCT_OFFSET(AVoxelWorld, bEnableGrassWhenEditing); } \
	FORCEINLINE static uint32 __PPO__DistanceBetweenActorHISMInVoxels() { return STRUCT_OFFSET(AVoxelWorld, DistanceBetweenActorHISMInVoxels); } \
	FORCEINLINE static uint32 __PPO__LightingChannels() { return STRUCT_OFFSET(AVoxelWorld, LightingChannels); } \
	FORCEINLINE static uint32 __PPO__MaxCollisionsLOD() { return STRUCT_OFFSET(AVoxelWorld, MaxCollisionsLOD); } \
	FORCEINLINE static uint32 __PPO__CollisionPresets() { return STRUCT_OFFSET(AVoxelWorld, CollisionPresets); } \
	FORCEINLINE static uint32 __PPO__LODUpdateRate() { return STRUCT_OFFSET(AVoxelWorld, LODUpdateRate); } \
	FORCEINLINE static uint32 __PPO__ActorCullingUpdateRate() { return STRUCT_OFFSET(AVoxelWorld, ActorCullingUpdateRate); } \
	FORCEINLINE static uint32 __PPO__bDontUseGlobalPool() { return STRUCT_OFFSET(AVoxelWorld, bDontUseGlobalPool); } \
	FORCEINLINE static uint32 __PPO__MeshThreadCount() { return STRUCT_OFFSET(AVoxelWorld, MeshThreadCount); } \
	FORCEINLINE static uint32 __PPO__LODCurve() { return STRUCT_OFFSET(AVoxelWorld, LODCurve); } \
	FORCEINLINE static uint32 __PPO__bOptimizeIndices() { return STRUCT_OFFSET(AVoxelWorld, bOptimizeIndices); } \
	FORCEINLINE static uint32 __PPO__bMultiplayer() { return STRUCT_OFFSET(AVoxelWorld, bMultiplayer); } \
	FORCEINLINE static uint32 __PPO__MultiplayerSyncRate() { return STRUCT_OFFSET(AVoxelWorld, MultiplayerSyncRate); } \
	FORCEINLINE static uint32 __PPO__MissingMaterial() { return STRUCT_OFFSET(AVoxelWorld, MissingMaterial); } \
	FORCEINLINE static uint32 __PPO__VoxelWorldEditor() { return STRUCT_OFFSET(AVoxelWorld, VoxelWorldEditor); } \
	FORCEINLINE static uint32 __PPO__MaterialInstance() { return STRUCT_OFFSET(AVoxelWorld, MaterialInstance); }


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_48_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_51_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_RPC_WRAPPERS
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_RPC_WRAPPERS_NO_PURE_DECLS
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVoxelWorldEditorInterface(); \
	friend struct Z_Construct_UClass_AVoxelWorldEditorInterface_Statics; \
public: \
	DECLARE_CLASS(AVoxelWorldEditorInterface, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelWorldEditorInterface)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_INCLASS \
private: \
	static void StaticRegisterNativesAVoxelWorldEditorInterface(); \
	friend struct Z_Construct_UClass_AVoxelWorldEditorInterface_Statics; \
public: \
	DECLARE_CLASS(AVoxelWorldEditorInterface, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Voxel"), NO_API) \
	DECLARE_SERIALIZER(AVoxelWorldEditorInterface)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelWorldEditorInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelWorldEditorInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelWorldEditorInterface); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelWorldEditorInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelWorldEditorInterface(AVoxelWorldEditorInterface&&); \
	NO_API AVoxelWorldEditorInterface(const AVoxelWorldEditorInterface&); \
public:


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelWorldEditorInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelWorldEditorInterface(AVoxelWorldEditorInterface&&); \
	NO_API AVoxelWorldEditorInterface(const AVoxelWorldEditorInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelWorldEditorInterface); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelWorldEditorInterface); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelWorldEditorInterface)


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_PRIVATE_PROPERTY_OFFSET
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_881_PROLOG
#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_RPC_WRAPPERS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_INCLASS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_PRIVATE_PROPERTY_OFFSET \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_RPC_WRAPPERS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_INCLASS_NO_PURE_DECLS \
	PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h_884_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PrototypeSurvivalCpp_Plugins_Voxel_Source_Voxel_Public_VoxelWorld_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
