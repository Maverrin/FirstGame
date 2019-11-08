// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "PhysicsEngine/BodyInstance.h"

#include "VoxelValue.h"
#include "VoxelMaterial.h"
#include "IntBox.h"
#include "VoxelSave.h"
#include "VoxelSpawners/VoxelGrassSpawner.h"
#include "VoxelSpawners/VoxelActorSpawner.h"
#include "VoxelRender/VoxelRenderFactory.h"
#include "VoxelRender/VoxelIntermediateChunk.h"
#include "VoxelConfigEnums.h"
#include "VoxelWorldGeneratorPicker.h"
#include "VoxelWorldGenerator.h"
#include "VoxelUtilities.h"
#include "VoxelPoolManager.h"

#include "VoxelWorld.generated.h"

class IVoxelRender;
class FVoxelData;
class FVoxelActorOctreeManager;
class UVoxelInvokerComponent;
class AVoxelWorldEditorInterface;
class AVoxelActor;
class UVoxelMaterialCollection;
class FVoxelPool;
class UVoxelMaterialInterface;
class AVoxelChunksOwner;
struct FVoxelActorSpawnInfo;
class UCurveFloat;
class FVoxelActorComputedChunksOctree;
class UHierarchicalInstancedStaticMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClientConnection);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWorldLoaded);

/**
 * Voxel World actor class
 */
UCLASS()
class VOXEL_API AVoxelWorld : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnClientConnection OnClientConnection;

	UPROPERTY(BlueprintAssignable)
	FOnWorldLoaded OnWorldLoaded;

	UPROPERTY()
	FVoxelMaterialsRefHolder MaterialsRef;
		
public:
	AVoxelWorld();
	
public:
	void AddActorInfos(const TArray<FVoxelActorSpawnInfo>& ActorInfos);
	bool HaveActorsBeenCreated(const FIntBox& Bounds) const;
	void NotifyActorsAreCreated(const FIntBox& Bounds);
	
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void EnableFloatingActorsInArea(const FIntBox& Bounds, TArray<AVoxelActor*>& OutActors);
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void EnableActorsInArea(const FIntBox& Bounds, TArray<AVoxelActor*>& OutActors);
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	AVoxelActor* EnableInstanceInArea(UHierarchicalInstancedStaticMeshComponent* Component, const FIntBox& Bounds, int InstanceIndex);
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	UClass* GetActorClassFromHISM(UHierarchicalInstancedStaticMeshComponent* Component);
	
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void AddInstance(TSubclassOf<AVoxelActor> VoxelActorClass, FTransform Transform);
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void RemoveInstance(UHierarchicalInstancedStaticMeshComponent* Component, const FIntBox& Bounds, int InstanceIndex);

public:
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void CreateWorld();

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void DestroyWorld(bool bClearMeshes = true);

	// Create the world when in editor (not PIE)
	void CreateInEditor(UClass* VoxelWorldEditorClass);
	// Destroy the world when in editor (not PIE)
	void DestroyInEditor();

	void Recreate();

public:
	void UpdateCollisionProfile();

