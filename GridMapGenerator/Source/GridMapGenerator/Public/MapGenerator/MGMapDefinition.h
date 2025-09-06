// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MGMapDefinition.generated.h"

UCLASS()
class GRIDMAPGENERATOR_API UMGMapDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Map")
	FString MapName;

	UPROPERTY(EditAnywhere, Category = "Map")
	TArray<TSubclassOf<AActor>> TileBlueprints;

	UPROPERTY(EditAnywhere, Category = "Map")
	int32 MapWidth;

	UPROPERTY(EditAnywhere, Category = "Map")
	int32 MapHeight;
};
