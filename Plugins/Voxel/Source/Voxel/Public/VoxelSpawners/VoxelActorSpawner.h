// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "VoxelSpawners/VoxelActor.h"
#include "VoxelSpawners/VoxelDefaultSpawner.h"
#include "Logging/MessageLog.h"
#include "Components/StaticMeshComponent.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "VoxelActorSpawner.generated.h"

USTRUCT()
struct VOXEL_API FVoxelActorConfig : public FVoxelDefaultSpawner
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere, Category = "Config")
	bool bUseActorClass = true;


	UPROPERTY(EditAnywhere, Category = "Config", meta = (EditCondition = "bUseActorClass"))
	TSubclassOf<AVoxelActor> Actor = nullptr;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (EditCondition = "!bUseActorClass"))
	UStaticMesh* Mesh = nullptr;


	// If false more precise but way more expensive
	UPROPERTY(EditAnywhere, Category = "Actor Config", meta = (EditCondition = "bUseActorClass"))
	bool bOnlyCheckVoxelsAtPositionForOverlap = true;

	UPROPERTY(EditAnywhere, Category = "Actor Config", meta = (EditCondition = "bUseActorClass"))
	bool bSpawnActorAndNotImposterMesh = false;


	// If you want to edit the HISM properties create a BP inheriting from HierarchicalInstancedStaticMeshComponent and set it here
	UPROPERTY(EditAnywhere, Category = "Instance Config", meta = (DisplayName = "HISM Template"))
	TSubclassOf<UHierarchicalInstancedStaticMeshComponent> HISMTemplate = UHierarchicalInstancedStaticMeshComponent::StaticClass();

	UPROPERTY(EditAnywhere, Category = "Instance Config", meta = (DisplayName = "HISM Start Cull Distance"))
	int32 HISMStartCullDistance = 10000.f;

	UPROPERTY(EditAnywhere, Category = "Instance Config", meta = (DisplayName = "HISM End Cull Distance"))
	int32 HISMEndCullDistance = 20000.f;

	
	UPROPERTY(EditAnywhere, Category = "Config")
	FVector PositionOffset = FVector::ZeroVector;
	
	UPROPERTY(EditAnywhere, Category = "Config")
	FVector ScaleOffset = FVector::OneVector;
	
	UPROPERTY(EditAnywhere, Category = "Config")
	FRotator RotationOffset = FRotator::ZeroRotator;


	inline UStaticMesh* GetMesh() const
	{
		if (bUseActorClass)
		{
			if (Actor)
			{
				auto* MeshComponent = GetDefault<AVoxelActor>(Actor)->Mesh;
				if (MeshComponent)
				{
					auto* StaticMesh = MeshComponent->GetStaticMesh();
					if (!StaticMesh)
					{
						FMessageLog("PIE").Error(FText::FromString("VoxelActorConfig: Voxel Actor mesh component doesn't have a static mesh (in " + Actor->GetName() + ")"));
					}
					return StaticMesh;
				}
			}
			return nullptr;
		}
		else
		{
			return Mesh;
		}
	}

	inline FTransform GetTransform() const
	{
		return FTransform(RotationOffset, PositionOffset, ScaleOffset);
	}
};

UCLASS()
class VOXEL_API UVoxelActorGroup : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Config")
	TArray<FVoxelActorConfig> ActorConfigs;
};

USTRUCT()
struct FVoxelActorGroupId
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Config")
	uint8 ActorId;
	UPROPERTY(EditAnywhere, Category = "Config")
	UVoxelActorGroup* ActorGroup;

	FVoxelActorGroupId() = default;
	FVoxelActorGroupId(uint8 ActorId, UVoxelActorGroup* ActorGroup)
		: ActorId(ActorId)
		, ActorGroup(ActorGroup)
	{
	}
};

UCLASS()
class VOXEL_API UVoxelActorSpawner : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Config")
	TArray<FVoxelActorGroupId> ActorGroupIds;

	UPROPERTY()
	TMap<uint8, UVoxelActorGroup*> ActorGroups_DEPRECATED;

	virtual void PostLoad() override
	{
		Super::PostLoad();

		for (auto& It : ActorGroups_DEPRECATED)
		{
			ActorGroupIds.Emplace(It.Key, It.Value);
		}
	}

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override
	{
		Super::PostEditChangeProperty(PropertyChangedEvent);

		if (PropertyChangedEvent.ChangeType != EPropertyChangeType::Interactive)
		{
			TSet<uint8> ActorIds;
			for (auto& ActorGroup : ActorGroupIds)
			{
				while (ActorIds.Contains(ActorGroup.ActorId) && ActorGroup.ActorId < 255)
				{
					ActorGroup.ActorId++;
				}
				ActorIds.Add(ActorGroup.ActorId);
			}
		}
	}
#endif
};

struct FVoxelActorSpawner_ThreadSafe
{
	FVoxelActorSpawner_ThreadSafe() = default;
	FVoxelActorSpawner_ThreadSafe(UVoxelActorSpawner* Spawner)
	{
		if (Spawner)
		{
			for (const auto& ActorGroupId : Spawner->ActorGroupIds)
			{
				auto ActorId = ActorGroupId.ActorId;
				auto ActorGroup = ActorGroupId.ActorGroup;
				if (ActorGroup)
				{
					auto& ActorConfigs = ActorGroups.FindOrAdd(ActorId);
					for (auto& ActorConfig : ActorGroup->ActorConfigs)
					{
						if (ActorConfig.Actor || ActorConfig.Mesh)
						{
							ActorConfigs.Add(ActorConfig);
						}
						else
						{
							FMessageLog("PIE").Error(FText::FromString("VoxelActorConfig error: Mesh and Actor are both null (in " + ActorGroup->GetName() + ")"));
						}
					}
				}
			}
		}
	}
		
	TMap<uint8, TArray<FVoxelActorConfig>> ActorGroups;
};

