// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelSpawners/VoxelDefaultSpawner.h"
#include "Engine/EngineTypes.h"
#include "VoxelGrassSpawner.generated.h"

USTRUCT()
struct VOXEL_API FVoxelGrassVariety : public FVoxelDefaultSpawner
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Grass Config")
	UStaticMesh* GrassMesh = nullptr;

	/** The distance where instances will begin to fade out if using a PerInstanceFadeAmount material node. 0 disables. */
	UPROPERTY(EditAnywhere, Category = "Grass Config", meta = (UIMin = 0, ClampMin = 0, UIMax = 1000000, ClampMax = 1000000))
	int32 StartCullDistance = 10000.f;

	/**
	 * The distance where instances will have completely faded out when using a PerInstanceFadeAmount material node. 0 disables.
	 * When the entire cluster is beyond this distance, the cluster is completely culled and not rendered at all.
	 */
	UPROPERTY(EditAnywhere, Category = "Grass Config", meta = (UIMin = 0, ClampMin = 0, UIMax = 1000000, ClampMax = 1000000))
	int32 EndCullDistance = 10000.f;

	/**
	 * Specifies the smallest LOD that will be used for this component.
	 * If -1 (default), the MinLOD of the static mesh asset will be used instead.
	 */
	UPROPERTY(EditAnywhere, Category = "Grass Config", meta = (UIMin = -1, ClampMin = -1, UIMax = 8, ClampMax = 8))
	int32 MinLOD = -1;
	
	/**
	 * Lighting channels that the grass will be assigned. Lights with matching channels will affect the grass.
	 * These channels only apply to opaque materials, direct lighting, and dynamic lighting and shadowing.
	 */
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category = "Grass Config")
	FLightingChannels LightingChannels;

	/** Whether the grass instances should receive decals. */
	UPROPERTY(EditAnywhere, Category = "Grass Config")
	bool bReceivesDecals = true;

	/** Whether the grass should cast shadows when using non-precomputed shadowing. **/
	UPROPERTY(EditAnywhere, Category = "Grass Config")
	bool bCastDynamicShadow = true;
};

UCLASS()
class VOXEL_API UVoxelGrassGroup : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Config")
	TArray<FVoxelGrassVariety> GrassVarieties;
};

USTRUCT()
struct FVoxelGrassTypeId
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Config")
	uint8 GrassId;
	UPROPERTY(EditAnywhere, Category = "Config")
	UVoxelGrassGroup* GrassGroup;

	FVoxelGrassTypeId() = default;
	FVoxelGrassTypeId(uint8 GrassId, UVoxelGrassGroup* GrassGroup)
		: GrassId(GrassId)
		, GrassGroup(GrassGroup)
	{
	}
};

UCLASS()
class VOXEL_API UVoxelGrassSpawner : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Config")
	TArray<FVoxelGrassTypeId> GrassTypeIds;

	UPROPERTY()
	TMap<uint8, UVoxelGrassGroup*> GrassTypes_DEPRECATED;

	virtual void PostLoad() override
	{
		Super::PostLoad();

		for (auto& It : GrassTypes_DEPRECATED)
		{
			GrassTypeIds.Emplace(It.Key, It.Value);
		}
	}

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override
	{
		Super::PostEditChangeProperty(PropertyChangedEvent);

		if (PropertyChangedEvent.ChangeType != EPropertyChangeType::Interactive)
		{
			TSet<uint8> GrassIds;
			for (auto& GrassType : GrassTypeIds)
			{
				while (GrassIds.Contains(GrassType.GrassId) && GrassType.GrassId < 255)
				{
					GrassType.GrassId++;
				}
				GrassIds.Add(GrassType.GrassId);
			}
		}
	}
#endif
};

struct FVoxelGrassSpawner_ThreadSafe
{
	FVoxelGrassSpawner_ThreadSafe() = default;
	FVoxelGrassSpawner_ThreadSafe(UVoxelGrassSpawner* Spawner)
	{
		if (Spawner)
		{
			for (const auto& GrassType : Spawner->GrassTypeIds)
			{
				auto GrassId = GrassType.GrassId;
				auto GrassGroup = GrassType.GrassGroup;
				if (GrassGroup)
				{
					auto& GrassVarieties = GrassTypes.FindOrAdd(GrassId);
					for (auto& GrassVariety : GrassGroup->GrassVarieties)
					{
						if (GrassVariety.GrassMesh)
						{
							GrassVarieties.Add(GrassVariety);
						}
					}
				}
			}
		}
	}
	
	TMap<uint8, TArray<FVoxelGrassVariety>> GrassTypes;
};

