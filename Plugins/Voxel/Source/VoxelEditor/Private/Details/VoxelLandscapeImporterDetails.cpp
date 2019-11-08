// Copyright 2018 Phyronnaz

#include "VoxelLandscapeImporterDetails.h"
#include "VoxelImporters/VoxelLandscapeImporter.h"

#include "VoxelAssets/VoxelHeightmapAsset.h"
#include "Factories/VoxelHeightmapAssetFactory.h"

#include "Misc/MessageDialog.h"

#include "LandscapeDataAccess.h"
#include "Landscape.h"
#include "LandscapeComponent.h"

#include "VoxelEditorDetailsUtils.h"

#define LOCTEXT_NAMESPACE "VoxelLandscapeImporterDetails"

TSharedRef<IDetailCustomization> FVoxelLandscapeImporterDetails::MakeInstance()
{
	return MakeShareable(new FVoxelLandscapeImporterDetails());
}

void FVoxelLandscapeImporterDetails::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	Importer = FVoxelEditorDetailsUtils::GetCurrentObjectFromDetails<AVoxelLandscapeImporter>(DetailLayout);

	ADD_BUTTON_TO_CATEGORY(DetailLayout,
		"Create VoxelLandscapeAsset from Landscape",
		LOCTEXT("Create", "Create"),
		LOCTEXT("CreateFromLandscape", "Create From Landscape"),
		LOCTEXT("Create", "Create"),
		this,
		&FVoxelLandscapeImporterDetails::OnCreateFromLandscape)
}

FReply FVoxelLandscapeImporterDetails::OnCreateFromLandscape()
{
	if (!Importer.IsValid())
	{
		return FReply::Handled();
	}
	if (!Importer->Landscape)
	{
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("Invalid Landscape")));
		return FReply::Handled();
	}

	FVoxelEditorDetailsUtils::CreateAsset<UVoxelHeightmapAssetFloat, UVoxelHeightmapAssetFloatFactory>([&](UVoxelHeightmapAssetFloat* Asset)
	{
		auto& Components = Importer->Landscape->LandscapeComponents;

		int Width = 0;
		int Height = 0;
		for (auto& Component : Components)
		{
			Width = FMath::Max(Width, Component->SectionBaseX + Component->ComponentSizeQuads);
			Height = FMath::Max(Height, Component->SectionBaseY + Component->ComponentSizeQuads);
		}
		
		TSharedRef<FVoxelLandscapeAssetData<float>, ESPMode::ThreadSafe> Data = MakeShared<FVoxelLandscapeAssetData<float>, ESPMode::ThreadSafe>();
		Data->SetSize(Width, Height, Importer->LayerInfos.Num() > 0);

		for (auto& Component : Components)
		{
			FLandscapeComponentDataInterface DataInterface(Component);

			if (Data->HasMaterials())
			{
				struct FTempWeightmap
				{
					TArray<uint8> Weightmap;
					EVoxelLandscapeImporterRGB Layer;
					uint8 Index;

					FTempWeightmap() = default;
				};

				TArray<FTempWeightmap> Weightmaps;
				Weightmaps.SetNum(Importer->LayerInfos.Num());

				for (int Index = 0; Index < Weightmaps.Num(); Index++)
				{
					auto& Weightmap = Weightmaps[Index];
					auto& WeightmapInfo = Importer->LayerInfos[Index];
					DataInterface.GetWeightmapTextureData(WeightmapInfo.LayerInfo, Weightmap.Weightmap);
					Weightmap.Layer = WeightmapInfo.Layer;
					Weightmap.Index = WeightmapInfo.Index;
				}
				Weightmaps.RemoveAll([&](auto& Weightmap) { return Weightmap.Weightmap.Num() == 0; });

				int32 WeightmapSize = (Component->SubsectionSizeQuads + 1) * Component->NumSubsections;

				if (Importer->MaterialConfig == EVoxelMaterialConfig::RGB)
				{
#if ENABLE_VOXELCOLORS
					for (int X = 0; X < Component->ComponentSizeQuads; X++)
					{
						for (int Y = 0; Y < Component->ComponentSizeQuads; Y++)
						{
							int Index = (Component->SectionBaseX + X) + Width * (Component->SectionBaseY + Y);
							int LocalIndex = X + WeightmapSize * Y;

							FVoxelMaterial& Material = Data->Materials[Index];
							if (Weightmaps.Num() > 0)
							{
								for (auto& Weightmap : Weightmaps)
								{
									uint8 Value = Weightmap.Weightmap[LocalIndex];
									switch (Weightmap.Layer)
									{
									case EVoxelLandscapeImporterRGB::R:
										Material.SetR(Value);
										break;
									case EVoxelLandscapeImporterRGB::G:
										Material.SetG(Value);
										break;
									case EVoxelLandscapeImporterRGB::B:
										Material.SetB(Value);
										break;
									default: check(false);
									}
								}
							}
							else
							{
								Material.SetR(0);
								Material.SetG(0);
								Material.SetB(0);
							}
						}
					}
#else
					FVoxelEditorDetailsUtils::ShowError(LOCTEXT("VoxelColorDisabled", "Error: MaterialConfig == RGB but ENABLE_VOXELCOLORS == 0"));
#endif
				}
				else
				{
					for (int X = 0; X < Component->ComponentSizeQuads; X++)
					{
						for (int Y = 0; Y < Component->ComponentSizeQuads; Y++)
						{
							int Index = (Component->SectionBaseX + X) + Width * (Component->SectionBaseY + Y);
							int LocalIndex = X + WeightmapSize * Y;

							FVoxelMaterial& Material = Data->Materials[Index];
							if (Weightmaps.Num() > 0)
							{
								uint8 MaxValue = Weightmaps[0].Weightmap[LocalIndex];
								uint8 MaxIndex = Weightmaps[0].Index;
								for (int WeightmapIndex = 1; WeightmapIndex < Weightmaps.Num(); WeightmapIndex++)
								{
									auto& Weightmap = Weightmaps[WeightmapIndex];

									uint8 Value = Weightmap.Weightmap[LocalIndex];
									if (Value > MaxValue)
									{
										MaxValue = Value;
										MaxIndex = Weightmap.Index;
									}
								}

								Material.SetIndex(MaxIndex);
							}
							else
							{
								Material.SetIndex(0);
							}
						}
					}
				}
			}

			for (int X = 0; X < Component->ComponentSizeQuads; X++)
			{
				for (int Y = 0; Y < Component->ComponentSizeQuads; Y++)
				{
					FVector Vertex = DataInterface.GetWorldVertex(X, Y);
					FVector LocalVertex = (Vertex - Importer->Landscape->GetActorLocation()) / Component->GetComponentTransform().GetScale3D();
					Data->SetHeight(LocalVertex.X, LocalVertex.Y, Vertex.Z);
				}
			}
		}

		Asset->SetData(Data);

		return true;
	});

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
