// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MGProceduralMap.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UMGProceduralMap : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GRIDMAPGENERATOR_API IMGProceduralMap
{
	GENERATED_BODY()

public:
	virtual FString GetMapSeed() const = 0;
	virtual void SetMapSeed(const FString& NewMapSeed) = 0;
};
