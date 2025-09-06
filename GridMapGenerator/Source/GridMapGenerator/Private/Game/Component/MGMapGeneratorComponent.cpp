// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Component/MGMapGeneratorComponent.h"


UMGMapGeneratorComponent::UMGMapGeneratorComponent()
{

}

void UMGMapGeneratorComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UMGMapGeneratorComponent::GenerateMap(const FString& MapSeed)
{
	TArray<FString> Seed;
	MapSeed.ParseIntoArray(Seed, TEXT(":"), true);
}
