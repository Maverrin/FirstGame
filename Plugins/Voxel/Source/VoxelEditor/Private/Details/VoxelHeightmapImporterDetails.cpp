// Copyright 2018 Phyronnaz

#include "VoxelHeightmapImporterDetails.h"
#include "VoxelImporters/VoxelHeightmapImporter.h"

#include "VoxelAssets/VoxelHeightmapAsset.h"
#include "Factories/VoxelHeightmapAssetFactory.h"

#include "LandscapeFileFormatInterface.h"
#include "LandscapeEditorModule.h"

#include "VoxelEditorDetailsUtils.h"
#include "VoxelGlobals.h"
#include "Misc/ScopedSlowTask.h"

#define LOCTEXT_NAMESPACE "VoxelHeightmapImporterDetails"

TSharedRef<IDetailCustomization> FVoxelHeightmapImporterDetails::MakeInstance()
{
	return MakeShareable(new FVoxelHeightmapImporterDetails());
}

void FVoxelHeightmapImporterDetails::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	Importer = FVoxelEditorDetailsUtils::GetCurrentObjectFromDetails<AVoxelHeightmapImporter>(DetailLayout);

	ADD_BUTTON_TO_CATEGORY(DetailLayout,
		"Create VoxelLandscapeAsset from Heightmap",
		LOCTEXT("Create", "Create"),
		LOCTEXT("CreateFromHeightmap", "Create From Heightmap"),
		LOCTEXT("Create", "Create"),
		this,
		&FVoxelHeightmapImporterDetails::OnCreateFromHeightmap)
}

///////////////////////////////////////////////////////////////////////////////

template<typename TLandscapeMapFileFormat> inline const TLandscapeMapFileFormat* GetFormat(const TCHAR* Extension, ILandscapeEditorModule& LandscapeEditorModule);

template<> inline const ILandscapeHeightmapFileFormat* GetFormat(const TCHAR* Extension, ILandscapeEditorModule& LandscapeEditorModule)
{
	return LandscapeEditorModule.GetHeightmapFormatByExtension(Extension);
}
template<> inline const ILandscapeWeightmapFileFormat* GetFormat(const TCHAR* Extension, ILandscapeEditorModule& LandscapeEditorModule)
{
	return LandscapeEditorModule.GetWeightmapFormatByExtension(Extension);
}

template<typename TLandscapeMapFileFormat, typename TLandscapeMapInfo> inline TLandscapeMapInfo Validate(const TCHAR* Filename, const TLandscapeMapFileFormat* Format);

template<> inline FLandscapeHeightmapInfo Validate(const TCHAR* Filename, const ILandscapeHeightmapFileFormat* Format)
{
	return Format->Validate(Filename);
}
template<> inline FLandscapeWeightmapInfo Validate(const TCHAR* Filename, const ILandscapeWeightmapFileFormat* Format)
{
	return Format->Validate(Filename, "");
}

template<typename TLandscapeMapImportData, typename TLandscapeMapFileFormat> inline TLandscapeMapImportData Import(const TCHAR* Filename, FLandscapeFileResolution ExpectedResolution, const TLandscapeMapFileFormat* Format);

template<> inline FLandscapeHeightmapImportData Import(const TCHAR* Filename, FLandscapeFileResolution ExpectedResolution, const ILandscapeHeightmapFileFormat* Format)
{
	return Format->Import(Filename, ExpectedResolution);
}
template<> inline FLandscapeWeightmapImportData Import(const TCHAR* Filename, FLandscapeFileResolution ExpectedResolution, const ILandscapeWeightmapFileFormat* Format)
{
	return Format->Import(Filename, "", ExpectedResolution);
}

///////////////////////////////////////////////////////////////////////////////