public:
	inline bool IsEditor() const { return PlayType == EPlayType::Editor; }
	inline TSharedRef<FVoxelData, ESPMode::ThreadSafe> GetDataSharedPtr() const { return Data.ToSharedRef(); }
	inline FVoxelData* GetData() const { return Data.Get(); }
	inline FVoxelPool* GetPool() const { return Pool.Get(); }
	inline UMaterialInstanceDynamic* GetMaterialInstance() const { return MaterialInstance; }
	inline const FVoxelWorldGeneratorPicker GetWorldGeneratorPicker() const { return WorldGenerator; }
	inline bool GetColorTransitions() const { return bColorTransitions; }
	FVoxelWorldGeneratorInit GetInitStruct() const;
	FVector GetChunkRelativePosition(const FIntVector& Position) const;

	inline bool IsTessellationEnabled(int InLOD) const
	{
		return GetEnableTessellation() && InLOD <= GetTessellationMaxLOD();
	}

	inline const TArray<TWeakObjectPtr<UVoxelInvokerComponent>>& GetInvokers() const { return Invokers; }
	inline bool IsDedicatedServer() const { return bIsDedicatedServer; }

	inline TSharedPtr<const FVoxelGrassSpawner_ThreadSafe, ESPMode::ThreadSafe> GetGrassSpawnerThreadSafe() const { return GrassSpawnerThreadSafe; }
	inline TSharedPtr<const FVoxelActorSpawner_ThreadSafe, ESPMode::ThreadSafe> GetActorSpawnerThreadSafe() const { return ActorSpawnerThreadSafe; }

	UMaterialInterface* GetVoxelMaterial(const FVoxelBlendedMaterial& Index) const;
	UMaterialInterface* GetVoxelMaterialWithTessellation(const FVoxelBlendedMaterial& Index) const;
	inline UMaterialInterface* GetVoxelMaterial(int InLOD, const FVoxelBlendedMaterial& Index) const
	{
		return IsTessellationEnabled(InLOD) ? GetVoxelMaterialWithTessellation(Index) : GetVoxelMaterial(Index);
	}
	inline UMaterialInterface* GetVoxelMaterial(int InLOD) const
	{
		auto* Result = IsTessellationEnabled(InLOD) ? GetVoxelMaterialWithTessellation() : GetVoxelMaterial();
		return Result ? Result : MissingMaterial;
	}
	
public:
	/** Set a MID scalar (float) parameter value */
	UFUNCTION(BlueprintCallable, meta=(Keywords = "SetFloatParameterValue"), Category="Rendering|Material")
	void SetScalarParameterValue(FName ParameterName, float Value);

	/** Set an MID texture parameter value */
	UFUNCTION(BlueprintCallable, Category="Rendering|Material")
	void SetTextureParameterValue(FName ParameterName, UTexture* Value);

	/** Set an MID vector parameter value */
	UFUNCTION(BlueprintCallable, meta=(Keywords = "SetColorParameterValue"), Category="Rendering|Material")
	void SetVectorParameterValue(FName ParameterName, FLinearColor Value);

public:
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void SetOctreeDepth(int NewDepth);
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	int GetOctreeDepth() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void SetOverrideBounds(bool bNewOverrideBounds);
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	bool GetOverrideBounds() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void SetWorldBounds(FIntBox NewWorldBounds);
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	FIntBox GetWorldBounds() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void SetLODLimit(int NewLODLimit);
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	int GetLODLimit() const;
	
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetChunkCullingLOD(int NewChunkCullingLOD);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	int GetChunkCullingLOD() const;
	
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void SetVoxelSize(float NewSize);
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	float GetVoxelSize() const;

	// CAN be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void SetVoxelMassMultiplierInKg(float NewVoxelMassMultiplierInKg);
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	float GetVoxelMassMultiplierInKg() const;	
	
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void SetWorldGeneratorObject(UVoxelWorldGenerator* NewGenerator);
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void SetWorldGeneratorClass(TSubclassOf<UVoxelWorldGenerator> NewGeneratorClass);

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void SetSaveObject(UVoxelWorldSaveObject* NewSaveObject);
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	UVoxelWorldSaveObject* GetSaveObject() const;
	
	// CAN be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void SetCreateWorldAutomatically(bool bNewCreateWorldAutomatically);
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	bool GetCreateWorldAutomatically() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void SetEnableUndoRedo(bool bNewEnableUndoRedo);
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	bool GetEnableUndoRedo() const;

	// CAN be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetWaitForOtherChunksToAvoidHoles(bool bNewWaitForOtherChunksToAvoidHoles);
	bool GetWaitForOtherChunksToAvoidHoles() const;
	
	// CANNOT be called when created. Add to existing seeds
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void AddSeeds(const TMap<FString, int>& NewSeeds);
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void AddSeed(FString Name, int Value);
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void ClearSeeds();
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	TMap<FString, int> GetSeeds() const;
	
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	void SetEnableWorldRebasing(bool bNewEnableWorldRebasing);
	UFUNCTION(BlueprintCallable, Category = "Voxel|General")
	bool GetEnableWorldRebasing() const;

