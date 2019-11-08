// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Input/Reply.h"
#include "IDetailCustomization.h"
#include "Widgets/Input/SButton.h"
#include "PropertyHandle.h"

class UVoxelMaterialCollection;

class FVoxelMaterialCollectionDetails : public IDetailCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IDetailCustomization> MakeInstance();

	FVoxelMaterialCollectionDetails();

private:
	/** IDetailCustomization interface */
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;

	FReply OnGenerateSingleMaterials();
	FReply OnGenerateDoubleMaterials();
	FReply OnGenerateTripleMaterials();
	FReply OnApplyPhysicalMaterials();

private:
	TWeakObjectPtr<UVoxelMaterialCollection> Collection;
};

class FVoxelMaterialCollectionElementCustomization : public IPropertyTypeCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<class IPropertyTypeCustomization> MakeInstance()
	{
		return MakeShareable(new FVoxelMaterialCollectionElementCustomization());
	}

	// IPropertyTypeCustomization interface
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, class IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

private:
	TSharedPtr<IPropertyHandle> PropertyHandle;
	TSharedPtr<IPropertyHandle> IndexHandle;
	TSharedPtr<IPropertyHandle> MaterialHandle;
	TSharedPtr<IPropertyHandle> PhysicalMaterialHandle;
	TSharedPtr<IPropertyHandle> ChildrenHandle;
	
	EVisibility NoChildrenOnlyVisibility() const;
	float NoChildrenOnlyMaxHeight() const;
	void GenerateArrayElementWidget(TSharedRef<IPropertyHandle> PropertyHandle, int32 ArrayIndex, IDetailChildrenBuilder& ChildrenBuilder);
};