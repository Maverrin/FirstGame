// Copyright 2018 Phyronnaz

#include "VoxelGraphSchema.h"
#include "ScopedTransaction.h"
#include "Internationalization/Internationalization.h"
#include "EdGraphNode_Comment.h"
#include "VoxelGraphEditorUtilities.h"
#include "Layout/SlateRect.h"

#include "VoxelGraph/VoxelNoiseNodes.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "VoxelGraph.h"
#include "VoxelGraphNode_Root.h"
#include "GraphEditorSettings.h"
#include "VoxelGraphNode_Knot.h"
#include "UObject/UObjectIterator.h"
#include "Runtime/Launch/Resources/Version.h"
#include "VoxelGraph/VoxelGraphMacro.h"
#include "VoxelGraphNode.h"
#include "AssetRegistryModule.h"
#include "Engine/StreamableManager.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "GraphEditorActions.h"
#include "Framework/Commands/UIAction.h"
#include "VoxelGraph/VoxelDefaultNodes.h"
#include "VoxelGraph/VoxelPortalNode.h"

#define LOCTEXT_NAMESPACE "VoxelGraphSchema"

UEdGraphNode* FVoxelGraphSchemaAction_NewNode::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode/* = true*/)
{
	check(VoxelNodeClass);

	UVoxelGraph* VoxelGraph = CastChecked<UVoxelGraph>(ParentGraph);

	UVoxelGraphGenerator* WorldGenerator = VoxelGraph->GetWorldGenerator();
	const FScopedTransaction Transaction(LOCTEXT("VoxelEditorNewNode", "Voxel Editor: New Node"));
	ParentGraph->Modify();
	WorldGenerator->Modify();

	UVoxelNode* NewNode = WorldGenerator->ConstructNewNode(VoxelNodeClass);

	NewNode->CreateStartingConnectors();

	NewNode->GraphNode->NodePosX = Location.X;
	NewNode->GraphNode->NodePosY = Location.Y;

	NewNode->GraphNode->AutowireNewNode(FromPin);

	WorldGenerator->PostEditChange();
	WorldGenerator->MarkPackageDirty();

	// Needed for eg PortalNodeInput, where it's always linked
	WorldGenerator->CompileVoxelNodesFromGraphNodes();

	return NewNode->GraphNode;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

UEdGraphNode* FVoxelGraphSchemaAction_NewMacroNode::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode /*= true*/)
{
	check(Macro);

	UVoxelGraph* VoxelGraph = CastChecked<UVoxelGraph>(ParentGraph);

	UVoxelGraphGenerator* WorldGenerator = VoxelGraph->GetWorldGenerator();
	const FScopedTransaction Transaction(LOCTEXT("VoxelEditorNewNode", "Voxel Editor: New Node"));
	ParentGraph->Modify();
	WorldGenerator->Modify();

	UVoxelGraphMacroNode* NewNode = CastChecked<UVoxelGraphMacroNode>(WorldGenerator->ConstructNewNode(UVoxelGraphMacroNode::StaticClass()));

	NewNode->Macro = Macro;

	NewNode->CreateStartingConnectors();

	NewNode->GraphNode->NodePosX = Location.X;
	NewNode->GraphNode->NodePosY = Location.Y;
	
	NewNode->GraphNode->ReconstructNode();

	NewNode->GraphNode->AutowireNewNode(FromPin);

	WorldGenerator->PostEditChange();
	WorldGenerator->MarkPackageDirty();

	WorldGenerator->CompileVoxelNodesFromGraphNodes();

	return NewNode->GraphNode;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

UEdGraphNode* FVoxelGraphSchemaAction_NewPortalNode::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode /*= true*/)
{
	check(InputNode);

	UVoxelGraph* VoxelGraph = CastChecked<UVoxelGraph>(ParentGraph);

	UVoxelGraphGenerator* WorldGenerator = VoxelGraph->GetWorldGenerator();
	const FScopedTransaction Transaction(LOCTEXT("VoxelEditorNewNode", "Voxel Editor: New Node"));
	ParentGraph->Modify();
	WorldGenerator->Modify();

	UVoxelPortalNodeOutput* NewNode = CastChecked<UVoxelPortalNodeOutput>(WorldGenerator->ConstructNewNode(UVoxelPortalNodeOutput::StaticClass()));
	NewNode->Selector.Input = InputNode;
	InputNode->OutputNodes.Add(NewNode);

	NewNode->GraphNode->ReconstructNode();

	NewNode->CreateStartingConnectors();

	NewNode->GraphNode->NodePosX = Location.X;
	NewNode->GraphNode->NodePosY = Location.Y;

	NewNode->GraphNode->AutowireNewNode(FromPin);

	WorldGenerator->PostEditChange();
	WorldGenerator->MarkPackageDirty();

	WorldGenerator->CompileVoxelNodesFromGraphNodes();

	return NewNode->GraphNode;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

UEdGraphNode* FVoxelGraphSchemaAction_NewKnotNode::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode /*= true*/)
{
	const FScopedTransaction Transaction(LOCTEXT("VoxelEditorNewKnotNode", "Voxel Editor: New Knot Node"));
	ParentGraph->Modify();

	FGraphNodeCreator<UVoxelGraphNode_Knot> KnotNodeCreator(*ParentGraph);
	UVoxelGraphNode_Knot* KnotNode = KnotNodeCreator.CreateNode();
	KnotNodeCreator.Finalize();
	//SetNodeMetaData(KnotNode, FNodeMetadata::DefaultGraphNode);

	KnotNode->NodePosX = Location.X;
	KnotNode->NodePosY = Location.Y;
	
	KnotNode->AutowireNewNode(FromPin);

	KnotNode->PropagatePinType();

	return KnotNode;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

UEdGraphNode* FVoxelGraphSchemaAction_NewComment::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode /*= true*/)
{
	// Add menu item for creating comment boxes
	UEdGraphNode_Comment* CommentTemplate = NewObject<UEdGraphNode_Comment>();

	FVector2D SpawnLocation = Location;

	FSlateRect Bounds;
	if (FVoxelGraphEditorUtilities::GetBoundsForSelectedNodes(ParentGraph, Bounds, 50.0f))
	{
		CommentTemplate->SetBounds(Bounds);
		SpawnLocation.X = CommentTemplate->NodePosX;
		SpawnLocation.Y = CommentTemplate->NodePosY;
	}

	return FEdGraphSchemaAction_NewNode::SpawnNodeFromTemplate<UEdGraphNode_Comment>(ParentGraph, CommentTemplate, SpawnLocation);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

UEdGraphNode* FVoxelGraphSchemaAction_Paste::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode /*= true*/)
{
	FVoxelGraphEditorUtilities::PasteNodesHere(ParentGraph, Location);
	return NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

UVoxelGraphSchema::UVoxelGraphSchema(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UVoxelGraphSchema::ConnectionCausesLoop(const UEdGraphPin* InputPin, const UEdGraphPin* OutputPin) const
{
	UEdGraphNode* const StartNode = OutputPin->GetOwningNode();

	TSet<UEdGraphNode*> ProcessedNodes;

	TArray<UEdGraphNode*> NodesToProcess;
	NodesToProcess.Add(InputPin->GetOwningNode());
	
	while (NodesToProcess.Num() > 0)
	{
		UEdGraphNode* Node = NodesToProcess.Pop(false);

		ProcessedNodes.Add(Node);

		if (auto* PortalInputGraphNode = Cast<UVoxelGraphNode>(Node))
		{
			if (auto* PortalInput = Cast<UVoxelPortalNodeInput>(PortalInputGraphNode->VoxelNode))
			{
				for (auto& PortalOutput : PortalInput->OutputNodes)
				{
					if (PortalOutput.IsValid())
					{
						if (StartNode == PortalOutput->GraphNode)
						{
							return true;
						}
						NodesToProcess.Add(PortalOutput->GraphNode);
					}
				}
			}
		}

		for (UEdGraphPin* Pin : Node->GetAllPins())
		{
			if (Pin->Direction == EGPD_Output)
			{
				for (auto& LPin : Pin->LinkedTo)
				{
					check(LPin->Direction == EGPD_Input);

					UEdGraphNode* NewNode = LPin->GetOwningNode();
					check(NewNode);

					if (StartNode == NewNode)
					{
						return true;
					}
					NodesToProcess.Add(NewNode);
				}
			}
		}
	}

	return false;
}

void UVoxelGraphSchema::GetPaletteActions(FGraphActionMenuBuilder& ActionMenuBuilder) const
{
	GetAllVoxelNodeActions(ActionMenuBuilder);
	GetCommentAction(ActionMenuBuilder);
}

void UVoxelGraphSchema::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	GetAllVoxelNodeActions(ContextMenuBuilder, ContextMenuBuilder.CurrentGraph);
	GetCommentAction(ContextMenuBuilder, ContextMenuBuilder.CurrentGraph);

	if (!ContextMenuBuilder.FromPin && FVoxelGraphEditorUtilities::CanPasteNodes(ContextMenuBuilder.CurrentGraph))
	{
		TSharedPtr<FVoxelGraphSchemaAction_Paste> NewAction(new FVoxelGraphSchemaAction_Paste(FText::GetEmpty(), LOCTEXT("PasteHereAction", "Paste here"), FText::GetEmpty(), 0));
		ContextMenuBuilder.AddAction(NewAction);
	}
}

bool UVoxelGraphSchema::TryCreateConnection(UEdGraphPin* A, UEdGraphPin* B) const
{
	bool bModified = UEdGraphSchema::TryCreateConnection(A, B);

	auto AK = Cast<UVoxelGraphNode_Knot>(A->GetOwningNode());
	auto BK = Cast<UVoxelGraphNode_Knot>(B->GetOwningNode());
	if (AK)
	{
		AK->PropagatePinType();
	}
	if (BK)
	{
		BK->PropagatePinType();
	}

	if (bModified)
	{
		CastChecked<UVoxelGraph>(A->GetOwningNode()->GetGraph())->GetWorldGenerator()->CompileVoxelNodesFromGraphNodes();
	}

	return bModified;
}

void UVoxelGraphSchema::TrySetDefaultValue(UEdGraphPin& Pin, const FString& NewDefaultValue) const
{
	FString DefaultValue = NewDefaultValue;

	auto Node = Cast<UVoxelGraphNode>(Pin.GetOwningNode());
	if (Node && Node->VoxelNode)
	{
		int Index = Node->GetInputPinIndex(&Pin);
		if (Index >= 0)
		{
			auto Category = FVoxelPinCategory::FromString(Pin.PinType.PinCategory);
			if (Category == EVoxelPinCategory::Float)
			{
				float Value = FCString::Atof(*DefaultValue);
				auto Min = Node->VoxelNode->GetInputPinDefaultValueMin(Index);
				auto Max = Node->VoxelNode->GetInputPinDefaultValueMax(Index);

				if (Min.IsSet())
				{
					Value = FMath::Max(Min.GetValue(), Value);
				}
				if (Max.IsSet())
				{
					Value = FMath::Min(Max.GetValue(), Value);
				}

				DefaultValue = FString::SanitizeFloat(Value);
			}
			else if (Category == EVoxelPinCategory::Int)
			{
				int Value = FCString::Atoi(*DefaultValue);
				auto Min = Node->VoxelNode->GetInputPinDefaultValueMin(Index);
				auto Max = Node->VoxelNode->GetInputPinDefaultValueMax(Index);

				if (Min.IsSet())
				{
					Value = FMath::Max(FMath::RoundToInt(Min.GetValue()), Value);
				}
				if (Max.IsSet())
				{
					Value = FMath::Min(FMath::RoundToInt(Max.GetValue()), Value);
				}

				DefaultValue = FString::FromInt(Value);
			}
		}
	}

	Super::TrySetDefaultValue(Pin, DefaultValue);

	CastChecked<UVoxelGraph>(Pin.GetOwningNode()->GetGraph())->GetWorldGenerator()->CompileVoxelNodesFromGraphNodes();
}

bool UVoxelGraphSchema::CreateAutomaticConversionNodeAndConnections(UEdGraphPin* PinA, UEdGraphPin* PinB) const
{
	if (PinA->Direction == EGPD_Input)
	{
		//Swap so that A is the from pin and B is the to pin.
		UEdGraphPin* Temp = PinA;
		PinA = PinB;
		PinB = Temp;
	}

	EVoxelPinCategory AType = FVoxelPinCategory::FromString(PinA->PinType.PinCategory);
	EVoxelPinCategory BType = FVoxelPinCategory::FromString(PinB->PinType.PinCategory);

	if (AType != BType && (AType == EVoxelPinCategory::Float || AType == EVoxelPinCategory::Int) && (BType == EVoxelPinCategory::Float || BType == EVoxelPinCategory::Int))
	{
		UEdGraphNode* ANode = PinA->GetOwningNode();
		UEdGraphNode* BNode = PinB->GetOwningNode();
		UVoxelGraph* Graph = CastChecked<UVoxelGraph>(ANode->GetGraph());
		UVoxelGraphGenerator* WorldGenerator = Graph->GetWorldGenerator();

		// Since we'll be adding a node, make sure to modify the graph itself.
		Graph->Modify();
		UVoxelNode* ConvertNode;
		if (AType == EVoxelPinCategory::Int)
		{
			ConvertNode = CastChecked<UVoxelNode_FloatOfInt>(WorldGenerator->ConstructNewNode(UVoxelNode_FloatOfInt::StaticClass()));
		}
		else
		{
			ConvertNode = CastChecked<UVoxelNode_Round>(WorldGenerator->ConstructNewNode(UVoxelNode_Round::StaticClass()));
		}
		ConvertNode->CreateStartingConnectors();

		UVoxelGraphNode* ConvertGraphNode = CastChecked<UVoxelGraphNode>(ConvertNode->GraphNode);
		ConvertGraphNode->NodePosX = (ANode->NodePosX + BNode->NodePosX) >> 1;
		ConvertGraphNode->NodePosY = (ANode->NodePosY + BNode->NodePosY) >> 1;

		auto InputPin = ConvertGraphNode->GetInputPin(0);
		auto OutputPin = ConvertGraphNode->GetOutputPin(0);

		check(InputPin->PinType.PinCategory == PinA->PinType.PinCategory);
		check(OutputPin->PinType.PinCategory == PinB->PinType.PinCategory);

		if (!UEdGraphSchema::TryCreateConnection(PinA, InputPin))
		{
			return false;
		}
		if (!UEdGraphSchema::TryCreateConnection(OutputPin, PinB))
		{
			InputPin->BreakAllPinLinks();
			Graph->RemoveNode(ConvertGraphNode);
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

TArray<UClass*> UVoxelGraphSchema::VoxelNodeClasses;
bool UVoxelGraphSchema::bVoxelNodeClassesInitialized = false;

FLinearColor UVoxelGraphSchema::GetPinTypeColor(const FEdGraphPinType& PinType) const
{
	EVoxelPinCategory Category = FVoxelPinCategory::FromString(PinType.PinCategory);
	const UGraphEditorSettings* Settings = GetDefault<UGraphEditorSettings>();
	
	if (Category == EVoxelPinCategory::Exec)
	{
		return Settings->ExecutionPinTypeColor;
	}
	else if (Category == EVoxelPinCategory::Float)
	{
		return Settings->FloatPinTypeColor;
	}
	else if (Category == EVoxelPinCategory::Boolean)
	{
		return Settings->BooleanPinTypeColor;
	}
	else if (Category == EVoxelPinCategory::Int)
	{
		return Settings->IntPinTypeColor;
	}
	else if (Category == EVoxelPinCategory::Material)
	{
		return Settings->ObjectPinTypeColor;
	}
	else if (Category == EVoxelPinCategory::Seed)
	{
		return Settings->SoftClassPinTypeColor;
	}

	// Type does not have a defined color!
	return Settings->DefaultPinTypeColor;
}

TSharedPtr<FEdGraphSchemaAction> UVoxelGraphSchema::GetCreateCommentAction() const
{
	return TSharedPtr<FEdGraphSchemaAction>(static_cast<FEdGraphSchemaAction*>(new FVoxelGraphSchemaAction_NewComment));
}

int32 UVoxelGraphSchema::GetNodeSelectionCount(const UEdGraph* Graph) const
{
	return FVoxelGraphEditorUtilities::GetNumberOfSelectedNodes(Graph);
}

void UVoxelGraphSchema::GetContextMenuActions(const UEdGraph* CurrentGraph, const UEdGraphNode* InGraphNode, const UEdGraphPin* InGraphPin, class FMenuBuilder* MenuBuilder, bool bIsDebugging) const
{	
	if (InGraphPin != NULL)
	{
		MenuBuilder->BeginSection("EdGraphSchemaPinActions", LOCTEXT("PinActionsMenuHeader", "Pin Actions"));
		{
			if (!bIsDebugging)
			{
				// Break pin links
				if (InGraphPin->LinkedTo.Num() > 0)
				{
					MenuBuilder->AddMenuEntry( FGraphEditorCommands::Get().BreakPinLinks );
				}
			}
		}
		MenuBuilder->EndSection();
	}

	Super::GetContextMenuActions(CurrentGraph, InGraphNode, InGraphPin, MenuBuilder, bIsDebugging);
}

void UVoxelGraphSchema::CreateDefaultNodesForGraph(UEdGraph& Graph) const
{
	const int32 RootNodeHeightOffset = -58;

	// Create the result node
	UVoxelGraphMacro* Macro = Cast<UVoxelGraphMacro>(CastChecked<UVoxelGraph>(&Graph)->GetWorldGenerator());
	if (Macro)
	{		
		UVoxelGraphMacroInputNode* InputNode = CastChecked<UVoxelGraphMacroInputNode>(Macro->ConstructNewNode(UVoxelGraphMacroInputNode::StaticClass()));
		UVoxelGraphMacroOutputNode* OutputNode = CastChecked<UVoxelGraphMacroOutputNode>(Macro->ConstructNewNode(UVoxelGraphMacroOutputNode::StaticClass()));

		Macro->InputNode = InputNode;
		Macro->OutputNode = OutputNode;
		
		UEdGraphNode* GraphInputNode = InputNode->GraphNode;
		UEdGraphNode* GraphOutputNode = OutputNode->GraphNode;
		GraphInputNode->NodePosX = -100;
		GraphOutputNode->NodePosX = 100;

		SetNodeMetaData(GraphInputNode, FNodeMetadata::DefaultGraphNode);
		SetNodeMetaData(GraphOutputNode, FNodeMetadata::DefaultGraphNode);
	}
	else
	{
		FGraphNodeCreator<UVoxelGraphNode_Root> StartNodeCreator(Graph);
		UVoxelGraphNode_Root* StartNode = StartNodeCreator.CreateNode();
		StartNodeCreator.Finalize();
		SetNodeMetaData(StartNode, FNodeMetadata::DefaultGraphNode);
	}
}

void UVoxelGraphSchema::BreakNodeLinks(UEdGraphNode& TargetNode) const
{
	Super::BreakNodeLinks(TargetNode);

	CastChecked<UVoxelGraph>(TargetNode.GetGraph())->GetWorldGenerator()->CompileVoxelNodesFromGraphNodes();
}

void UVoxelGraphSchema::BreakPinLinks(UEdGraphPin& TargetPin, bool bSendsNodeNotifcation) const
{
	const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "GraphEd_BreakPinLinks", "Break Pin Links"));

	auto OldLinkedTo = TargetPin.LinkedTo;
	Super::BreakPinLinks(TargetPin, bSendsNodeNotifcation);

	// if this would notify the node then we need to compile the World Generator
	if (bSendsNodeNotifcation)
	{
		CastChecked<UVoxelGraph>(TargetPin.GetOwningNode()->GetGraph())->GetWorldGenerator()->CompileVoxelNodesFromGraphNodes();
	}	

	auto AK = Cast<UVoxelGraphNode_Knot>(TargetPin.GetOwningNode());
	if (AK)
	{
		AK->PropagatePinType();
	}
	for (auto& Pin : OldLinkedTo)
	{
		auto BK = Cast<UVoxelGraphNode_Knot>(Pin->GetOwningNode());
		if (BK)
		{
			BK->PropagatePinType();
		}
	}
}

void UVoxelGraphSchema::OnPinConnectionDoubleCicked(UEdGraphPin* PinA, UEdGraphPin* PinB, const FVector2D& GraphPosition) const
{
	const FScopedTransaction Transaction(LOCTEXT("CreateRerouteNodeOnWire", "Create Reroute Node"));

	const FVector2D NodeSpacerSize(42.0f, 24.0f);
	const FVector2D KnotTopLeft = GraphPosition - (NodeSpacerSize * 0.5f);

	// Create a new knot
	UEdGraph* ParentGraph = PinA->GetOwningNode()->GetGraph();

	FVoxelGraphSchemaAction_NewKnotNode Action;
	UVoxelGraphNode_Knot* NewKnot = Cast<UVoxelGraphNode_Knot>(Action.PerformAction(ParentGraph, NULL, KnotTopLeft, true));

	// Move the connections across (only notifying the knot, as the other two didn't really change)
	PinA->BreakLinkTo(PinB);
	PinA->MakeLinkTo((PinA->Direction == EGPD_Output) ? NewKnot->GetInputPin() : NewKnot->GetOutputPin());
	PinB->MakeLinkTo((PinB->Direction == EGPD_Output) ? NewKnot->GetInputPin() : NewKnot->GetOutputPin());
	NewKnot->PropagatePinType();

	// Recompile
	CastChecked<UVoxelGraph>(PinA->GetOwningNode()->GetGraph())->GetWorldGenerator()->CompileVoxelNodesFromGraphNodes();
}

const FPinConnectionResponse UVoxelGraphSchema::CanCreateConnection(const UEdGraphPin* PinA, const UEdGraphPin* PinB) const
{
	// Make sure the pins are not on the same node
	if (PinA->GetOwningNode() == PinB->GetOwningNode())
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("ConnectionSameNode", "Both are on the same node"));
	}

	// Compare the directions
	const UEdGraphPin* InputPin = NULL;
	const UEdGraphPin* OutputPin = NULL;

	if (!CategorizePinsByDirection(PinA, PinB, /*out*/ InputPin, /*out*/ OutputPin))
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("ConnectionIncompatible", "Directions are not compatible"));
	}

	check(InputPin);
	check(OutputPin);
	auto InputCategory = FVoxelPinCategory::FromString(InputPin->PinType.PinCategory);
	auto OutputCategory = FVoxelPinCategory::FromString(OutputPin->PinType.PinCategory);

	if (InputCategory != OutputCategory && InputCategory != EVoxelPinCategory::Wildcard && OutputCategory != EVoxelPinCategory::Wildcard)
	{
		if (InputCategory == EVoxelPinCategory::Float && OutputCategory == EVoxelPinCategory::Int)
		{
			return FPinConnectionResponse(CONNECT_RESPONSE_MAKE_WITH_CONVERSION_NODE, LOCTEXT("CastToFloat", "Cast to float"));
		}
		else if (InputCategory == EVoxelPinCategory::Int && OutputCategory == EVoxelPinCategory::Float)
		{
			return FPinConnectionResponse(CONNECT_RESPONSE_MAKE_WITH_CONVERSION_NODE, LOCTEXT("RoundToInt", "Round to int"));
		}
		else
		{
			return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("TypesIncompatible", "Types are not compatible"));
		}
	}

	if (ConnectionCausesLoop(InputPin, OutputPin))
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("ConnectionLoop", "Connection would cause loop"));
	}

	// Break existing connections on inputs only except for exec - multiple output connections are acceptable
	if (InputCategory != EVoxelPinCategory::Exec && InputPin->LinkedTo.Num() > 0)
	{
		ECanCreateConnectionResponse ReplyBreakOutputs;
		if (InputPin == PinA)
		{
			ReplyBreakOutputs = CONNECT_RESPONSE_BREAK_OTHERS_A;
		}
		else
		{
			ReplyBreakOutputs = CONNECT_RESPONSE_BREAK_OTHERS_B;
		}
		return FPinConnectionResponse(ReplyBreakOutputs, LOCTEXT("ConnectionReplace", "Replace existing connections"));
	}
	
	if (OutputCategory == EVoxelPinCategory::Exec && OutputPin->LinkedTo.Num() > 0)
	{
		ECanCreateConnectionResponse ReplyBreakOutputs;
		if (OutputPin == PinA)
		{
			ReplyBreakOutputs = CONNECT_RESPONSE_BREAK_OTHERS_A;
		}
		else
		{
			ReplyBreakOutputs = CONNECT_RESPONSE_BREAK_OTHERS_B;
		}
		return FPinConnectionResponse(ReplyBreakOutputs, LOCTEXT("ConnectionReplace", "Replace existing connections"));
	}

	return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT(""));
}