///////////////////////////////////////////////////////////////////////////////
		
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetRenderType(EVoxelRenderType Type);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	EVoxelRenderType GetRenderType() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetUVConfig(EVoxelUVConfig Config);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	EVoxelUVConfig GetUVConfig() const;
	
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetNormalConfig(EVoxelNormalConfig Config);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	EVoxelNormalConfig GetNormalConfig() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetMaterialConfig(EVoxelMaterialConfig Config);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	EVoxelMaterialConfig GetMaterialConfig() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering", meta = (DisplayName = "Set VoxelWorld Material"))
	void SetVoxelMaterial(UMaterialInterface* NewMaterial);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering", meta = (DisplayName = "Get VoxelWorld Material"))
	UMaterialInterface* GetVoxelMaterial() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering", meta = (DisplayName = "Set VoxelWorld Material With Tessellation"))
	void SetVoxelMaterialWithTessellation(UMaterialInterface* NewMaterial);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering", meta = (DisplayName = "Get VoxelWorld Material With Tessellation"))
	UMaterialInterface* GetVoxelMaterialWithTessellation() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetMaterialCollection(UVoxelMaterialCollection* NewMaterialCollection);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	UVoxelMaterialCollection* GetMaterialCollection() const;
	
	// CAN be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetChunksFadeDuration(float NewChunksFadeDuration);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	float GetChunksFadeDuration() const;
	
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetEnableTessellation(bool NewEnableTessellation);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	bool GetEnableTessellation() const;
	
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetBoundsExtension(float NewBoundsExtension);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	float GetBoundsExtension() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetTessellationMaxLOD(int NewTessellationMaxLOD);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	int GetTessellationMaxLOD() const;
	
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetGrassSpawner(UVoxelGrassSpawner* Spawner);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	UVoxelGrassSpawner* GetGrassSpawner() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetActorSpawner(UVoxelActorSpawner* Spawner);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	UVoxelActorSpawner* GetActorSpawner() const;

	// CAN be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetMaxGrassChunkLOD(int NewMaxGrassChunkLOD);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	int GetMaxGrassChunkLOD() const;

	// CAN be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetMaxActorChunkLOD(int NewMaxActorChunkLOD);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	int GetMaxActorChunkLOD() const;
	
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetEnableGrassWhenEditing(bool bNewEnableGrassWhenEditing);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	bool GetEnableGrassWhenEditing() const;
	
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering", meta = (DisplayName = "Set Distance Between Actor HISM In Voxels"))
	void SetDistanceBetweenActorHISMInVoxels(int NewDistanceBetweenActorHISMInVoxels);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering", meta = (DisplayName = "Get Distance Between Actor HISM In Voxels"))
	int GetDistanceBetweenActorHISMInVoxels() const;
	
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	void SetLightingChannels(FLightingChannels NewLightingChannels);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Rendering")
	FLightingChannels GetLightingChannels() const;
	
///////////////////////////////////////////////////////////////////////////////
	
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Collisions")
	void SetMaxCollisionsLOD(int NewMaxCollisionsLOD);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Collisions")
	int GetMaxCollisionsLOD() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Collisions")
	void SetCollisionPresets(FBodyInstance NewCollisionPresets);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Collisions")
	FBodyInstance GetCollisionPresets() const;
		
///////////////////////////////////////////////////////////////////////////////
		
	// CAN be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Performance")
	void SetLODUpdateRate(float NewLODUpdateRate);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Performance")
	float GetLODUpdateRate() const;
	
	// CAN be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Performance")
	void SetActorCullingUpdateRate(float NewActorCullingUpdateRate);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Performance")
	float GetActorCullingUpdateRate() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Performance")
	void SetDontUseGlobalPool(bool bNewDontUseGlobalPool);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Performance")
	bool GetDontUseGlobalPool() const;

	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Performance")
	void SetMeshThreadCount(int NewMeshThreadCount);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Performance")
	int GetMeshThreadCount() const;

	// CAN be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Performance")
	void SetLODCurve(UCurveFloat* NewCurve);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Performance")
	UCurveFloat* GetLODCurve() const;

	// CAN be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Performance")
	void SetOptimizeIndices(bool bNewOptimizeIndices);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Performance")
	bool GetOptimizeIndices() const;
	
	
