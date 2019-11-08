// Copyright 2018 Phyronnaz

#include "VoxelWorld.h"
#include "VoxelLogStatDefinitions.h"
#include "VoxelData/VoxelData.h"
#include "VoxelRender/IVoxelRender.h"
#include "VoxelComponents/VoxelInvokerComponent.h"
#include "VoxelUtilities.h"
#include "VoxelNetworking/VoxelNetworking.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "VoxelSpawners/VoxelActorOctree.h"
#include "VoxelSpawners/VoxelActor.h"
#include "VoxelDebug/VoxelCrashReporter.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BillboardComponent.h"
#include "Engine/Texture2D.h"
#include "VoxelRender/VoxelProceduralMeshComponent.h"
#include "EngineUtils.h"
#include "VoxelPlaceableItems/VoxelAssetActor.h"
#include "Logging/MessageLog.h"
#include "FastNoise.h"
#include "VoxelPlaceableItems/VoxelDefaultItems.h"
#include "VoxelPlaceableItems/VoxelPlaceableItemActor.h"
#include "Engine/Engine.h"
#include "VoxelMaterialCollection.h"
#include "UObject/UObjectIterator.h"
#include "VoxelThreadPool.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "VoxelGraph/VoxelComputeNodeTree.h"
#include "VoxelNetworking/VoxelTcpSocket.h"
#include "VoxelCacheManager.h"
#include "HAL/IConsoleManager.h"
#include "TimerManager.h"

#define LOCTEXT_NAMESPACE "VoxelWorld"

DECLARE_CYCLE_STAT(TEXT("AVoxelWorld::Tick"), STAT_VoxelWorld_Tick, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("AVoxelWorld::ReceiveData"), STAT_VoxelWorld_ReceiveData, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("AVoxelWorld::SendData"), STAT_VoxelWorld_SendData, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("AVoxelWorld::GetIntersection"), STAT_VoxelWorld_GetIntersection, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("AVoxelWorld::CreateWorldInternal"), STAT_VoxelWorld_CreateWorldInternal, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("AVoxelWorld::DestroyWorldInternal"), STAT_VoxelWorld_DestroyWorldInternal, STATGROUP_Voxel);

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Commands ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define CmdHelperBool(Name) \
static void	Name(const TArray<FString>& Args, UWorld* World) \
{ \
	bool bShow = Args.Num() == 0 || (Args[0] == "1" || Args[0] == "true"); \
	 \
	for (TActorIterator<AVoxelWorld> It(World); It; ++It) \
	{ \
		(*It)->b##Name = bShow; \
	} \
}

CmdHelperBool(ShowInvokersBounds);
CmdHelperBool(ShowWorldBounds);
CmdHelperBool(ShowDataOctreeLeavesStatus);
CmdHelperBool(ShowUpdatedChunks);

FAutoConsoleCommandWithWorldAndArgs ShowInvokersBoundsCmd(
	TEXT("voxel.ShowInvokersBounds"),
	TEXT("Show Voxel Invokers Bounds"),
	FConsoleCommandWithWorldAndArgsDelegate::CreateStatic(ShowInvokersBounds));

FAutoConsoleCommandWithWorldAndArgs ShowWorldBoundsCmd(
	TEXT("voxel.ShowWorldBounds"),
	TEXT("Show Voxel Worlds Bounds"),
	FConsoleCommandWithWorldAndArgsDelegate::CreateStatic(ShowWorldBounds));

FAutoConsoleCommandWithWorldAndArgs ShowDataOctreeLeavesStatusCmd(
	TEXT("voxel.ShowDataOctreeLeavesStatus"),
	TEXT("Show Data Octree Leaves Status. Useful to debug the cache status & to see which chunks are stored in memory"),
	FConsoleCommandWithWorldAndArgsDelegate::CreateStatic(ShowDataOctreeLeavesStatus));

FAutoConsoleCommandWithWorldAndArgs ShowUpdatedChunksCmd(
	TEXT("voxel.ShowUpdatedChunks"),
	TEXT("Show Updated Chunks"),
	FConsoleCommandWithWorldAndArgsDelegate::CreateStatic(ShowUpdatedChunks));

///////////////////////////////////////////////////////////////////////////////
///////////////////// Macros to generate getters/setters //////////////////////
///////////////////////////////////////////////////////////////////////////////

static TArray<FString> __NoCheckVariables;
struct FLocalAddToCheckVariables
{
	FLocalAddToCheckVariables(FString String)
	{
		__NoCheckVariables.Add(String);
	}
};
#define COMBINEIMPL(A, B) A##B
#define COMBINE(A, B) COMBINEIMPL(A, B)
#define ADD_TO_NOCHECKVARIABLES(Text)\
static FLocalAddToCheckVariables COMBINE(__NoCheckVar, __LINE__) = FLocalAddToCheckVariables(Text);

inline void __VoxelLogError(const FText& Error)
{
	FMessageLog("PIE").Error(Error);
}

#define CHECK_VOXELWORLD_IS_CREATED(Name, ...) if(!IsCreated()) { __VoxelLogError(FText::FromString(FString(#Name) + TEXT(": World isn't created!"))); return __VA_ARGS__; }
#define CHECK_VOXELWORLD_ISNT_CREATED(Name, ...) if(IsCreated()) { __VoxelLogError(FText::FromString(FString(#Name) + TEXT(": World is created!"))); return __VA_ARGS__; }

