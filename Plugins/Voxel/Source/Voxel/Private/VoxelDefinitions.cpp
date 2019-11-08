// Copyright 2018 Phyronnaz

#include "IntBox.h"
#include "VoxelPlaceableItems/VoxelPlaceableItem.h"
#include "VoxelValue.h"
#include "VoxelRender/VoxelIntermediateChunk.h"

// +/- 1000: prevents integers overflow
FIntBox const FIntBox::Infinite = FIntBox(FIntVector(MIN_int32 + 1000, MIN_int32 + 1000, MIN_int32 + 1000), FIntVector(MAX_int32 - 1000, MAX_int32 - 1000, MAX_int32 - 1000));

FVoxelValue const FVoxelValue::Full = FVoxelValue(-1);
FVoxelValue const FVoxelValue::Empty = FVoxelValue(1);
