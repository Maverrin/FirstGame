// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelMaterial.h"
#include "IntBox.h"
#include "VoxelWorldGenerator.h"
#include "Serialization/BufferArchive.h"
#include "Serialization/MemoryReader.h"
#include "VoxelUtilities.h"
#include "VoxelLogStatDefinitions.h"
#include "Logging/MessageLog.h"
#include "VoxelHeightmapAsset.generated.h"

DECLARE_MEMORY_STAT(TEXT("Voxel Landscape Assets Memory"), STAT_VoxelLandscapeAssetMemory, STATGROUP_VoxelMemory);

template<typename T>
struct FVoxelLandscapeAssetData
{
	TArray<T> Heights;
	TArray<FVoxelMaterial> Materials;
	int Width;
	int Height;
	T MaxHeight = 0;
	T MinHeight = 0;

	///////////////////////////////////////////////////////////////////////////

	FVoxelLandscapeAssetData()
	{
		INC_DWORD_STAT_BY(STAT_VoxelLandscapeAssetMemory, GetAllocatedSize());
	}
	~FVoxelLandscapeAssetData()
	{
		DEC_DWORD_STAT_BY(STAT_VoxelLandscapeAssetMemory, GetAllocatedSize());
	}

	inline int GetAllocatedSize() const
	{
		return Heights.GetAllocatedSize() + Materials.GetAllocatedSize();
	}

	///////////////////////////////////////////////////////////////////////////

	inline void SetSize(int NewWidth, int NewHeight, bool bCreateMaterials)
	{
		DEC_DWORD_STAT_BY(STAT_VoxelLandscapeAssetMemory, GetAllocatedSize());

		Width = NewWidth;
		Height = NewHeight;
		Heights.SetNumUninitialized(NewWidth * NewHeight);
		Materials.SetNumUninitialized(bCreateMaterials ? NewWidth * NewHeight : 0);

		INC_DWORD_STAT_BY(STAT_VoxelLandscapeAssetMemory, GetAllocatedSize());
	}

	///////////////////////////////////////////////////////////////////////////

	inline int GetIndex(int X, int Y) const
	{
		return X + Width * Y;
	}
	inline bool IsValidIndex(int X, int Y) const
	{
		return (0 <= X && X < Width) && (0 <= Y && Y < Height);
	}
	inline bool HasMaterials() const { return Materials.Num() > 0; }

	///////////////////////////////////////////////////////////////////////////

	inline void SetHeight(int X, int Y, T NewHeight)
	{
		MaxHeight = FMath::Max(MaxHeight, NewHeight);
		MinHeight = FMath::Min(MinHeight, NewHeight);
		Heights[GetIndex(X, Y)] = NewHeight;
	}
	inline void SetMaterial(int X, int Y, int Z, const FVoxelMaterial& NewMaterial)
	{
		Materials[GetIndex(X, Y)] = NewMaterial;
	}

	///////////////////////////////////////////////////////////////////////////

	inline T GetHeight(int X, int Y) const
	{
		return Heights[GetIndex(X, Y)];
	}
	inline FVoxelMaterial GetMaterial(int X, int Y) const
	{
		return Materials[GetIndex(X, Y)];
	}
};

template<typename T>
class VOXEL_API FVoxelLandscapeAssetInstance : public FVoxelWorldGeneratorInstance
{
public:	
	const TSharedRef<FVoxelLandscapeAssetData<T>, ESPMode::ThreadSafe> Data;
	const int Precision;
	const float HeightMultiplier;
	const float HeightOffset;
	const float AdditionalThickness;
	const int ScaleMultiplier;
	const FIntBox AssetBounds;

	FVoxelLandscapeAssetInstance(
		const TSharedRef<FVoxelLandscapeAssetData<T>, ESPMode::ThreadSafe>& Data,
		int Precision,
		float HeightMultiplier,
		float HeightOffset,
		float AdditionalThickness,
		int ScaleMultiplier)
		: Data(Data)
		, Precision(Precision)
		, HeightMultiplier(HeightMultiplier)
		, HeightOffset(HeightOffset)
		, AdditionalThickness(AdditionalThickness)
		, ScaleMultiplier(ScaleMultiplier)
		, AssetBounds(
			FIntVector(
				0,
				0, 
				FMath::FloorToInt(-Precision + Data->MinHeight * HeightMultiplier + HeightOffset - AdditionalThickness)),
			FIntVector(
				Data->Width * ScaleMultiplier,
				Data->Height * ScaleMultiplier,
				FMath::CeilToInt(+Precision + Data->MaxHeight * HeightMultiplier + HeightOffset))
		)
	{
	}

