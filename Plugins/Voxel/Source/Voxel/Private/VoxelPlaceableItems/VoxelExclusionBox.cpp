// Copyright 2018 Phyronnaz

#include "VoxelPlaceableItems/VoxelExclusionBox.h"
#include "Components/BoxComponent.h"
#include "VoxelWorld.h"
#include "VoxelLogStatDefinitions.h"
#include "VoxelPlaceableItems/VoxelDefaultItems.h"
#include "VoxelData/VoxelData.h"
#include "VoxelUtilities.h"

FIntBox AVoxelExclusionBox::GetBox() const
{
	if (!World)
	{
		UE_LOG(LogVoxel, Error, TEXT("AVoxelExclusionBox::GetBox: Invalid world"));
		return FIntBox();
	}

	const float VoxelSize = World->GetVoxelSize();

	FIntVector Position = World->GlobalToLocal(GetActorLocation() + FVector::OneVector * VoxelSize / 2.f);

	FVector Scale = GetActorScale3D();
	
	const float Ratio = VoxelSize / 100.f;
	FIntVector S = FVoxelIntVector::RoundToInt(Scale / Ratio);

	return FIntBox(Position - S, Position + S);
}

inline void AddExclusionBoxToWorldImpl(AVoxelWorld* World, const FIntBox& Bounds, bool bExcludeTerrain, bool bExcludeVoxelActors, bool bExcludeVoxelGrass, bool bDisableEdits)
{
	auto* Data = World->GetData();
	FVoxelScopeSetLock Lock(Data, FIntBox::Infinite);
	Data->AddItem<FVoxelExclusionBoxItem>(Bounds, bExcludeTerrain, bExcludeVoxelActors, bExcludeVoxelGrass);
	if (bDisableEdits)
	{
		Data->AddItem<FVoxelDisableEditsBoxItem>(Bounds);
	}

	TArray<FVoxelDataOctree*> AlreadyCreatedChunks;
	Data->GetOctree()->GetCreatedChunksOverlappingBox(Bounds, AlreadyCreatedChunks);
	for (auto& Octree : AlreadyCreatedChunks)
	{
		if (bExcludeTerrain)
		{
			Octree->SetValueOrMaterialLambda<FVoxelValue>(Bounds, [&](int X, int Y, int Z, FVoxelValue& Value) { Value = FVoxelValue::Empty; });
		}
		if (bExcludeVoxelGrass || bExcludeVoxelActors)
		{
			Octree->SetValueOrMaterialLambda<FVoxelMaterial>(Bounds, [&](int X, int Y, int Z, FVoxelMaterial& Material)
			{
				if (bExcludeVoxelGrass)
				{
					Material.SetVoxelGrassId(255);
				}
				if (bExcludeVoxelActors)
				{
					Material.SetVoxelActorId(255);
				}
			});
		}
	}
}

void AVoxelExclusionBox::AddItemToWorld(AVoxelWorld* InWorld) const
{
	Super::AddItemToWorld(InWorld);
	if (InWorld == World)
	{		
		AddExclusionBoxToWorldImpl(World, GetBox(), bExcludeTerrain, bExcludeVoxelActors, bExcludeVoxelGrass, bDisableEdits);
	}
}

void AVoxelExclusionBox::AddExclusionBoxToWorld(AVoxelWorld* World, const FIntBox& Bounds, bool bExcludeTerrain, bool bExcludeVoxelActors, bool bExcludeVoxelGrass, bool bDisableEdits)
{
	AddExclusionBoxToWorldImpl(World, Bounds, bExcludeTerrain, bExcludeVoxelActors, bExcludeVoxelGrass, bDisableEdits);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#if WITH_EDITOR
AVoxelExclusionBox::AVoxelExclusionBox()
	: CurrentVoxelSize(0)
{
	SetActorEnableCollision(false);

	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	Box->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Box->SetBoxExtent(FVector::OneVector * 100);
	SetRootComponent(Box);

	PrimaryActorTick.bCanEverTick = true;
}

///////////////////////////////////////////////////////////////////////////////

void AVoxelExclusionBox::BeginPlay()
{
    Super::BeginPlay();
	PrimaryActorTick.SetTickFunctionEnable(false);
}

void AVoxelExclusionBox::Tick(float DeltaTime)
{
	if (World)
	{
		if (CurrentVoxelSize != World->GetVoxelSize() || CurrentWorldLocation != World->GetActorLocation())
		{
			ClampTransform();
		}
	}
}

void AVoxelExclusionBox::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (World)
	{
		ClampTransform();
	}
}

void AVoxelExclusionBox::PostEditMove(bool bFinished)
{
	Super::PostEditMove(bFinished);

	if (bFinished && World)
	{
		ClampTransform();
	}
}

///////////////////////////////////////////////////////////////////////////////

void AVoxelExclusionBox::ClampTransform()
{
	CurrentVoxelSize = World->GetVoxelSize();
	CurrentWorldLocation = World->GetActorLocation();

	{
		FVector Position = GetActorLocation();

		const FVector HalfSize = FVector(CurrentVoxelSize) / 2;

		Position -= HalfSize;
		Position -= CurrentWorldLocation;
		Position /= CurrentVoxelSize;

		Position.X = FMath::RoundToInt(Position.X);
		Position.Y = FMath::RoundToInt(Position.Y);
		Position.Z = FMath::RoundToInt(Position.Z);

		Position *= CurrentVoxelSize;
		Position += CurrentWorldLocation;
		Position += HalfSize;

		SetActorLocation(Position);
	}
	{
		FVector Scale = GetActorScale3D();

		const float Ratio = CurrentVoxelSize / 100.f;
		Scale.X = FMath::RoundToInt(FMath::Max(Scale.X, 0.f) / Ratio) * Ratio;
		Scale.Y = FMath::RoundToInt(FMath::Max(Scale.Y, 0.f) / Ratio) * Ratio;
		Scale.Z = FMath::RoundToInt(FMath::Max(Scale.Z, 0.f) / Ratio) * Ratio;

		SetActorScale3D(Scale);
	}
	SetActorRotation(FRotator::ZeroRotator);
}
#endif
