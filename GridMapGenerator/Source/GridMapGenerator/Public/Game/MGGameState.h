// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Interface/MGProceduralMap.h"
#include "Net/UnrealNetwork.h"
#include "MGGameState.generated.h"

/**
 * 랜덤 시드를 모든 클라이언트에 복제하는 GameState 클래스
 */
UCLASS()
class GRIDMAPGENERATOR_API AMGGameState : public AGameState, public IMGProceduralMap
{
	GENERATED_BODY()

	/* Lifecycle 섹션 */
public:
	AMGGameState();

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/* Map Seed 섹션 */
public:
	FORCEINLINE virtual FString GetMapSeed() const override { return MapSeed; };
	virtual void SetMapSeed(const FString& NewMapSeed) override;
	virtual void GenerateMap(const FString& MapSeed) override;
	
protected:
	UFUNCTION()
	void OnRep_ChangeMapSeed();
	
private:
	// NOTE: MapSeed는 MapName:MapWidth:MapHeight:Seed 형식의 문자열로 저장됨
	UPROPERTY(ReplicatedUsing = OnRep_ChangeMapSeed, BlueprintReadOnly, Category = "Seed", meta = (AllowPrivateAccess = "true"))
	FString MapSeed;
};
