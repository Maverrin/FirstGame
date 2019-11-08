// Copyright 2018 Phyronnaz

#include "VoxelTools/VoxelAssetTools.h"
#include "VoxelWorld.h"
#include "VoxelLogStatDefinitions.h"
#include "VoxelTools/VoxelTools.h"
#include "VoxelData/VoxelData.h"
#include "Engine/Engine.h"

DECLARE_CYCLE_STAT(TEXT("UVoxelAssetTools::ImportAsset"), STAT_UVoxelAssetTools_ImportAsset, STATGROUP_Voxel);

template<bool bSmartImport, bool bAdd>
inline void ImportAssetImplInternal(
	FVoxelData* Data, 
	const FVoxelDataAssetData& AssetData, 
	const FIntBox& Bounds, 
	bool bImportValues, 
	bool bImportMaterials)
{
	const FIntVector Size = Bounds.Size();
	check(Size == AssetData.Size);

	TArray<FVoxelValue> Values;
	TArray<FVoxelMaterial> Materials;
	if (bImportValues || bSmartImport)
	{
		Values.SetNumUninitialized(Size.X * Size.Y * Size.Z);
	}
	if (bImportMaterials)
	{
		Materials.SetNumUninitialized(Size.X * Size.Y * Size.Z);
	}

	{
		FVoxelScopeSetLock Lock(Data, Bounds);
		const FIntVector& CoordOffset = Bounds.Min;
		if (bImportValues)
		{
			Data->SetValueOrMaterialLambda<FVoxelValue>(Bounds, [&](int GX, int GY, int GZ, FVoxelValue& OldValue)
			{
				int LX = GX - CoordOffset.X;
				int LY = GY - CoordOffset.Y;
				int LZ = GZ - CoordOffset.Z;
				const FVoxelValue& NewValue = AssetData.GetValue(LX, LY, LZ);
				if (!bSmartImport)
				{
					OldValue = NewValue;
				}
				else
				{
					if (bAdd)
					{
						if (!NewValue.IsEmpty() || (OldValue.IsEmpty() && !NewValue.IsTotallyEmpty()))
						{
							OldValue = NewValue;
						}
					}
					else
					{
						if (NewValue.IsEmpty() || (!OldValue.IsEmpty() && !NewValue.IsTotallyFull()))
						{
							OldValue = NewValue;
						}
					}
				}
			});
		}
		if (bImportMaterials)
		{
			Data->SetValueOrMaterialLambda<FVoxelMaterial>(Bounds, [&](int GX, int GY, int GZ, FVoxelMaterial& OldMaterial)
			{
				int LX = GX - CoordOffset.X;
				int LY = GY - CoordOffset.Y;
				int LZ = GZ - CoordOffset.Z;
				const FVoxelValue& NewValue = AssetData.GetValue(LX, LY, LZ);
				const FVoxelMaterial& NewMaterial = AssetData.GetMaterial(LX, LY, LZ);
				if (!bSmartImport)
				{
					OldMaterial = NewMaterial;
				}
				else
				{
					if (bAdd)
					{
						if (!NewValue.IsEmpty())
						{
							OldMaterial = NewMaterial;
						}
					}
					else
					{
						if (NewValue.IsEmpty())
						{
							OldMaterial = NewMaterial;
						}
					}
				}
			});
		}
	}
}

