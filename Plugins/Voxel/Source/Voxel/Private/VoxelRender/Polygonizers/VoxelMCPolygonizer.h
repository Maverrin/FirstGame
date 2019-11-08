// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelDirection.h"
#include "VoxelGlobals.h"
#include "VoxelMaterial.h"
#include "VoxelValue.h"
#include "VoxelData/VoxelData.h"
#include "VoxelRender/VoxelIntermediateChunk.h"
#include "VoxelConfigEnums.h"
#include "VoxelDebug/VoxelStats.h"
// TODO: Make private
// Return the smallest multiple N of y such that:
//   x <= y * N
#define CEILING(x,y) (((x) + (y) - 1) / (y))

// A cube is 4x4x4 values, with last positions overlapping with next one ("owning" 3x3x3 values)
#define BYTE_COUNT (CEILING(CHUNK_SIZE + 1, 8))

// +1: for end edge, +2: for normals
#define MC_EXTENDED_CHUNK_SIZE (CHUNK_SIZE + 3)

#define EDGE_INDEX_COUNT 4

class FVoxelMCPolygonizer
{
public:
	FVoxelMCPolygonizer(int LOD, FVoxelData* Data, const FIntVector& ChunkPosition, EVoxelNormalConfig NormalConfig, EVoxelMaterialConfig MaterialConfig, EVoxelUVConfig UVConfig, FVoxelMeshProcessingParameters MeshParameters);
	~FVoxelMCPolygonizer();

	bool CreateChunk(FVoxelChunk& OutChunk, FVoxelStatsElement& Stats);
	
	// For NormalImpl
	inline FVoxelValue GetValue(int X, int Y, int Z, const FVoxelMap& Map) const;

private:
	const int LOD;
	// Step between cubes
	const int Step;
	const int Size;
	FVoxelData* const Data;
	const FIntVector ChunkPosition;
	const EVoxelNormalConfig NormalConfig;
	const EVoxelMaterialConfig MaterialConfig;
	const EVoxelUVConfig UVConfig;
	const FVoxelMeshProcessingParameters MeshParameters;

	FVoxelMap Map;

	FVoxelValue CachedValues[MC_EXTENDED_CHUNK_SIZE * MC_EXTENDED_CHUNK_SIZE * MC_EXTENDED_CHUNK_SIZE];
	FVoxelMaterial* CachedMaterials; // Only if LOD == 0

	// Cache to get index of already created vertices
	int Cache0[CHUNK_SIZE * CHUNK_SIZE * EDGE_INDEX_COUNT];
	int Cache1[CHUNK_SIZE * CHUNK_SIZE * EDGE_INDEX_COUNT];
	bool bCurrentCacheIs0 = false;

	inline int* GetCurrentCache() { return bCurrentCacheIs0 ? Cache0 : Cache1; }
	inline int* GetOldCache()     { return bCurrentCacheIs0 ? Cache1 : Cache0; }
	inline int GetCacheIndex(int EdgeIndex, int LX, int LY) const
	{
		checkVoxelSlow(0 <= LX && LX < CHUNK_SIZE);
		checkVoxelSlow(0 <= LY && LY < CHUNK_SIZE);
		checkVoxelSlow(0 <= EdgeIndex && EdgeIndex < EDGE_INDEX_COUNT);
		return EdgeIndex + LX * EDGE_INDEX_COUNT + LY * EDGE_INDEX_COUNT * CHUNK_SIZE;
	}

	void GetNormal(const FVector& Position, FVector& Result) const;
	inline FVoxelValue GetValueNoCache(int X, int Y, int Z) const
	{
		checkVoxelSlow(LOD > 0);
		return Data->GetValue(X + ChunkPosition.X, Y + ChunkPosition.Y, Z + ChunkPosition.Z, Map, LOD);
	}
	inline FVoxelMaterial GetMaterialNoCache(int X, int Y, int Z) const
	{
		checkVoxelSlow(LOD > 0);
		return Data->GetMaterial(X + ChunkPosition.X, Y + ChunkPosition.Y, Z + ChunkPosition.Z, Map, LOD);
	}	
	inline FVoxelMaterial GetMaterialNoCache(const FIntVector& P) const { return GetMaterialNoCache(P.X, P.Y, P.Z); }

private:	
	struct FLocalVoxelVertex
	{
		FVector Position;
		FVector GradientNormal;
		FVector NormalSum = FVector::ZeroVector;
		FVoxelMaterial Material = FVoxelMaterial(NoInit);
		FVector2D UVs;
		EVoxelNormalConfig VertexNormalConfig;
		bool bForceUseGradient = false;
		
		FLocalVoxelVertex(EVoxelNormalConfig VertexNormalConfig) : VertexNormalConfig(VertexNormalConfig) {}

