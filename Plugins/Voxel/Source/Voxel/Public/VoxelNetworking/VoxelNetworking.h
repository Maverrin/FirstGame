// Copyright 2018 Phyronnaz

#pragma once


#include "CoreMinimal.h"
#include "VoxelDiff.h"
#include "VoxelSave.h"
#include "VoxelNetworking/VoxelTcpSocket.h"

#define PACKET_SIZE_IN_DIFF 250

DECLARE_DELEGATE(FOnVoxelNetworkingServerConnection)

class AVoxelWorld;

/**
 * The client can only receive diffs and saves
 */
class FVoxelNetworkingClient
{
public:
	FVoxelNetworkingClient(FVoxelTcpSocket* Socket);
	~FVoxelNetworkingClient();

	/**
	 * Receive the diffs from the server. Must not be called when IsNextUpdateRemoteLoad is true
	 */
	bool ReceiveDiffQueues(TArray<TVoxelChunkDiff<FVoxelValue>>& OutValueDiffQueue, TArray<TVoxelChunkDiff<FVoxelMaterial>>& OutMaterialDiffQueue);

	/**
	 * Receive the save from the server. Must not be called when IsNextUpdateRemoteLoad is false
	 */
	void ReceiveSave(FVoxelCompressedWorldSave& OutSave);

	/**
	 * Is the connection valid?
	 */
	bool IsValid() const;

	/**
	 * Is the server sending the save?
	 */
	bool IsNextUpdateRemoteLoad();

	/**
	 * Check if headers has been received. Should be called before IsNextUpdateRemoteLoad
	 */
	void UpdateExpectedSize();

private:
	FVoxelTcpSocket* const Socket;

	bool bExpectedSizeUpToDate = false;
	uint32 ExpectedSize = 0;
	bool bNextUpdateIsRemoteLoad = false;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * The server can send the diffs and the saves
 */
class FVoxelNetworkingServer
{
public:
	FOnVoxelNetworkingServerConnection OnConnectionDelegate;
	
	FVoxelNetworkingServer(FVoxelTcpSocket* ServerSocket);
	~FVoxelNetworkingServer();

	/** Delegate */
	FOnVoxelNetworkingServerConnection& OnConnection();

	/**
	 * Has the server started?
	 */
	bool IsValid();

	/**
	 * Send the  diffs
	 */
	template<typename T>
	inline void SendDiffQueue(const TArray<TVoxelChunkDiff<T>>& DiffQueue) { T::unimplemented; }
	/**
	 * Send a world save
	 * @param	bOnlyToNewConnections	Only send save to the one that haven't synced yet
	 */
	void SendSave(FVoxelCompressedWorldSave& Save, bool bOnlyToNewConnections);

private:
	TArray<TSharedPtr<FVoxelTcpSocket>> Sockets;
	TArray<TSharedPtr<FVoxelTcpSocket>> SocketsToSendSave;
	FCriticalSection SocketsLock;
	FVoxelTcpSocket* const ServerSocket;

	void SendValuesDiffs(const TArray<TVoxelChunkDiff<FVoxelValue>>& DiffQueue);
	void SendMaterialsDiffs(const TArray<TVoxelChunkDiff<FVoxelMaterial>>& DiffQueue);
	template<typename T>
	void SendDiffs(const TArray<TVoxelChunkDiff<T>>& DiffList);

	/**
	 * Callback from the server
	 */
	void Accept(TSharedPtr<FVoxelTcpSocket> NewSocket);
};

template<> inline void FVoxelNetworkingServer::SendDiffQueue<FVoxelValue>(const TArray<TVoxelChunkDiff<FVoxelValue>>& DiffQueue) { SendValuesDiffs(DiffQueue); }
template<> inline void FVoxelNetworkingServer::SendDiffQueue<FVoxelMaterial>(const TArray<TVoxelChunkDiff<FVoxelMaterial>>& DiffQueue) { SendMaterialsDiffs(DiffQueue); }

