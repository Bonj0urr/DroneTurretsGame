// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DTG_BaseDrone.generated.h"

UCLASS()
class DRONETURRETSGAME_API ADTG_BaseDrone : public APawn
{
	GENERATED_BODY()

public:
	ADTG_BaseDrone();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
