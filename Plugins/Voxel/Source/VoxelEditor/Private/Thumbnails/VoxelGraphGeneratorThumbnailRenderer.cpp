// Copyright 2018 Phyronnaz

#include "VoxelGraphGeneratorThumbnailRenderer.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "Engine/Texture2D.h"

bool UVoxelGraphGeneratorThumbnailRenderer::CanVisualizeAsset(UObject* Object)
{
	return Object->IsA(UVoxelGraphGenerator::StaticClass());
}

void UVoxelGraphGeneratorThumbnailRenderer::GetThumbnailSize(UObject* Object, float Zoom, uint32& OutWidth, uint32& OutHeight) const
{
	UTextureThumbnailRenderer::GetThumbnailSize(CastChecked<UVoxelGraphGenerator>(Object)->GetPreviewTexture(), Zoom, OutWidth, OutHeight);
}

void UVoxelGraphGeneratorThumbnailRenderer::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* Target, FCanvas* Canvas)
{
	UTextureThumbnailRenderer::Draw(CastChecked<UVoxelGraphGenerator>(Object)->GetPreviewTexture(), X, Y, Width, Height, Target, Canvas);
}
