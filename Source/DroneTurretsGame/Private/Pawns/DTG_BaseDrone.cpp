// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/DTG_BaseDrone.h"

ADTG_BaseDrone::ADTG_BaseDrone()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ADTG_BaseDrone::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADTG_BaseDrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADTG_BaseDrone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