///////////////////////////////////////////////////////////////////////////////
	
	// CANNOT be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Multiplayer")
	void SetMultiplayer(bool bNewMultiplayer);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Multiplayer")
	bool GetMultiplayer() const;

	// CAN be called when created
	UFUNCTION(BlueprintCallable, Category = "Voxel|Multiplayer")
	void SetMultiplayerSyncRate(float NewMultiplayerSyncRate);
	UFUNCTION(BlueprintCallable, Category = "Voxel|Multiplayer")
	float GetMultiplayerSyncRate() const;
	
public:
	// Is this world created?
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	bool IsCreated() const;

	// Bounds of this world
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	FIntBox GetBounds() const;

	// Number of mesh processing tasks not finished
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	int32 GetTaskCount() const;

public:
	/**
	 * Convert position from world space to voxel space
	 * @param	Position	Position in world space
	 * @return	Position in voxel space
	 */
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	FIntVector GlobalToLocal(const FVector& Position) const;
	// Precision errors with large world offset
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	FVector GlobalToLocalFloat(const FVector& Position) const;

	/**
	 * Convert position from voxel space to world space
	 * @param	Position	Position in voxel space
	 * @return	Position in world space
	 */
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	FVector LocalToGlobal(const FIntVector& Position) const;
	// Precision errors with large world offset
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	FVector LocalToGlobalFloat(const FVector& Position) const;

	/**
	 * Get the 8 neighbors in voxel space of GlobalPosition
	 * @param	GlobalPosition	The position in world space
	 * @return	The 8 neighbors in voxel space 
	 */
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	TArray<FIntVector> GetNeighboringPositions(const FVector& GlobalPosition) const;

public:
	/**
	 * Add chunks at position to update queue
	 * @param	Position	Position in voxel space
	 */
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void UpdateChunksAtPosition(const FIntVector& Position);
	/**
	 * Add chunks overlapping box to update queue
	 * @param	Box			Box
	 */
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void UpdateChunksOverlappingBox(const FIntBox& Box, bool bRemoveHoles);
	void UpdateChunksOverlappingBox(const FIntBox& Box, TFunction<void()> CallbackWhenUpdated);
	/**
	 * Update all the chunks
	 */
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void UpdateAll();

public:
	// Get the render chunks LOD at Position
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	int GetLODAt(const FIntVector& Position) const;
	// Is position in this world?
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	bool IsInWorld(const FIntVector& Position) const;
		
	/**
	 * Is the position inside the world mesh? If false then it's outside, if true then it might inside
	 * @param	Position	Position in global space
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	bool IsInside(const FVector& Position) const;

	/**
	 * Get the intersection using voxel data. Doesn't depend on LOD. Useful for short distances, but really expensive for big ones
	 * @param	Start				The start of the raycast. The start and the end must have only one coordinate not in common
	 * @param	End					The end of the raycast. The start and the end must have only one coordinate not in common
	 * @param	GlobalPosition		The world position of the intersection if found
	 * @param	VoxelPosition		The voxel position of the intersection if found
	 * @return	Has intersected?
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	bool GetIntersection(const FIntVector& Start, const FIntVector& End, FVector& GlobalPosition, FIntVector& VoxelPosition) const;

	/**
	 * Get the normal at the voxel position Position using gradient. May differ from the mesh normal
	 * @param	Position	Position in voxel space
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	FVector GetNormal(const FIntVector& Position) const;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	float GetValue(const FIntVector& Position) const;
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void SetValue(const FIntVector& Position, float Value, bool bUpdateRender = true);
	
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	FVoxelMaterial GetMaterial(const FIntVector& Position) const;
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void SetMaterial(const FIntVector& Position, const FVoxelMaterial& Material, bool bUpdateRender = true);

public:
	/**
	 * Get a save of the current world
	 * @return	SaveArray
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	void GetSave(FVoxelUncompressedWorldSave& OutSave) const;
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	void GetCompressedSave(FVoxelCompressedWorldSave& OutSave) const;
	/**
	 * Load world from save
	 * @param	Save	Save to load from
	 * @param	bReset	Reset existing world? Set to false only if current world is unmodified
	 */
	UFUNCTION(BlueprintCallable, Category = "Voxel", meta = (AdvancedDisplay = "1"))
	void LoadFromSave(const FVoxelUncompressedWorldSave& Save);
	UFUNCTION(BlueprintCallable, Category = "Voxel", meta = (AdvancedDisplay = "1"))
	void LoadFromCompressedSave(UPARAM(ref) FVoxelCompressedWorldSave& Save);
	
