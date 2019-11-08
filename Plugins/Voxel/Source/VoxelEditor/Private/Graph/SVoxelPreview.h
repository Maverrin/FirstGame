// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Styling/SlateBrush.h"
#include "Widgets/SCompoundWidget.h"

class UTexture2D;

class SVoxelPreview : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS( SVoxelPreview ) {};
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	inline UTexture2D* GetTexture() const { return Texture; }
	void SetTexture(UTexture2D* Texture);

private:
	UTexture2D* Texture;
	FSlateBrush Brush;
};
