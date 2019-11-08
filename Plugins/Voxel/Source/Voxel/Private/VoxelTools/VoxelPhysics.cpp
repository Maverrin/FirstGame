// Copyright 2018 Phyronnaz


#include "VoxelTools/VoxelPhysics.h"
#include "VoxelWorld.h"
#include "VoxelTools/VoxelPart.h"
#include "VoxelTools/VoxelTools.h"
#include "VoxelLogStatDefinitions.h"
#include "VoxelData/VoxelData.h"
#include "VoxelWorldGenerators/EmptyWorldGenerator.h"
#include "Engine/Engine.h"

DECLARE_CYCLE_STAT(TEXT("UVoxelTools::RemoveFloatingBlocks"), STAT_UVoxelTools_RemoveFloatingBlocks, STATGROUP_Voxel);

///////////////////////////////////////////////////////////////////////////////

inline uint32 GetIndex(const FIntBox& Box, const FIntVector& Size, int X, int Y, int Z)
{
	return (X - Box.Min.X) + (Y - Box.Min.Y) * Size.X + (Z - Box.Min.Z) * Size.X * Size.Y;
}
inline uint32 GetIndex(const FIntBox& Box, const FIntVector& Size, const FIntVector& P)
{
	return GetIndex(Box, Size, P.X, P.Y, P.Z);
}

inline bool SearchForFloatingBlocks(
	FVoxelData* Data, 
	const FIntBox& Bounds,
	FVoxelPhysicsResult& Result)
{
	TArray<FVoxelValue>& ValuesArray = Result.Values;
	TArray<FVoxelMaterial>& Materials = Result.Materials;
	TArray<bool>& VisitedArray = Result.Visited;
	TArray<FIntVector>& FloatingPoints = Result.FloatingPoints;
	FIntBox& BoxToUpdate = Result.BoxToUpdate;

	const FIntVector Size = Bounds.Size();

	ValuesArray.SetNumUninitialized(Size.X * Size.Y * Size.Z);
	VisitedArray.SetNumZeroed(Size.X * Size.Y * Size.Z);

	TArray<FVoxelId> Octrees;
	Data->BeginGet(Bounds, Octrees);
	bool bIsSet = false;

	Data->GetValuesAndMaterials(ValuesArray.GetData(), nullptr, Bounds, Bounds.Min, 0, Size);
	
#if 0
	auto& Values = ValuesArray;
	auto& Visited = VisitedArray;
#else
	auto* Values = ValuesArray.GetData();
	auto* Visited = VisitedArray.GetData();
#endif

	TArray<FIntVector> Queue;

	// Fill Visited array
	{
		// Add borders
		for (int X = Bounds.Min.X; X < Bounds.Max.X; X++)
		{
			for (int Y = Bounds.Min.Y; Y < Bounds.Max.Y; Y++)
			{
				Queue.Emplace(X, Y, Bounds.Min.Z);
				Queue.Emplace(X, Y, Bounds.Max.Z - 1);
			}
			for (int Z = Bounds.Min.Z; Z < Bounds.Max.Z; Z++)
			{
				Queue.Emplace(X, Bounds.Min.Y, Z);
				Queue.Emplace(X, Bounds.Max.Y - 1, Z);
			}
		}
		for (int Y = Bounds.Min.Y; Y < Bounds.Max.Y; Y++)
		{
			for (int Z = Bounds.Min.Z; Z < Bounds.Max.Z; Z++)
			{
				Queue.Emplace(Bounds.Min.X, Y, Z);
				Queue.Emplace(Bounds.Max.X - 1, Y, Z);
			}
		}

		while (Queue.Num() > 0)
		{
			const FIntVector Position = Queue.Pop(false);

			if (Bounds.IsInside(Position))
			{
				int Index = GetIndex(Bounds, Size, Position);
				if (!Visited[Index] && !Values[Index].IsEmpty())
				{
					Visited[Index] = true;
					FVoxelUtilities::AddNeighborsToArray(Position, Queue);
				}
			}
		}
	}

	FVoxelDataOctree* Octree = nullptr;
	for (int Z = Bounds.Min.Z; Z < Bounds.Max.Z; Z++)
	{
		for (int Y = Bounds.Min.Y; Y < Bounds.Max.Y; Y++)
		{
			for (int X = Bounds.Min.X; X < Bounds.Max.X; X++)
			{
				const int Index = GetIndex(Bounds, Size, X, Y, Z);

				auto& Value = Values[Index];
				if (!Visited[Index] && !Value.IsEmpty())
				{
					// BeginSet is expensive, so we avoid calling it until we really have to
					if (!bIsSet)
					{
						Data->EndGet(Octrees);
						Data->BeginSet(Bounds, Octrees);
						Materials.SetNumUninitialized(Size.X * Size.Y * Size.Z);
						bIsSet = true;
					}

					Materials[Index] = Data->GetMaterial(X, Y, Z, Octree);
					Data->SetValue(X, Y, Z, FVoxelValue::Empty, Octree);

					FloatingPoints.Emplace(X, Y, Z);
					if (BoxToUpdate.IsValid())
					{
						BoxToUpdate += FIntVector(X, Y, Z);
					}
					else
					{
						BoxToUpdate = FIntVector(X, Y, Z);
					}
				}
			}
		}
	}

	if (bIsSet)
	{
		Data->EndSet(Octrees);
		return true;
	}
	else
	{
		Data->EndGet(Octrees);
		return false;
	}
}

