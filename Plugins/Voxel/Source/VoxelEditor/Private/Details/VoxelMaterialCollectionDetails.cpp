// Copyright 2018 Phyronnaz

#include "VoxelMaterialCollectionDetails.h"
#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"

#include "VoxelEditorDetailsUtils.h"

#include "VoxelMaterialCollection.h"
#include "Materials/Material.h"
#include "Materials/MaterialExpression.h"
#include "ObjectTools.h"
#include "VoxelMaterialCollectionHelpers.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SSpacer.h"
#include "Widgets/Input/SButton.h"
#include "IDetailChildrenBuilder.h"
#include "PropertyCustomizationHelpers.h"

#define LOCTEXT_NAMESPACE "VoxelMaterialCollectionDetails"

TSharedRef<IDetailCustomization> FVoxelMaterialCollectionDetails::MakeInstance()
{
	return MakeShareable(new FVoxelMaterialCollectionDetails());
}

FVoxelMaterialCollectionDetails::FVoxelMaterialCollectionDetails()
{

}

void FVoxelMaterialCollectionDetails::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	Collection = FVoxelEditorDetailsUtils::GetCurrentObjectFromDetails<UVoxelMaterialCollection>(DetailLayout);

	ADD_BUTTON_TO_CATEGORY(DetailLayout,
		"Generate",
		LOCTEXT("GenerateSingle", "Generate Single"),
		LOCTEXT("GenerateSingleMaterials", "Generate Single Materials"),
		LOCTEXT("GenerateSingle", "Generate Single"),
		this,
		&FVoxelMaterialCollectionDetails::OnGenerateSingleMaterials)

	ADD_BUTTON_TO_CATEGORY(DetailLayout,
		"Generate",
		LOCTEXT("GenerateDouble", "Generate Double"),
		LOCTEXT("GenerateDoubleMaterials", "Generate Double Materials"),
		LOCTEXT("GenerateDouble", "Generate Double"),
		this,
		&FVoxelMaterialCollectionDetails::OnGenerateDoubleMaterials)

	ADD_BUTTON_TO_CATEGORY(DetailLayout,
		"Generate",
		LOCTEXT("GenerateTriple", "Generate Triple"),
		LOCTEXT("GenerateTripleMaterials", "Generate Triple Materials"),
		LOCTEXT("GenerateTriple", "Generate Triple"),
		this,
		&FVoxelMaterialCollectionDetails::OnGenerateTripleMaterials)
}


FReply FVoxelMaterialCollectionDetails::OnGenerateSingleMaterials()
{
	FString Error;
	if (FVoxelMaterialCollectionHelpers::GenerateSingleMaterials(Collection.Get(), Error))
	{
		FNotificationInfo Info(LOCTEXT("Success", "Success"));
		Info.ExpireDuration = 5.f;
		FSlateNotificationManager::Get().AddNotification(Info);
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(Error));
		return FReply::Handled();
	}

	return FReply::Handled();
}


FReply FVoxelMaterialCollectionDetails::OnGenerateDoubleMaterials()
{
	FString Error;
	if (FVoxelMaterialCollectionHelpers::GenerateDoubleMaterials(Collection.Get(), Error))
	{
		FNotificationInfo Info(LOCTEXT("Success", "Success"));
		Info.ExpireDuration = 5.f;
		FSlateNotificationManager::Get().AddNotification(Info);
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(Error));
		return FReply::Handled();
	}

	return FReply::Handled();
}

FReply FVoxelMaterialCollectionDetails::OnGenerateTripleMaterials()
{
	auto ThisWillTakeAWhileValue = FMessageDialog::Open(EAppMsgType::YesNoCancel, LOCTEXT("ThisWillTakeAWhile", "This will take a while! Triple materials are only needed when 3 different materials are on a same triangle, which is really rare. You don't need them to test your materials. Do you want to continue?"));

    switch(ThisWillTakeAWhileValue)
    {
    case EAppReturnType::Yes:
        break;
    case EAppReturnType::No:
    case EAppReturnType::Cancel:
        return FReply::Handled();
    }
	
	FString Error;
	if (FVoxelMaterialCollectionHelpers::GenerateTripleMaterials(Collection.Get(), Error))
	{
		FNotificationInfo Info(LOCTEXT("Success", "Success"));
		Info.ExpireDuration = 5.f;
		FSlateNotificationManager::Get().AddNotification(Info);
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(Error));
		return FReply::Handled();
	}

	return FReply::Handled();
}

void FVoxelMaterialCollectionElementCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> InPropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	PropertyHandle = InPropertyHandle;
	IndexHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FVoxelMaterialCollectionElement, Index));
	MaterialHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FVoxelMaterialCollectionElement, MaterialFunction));
	PhysicalMaterialHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FVoxelMaterialCollectionElement, PhysicalMaterial));
	ChildrenHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FVoxelMaterialCollectionElement, Children));
		   
	auto IndexWidget = IndexHandle->CreatePropertyValueWidget();
	IndexWidget->SetVisibility(TAttribute<EVisibility>(this, &FVoxelMaterialCollectionElementCustomization::NoChildrenOnlyVisibility));
	
	auto PhysicalMaterialWidget = PhysicalMaterialHandle->CreatePropertyValueWidget();
	PhysicalMaterialWidget->SetVisibility(TAttribute<EVisibility>(this, &FVoxelMaterialCollectionElementCustomization::NoChildrenOnlyVisibility));
		
	HeaderRow
	.NameContent()
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			IndexWidget
		]
		+ SHorizontalBox::Slot()
		.FillWidth(1)
		[
			SNew(SSpacer)
		]
	]
	.ValueContent()
	.HAlign(HAlign_Fill)
	.MaxDesiredWidth(TOptional<float>())
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				MaterialHandle->CreatePropertyValueWidget()
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1)
			[
				SNew(SSpacer)
			]
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.MaxHeight(TAttribute<float>(this, &FVoxelMaterialCollectionElementCustomization::NoChildrenOnlyMaxHeight))
		[
			SNew(SHorizontalBox)
			.Visibility_Raw(this, &FVoxelMaterialCollectionElementCustomization::NoChildrenOnlyVisibility)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				PhysicalMaterialWidget
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1)
			[
				SNew(SSpacer)
			]
		]
	];
}

void FVoxelMaterialCollectionElementCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> InPropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	ChildrenHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FVoxelMaterialCollectionElement, Children));

	TSharedRef<FDetailArrayBuilder> NodeArrayBuilder = MakeShareable(new FDetailArrayBuilder(ChildrenHandle.ToSharedRef()));
	NodeArrayBuilder->OnGenerateArrayElementWidget(FOnGenerateArrayElementWidget::CreateSP(this, &FVoxelMaterialCollectionElementCustomization::GenerateArrayElementWidget));
	ChildBuilder.AddCustomBuilder(NodeArrayBuilder);
}

EVisibility FVoxelMaterialCollectionElementCustomization::NoChildrenOnlyVisibility() const
{
	uint32 Num;
	ChildrenHandle->AsArray()->GetNumElements(Num);
	return Num == 0 ? EVisibility::Visible : EVisibility::Hidden;
}

float FVoxelMaterialCollectionElementCustomization::NoChildrenOnlyMaxHeight() const
{
	uint32 Num;
	ChildrenHandle->AsArray()->GetNumElements(Num);
	return Num == 0 ? 1000 : 1;
}

void FVoxelMaterialCollectionElementCustomization::GenerateArrayElementWidget(TSharedRef<IPropertyHandle> ChildHandle, int32 ArrayIndex, IDetailChildrenBuilder& ChildrenBuilder)
{
	auto ChildIndexHandle = ChildHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FVoxelMaterialCollectionElementIndex, InstanceIndex));
	auto ChildInstanceHandle = ChildHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FVoxelMaterialCollectionElementIndex, MaterialInstance));
	auto ChildPhysicalMaterialHandle = ChildHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FVoxelMaterialCollectionElementIndex, PhysicalMaterial));

	ChildrenBuilder.AddCustomRow(FText())
	.NameContent()
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			ChildIndexHandle->CreatePropertyValueWidget()
		]
		+ SHorizontalBox::Slot()
		.FillWidth(1)
		[
			SNew(SSpacer)
		]
	]
	.ValueContent()
	.HAlign(HAlign_Fill)
	.MaxDesiredWidth(TOptional<float>())
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				ChildInstanceHandle->CreatePropertyValueWidget()
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1)
			[
				SNew(SSpacer)
			]
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				ChildPhysicalMaterialHandle->CreatePropertyValueWidget()
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1)
			[
				SNew(SSpacer)
			]
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SButton)
				.OnClicked_Lambda([=]() { ChildrenHandle->AsArray()->Insert(ArrayIndex); return FReply::Handled(); })
				.Content()
				[
					SNew(STextBlock)
					.Text(LOCTEXT("InsertItem", "Insert"))
				]
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SButton)
				.OnClicked_Lambda([=]() { ChildrenHandle->AsArray()->DeleteItem(ArrayIndex); return FReply::Handled(); })
				.Content()
				[
					SNew(STextBlock)
					.Text(LOCTEXT("DeleteItem", "Delete"))
				]
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SButton)
				.OnClicked_Lambda([=]() { ChildrenHandle->AsArray()->DuplicateItem(ArrayIndex); return FReply::Handled(); })
				.Content()
				[
					SNew(STextBlock)
					.Text(LOCTEXT("DuplicateItem", "Duplicate"))
				]
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1)
			[
				SNew(SSpacer)
			]
		]
	];
}

#undef LOCTEXT_NAMESPACE
