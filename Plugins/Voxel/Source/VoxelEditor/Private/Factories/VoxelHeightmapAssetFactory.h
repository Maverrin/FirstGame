// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Factories/Factory.h"
#include "VoxelAssets/VoxelHeightmapAsset.h"
#include "VoxelHeightmapAssetFactory.generated.h"

UCLASS()
class UVoxelHeightmapAssetFloatFactory : public UFactory
{
	GENERATED_BODY()

public:
	UVoxelHeightmapAssetFloatFactory()
	{
		bCreateNew = false;
		bEditAfterNew = true;
		SupportedClass = UVoxelHeightmapAssetFloat::StaticClass();
	}

	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override
	{
		auto NewAsset = NewObject<UVoxelHeightmapAssetFloat>(InParent, Class, Name, Flags);

		return NewAsset;
	}
	// End of UFactory interface
};

UCLASS()
class UVoxelHeightmapAssetUINT16Factory : public UFactory
{
	GENERATED_BODY()

public:
	UVoxelHeightmapAssetUINT16Factory()
	{
		bCreateNew = false;
		bEditAfterNew = true;
		SupportedClass = UVoxelHeightmapAssetUINT16::StaticClass();
	}

	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override
	{
		auto NewAsset = NewObject<UVoxelHeightmapAssetUINT16>(InParent, Class, Name, Flags);

		return NewAsset;
	}
	// End of UFactory interface
};
