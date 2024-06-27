// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/DTG_WeaponComponent.h"
#include "Projectiles/DTG_BaseProjectile.h"
#include "Pawns/DTG_BaseDrone.h"

UDTG_WeaponComponent::UDTG_WeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	bCanShoot = true;
}


void UDTG_WeaponComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UDTG_WeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UDTG_WeaponComponent::Shoot()
{
	if (bCanShoot)
	{
		AActor* Owner = this->GetOwner();
		if (!Owner) return;

		ADTG_BaseDrone* BaseDrone = Cast<ADTG_BaseDrone>(Owner);
		if (!BaseDrone) return;

		FRotator ControlRotation = BaseDrone->GetControlRotation();
		FVector SpawnPoint = BaseDrone->GetProjectileSpawnPoint()->GetComponentLocation();

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = Owner;

		ADTG_BaseProjectile* Projectile = this->GetWorld()->SpawnActor<ADTG_BaseProjectile>(
			ProjectileClass, SpawnPoint, ControlRotation, SpawnParams);

		bCanShoot = false;
		BaseDrone->GetWorldTimerManager().SetTimer(
			ShootDelayTimer,
			[this]()
			{
				if (this)
				{
					bCanShoot = true;
				}
			},
			2.0f,
			false
		);
	}
}

