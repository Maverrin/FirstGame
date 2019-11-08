// Copyright 2018 Phyronnaz

#include "VoxelChunkOctree.h"
#include "Curves/RichCurve.h"

FVoxelChunkOctree::FVoxelChunkOctree(FVoxelChunkOctreeSettings* Settings, uint8 LOD)
	: TVoxelOctree(LOD)
	, Settings(*Settings)
	, Root(this)
{
	check(LOD > 0);

	CreateChildren();

	bContinueInit = true;
	while (bContinueInit)
	{
		bContinueInit = false;
		Init();
	}
}

FVoxelChunkOctree::FVoxelChunkOctree(FVoxelChunkOctree* Parent, uint8 ChildIndex)
	: TVoxelOctree(Parent, ChildIndex)
	, Settings(Parent->Settings)
	, Root(Parent->Root)
{
	if (LOD > 0 && GetBounds().Intersect(Settings.WorldBounds))
	{
		if (LOD > Settings.LODLimit)
		{
			CreateChildren();
		}
		else
		{
			const auto& LocalCameraBounds = Settings.CameraBounds;
			for (const FIntBox& Bound : LocalCameraBounds)
			{
				if (GetBounds().Intersect(Bound))
				{
					CreateChildren();
					break;
				}
			}
			if (IsLeaf() && LocalCameraBounds.Num() > 0 && Settings.LODCurve)
			{
				int Distance = GetBounds().ComputeSquaredDistanceFromBoxToBox(LocalCameraBounds[0]);
				for (int Index = 1; Index < LocalCameraBounds.Num(); Index++)
				{
					Distance = FMath::Min(Distance, GetBounds().ComputeSquaredDistanceFromBoxToBox(LocalCameraBounds[Index]));
				}
				float DistanceSqrt = FMath::Sqrt(Distance);
				int WantedLOD = FMath::CeilToInt(Settings.LODCurve->Eval(DistanceSqrt));
				if (LOD > WantedLOD)
				{
					CreateChildren();
				}
			}
		}
	}
}

void FVoxelChunkOctree::GetLeavesBounds(TSet<FIntBox>& InBounds) const
{
	if (IsLeaf())
	{
		if (GetBounds().Intersect(Settings.WorldBounds))
		{
			InBounds.Add(GetBounds());
		}
	}
	else
	{
		for (auto& Child : GetChildren())
		{
			Child->GetLeavesBounds(InBounds);
		}
	}
}

void FVoxelChunkOctree::GetLeavesTransitionsMasks(TMap<FIntBox, uint8>& TransitionsMasks) const
{
	if (IsLeaf())
	{
		if (GetBounds().Intersect(Settings.WorldBounds))
		{
			uint8 TransitionsMask = 0;
			for (auto& Direction : { XMin, XMax, YMin, YMax, ZMin, ZMax })
			{
				FVoxelChunkOctree* AdjacentChunk = GetAdjacentChunk(Direction);
				if (AdjacentChunk && AdjacentChunk->LOD < LOD)
				{
					TransitionsMask |= Direction;
				}
			}
			TransitionsMasks.Add(GetBounds(), TransitionsMask);
		}
	}
	else
	{
		for (auto& Child : GetChildren())
		{
			Child->GetLeavesTransitionsMasks(TransitionsMasks);
		}
	}
}

FVoxelChunkOctree* FVoxelChunkOctree::GetAdjacentChunk(EVoxelDirection Direction) const
{
	FIntVector P;
	switch (Direction)
	{
	case XMin:
		P = Position - FIntVector(Size(), 0, 0);
		break;
	case XMax:
		P = Position + FIntVector(Size(), 0, 0);
		break;
	case YMin:
		P = Position - FIntVector(0, Size(), 0);
		break;
	case YMax:
		P = Position + FIntVector(0, Size(), 0);
		break;
	case ZMin:
		P = Position - FIntVector(0, 0, Size());
		break;
	case ZMax:
		P = Position + FIntVector(0, 0, Size());
		break;
	default:
		check(false);
		P = FIntVector::ZeroValue;
	}

	if (Root->IsInOctree(P))
	{
		return Root->GetLeaf(P);
	}
	else
	{
		return nullptr;
	}
}

void FVoxelChunkOctree::Init()
{
	if (IsLeaf())
	{
		for (auto& Direction : { XMin, XMax, YMin, YMax, ZMin, ZMax })
		{
			FVoxelChunkOctree* AdjacentChunk = GetAdjacentChunk(Direction);
			while (AdjacentChunk && AdjacentChunk->LOD > LOD + 1 && AdjacentChunk->GetBounds().Intersect(Settings.WorldBounds))
			{
				AdjacentChunk->CreateChildren();
				AdjacentChunk = GetAdjacentChunk(Direction);
				Root->bContinueInit = true;
			}
		}
	}
	else
	{
		for (auto& Child : GetChildren())
		{
			Child->Init();
		}
	}
}