		inline FVoxelProcMeshVertex GetProcMeshVertex() const
		{
			FVector Normal;
			if (VertexNormalConfig == EVoxelNormalConfig::GradientNormal || bForceUseGradient)
			{
				Normal = GradientNormal;
			}
			else if (VertexNormalConfig == EVoxelNormalConfig::MeshNormal)
			{
				Normal = NormalSum.GetSafeNormal();
			}
			else
			{
				check(VertexNormalConfig == EVoxelNormalConfig::NoNormal);
				Normal = FVector::ZeroVector;
			}

			return FVoxelProcMeshVertex(Position, Normal, FVoxelProcMeshTangent(), Material.GetColor(), UVs, Material.GetVoxelGrassId(), Material.GetVoxelActorId());
		}
	};
};

#define TRANSITION_EDGE_INDEX_COUNT 10

class FVoxelMCTransitionsPolygonizer
{
public:
	FVoxelMCTransitionsPolygonizer(int LOD, FVoxelData* Data, const FIntVector& ChunkPosition, uint8 TransitionsMask, EVoxelNormalConfig NormalConfig, EVoxelMaterialConfig MaterialConfig, EVoxelUVConfig UVConfig, FVoxelMeshProcessingParameters MeshParameters);

	bool CreateTransitions(FVoxelChunk& OutChunk, FVoxelStatsElement& Stats);

private:
	const int LOD;
	const int Step;
	const int Size;
	FVoxelData* const Data;
	const FIntVector ChunkPosition;
	const uint8 TransitionsMask;
	const EVoxelNormalConfig NormalConfig;
	const EVoxelMaterialConfig MaterialConfig;
	const EVoxelUVConfig UVConfig;
	const FVoxelMeshProcessingParameters MeshParameters;

	FVoxelMap Map;
	
	int Cache2D[CHUNK_SIZE * CHUNK_SIZE * TRANSITION_EDGE_INDEX_COUNT];
	inline int GetCacheIndex(int EdgeIndex, int LX, int LY) const
	{
		checkVoxelSlow(0 <= LX && LX < CHUNK_SIZE);
		checkVoxelSlow(0 <= LY && LY < CHUNK_SIZE);
		checkVoxelSlow(0 <= EdgeIndex && EdgeIndex < TRANSITION_EDGE_INDEX_COUNT);
		return EdgeIndex + LX * TRANSITION_EDGE_INDEX_COUNT + LY * TRANSITION_EDGE_INDEX_COUNT * CHUNK_SIZE;
	}

	void GetNormal(const FVector& Position, FVector& Result) const;

	inline FVoxelValue GetValue(EVoxelDirection Direction, int X, int Y) const
	{
		int GX, GY, GZ;
		Local2DToGlobal(Direction, X, Y, 0, GX, GY, GZ);

		return Data->GetValue(GX + ChunkPosition.X, GY + ChunkPosition.Y, GZ + ChunkPosition.Z, Map, LOD);
	}
	inline FVoxelMaterial GetMaterial(int X, int Y, int Z) const
	{
		return Data->GetMaterial(X + ChunkPosition.X, Y + ChunkPosition.Y, Z + ChunkPosition.Z, Map, LOD);
	}
	
	inline void Local2DToGlobal(EVoxelDirection Direction, int LX, int LY, int LZ, int& OutGX, int& OutGY, int& OutGZ) const
	{
		const int& S = Size;
		switch (Direction)
		{
		case XMin:
			OutGX = LZ;
			OutGY = LX;
			OutGZ = LY;
			break;
		case XMax:
			OutGX = S - LZ;
			OutGY = LY;
			OutGZ = LX;
			break;
		case YMin:
			OutGX = LY;
			OutGY = LZ;
			OutGZ = LX;
			break;
		case YMax:
			OutGX = LX;
			OutGY = S - LZ;
			OutGZ = LY;
			break;
		case ZMin:
			OutGX = LX;
			OutGY = LY;
			OutGZ = LZ;
			break;
		case ZMax:
			OutGX = LY;
			OutGY = LX;
			OutGZ = S - LZ;
			break;
		default:
			check(false);
			break;
		}
	}

private:
	struct FLocalVoxelVertex
	{
		FVector Position;
		FVector GradientNormal;
		FVoxelMaterial Material = FVoxelMaterial(NoInit);
		FVector2D UVs;
		EVoxelNormalConfig VertexNormalConfig;

		FLocalVoxelVertex(EVoxelNormalConfig VertexNormalConfig) : VertexNormalConfig(VertexNormalConfig) {}

		inline FVoxelProcMeshVertex GetProcMeshVertex() const
		{
			FVector Normal;
			if (VertexNormalConfig == EVoxelNormalConfig::GradientNormal || VertexNormalConfig == EVoxelNormalConfig::MeshNormal)
			{
				Normal = GradientNormal;
			}
			else
			{
				check(VertexNormalConfig == EVoxelNormalConfig::NoNormal);
				Normal = FVector::ZeroVector;
			}

			return FVoxelProcMeshVertex(Position, Normal, FVoxelProcMeshTangent(), Material.GetColor(), UVs, Material.GetVoxelGrassId(), Material.GetVoxelActorId());
		}
	};
};
