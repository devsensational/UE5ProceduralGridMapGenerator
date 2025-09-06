// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/MGGameMode.h"
#include "Game/MGGameState.h"
#include "Engine/Engine.h"
#include "Math/UnrealMathUtility.h"

AMGGameMode::AMGGameMode()
{
	GameStateClass = AMGGameState::StaticClass();
}

void AMGGameMode::BeginPlay()
{
	Super::BeginPlay();

	AMGGameState *MGGameState = GetGameState<AMGGameState>();
	MGGameState->SetMapSeed(FString::FromInt(FMath::RandRange(0,	1000000)));
}

void AMGGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}
