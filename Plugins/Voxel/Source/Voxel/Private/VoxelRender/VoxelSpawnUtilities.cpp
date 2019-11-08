// Copyright 2018 Phyronnaz

#include "VoxelSpawnUtilities.h"
#include "VoxelWorldGenerator.h"
#include "VoxelGrassUtilities.h"
#include "VoxelUtilities.h"
#include "VoxelSpawners/VoxelActor.h"
#include "VoxelRender/VoxelIntermediateChunk.h"
#include "Runtime/Launch/Resources/Version.h"

inline float GetTriangleArea(const FVector& A, const FVector& B, const FVector& C, int VoxelSize)
{
	return ((A - B) ^ (C - B)).Size() / 2 * VoxelSize * VoxelSize / 100000; // 10m^2 in cm^2;
}

inline int32 GetSeed(uint64 Id, uint64 Index, const FIntVector& V, int64 Seed)
{
	int64 X = V.X;
	int64 Y = V.Y;
	int64 Z = V.Z;
	return X ^ Y ^ Z + Index + (Id << 10) * Seed;
}

inline FMatrix GetMatrixFromStream(const FRandomStream& Stream, const FVoxelDefaultSpawner& Settings, const FVector& WorldUp, const FVector& Position, const FVector& Normal)
{
	FVector Scale;
	switch (Settings.Scaling)
	{
	case EVoxelSpawnerScaling::Uniform:
		Scale.X = Settings.ScaleX.Interpolate(Stream.GetFraction());
		Scale.Y = Scale.X;
		Scale.Z = Scale.X;
		break;
	case EVoxelSpawnerScaling::Free:
		Scale.X = Settings.ScaleX.Interpolate(Stream.GetFraction());
		Scale.Y = Settings.ScaleY.Interpolate(Stream.GetFraction());
		Scale.Z = Settings.ScaleZ.Interpolate(Stream.GetFraction());
		break;
	case EVoxelSpawnerScaling::LockXY:
		Scale.X = Settings.ScaleX.Interpolate(Stream.GetFraction());
		Scale.Y = Scale.X;
		Scale.Z = Settings.ScaleZ.Interpolate(Stream.GetFraction());
		break;
	default:
		check(false);
	}

	const float Rot = Settings.RandomRotation ? Stream.GetFraction() * 360.0f : 0.0f;
	FMatrix BaseXForm = FScaleRotationTranslationMatrix(Scale, FRotator(0.0f, Rot, 0.0f), FVector::ZeroVector);
	
	switch (Settings.RotationAlignment)
	{
	case EVoxelSpawnerRotation::AlignToSurface:
		BaseXForm *= FRotationMatrix::MakeFromZ(Normal);
		break;
	case EVoxelSpawnerRotation::AlignToWorldUp:
		BaseXForm *= FRotationMatrix::MakeFromZ(WorldUp);
		break;
	case EVoxelSpawnerRotation::DontAlign:
		BaseXForm *= FRotationMatrix::MakeFromZ(Stream.GetUnitVector());
		break;
	default:
		check(false);
	}

	return BaseXForm.ConcatTranslation(Position);
}

inline FIntVector GetIntVectorForSeed(const FVector& Input, const FIntVector& ChunkPosition)
{
	double A = Input.X;
	double B = Input.Y;
	double C = Input.Z;
	A *= 1e5;
	B *= 1e5;
	C *= 1e5;
	return ChunkPosition * int32(1e5) + FIntVector(FMath::RoundToInt(A), FMath::RoundToInt(B), FMath::RoundToInt(C));
}

