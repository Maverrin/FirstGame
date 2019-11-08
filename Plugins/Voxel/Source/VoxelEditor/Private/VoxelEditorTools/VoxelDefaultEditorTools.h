// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "VoxelEditorTool.h"
#include "VoxelTools/VoxelMarker.h"
#include "VoxelEditorUtilities.h"
#include "VoxelData/VoxelData.h"
#include "VoxelDefaultEditorTools.generated.h"

#define LOCTEXT_NAMESPACE "VoxelDefaultEditorTools"

class FVoxelDefaultEditorToolsCommands : public TCommands<FVoxelDefaultEditorToolsCommands>
{
public:
	FVoxelDefaultEditorToolsCommands() : TCommands<FVoxelDefaultEditorToolsCommands>
		(
			"VoxelTools", // Context name for icons
			NSLOCTEXT("Contexts", "VoxelEdMode", "Voxel Editor Mode"), // Localized context name for displaying
			NAME_None, // Parent
			"VoxelStyle" // Icon Style Set
		)
	{
	}


	virtual void RegisterCommands() override
	{
		// Tools
		UI_COMMAND(Projection, "Projection", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Sphere, "Sphere", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Box, "Box", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Custom0, "Custom0", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Custom1, "Custom1", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Custom2, "Custom2", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Custom3, "Custom3", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Custom4, "Custom4", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Custom5, "Custom5", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Custom6, "Custom6", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Custom7, "Custom7", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Custom8, "Custom8", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Custom9, "Custom9", "", EUserInterfaceActionType::RadioButton, FInputChord());

		// Modes
		UI_COMMAND(Paint, "Paint", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Sculpt, "Sculpt", "", EUserInterfaceActionType::RadioButton, FInputChord());
		UI_COMMAND(Grass, "Grass", "", EUserInterfaceActionType::RadioButton, FInputChord());
	}

public:
	// Tools
	TSharedPtr<FUICommandInfo> Projection;
	TSharedPtr<FUICommandInfo> Sphere;
	TSharedPtr<FUICommandInfo> Box;

	TSharedPtr<FUICommandInfo> Custom0;
	TSharedPtr<FUICommandInfo> Custom1;
	TSharedPtr<FUICommandInfo> Custom2;
	TSharedPtr<FUICommandInfo> Custom3;
	TSharedPtr<FUICommandInfo> Custom4;
	TSharedPtr<FUICommandInfo> Custom5;
	TSharedPtr<FUICommandInfo> Custom6;
	TSharedPtr<FUICommandInfo> Custom7;
	TSharedPtr<FUICommandInfo> Custom8;
	TSharedPtr<FUICommandInfo> Custom9;
	
	// Modes
	TSharedPtr<FUICommandInfo> Paint;
	TSharedPtr<FUICommandInfo> Sculpt;
	TSharedPtr<FUICommandInfo> Grass;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

UENUM(BlueprintType)
enum class EVoxelEditorTool_SculptPaint : uint8
{
	Sculpt = 0,
	Paint = 1,
	Grass = 2
};

UENUM(BlueprintType)
enum class EVoxelEditorTool_Icons : uint8
{
	Projection,
	Sphere,
	Box,
	Custom0,
	Custom1,
	Custom2,
	Custom3,
	Custom4,
	Custom5,
	Custom6,
	Custom7,
	Custom8,
	Custom9
};

UCLASS(Blueprintable, abstract)
class UVoxelEditorTool_SculptPaintBase : public UVoxelEditorTool
{
	GENERATED_BODY()
		
public:
	UPROPERTY(EditDefaultsOnly, Category = "Voxel Editor Tools")
	TSubclassOf<AVoxelMarker> MarkerClass;
	
	UPROPERTY(EditDefaultsOnly, Category = "Voxel Editor Tools")
	EVoxelEditorTool_Icons Icon;

	UPROPERTY(EditDefaultsOnly, Category = "Voxel Editor Tools")
	FText Label;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Voxel Editor Tools")
	FText Tooltip;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Voxel Editor Tools", DisplayName = "Input Key")
	void K2_InputKey(FKey Key, EInputEvent Event, bool& Handled);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Voxel Editor Tools", DisplayName = "Input Axis")
	void K2_InputAxis(FKey Key, float Delta, float DeltaTime, bool& Handled);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Voxel Editor Tools", DisplayName = "Handle Voxel World Click")
	void K2_HandleVoxelWorldClick(FVector Position, FVector Normal);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Voxel Editor Tools", DisplayName = "Tick")
	void K2_Tick(float DeltaTime, FVector LastPosition, FVector LastNormal, bool bHidden);

	UFUNCTION(BlueprintCallable, Category = "Voxel Editor Tools")
	EVoxelEditorTool_SculptPaint GetCurrentMode() const { return (EVoxelEditorTool_SculptPaint)GetMode(); }

	UFUNCTION(BlueprintCallable, Category = "Voxel Editor Tools")
	AVoxelWorld* GetCurrentVoxelWorld() const { return World; }

	UFUNCTION(BlueprintCallable, Category = "Voxel Editor Tools")
	AVoxelMarker* GetMarker() const { return Marker; }
	
	UFUNCTION(BlueprintCallable, Category = "Voxel Editor Tools")
	bool IsKeyDown(FKey Key) const { return Viewport && Viewport->KeyState(Key); }

	UFUNCTION(BlueprintCallable, Category = "Voxel Editor Tools")
	void EndEdit()
	{
		World->GetData()->SaveFrame();
		FVoxelEditorUtilities::ModifyWorld(World);
	}

public:
	virtual TSharedPtr<FUICommandInfo> GetCommand() const override;
	virtual FText GetLabel() const override { return Label; }
	virtual FText GetToolTip() const override { return Tooltip; }

public:
	virtual void Enable() override;
	virtual void Disable() override;
	virtual void GetModeCommands(TArray<FVoxelEditorToolMode>& OutCommands) const override;
	virtual bool IsModePropertyVisible(const UProperty& Property) const override;

public:
	virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) override;
	virtual void HandleClick(FEditorViewportClient* ViewportClient, HHitProxy* HitProxy, const FViewportClick& Click) override;
	virtual bool InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event) override;
	virtual bool InputAxis(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, float Delta, float DeltaTime) override;
	
private:
	void CreateMarker();
	void DestroyMarker();
	
	UPROPERTY()
	AVoxelMarker* Marker;

	FViewport* Viewport = nullptr;

	FVector SavedLastPosition;
	FVector SavedLastNormal;
	bool bIsMarkerHidden = false;
};
#undef LOCTEXT_NAMESPACE