public:	
	/**
	 * Connect to the server
	 * @param	Ip		The ip of the server
	 * @param	Port	The port of the server
	 */
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	bool ConnectClient(const FString& Ip = TEXT("127.0.0.1"), int32 Port = 10000);
	
	/**
	 * Start the server
	 * @param	Ip		The IP to accept connection. 0.0.0.0 to accept all
	 * @param	Port	The port of the server
	 */
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void StartServer(const FString& Ip = TEXT("0.0.0.0"), int32 Port = 10000);

public:
	// Undo last frame. bEnableUndoRedo must be true, and SaveFrame must have been called after any edits
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void Undo();
	// Redo last undone frame. bEnableUndoRedo must be true, and SaveFrame must have been called after any edits
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void Redo();
	// Save the edits since the last call to SaveFrame/Undo/Redo and clear the redo stack. bEnableUndoRedo must be true
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void SaveFrame();
	// Clear all the frames. bEnableUndoRedo must be true
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void ClearFrames();

public:
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	void DrawDebugIntBox(const FIntBox& Box, float Lifetime = 1, float Thickness = 10, FLinearColor Color = FLinearColor::Red) const;
	void DrawDebugIntBox(const FIntBox& Box, float Lifetime = 1, float Thickness = 10, FColor Color = FColor::Red, float BorderOffset = 0) const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	void DebugVoxelsInsideBox(FIntBox Box, FLinearColor Color = FLinearColor::Red, float Lifetime = 1, float Thickness = 1, bool bDebugDensities = true, FLinearColor TextColor = FLinearColor::Black) const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	void ClearCache(const TArray<FIntBox>& BoundsToKeepCached);
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Voxel")
	void Cache(const TArray<FIntBox>& BoundsToCache);

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void AddOffset(const FIntVector& OffsetInVoxels, bool bMoveActor = true);

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void AddWorms(float Radius = 25, int Seed = 2727, FVector RotationAmplitude = FVector(10, 10, 90), FVector NoiseDir = FVector(1, 1, 1), float NoiseSegmentLength = 10, FVector Start = FVector(0, 0,0), FVector InitialDir = FVector(1, 1, -1), float VoxelSegmentLength = 50, int NumSegments = 100, float SplitProbability = 0.1, float SplitProbabilityGain = 0.1, int BranchMeanSize = 25, int BranchSizeVariation = 10);

public:
	//~ Begin AActor Interface
	void BeginPlay() override;
	void EndPlay(EEndPlayReason::Type EndPlayReason) override;
	void Tick(float DeltaTime) override;
	void Serialize(FArchive& Ar) override;
	void ApplyWorldOffset(const FVector& InOffset, bool bWorldShift) override;
	void PostLoad() override;
#if WITH_EDITOR
	bool ShouldTickIfViewportsOnly() const override;
	bool CanEditChange(const UProperty* InProperty) const override;
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR
	//~ End AActor Interface