inline void SpawnFloatingBlocks(
	TArray<AVoxelPart*>& SpawnedActors, 
	AVoxelWorld* World, 
	const FIntBox& Bounds,
	TSubclassOf<AVoxelPart> 
	ClassToSpawn,
	FVoxelPhysicsResult& Result)
{
	TArray<FVoxelValue>& Values = Result.Values;
	TArray<FVoxelMaterial>& Materials = Result.Materials;
	TArray<bool>& Visited = Result.Visited;
	TArray<FIntVector>& FloatingPoints = Result.FloatingPoints;
	FIntBox& BoxToUpdate = Result.BoxToUpdate;

	const FIntVector Size = Bounds.Size();

	if (FloatingPoints.Num() == 0)
	{
		return;
	}

	uint8 LOD = FVoxelUtilities::GetDepthFromSize<VOXEL_CELL_SIZE>(Size.GetMax());
	auto WorldGenerator = MakeShared<FEmptyWorldGeneratorInstance, ESPMode::ThreadSafe>(World->GetData()->WorldGenerator);
	
	TArray<FIntVector> Queue;
	while (FloatingPoints.Num() > 0)
	{
		// Find all connected points to this point to create different VoxelParts for each section

		FIntVector PointPosition = FloatingPoints.Pop(false);

		TSharedPtr<FVoxelData, ESPMode::ThreadSafe> CurrentData = MakeShared<FVoxelData, ESPMode::ThreadSafe>(LOD, WorldGenerator, false, false);
		FVoxelDataOctree* Octree = nullptr;

		float Mass = 0;

		if (!Visited[GetIndex(Bounds, Size, PointPosition)])
		{
			Queue.Reset();
			Queue.Add(PointPosition);
			while (Queue.Num() > 0)
			{
				FIntVector Position = Queue.Pop(false);

				if (Bounds.IsInside(Position))
				{
					int Index = GetIndex(Bounds, Size, Position);

					auto& Value = Values[Index];
					if (!Visited[Index] && !Value.IsEmpty())
					{
						Visited[Index] = true;
						Mass += -Value.ToFloat();
						
						FIntVector LocalPosition = Position - PointPosition;
						CurrentData->SetValue(LocalPosition, Value, Octree);
						CurrentData->SetMaterial(LocalPosition, Materials[Index], Octree);

						FVoxelUtilities::AddNeighborsToArray(Position, Queue);
					}
				}
			}

			// Create the VoxelPart
			AVoxelPart* Part = World->GetWorld()->SpawnActor<AVoxelPart>(ClassToSpawn);
			Part->World = World;
			Part->SetActorLocation(World->LocalToGlobal(PointPosition));
			Part->Init(CurrentData, Bounds.TranslateBy(-PointPosition), Mass * World->GetVoxelMassMultiplierInKg(), PointPosition);
			SpawnedActors.Add(Part);
		}
	}
	
	TArray<TWeakObjectPtr<AVoxelPart>> SpawnedActorsPtrs;
	for (auto& Actor : SpawnedActors)
	{
		SpawnedActorsPtrs.Add(Actor);
	}
	World->UpdateChunksOverlappingBox(BoxToUpdate, [=]()
	{
		for (auto& Actor : SpawnedActorsPtrs)
		{
			if (Actor.IsValid())
			{
				Actor->WorldUpdateDone();
			}
		}
	});
}

///////////////////////////////////////////////////////////////////////////////

void FVoxelPhysicsAsyncWork::DoWork()
{
	SearchForFloatingBlocks(Data.Get(), Bounds, Result);
}

///////////////////////////////////////////////////////////////////////////////

void UVoxelPhysicsTools::RemoveFloatingBlocks(
		UObject* WorldContextObject,
		struct FLatentActionInfo LatentInfo,
		TArray<AVoxelPart*>& SpawnedActors,
		AVoxelWorld* World,
		const FIntBox& Bounds,
		TSubclassOf<AVoxelPart> ClassToSpawn)
{
	SCOPE_CYCLE_COUNTER(STAT_UVoxelTools_RemoveFloatingBlocks);
	
	CHECK_WORLD_VOXELTOOLS(RemoveFloatingBlocks);
	
	if (!ClassToSpawn || ClassToSpawn->HasAnyClassFlags(CLASS_Abstract))
	{
		FMessageLog("PIE").Error(FText::FromString("RemoveFloatingBlocks: Invalid ClassToSpawn"));
		return;
	}

	auto* SpawnedActorsPtr = &SpawnedActors;
	
	if (UWorld* ObjectWorld = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = ObjectWorld->GetLatentActionManager();
		if (!LatentActionManager.FindExistingAction<FVoxelLatentAction<FVoxelPhysicsAsyncWork>>(LatentInfo.CallbackTarget, LatentInfo.UUID))
		{
			if (UVoxelPhysicsTools::SearchIsRunning.FindOrAdd(World->GetWorld()))
			{
				GEngine->AddOnScreenDebugMessage(-1, 0.1, FColor::White, "RemoveFloatingBlocks: task already running");
				return;
			}

			UVoxelPhysicsTools::SearchIsRunning[World->GetWorld()] = true;
			TSharedPtr<FVoxelPhysicsAsyncWork> Work = MakeShared<FVoxelPhysicsAsyncWork>(World, Bounds);
			World->GetPool()->AsyncTasksPool->AddQueuedWork(Work.Get());

			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FVoxelLatentAction<FVoxelPhysicsAsyncWork>(Work, LatentInfo, "VoxelPhysics: Waiting",
				[=](FVoxelPhysicsAsyncWork& Work)
				{
					SpawnFloatingBlocks(*SpawnedActorsPtr, World, Bounds, ClassToSpawn, Work.Result);
					UVoxelPhysicsTools::SearchIsRunning[World->GetWorld()] = false;
				}
			));
		}
	}
}

TMap<UWorld*, bool> UVoxelPhysicsTools::SearchIsRunning;