#define GETTER_SETTER_IMPL(Name, Prefix, CheckFunc, Accessor) \
void AVoxelWorld::Set##Name(decltype(AVoxelWorld::Prefix##Name) New) \
{ \
	CheckFunc(Set##Name); \
	Prefix##Name = Accessor; \
} \
decltype(AVoxelWorld::Prefix##Name) AVoxelWorld::Get##Name() const \
{ \
	return Prefix##Name; \
}

#define IGNOREMACRO(...)
#define GETTER_SETTER_NOCHECK(Name)              GETTER_SETTER_IMPL(Name,,  IGNOREMACRO, New); ADD_TO_NOCHECKVARIABLES(#Name);
#define GETTER_SETTER_NOCHECK_BOOL(Name)         GETTER_SETTER_IMPL(Name,b, IGNOREMACRO, New); ADD_TO_NOCHECKVARIABLES("b"#Name);
#define GETTER_SETTER_CHECKNOTCREATED(Name)      GETTER_SETTER_IMPL(Name,,  CHECK_VOXELWORLD_ISNT_CREATED, New)
#define GETTER_SETTER_CHECKNOTCREATED_BOOL(Name) GETTER_SETTER_IMPL(Name,b, CHECK_VOXELWORLD_ISNT_CREATED, New)
#define GETTER_SETTER_CHECKNOTCREATED_ACCESSOR(Name, Accessor) GETTER_SETTER_IMPL(Name,, CHECK_VOXELWORLD_ISNT_CREATED, Accessor)

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

inline bool IsDedicatedServerInternal(UWorld* World)
{
	auto* GameInstance = World->GetGameInstance();
	if (!GameInstance)
	{
		return false;
	}
	auto* WorldContext = GameInstance->GetWorldContext();
	if (!WorldContext)
	{
		return false;
	}
	return WorldContext->RunAsDedicated;
}

inline void FixWorldBoundsMinMax(int& Min, int& Max)
{
	if (Min >= Max)
	{
		if (Max > 0)
		{
			Min = Max - CHUNK_SIZE;
		}
		else
		{
			Max = Min + CHUNK_SIZE;
		}
	}
}

inline void FixWorldBounds(FIntBox& WorldBounds, int Depth)
{
	FixWorldBoundsMinMax(WorldBounds.Min.X, WorldBounds.Max.X);
	FixWorldBoundsMinMax(WorldBounds.Min.Y, WorldBounds.Max.Y);
	FixWorldBoundsMinMax(WorldBounds.Min.Z, WorldBounds.Max.Z);
	if (!WorldBounds.IsMultipleOf(CHUNK_SIZE))
	{
		WorldBounds.MakeMultipleOfInclusive(CHUNK_SIZE);
	}
	WorldBounds = FVoxelUtilities::GetBoundsFromDepth<CHUNK_SIZE>(Depth).Overlap(WorldBounds);
	check(WorldBounds.IsMultipleOf(CHUNK_SIZE));
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

AVoxelWorld::AVoxelWorld()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bHighPriority = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

#if WITH_EDITORONLY_DATA
	{
		auto SpriteComponent = CreateEditorOnlyDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));

		// Structure to hold one-time initialization
		struct FConstructorStatics
		{
			ConstructorHelpers::FObjectFinderOptional<UTexture2D> SpriteTextureObject;
			FName ID_Voxel;
			FText NAME_Voxel;
			FConstructorStatics()
				: SpriteTextureObject(TEXT("/Engine/EditorResources/S_Terrain"))
				, ID_Voxel(TEXT("VoxelWorld"))
				, NAME_Voxel(NSLOCTEXT("VoxelCategory", "Voxel World", "Voxel World"))
			{
			}
		};
		static FConstructorStatics ConstructorStatics;

		if (SpriteComponent)
		{
			SpriteComponent->Sprite = ConstructorStatics.SpriteTextureObject.Get();
			SpriteComponent->RelativeScale3D = FVector(0.5f, 0.5f, 0.5f);
			SpriteComponent->bHiddenInGame = true;
			SpriteComponent->bIsScreenSizeScaled = true;
			SpriteComponent->SpriteInfo.Category = ConstructorStatics.ID_Voxel;
			SpriteComponent->SpriteInfo.DisplayName = ConstructorStatics.NAME_Voxel;
			SpriteComponent->SetupAttachment(RootComponent);
			SpriteComponent->bReceivesDecals = false;
		}
	}
#endif // WITH_EDITORONLY_DATA
	{
		ConstructorHelpers::FObjectFinderOptional<UMaterialInterface> MaterialFinder(TEXT("/Voxel/M_MissingMaterial"));
		MissingMaterial = MaterialFinder.Get();
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void AVoxelWorld::AddActorInfos(const TArray<FVoxelActorSpawnInfo>& ActorInfos)
{
	if (ActorInfos.Num() > 0)
	{
		ActorOctree->AddActorInfos(ActorInfos);
	}
}

bool AVoxelWorld::HaveActorsBeenCreated(const FIntBox& Bounds) const
{
	return ActorComputedChunksOctree->IsPartiallyComputed(Bounds);
}

void AVoxelWorld::NotifyActorsAreCreated(const FIntBox& Bounds)
{
	check(!HaveActorsBeenCreated(Bounds));
	ActorComputedChunksOctree->SetAsComputed(Bounds);
}

void AVoxelWorld::EnableFloatingActorsInArea(const FIntBox& Bounds, TArray<AVoxelActor*>& OutActors)
{
	CHECK_VOXELWORLD_IS_CREATED(EnableFloatingActorsInArea);

	ActorOctree->EnableFloatingActorsInArea(Bounds, OutActors);
}

void AVoxelWorld::EnableActorsInArea(const FIntBox& Bounds, TArray<AVoxelActor*>& OutActors)
{
	CHECK_VOXELWORLD_IS_CREATED(EnableActorsInArea);

	ActorOctree->EnableActorsInArea(Bounds, OutActors);
}

AVoxelActor* AVoxelWorld::EnableInstanceInArea(UHierarchicalInstancedStaticMeshComponent* Component, const FIntBox& Bounds, int InstanceIndex)
{
	CHECK_VOXELWORLD_IS_CREATED(EnableInstanceInArea, nullptr);
	if (!Component)
	{
		__VoxelLogError(LOCTEXT("EnableInstanceInAreaInvalidComponent", "EnableInstanceInArea: Invalid Component"));
		return nullptr;
	}

	return ActorOctree->EnableInstanceInArea(Component, Bounds, InstanceIndex);
}

UClass* AVoxelWorld::GetActorClassFromHISM(UHierarchicalInstancedStaticMeshComponent* Component)
{
	CHECK_VOXELWORLD_IS_CREATED(GetActorClassFromHISM, nullptr);
	if (!Component)
	{
		__VoxelLogError(LOCTEXT("GetActorClassFormHISMInvalidComponent", "GetActorClassFormHISM: Invalid Component"));
		return nullptr;
	}

	return ActorOctree->GetActorClassFromHISM(Component);
}

void AVoxelWorld::AddInstance(TSubclassOf<AVoxelActor> VoxelActorClass, FTransform Transform)
{
	CHECK_VOXELWORLD_IS_CREATED(AddInstance);

	if (!VoxelActorClass)
	{
		FMessageLog("PIE").Error(LOCTEXT("InvalidVoxelActorClass", "AddInstance: Invalid VoxelActorClass!"));
		return;
	}

	FVoxelActorConfig* ConfigPtr = nullptr;
	for(auto& It : ActorSpawnerThreadSafe->ActorGroups)
	{
		for (auto& Config : It.Value)
		{
			if (Config.Actor == VoxelActorClass)
			{
				if (!ConfigPtr)
				{
					ConfigPtr = &Config;
				}
				else
				{
					FMessageLog("PIE").Warning(FText::FromString("AVoxelWorld::AddInstance: multiple configs found for class " + VoxelActorClass->GetName() + "!"));
				}
			}
		}
	}
	if (!ConfigPtr)
	{
		FMessageLog("PIE").Error(FText::FromString("AVoxelWorld::AddInstance: no config found for class " + VoxelActorClass->GetName() + "!"));
		return;
	}

	ActorOctree->AddActorInfos({ FVoxelActorSpawnInfo(ConfigPtr, MoveTemp(Transform)) });
}

void AVoxelWorld::RemoveInstance(UHierarchicalInstancedStaticMeshComponent* Component, const FIntBox& Bounds, int InstanceIndex)
{
	CHECK_VOXELWORLD_IS_CREATED(RemoveInstance);
	if (!Component)
	{
		__VoxelLogError(LOCTEXT("RemoveInstanceInvalidComponent", "RemoveInstance: Invalid Component"));
		return;
	}

	return ActorOctree->RemoveInstance(Component, Bounds, InstanceIndex);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void AVoxelWorld::CreateWorld()
{
	if (!IsCreated())
	{
		CreateWorldInternal(
			EPlayType::Normal,
			GrassSpawner,
			ActorSpawner,
			bMultiplayer,
			bEnableUndoRedo,
			bDontUseGlobalPool);
	}
	else
	{
		FMessageLog("PIE").Error(LOCTEXT("CreateWorld", "Can't create world: already created"));
	}
}

void AVoxelWorld::DestroyWorld(bool bClearMeshes)
{
	if (IsCreated())
	{
		DestroyWorldInternal();
		auto Components = GetComponents(); // need a copy as we are modifying it when destroying comps
		for (auto& Component : Components)
		{
			auto Mesh = Cast<UVoxelProceduralMeshComponent>(Component);
			if (bClearMeshes && Mesh)
			{
				Mesh->ClearSections();
			}
			
			if (!Mesh)
			{
				auto HISM = Cast<UHierarchicalInstancedStaticMeshComponent>(Component);
				if (HISM)
				{
					HISM->DestroyComponent();
				}
			}
		}
	}
	else
	{
		FMessageLog("PIE").Error(LOCTEXT("DestroyWorld", "Can't destroy world: not created"));
	}
}

void AVoxelWorld::CreateInEditor(UClass* VoxelWorldEditorClass)
{
	check(VoxelWorldEditorClass);

	if (IsCreated())
	{
		DestroyWorldInternal();
	}

	if (!VoxelWorldEditor)
	{
		// Create/Find VoxelWorldEditor
		for (TActorIterator<AVoxelWorldEditorInterface> It(GetWorld()); It; ++It)
		{
			VoxelWorldEditor = *It;
			break;
		}
		if (!VoxelWorldEditor)
		{
			FActorSpawnParameters Transient;
			Transient.ObjectFlags = RF_Transient;
			VoxelWorldEditor = GetWorld()->SpawnActor<AVoxelWorldEditorInterface>(VoxelWorldEditorClass, Transient);
		}
	}
	VoxelWorldEditor->Init(this);

	CreateWorldInternal(
		EPlayType::Editor,
		GrassSpawner,
		nullptr,
		false,
		true,
		true);
}

void AVoxelWorld::DestroyInEditor()
{
	if (IsCreated())
	{
		DestroyWorldInternal();
		auto Components = GetComponents(); // need a copy as we are modifying it when destroying comps
		for (auto& Component : Components)
		{
			if (auto Mesh = Cast<UVoxelProceduralMeshComponent>(Component))
			{
				Mesh->DestroyComponent();
			}
			if (auto Mesh = Cast<UHierarchicalInstancedStaticMeshComponent>(Component))
			{
				if (Mesh->HasAnyFlags(RF_Transient))
				{
					Mesh->DestroyComponent();
				}
			}
		}
	}
}

void AVoxelWorld::Recreate()
{
	check(IsCreated());

	Render.Reset();
	auto Components = GetComponents();
	for (auto& Component : Components)
	{
		auto Mesh = Cast<UVoxelProceduralMeshComponent>(Component);
		if (Mesh)
		{
			Mesh->DestroyComponent();
		}
	}
	Render = FVoxelRenderFactory::GetVoxelRender(RenderType, this);
	InvokerComponentChangeVersion = -1;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void AVoxelWorld::UpdateCollisionProfile()
{
	CollisionPresets.LoadProfileData(false);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

UMaterialInterface* AVoxelWorld::GetVoxelMaterial(const FVoxelBlendedMaterial& Index) const
{
	auto* Value = MaterialCollection ? MaterialCollection->GetVoxelMaterial(Index) : nullptr;
	if (!Value)
	{
		if (!MaterialCollection)
		{
			FMessageLog("PIE").Error(LOCTEXT("InvalidMaterialCollection", "Invalid Material Collection"));
		}
		else
		{
			FMessageLog("PIE").Error(FText::FromString(FString::Printf(TEXT("Missing the following generated material in %s: %s"), *MaterialCollection->GetPathName(), *Index.ToString())));
		}
	}
	return Value ? Value : MissingMaterial;
}

UMaterialInterface* AVoxelWorld::GetVoxelMaterialWithTessellation(const FVoxelBlendedMaterial& Index) const
{
	auto* Value = MaterialCollection ? MaterialCollection->GetVoxelMaterialWithTessellation(Index) : nullptr;
	if (!Value)
	{
		if (!MaterialCollection)
		{
			FMessageLog("PIE").Error(LOCTEXT("InvalidMaterialCollection", "Invalid Material Collection"));
		}
		else
		{
			FMessageLog("PIE").Error(FText::FromString(FString::Printf(TEXT("Missing the following generated material in %s: Tessellation %s"), *MaterialCollection->GetPathName(), *Index.ToString())));
		}
	}
	return Value ? Value : MissingMaterial;
}

void AVoxelWorld::SetScalarParameterValue(FName ParameterName, float Value)
{
	CHECK_VOXELWORLD_IS_CREATED(SetScalarParameterValue);
	MaterialInstance->SetScalarParameterValue(ParameterName, Value);
	Render->SetScalarParameterValue(ParameterName, Value);
}

void AVoxelWorld::SetTextureParameterValue(FName ParameterName, UTexture* Value)
{
	CHECK_VOXELWORLD_IS_CREATED(SetTextureParameterValue);
	MaterialInstance->SetTextureParameterValue(ParameterName, Value);
	Render->SetTextureParameterValue(ParameterName, Value);
}

void AVoxelWorld::SetVectorParameterValue(FName ParameterName, FLinearColor Value)
{
	CHECK_VOXELWORLD_IS_CREATED(SetVectorParameterValue);
	MaterialInstance->SetVectorParameterValue(ParameterName, Value);
	Render->SetVectorParameterValue(ParameterName, Value);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

FVoxelWorldGeneratorInit AVoxelWorld::GetInitStruct() const
{
	return FVoxelWorldGeneratorInit(GetSeeds(), GetVoxelSize());
}

FVector AVoxelWorld::GetChunkRelativePosition(const FIntVector& Position) const
{
	return FVector(Position + WorldOffset) * GetVoxelSize();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void AVoxelWorld::SetOctreeDepth(int NewDepth)
{
	CHECK_VOXELWORLD_ISNT_CREATED(SetOctreeDepth);
	OctreeDepth = FMath::Clamp(NewDepth, 1, MAX_WORLD_DEPTH - 1);
	// Update world size
	WorldSizeInVoxel = FVoxelUtilities::GetSizeFromDepth<CHUNK_SIZE>(OctreeDepth);
}

int AVoxelWorld::GetOctreeDepth() const
{
	return OctreeDepth;
}

GETTER_SETTER_CHECKNOTCREATED_BOOL(OverrideBounds);
GETTER_SETTER_CHECKNOTCREATED(WorldBounds);

GETTER_SETTER_CHECKNOTCREATED_ACCESSOR(LODLimit, FMath::Clamp(New, 0, MAX_WORLD_DEPTH - 1));
GETTER_SETTER_CHECKNOTCREATED_ACCESSOR(ChunkCullingLOD, FMath::Clamp(New, 0, MAX_WORLD_DEPTH - 1));
GETTER_SETTER_CHECKNOTCREATED_ACCESSOR(VoxelSize, FMath::Max(New, 0.f));
GETTER_SETTER_NOCHECK(VoxelMassMultiplierInKg);
GETTER_SETTER_CHECKNOTCREATED(SaveObject);
GETTER_SETTER_NOCHECK_BOOL(CreateWorldAutomatically);
GETTER_SETTER_CHECKNOTCREATED_BOOL(EnableUndoRedo);
GETTER_SETTER_NOCHECK_BOOL(WaitForOtherChunksToAvoidHoles);

void AVoxelWorld::SetWorldGeneratorObject(UVoxelWorldGenerator* NewGenerator)
{
	if (!NewGenerator)
	{
		FMessageLog("PIE").Error(LOCTEXT("SetWorldGeneratorObjectNull", "SetWorldGeneratorObject: NewGenerator is NULL"));
		return;
	}

	CHECK_VOXELWORLD_ISNT_CREATED(SetWorldGeneratorObject);

	WorldGenerator.Type = EVoxelWorldGeneratorPickerType::Object;
	WorldGenerator.WorldGeneratorObject = NewGenerator;
}

void AVoxelWorld::SetWorldGeneratorClass(TSubclassOf<UVoxelWorldGenerator> NewGeneratorClass)
{
	if(!NewGeneratorClass)
	{
		FMessageLog("PIE").Error(LOCTEXT("SetWorldGeneratorClassNull", "SetWorldGeneratorClass: NewGeneratorClass is NULL"));
		return;
	}

	CHECK_VOXELWORLD_ISNT_CREATED(SetWorldGeneratorObject);

	WorldGenerator.Type = EVoxelWorldGeneratorPickerType::Class;
	WorldGenerator.WorldGeneratorClass = NewGeneratorClass;
}

void AVoxelWorld::AddSeeds(const TMap<FString, int>& NewSeeds)
{
	CHECK_VOXELWORLD_ISNT_CREATED(AddSeeds);
	Seeds.Append(NewSeeds);
}

void AVoxelWorld::AddSeed(FString Name, int Value)
{
	CHECK_VOXELWORLD_ISNT_CREATED(AddSeed);
	Seeds.Add(Name, Value);
}

void AVoxelWorld::ClearSeeds()
{
	CHECK_VOXELWORLD_ISNT_CREATED(ClearSeeds);
	Seeds.Reset();
}

TMap<FString, int> AVoxelWorld::GetSeeds() const
{
	return Seeds;
}
GETTER_SETTER_CHECKNOTCREATED_BOOL(EnableWorldRebasing);

///////////////////////////////////////////////////////////////////////////////

GETTER_SETTER_CHECKNOTCREATED(RenderType);
GETTER_SETTER_CHECKNOTCREATED(UVConfig);
GETTER_SETTER_CHECKNOTCREATED(NormalConfig);
GETTER_SETTER_CHECKNOTCREATED(MaterialConfig);
GETTER_SETTER_CHECKNOTCREATED(VoxelMaterial);
GETTER_SETTER_CHECKNOTCREATED(VoxelMaterialWithTessellation);
GETTER_SETTER_CHECKNOTCREATED(MaterialCollection);

GETTER_SETTER_NOCHECK(ChunksFadeDuration);
GETTER_SETTER_CHECKNOTCREATED_BOOL(EnableTessellation);
GETTER_SETTER_CHECKNOTCREATED(BoundsExtension);
GETTER_SETTER_CHECKNOTCREATED(TessellationMaxLOD);

GETTER_SETTER_CHECKNOTCREATED(GrassSpawner);
GETTER_SETTER_CHECKNOTCREATED(ActorSpawner);
GETTER_SETTER_NOCHECK(MaxGrassChunkLOD);
GETTER_SETTER_NOCHECK(MaxActorChunkLOD);
GETTER_SETTER_NOCHECK_BOOL(EnableGrassWhenEditing);
GETTER_SETTER_CHECKNOTCREATED(DistanceBetweenActorHISMInVoxels);

GETTER_SETTER_CHECKNOTCREATED(LightingChannels);
	
///////////////////////////////////////////////////////////////////////////////

GETTER_SETTER_CHECKNOTCREATED(MaxCollisionsLOD);
GETTER_SETTER_CHECKNOTCREATED(CollisionPresets);
		
///////////////////////////////////////////////////////////////////////////////

GETTER_SETTER_NOCHECK(LODUpdateRate);

GETTER_SETTER_NOCHECK(ActorCullingUpdateRate);

GETTER_SETTER_CHECKNOTCREATED_BOOL(DontUseGlobalPool);
GETTER_SETTER_CHECKNOTCREATED(MeshThreadCount);
GETTER_SETTER_NOCHECK(LODCurve);
GETTER_SETTER_NOCHECK_BOOL(OptimizeIndices);

///////////////////////////////////////////////////////////////////////////////

GETTER_SETTER_CHECKNOTCREATED_BOOL(Multiplayer);
GETTER_SETTER_NOCHECK(MultiplayerSyncRate);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

bool AVoxelWorld::IsCreated() const
{
	return bIsCreated;
}

FIntBox AVoxelWorld::GetBounds() const
{
	CHECK_VOXELWORLD_IS_CREATED(GetBounds, FIntBox());
	return Data->GetBounds();
}

int32 AVoxelWorld::GetTaskCount() const
{
	return IsCreated() ? FMath::Max(Render->GetTaskCount(), 0) : 0;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

FIntVector AVoxelWorld::GlobalToLocal(const FVector& Position) const
{
	FVector P = GetTransform().InverseTransformPosition(Position) / GetVoxelSize();

	FIntVector LocalPosition;

	switch (GetRenderType())
	{
	case EVoxelRenderType::Cubic:
	{
		LocalPosition = FIntVector(FMath::FloorToInt(P.X), FMath::FloorToInt(P.Y), FMath::FloorToInt(P.Z));
		break;
	}
	case EVoxelRenderType::MarchingCubes:
	default:
	{
		LocalPosition = FIntVector(FMath::RoundToInt(P.X), FMath::RoundToInt(P.Y), FMath::RoundToInt(P.Z));
		break;
	}
	}

	return LocalPosition - WorldOffset;
}

FVector AVoxelWorld::GlobalToLocalFloat(const FVector& Position) const
{
	return GetTransform().InverseTransformPosition(Position) / GetVoxelSize() - FVector(WorldOffset);
}

FVector AVoxelWorld::LocalToGlobal(const FIntVector& Position) const
{
	return GetTransform().TransformPosition(GetVoxelSize() * FVector(Position + WorldOffset));
}

FVector AVoxelWorld::LocalToGlobalFloat(const FVector& Position) const
{
	return GetTransform().TransformPosition(GetVoxelSize() * (Position + FVector(WorldOffset)));
}

TArray<FIntVector> AVoxelWorld::GetNeighboringPositions(const FVector& GlobalPosition) const
{
	FVector P = GlobalToLocalFloat(GlobalPosition);
	return TArray<FIntVector>({
		FIntVector(FMath::FloorToInt(P.X), FMath::FloorToInt(P.Y), FMath::FloorToInt(P.Z)),
		FIntVector(FMath::CeilToInt(P.X) , FMath::FloorToInt(P.Y), FMath::FloorToInt(P.Z)),
		FIntVector(FMath::FloorToInt(P.X), FMath::CeilToInt(P.Y) , FMath::FloorToInt(P.Z)),
		FIntVector(FMath::CeilToInt(P.X) , FMath::CeilToInt(P.Y) , FMath::FloorToInt(P.Z)),
		FIntVector(FMath::FloorToInt(P.X), FMath::FloorToInt(P.Y), FMath::CeilToInt(P.Z)),
		FIntVector(FMath::CeilToInt(P.X) , FMath::FloorToInt(P.Y), FMath::CeilToInt(P.Z)),
		FIntVector(FMath::FloorToInt(P.X), FMath::CeilToInt(P.Y) , FMath::CeilToInt(P.Z)),
		FIntVector(FMath::CeilToInt(P.X) , FMath::CeilToInt(P.Y) , FMath::CeilToInt(P.Z))
		});
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void AVoxelWorld::UpdateChunksAtPosition(const FIntVector& Position)
{
	CHECK_VOXELWORLD_IS_CREATED(UpdateChunksAtPosition);
	Render->UpdateBox(FIntBox(Position), false);
}

void AVoxelWorld::UpdateChunksOverlappingBox(const FIntBox& Box, bool bRemoveHoles)
{
	CHECK_VOXELWORLD_IS_CREATED(UpdateChunksOverlappingBox);
	Render->UpdateBox(Box, bRemoveHoles);
}

void AVoxelWorld::UpdateChunksOverlappingBox(const FIntBox& Box, TFunction<void()> CallbackWhenUpdated)
{
	Render->UpdateBox(Box, true, CallbackWhenUpdated);
}

void AVoxelWorld::UpdateAll()
{
	CHECK_VOXELWORLD_IS_CREATED(UpdateAll);
	Render->UpdateBox(FIntBox::Infinite, false);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int AVoxelWorld::GetLODAt(const FIntVector& Position) const
{
	CHECK_VOXELWORLD_IS_CREATED(GetLODAt, 0);

	if (IsInWorld(Position))
	{
		return Render->GetLODAtPosition(Position);
	}
	else
	{
		FMessageLog("PIE").Error(FText::Format(LOCTEXT("GetLODAtNIW", "GetLODAt: Not in world: ({0}, {1}, {2})"), Position.X, Position.Y, Position.Z));
		return 0;
	}
}

bool AVoxelWorld::IsInWorld(const FIntVector& Position) const
{
	CHECK_VOXELWORLD_IS_CREATED(IsInWorld, false);
	return Data->IsInWorld(Position);
}

bool AVoxelWorld::IsInside(const FVector& Position) const
{
	CHECK_VOXELWORLD_IS_CREATED(IsInside, false);
	for (auto& P : GetNeighboringPositions(Position))
	{
		if (!FVoxelValue(GetValue(P)).IsEmpty())
		{
			return true;
		}
	}
	return false;
}

bool AVoxelWorld::GetIntersection(const FIntVector& Start, const FIntVector& End, FVector& OutGlobalPosition, FIntVector& OutVoxelPosition) const
{
	SCOPE_CYCLE_COUNTER(STAT_VoxelWorld_GetIntersection);
	
	CHECK_VOXELWORLD_IS_CREATED(GetIntersection, false);

	FIntVector Diff = End - Start;
	if (Diff.X != 0)
	{
		if (Diff.Y != 0 || Diff.Z != 0)
		{
			FMessageLog("PIE").Error(LOCTEXT("GetIntersectionError", "GetIntersection: Start and end should have 2 common coordinates"));
			return false;
		}
	}
	else if (Diff.Y != 0)
	{
		if (Diff.X != 0 || Diff.Z != 0)
		{
			FMessageLog("PIE").Error(LOCTEXT("GetIntersectionError", "GetIntersection: Start and end should have 2 common coordinates"));
			return false;
		}
	}
	else if (Diff.Z != 0)
	{
		if (Diff.X != 0 || Diff.Y != 0)
		{
			FMessageLog("PIE").Error(LOCTEXT("GetIntersectionError", "GetIntersection: Start and end should have 2 common coordinates"));
			return false;
		}
	}

	FIntVector RealStart(FMath::Min(Start.X, End.X), FMath::Min(Start.Y, End.Y), FMath::Min(Start.Z, End.Z));
	FIntVector RealEnd(FMath::Max(Start.X, End.X) + 1, FMath::Max(Start.Y, End.Y) + 1, FMath::Max(Start.Z, End.Z) + 1);

	bool bFound = false;
	
	{
		FVoxelScopeGetLock Lock(Data, FIntBox(RealStart, RealEnd));

		FVoxelValue OldValue = Data->GetValue(RealStart.X, RealStart.Y, RealStart.Z);
		FIntVector OldPosition = RealStart;
		for (int X = RealStart.X; X < RealEnd.X; X++)
		{
			for (int Y = RealStart.Y; Y < RealEnd.Y; Y++)
			{
				for (int Z = RealStart.Z; Z < RealEnd.Z; Z++)
				{
					if (UNLIKELY(!Data->IsInWorld(X, Y, Z)))
					{
						FMessageLog("PIE").Error(LOCTEXT("GetIntersectionOOB", "GetIntersection: Out of world!"));
						return false;
					}

					FVoxelValue Value = Data->GetValue(X, Y, Z);
					FIntVector Position(X, Y, Z);

					if (!FVoxelUtilities::HaveSameSign(OldValue, Value))
					{
						bool bSuccess;
						const float t = OldValue.ThisDividedByThisMinusA(Value, bSuccess);
						check(bSuccess);

						FVector Q = t * FVector(Position) + (1 - t) * FVector(OldPosition);
						OutGlobalPosition = LocalToGlobalFloat(Q);
						OutVoxelPosition = Position;
						bFound = true;
					}

					OldValue = Value;
					OldPosition = Position;

					if (bFound)
					{
						break;
					}
				}
				if (bFound)
				{
					break;
				}
			}
			if (bFound)
			{
				break;
			}
		}
	}

	return bFound;
}

FVector AVoxelWorld::GetNormal(const FIntVector& Position) const
{	
	CHECK_VOXELWORLD_IS_CREATED(GetNormal, FVector::ZeroVector);

	FVoxelScopeGetLock Lock(Data, FIntBox(FIntVector(Position.X - 1, Position.Y - 1, Position.Z - 1), FIntVector(Position.X + 2, Position.Y + 2, Position.Z + 2)));
	FVector Gradient = Data->GetGradient(Position);

	return Gradient;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

float AVoxelWorld::GetValue(const FIntVector& Position) const
{
	CHECK_VOXELWORLD_IS_CREATED(GetValue, 0);

	if (IsInWorld(Position))
	{
		FVoxelValue Value;

		{
			FVoxelScopeGetLock Lock(Data, FIntBox(Position));
			Value = Data->GetValue(Position);
		}

		return Value.ToFloat();
	}
	else
	{
		FMessageLog("PIE").Error(FText::Format(LOCTEXT("GetValueOOB", "Get value: Not in world: ({0}, {1}, {2})"), Position.X, Position.Y, Position.Z));
		return 0;
	}
}

void AVoxelWorld::SetValue(const FIntVector& Position, float Value, bool bUpdateRender)
{
	CHECK_VOXELWORLD_IS_CREATED(SetValue);

	if (IsInWorld(Position))
	{
		{
			FVoxelScopeSetLock Lock(Data, FIntBox(Position));
			Data->SetValue(Position, Value);
		}

		if (bUpdateRender)
		{
			UpdateChunksAtPosition(Position);
		}
	}
	else
	{
		FMessageLog("PIE").Error(FText::Format(LOCTEXT("SetValueOOB", "Set Value: Not in world: ({0}, {1}, {2})"), Position.X, Position.Y, Position.Z));
	}
}

FVoxelMaterial AVoxelWorld::GetMaterial(const FIntVector& Position) const
{
	CHECK_VOXELWORLD_IS_CREATED(GetMaterial, FVoxelMaterial());

	if (IsInWorld(Position))
	{
		FVoxelMaterial Material;
		
		{
			FVoxelScopeGetLock Lock(Data, FIntBox(Position));
			Material = Data->GetMaterial(Position);
		}

		return Material;
	}
	else
	{
		FMessageLog("PIE").Error(FText::Format(LOCTEXT("GetMaterialOOB", "Get material: Not in world: ({0}, {1}, {2})"), Position.X, Position.Y, Position.Z));
		return FVoxelMaterial();
	}
}

void AVoxelWorld::SetMaterial(const FIntVector& Position, const FVoxelMaterial& Material, bool bUpdateRender)
{
	CHECK_VOXELWORLD_IS_CREATED(SetMaterial);

	if (IsInWorld(Position))
	{
		
		{
			FVoxelScopeSetLock Lock(Data, FIntBox(Position));
			Data->SetMaterial(Position, Material);
		}

		if (bUpdateRender)
		{
			UpdateChunksAtPosition(Position);
		}
	}
	else
	{
		FMessageLog("PIE").Error(FText::Format(LOCTEXT("SetMaterialOOB", "Set material: Not in world: ({0}, {1}, {2})"), Position.X, Position.Y, Position.Z));
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void AVoxelWorld::GetSave(FVoxelUncompressedWorldSave& OutSave) const
{
	CHECK_VOXELWORLD_IS_CREATED(GetSave);
	Data->GetSave(OutSave);
}

void AVoxelWorld::GetCompressedSave(FVoxelCompressedWorldSave& OutSave) const
{
	CHECK_VOXELWORLD_IS_CREATED(GetCompressedSave);
	FVoxelUncompressedWorldSave Save;
	Data->GetSave(Save);
	UVoxelSaveUtilities::CompressVoxelSave(Save, OutSave);
}

void AVoxelWorld::LoadFromSave(const FVoxelUncompressedWorldSave& Save)
{
	CHECK_VOXELWORLD_IS_CREATED(LoadFromSave, );
	if (Save.GetDepth() == -1)
	{
		FMessageLog("PIE").Error(LOCTEXT("LoadFromSaveError", "LoadFromSave: Invalid save"));
	}
	else
	{
		if (Save.GetDepth() > OctreeDepth)
		{
			FMessageLog("PIE").Warning(LOCTEXT("LoadFromSaveWarning", "LoadFromSave: Save depth is bigger than world depth, possible loss of data"));
		}
		TArray<FIntBox> BoundsToUpdate;
		Data->LoadFromSave(Save, BoundsToUpdate);
		for (auto& Bounds : BoundsToUpdate)
		{
			UpdateChunksOverlappingBox(Bounds, false);
		}
	}
}

void AVoxelWorld::LoadFromCompressedSave(FVoxelCompressedWorldSave& Save)
{
	CHECK_VOXELWORLD_IS_CREATED(LoadFromCompressedSave);
	FVoxelUncompressedWorldSave UncompressedSave;
	UVoxelSaveUtilities::DecompressVoxelSave(Save, UncompressedSave);
	LoadFromSave(UncompressedSave);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

bool AVoxelWorld::ConnectClient(const FString& Ip, int32 Port)
{
	if (!bMultiplayer)
	{
		FMessageLog("PIE").Error(LOCTEXT("CreateClientSocketbMultiplayer", "ConnectClient: Starting client with bMultiplayer set to false"));
		return false;
	}
	if (NetworkClient.IsValid())
	{
		FMessageLog("PIE").Error(LOCTEXT("CreateClientSocketCCreated", "ConnectClient: Cannot create client: client already created"));
		return false;
	}
	if (NetworkServer.IsValid())
	{
		FMessageLog("PIE").Error(LOCTEXT("CreateClientSocketSCreated", "ConnectClient: Cannot create client: server already created"));
		return false;
	}
	Socket = MakeShared<FVoxelTcpSocket>();
	if (!Socket->ConnectTcpClient(Ip, Port))
	{
		FMessageLog("PIE").Error(LOCTEXT("CreateClientSocketFailed", "ConnectClient: Connection failed!"));
		return false;
	}

	NetworkClient = MakeShared<FVoxelNetworkingClient>(Socket.Get());
	UE_LOG(LogVoxel, Log, TEXT("Client started"));

	return true;
}

void AVoxelWorld::StartServer(const FString& Ip, int32 Port)
{
	if (!bMultiplayer)
	{
		FMessageLog("PIE").Error(LOCTEXT("CreateServerSocketbMultiplayer", "CreateServerSocket: Starting server with bMultiplayer set to false"));
		return;
	}
	if (NetworkClient.IsValid())
	{
		FMessageLog("PIE").Error(LOCTEXT("CreateServerSocketCCreated", "CreateServerSocket: Cannot create server: client already created"));
		return;
	}
	if (NetworkServer.IsValid())
	{
		FMessageLog("PIE").Error(LOCTEXT("CreateServerSocketSCreated", "CreateServerSocket: Cannot create server: server already created"));
		return;
	}
	Socket = MakeShared<FVoxelTcpSocket>();
	Socket->StartTcpServer(Ip, Port);

	NetworkServer = MakeShared<FVoxelNetworkingServer>(Socket.Get());
	NetworkServer->OnConnection().BindUObject(this, &AVoxelWorld::TriggerOnClientConnection);

	UE_LOG(LogVoxel, Log, TEXT("Server started"));
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void AVoxelWorld::Undo()
{
	CHECK_VOXELWORLD_IS_CREATED(Undo);

	if (!bEnableUndoRedo)
	{
		FMessageLog("PIE").Error(LOCTEXT("UndobEnableUndoRedo", "Undo: Undo called but bEnableUndoRedo is false"));
	}
	else if (!GetData()->CheckIfCurrentFrameIsEmpty())
	{
		FMessageLog("PIE").Error(LOCTEXT("UndoSaveFrame", "Undo: Undo called before SaveFrame"));
	}
	else
	{
		TArray<FIntBox> BoundsToUpdate;
		GetData()->Undo(BoundsToUpdate);
		for (auto& Bounds : BoundsToUpdate)
		{
			UpdateChunksOverlappingBox(Bounds, false);
		}
	}
}

void AVoxelWorld::Redo()
{
	CHECK_VOXELWORLD_IS_CREATED(Redo);

	if (!bEnableUndoRedo)
	{
		FMessageLog("PIE").Error(LOCTEXT("RedobEnableUndoRedo", "Redo: Redo called but bEnableUndoRedo is false"));
	}
	else if (!GetData()->CheckIfCurrentFrameIsEmpty())
	{
		FMessageLog("PIE").Error(LOCTEXT("RedoSaveFrame", "Redo: Redo called before SaveFrame"));
	}
	else
	{
		TArray<FIntBox> BoundsToUpdate;
		GetData()->Redo(BoundsToUpdate);
		for (auto& Bounds : BoundsToUpdate)
		{
			UpdateChunksOverlappingBox(Bounds, false);
		}
	}
}

void AVoxelWorld::SaveFrame()
{
	CHECK_VOXELWORLD_IS_CREATED(SaveFrame);
	if (!bEnableUndoRedo)
	{
		FMessageLog("PIE").Error(LOCTEXT("SaveFrame", "SaveFrame: SaveFrame called but bEnableUndoRedo is false"));
	}
	else
	{
		GetData()->SaveFrame();
	}
}

void AVoxelWorld::ClearFrames()
{
	CHECK_VOXELWORLD_IS_CREATED(ClearFrames);
	if (!bEnableUndoRedo)
	{
		FMessageLog("PIE").Error(LOCTEXT("ClearFrames", "ClearFrames: ClearFrames called but bEnableUndoRedo is false"));
	}
	else
	{
		GetData()->ClearFrames();
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void AVoxelWorld::DrawDebugIntBox(const FIntBox& Box, float Lifetime, float Thickness, FLinearColor Color) const
{
	DrawDebugIntBox(Box, Lifetime, Thickness, Color.ToFColor(false));
}

void AVoxelWorld::DrawDebugIntBox(const FIntBox& Box, float Lifetime, float Thickness, FColor Color, float BorderOffset) const
{
	FVector Min = LocalToGlobal(Box.Min);
	FVector Max = LocalToGlobal(Box.Max);

	FBox DebugBox(Min + BorderOffset, Max - BorderOffset);

	DrawDebugBox(GetWorld(), DebugBox.GetCenter(), DebugBox.GetExtent(), Color, false, Lifetime, 0, Thickness);
}

void AVoxelWorld::DebugVoxelsInsideBox(FIntBox Box, FLinearColor Color, float Lifetime, float Thickness, bool bDebugDensities, FLinearColor TextColor) const
{
	CHECK_VOXELWORLD_IS_CREATED(DebugVoxelsInsideBox);
	for (int X = Box.Min.X; X < Box.Max.X; X++)
	{
		for (int Y = Box.Min.Y; Y < Box.Max.Y; Y++)
		{
			for (int Z = Box.Min.Z; Z < Box.Max.Z; Z++)
			{
				DrawDebugIntBox(FIntBox(X, Y, Z), Lifetime, Thickness, Color);

				if (bDebugDensities)
				{
					FVoxelScopeGetLock Lock(GetData(), FIntBox(X, Y, Z));
					FVoxelValue Value = GetData()->GetValue(X, Y, Z);
					DrawDebugString(GetWorld(), LocalToGlobal(FIntVector(X, Y, Z)), Value.ToString(), nullptr, TextColor.ToFColor(false), Lifetime);
				}
			}
		}
	}
}

void AVoxelWorld::ClearCache(const TArray<FIntBox>& BoundsToKeepCached)
{
	CHECK_VOXELWORLD_IS_CREATED(ClearCache);
	CacheManager->ClearCache(BoundsToKeepCached);
}

void AVoxelWorld::Cache(const TArray<FIntBox>& BoundsToCache)
{
	CHECK_VOXELWORLD_IS_CREATED(Cache);
	CacheManager->Cache(BoundsToCache);
}

void AVoxelWorld::AddOffset(const FIntVector& OffsetInVoxels, bool bMoveActor)
{
	CHECK_VOXELWORLD_IS_CREATED(AddOffset);
	if (bMoveActor)
	{
		SetActorLocation(GetTransform().TransformPosition(GetVoxelSize() * FVector(OffsetInVoxels)));
	}
	WorldOffset -= OffsetInVoxels;
	Render->RecomputeMeshPositions();
}

void AVoxelWorld::AddWorms(float Radius, int Seed, FVector RotationAmplitude, FVector NoiseDir, float NoiseSegmentLength, FVector Start, FVector InitialDir,
	                       float VoxelSegmentLength, int NumSegments, float SplitProbability, float SplitProbabilityGain, int BranchMeanSize, int BranchSizeVariation)
{
	CHECK_VOXELWORLD_IS_CREATED(AddWorms);
	
	TArray<FVoxelId> Octrees;

	static bool bIsFirst = true;
	static FRandomStream Stream;

	bool bIsFirstLocal = bIsFirst;

	if (bIsFirstLocal)
	{
		Stream = FRandomStream(Seed);
		bIsFirst = false;
		GetData()->BeginSet(FIntBox::Infinite, Octrees);
	}

	FastNoise ModuleX;
	FastNoise ModuleY;
	FastNoise ModuleZ;

	ModuleX.SetSeed(Seed);
	ModuleY.SetSeed(Seed + 1);
	ModuleZ.SetSeed(Seed + 2);

	FVector CurrentPosition = Start;
	FVector CurrentDir = InitialDir;
	for (int I = 0; I < NumSegments; I++)
	{
		FVector NewPosition = CurrentPosition + CurrentDir * VoxelSegmentLength;
		GetData()->AddItem<FVoxelPerlinWorm>(CurrentPosition, NewPosition, Radius);
		CurrentPosition = NewPosition;

		FVector NoisePosition = NoiseDir * NoiseSegmentLength * I;
		CurrentDir = CurrentDir.RotateAngleAxis(RotationAmplitude.X * ModuleX.GetSimplex(NoisePosition.X, NoisePosition.Y, NoisePosition.Z), FVector(1, 0, 0));
		CurrentDir = CurrentDir.RotateAngleAxis(RotationAmplitude.Y * ModuleY.GetSimplex(NoisePosition.X, NoisePosition.Y, NoisePosition.Z), FVector(0, 1, 0));
		CurrentDir = CurrentDir.RotateAngleAxis(RotationAmplitude.Z * ModuleZ.GetSimplex(NoisePosition.X, NoisePosition.Y, NoisePosition.Z), FVector(0, 0, 1));

		if (Stream.FRand() < SplitProbability)
		{
			AddWorms(
				Radius,
				Seed + 10, 
				RotationAmplitude,
				NoiseDir, 
				NoiseSegmentLength, 
				CurrentPosition,
				CurrentDir.RotateAngleAxis((Stream.FRand() * 2 - 1) * RotationAmplitude.X, FVector(1, 0, 0)).RotateAngleAxis((Stream.FRand() * 2 - 1) * RotationAmplitude.Y, FVector(0, 1, 0)).RotateAngleAxis((Stream.FRand() * 2 - 1) * RotationAmplitude.Z, FVector(0, 0, 1)),
				VoxelSegmentLength, 
				FMath::Min<int>(BranchMeanSize + (Stream.FRand() * 2 - 1) * BranchSizeVariation, NumSegments - (I + 1)),
				SplitProbability * SplitProbabilityGain,
				SplitProbabilityGain);
		}
	}

	if (bIsFirstLocal)
	{
		GetData()->EndSet(Octrees);
		bIsFirst = true;
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void AVoxelWorld::BeginPlay()
{
	Super::BeginPlay();

	FVoxelCrashReporter::ResetIgnoreMessages();
	FVoxelGraphPerfCounter::Reset();

	UpdateCollisionProfile();

	if (!IsCreated() && bCreateWorldAutomatically)
	{
		CreateWorld();
	}
}

void AVoxelWorld::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (IsCreated())
	{
		DestroyWorld(false);
	}
}

void AVoxelWorld::Tick(float DeltaTime)
{
	SCOPE_CYCLE_COUNTER(STAT_VoxelWorld_Tick);

	Super::Tick(DeltaTime);

	if (IsCreated())
	{
		const float Time = GetWorld()->GetTimeSeconds();

		// Debug
		{
			if (bShowWorldBounds)
			{
				FIntBox Bounds = Data->GetBounds();
				DrawDebugIntBox(Bounds, 2 * DeltaTime, WorldBoundsThickness, FLinearColor::Red);
			}
			if (bShowInvokersBounds)
			{
				for (auto& Invoker : Invokers)
				{
					if (Invoker.IsValid())
					{
						DrawDebugIntBox(Invoker->GetCameraBounds(this), 2 * DeltaTime, InvokersBoundsThickness, Invoker->IsLocalInvoker() ? FColor::Red : FColor::Silver);
					}
				}
			}
		}

		auto TaskCount = Render->GetTaskCount();
		if (TaskCount >= 0)
		{
			if (TaskCount > 0)
			{
				GEngine->AddOnScreenDebugMessage((uint64)((PTRINT)this), 0.1, FColor::White, FString::Printf(TEXT("Tasks remaining: %d"), TaskCount));
			}
			else
			{
				if (!bWorldLoadAlreadyFinished)
				{
					bWorldLoadAlreadyFinished = true;
					OnWorldLoaded.Broadcast();
				}
			}
		}

		if (CacheManager->IsCaching())
		{			
			GEngine->AddOnScreenDebugMessage((uint64)((PTRINT)this) + 1, 0.1, FColor::White, TEXT("Building cache"));
		}

		if (InvokerComponentChangeVersion < UVoxelInvokerComponent::GetChangeVersion())
		{
			InvokerComponentChangeVersion = UVoxelInvokerComponent::GetChangeVersion();
			Invokers = UVoxelInvokerComponent::GetInvokers(GetWorld());
			Invokers.RemoveAll([](auto Ptr) { return !Ptr.IsValid(); });
		}

		Render->Tick(DeltaTime);

		if (NextActorCullingUpdateTime < Time)
		{
			NextActorCullingUpdateTime = Time + 1.f / ActorCullingUpdateRate;
			ActorOctree->Cull();
		}

		if (bMultiplayer)
		{
			if (NetworkClient.IsValid())
			{
				ReceiveData();
			}
			else if (NetworkServer.IsValid())
			{
				if (NextSyncTime < Time)
				{
					NextSyncTime = Time + 1.f / MultiplayerSyncRate;
					SendData();

					if (OnClientConnectionTrigger.GetValue() > 0)
					{
						OnClientConnectionTrigger.Reset();

						UE_LOG(LogVoxel, Log, TEXT("Sending world to clients"));
						FVoxelCompressedWorldSave Save;
						GetCompressedSave(Save);
						NetworkServer->SendSave(Save, true);

						OnClientConnection.Broadcast();
					}
				}
			}
		}
	}
}

void AVoxelWorld::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	// Temp fix
	if (IsTemplate())
	{
		CollisionPresets.FixupData(this);
	}
}

void AVoxelWorld::ApplyWorldOffset(const FVector& InOffset, bool bWorldShift)
{
	if (!IsCreated() || !bEnableWorldRebasing)
	{
		Super::ApplyWorldOffset(InOffset, bWorldShift);
	}
	else
	{
		const FVector RelativeOffset = InOffset / GetVoxelSize();
		const FIntVector IntegerOffset = FVoxelIntVector::RoundToInt(RelativeOffset);
		const FVector GlobalIntegerOffset = (FVector)IntegerOffset * GetVoxelSize();
		const FVector Diff = InOffset - GlobalIntegerOffset;

		Super::ApplyWorldOffset(Diff, bWorldShift);

		WorldOffset += IntegerOffset;

		Render->RecomputeMeshPositions();
		ActorOctree->RecomputeMeshPositions();
	}
}

void AVoxelWorld::PostLoad()
{
	Super::PostLoad();

	if (LOD_DEPRECATED > 0)
	{
		OctreeDepth = LOD_DEPRECATED;
	}
}

#if WITH_EDITOR
bool AVoxelWorld::ShouldTickIfViewportsOnly() const
{
	return true;
}

bool AVoxelWorld::CanEditChange(const UProperty* InProperty) const
{
	if (!InProperty)
	{
		return Super::CanEditChange(InProperty);
	}

	const FString Name = InProperty->GetNameCPP();

	bool bCanEdit;

	if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, NormalConfig))
	{
		bCanEdit = RenderType == EVoxelRenderType::MarchingCubes;
	}
	else if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, VoxelMaterial))
	{
		bCanEdit = MaterialConfig == EVoxelMaterialConfig::RGB;
	}
	else if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, VoxelMaterialWithTessellation))
	{
		bCanEdit = MaterialConfig == EVoxelMaterialConfig::RGB;
	}
	else if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, MaterialCollection))
	{
		bCanEdit = MaterialConfig != EVoxelMaterialConfig::RGB;
	}
	else
	{
		bCanEdit = true;
	}

	const static TArray<FString> EditsAllowedObjectsWhenCreated = 
	{
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, SaveObject), 
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, VoxelSize),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, VoxelMaterial),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, MaterialCollection),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, MaterialConfig),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, RenderType), 
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, NormalConfig),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, UVConfig),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, bShowWorldBounds),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, bShowAllRenderChunks),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, bColorTransitions),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, WorldBoundsThickness),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, bShowInvokersBounds),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, InvokersBoundsThickness),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, bShowDataOctreeLeavesStatus),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, bHideEmptyDataOctreeLeaves),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, DataOctreeLeavesThickness),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, bShowUpdatedChunks),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, bDebugMultiplayer),
		GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, UpdatedChunksThickness)
	};

	if (IsCreated())
	{
		return bCanEdit && (EditsAllowedObjectsWhenCreated.Contains(InProperty->GetNameCPP()) || __NoCheckVariables.Contains(InProperty->GetNameCPP())) && Super::CanEditChange(InProperty);
	}
	else
	{
		return bCanEdit && Super::CanEditChange(InProperty);
	}
}