inline void ImportAssetImpl(
	bool bSmartImport,
	bool bAdd,
	FVoxelData* Data,
	const FVoxelDataAssetData& AssetData,
	const FIntBox& Bounds,
	bool bImportValues,
	bool bImportMaterials)
{
	if (bSmartImport)
	{
		if (bAdd)
		{
			ImportAssetImplInternal<true, true>(Data, AssetData, Bounds, bImportValues, bImportMaterials);
		}
		else
		{
			ImportAssetImplInternal<true, false>(Data, AssetData, Bounds, bImportValues, bImportMaterials);
		}
	}
	else
	{
		if (bAdd)
		{
			ImportAssetImplInternal<false, true>(Data, AssetData, Bounds, bImportValues, bImportMaterials);
		}
		else
		{
			ImportAssetImplInternal<false, false>(Data, AssetData, Bounds, bImportValues, bImportMaterials);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

inline int GetOffset(EVoxelAssetPositionOffset Offset, int Min, int Max)
{
	switch (Offset)
	{
	case EVoxelAssetPositionOffset::PositionIsMin:
		return Min;
	case EVoxelAssetPositionOffset::PositionIsMiddle:
		return FMath::RoundToInt(float(Min + Max) / 2.f);
	case EVoxelAssetPositionOffset::PositionIsMax:
	default:
		return Max;
	}
}

inline FIntBox GetBoundsWithOffset(
	const FIntVector& Size,
	const FIntVector& Position,
	EVoxelAssetPositionOffset OffsetX,
	EVoxelAssetPositionOffset OffsetY,
	EVoxelAssetPositionOffset OffsetZ)
{
	FIntVector Offset;
	Offset.X = GetOffset(OffsetX, 0, Size.X);
	Offset.Y = GetOffset(OffsetY, 0, Size.Y);
	Offset.Z = GetOffset(OffsetZ, 0, Size.Z);
	return FIntBox(Position - Offset, Position - Offset + Size);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelImportAssetAsyncWork::DoWork()
{
	ImportAssetImpl(
		bSmartImport, 
		bAdd, 
		Data.Get(),
		AssetData.Get(), 
		Bounds, 
		bImportValues, 
		bImportMaterials);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void UVoxelAssetTools::ImportAsset(
	AVoxelWorld* World,
	UVoxelDataAsset* Asset,
	const FIntVector& Position,
	EVoxelAssetPositionOffset OffsetX,
	EVoxelAssetPositionOffset OffsetY,
	EVoxelAssetPositionOffset OffsetZ,
	bool bImportValues,
	bool bImportMaterials,
	bool bSmartImport,
	EVoxelAssetSmartImportType SmartImportType)
{
	SCOPE_CYCLE_COUNTER(STAT_UVoxelAssetTools_ImportAsset);

	CHECK_WORLD_VOXELTOOLS(ImportAsset);

	if (!Asset)
	{
		FMessageLog("PIE").Error(FText::FromString("ImportAsset: Asset is NULL"));
		return;
	}
	
	auto AssetData = Asset->GetData();
	FIntBox Bounds = GetBoundsWithOffset(Asset->GetSize(), Position, OffsetX, OffsetY, OffsetZ);
	ImportAssetImpl(
		bSmartImport, 
		SmartImportType == EVoxelAssetSmartImportType::Add, 
		World->GetData(), 
		AssetData.Get(), 
		Bounds, 
		bImportValues, 
		bImportMaterials);
	World->UpdateChunksOverlappingBox(Bounds, true);
}

void UVoxelAssetTools::ImportAssetAsync(
	UObject* WorldContextObject,
    FLatentActionInfo LatentInfo,
	AVoxelWorld* World,
	UVoxelDataAsset* Asset,
	const FIntVector& Position,
	EVoxelAssetPositionOffset OffsetX,
	EVoxelAssetPositionOffset OffsetY, 
	EVoxelAssetPositionOffset OffsetZ,
	bool bImportValues,
	bool bImportMaterials,
	bool bSmartImport, 
	EVoxelAssetSmartImportType SmartImportType)
{
	CHECK_WORLD_VOXELTOOLS(ImportAssetAsync);

	if (!Asset)
	{
		FMessageLog("PIE").Error(FText::FromString("ImportAsset: Asset is NULL"));
		return;
	}

	if (UWorld* ObjectWorld = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = ObjectWorld->GetLatentActionManager();
		if (!LatentActionManager.FindExistingAction<FVoxelLatentAction<FVoxelImportAssetAsyncWork>>(LatentInfo.CallbackTarget, LatentInfo.UUID))
		{
			auto AssetData = Asset->GetData();
			FIntBox Bounds = GetBoundsWithOffset(Asset->GetSize(), Position, OffsetX, OffsetY, OffsetZ);
			TSharedPtr<FVoxelImportAssetAsyncWork> Task = MakeShared<FVoxelImportAssetAsyncWork>(
				World, 
				bSmartImport,
				SmartImportType == EVoxelAssetSmartImportType::Add,
				AssetData,
				Bounds,
				bImportValues,
				bImportMaterials);
			auto* Pool = World->GetPool()->AsyncTasksPool;
			Pool->AddQueuedWork(Task.Get());

			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FVoxelLatentAction<FVoxelImportAssetAsyncWork>(
				Task, 
				LatentInfo, 
				"ImportAsset: Waiting for completion",
				[=](FVoxelImportAssetAsyncWork& Work)
				{
					Work.World->UpdateChunksOverlappingBox(Work.Bounds, true);
				}
			));
		}
	}
}

