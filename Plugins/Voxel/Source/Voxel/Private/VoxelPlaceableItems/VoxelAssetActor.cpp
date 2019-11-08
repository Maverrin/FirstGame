// Copyright 2018 Phyronnaz

#include "VoxelPlaceableItems/VoxelAssetActor.h"
#include "VoxelWorld.h"
#include "VoxelData/VoxelData.h"
#include "VoxelRender/AsyncWorks/VoxelMCPolygonizerAsyncWork.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"
#include "VoxelPlaceableItems/VoxelDefaultItems.h"
#include "VoxelRender/VoxelRenderUtilities.h"
#include "VoxelRender/VoxelRenderFactory.h"
#include "VoxelAssets/VoxelDataAsset.h"

void AVoxelAssetActor::AddItemToWorld(AVoxelWorld* InWorld) const
{
	Super::AddItemToWorld(InWorld);
	if (Asset && InWorld == World)
	{
		TSharedRef<FVoxelDataAssetInstance, ESPMode::ThreadSafe> AssetInstance = Asset->GetAsset(World->GlobalToLocal(GetActorLocation()));
		AssetInstance->Init(World->GetInitStruct());

		auto* Data = World->GetData();
		FVoxelScopeSetLock Lock(Data, FIntBox::Infinite);
		Data->AddItem<FVoxelAssetItem>(AssetInstance, Priority, bInvert);
		
		auto Bounds = AssetInstance->GetWorldBounds();
		TArray<FVoxelDataOctree*> AlreadyCreatedChunks;
		Data->GetOctree()->GetCreatedChunksOverlappingBox(Bounds, AlreadyCreatedChunks);
		TVoxelBuffer<FVoxelValue> ValuesBuffer;
		TVoxelBuffer<FVoxelMaterial> MaterialsBuffer;
		for (auto& Octree : AlreadyCreatedChunks)
		{
			auto LocalBounds = Bounds.Overlap(Octree->GetBounds());
			AssetInstance->GetValuesAndMaterials(ValuesBuffer.data(), MaterialsBuffer.data(), LocalBounds, LocalBounds.Min, 0, FIntVector(VOXEL_CELL_SIZE), 0, FVoxelPlaceableItemHolder());
#define INDEX(X, Y, Z) ((X - LocalBounds.Min.X) + (Y - LocalBounds.Min.Y) * VOXEL_CELL_SIZE + (Z - LocalBounds.Min.Z) * VOXEL_CELL_SIZE * VOXEL_CELL_SIZE)
			Octree->SetValueOrMaterialLambda<FVoxelValue>(Bounds, [&](int X, int Y, int Z, FVoxelValue& Value)
			{
				auto& AssetValue = ValuesBuffer[INDEX(X, Y, Z)];
				if (!AssetValue.IsEmpty())
				{
					Value = bInvert ? AssetValue.GetInverse() : AssetValue;
				}
			});
			Octree->SetValueOrMaterialLambda<FVoxelMaterial>(Bounds, [&](int X, int Y, int Z, FVoxelMaterial& Material)
			{
				if (!ValuesBuffer[INDEX(X, Y, Z)].IsEmpty())
				{
					Material = MaterialsBuffer[INDEX(X, Y, Z)];
				}
			});
#undef INDEX
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#if WITH_EDITOR
FVoxelQueuedThreadPool* AVoxelAssetActor::ThreadPool = nullptr;

AVoxelAssetActor::AVoxelAssetActor()
	: Materials(MakeShared<FVoxelChunkMaterials>(&MaterialsRef))
{
	SetActorEnableCollision(false);

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	Box->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Box->SetBoxExtent(FVector::ZeroVector);

	PrimaryActorTick.bCanEverTick = true;

	if (!ThreadPool)
	{
		ThreadPool = new FVoxelQueuedThreadPool();
		ThreadPool->Create(8, 1024 * 1024);
	}
}

///////////////////////////////////////////////////////////////////////////////

void AVoxelAssetActor::Update()
{
	check(World && Asset);

	if (CurrentVoxelMaterial != World->GetVoxelMaterial() || CurrentMaterialCollection != World->GetMaterialCollection())
	{
		Materials->Reset();
	}

	CurrentVoxelSize		  = World->GetVoxelSize();
	CurrentRenderType		  = World->GetRenderType();
	CurrentUVConfig			  = World->GetUVConfig();
	CurrentNormalConfig		  = World->GetNormalConfig();
	CurrentMaterialConfig     = World->GetMaterialConfig();
	CurrentVoxelMaterial      = World->GetVoxelMaterial();
	CurrentMaterialCollection = World->GetMaterialCollection();

	TSharedRef<FVoxelDataAssetInstance, ESPMode::ThreadSafe> AssetInstance = Asset->GetAsset(FIntVector::ZeroValue);
	AssetInstance->Init(World->GetInitStruct());

	FIntVector AssetSize = Asset->GetSize();
	uint8 LOD = FVoxelUtilities::GetDepthFromSize<VOXEL_CELL_SIZE>(AssetSize.GetMax() * 2 + 1);
	
	TSharedRef<FVoxelData, ESPMode::ThreadSafe> Data = MakeShared<FVoxelData, ESPMode::ThreadSafe>(LOD, AssetInstance, false, false);

	const int ChunkLOD = FMath::Clamp(LOD - MaxOctreeDepth, 0, MAX_WORLD_DEPTH - 1);
	
	TArray<TSharedPtr<FVoxelPolygonizerAsyncWork>> Threads;
	FVoxelRenderFactory::CreatePolygonizerThreads(Threads, ThreadPool, World, Data, FIntBox(FIntVector::ZeroValue - FIntVector(1, 1, 1), AssetSize + FIntVector(1, 1, 1)), ChunkLOD);
	
	int MeshIndex = 0;
	for (auto& Thread : Threads)
	{
		Thread->WaitForCompletion();

		if (!Thread->Chunk->IsEmpty())
		{
			UVoxelProceduralMeshComponent* Mesh;
			if (Meshes.IsValidIndex(MeshIndex))
			{
				Mesh = Meshes[MeshIndex];
			}
			else
			{
				Mesh = NewObject<UVoxelProceduralMeshComponent>(this, NAME_None, RF_Transient);
				Mesh->bUseAsyncCooking = true;
				Mesh->SetupAttachment(GetRootComponent(), NAME_None);
				Mesh->RegisterComponent();
				Mesh->bCastShadowAsTwoSided = true;
				Mesh->SetSimulatePhysics(false);
				Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
				Mesh->SetRelativeScale3D(FVector::OneVector);
				Meshes.Add(Mesh);
			}

			Mesh->SetRelativeLocation(FVector(Thread->ChunkPosition));

			FVoxelRenderUtilities::CreateMeshSectionFromChunks(ChunkLOD, false, World, Mesh, Materials, Thread->Chunk);

			MeshIndex++;
		}
	}

	for (int I = MeshIndex; I < Meshes.Num(); I++)
	{
		Meshes[I]->DestroyComponent();
	}
	Meshes.SetNum(MeshIndex);

	// Update box
	Box->SetRelativeScale3D(FVector::OneVector);
	FVector HalfSize = (FVector)AssetSize / 2.f;
	Box->SetBoxExtent(HalfSize);
	Box->SetRelativeLocation(HalfSize);

	// Update scale
	Root->SetWorldScale3D(FVector::OneVector * CurrentVoxelSize);

	bBuilt = true;
}

///////////////////////////////////////////////////////////////////////////////

void AVoxelAssetActor::BeginPlay()
{
    Super::BeginPlay();
	SetActorHiddenInGame(true);
	PrimaryActorTick.SetTickFunctionEnable(false);
}

void AVoxelAssetActor::Tick(float DeltaTime)
{
	if (World && Asset)
	{
		if (!bBuilt ||			
			CurrentRenderType		  != World->GetRenderType()     ||
			CurrentUVConfig			  != World->GetUVConfig()	    ||
			CurrentNormalConfig		  != World->GetNormalConfig()   ||
			CurrentMaterialConfig     != World->GetMaterialConfig() ||
			CurrentVoxelMaterial      != World->GetVoxelMaterial()  ||
			CurrentMaterialCollection != World->GetMaterialCollection())
		{
			Update();
		}
		if (CurrentVoxelSize     != World->GetVoxelSize()  ||
			CurrentWorldLocation != World->GetActorLocation())
		{
			ClampTransform();
		}
	}
	else if (!Asset)
	{
		for (auto& Mesh : Meshes)
		{
			Mesh->ClearSections();
		}
	}
}

void AVoxelAssetActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (World)
	{
		ClampTransform();
	}
}

void AVoxelAssetActor::PostEditMove(bool bFinished)
{
	Super::PostEditMove(bFinished);

	if (bFinished && World)
	{
		ClampTransform();
	}
}

///////////////////////////////////////////////////////////////////////////////

void AVoxelAssetActor::ClampTransform()
{
	CurrentVoxelSize = World->GetVoxelSize();
	CurrentWorldLocation = World->GetActorLocation();

	FVector Position = GetActorLocation();
	Position -= World->GetActorLocation();
	Position /= CurrentVoxelSize;

	Position.X = FMath::RoundToInt(Position.X);
	Position.Y = FMath::RoundToInt(Position.Y);
	Position.Z = FMath::RoundToInt(Position.Z);

	Position *= CurrentVoxelSize;
	Position += World->GetActorLocation();

	SetActorLocation(Position);

	SetActorRotation(FRotator::ZeroRotator.Quaternion());	
	
	SetActorScale3D(FVector::OneVector * CurrentVoxelSize);
}
#endif