void UVoxelGraphSchema::GetAllVoxelNodeActions(FGraphActionMenuBuilder& ActionMenuBuilder, const UEdGraph* CurrentGraph) const
{
	InitVoxelNodeClasses();
	
	auto* FromPin = ActionMenuBuilder.FromPin;
	EVoxelPinCategory Category = FromPin ? FVoxelPinCategory::FromString(FromPin->PinType.PinCategory) : EVoxelPinCategory::Wildcard;
	auto Direction = FromPin ? (EEdGraphPinDirection)FromPin->Direction : EGPD_Input;

	// Macros
	{
		// Load the asset registry module
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));

		// Collect a full list of assets with the specified class
		TArray<FAssetData> AssetDataList;
		AssetRegistryModule.Get().GetAssetsByClass(UVoxelGraphMacro::StaticClass()->GetFName(), AssetDataList);

		for (const FAssetData& AssetData : AssetDataList)
		{
			FStreamableManager AssetLoader;
			FStringAssetReference AssetRef(AssetData.ObjectPath.ToString());
			UVoxelGraphMacro* Macro = CastChecked<UVoxelGraphMacro>(AssetLoader.LoadSynchronous(AssetRef));

			if (!Macro->InputNode || !Macro->OutputNode || !Macro->bShowInContextMenu)
			{
				continue;
			}

			if (Macro->bShowInContextMenu &&
				(!FromPin || 
 				 (Direction == EGPD_Input && Macro->OutputNode && Macro->OutputNode->HasInputPinWithCategory(Category)) ||
				 (Direction == EGPD_Output && Macro->InputNode && Macro->InputNode->HasOutputPinWithCategory(Category))))
			{
				const FText Name = FText::FromString(Macro->GetName());
				const FText AddToolTip = FText::Format(LOCTEXT("NewVoxelNodeTooltip", "Adds {0} node here"), Name);

				TSharedPtr<FVoxelGraphSchemaAction_NewMacroNode> NewNodeAction(
					new FVoxelGraphSchemaAction_NewMacroNode(
						LOCTEXT("VoxelNodeAction", "Voxel Macro Nodes"),
						Name, 
						AddToolTip, 
						0));
				NewNodeAction->Macro = Macro;
				ActionMenuBuilder.AddAction(NewNodeAction);
			}
		}
	}

	// Portal nodes
	if (!FromPin || Direction == EGPD_Input)
	{
		auto* Graph = Cast<UVoxelGraph>(CurrentGraph);
		if (Graph)
		{
			auto* WorldGenerator = Graph->GetWorldGenerator();
			for (auto& Node : WorldGenerator->AllNodes)
			{
				auto* InputNode = Cast<UVoxelPortalNodeInput>(Node);
				if (InputNode && (!FromPin || InputNode->GetCategory() == Category))
				{
					const FText Name = FText::FromString(InputNode->Name);
					const FText AddToolTip = FText::Format(LOCTEXT("NewVoxelPortalNodeTooltip", "Adds {0} node here"), Name);

					TSharedPtr<FVoxelGraphSchemaAction_NewPortalNode> NewNodeAction(
						new FVoxelGraphSchemaAction_NewPortalNode(
							LOCTEXT("VoxelNodeAction", "Local variables"),
							Name,
							AddToolTip,
							0));
					NewNodeAction->InputNode = InputNode;
					ActionMenuBuilder.AddAction(NewNodeAction);
				}
			}
		}
	}

	for (auto& NodeClass : VoxelNodeClasses)
	{
		UVoxelNode* DefaultNode = NodeClass->GetDefaultObject<UVoxelNode>();
		if (!FromPin ||
			(Direction == EGPD_Input && DefaultNode->HasOutputPinWithCategory(Category)) ||
			(Direction == EGPD_Output && DefaultNode->HasInputPinWithCategory(Category)))
		{
			bool bIsNoise = NodeClass->IsChildOf(UVoxelNode_NoiseNode::StaticClass());
			FText Name = FText::FromString(NodeClass->GetDescription());
			FText AddToolTip = FText::Format(LOCTEXT("NewVoxelNodeTooltip", "Adds {0} node here"), Name);
			FText Keywords = NodeClass->GetMetaDataText(TEXT("Keywords"), TEXT("UObjectKeywords"), GetClass()->GetFullGroupName(false));

			TSharedPtr<FVoxelGraphSchemaAction_NewNode> NewNodeAction(
				new FVoxelGraphSchemaAction_NewNode(
					bIsNoise ? LOCTEXT("VoxelNoiseNodeAction", "Voxel Noise Nodes") : LOCTEXT("VoxelNodeAction", "Voxel Nodes"),
					Name,
					AddToolTip,
					0,
					Keywords));
			NewNodeAction->VoxelNodeClass = NodeClass;
			ActionMenuBuilder.AddAction(NewNodeAction);
		}
	}

	const FText MenuDescription = LOCTEXT("AddKnotNoteAction", "Add reroute node...");
	const FText ToolTip = LOCTEXT("CreateKnotNodeToolTip", "Creates a reroute node.");
	TSharedPtr<FVoxelGraphSchemaAction_NewKnotNode> NewNodeAction(new FVoxelGraphSchemaAction_NewKnotNode(FText::GetEmpty(), MenuDescription, ToolTip, 0));
	ActionMenuBuilder.AddAction(NewNodeAction);
}

