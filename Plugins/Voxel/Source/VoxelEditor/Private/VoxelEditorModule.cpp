// Copyright 2018 Phyronnaz

#include "VoxelEditorModule.h"

#include "Interfaces/IPluginManager.h"
#include "IPlacementModeModule.h"
#include "PropertyEditorModule.h"
#include "Styling/SlateStyle.h"
#include "EditorModeRegistry.h"

#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "VoxelWorld.h"
#include "VoxelPlaceableItems/VoxelExclusionBox.h"
#include "VoxelPlaceableItems/VoxelAssetActor.h"

#include "VoxelCrashReporterEditor.h"

#include "AssetTools/AssetTypeActions_VoxelGrassGroup.h"
#include "AssetTools/AssetTypeActions_VoxelGrassSpawner.h"
#include "AssetTools/AssetTypeActions_VoxelDataAsset.h"
#include "AssetTools/AssetTypeActions_VoxelHeightmapAsset.h"
#include "AssetTools/AssetTypeActions_VoxelGraphWorldGenerator.h"
#include "AssetTools/AssetTypeActions_VoxelActorSpawner.h"
#include "AssetTools/AssetTypeActions_VoxelActorGroup.h"
#include "AssetTools/AssetTypeActions_VoxelGraphMacro.h"
#include "AssetTools/AssetTypeActions_VoxelWorldSaveObject.h"
#include "AssetTools/AssetTypeActions_VoxelMaterialCollection.h"

#include "Thumbnails/VoxelGraphGeneratorThumbnailRenderer.h"

#include "Graph/VoxelGraphConnectionDrawingPolicy.h"
#include "Graph/VoxelGraphNodeFactory.h"
#include "Graph/VoxelGraphPanelPinFactory.h"
#include "Graph/VoxelGraphEditorToolkit.h"

#include "DataAssetEditor/VoxelDataAssetEditorToolkit.h"

#include "EdMode/VoxelEdMode.h"

#include "VoxelEditorTools/VoxelDefaultEditorTools.h"

#include "Factories/VoxelWorldFactory.h"
#include "Factories/VoxelPlaceableItemActorFactory.h"

#include "Details/VoxelWorldDetails.h"
#include "Details/VoxelLandscapeImporterDetails.h"
#include "Details/VoxelHeightmapImporterDetails.h"
#include "Details/VoxelSplineImporterDetails.h"
#include "Details/VoxelMeshImporterDetails.h"
#include "Details/VoxelAssetActorDetails.h"
#include "Details/VoxelWorldGeneratorPickerCustomization.h"
#include "Details/VoxelPortalNodeSelectorCustomization.h"
#include "Details/VoxelMaterialCollectionDetails.h"
#include "Details/VoxelDataAssetEditorVoxelWorldDetails.h"
#include "Styling/SlateStyleRegistry.h"

#include "VoxelImporters/VoxelSplineImporter.h"
#include "VoxelImporters/VoxelMeshImporter.h"
#include "VoxelImporters/VoxelLandscapeImporter.h"
#include "VoxelImporters/VoxelHeightmapImporter.h"

#define LOCTEXT_NAMESPACE "VoxelEditorModule"

const FVector2D Icon14x14(14.0f, 14.0f);
const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);
const FVector2D Icon64x64(64.0f, 64.0f);
const FVector2D Icon512x512(512.0f, 512.0f);

DEFINE_LOG_CATEGORY(LogVoxelEditor);

/**
 * Implements the VoxelEditor module.
 */
