// Copyright 2018 Phyronnaz

#include "VoxelTools/VoxelPart.h"
#include "VoxelComponents/VoxelAutoDisableComponent.h"
#include "VoxelData/VoxelData.h"
#include "VoxelGlobals.h"
#include "VoxelWorld.h"
#include "VoxelRender/VoxelPolygonizerAsyncWork.h"
#include "VoxelRender/AsyncWorks/VoxelMCPolygonizerAsyncWork.h"
#include "VoxelRender/AsyncWorks/VoxelCubicPolygonizerAsyncWork.h"
#include "VoxelRender/VoxelRenderUtilities.h"
#include "VoxelRender/VoxelGrassUtilities.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "Engine/StaticMeshActor.h"
#include "Components/BoxComponent.h"

AVoxelPartSimpleMesh::AVoxelPartSimpleMesh()
	: Materials(MakeShared<FVoxelChunkMaterials>(&MaterialsRef))
{
	SetActorEnableCollision(true);
	RootComponent = CreateDefaultSubobject<UVoxelProceduralMeshComponent>("Root");
	RootComponent->Mobility = EComponentMobility::Movable;
	PrimaryActorTick.bCanEverTick = true;
}

void AVoxelPartSimpleMesh::Init(TSharedPtr<FVoxelData, ESPMode::ThreadSafe> InData, const FIntBox& Bounds, float InMass, const FIntVector& Position)
{
	Data = InData;
	Mass = InMass;
	FVoxelRenderFactory::CreatePolygonizerThreads(Threads, World->GetPool()->MeshPool, World, Data.ToSharedRef(), Bounds, 0, true);
	ThreadsRemaining = Threads.Num();
}

void AVoxelPartSimpleMesh::Tick(float DeltaSeconds)
{
	if (!World || World->IsPendingKill())
	{
		SetActorTickEnabled(false);
		FMessageLog("PIE").Warning(FText::FromString("VoxelPartSimpleMesh: World was destroyed too soon, canceling tasks"));
		return;
	}

	for (auto& Thread : Threads)
	{
		if (Thread->IsDone() && !DoneThreads.Contains(Thread.Get()))
		{
			DoneThreads.Add(Thread.Get());
			ThreadsRemaining--;
		}
	}

	if (ThreadsRemaining == 0 && bWorldUpdateDone)
	{
		SetActorTickEnabled(false);

		auto* RootMesh = CastChecked<UVoxelProceduralMeshComponent>(RootComponent);
		RootMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
		RootMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		RootMesh->bUseComplexAsSimpleCollision = false;
		RootMesh->SetMassOverrideInKg(NAME_None, Mass);

		const int VoxelSize = World->GetVoxelSize();		
		TArray<FVector> Vertices;
		for (auto& Thread : Threads)
		{
			if (!Thread->Chunk->IsEmpty())
			{
				FVector Position(Thread->ChunkPosition);

				auto* Mesh = GetMesh(Position);
				FVoxelRenderUtilities::CreateMeshSectionFromChunks(0, false, World, Mesh, Materials, Thread->Chunk);
				
				Thread->Chunk->IterateOnBuffers([&](auto& Buffer)
				{
					for (auto& VPosition : Buffer.Positions)
					{
						Vertices.Add((VPosition + Position) * VoxelSize);
					}
				});

				for (auto& BufferIt : Thread->GrassBuffers)
				{
					auto& Buffer = BufferIt.Value;
					auto Grass = GetGrass(Position);
					FVoxelGrassUtilities::InitGrass(Grass, Buffer->GrassVariety);
					FVoxelGrassUtilities::SetNewPositions(Grass, Buffer);
				}

				if (Vertices.Num() > 16) // Don't add too small chunks
				{
					RootMesh->AddCollisionConvexMesh(Vertices);
					Vertices.Reset();
				}
			}
		}
		if (Vertices.Num() > 0)
		{
			RootMesh->AddCollisionConvexMesh(Vertices);
		}
		Data.Reset();

		OnLoaded.Broadcast();

		FTimerHandle Dummy;
		GetWorld()->GetTimerManager().SetTimer(Dummy, [=]() { RootMesh->SetSimulatePhysics(true); }, 0.1f, false);		
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, DeltaSeconds / 2, FColor::White, FString::Printf(TEXT("Part Tasks remaining: %d %s"), ThreadsRemaining, ThreadsRemaining == 0 ? TEXT("(waiting for world update to be done)") : TEXT("")));
	}
}

