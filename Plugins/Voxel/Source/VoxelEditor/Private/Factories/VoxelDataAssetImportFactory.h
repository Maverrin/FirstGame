// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Factories/Factory.h"
#include "VoxelDataAssetImportFactory.generated.h"

UCLASS()
class UVoxelDataAssetImportFactory : public UFactory
{
	GENERATED_BODY()

public:
	UVoxelDataAssetImportFactory();

	// UFactory interface
	virtual bool FactoryCanImport(const FString& Filename);
	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
	// End of UFactory interface
};
