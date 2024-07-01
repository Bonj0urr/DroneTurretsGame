// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/DTG_BasePickup.h"
#include "DTG_HealthPickup.generated.h"

UCLASS()
class DRONETURRETSGAME_API ADTG_HealthPickup : public ADTG_BasePickup
{
	GENERATED_BODY()
	
public:
	ADTG_HealthPickup();

protected:
    virtual void OnPickup(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
