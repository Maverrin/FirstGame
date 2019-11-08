// Copyright 2018 Phyronnaz

#include "VoxelNetworking/VoxelNetworking.h"
#include "VoxelLogStatDefinitions.h"

#include "Serialization/ArchiveSaveCompressedProxy.h"
#include "Serialization/ArchiveLoadCompressedProxy.h"
#include "Engine.h"

DECLARE_CYCLE_STAT(TEXT("FVoxelTcpClient::ReceiveData"), STAT_FVoxelTcpClient_ReceiveData, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("FVoxelTcpServer::SendData"), STAT_FVoxelTcpServer_SendData, STATGROUP_Voxel);

FVoxelNetworkingClient::FVoxelNetworkingClient(FVoxelTcpSocket* InSocket)
	: Socket(InSocket)
{
	check(Socket);
}

FVoxelNetworkingClient::~FVoxelNetworkingClient()
{
	Socket->Destroy();
}

bool FVoxelNetworkingClient::ReceiveDiffQueues(TArray<TVoxelChunkDiff<FVoxelValue>>& OutValueDiffQueue, TArray<TVoxelChunkDiff<FVoxelMaterial>>& OutMaterialDiffQueue)
{
	SCOPE_CYCLE_COUNTER(STAT_FVoxelTcpClient_ReceiveData);

	check(!bNextUpdateIsRemoteLoad);

	if (Socket->IsValid())
	{
		if (bExpectedSizeUpToDate)
		{
			uint32 PendingDataSize = 0;
			if (Socket->HasPendingData(PendingDataSize))
			{
				if (PendingDataSize >= ExpectedSize)
				{
					TArray<uint8> ReceivedData;
					ReceivedData.SetNumUninitialized(ExpectedSize);

					int32 BytesRead = 0;
					Socket->Recv(ReceivedData.GetData(), ReceivedData.Num(), BytesRead);
					check(BytesRead == ExpectedSize);

					FArchiveLoadCompressedProxy Decompressor = FArchiveLoadCompressedProxy(ReceivedData, ECompressionFlags::COMPRESS_ZLIB);
					check(!Decompressor.GetError());

					//Decompress
					FBufferArchive DecompressedDataArray;
					Decompressor << DecompressedDataArray;

					FMemoryReader DecompressedData = FMemoryReader(DecompressedDataArray);

					bool bValues;
					uint32 ItemCount;
					DecompressedData << bValues;
					DecompressedData << ItemCount;

					check(ItemCount <= PACKET_SIZE_IN_DIFF);

					if (bValues)
					{
						for (uint32 i = 0; i < ItemCount; i++)
						{
							TVoxelChunkDiff<FVoxelValue> Diff;
							DecompressedData << Diff;
							OutValueDiffQueue.Add(Diff);
						}
					}
					else
					{
						for (uint32 i = 0; i < ItemCount; i++)
						{
							TVoxelChunkDiff<FVoxelMaterial> Diff;
							DecompressedData << Diff;
							OutMaterialDiffQueue.Add(Diff);
						}
					}

					bExpectedSizeUpToDate = false;
					UpdateExpectedSize();

					return true;
				}
			}
		}
	}
	else
	{
		UE_LOG(LogVoxel, Error, TEXT("Client not connected"));
	}

	return false;
}

void FVoxelNetworkingClient::ReceiveSave(FVoxelCompressedWorldSave& OutSave)
{
	check(bNextUpdateIsRemoteLoad);

	if (Socket->IsValid())
	{
		if (bExpectedSizeUpToDate)
		{
			uint32 PendingDataSize = 0;
			if (Socket->HasPendingData(PendingDataSize))
			{
				if (PendingDataSize >= ExpectedSize)
				{
					FBufferArchive ReceivedData(true);
					ReceivedData.SetNumUninitialized(ExpectedSize);

					int32 BytesRead = 0;
					Socket->Recv(ReceivedData.GetData(), ReceivedData.Num(), BytesRead);
					bool bSuccess = BytesRead == ExpectedSize;
					UE_LOG(LogVoxel, Log, TEXT("Remote load: Bytes to receive: %d. Bytes received: %d. Success: %d"), ExpectedSize, BytesRead, bSuccess);
					if (bSuccess)
					{

						FMemoryReader Reader(ReceivedData);
						OutSave.Serialize(Reader);

						bNextUpdateIsRemoteLoad = false;
						bExpectedSizeUpToDate = false;
						UpdateExpectedSize();
					}
					else
					{
						UE_LOG(LogVoxel, Error, TEXT("Remote load: Fail"));
					}
				}
				else
				{
					UE_LOG(LogVoxel, Error, TEXT("Remote load: Not enough data"));
				}
			}
			else
			{
				UE_LOG(LogVoxel, Error, TEXT("Remote load: No data"));
			}
		}
	}
	else
	{
		UE_LOG(LogVoxel, Error, TEXT("Client not connected"));
	}
}

bool FVoxelNetworkingClient::IsValid() const
{
	return Socket->IsValid();
}

bool FVoxelNetworkingClient::IsNextUpdateRemoteLoad()
{
	return bNextUpdateIsRemoteLoad;
}