	//~ Begin FVoxelWorldGeneratorInstance Interface
	void GetValuesAndMaterials(
		FVoxelValue Values[], 
		FVoxelMaterial Materials[],
		const FIntBox& Bounds, 
		const FIntVector& Offset, 
		int LOD, 
		const FIntVector& ArraySize, 
		int QueryLOD, 
		const FVoxelPlaceableItemHolder& ItemHolder) const final
	{
		const int Step = 1 << LOD;

		check(Bounds.IsMultipleOf(Step));

		for (int X = Bounds.Min.X; X < Bounds.Max.X; X += Step)
		{
			for (int Y = Bounds.Min.Y; Y < Bounds.Max.Y; Y += Step)
			{
				const int IndexX = X / ScaleMultiplier;
				const int IndexY = Y / ScaleMultiplier;

				if (Data->IsValidIndex(IndexX, IndexY))
				{
					const float Height = Data->GetHeight(IndexX, IndexY) * HeightMultiplier + HeightOffset;

					for (int Z = Bounds.Min.Z; Z < Bounds.Max.Z; Z += Step)
					{
						FVoxelValue Value;
						FVoxelMaterial Material;

						if (Values)
						{
							if (AssetBounds.IsInside(X, Y, Z))
							{
								if (Height > Z + Precision)
								{
									// If voxel over us is in, we're entirely in
									Value = FVoxelValue::Full;
								}
								else if (Height < Z - Precision)
								{
									// If voxel under us is out, we're entirely out
									Value = FVoxelValue::Empty;
								}
								else
								{
									Value = (Z - Height) / float(Precision);
								}
							}
							else
							{
								// Outside asset bounds
								Value = FVoxelValue::Empty;
							}
						}
						if (Materials)
						{
							Material = Data->HasMaterials() ? Data->GetMaterial(IndexX, IndexY) : FVoxelMaterial();
						}

						SetValueAndMaterial(Values, Materials, Offset, LOD, ArraySize, ItemHolder, X, Y, Z, Value, Material);
					}
				}
				else
				{
					for (int GZ = Bounds.Min.Z; GZ < Bounds.Max.Z; GZ += Step)
					{
						SetValueAndMaterial(Values, Materials, Offset, LOD, ArraySize, ItemHolder, X, Y, GZ, FVoxelValue::Empty, FVoxelMaterial());
					}
				}
			}
		}
	}

	EVoxelEmptyState IsEmpty(const FIntBox& Bounds, int LOD) const final
	{
		return !Bounds.Intersect(AssetBounds) ? EVoxelEmptyState::AllEmpty : EVoxelEmptyState::Unknown;
	}
	//~ End FVoxelWorldGeneratorInstance Interface

};

/**
 * Asset that holds 2D information.
 */
UCLASS(abstract, BlueprintType)
class VOXEL_API UVoxelHeightmapAsset : public UVoxelWorldGenerator 
{
	GENERATED_BODY()

public:
	// Higher precision can improve render quality, but voxel values are lower (hardness not constant)
	UPROPERTY(EditAnywhere, meta = (ClampMin = "1", UIMin = "1"), Category = "Voxel")
	int Precision = 4;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	float HeightMultiplier = 0;

	// In world size, applied after HeightMultiplier
	UPROPERTY(EditAnywhere, Category = "Voxel")
	float HeightOffset = 0;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	float AdditionalThickness = 0;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "1", UIMin = "1"), Category = "Voxel")
	int ScaleMultiplier = 1;

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	int GetWidth() const
	{
		return Width;
	}
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	int GetHeight() const
	{
		return Height;
	}

