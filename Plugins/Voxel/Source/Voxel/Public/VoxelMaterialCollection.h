// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialFunction.h"
#include "VoxelMaterialCollection.generated.h"

struct FVoxelBlendedMaterial;
class UTexture;
class UMaterialInstanceDynamic;
class UPhysicalMaterial;
class UMaterialInstanceConstant;

USTRUCT(BlueprintType)
struct VOXEL_API FVoxelMaterialCollectionDoubleIndex
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Config")
	int I;
	UPROPERTY(EditAnywhere, Category = "Config")
	int J;

	FVoxelMaterialCollectionDoubleIndex() {}
	FVoxelMaterialCollectionDoubleIndex(int I, int J)
		: I(I)
		, J(J)
	{
		check(I < J);
	}

	inline bool operator==(const FVoxelMaterialCollectionDoubleIndex& Other) const
	{
		return I == Other.I && J == Other.J;
	}
};

inline uint32 GetTypeHash(const FVoxelMaterialCollectionDoubleIndex& O)
{
	return O.I ^ O.J;
}

USTRUCT(BlueprintType)
struct VOXEL_API FVoxelMaterialCollectionTripleIndex
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Config")
	int I;
	UPROPERTY(EditAnywhere, Category = "Config")
	int J;
	UPROPERTY(EditAnywhere, Category = "Config")
	int K;

	FVoxelMaterialCollectionTripleIndex() {}
	FVoxelMaterialCollectionTripleIndex(int I, int J, int K)
		: I(I)
		, J(J)
		, K(K)
	{
		check(I < J && J < K);
	}

	inline bool operator==(const FVoxelMaterialCollectionTripleIndex& Other) const
	{
		return I == Other.I && J == Other.J && K == Other.K;
	}
};

inline uint32 GetTypeHash(const FVoxelMaterialCollectionTripleIndex& O)
{
	return O.I ^ O.J ^ O.K;
}

///////////////////////////////////////////////////////////////////////////////

USTRUCT()
struct FVoxelMaterialCollectionElementIndex
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Voxel", meta = (DisplayName = "Index"))
	uint8 InstanceIndex;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	UMaterialInstanceConstant* MaterialInstance;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	UPhysicalMaterial* PhysicalMaterial;
};

USTRUCT()
struct FVoxelMaterialCollectionElement
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere, Category = "Voxel")
	uint8 Index;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	UMaterialFunction* MaterialFunction;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	UPhysicalMaterial* PhysicalMaterial;
	
	UPROPERTY(EditAnywhere, Category = "Voxel", meta = (DisplayName = "Instances"))
	TArray<FVoxelMaterialCollectionElementIndex> Children;
};

UCLASS(BlueprintType)
class VOXEL_API UVoxelMaterialCollection : public UObject
{
	GENERATED_BODY()
		
public:
	UPROPERTY(EditAnywhere, Category = "General")
	bool bEnableTessellation;

public:
	UPROPERTY(EditAnywhere, Category = "Templates")
	UMaterial* SingleMaterialTemplate;

	UPROPERTY(EditAnywhere, Category = "Templates")
	UMaterial* DoubleMaterialTemplate;

	UPROPERTY(EditAnywhere, Category = "Templates")
	UMaterial* TripleMaterialTemplate;

public:
	UPROPERTY(EditAnywhere, Category = "Layers")
	TArray<FVoxelMaterialCollectionElement> Materials;

	UPROPERTY()
	TArray<UMaterialFunction*> MaterialFunctions_DEPRECATED;

	UPROPERTY()
	TArray<UPhysicalMaterial*> PhysicalMaterials_DEPRECATED;

public:
	UPROPERTY()
	TMap<uint8, UMaterialInterface*> GeneratedSingleMaterials;

	UPROPERTY()
	TMap<FVoxelMaterialCollectionDoubleIndex, UMaterialInterface*> GeneratedDoubleMaterials;

	UPROPERTY()
	TMap<FVoxelMaterialCollectionTripleIndex, UMaterialInterface*> GeneratedTripleMaterials;

public:
	UPROPERTY()
	TMap<uint8, UMaterialInterface*> GeneratedSingleMaterialsTess;

	UPROPERTY()
	TMap<FVoxelMaterialCollectionDoubleIndex, UMaterialInterface*> GeneratedDoubleMaterialsTess;

	UPROPERTY()
	TMap<FVoxelMaterialCollectionTripleIndex, UMaterialInterface*> GeneratedTripleMaterialsTess;

public:
	UMaterialInterface* GetVoxelMaterial(const FVoxelBlendedMaterial& Index);
	UMaterialInterface* GetVoxelMaterialWithTessellation(const FVoxelBlendedMaterial& Index);

protected:
	virtual void PostLoad() override
	{
		Super::PostLoad();

		if (MaterialFunctions_DEPRECATED.Num() > 0)
		{
			for (int Index = 0; Index < MaterialFunctions_DEPRECATED.Num(); Index++)
			{
				int Last = Materials.Emplace();
				auto& NewMaterial = Materials[Last];
				NewMaterial.Index = Index;
				NewMaterial.MaterialFunction = MaterialFunctions_DEPRECATED[Index];
				if (PhysicalMaterials_DEPRECATED.IsValidIndex(Index))
				{
					NewMaterial.PhysicalMaterial = PhysicalMaterials_DEPRECATED[Index];
				}
			}
		}
	}
};