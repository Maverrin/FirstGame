// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"

struct FAssetData;
class IPropertyHandle;

class FVoxelPortalNodeSelectorCustomization : public IPropertyTypeCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<class IPropertyTypeCustomization> MakeInstance()
	{
		return MakeShareable(new FVoxelPortalNodeSelectorCustomization());
	}

	// IPropertyTypeCustomization interface
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, class IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

private:
	TSharedPtr<IPropertyHandle> PropertyHandle;
	TSharedPtr<IPropertyHandle> TargetHandle;
	TArray<TSharedPtr<TWeakObjectPtr<class UVoxelPortalNodeInput>>> NodesArray;
	TSharedPtr<class STextBlock> CurrentText;
	TArray<TWeakObjectPtr<class UVoxelPortalNodeOutput>> PortalNodePtrs;
};
