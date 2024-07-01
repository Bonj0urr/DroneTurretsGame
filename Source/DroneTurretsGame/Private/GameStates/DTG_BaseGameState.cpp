// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStates/DTG_BaseGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/DTG_BaseTurret.h"

void ADTG_BaseGameState::BeginPlay()
{
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(this, ADTG_BaseTurret::StaticClass(), Actors);

	CurrentEnemyCount = Actors.Num();

	UE_LOG(LogTemp, Warning, TEXT("Current enemy count: %d"), CurrentEnemyCount);
}

void ADTG_BaseGameState::DecrementEnemyCount()
{
	CurrentEnemyCount -= 1;
	IsEnemyCountZero();
}

void ADTG_BaseGameState::SetEnemyCount(int32 NewEnemyCount)
{
	CurrentEnemyCount = NewEnemyCount;
}

void ADTG_BaseGameState::IsEnemyCountZero()
{
	if (CurrentEnemyCount <= 0)
	{
		OnEndGameResultDelegate.Broadcast(true);
	}
}


