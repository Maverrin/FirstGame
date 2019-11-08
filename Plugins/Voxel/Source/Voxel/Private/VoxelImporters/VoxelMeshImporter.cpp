// Copyright 2018 Phyronnaz

#include "VoxelImporters/VoxelMeshImporter.h"

#include "Components/PrimitiveComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/StaticMesh.h"
#include "KismetProceduralMeshLibrary.h"
#include "VoxelAssets/VoxelDataAsset.h"
#include "VoxelUtilities.h"
#include "SDFGen/makelevelset3.h"

AVoxelMeshImporter::AVoxelMeshImporter()
	: VoxelSize(100)
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = MeshComponent;
};

void AVoxelMeshImporter::ImportToAsset(FVoxelDataAssetData& Asset, FIntVector& OutOffset)
{
	check(StaticMesh);

	StaticMesh->bAllowCPUAccess = true;

	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FProcMeshTangent> Tangents;
	UKismetProceduralMeshLibrary::GetSectionFromStaticMesh(StaticMesh, 0, 0, Vertices, Triangles, Normals, UVs, Tangents);

	std::vector<Vec3f> Vec3fVertices;
	std::vector<Vec3ui> Vec3uiTriangles;

	FBox Box(GetTransform().TransformPosition(Vertices[0]), GetTransform().TransformPosition(Vertices[1]));
	for (auto& Vertice : Vertices)
	{
		Vertice = GetTransform().TransformPosition(Vertice);
		Box += Vertice;
		Vec3fVertices.emplace_back(Vertice.X, Vertice.Y, Vertice.Z);
	}

	for (int I = 0; I < Triangles.Num(); I += 3)
	{
		Vec3uiTriangles.emplace_back(Triangles[I], Triangles[I + 1], Triangles[I + 2]);
	}

	FVector SizeFloat = Box.GetSize() / VoxelSize;
	const FIntVector Size(FMath::CeilToInt(SizeFloat.X), FMath::CeilToInt(SizeFloat.Y), FMath::CeilToInt(SizeFloat.Z));
	const Vec3f Origin(Box.Min.X, Box.Min.Y, Box.Min.Z);

	Array3f Result;
	make_level_set3(Vec3uiTriangles, Vec3fVertices, Origin, VoxelSize, Size.X, Size.Y, Size.Z, Result);
	
	OutOffset = FVoxelIntVector::RoundToInt((Box.Min - GetActorLocation()) / VoxelSize);
	Asset.SetSize(Size, false);

	for (int X = 0; X < Size.X; X++)
	{
		for (int Y = 0; Y < Size.Y; Y++)
		{
			for (int Z = 0; Z < Size.Z; Z++)
			{
				Asset.SetValue(X, Y, Z, FMath::Clamp(Result(X, Y, Z) / VoxelSize, -1.f, 1.f));
			}
		}
	}
}

#if WITH_EDITOR
void AVoxelMeshImporter::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	MeshComponent->SetStaticMesh(StaticMesh);
}
#endif

