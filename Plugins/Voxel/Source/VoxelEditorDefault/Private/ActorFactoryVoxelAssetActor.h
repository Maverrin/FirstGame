// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Factories/Factory.h"
#include "ActorFactories/ActorFactory.h"
#include "ActorFactoryVoxelAssetActor.generated.h"

class AActor;
struct FAssetData;

UCLASS()
class UActorFactoryVoxelAssetActor : public UActorFactory
{
	GENERATED_BODY()

public:
	UActorFactoryVoxelAssetActor();

	//~ Begin UActorFactory Interface
	virtual void PostSpawnActor( UObject* Asset, AActor* NewActor ) override;
	virtual void PostCreateBlueprint( UObject* Asset, AActor* CDO ) override;
	virtual bool CanCreateActorFrom( const FAssetData& AssetData, FText& OutErrorMsg ) override;
	virtual UObject* GetAssetFromActorInstance(AActor* ActorInstance) override;
	//~ End UActorFactory Interface
};
