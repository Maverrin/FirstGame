// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelWorldGenerator.h"
#include "VoxelLogStatDefinitions.h"
#include "Logging/MessageLog.h"
#include "Serialization/BufferArchive.h"
#include "Serialization/MemoryReader.h"
#include "VoxelGlobals.h"
#include "VoxelUtilities.h"
#include "VoxelDataAsset.generated.h"

DECLARE_MEMORY_STAT(TEXT("Voxel Data Assets Memory"), STAT_VoxelDataAssetMemory, STATGROUP_VoxelMemory);

struct VOXEL_API FVoxelDataAssetData
{
	FIntVector Size;
	TArray<FVoxelValue> Values;
	TArray<FVoxelMaterial> Materials;
	
	///////////////////////////////////////////////////////////////////////////

	FVoxelDataAssetData()
	{
		INC_DWORD_STAT_BY(STAT_VoxelDataAssetMemory, GetAllocatedSize());
	}
	~FVoxelDataAssetData()
	{
		DEC_DWORD_STAT_BY(STAT_VoxelDataAssetMemory, GetAllocatedSize());
	}
	
	///////////////////////////////////////////////////////////////////////////

	inline void SetSize(const FIntVector& NewSize, bool bCreateMaterials)
	{
		DEC_DWORD_STAT_BY(STAT_VoxelDataAssetMemory, GetAllocatedSize());

		Size = NewSize;
		Values.SetNumUninitialized(NewSize.X * NewSize.Y * NewSize.Z);
		Materials.SetNumUninitialized(bCreateMaterials ? NewSize.X * NewSize.Y * NewSize.Z : 0);
		
		INC_DWORD_STAT_BY(STAT_VoxelDataAssetMemory, GetAllocatedSize());
	}
	
	///////////////////////////////////////////////////////////////////////////

	inline int GetIndex(int X, int Y, int Z) const
	{
		checkVoxelSlow(0 <= X && X <= Size.X);
		checkVoxelSlow(0 <= Y && Y <= Size.Y);
		checkVoxelSlow(0 <= Z && Z <= Size.Z);
		return X + Size.X * Y + Size.X * Size.Y * Z;
	}
	inline bool IsValidIndex(int X, int Y, int Z) const
	{
		return (0 <= X && X < Size.X) &&
	     	   (0 <= Y && Y < Size.Y) &&
			   (0 <= Z && Z < Size.Z);
	}
	inline bool HasMaterials() const { return Materials.Num() > 0; }

	inline int GetAllocatedSize() const
	{
		return Values.GetAllocatedSize() + Materials.GetAllocatedSize();
	}

	///////////////////////////////////////////////////////////////////////////

	inline void SetValue(int X, int Y, int Z, FVoxelValue NewValue)
	{
		Values[GetIndex(X, Y, Z)] = NewValue;
	}
	inline void SetMaterial(int X, int Y, int Z, const FVoxelMaterial& NewMaterial)
	{
		Materials[GetIndex(X, Y, Z)] = NewMaterial;
	}

	///////////////////////////////////////////////////////////////////////////

	inline FVoxelValue GetValue(int X, int Y, int Z) const
	{
		return Values[GetIndex(X, Y, Z)];
	}
	inline FVoxelMaterial GetMaterial(int X, int Y, int Z) const
	{
		return Materials[GetIndex(X, Y, Z)];
	}
};

class VOXEL_API FVoxelDataAssetInstance : public FVoxelWorldGeneratorInstance
{
public:
	const TSharedRef<FVoxelDataAssetData, ESPMode::ThreadSafe> Data;
	const FIntVector Position;

	FVoxelDataAssetInstance(const TSharedRef<FVoxelDataAssetData, ESPMode::ThreadSafe>& Data, const FIntVector& Position)
		: Data(Data)
		, Position(Position)
	{
	}

	//~ Begin FVoxelAssetInstance Interface
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

		for (int GZ = Bounds.Min.Z; GZ < Bounds.Max.Z; GZ += Step)
		{
			int Z = GZ - Position.Z;
			for (int GY = Bounds.Min.Y; GY < Bounds.Max.Y; GY += Step)
			{
				int Y = GY - Position.Y;
				for (int GX = Bounds.Min.X; GX < Bounds.Max.X; GX += Step)
				{
					int X = GX - Position.X;

					FVoxelValue Value = FVoxelValue::Empty;
					FVoxelMaterial Material;

					if (Data->IsValidIndex(X, Y, Z))
					{
						int Index = Data->GetIndex(X, Y, Z);
						if (Values)
						{
							Value = Data->Values[Index];
						}
						if (Materials && Data->HasMaterials())
						{
							Material = Data->Materials[Index];
						}
					}

					SetValueAndMaterial(Values, Materials, Offset, LOD, ArraySize, ItemHolder, GX, GY, GZ, Value, Material);
				}
			}
		}
	}
	//~ End FVoxelAssetInstance Interface

	inline FIntBox GetWorldBounds() const
	{
		return FIntBox(Position, Position + Data->Size);
	}

	EVoxelEmptyState IsEmpty(const FIntBox& Bounds, int LOD) const final
	{
		return !Bounds.Intersect(GetWorldBounds()) ? EVoxelEmptyState::AllEmpty : EVoxelEmptyState::Unknown;
	}
};