protected:
	// WorldSizeInVoxel = CHUNK_SIZE * 2^Depth. Has little impact on performance
	UPROPERTY(EditAnywhere, Category = "Voxel|General", meta = (ClampMin = "1", ClampMax = "25", UIMin = "1", UIMax = "25"))
	int OctreeDepth = 10;

	UPROPERTY()
	int LOD_DEPRECATED;

	// Size of an edge of the world
	UPROPERTY(EditAnywhere, Category = "Voxel|General", meta = (ClampMin = "1"))
	int WorldSizeInVoxel = FVoxelUtilities::GetSizeFromDepth<CHUNK_SIZE>(9);

	UPROPERTY(EditAnywhere, Category = "Voxel|General")
	bool bOverrideBounds = false;

	UPROPERTY(EditAnywhere, Category = "Voxel|General", meta = (ClampMax = "-1", EditCondition = "bOverrideBounds"))
	FIntBox WorldBounds;	

	// Chunks can't have a LOD higher than this. Useful is background has a too low resolution. WARNING: Don't set this too low, 5 under Octree Depth should be safe
	UPROPERTY(EditAnywhere, Category = "Voxel|General", meta = (ClampMin = "0", ClampMax = "25", UIMin = "0", UIMax = "25", DisplayName = "LOD Limit"))
	int LODLimit = MAX_WORLD_DEPTH - 1;

	// Chunks with a LOD strictly higher than this won't be rendered
	UPROPERTY(EditAnywhere, Category = "Voxel|General", meta = (ClampMin = "0", ClampMax = "25", UIMin = "0", UIMax = "25"))
	int ChunkCullingLOD = MAX_WORLD_DEPTH - 1;

	// Size of a voxel in cm
	UPROPERTY(EditAnywhere, Category = "Voxel|General")
	float VoxelSize = 100;

	// Mass in kg of a voxel (multiplied by its density)
	UPROPERTY(EditAnywhere, Category = "Voxel|General")
	float VoxelMassMultiplierInKg = 1;

	// Generator of this world
	UPROPERTY(EditAnywhere, Category = "Voxel|General")
	FVoxelWorldGeneratorPicker WorldGenerator;

	// Automatically loaded on creation
	UPROPERTY(EditAnywhere, Category = "Voxel|General")
	UVoxelWorldSaveObject* SaveObject = nullptr;

	UPROPERTY(EditAnywhere, Category = "Voxel|General")
	bool bCreateWorldAutomatically = false;

	// Keep all the changes in memory to enable undo/redo. Can be expensive
	UPROPERTY(EditAnywhere, Category = "Voxel|General")
	bool bEnableUndoRedo = false;

	// Less holes, but might look more laggy
	UPROPERTY(EditAnywhere, Category = "Voxel|General")
	bool bWaitForOtherChunksToAvoidHoles = true;

	UPROPERTY(EditAnywhere, Category = "Voxel|General", meta = (ClampMin = "1", UIMin = "1"))
	TMap<FString, int> Seeds;

	// If true, the voxel world will try to stay near its original coordinates when rebasing, and will offset the voxel coordinates instead
	UPROPERTY(EditAnywhere, Category = "Voxel|General")
	bool bEnableWorldRebasing = false;

	//////////////////////////////////////////////////////////////////////////////

	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering")
	EVoxelRenderType RenderType = EVoxelRenderType::MarchingCubes;

	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering")
	EVoxelUVConfig UVConfig = EVoxelUVConfig::GlobalUVs;
	
	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering")
	EVoxelNormalConfig NormalConfig = EVoxelNormalConfig::GradientNormal;
	
	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering")
	EVoxelMaterialConfig MaterialConfig = EVoxelMaterialConfig::RGB;

	// The material of the world
	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering", meta = (DisplayName = "VoxelWorld Material"))
	UMaterialInterface* VoxelMaterial = nullptr;

	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering", meta = (DisplayName = "VoxelWorld Material With Tessellation", EditCondition ="bEnableTessellation"))
	UMaterialInterface* VoxelMaterialWithTessellation = nullptr;

	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering")
	UVoxelMaterialCollection* MaterialCollection;

	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering")
	bool bEnableTessellation = false;

	// Increases the chunks bounding boxes, useful when using tessellation
	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering", meta = (EditCondition ="bEnableTessellation"))
	float BoundsExtension = 0;
	
	// Inclusive. Chunks with a LOD higher than that will use a non tessellated material
	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering", meta = (ClampMin = "0", ClampMax = "25", UIMin = "0", UIMax = "25", EditCondition ="bEnableTessellation"))
	int TessellationMaxLOD = 0;

	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering", meta = (ClampMin = "0", UIMin = "0"))
	float ChunksFadeDuration = 1;

	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering")
	UVoxelGrassSpawner* GrassSpawner = nullptr;
	
	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering")
	UVoxelActorSpawner* ActorSpawner = nullptr;
		
	// Chunks with a LOD higher than this won't have any grass
	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering", meta = (ClampMin = "0", UIMin = "0"))
	int MaxGrassChunkLOD = 0;
	
	// Chunks with a LOD higher than this won't have any actor spawned. Warning: setting this too high will create precision errors
	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering", meta = (ClampMin = "0", UIMin = "0"))
	int MaxActorChunkLOD = 0;

	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering")
	bool bEnableGrassWhenEditing = false;
	
	// Distance Between Actor Hierarchical Instanced Static Mesh Components In Voxels
	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering", meta = (DisplayName = "Distance Between Actor HISM In Voxels"))
	int DistanceBetweenActorHISMInVoxels = 256;

	UPROPERTY(EditAnywhere, Category = "Voxel|Rendering")
	FLightingChannels LightingChannels;
	
	//////////////////////////////////////////////////////////////////////////////

	// Max LOD to compute collisions on. Inclusive.
	UPROPERTY(EditAnywhere, Category = "Voxel|Collisions", meta = (ClampMin = "0", UIMin = "0"))
	int MaxCollisionsLOD = 3;

	UPROPERTY(EditAnywhere, Category = "Voxel|Collisions", meta = (ShowOnlyInnerProperties))
	FBodyInstance CollisionPresets;
	
	//////////////////////////////////////////////////////////////////////////////
	
	// Number of LOD update per second
	UPROPERTY(EditAnywhere, Category = "Voxel|Performance", meta = (ClampMin = "0.000001", UIMin = "0.000001"), DisplayName = "LOD Update Rate")
	float LODUpdateRate = 15;

	// Number of actor culling update per second
	UPROPERTY(EditAnywhere, Category = "Voxel|Performance", meta = (ClampMin = "0.000001", UIMin = "0.000001"))
	float ActorCullingUpdateRate = 1;

	UPROPERTY(EditAnywhere, Category = "Voxel|Performance")
	bool bDontUseGlobalPool = true;

	// Number of threads allocated for the mesh processing. Setting it too high may impact performance
	UPROPERTY(EditAnywhere, Category = "Voxel|Performance", meta = (ClampMin = "1", UIMin = "1", EditCondition = "bDontUseGlobalPool"))
	int MeshThreadCount = 2;
	
	// X = distance in voxels, Y = LOD (rounded up). Expensive, if you can leave it unset
	UPROPERTY(EditAnywhere, Category = "Voxel|Performance")
	UCurveFloat* LODCurve;
	
	// If true, the mesh indices will be sorted to improve GPU cache performance. Adds a cost to the async mesh building. If you don't see any perf difference, leave it off
	UPROPERTY(EditAnywhere, Category = "Voxel|Performance")
	bool bOptimizeIndices = false;
	
	//////////////////////////////////////////////////////////////////////////////

	// Is this world multiplayer?
	UPROPERTY(EditAnywhere, Category = "Voxel|Multiplayer")
	bool bMultiplayer = false;

	// Number of sync per second
	UPROPERTY(EditAnywhere, Category = "Voxel|Multiplayer", meta = (EditCondition = "bMultiplayer"))
	float MultiplayerSyncRate = 15;
	
	//////////////////////////////////////////////////////////////////////////////
	
