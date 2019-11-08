// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "ActorFactories/ActorFactory.h"
#include "VoxelPlaceableItemActorFactory.generated.h"

UCLASS()
class UVoxelPlaceableItemActorFactory : public UActorFactory
{
	GENERATED_BODY()

public:
	UVoxelPlaceableItemActorFactory();

	//~ Begin UActorFactory Interface
	void PostSpawnActor(UObject* Asset, AActor* NewActor) override;
	//~ End UActorFactory Interface
};

UCLASS()
class UVoxelExclusionBoxFactory : public UVoxelPlaceableItemActorFactory
{
	GENERATED_BODY()

public:
	UVoxelExclusionBoxFactory();
};

UCLASS()
class UVoxelAssetActorFactory : public UVoxelPlaceableItemActorFactory
{
	GENERATED_BODY()

public:
	UVoxelAssetActorFactory();
};
