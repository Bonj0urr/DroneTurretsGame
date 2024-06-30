// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/DTG_AmmoPickup.h"
#include "Pawns/DTG_BaseDrone.h"
#include "Components/DTG_WeaponComponent.h"

ADTG_AmmoPickup::ADTG_AmmoPickup()
{

}

void ADTG_AmmoPickup::OnPickup(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADTG_BaseDrone* Drone = Cast<ADTG_BaseDrone>(OtherActor);
	if (!Drone) return;

	if (UDTG_WeaponComponent* WeaponComponent = Drone->GetWeaponComponent())
	{
		WeaponComponent->AddAmmo(PickupAmount);
	}
	this->Destroy();
}

