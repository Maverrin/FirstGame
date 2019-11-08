// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Layout/Visibility.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Input/Reply.h"
#include "SGraphNode.h"

class SVerticalBox;
class UVoxelGraphNode;

class SVoxelGraphNode : public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(SVoxelGraphNode){}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, class UVoxelGraphNode_Base* InNode);
	
	/** Called when GraphNode changes its error information, may be called when no change has actually occurred: */
	void RefreshErrorInfo();

protected:
	//~ Begin SGraphNode Interface
	virtual void UpdateGraphNode() override;
	virtual void CreateOutputSideAddButton(TSharedPtr<SVerticalBox> OutputBox) override;
	virtual EVisibility IsAddPinButtonVisible() const override;
	virtual FReply OnAddPin() override;
	virtual TSharedRef<SWidget> CreateTitleWidget(TSharedPtr<SNodeTitle> NodeTitle) override;
	//~ End SGraphNode Interface

private:
	/** Set up node in 'standard' mode */
	void UpdateStandardNode();
	/** Set up node in 'compact' mode */
	void UpdateCompactNode();
	/** Get title in compact mode */
	FText GetNodeCompactTitle() const;
	/** @return the tint for the node's main body */
	FSlateColor GetNodeBodyColor() const;
	/** Set-up the error reporting widget for the node */
	void SetupErrorReporting();
	/** Called to set error text on the node */
	void UpdateErrorInfo();
	/* Called when text is committed on the node */
	void OnNameTextCommited ( const FText& InText, ETextCommit::Type CommitInfo ) ;

	UVoxelGraphNode_Base* VoxelNode;
};
