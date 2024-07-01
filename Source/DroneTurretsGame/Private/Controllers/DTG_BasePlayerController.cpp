// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/DTG_BasePlayerController.h"
#include "EnhancedInputSubsystems.h"

void ADTG_BasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DroneMappingContext, 0);
	}
}