UHierarchicalInstancedStaticMeshComponent* AVoxelPartSimpleMesh::GetGrass(const FVector& Position)
{
	auto* Grass = NewObject<UHierarchicalInstancedStaticMeshComponent>(this, NAME_None, RF_Transient);
	Grass->SetupAttachment(GetRootComponent(), NAME_None);
	Grass->SetMobility(EComponentMobility::Movable);
	Grass->RegisterComponent();
	Grass->SetRelativeLocation(Position * World->GetVoxelSize());
	return Grass;
}

UVoxelProceduralMeshComponent* AVoxelPartSimpleMesh::GetMesh(const FVector& Position)
{
	auto* Mesh = NewObject<UVoxelProceduralMeshComponent>(this, NAME_None, RF_Transient);
	Mesh->bUseAsyncCooking = true;
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetupAttachment(GetRootComponent(), NAME_None);
	Mesh->SetMobility(EComponentMobility::Movable);
	Mesh->RegisterComponent();
	Mesh->bCastShadowAsTwoSided = true;
	Mesh->SetRelativeLocation(Position * World->GetVoxelSize());
	Mesh->SetWorldScale3D(FVector(World->GetVoxelSize()));
	return Mesh;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void AVoxelPartCube::Init(TSharedPtr<FVoxelData, ESPMode::ThreadSafe> Data, const FIntBox& Bounds, float Mass, const FIntVector& Position)
{	
	struct FTemp
	{
		FVector Position;
		FLinearColor Color;
	};
	TArray<FTemp> PositionsAndColors;
	Data->GetOctree()->CallLambdaOnValuesInBounds<true>(Bounds, [&](int X, int Y, int Z, const FVoxelValue& Value, const FVoxelMaterial& VoxelMaterial)
	{
		if (!Value.IsEmpty())
		{
			PositionsAndColors.Emplace(FTemp{ World->LocalToGlobal(FIntVector(X, Y, Z) + Position), VoxelMaterial.GetLinearColor() });
		}
	});

	UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, *FString("/Engine/BasicShapes/Cube.Cube"));
	TArray<AStaticMeshActor*> Actors;
	for (auto& PositionAndColor : PositionsAndColors)
	{
		auto* StaticMeshActor = GetWorld()->SpawnActor<AStaticMeshActor>(PositionAndColor.Position, FRotator::ZeroRotator);
		StaticMeshActor->SetActorScale3D(FVector(World->GetVoxelSize() / 100));
		StaticMeshActor->SetMobility(EComponentMobility::Movable);
		UStaticMeshComponent* StaticMeshComponent = StaticMeshActor->GetStaticMeshComponent();
		StaticMeshComponent->SetStaticMesh(CubeMesh);
		StaticMeshComponent->SetSimulatePhysics(true);
		StaticMeshComponent->SetMassOverrideInKg(NAME_None, World->GetVoxelMassMultiplierInKg());
		{
			auto* Instance = UMaterialInstanceDynamic::Create(Material, StaticMeshActor);
			Instance->SetVectorParameterValue(TEXT("VertexColor"), PositionAndColor.Color);
			StaticMeshComponent->SetMaterial(0, Instance);
		}
		Actors.Add(StaticMeshActor);
	}

	OnCubesCreated(Actors);

	Destroy();
}

