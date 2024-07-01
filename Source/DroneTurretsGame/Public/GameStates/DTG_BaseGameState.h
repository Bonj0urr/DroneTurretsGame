// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "DTG_BaseGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEndGameResultSignature, bool, IsEndGame);

UCLASS()
class DRONETURRETSGAME_API ADTG_BaseGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	void DecrementEnemyCount();

	void SetEnemyCount(int NewEnemyCount);

	void IsEnemyCountZero();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnEndGameResultSignature OnEndGameResultDelegate;

private:
	int32 CurrentEnemyCount = 3;
};