class FVoxelEditorModule : public IVoxelEditorModule
{
public:
	virtual void StartupModule() override
	{
		FVoxelCrashReporterEditor::Register();

		// Voxel asset category
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		VoxelAssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("Voxel")), LOCTEXT("VoxelAssetCategory", "Voxel"));

		RegisterPlacementModeExtensions();
		RegisterClassLayout();
		RegisterAssetTools();

		// Thumbnails
		UThumbnailManager::Get().RegisterCustomRenderer(UVoxelGraphGenerator::StaticClass(), UVoxelGraphGeneratorThumbnailRenderer::StaticClass());

		// Graph
		{
			TSharedPtr<FVoxelGraphConnectionDrawingPolicyFactory> VoxelGraphConnectionFactory = MakeShareable(new FVoxelGraphConnectionDrawingPolicyFactory);
			FEdGraphUtilities::RegisterVisualPinConnectionFactory(VoxelGraphConnectionFactory);

			TSharedPtr<FVoxelGraphNodeFactory> VoxelGraphNodeFactory = MakeShareable(new FVoxelGraphNodeFactory());
			FEdGraphUtilities::RegisterVisualNodeFactory(VoxelGraphNodeFactory);

			TSharedPtr<FVoxelGraphPanelPinFactory> VoxelGraphPanelPinFactory = MakeShareable(new FVoxelGraphPanelPinFactory());
			FEdGraphUtilities::RegisterVisualPinFactory(VoxelGraphPanelPinFactory);
		}

		// Icons
		{
			FString ContentDir = IPluginManager::Get().FindPlugin(TEXT("Voxel"))->GetContentDir() + "/";

			StyleSet = MakeShareable(new FSlateStyleSet("VoxelStyle"));
			StyleSet->SetContentRoot(FPaths::EngineContentDir() / TEXT("Editor/Slate"));
			StyleSet->SetCoreContentRoot(FPaths::EngineContentDir() / TEXT("Slate"));

			// VoxelWorld
			StyleSet->Set("ClassThumbnail.VoxelWorld"                        , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/World_64x.png"), Icon64x64));
			StyleSet->Set("ClassIcon.VoxelWorld"                             , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/World_16x.png"), Icon16x16));
																		     
			// Voxel Material Collection								     
			StyleSet->Set("ClassThumbnail.VoxelMaterialCollection"           , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/AssetIcons/PaperTileMap_64x.png")), Icon64x64));
			StyleSet->Set("ClassIcon.VoxelMaterialCollection"                , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/AssetIcons/PaperTileMap_16x.png")), Icon16x16));
																		     
			// Compile To C++											     
			StyleSet->Set("VoxelGraphEditor.CompileToCpp"                    , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/icon_compile_40x.png")), Icon40x40));
			StyleSet->Set("VoxelGraphEditor.CompileToCpp.Small"              , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/icon_compile_40x.png")), Icon20x20));
																		     
			// Update Macros											     
			StyleSet->Set("VoxelGraphEditor.RecreateNodes"                   , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/icon_Cascade_RestartInLevel_40x.png")), Icon40x40));
			StyleSet->Set("VoxelGraphEditor.RecreateNodes.Small"             , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/icon_Cascade_RestartInLevel_40x.png")), Icon20x20));
																		     
			// Enable automatic preview									     
			StyleSet->Set("VoxelGraphEditor.ToggleAutomaticPreview"          , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/icon_MatEd_LivePreview_40x.png")), Icon40x40));
			StyleSet->Set("VoxelGraphEditor.ToggleAutomaticPreview.Small"    , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/icon_MatEd_LivePreview_40x.png")), Icon20x20));
																		     
			// Update preview											     
			StyleSet->Set("VoxelGraphEditor.UpdatePreview"                   , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/icon_Cascade_RestartInLevel_40x.png")), Icon40x40));
			StyleSet->Set("VoxelGraphEditor.UpdatePreview.Small"             , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/icon_Cascade_RestartInLevel_40x.png")), Icon20x20));
																		     
			// Toggle stats												     
			StyleSet->Set("VoxelGraphEditor.ToggleStats"                     , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/Profiler/profiler_stats_40x.png")), Icon40x40));
			StyleSet->Set("VoxelGraphEditor.ToggleStats.Small"               , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/Profiler/profiler_stats_40x.png")), Icon20x20));

			// Toggle ShowAxisDependencies
			StyleSet->Set("VoxelGraphEditor.ToggleShowAxisDependencies"      , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/Profiler/profiler_Calls_32x.png")), Icon40x40));
			StyleSet->Set("VoxelGraphEditor.ToggleShowAxisDependencies.Small", new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/Profiler/profiler_Calls_32x.png")), Icon20x20));
			
			// Importers
			StyleSet->Set("ClassThumbnail.VoxelHeightmapImporter"            , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/Import_64x.png"), Icon64x64));
			StyleSet->Set("ClassIcon.VoxelHeightmapImporter"                 , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/Import_16x.png"), Icon16x16));
			StyleSet->Set("ClassThumbnail.VoxelLandscapeImporter"            , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/Import_64x.png"), Icon64x64));
			StyleSet->Set("ClassIcon.VoxelLandscapeImporter"                 , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/Import_16x.png"), Icon16x16));
			StyleSet->Set("ClassThumbnail.VoxelMeshImporter"                 , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/Import_64x.png"), Icon64x64));
			StyleSet->Set("ClassIcon.VoxelMeshImporter"                      , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/Import_16x.png"), Icon16x16));
			StyleSet->Set("ClassThumbnail.VoxelSplineImporter"               , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/Import_64x.png"), Icon64x64));
			StyleSet->Set("ClassIcon.VoxelSplineImporter"                    , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/Import_16x.png"), Icon16x16));
			
			// Actors
			StyleSet->Set("ClassThumbnail.VoxelActorSpawner"                 , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/ActorSpawner_64x.png"), Icon64x64));
			StyleSet->Set("ClassIcon.VoxelActorSpawner"                      , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/ActorSpawner_16x.png"), Icon16x16));
			StyleSet->Set("ClassThumbnail.VoxelActorGroup"                   , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/ActorGroup_64x.png")  , Icon64x64));
			StyleSet->Set("ClassIcon.VoxelActorGroup"                        , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/ActorGroup_16x.png")  , Icon16x16));
																		     
			// Grass													     
			StyleSet->Set("ClassThumbnail.VoxelGrassSpawner"                 , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/GrassSpawner_64x.png"), Icon64x64));
			StyleSet->Set("ClassIcon.VoxelGrassSpawner"                      , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/GrassSpawner_16x.png"), Icon16x16));
			StyleSet->Set("ClassThumbnail.VoxelGrassGroup"                   , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/GrassGroup_64x.png")  , Icon64x64));
			StyleSet->Set("ClassIcon.VoxelGrassGroup"                        , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/GrassGroup_16x.png")  , Icon16x16));
																		     
			// Voxel Graph												     
			StyleSet->Set("ClassThumbnail.VoxelGraphGenerator"               , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/VoxelGraph_64x.png"), Icon64x64));
			StyleSet->Set("ClassIcon.VoxelGraphGenerator"                    , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/VoxelGraph_16x.png"), Icon16x16));
																		     
			// Data Asset												     
			StyleSet->Set("ClassThumbnail.VoxelDataAsset"                    , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/DataAsset_64x.png"), Icon64x64));
			StyleSet->Set("ClassIcon.VoxelDataAsset"                         , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/DataAsset_16x.png"), Icon16x16));
																		     
			// Landscape asset											     
			StyleSet->Set("ClassThumbnail.VoxelLandscapeAsset"               , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/Landscape_64x.png"), Icon64x64));
			StyleSet->Set("ClassIcon.VoxelLandscapeAsset"                    , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/Landscape_16x.png"), Icon16x16));	
																		     
			// Voxel Editor Tools										     
			StyleSet->Set("VoxelTools.Tab"                                   , new FSlateImageBrush(ContentDir + TEXT("Icons/UIIcons/mode_40.png"), Icon40x40));
																		     
			StyleSet->Set("VoxelTools.Projection"                            , new FSlateImageBrush(ContentDir + TEXT("Icons/UIIcons/tool_projection_40.png"), Icon40x40));
			StyleSet->Set("VoxelTools.Box"                                   , new FSlateImageBrush(ContentDir + TEXT("Icons/UIIcons/tool_box_40.png")       , Icon40x40));
			StyleSet->Set("VoxelTools.Sphere"                                , new FSlateImageBrush(ContentDir + TEXT("Icons/UIIcons/tool_sphere_40.png")    , Icon40x40)); 
																		     
			StyleSet->Set("VoxelTools.Paint"                                 , new FSlateImageBrush(ContentDir + TEXT("Icons/UIIcons/mode_paint_40.png")    , Icon40x40));
			StyleSet->Set("VoxelTools.Sculpt"                                , new FSlateImageBrush(ContentDir + TEXT("Icons/UIIcons/mode_sculpt_40.png")    , Icon40x40)); 
			StyleSet->Set("VoxelTools.Grass"                                , new FSlateImageBrush(ContentDir + TEXT("Icons/UIIcons/mode_sculpt_40.png")    , Icon40x40)); 
																		     
			// Data Asset Editor										     
			StyleSet->Set("VoxelDataAssetEditor.IncreaseWorkArea"            , new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Icons/icon_TextureEd_FillViewport_40x.png")), Icon40x40));
																		     
			// World generator											     
			StyleSet->Set("ClassThumbnail.VoxelWorldGenerator"               , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/WorldGenerator_64x.png"), Icon64x64));
			StyleSet->Set("ClassIcon.VoxelWorldGenerator"                    , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/WorldGenerator_16x.png"), Icon16x16));
																		     
			// Voxel World Object Save									     
			StyleSet->Set("ClassThumbnail.VoxelWorldSaveObject"              , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/VoxelWorldSaveObject_64x.png"), Icon64x64));
			StyleSet->Set("ClassIcon.VoxelWorldSaveObject"                   , new FSlateImageBrush(ContentDir + TEXT("Icons/AssetIcons/VoxelWorldSaveObject_16x.png"), Icon16x16));
			
			FSlateStyleRegistry::RegisterSlateStyle(*StyleSet.Get());
		}

		// Voxel Editor Tools
		{
			FEditorModeRegistry::Get().RegisterMode<FEdModeVoxel>(FEdModeVoxel::EM_Voxel, LOCTEXT("VoxelEdModeName", "Voxels"), FSlateIcon("VoxelStyle", "VoxelTools.Tab"), true);
			FVoxelDefaultEditorToolsCommands::Register();
		}
	}

	virtual void ShutdownModule() override
	{
		FEditorModeRegistry::Get().UnregisterMode(FEdModeVoxel::EM_Voxel);

		if (UObjectInitialized())
		{
			UThumbnailManager::Get().UnregisterCustomRenderer(UVoxelGraphGenerator::StaticClass());
		}

		UnregisterPlacementModeExtensions();
		UnregisterClassLayout();
		UnregisterAssetTools();

		if (StyleSet.IsValid())
		{
			FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet.Get());
			StyleSet.Reset();
		}
	}

	virtual bool SupportsDynamicReloading() override
	{
		return true;
	}


protected:
	
	/** Registers placement mode extensions. */
	void RegisterPlacementModeExtensions()
	{
		FPlacementCategoryInfo Info(
			LOCTEXT("VoxelCategoryName", "Voxel"),
			"Voxel",
			TEXT("PMVoxel"),
			25
		);

		IPlacementModeModule::Get().RegisterPlacementCategory(Info);
		IPlacementModeModule::Get().RegisterPlaceableItem(Info.UniqueHandle, MakeShareable(new FPlaceableItem(UVoxelWorldFactory::StaticClass()->GetDefaultObject<UVoxelWorldFactory>(), FAssetData(AVoxelWorld::StaticClass()))));
		IPlacementModeModule::Get().RegisterPlaceableItem(Info.UniqueHandle, MakeShareable(new FPlaceableItem(UVoxelExclusionBoxFactory::StaticClass()->GetDefaultObject<UVoxelExclusionBoxFactory>(), FAssetData(AVoxelExclusionBox::StaticClass()))));
		IPlacementModeModule::Get().RegisterPlaceableItem(Info.UniqueHandle, MakeShareable(new FPlaceableItem(UVoxelAssetActorFactory::StaticClass()->GetDefaultObject<UVoxelAssetActorFactory>(), FAssetData(AVoxelAssetActor::StaticClass()))));
		
		IPlacementModeModule::Get().RegisterPlaceableItem(Info.UniqueHandle, MakeShareable(new FPlaceableItem(nullptr, FAssetData(AVoxelHeightmapImporter::StaticClass()))));
		IPlacementModeModule::Get().RegisterPlaceableItem(Info.UniqueHandle, MakeShareable(new FPlaceableItem(nullptr, FAssetData(AVoxelLandscapeImporter::StaticClass()))));
		IPlacementModeModule::Get().RegisterPlaceableItem(Info.UniqueHandle, MakeShareable(new FPlaceableItem(nullptr, FAssetData(AVoxelMeshImporter::StaticClass()))));
		IPlacementModeModule::Get().RegisterPlaceableItem(Info.UniqueHandle, MakeShareable(new FPlaceableItem(nullptr, FAssetData(AVoxelSplineImporter::StaticClass()))));
	}

	/** Unregisters placement mode extensions. */
	void UnregisterPlacementModeExtensions()
	{
		if (IPlacementModeModule::IsAvailable())
		{
			IPlacementModeModule::Get().UnregisterPlacementCategory("Voxel");
		}
	}

	void RegisterClassLayout()
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

		//Custom detail views
		PropertyModule.RegisterCustomClassLayout("VoxelWorld"                    , FOnGetDetailCustomizationInstance::CreateStatic(&FVoxelWorldDetails                    ::MakeInstance));
		PropertyModule.RegisterCustomClassLayout("VoxelMaterialCollection"       , FOnGetDetailCustomizationInstance::CreateStatic(&FVoxelMaterialCollectionDetails       ::MakeInstance));
		PropertyModule.RegisterCustomClassLayout("VoxelLandscapeImporter"        , FOnGetDetailCustomizationInstance::CreateStatic(&FVoxelLandscapeImporterDetails        ::MakeInstance));
		PropertyModule.RegisterCustomClassLayout("VoxelHeightmapImporter"        , FOnGetDetailCustomizationInstance::CreateStatic(&FVoxelHeightmapImporterDetails        ::MakeInstance));
		PropertyModule.RegisterCustomClassLayout("VoxelSplineImporter"           , FOnGetDetailCustomizationInstance::CreateStatic(&FVoxelSplineImporterDetails           ::MakeInstance));
		PropertyModule.RegisterCustomClassLayout("VoxelMeshImporter"             , FOnGetDetailCustomizationInstance::CreateStatic(&FVoxelMeshImporterDetails             ::MakeInstance));
		PropertyModule.RegisterCustomClassLayout("VoxelAssetActor"               , FOnGetDetailCustomizationInstance::CreateStatic(&FVoxelAssetActorDetails               ::MakeInstance));
		PropertyModule.RegisterCustomClassLayout("VoxelDataAssetEditorVoxelWorld", FOnGetDetailCustomizationInstance::CreateStatic(&FVoxelDataAssetEditorVoxelWorldDetails::MakeInstance));
		
		PropertyModule.RegisterCustomPropertyTypeLayout("VoxelWorldGeneratorPicker"     , FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FVoxelWorldGeneratorPickerCustomization     ::MakeInstance));
		PropertyModule.RegisterCustomPropertyTypeLayout("VoxelMaterialCollectionElement", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FVoxelMaterialCollectionElementCustomization::MakeInstance));
		PropertyModule.RegisterCustomPropertyTypeLayout("VoxelPortalNodeSelector"       , FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FVoxelPortalNodeSelectorCustomization       ::MakeInstance));

		PropertyModule.NotifyCustomizationModuleChanged();
	}

	void UnregisterClassLayout()
	{
		FPropertyEditorModule* PropertyModule = FModuleManager::GetModulePtr<FPropertyEditorModule>("PropertyEditor");

		if (PropertyModule != nullptr)
		{
			PropertyModule->UnregisterCustomClassLayout("VoxelWorld");
			PropertyModule->UnregisterCustomClassLayout("VoxelMaterialCollection");
			PropertyModule->UnregisterCustomClassLayout("VoxelLandscapeImporter");
			PropertyModule->UnregisterCustomClassLayout("VoxelHeightmapImporter");
			PropertyModule->UnregisterCustomClassLayout("VoxelSplineImporter");
			PropertyModule->UnregisterCustomClassLayout("VoxelMeshImporter");
			PropertyModule->UnregisterCustomClassLayout("VoxelRawVoxImporter");
			PropertyModule->UnregisterCustomClassLayout("VoxelMagicaVoxelImporter");
			PropertyModule->UnregisterCustomClassLayout("VoxelWorldSectionImporter");
			PropertyModule->UnregisterCustomClassLayout("VoxelAssetActor");
			
			PropertyModule->UnregisterCustomPropertyTypeLayout("VoxelWorldGeneratorPicker");
			PropertyModule->UnregisterCustomPropertyTypeLayout("VoxelPortalNodeSelector");

			PropertyModule->NotifyCustomizationModuleChanged();
		}
	}

	/** Registers asset tool actions. */
	void RegisterAssetTools()
	{
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_VoxelWorldSaveObject(    VoxelAssetCategoryBit)));
		RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_VoxelMaterialCollection( VoxelAssetCategoryBit)));
		RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_VoxelGrassGroup(         VoxelAssetCategoryBit)));
		RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_VoxelGrassSpawner(       VoxelAssetCategoryBit)));
		RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_VoxelDataAsset(          VoxelAssetCategoryBit)));
		RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_VoxelActorSpawner(       VoxelAssetCategoryBit)));
		RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_VoxelActorGroup(         VoxelAssetCategoryBit)));
		RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_VoxelHeightmapAsset(     VoxelAssetCategoryBit)));
		RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_VoxelGraphWorldGenerator(VoxelAssetCategoryBit)));
		RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_VoxelGraphMacro(         VoxelAssetCategoryBit)));
	}

	/**
	* Registers a single asset type action.
	*
	* @param AssetTools The asset tools object to register with.
	* @param Action The asset type action to register.
	*/
	void RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
	{
		AssetTools.RegisterAssetTypeActions(Action);
		RegisteredAssetTypeActions.Add(Action);
	}

	/** Unregisters asset tool actions. */
	void UnregisterAssetTools()
	{
		FAssetToolsModule* AssetToolsModule = FModuleManager::GetModulePtr<FAssetToolsModule>("AssetTools");

		if (AssetToolsModule != nullptr)
		{
			IAssetTools& AssetTools = AssetToolsModule->Get();

			for (auto& Action : RegisteredAssetTypeActions)
			{
				AssetTools.UnregisterAssetTypeActions(Action);
			}
		}
	}

	virtual TSharedRef<IVoxelGraphEditorToolkit> CreateVoxelGraphEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UVoxelGraphGenerator* WorldGenerator) override
	{
		TSharedRef<FVoxelGraphEditorToolkit> NewVoxelEditor(new FVoxelGraphEditorToolkit());
		NewVoxelEditor->InitVoxelEditor(Mode, InitToolkitHost, WorldGenerator);
		return NewVoxelEditor;
	}

	virtual void CreateVoxelDataAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UVoxelDataAsset* DataAsset) override
	{
		TSharedRef<FVoxelDataAssetEditorToolkit> NewVoxelEditor(new FVoxelDataAssetEditorToolkit());
		NewVoxelEditor->InitVoxelEditor(Mode, InitToolkitHost, DataAsset);
	}

private:
	/** The collection of registered asset type actions. */
	TArray<TSharedRef<IAssetTypeActions>> RegisteredAssetTypeActions;
	EAssetTypeCategories::Type VoxelAssetCategoryBit;
	TSharedPtr< class FSlateStyleSet > StyleSet;
};

IMPLEMENT_MODULE(FVoxelEditorModule, VoxelEditor);

#undef LOCTEXT_NAMESPACE
#undef IMAGE_PLUGIN_BRUSH
