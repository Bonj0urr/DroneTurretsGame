// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStates/DTG_BaseGameState.h"

void ADTG_BaseGameState::BeginPlay()
{
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


