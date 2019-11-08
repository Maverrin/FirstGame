// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Logging/MessageLog.h"
#include "VoxelPlaceableItemActor.generated.h"

class AVoxelWorld;

UCLASS(HideCategories = ("Tick", "Replication", "Input", "Actor", "Rendering", "HOLD", "LOD", "Cooking"))
class VOXEL_API AVoxelPlaceableItemActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Config")
	AVoxelWorld* World;

	virtual void AddItemToWorld(AVoxelWorld* InWorld) const
	{
		if (!World)
		{
			FMessageLog("PIE").Error(FText::FromString("Invalid world on " + GetName()));
		}
	}
};
