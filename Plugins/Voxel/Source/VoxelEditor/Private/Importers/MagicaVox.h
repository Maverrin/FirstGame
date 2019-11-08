// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelAssets/VoxelDataAsset.h"
#include "Misc/FileHelper.h"
#include "Misc/MessageDialog.h"

namespace MagicaVox
{
	inline int ReadInt(TArray<uint8>& Bytes, int& Position)
	{
		int Result = Bytes[Position] + 256 * Bytes[Position + 1] + 256 * 256 * Bytes[Position + 2] + 256 * 256 * 256 * Bytes[Position + 3];
		Position += 4;
		return Result;
	}

	inline bool ReadString(TArray<uint8>& Bytes, int& Position, const FString& Chars)
	{
		TCHAR Start[4];
		for (int i = 0; i < 4; i++)
		{
			Start[i] = Bytes[Position];
			Position++;
		}
		return Start[0] == Chars[0] && Start[1] == Chars[1] && Start[2] == Chars[2] && Start[3] == Chars[3];
	}

	inline uint8 ReadByte(TArray<uint8>& Bytes, int& Position)
	{
		uint8 Result = Bytes[Position];
		Position++;
		return Result;
	}

	bool ImportToAsset(const FString& Filename, FVoxelDataAssetData& Asset)
	{
		TArray<uint8> Bytes;
		bool bSuccess = FFileHelper::LoadFileToArray(Bytes, *Filename);
		if (!bSuccess)
		{
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("Error when opening the file")));
			return false;
		}

		int Position = 0;

		bSuccess = ReadString(Bytes, Position, TEXT("VOX "));
		if (!bSuccess)
		{
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("File is corrupted")));
			return false;
		}

		int Version = ReadInt(Bytes, Position);

		bSuccess = ReadString(Bytes, Position, TEXT("MAIN"));
		if (!bSuccess)
		{
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("File is corrupted")));
			return false;
		}

		Position += 8; // Unknown

		int PackCount;
		bSuccess = ReadString(Bytes, Position, TEXT("PACK"));
		Position += 8; // Unknown
		if (bSuccess)
		{
			PackCount = ReadInt(Bytes, Position);
		}
		else
		{
			Position -= 4 + 8;
			PackCount = 1;
		}

		for (int i = 0; i < 1 /*PackCount*/; i++) // TODO: PackCount != 1
		{
			bSuccess = ReadString(Bytes, Position, TEXT("SIZE"));
			if (!bSuccess)
			{
				FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("File is corrupted")));
				return false;
			}
			Position += 8; // Unknown

			const int SizeX = ReadInt(Bytes, Position);
			const int SizeY = ReadInt(Bytes, Position);
			const int SizeZ = ReadInt(Bytes, Position);

			Asset.SetSize(FIntVector(SizeY, SizeX, SizeZ), true);

			TArray<bool> Blocks;
			TArray<uint8> Colors;
			Blocks.SetNum(SizeX * SizeY * SizeZ);
			Colors.SetNum(SizeX * SizeY * SizeZ);


			bSuccess = ReadString(Bytes, Position, TEXT("XYZI"));
			if (!bSuccess)
			{
				FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("File is corrupted")));
				return false;
			}
			Position += 8; // Unknown

			const int N = ReadInt(Bytes, Position);

			for (int K = 0; K < N; K++)
			{
				int X = ReadByte(Bytes, Position);
				int Y = ReadByte(Bytes, Position);
				int Z = ReadByte(Bytes, Position);
				int Color = ReadByte(Bytes, Position);

				Blocks[X + SizeX * Y + SizeX * SizeY * Z] = true;
				Colors[X + SizeX * Y + SizeX * SizeY * Z] = Color;
			}

			for (int Z = 0; Z < SizeZ; Z++)
			{
				for (int Y = 0; Y < SizeY; Y++)
				{
					for (int X = 0; X < SizeX; X++)
					{
						int Index = X + SizeX * Y + SizeX * SizeY * Z;

						Asset.SetValue(Y, X, Z, Blocks[Index] ? FVoxelValue::Full : FVoxelValue::Empty);
						FVoxelMaterial Material;
						Material.SetIndex(Colors[Index]);
						Asset.SetMaterial(Y, X, Z, Material);
					}
				}
			}
		}

		return true;
	}
}