void FVoxelSpawnUtilities::SpawnGrass(
	int VoxelSize, 
	bool bEnableGrassWhenEditing,
	const FVoxelGrassSpawner_ThreadSafe& Spawner,
	const FVoxelWorldGeneratorInstance& Generator,
	const FVoxelChunk& Chunk,
	const FIntVector& ChunkPosition,
	const FVoxelPreviousGrassInfo& OldPreviousGrassInfo,
	FVoxelGrassBufferMap& GrassBuffers, 
	FVoxelPreviousGrassInfo& NewPreviousGrassInfo)
{
	if (Spawner.GrassTypes.Num() == 0)
	{
		return;
	}

	const bool bFirstTime = OldPreviousGrassInfo.Num() == 0 || bEnableGrassWhenEditing;

	TMap<FVoxelGrassInfoIndex, TArray<FMatrix>> Transforms;

	Chunk.IterateOnTriangles([&](const FVoxelProcMeshVertex& A, const FVoxelProcMeshVertex& B, const FVoxelProcMeshVertex& C)
	{
		const float TriangleArea = GetTriangleArea(A.Position, B.Position, C.Position, VoxelSize);
		check(TriangleArea >= 0);

		TArray<uint8> GrassIds;
		GrassIds.AddUnique(A.GrassId);
		GrassIds.AddUnique(B.GrassId);
		GrassIds.AddUnique(C.GrassId);

		const FVector& Start = A.Position;
		const FVector AxisX = B.Position - A.Position;
		const FVector AxisY = C.Position - A.Position;

		const FVector Normal = FVector::CrossProduct(AxisY, AxisX).GetSafeNormal();
		const FVector WorldUp = Generator.GetUpVector(FVoxelIntVector::RoundToInt(A.Position + FVector(ChunkPosition))).GetSafeNormal();
		const float Angle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(Normal, WorldUp)));

		const FIntVector RNGCenter = GetIntVectorForSeed(A.Position + B.Position + C.Position, ChunkPosition);

		for (auto& GrassId : GrassIds)
		{
			auto* GrassVarietiesPtr = Spawner.GrassTypes.Find(GrassId);
			if (!GrassVarietiesPtr)
			{
				continue;
			}

			int GrassVarietyIndex = -1;
			for (auto& GrassVariety : *GrassVarietiesPtr)
			{
				if (GrassVariety.MinAngleWithWorldUp <= Angle && Angle <= GrassVariety.MaxAngleWithWorldUp)
				{
					GrassVarietyIndex++;
					
					const FVoxelGrassInfoIndex GrassIndex(GrassId, GrassVarietyIndex);
					TArray<FMatrix>& InstanceTransforms = Transforms.FindOrAdd(GrassIndex);

					const TSet<FIntVector>* OldPositions = OldPreviousGrassInfo.Find(GrassIndex);
					TSet<FIntVector>& NewPositions = NewPreviousGrassInfo.FindOrAdd(GrassIndex);

					FRandomStream Stream(GetSeed(GrassId, GrassVarietyIndex, RNGCenter, GrassVariety.Seed));

					const float GrassToAdd = GrassVariety.Density * TriangleArea;
					const int GrassCount = Stream.GetFraction() < FMath::Frac(GrassToAdd) ? FMath::CeilToInt(GrassToAdd) : FMath::FloorToInt(GrassToAdd);
					for (int Index = 0; Index < GrassCount; Index++)
					{
						float X = Stream.GetFraction();
						float Y = Stream.GetFraction();
						if (X + Y > 1)
						{
							X = 1 - X;
							Y = 1 - Y;
						}
						FVector Position = Start + X * AxisX + Y * AxisY;
						FIntVector RoundedPosition = FVoxelIntVector::RoundToInt(Position * 100 * VoxelSize);

						if (bFirstTime || (OldPositions && (*OldPositions).Contains(RoundedPosition)))
						{
							NewPositions.Add(RoundedPosition);
							InstanceTransforms.Add(GetMatrixFromStream(Stream, GrassVariety, WorldUp, Position * VoxelSize, Normal));
						}
					}
				}
			}
		}
	});

	for (auto& TransformsIt : Transforms)
	{
		auto& GrassId = TransformsIt.Key.GrassId;
		auto& GrassVarietyIndex = TransformsIt.Key.GrassVariety;
		auto& InstanceTransforms = TransformsIt.Value;

		if (InstanceTransforms.Num() > 0)
		{
			auto Buffer = MakeShared<FVoxelGrassBuffer>();
			GrassBuffers.Add(TransformsIt.Key, Buffer);
			auto& GrassVariety = Spawner.GrassTypes[GrassId][GrassVarietyIndex];
			Buffer->GrassVariety = GrassVariety;
			auto& InstanceBuffer = Buffer->InstanceBuffer;

#if ENGINE_MINOR_VERSION < 20
			InstanceBuffer.AllocateInstances(InstanceTransforms.Num(), true);
#else
			InstanceBuffer.AllocateInstances(InstanceTransforms.Num(), EResizeBufferFlags::None, true);
#endif
			int32 InstanceIndex = 0;
			for (auto& InstanceTransform : InstanceTransforms)
			{
				Buffer->InstanceBuffer.SetInstance(InstanceIndex++, InstanceTransform, 0);
			}

			TArray<int32> SortedInstances;
			TArray<int32> InstanceReorderTable;
			UHierarchicalInstancedStaticMeshComponent::BuildTreeAnyThread(InstanceTransforms, GrassVariety.GrassMesh->GetBounds().GetBox(), Buffer->ClusterTree, SortedInstances, InstanceReorderTable, Buffer->OutOcclusionLayerNum, 1);

			// in-place sort the instances

			for (int32 FirstUnfixedIndex = 0; FirstUnfixedIndex < InstanceTransforms.Num(); FirstUnfixedIndex++)
			{
				int32 LoadFrom = SortedInstances[FirstUnfixedIndex];
				if (LoadFrom != FirstUnfixedIndex)
				{
					check(LoadFrom > FirstUnfixedIndex);
					InstanceBuffer.SwapInstance(FirstUnfixedIndex, LoadFrom);

					int32 SwapGoesTo = InstanceReorderTable[FirstUnfixedIndex];
					check(SwapGoesTo > FirstUnfixedIndex);
					check(SortedInstances[SwapGoesTo] == FirstUnfixedIndex);
					SortedInstances[SwapGoesTo] = LoadFrom;
					InstanceReorderTable[LoadFrom] = SwapGoesTo;

					InstanceReorderTable[FirstUnfixedIndex] = FirstUnfixedIndex;
					SortedInstances[FirstUnfixedIndex] = FirstUnfixedIndex;
				}
			}
		}
	}
}

