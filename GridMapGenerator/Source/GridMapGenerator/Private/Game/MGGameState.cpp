// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/MGGameState.h"

#include "Game/Component/MGMapGeneratorComponent.h"
#include "GridMapGenerator/GridMapGenerator.h"
#include "Net/UnrealNetwork.h"

AMGGameState::AMGGameState()
{
	bReplicates = true;
	
	MapSeed = TEXT("");

	MapGeneratorComponent = CreateDefaultSubobject<UMGMapGeneratorComponent>(TEXT("MapGeneratorComponent"));
}

void AMGGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(AMGGameState, MapSeed);
}

void AMGGameState::SetMapSeed(const FString& NewMapSeed)
{
	if (HasAuthority())
	{
		MapSeed = NewMapSeed;
		OnRep_ChangeMapSeed();
	}
}

void AMGGameState::OnRep_ChangeMapSeed()
{
	UE_LOG(LogTemp, Log, TEXT("Map seed changed to: %s"), *MapSeed);

	if (MapGeneratorComponent)
	{
		MapGeneratorComponent->GenerateMap(MapSeed);
	}
}
