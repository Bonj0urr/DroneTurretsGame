// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/DTG_BaseTurret.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/DTG_HealthComponent.h"
#include "Projectiles/DTG_BaseProjectile.h"

ADTG_BaseTurret::ADTG_BaseTurret()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	RootComponent = CapsuleComponent;

	TurretBaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretBaseMeshComponent"));
	TurretBaseMeshComponent->SetupAttachment(RootComponent);

	TurretTowerMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretTowerMeshComponent"));
	TurretTowerMeshComponent->SetupAttachment(TurretBaseMeshComponent);

	ProjectileSpawnPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileSpawnPoint"));
	ProjectileSpawnPoint->SetupAttachment(TurretTowerMeshComponent);

	HealthComponent = CreateDefaultSubobject<UDTG_HealthComponent>(TEXT("HealthComponent"));
}

void ADTG_BaseTurret::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADTG_BaseTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADTG_BaseTurret::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ADTG_BaseTurret::Shoot(FVector TargetLocation)
{
	FVector SpawnPointLocation = this->GetProjectileSpawnPoint()->GetComponentLocation();

	FRotator DirectionRotation = (TargetLocation - SpawnPointLocation).GetSafeNormal().Rotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;

	ADTG_BaseProjectile* Projectile = this->GetWorld()->SpawnActor<ADTG_BaseProjectile>(
		ProjectileClass, SpawnPointLocation, DirectionRotation, SpawnParams);
}