public:
	UPROPERTY(EditAnywhere, Category = "Voxel|Debug")
	bool bShowWorldBounds = false;
	UPROPERTY(EditAnywhere, Category = "Voxel|Debug")
	bool bShowAllRenderChunks = false;
	UPROPERTY(EditAnywhere, Category = "Voxel|Debug")
	bool bColorTransitions = false;
	UPROPERTY(EditAnywhere, Category = "Voxel|Debug", meta = (EditCondition = "bShowWorldBounds"))
	float WorldBoundsThickness = 100;
	UPROPERTY(EditAnywhere, Category = "Voxel|Debug")
	bool bShowInvokersBounds = false;
	UPROPERTY(EditAnywhere, Category = "Voxel|Debug", meta = (EditCondition = "bShowInvokersBounds"))
	float InvokersBoundsThickness = 100;
	UPROPERTY(EditAnywhere, Category = "Voxel|Debug")
	bool bShowDataOctreeLeavesStatus = false;
	UPROPERTY(EditAnywhere, Category = "Voxel|Debug", meta = (EditCondition = "bShowDataOctreeLeavesStatus"))
	bool bHideEmptyDataOctreeLeaves = true;
	UPROPERTY(EditAnywhere, Category = "Voxel|Debug", meta = (EditCondition = "bShowDataOctreeLeavesStatus"))
	float DataOctreeLeavesThickness = 50;
	UPROPERTY(EditAnywhere, Category = "Voxel|Debug")
	bool bShowUpdatedChunks = false;
	UPROPERTY(EditAnywhere, Category = "Voxel|Debug", meta = (EditCondition = "bShowUpdatedChunks"))
	float UpdatedChunksThickness = 50;
	UPROPERTY(EditAnywhere, Category = "Voxel|Debug", meta = (EditCondition = "bMultiplayer"))
	bool bDebugMultiplayer = false;

