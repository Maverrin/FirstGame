// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Input/Reply.h"
#include "IDetailCustomization.h"
#include "Widgets/Input/SButton.h"

class AVoxelAssetActor;;

class FVoxelAssetActorDetails : public IDetailCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IDetailCustomization> MakeInstance();

	FVoxelAssetActorDetails();

private:
	/** IDetailCustomization interface */
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;

	FReply OnUpdate();
	bool IsEnabled() const;

private:
	TWeakObjectPtr<AVoxelAssetActor> AssetActor;
};