void FVoxelNetworkingClient::UpdateExpectedSize()
{
	if (!bExpectedSizeUpToDate)
	{
		uint32 PendingDataSize = 0;
		if (Socket->HasPendingData(PendingDataSize))
		{
			if (PendingDataSize >= 5)
			{
				uint8 ReceivedData[5];

				int BytesRead;
				Socket->Recv(ReceivedData, 5, BytesRead);
				check(BytesRead == 5);

				ExpectedSize = ReceivedData[0] + 256 * (ReceivedData[1] + 256 * (ReceivedData[2] + 256 * ReceivedData[3]));
				bNextUpdateIsRemoteLoad = !!ReceivedData[4];

				bExpectedSizeUpToDate = true;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////

FVoxelNetworkingServer::FVoxelNetworkingServer(FVoxelTcpSocket* InServerSocket)
	: ServerSocket(InServerSocket)
{
	check(ServerSocket);
	ServerSocket->OnConnection.BindRaw(this, &FVoxelNetworkingServer::Accept);
}

FVoxelNetworkingServer::~FVoxelNetworkingServer()
{
	for (auto& Socket : Sockets)
	{
		Socket->Destroy();
	}
	ServerSocket->Destroy();
}

FOnVoxelNetworkingServerConnection& FVoxelNetworkingServer::OnConnection()
{
	return OnConnectionDelegate;
}

void FVoxelNetworkingServer::Accept(TSharedPtr<FVoxelTcpSocket> NewSocket)
{
	FScopeLock Lock(&SocketsLock);

	OnConnectionDelegate.ExecuteIfBound();

	Sockets.Add(NewSocket);
	SocketsToSendSave.Add(NewSocket);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Connected!"));
}

bool FVoxelNetworkingServer::IsValid()
{
	FScopeLock Lock(&SocketsLock);
	return Sockets.Num() > 0;
}

void FVoxelNetworkingServer::SendSave(FVoxelCompressedWorldSave& Save, bool bOnlyToNewConnections)
{	
	FBufferArchive Writer;
	Save.Serialize(Writer);

	{
		FScopeLock Lock(&SocketsLock);
		for (auto& Socket : (bOnlyToNewConnections ? SocketsToSendSave : Sockets))
		{
			// Send
			int32 BytesSent = 0;

			uint8 Data[5];

			uint32 Tmp = Writer.Num();
			Data[0] = Tmp % 256;
			Tmp /= 256;
			Data[1] = Tmp % 256;
			Tmp /= 256;
			Data[2] = Tmp % 256;
			Tmp /= 256;
			Data[3] = Tmp % 256;
			Data[4] = true;

			Socket->Send(Data, 5, BytesSent);
			if (BytesSent != 5)
			{
				UE_LOG(LogVoxel, Error, TEXT("Header for remote load failed to send"));
			}
			else
			{
				bool bSuccess = Socket->Send(Writer.GetData(), Writer.Num(), BytesSent);
				UE_LOG(LogVoxel, Log, TEXT("Remote load: Bytes to send: %d. Bytes sent: %d. Success: %d"), Writer.Num(), BytesSent, bSuccess);
			}
		}
		SocketsToSendSave.Reset();
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelNetworkingServer::SendValuesDiffs(const TArray<TVoxelChunkDiff<FVoxelValue>>& DiffQueue)
{
	SendDiffs(DiffQueue);
}


void FVoxelNetworkingServer::SendMaterialsDiffs(const TArray<TVoxelChunkDiff<FVoxelMaterial>>& DiffQueue)
{
	SendDiffs(DiffQueue);
}

template<typename T>
void FVoxelNetworkingServer::SendDiffs(const TArray<TVoxelChunkDiff<T>>& DiffList)
{
	SCOPE_CYCLE_COUNTER(STAT_FVoxelTcpServer_SendData);

	if (DiffList.Num() == 0)
	{
		return;
	}

	int I = 0;
	while (I < DiffList.Num())
	{
		uint32 SizeToSend = FMath::Min<int>(PACKET_SIZE_IN_DIFF, DiffList.Num() - I);

		FBufferArchive Writer;
		bool bValue;
		Writer << bValue;
		Writer << SizeToSend;

		for (uint32 K = 0; K < SizeToSend; K++)
		{
			Writer << const_cast<TVoxelChunkDiff<T>&>(DiffList[I]);
			I++;
		}

		TArray<uint8> DataToSend;
		FArchiveSaveCompressedProxy Compressor = FArchiveSaveCompressedProxy(DataToSend, ECompressionFlags::COMPRESS_ZLIB);
		// Send entire binary array/archive to compressor
		Compressor << Writer;
		// Send archive serialized data to binary array
		Compressor.Flush();

		{
			FScopeLock Lock(&SocketsLock);
			for (auto& Socket : Sockets)
			{
				// Send
				int32 BytesSent = 0;

				uint8 Data[5];

				uint32 Tmp = DataToSend.Num();
				Data[0] = Tmp % 256;
				Tmp /= 256;
				Data[1] = Tmp % 256;
				Tmp /= 256;
				Data[2] = Tmp % 256;
				Tmp /= 256;
				Data[3] = Tmp % 256;
				Data[4] = false;

				Socket->Send(Data, 5, BytesSent);
				if (BytesSent != 5)
				{
					UE_LOG(LogVoxel, Error, TEXT("Header failed to send"));
				}
				else
				{
					bool bSuccess = Socket->Send(DataToSend.GetData(), DataToSend.Num(), BytesSent);
					UE_LOG(LogVoxel, Log, TEXT("Bytes to send: %d. Bytes sent: %d. Success: %d"), DataToSend.Num(), BytesSent, bSuccess);
				}
			}
		}
	}
}
