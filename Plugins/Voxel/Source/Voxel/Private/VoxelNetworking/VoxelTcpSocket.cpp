// Copyright 2018 Phyronnaz

#include "VoxelNetworking/VoxelTcpSocket.h"
#include "VoxelLogStatDefinitions.h"
#include "VoxelGlobals.h"

FVoxelTcpSocket::FVoxelTcpSocket() 
	: Socket(nullptr)
{

}

FVoxelTcpSocket::~FVoxelTcpSocket()
{
	check(!Socket);
	check(!TcpListener);
}

bool FVoxelTcpSocket::IsValid()
{
	check(!(TcpListener && Socket));
	return Socket || TcpListener;
}

void FVoxelTcpSocket::Destroy()
{
	check(!(TcpListener && Socket));
	if (Socket)
	{
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
		Socket = nullptr;
	}
	if (TcpListener)
	{
		TcpListener.Reset();
	}
}

bool FVoxelTcpSocket::HasPendingData(uint32& PendingDataSize)
{
	check(Socket);
	return Socket->HasPendingData(PendingDataSize);
}

bool FVoxelTcpSocket::Recv(uint8* Data, int32 BufferSize, int32& BytesRead)
{
	check(Socket);
	return	Socket->Recv(Data, BufferSize, BytesRead);
}

bool FVoxelTcpSocket::Send(const uint8* Data, int32 Count, int32& BytesSent)
{
	check(Socket);
	return Socket->Send(Data, Count, BytesSent);
}

bool FVoxelTcpSocket::ConnectToEndpoint(const FIPv4Endpoint& Endpoint)
{
	Destroy();

	Socket = FTcpSocketBuilder(TEXT("RemoteConnection"));

	int BufferSize = 1000000;
	int NewSize;
	Socket->SetReceiveBufferSize(BufferSize, NewSize);
	check(BufferSize == NewSize);

	if (Socket)
	{
		if (!Socket->Connect(*Endpoint.ToInternetAddr()))
		{
			Destroy();
			return false;
		}
	}

	return true;
}

void FVoxelTcpSocket::StartServerOnEndpoint(const FIPv4Endpoint& Endpoint)
{
	Destroy();

	TcpListener = MakeUnique<FTcpListener>(Endpoint);
	TcpListener->OnConnectionAccepted().BindRaw(this, &FVoxelTcpSocket::Accept);
}

bool FVoxelTcpSocket::Accept(FSocket* NewSocket, const FIPv4Endpoint& Endpoint)
{
	TSharedPtr<FVoxelTcpSocket> NewTcpSocket = MakeShared<FVoxelTcpSocket>();
	NewTcpSocket->Socket = NewSocket;


	int BufferSize = 1000000;
	int NewSize;
	NewSocket->SetSendBufferSize(BufferSize, NewSize);
	check(BufferSize == NewSize);

	OnConnection.Execute(NewTcpSocket);

	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

bool FVoxelTcpSocket::ConnectTcpClient(const FString& Ip, int32 Port)
{
	TSharedPtr<FInternetAddr> RemoteAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

	bool bIsValid;
	RemoteAddr->SetIp(*Ip, bIsValid);
	RemoteAddr->SetPort(Port);

	if (!bIsValid)
	{
		UE_LOG(LogVoxel, Error, TEXT("IP address was not valid"));
		return false;
	}

	FIPv4Endpoint Endpoint(RemoteAddr);

	return ConnectToEndpoint(Endpoint);
}

void FVoxelTcpSocket::StartTcpServer(const FString& Ip, int32 Port)
{
	FIPv4Address Addr;
	FIPv4Address::Parse(Ip, Addr);

	FIPv4Endpoint Endpoint(Addr, Port);
	
	StartServerOnEndpoint(Endpoint);
}

