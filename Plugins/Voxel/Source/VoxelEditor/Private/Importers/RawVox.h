// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelAssets/VoxelDataAsset.h"
#include "Misc/FileHelper.h"
#include "Misc/MessageDialog.h"

namespace RawVox
{
	bool ImportToAsset(const FString& File, FVoxelDataAssetData& Asset)
	{
		TArray<uint8> Result;
		bool bSuccess = FFileHelper::LoadFileToArray(Result, *File);
		if (!bSuccess)
		{
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("Error when opening the file")));
			return false;
		}

		int Position = 0;
		TCHAR Start[4];
		for (int i = 0; i < 4; i++)
		{
			Start[i] = Result[Position];
			Position++;
		}
		bSuccess = Start[0] == 'X' && Start[1] == 'O' && Start[2] == 'V' && Start[3] == 'R';
		if (!bSuccess)
		{
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("File is corrupted")));
			return false;
		}

		const int SizeX = Result[Position] + 256 * Result[Position + 1] + 256 * 256 * Result[Position + 2] + 256 * 256 * 256 * Result[Position + 3];
		Position += 4;
		const int SizeY = Result[Position] + 256 * Result[Position + 1] + 256 * 256 * Result[Position + 2] + 256 * 256 * 256 * Result[Position + 3];
		Position += 4;
		const int SizeZ = Result[Position] + 256 * Result[Position + 1] + 256 * 256 * Result[Position + 2] + 256 * 256 * 256 * Result[Position + 3];
		Position += 4;

		const int BitsPerVoxel = Result[Position];
		Position += 4;

		union
		{
			float f;
			uint8 b[4];
		} U;

		Asset.SetSize(FIntVector(SizeX, SizeZ, SizeY), false);

		for (int Z = 0; Z < SizeZ; Z++)
		{
			for (int Y = 0; Y < SizeY; Y++)
			{
				for (int X = 0; X < SizeX; X++)
				{
					float Val;
					if (BitsPerVoxel == 8)
					{
						Val = (Result[Position] - 128) / 128.f;
						Position++;
					}
					else if (BitsPerVoxel == 16)
					{
						Val = (Result[Position] + 256 * Result[Position + 1] - 32768) / 32768.f;
						Position += 2;
					}
					else if (BitsPerVoxel == 32)
					{
						U.b[0] = Result[Position];
						Position++;
						U.b[1] = Result[Position];
						Position++;
						U.b[2] = Result[Position];
						Position++;
						U.b[3] = Result[Position];
						Position++;

						Val = -(U.f - 0.5) * 2;
					}
					else
					{
						FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("File is corrupted")));
						return false;
					}
					Asset.SetValue(X, Z, Y, Val);
				}
			}
		}

		return true;
	}
}

