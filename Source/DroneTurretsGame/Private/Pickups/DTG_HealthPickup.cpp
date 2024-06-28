// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/DTG_HealthPickup.h"
#include "Pawns/DTG_BaseDrone.h"
#include "Components/DTG_HealthComponent.h"

ADTG_HealthPickup::ADTG_HealthPickup()
{

}

void ADTG_HealthPickup::OnPickup(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADTG_BaseDrone* Drone = Cast<ADTG_BaseDrone>(OtherActor);
	if (!Drone) return;

	if (UDTG_HealthComponent* HealthComponent = Drone->GetHealthComponent())
	{
		HealthComponent->AddHealth(PickupAmount);
	}
}