protected:
	template<typename T>
	inline void TryLoad(TSharedRef<FVoxelLandscapeAssetData<T>, ESPMode::ThreadSafe>& Data)
	{
		if (Data->Heights.Num() == 0)
		{
			// Seems invalid, try to load
			LoadData(Data);
		}
	}

	template<typename T>
	inline void SaveData(const TSharedRef<FVoxelLandscapeAssetData<T>, ESPMode::ThreadSafe>& Data)
	{
		Modify();

		Version = VMAX;
		ConfigFlags = GetVoxelConfigFlags();

		FBufferArchive Archive;
		
		Archive << Data->Heights;
		FVoxelUtilities::AddMaterialsToArchive(Data->Materials, Archive);
		Archive << Data->Width;
		Archive << Data->Height;
		Archive << Data->MaxHeight;
		Archive << Data->MinHeight;

		FVoxelUtilities::CompressData(Archive, CompressedData);

		SyncProperties(Data);
	}

	template<typename T>
	inline void LoadData(TSharedRef<FVoxelLandscapeAssetData<T>, ESPMode::ThreadSafe>& Data)
	{
		Data = MakeShared<FVoxelLandscapeAssetData<T>, ESPMode::ThreadSafe>();

		TArray<uint8> UncompressedData;
		if (!FVoxelUtilities::DecompressData(CompressedData, UncompressedData))
		{
			FMessageLog("PIE").Error(FText::FromString("VoxelHeightmapAsset: Load failed (asset: " + GetName() + ")"));
			return;
		}

		FMemoryReader Reader(UncompressedData);

		Reader << Data->Heights;
		FVoxelUtilities::GetMaterialsFromArchive(Data->Materials, Reader, ConfigFlags);
		Reader << Data->Width;
		Reader << Data->Height;
		Reader << Data->MaxHeight;
		if (Version >= V2)
		{
			Reader << Data->MinHeight;
		}

		SyncProperties(Data);
	}

	template<typename T>
	void SyncProperties(const TSharedRef<FVoxelLandscapeAssetData<T>, ESPMode::ThreadSafe>& Data)
	{
		// To access those properties without loading the asset
		Width = Data->Width;
		Height = Data->Height;
	}

protected:
	virtual void Serialize(FArchive& Ar) override
	{
		Super::Serialize(Ar);

		if (Ar.IsLoading() || Ar.IsSaving())
		{
			if (Version >= V1)
			{
				Ar << ConfigFlags;
				Ar << CompressedData;
			}
			else
			{
				Ar << CompressedData;
			}
		}
	}

private:
	enum EVersion : int
	{
		V0 = 0,
		V1 = 1,
		V2 = 2,
		VMAX = 2
	};
	
	UPROPERTY()
	int Version;

	UPROPERTY()
	int Width;
	UPROPERTY()
	int Height;

	uint32 ConfigFlags;
	TArray<uint8> CompressedData;
};

UCLASS(hidedropdown)
class VOXEL_API UVoxelHeightmapAssetFloat : public UVoxelHeightmapAsset
{
	GENERATED_BODY()

public:
	UVoxelHeightmapAssetFloat()
	{
		HeightMultiplier = 0.01f;
	}

	inline void SetData(TSharedRef<FVoxelLandscapeAssetData<float>, ESPMode::ThreadSafe> InData)
	{
		Data = InData;
		SaveData(Data);
	}
	inline TSharedRef<const FVoxelLandscapeAssetData<float>, ESPMode::ThreadSafe> GetData()
	{
		TryLoad(Data);
		return Data;
	}

	//~ Begin UVoxelWorldGenerator Interface
	TSharedRef<FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> GetWorldGenerator() override
	{
		TryLoad(Data);
		return MakeShared<FVoxelLandscapeAssetInstance<float>, ESPMode::ThreadSafe>(Data, Precision, HeightMultiplier, HeightOffset, AdditionalThickness, ScaleMultiplier);
	}
	//~ End UVoxelWorldGenerator Interface

private:
	TSharedRef<FVoxelLandscapeAssetData<float>, ESPMode::ThreadSafe> Data = MakeShared<FVoxelLandscapeAssetData<float>, ESPMode::ThreadSafe>();
};

UCLASS(hidedropdown)
class VOXEL_API UVoxelHeightmapAssetUINT16 : public UVoxelHeightmapAsset
{
	GENERATED_BODY()

public:
	UVoxelHeightmapAssetUINT16() 
	{
		HeightOffset = -32768 / 128.f;
		HeightMultiplier = 1.f / 128.f;
		AdditionalThickness = -HeightOffset;
	}

	inline void SetData(TSharedRef<FVoxelLandscapeAssetData<uint16>, ESPMode::ThreadSafe> InData)
	{
		Data = InData;
		SaveData(Data);
	}
	inline TSharedRef<const FVoxelLandscapeAssetData<uint16>, ESPMode::ThreadSafe> GetData()
	{
		TryLoad(Data);
		return Data;
	}

	//~ Begin UVoxelWorldGenerator Interface
	TSharedRef<FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> GetWorldGenerator() override
	{
		TryLoad(Data);
		return MakeShared<FVoxelLandscapeAssetInstance<uint16>, ESPMode::ThreadSafe>(Data, Precision, HeightMultiplier, HeightOffset, AdditionalThickness, ScaleMultiplier);
	}
	//~ End UVoxelWorldGenerator Interface


private:
	TSharedRef<FVoxelLandscapeAssetData<uint16>, ESPMode::ThreadSafe> Data = MakeShared<FVoxelLandscapeAssetData<uint16>, ESPMode::ThreadSafe>();
};