void FVoxelSpawnUtilities::SpawnActors(
	int VoxelSize, 
	const FVoxelActorSpawner_ThreadSafe& Spawner,
	const FVoxelWorldGeneratorInstance& Generator,
	const FVoxelChunk& Chunk, 
	const FIntVector& ChunkPosition,
	TArray<FVoxelActorSpawnInfo>& ActorsSpawnInfo)
{
	if (Spawner.ActorGroups.Num() == 0)
	{
		return;
	}

	TMap<FVoxelGrassInfoIndex, TArray<FMatrix>> Transforms;

	Chunk.IterateOnTriangles([&](const FVoxelProcMeshVertex& A, const FVoxelProcMeshVertex& B, const FVoxelProcMeshVertex& C)
	{
		const float TriangleArea = GetTriangleArea(A.Position, B.Position, C.Position, VoxelSize);
		check(TriangleArea >= 0);

		TArray<uint8> ActorIds;
		ActorIds.AddUnique(A.ActorId);
		ActorIds.AddUnique(B.ActorId);
		ActorIds.AddUnique(C.ActorId);

		const FVector& Start = A.Position;
		const FVector AxisX = B.Position - A.Position;
		const FVector AxisY = C.Position - A.Position;

		const FVector Normal = FVector::CrossProduct(AxisY, AxisX).GetSafeNormal();
		const FVector WorldUp = Generator.GetUpVector(FVoxelIntVector::RoundToInt(A.Position + FVector(ChunkPosition))).GetSafeNormal();
		const float Angle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(Normal, WorldUp)));
		
		const FIntVector RNGCenter = GetIntVectorForSeed(A.Position + B.Position + C.Position, ChunkPosition);

		for (auto& ActorId : ActorIds)
		{
			auto* ActorConfigsPtr = Spawner.ActorGroups.Find(ActorId);
			if (!ActorConfigsPtr)
			{
				continue;
			}

			for (int ActorConfigIndex = 0; ActorConfigIndex < ActorConfigsPtr->Num(); ActorConfigIndex++)
			{
				auto& ActorConfig = (*ActorConfigsPtr)[ActorConfigIndex];
				
				if (ActorConfig.MinAngleWithWorldUp <= Angle && Angle <= ActorConfig.MaxAngleWithWorldUp)
				{
					FRandomStream Stream(GetSeed(ActorId, ActorConfigIndex, RNGCenter, ActorConfig.Seed));

					const float ActorsToAdd = ActorConfig.Density * TriangleArea;
					const int ActorsCount = Stream.GetFraction() < FMath::Frac(ActorsToAdd) ? FMath::CeilToInt(ActorsToAdd) : FMath::FloorToInt(ActorsToAdd);
					for (int Index = 0; Index < ActorsCount; Index++)
					{
						float X = Stream.GetFraction();
						float Y = Stream.GetFraction();
						if (X + Y > 1)
						{
							X = 1 - X;
							Y = 1 - Y;
						}
						FVector Position = FVector(ChunkPosition) + Start + X * AxisX + Y * AxisY;
						FMatrix Matrix = GetMatrixFromStream(Stream, ActorConfig, WorldUp, Position, Normal);
						ActorsSpawnInfo.Add(FVoxelActorSpawnInfo(&ActorConfig, FTransform(Matrix)));
					}
				}
			}
		}
	});
}