void AVoxelWorld::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	OctreeDepth = FMath::Clamp(OctreeDepth, 1, MAX_WORLD_DEPTH - 1);

	if (PropertyChangedEvent.MemberProperty)
	{
		auto Name = PropertyChangedEvent.MemberProperty->GetNameCPP();
		if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, OctreeDepth))
		{
			WorldSizeInVoxel = FVoxelUtilities::GetSizeFromDepth<CHUNK_SIZE>(OctreeDepth);
		}
		else if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, WorldSizeInVoxel))
		{
			OctreeDepth = FVoxelUtilities::GetDepthFromSize<CHUNK_SIZE>(WorldSizeInVoxel);
			WorldSizeInVoxel = FVoxelUtilities::GetSizeFromDepth<CHUNK_SIZE>(OctreeDepth);
		} 
		if (IsCreated())
		{
			if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, VoxelMaterial))
			{
				Recreate();
			}
			else if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, VoxelMaterialWithTessellation))
			{
				Recreate();
			}
			else if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, MaterialCollection))
			{
				Recreate();
			}
			else if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, MaterialConfig))
			{
				Recreate();
			}
			else if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, RenderType))
			{
				Recreate();
			}
			else if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, NormalConfig))
			{
				UpdateAll();
			}
			else if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, UVConfig))
			{
				UpdateAll();
			}
			else if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, VoxelSize))
			{
				Recreate();
			}
		}
	}

	FixWorldBounds(WorldBounds, OctreeDepth);
}
#endif

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void AVoxelWorld::CreateWorldInternal(
	EPlayType InPlayType,
	UVoxelGrassSpawner* InGrassSpawner,
	UVoxelActorSpawner* InActorSpawner,
	bool bInMultiplayer,
	bool bInEnableUndoRedo,
	bool bInDontUseGlobalPool)
{
	SCOPE_CYCLE_COUNTER(STAT_VoxelWorld_CreateWorldInternal);

	check(!IsCreated());
	check(!Data.IsValid());
	check(!Render.IsValid());
	check(!Pool.IsValid());

	UE_LOG(LogVoxel, Warning, TEXT("Loading world"));
	
	// Create pool
	if (!bInDontUseGlobalPool)
	{
		if (FVoxelPool::IsGlobalVoxelPoolCreated())
		{
			Pool = FVoxelPool::GetGlobalPool();
		}
		else
		{
			FMessageLog("PIE").Error(LOCTEXT("GlobalPoolNotCreated", "DontUseGlobalPool = false but global pool isn't created!"));
		}
	}
	if (!Pool.IsValid())
	{
		Pool = FVoxelPool::Create(MeshThreadCount);
	}
	
	// Create Data
	{
		auto InstancedWorldGenerator = WorldGenerator.GetWorldGenerator();
		InstancedWorldGenerator->Init(GetInitStruct());

		FIntBox Bounds = FVoxelUtilities::GetBoundsFromDepth<CHUNK_SIZE>(OctreeDepth);
		if (bOverrideBounds)
		{
			Bounds = WorldBounds;
		}
		FixWorldBounds(Bounds, OctreeDepth);

		Data = MakeShared<FVoxelData, ESPMode::ThreadSafe>(
			OctreeDepth + DATA_OCTREE_DEPTH_DIFF,
			Bounds,
			InstancedWorldGenerator,
			bInMultiplayer,
			bInEnableUndoRedo);
	}
	// Create Render
	Render = FVoxelRenderFactory::GetVoxelRender(RenderType, this);

	// Create cache manager
	CacheManager = MakeShared<FVoxelCacheManager>(this);

	// Create actor octree
	ActorOctree = MakeShared<FVoxelActorOctreeManager>(this);
	ActorComputedChunksOctree = MakeShared<FVoxelActorComputedChunksOctree>(OctreeDepth);

	// Create deep copies of the configs
	GrassSpawnerThreadSafe = MakeShared<FVoxelGrassSpawner_ThreadSafe, ESPMode::ThreadSafe>(InGrassSpawner);
	ActorSpawnerThreadSafe = MakeShared<FVoxelActorSpawner_ThreadSafe, ESPMode::ThreadSafe>(InActorSpawner);
	
	PlayType = InPlayType;
	bIsCreated = true;
	InvokerComponentChangeVersion = -1;
	WorldOffset = FIntVector::ZeroValue;
	bWorldLoadAlreadyFinished = false;
	MaterialInstance = UMaterialInstanceDynamic::Create(MissingMaterial, this);
	bIsDedicatedServer = IsDedicatedServerInternal(GetWorld());

	// Load if possible
	if (SaveObject)
	{
		LoadFromCompressedSave(SaveObject->Save);
	}

	// Add placeable items AFTER LOADING and if not in editor
	if (PlayType != EPlayType::Editor)
	{
		for (TActorIterator<AVoxelPlaceableItemActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			(*ActorItr)->AddItemToWorld(this);
		}
	}

	// Start timers
	auto& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(CacheDebugHandle, [this]
	{
		if (bShowDataOctreeLeavesStatus)
		{
			CacheManager->DebugCache(bHideEmptyDataOctreeLeaves, 0.5f, DataOctreeLeavesThickness);
		}
	}, 0.5f, true);
}

