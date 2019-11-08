// Copyright 2018 Phyronnaz

#include "VoxelPortalNodeSelectorCustomization.h"

#include "Widgets/DeclarativeSyntaxSupport.h"
#include "PropertyHandle.h"
#include "IDetailChildrenBuilder.h"
#include "DetailLayoutBuilder.h"
#include "PropertyCustomizationHelpers.h"
#include "Components/ComboBox.h"

#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"
#include "VoxelGraph/VoxelPortalNode.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "IPropertyTypeCustomization.h"
#include "IPropertyUtilities.h"

#define LOCTEXT_NAMESPACE "VoxelPortalNodeSelectorCustomization"

void FVoxelPortalNodeSelectorCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> InPropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	PropertyHandle = InPropertyHandle;
	TargetHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FVoxelPortalNodeSelector, Input));
	
	UObject* SelectedNode;
	auto Result = TargetHandle->GetValue(SelectedNode);
	if (Result == FPropertyAccess::Fail || Result == FPropertyAccess::MultipleValues)
	{
		return;
	}
	if (!SelectedNode || !SelectedNode->IsA<UVoxelPortalNodeInput>())
	{
		return;
	}

	const TArray<TWeakObjectPtr<UObject>>& Objects = CustomizationUtils.GetPropertyUtilities()->GetSelectedObjects();

	PortalNodePtrs.Empty();
	for (auto& Node : Objects)
	{
		auto* PortalNode = Cast<UVoxelPortalNodeOutput>(Node.Get());
		if (PortalNode)
		{
			PortalNodePtrs.Emplace(PortalNode);
		}
	}
	if (PortalNodePtrs.Num() == 0) { return; }

	auto* Graph = PortalNodePtrs[0].Get()->Graph;
	if (!Graph) { return; }

	NodesArray.Empty();
	int SelectedNodeIndex = -1;
	auto Nodes = Graph->AllNodes.FilterByPredicate([&](auto& Node) { return Node->IsA(UVoxelPortalNodeInput::StaticClass()); });
	for (int NodeIndex = 0; NodeIndex < Nodes.Num(); NodeIndex++)
	{
		auto& Node = Nodes[NodeIndex];
		NodesArray.Add(MakeShared<TWeakObjectPtr<UVoxelPortalNodeInput>>(TWeakObjectPtr<UVoxelPortalNodeInput>(CastChecked<UVoxelPortalNodeInput>(Node))));
		if (Node == SelectedNode)
		{
			SelectedNodeIndex = NodeIndex;
		}
	}

	HeaderRow
	.NameContent()
	[
		PropertyHandle->CreatePropertyNameWidget()
	]
	.ValueContent()
	.HAlign(HAlign_Fill)
	.MaxDesiredWidth(TOptional<float>())
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		[
			SNew(SComboBox<TSharedPtr<TWeakObjectPtr<UVoxelPortalNodeInput>>>)
			.IsEnabled(!PropertyHandle->IsEditConst())
			.OptionsSource(&NodesArray)
			.ContentPadding(0)
			.OnSelectionChanged_Lambda([&](TSharedPtr<TWeakObjectPtr<UVoxelPortalNodeInput>> ValuePtr, ESelectInfo::Type)
			{
				if (ValuePtr->IsValid())
				{
					{
						// Remove existing ref
						UObject* CurrentValue;
						TargetHandle->GetValue(CurrentValue);
						UVoxelPortalNodeInput* CurrentInput = Cast<UVoxelPortalNodeInput>(CurrentValue);
						if (CurrentInput)
						{
							for (auto& PortalNodePtr : PortalNodePtrs)
							{
								CurrentInput->OutputNodes.Remove(PortalNodePtr);
							}
						}
					}
					{
						// Set value & text and add ref
						UVoxelPortalNodeInput* Value = ValuePtr->Get();
						check(Value);
						TargetHandle->SetValue(Value);
						Value->OutputNodes.Append(PortalNodePtrs);
						for (auto& PortalNodePtr : PortalNodePtrs)
						{
							if (PortalNodePtr.IsValid())
							{
								PortalNodePtr.Get()->RecreateNodeAndBreakAllLinks();
							}
						}

						CurrentText->SetText(FText::FromString(Value->Name));
					}
				}
				else
				{
					CurrentText->SetText(FText());
				}
			})
			.OnGenerateWidget_Lambda([&](TSharedPtr<TWeakObjectPtr<UVoxelPortalNodeInput>> Value)
			{
				return SNew(STextBlock)
			    		.Font(IDetailLayoutBuilder::GetDetailFont())
						.Text(FText::FromString(Value.IsValid() && Value->IsValid() ? Value->Get()->Name : ""));
			})
			.InitiallySelectedItem(NodesArray.IsValidIndex(SelectedNodeIndex)? NodesArray[SelectedNodeIndex] : TSharedPtr<TWeakObjectPtr<UVoxelPortalNodeInput>>())
			[
				SAssignNew(CurrentText, STextBlock)
				.Font(IDetailLayoutBuilder::GetDetailFont())
				.Text(FText::FromString(SelectedNode ? CastChecked<UVoxelPortalNodeInput>(SelectedNode)->Name : ""))
			]
		]
	];
}

void FVoxelPortalNodeSelectorCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> InPropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
}

#undef LOCTEXT_NAMESPACE
