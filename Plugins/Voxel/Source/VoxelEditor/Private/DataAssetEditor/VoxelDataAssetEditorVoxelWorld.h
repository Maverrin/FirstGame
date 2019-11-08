// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelWorld.h"
#include "VoxelMaterialCollection.h"
#include "Engine/StreamableManager.h"
#include "UnrealEdMisc.h"
#include "VoxelDataAssetEditorVoxelWorld.generated.h"

UCLASS(Config = EditorPerProjectUserSettings)
class UVoxelDataAssetEditorVoxelWorldSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	float VoxelSize = 100;

	UPROPERTY(Config)
	EVoxelRenderType RenderType = EVoxelRenderType::MarchingCubes;

	UPROPERTY(Config)
	EVoxelNormalConfig NormalConfig = EVoxelNormalConfig::GradientNormal;

	UPROPERTY(Config)
	EVoxelMaterialConfig MaterialConfig = EVoxelMaterialConfig::IndexWithMultipleMaterials;

	UPROPERTY(Config)
	FString VoxelMaterialPath;

	UPROPERTY(Config)
	FString MaterialCollectionPath;
	
	//~ Begin UObject Interface
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override
	{
		Super::PostEditChangeProperty(PropertyChangedEvent);

		if (!FUnrealEdMisc::Get().IsDeletePreferences())
		{
			SaveConfig();
		}
	}
#endif
};

UCLASS(hidedropdown, notplaceable, NotBlueprintType, NotBlueprintable)
class AVoxelDataAssetEditorVoxelWorld : public AVoxelWorld
{
	GENERATED_BODY()

public:
	void SaveToDefaults() const
	{
		UVoxelDataAssetEditorVoxelWorldSettings* MutableDefault = GetMutableDefault<UVoxelDataAssetEditorVoxelWorldSettings>();
		MutableDefault->VoxelSize = VoxelSize;
		MutableDefault->RenderType = RenderType;
		MutableDefault->NormalConfig = NormalConfig;
		MutableDefault->MaterialConfig = MaterialConfig;
		MutableDefault->VoxelMaterialPath = VoxelMaterial ? VoxelMaterial->GetPathName() : TEXT("");
		MutableDefault->MaterialCollectionPath = MaterialCollection ? MaterialCollection->GetPathName() : TEXT("");
		MutableDefault->PostEditChange();
	}

	void LoadFromDefaults()
	{
		const UVoxelDataAssetEditorVoxelWorldSettings* Default = GetDefault<UVoxelDataAssetEditorVoxelWorldSettings>();
		VoxelSize = Default->VoxelSize;
		RenderType = Default->RenderType;
		NormalConfig = Default->NormalConfig;
		MaterialConfig = Default->MaterialConfig;

		FStreamableManager AssetLoader;
		FStringAssetReference VoxelMaterialRef(Default->VoxelMaterialPath);
		FStringAssetReference MaterialCollectionRef(Default->MaterialCollectionPath);
		VoxelMaterial = AssetLoader.LoadSynchronous<UMaterialInterface>(VoxelMaterialRef);
		MaterialCollection = AssetLoader.LoadSynchronous<UVoxelMaterialCollection>(MaterialCollectionRef);
	}
};