void AVoxelWorld::DestroyWorldInternal()
{
	SCOPE_CYCLE_COUNTER(STAT_VoxelWorld_DestroyWorldInternal);

	check(IsCreated());
	check(Render.IsValid());
	check(Data.IsValid());
	check(Pool.IsValid());

	UE_LOG(LogVoxel, Warning, TEXT("Unloading world"));
	
	CacheManager.Reset();
	Render.Reset();
	Data.Reset();
	Pool.Reset();

	ActorOctree.Reset();
	ActorComputedChunksOctree.Reset();
	NetworkClient.Reset();
	NetworkServer.Reset();

	bIsCreated = false;
	PlayType = EPlayType::Destroyed;

	// Cancel timers
	auto& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.ClearTimer(CacheDebugHandle);
}

void AVoxelWorld::ReceiveData()
{
	SCOPE_CYCLE_COUNTER(STAT_VoxelWorld_ReceiveData);

	if (NetworkClient->IsValid())
	{
		NetworkClient->UpdateExpectedSize();
		if (NetworkClient->IsNextUpdateRemoteLoad())
		{
			FVoxelCompressedWorldSave Save;
			NetworkClient->ReceiveSave(Save);
			LoadFromCompressedSave(Save);
		}
		else
		{
			TArray<FIntBox> ModifiedBounds;
			TArray<TVoxelChunkDiff<FVoxelValue>> ValueDiffQueue;
			TArray<TVoxelChunkDiff<FVoxelMaterial>> MaterialDiffQueue;
			if (NetworkClient->ReceiveDiffQueues(ValueDiffQueue, MaterialDiffQueue))
			{
				Data->LoadFromDiffQueues(ValueDiffQueue, MaterialDiffQueue, ModifiedBounds);

				for (auto& Bounds : ModifiedBounds)
				{
					UpdateChunksOverlappingBox(Bounds, false);
					if (bDebugMultiplayer)
					{
						DrawDebugIntBox(Bounds, 1.1f / MultiplayerSyncRate, 10, FColor::Magenta);
					}
				}
			}
		}
	}
}

void AVoxelWorld::SendData()
{
	SCOPE_CYCLE_COUNTER(STAT_VoxelWorld_SendData);

	if (NetworkServer->IsValid())
	{
		TArray<TVoxelChunkDiff<FVoxelValue>> ValueDiffQueue;
		TArray<TVoxelChunkDiff<FVoxelMaterial>> MaterialDiffQueue;
		Data->GetDiffQueues(ValueDiffQueue, MaterialDiffQueue);

		NetworkServer->SendDiffQueue(ValueDiffQueue);
		NetworkServer->SendDiffQueue(MaterialDiffQueue);
	}
}

void AVoxelWorld::TriggerOnClientConnection()
{
	OnClientConnectionTrigger.Increment();
}
#undef LOCTEXT_NAMESPACE