void UVoxelGraphSchema::GetCommentAction(FGraphActionMenuBuilder& ActionMenuBuilder, const UEdGraph* CurrentGraph /*= NULL*/) const
{
	if (!ActionMenuBuilder.FromPin)
	{
		const bool bIsManyNodesSelected = CurrentGraph ? (FVoxelGraphEditorUtilities::GetNumberOfSelectedNodes(CurrentGraph) > 0) : false;
		const FText MenuDescription = bIsManyNodesSelected ? LOCTEXT("CreateCommentAction", "Create Comment from Selection") : LOCTEXT("AddCommentAction", "Add Comment...");
		const FText ToolTip = LOCTEXT("CreateCommentToolTip", "Creates a comment.");

		TSharedPtr<FVoxelGraphSchemaAction_NewComment> NewAction(new FVoxelGraphSchemaAction_NewComment(FText::GetEmpty(), MenuDescription, ToolTip, 0));
		ActionMenuBuilder.AddAction(NewAction);
	}

}

void UVoxelGraphSchema::InitVoxelNodeClasses()
{
	if (bVoxelNodeClassesInitialized)
	{
		return;
	}
	VoxelNodeClasses.Empty();

	// Construct list of non-abstract voxel node classes.
	for (TObjectIterator<UClass> It; It; ++It)
	{
		if (It->IsChildOf(UVoxelNode::StaticClass()) && !It->HasAnyClassFlags(CLASS_Abstract | CLASS_NotPlaceable | CLASS_Deprecated))
		{
			VoxelNodeClasses.Add(*It);
		}
	}

	VoxelNodeClasses.Sort();

	bVoxelNodeClassesInitialized = true;
}

#undef LOCTEXT_NAMESPACE
