// Copyright 2018 Phyronnaz

#pragma once


#include "CoreMinimal.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "Sockets.h"
#include "Common/TcpListener.h"

DECLARE_DELEGATE_RetVal_OneParam(void, FOnVoxelSocketConnectionAccepted, TSharedPtr<class FVoxelTcpSocket>)

class FVoxelTcpSocket
{
public:
	FOnVoxelSocketConnectionAccepted OnConnection;

	FVoxelTcpSocket();
	virtual ~FVoxelTcpSocket();

	bool IsValid();
	void Destroy();
	bool HasPendingData(uint32& PendingDataSize);
	bool Recv(uint8* Data, int32 BufferSize, int32& BytesRead);
	bool Send(const uint8* Data, int32 Count, int32& BytesSent);

	bool ConnectToEndpoint(const FIPv4Endpoint& Endpoint);
	void StartServerOnEndpoint(const FIPv4Endpoint& Endpoint);

	bool Accept(FSocket* NewSocket, const FIPv4Endpoint& Endpoint);

	FSocket* Socket;
	TUniquePtr<FTcpListener> TcpListener;
	
	bool ConnectTcpClient(const FString& Ip = TEXT("127.0.0.1"), int32 Port = 10000);
	void StartTcpServer(const FString& Ip = TEXT("0.0.0.0"), int32 Port = 10000);
};

