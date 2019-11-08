// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "ThumbnailRendering/ThumbnailRenderer.h"
#include "ThumbnailRendering/TextureThumbnailRenderer.h"
#include "VoxelGraphGeneratorThumbnailRenderer.generated.h"

class FCanvas;
class FRenderTarget;

UCLASS(MinimalAPI)
class UVoxelGraphGeneratorThumbnailRenderer : public UTextureThumbnailRenderer
{
	GENERATED_BODY()
public:

	// Begin UThumbnailRenderer Object
	VOXELEDITOR_API virtual bool CanVisualizeAsset(UObject* Object) override;
	VOXELEDITOR_API virtual void GetThumbnailSize(UObject* Object, float Zoom, uint32& OutWidth, uint32& OutHeight) const override;
	VOXELEDITOR_API virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* Target, FCanvas* Canvas) override;
	// End UThumbnailRenderer Object
};