private:
	UPROPERTY()
	UMaterialInterface* MissingMaterial;

	UPROPERTY(Transient)
	AVoxelWorldEditorInterface* VoxelWorldEditor;

	// Material to copy interp param from
	UPROPERTY(Transient)
	UMaterialInstanceDynamic* MaterialInstance;

	enum class EPlayType
	{
		Destroyed,
		Editor,
		Normal
	};
	EPlayType PlayType = EPlayType::Destroyed;

	FVoxelPoolRef Pool;	

	TSharedPtr<FVoxelData, ESPMode::ThreadSafe> Data;
	TSharedPtr<IVoxelRender> Render;
	TSharedPtr<class FVoxelCacheManager> CacheManager;
	
	bool bIsCreated = false;
	int InvokerComponentChangeVersion = -1;
	bool bWorldLoadAlreadyFinished = false;
	bool bIsDedicatedServer = false;

	FTimerHandle CacheDebugHandle;

	TArray<TWeakObjectPtr<UVoxelInvokerComponent>> Invokers;

	// Position of the voxel world actor in voxel space
	FIntVector WorldOffset = FIntVector::ZeroValue;

private:
	TSharedPtr<class FVoxelTcpSocket> Socket;

	TSharedPtr<class FVoxelNetworkingServer> NetworkServer;
	TSharedPtr<class FVoxelNetworkingClient> NetworkClient;

	FThreadSafeCounter OnClientConnectionTrigger;

	TSharedPtr<FVoxelGrassSpawner_ThreadSafe, ESPMode::ThreadSafe> GrassSpawnerThreadSafe;
	TSharedPtr<FVoxelActorSpawner_ThreadSafe, ESPMode::ThreadSafe> ActorSpawnerThreadSafe;

	float NextSyncTime = 0;
	float NextActorCullingUpdateTime = 0;

	TSharedPtr<FVoxelActorOctreeManager> ActorOctree;
	TSharedPtr<FVoxelActorComputedChunksOctree> ActorComputedChunksOctree;

private:
	// Create the world
	void CreateWorldInternal(
		EPlayType InPlayType,
		UVoxelGrassSpawner* InGrassSpawner,
		UVoxelActorSpawner* InActorSpawner,
		bool bInMultiplayer,
		bool bInEnableUndoRedo,
		bool bInDontUseGlobalPool);

	// Destroy the world
	void DestroyWorldInternal();

	// Receive data from server
	void ReceiveData();
	// Send data to clients
	void SendData();

	void TriggerOnClientConnection();
};

/**
 * Interface to use the VoxelWorldEditor in the VoxelEditor module
 */
UCLASS(notplaceable, HideCategories = ("Tick", "Replication", "Input", "Actor", "Rendering", "Hide"))
class VOXEL_API AVoxelWorldEditorInterface : public AActor
{
	GENERATED_BODY()

public:
	virtual void Init(TWeakObjectPtr<AVoxelWorld> NewWorld) {}
};