template<typename TLandscapeMapImportData, typename TLandscapeMapFileFormat, typename TLandscapeMapInfo>
bool GetMap(const FString& Filename, int& OutWidth, int& OutHeight, TLandscapeMapImportData& OutMapImportData)
{
	ILandscapeEditorModule& LandscapeEditorModule = FModuleManager::GetModuleChecked<ILandscapeEditorModule>("LandscapeEditor");
	FString Extension = FPaths::GetExtension(Filename, true);
	const TLandscapeMapFileFormat* Format = GetFormat<TLandscapeMapFileFormat>(*Extension, LandscapeEditorModule);

	if (!Format)
	{
		FVoxelEditorDetailsUtils::ShowError(FText::FromString("Error: Unknown extension " + Extension));
		return false;
	}

	TLandscapeMapInfo Info = Validate<TLandscapeMapFileFormat, TLandscapeMapInfo>(*Filename, Format);
	switch (Info.ResultCode)
	{
	case ELandscapeImportResult::Success:
		break;
	case ELandscapeImportResult::Warning:
	{
		if (!FVoxelEditorDetailsUtils::ShowWarning(Info.ErrorMessage))
		{
			return false;
		}
	}
	case ELandscapeImportResult::Error:
	{
		FVoxelEditorDetailsUtils::ShowError(Info.ErrorMessage);
		return false;
	}
	default: check(false);
	}

	OutWidth = Info.PossibleResolutions[0].Width;
	OutHeight = Info.PossibleResolutions[0].Height;
	OutMapImportData = Import<TLandscapeMapImportData, TLandscapeMapFileFormat>(*Filename, Info.PossibleResolutions[0], Format);

	switch (OutMapImportData.ResultCode)
	{
	case ELandscapeImportResult::Success:
		break;
	case ELandscapeImportResult::Warning:
	{
		if (!FVoxelEditorDetailsUtils::ShowWarning(Info.ErrorMessage))
		{
			return false;
		}
	}
	case ELandscapeImportResult::Error:
	{
		FVoxelEditorDetailsUtils::ShowError(Info.ErrorMessage);
		return false;
	}
	default: check(false);
	}

	return true;
}

bool GetHeightmap(const FString& Filename, int& OutWidth, int& OutHeight, FLandscapeHeightmapImportData& OutHeightmapImportData)
{
	return GetMap<FLandscapeHeightmapImportData, ILandscapeHeightmapFileFormat, FLandscapeHeightmapInfo>(Filename, OutWidth, OutHeight, OutHeightmapImportData);
}

bool GetWeightmap(const FString& Filename, int& OutWidth, int& OutHeight, FLandscapeWeightmapImportData& OutWeightmapImportData)
{
	return GetMap<FLandscapeWeightmapImportData, ILandscapeWeightmapFileFormat, FLandscapeWeightmapInfo>(Filename, OutWidth, OutHeight, OutWeightmapImportData);
}

///////////////////////////////////////////////////////////////////////////////