/**
 * A Data Asset stores the values of every voxel inside it
 */
UCLASS(hidedropdown, BlueprintType)
class VOXEL_API UVoxelDataAsset : public UVoxelWorldGenerator
{
	GENERATED_BODY()

public:
	// Final position = Position + Offset
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel")
	FIntVector Position;
	// Final position = Position + Offset
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel")
	FIntVector Offset;

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	FIntVector GetSize() const
	{
		return Size;
	}

	inline void SetData(TSharedRef<FVoxelDataAssetData, ESPMode::ThreadSafe> InData)
	{
		Data = InData;
		Save();
	}
	inline TSharedRef<const FVoxelDataAssetData, ESPMode::ThreadSafe> GetData()
	{
		TryLoad();
		return Data;
	}

	//~ Begin UVoxelWorldGenerator Interface
	TSharedRef<FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> GetWorldGenerator() final
	{
		return GetAsset(Position);
	}
	//~ End UVoxelWorldGenerator Interface
	
	TSharedRef<FVoxelDataAssetInstance, ESPMode::ThreadSafe> GetAsset(const FIntVector& PositionOverride)
	{
		TryLoad();
		return MakeShared<FVoxelDataAssetInstance, ESPMode::ThreadSafe>(Data, Offset + PositionOverride);
	}

protected:
	virtual void Serialize(FArchive& Ar) override
	{
		Super::Serialize(Ar);

		if (Ar.IsLoading() || Ar.IsSaving())
		{
			if (Version >= V2)
			{
				Ar << ConfigFlags;
				Ar << CompressedData;
			}
		}
	}
	virtual void PostLoad() override
	{
		Super::PostLoad();
		if (CompressedData_DEPRECATED.Num() > 0)
		{
			Modify();
			ConfigFlags = EnableVoxelColors | EnableVoxelSpawnedActors | EnableVoxelGrass;
			CompressedData = CompressedData_DEPRECATED;
		}
	}

private:
	void TryLoad()
	{
		if (Data->Values.Num() == 0)
		{
			// Seems invalid, try to load
			Load();
		}
	}
	void Save()
	{
		Modify();

		Version = VMAX;
		ConfigFlags = GetVoxelConfigFlags();

		FBufferArchive Archive;

		Archive << Data->Size;
		Archive << Data->Values;
		FVoxelUtilities::AddMaterialsToArchive(Data->Materials, Archive);

		FVoxelUtilities::CompressData(Archive, CompressedData);

		SyncProperties();
	}
	void Load()
	{
		Data = MakeShared<FVoxelDataAssetData, ESPMode::ThreadSafe>();

		TArray<uint8> UncompressedData;
		if (!FVoxelUtilities::DecompressData(CompressedData, UncompressedData))
		{
			FMessageLog("PIE").Error(FText::FromString("VoxelDataAsset: Load failed (asset: " + GetName() + ")"));
			return;
		}

		FMemoryReader Reader(UncompressedData);

		if (V1 <= Version && Version < V_MoveOffsetFromDataToObject)
		{
			Reader << Offset;
		}
		Reader << Data->Size;
		Reader << Data->Values;
		FVoxelUtilities::GetMaterialsFromArchive(Data->Materials, Reader, ConfigFlags);
		
		SyncProperties();
	}
	void SyncProperties()
	{
		// To access those properties without loading the asset
		Size = Data->Size;
	}

	TSharedRef<FVoxelDataAssetData, ESPMode::ThreadSafe> Data = MakeShared<FVoxelDataAssetData, ESPMode::ThreadSafe>();

private:
	enum EVersion : int
	{
		V0 = 0,
		V1 = 1,
		V2 = 2,
		V_MoveOffsetFromDataToObject = 3,
		VMAX = 3
	};
	
	UPROPERTY()
	int Version;

	UPROPERTY()
	TArray<uint8> CompressedData_DEPRECATED;

	UPROPERTY()
	FIntVector Size;

	uint32 ConfigFlags;
	TArray<uint8> CompressedData;
};
