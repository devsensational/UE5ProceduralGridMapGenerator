// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MGGameMode.generated.h"

// Forward declaration
class AMGGameState;

UCLASS()
class GRIDMAPGENERATOR_API AMGGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	AMGGameMode();

protected:
	virtual void BeginPlay() override;

	virtual void PostLogin(APlayerController* NewPlayer) override;
};