FReply FVoxelHeightmapImporterDetails::OnCreateFromHeightmap()
{
	struct FTempWeightmap
	{
		TArray<uint8> Data;
		EVoxelHeightmapImporterRGB Layer;
		uint8 Index;

		FTempWeightmap() = default;
	};

	if (!Importer.IsValid())
	{
		return FReply::Handled();
	}

	FVoxelEditorDetailsUtils::CreateAsset<UVoxelHeightmapAssetUINT16, UVoxelHeightmapAssetUINT16Factory>([&](UVoxelHeightmapAssetUINT16* Asset)
	{
		FScopedSlowTask Progress(4.f, LOCTEXT("CreatingAsset", "Creating heightmap asset..."));
 		Progress.MakeDialog(true, true);
		
		int Width, Height;
		FLandscapeHeightmapImportData HeightmapImportData;
		TArray<FTempWeightmap> Weightmaps;
		{
			Progress.EnterProgressFrame(0.5f, LOCTEXT("LoadingHeightmap", "Loading heightmap"));
			RETURN_IF_CANCEL();
			
			if (!GetHeightmap(Importer->Heightmap.FilePath, Width, Height, HeightmapImportData))
			{
				return false;
			}
			
			Progress.EnterProgressFrame(0.5f, LOCTEXT("LoadingWeightmaps", "Loading weightmaps"));
			RETURN_IF_CANCEL();

			Weightmaps.SetNum(Importer->Weightmaps.Num());
			for (int Index = 0; Index < Weightmaps.Num(); Index++)
			{
				auto& Weightmap = Weightmaps[Index];
				auto& WeightmapInfo = Importer->Weightmaps[Index];

				int WeightmapWidth;
				int WeightmapHeight;
				FLandscapeWeightmapImportData Result;
				if (!GetWeightmap(WeightmapInfo.File.FilePath, WeightmapWidth, WeightmapHeight, Result))
				{
					return false;
				}
				if (WeightmapWidth != Width || WeightmapHeight != Height)
				{
					FVoxelEditorDetailsUtils::ShowError(FText::Format(LOCTEXT("InvalidResolution", "Weightmap resolution is not the same as Heightmap ({0})"), FText::FromString(WeightmapInfo.File.FilePath)));
					return false;
				}
				Weightmap.Data = MoveTemp(Result.Data);
				Weightmap.Layer = WeightmapInfo.Layer;
				Weightmap.Index = WeightmapInfo.Index;
			}
		}

		RETURN_IF_CANCEL();

		TSharedRef<FVoxelLandscapeAssetData<uint16>, ESPMode::ThreadSafe> Data = MakeShared<FVoxelLandscapeAssetData<uint16>, ESPMode::ThreadSafe>();
		Data->SetSize(Width, Height, Weightmaps.Num() > 0);
		
		Progress.EnterProgressFrame(1.f, LOCTEXT("Heightmap", "Copying heightmap"));
		{
			FScopedSlowTask HeightmapProgress(Width * Height);
			for (uint32 Index = 0; Index < uint32(Width * Height); Index++)
			{
				if ((Index & 0x0000FFFF) == 0)
				{
					HeightmapProgress.EnterProgressFrame(0x0000FFFF);
					RETURN_IF_CANCEL();
				}
				uint16 NewHeight = HeightmapImportData.Data[Index];
				Data->Heights[Index] = NewHeight;
				Data->MaxHeight = FMath::Max(Data->MaxHeight, NewHeight);
			}
		}

		RETURN_IF_CANCEL();
		
		Progress.EnterProgressFrame(1.f, LOCTEXT("Weightmaps", "Copying weightmaps"));
		if (Data->HasMaterials())
		{
			FScopedSlowTask WeightmapProgress(Width * Height);
			if (Importer->MaterialConfig == EVoxelMaterialConfig::RGB)
			{
#if ENABLE_VOXELCOLORS
				for (uint32 Index = 0; Index < uint32(Width * Height); Index++)
				{
					if ((Index & 0x0000FFFF) == 0)
					{
						WeightmapProgress.EnterProgressFrame(0x0000FFFF);
						RETURN_IF_CANCEL();
					}
					FVoxelMaterial& Material = Data->Materials[Index];
					for (auto& Weightmap : Weightmaps)
					{
						uint8 Value = Weightmap.Data[Index];
						switch (Weightmap.Layer)
						{
						case EVoxelHeightmapImporterRGB::R:
							Material.SetR(Value);
							break;
						case EVoxelHeightmapImporterRGB::G:
							Material.SetG(Value);
							break;
						case EVoxelHeightmapImporterRGB::B:
							Material.SetB(Value);
							break;
						default: check(false);
						}
					}
				}
#else
				FVoxelEditorDetailsUtils::ShowError(LOCTEXT("VoxelColorDisabled", "Error: MaterialConfig == RGB but ENABLE_VOXELCOLORS == 0"));
#endif
			}
			else
			{
				for (uint32 Index = 0; Index < uint32(Width * Height); Index++)
				{
					if ((Index & 0x0000FFFF) == 0)
					{
						WeightmapProgress.EnterProgressFrame(0x0000FFFF);
						RETURN_IF_CANCEL();
					}
					FVoxelMaterial& Material = Data->Materials[Index];

					uint8 MaxValue = Weightmaps[0].Data[Index];
					uint8 MaxIndex = Weightmaps[0].Index;
					for (int WeightmapIndex = 1; WeightmapIndex < Weightmaps.Num(); WeightmapIndex++)
					{
						auto& Weightmap = Weightmaps[WeightmapIndex];
						uint8 Value = Weightmap.Data[Index];
						if (Value > MaxValue)
						{
							MaxValue = Value;
							MaxIndex = Weightmap.Index;
						}
					}

					Material.SetIndex(MaxIndex);
				}
			}
		}

		RETURN_IF_CANCEL();

		Progress.EnterProgressFrame(1.f, LOCTEXT("SavingAsset", "Saving asset"));

		Asset->SetData(Data);

		return true;
	});

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
