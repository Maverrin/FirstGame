// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelOctree.h"
#include "IntBox.h"
#include "VoxelGlobals.h"
#include "VoxelDirection.h"

struct FRichCurve;

struct FVoxelChunkOctreeSettings
{
	uint8 LODLimit;
	const FRichCurve* LODCurve;
	FIntBox WorldBounds;
	TArray<FIntBox> CameraBounds;
};

/**
 * Create the octree for rendering and spawning VoxelChunks
 */
class FVoxelChunkOctree : public TVoxelOctree<FVoxelChunkOctree, CHUNK_SIZE>
{
public:
	const FVoxelChunkOctreeSettings& Settings;
	FVoxelChunkOctree* const Root;

	FVoxelChunkOctree(FVoxelChunkOctreeSettings* Settings, uint8 LOD);
	FVoxelChunkOctree(FVoxelChunkOctree* Parent, uint8 ChildIndex);

	void GetLeavesBounds(TSet<FIntBox>& Bounds) const;
	void GetLeavesTransitionsMasks(TMap<FIntBox, uint8>& TransitionsMasks) const;

	FVoxelChunkOctree* GetAdjacentChunk(EVoxelDirection Direction) const;

private:
	bool bContinueInit;

	void Init();
};