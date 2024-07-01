// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/DTG_BaseProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/DamageEvents.h"

ADTG_BaseProjectile::ADTG_BaseProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	RootComponent = ProjectileMesh;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->InitialSpeed = 4000.0f;
	ProjectileMovementComponent->MaxSpeed = 4000.0f;
}

void ADTG_BaseProjectile::BeginPlay()
{
	Super::BeginPlay();

	ProjectileMesh->OnComponentHit.AddDynamic(this, &ADTG_BaseProjectile::OnHit);

	SetLifeSpan(LifeTime);
}

void ADTG_BaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADTG_BaseProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NarmalImpuls, const FHitResult& Hit)
{
	AActor* OwnerActor = this->GetOwner();

	if (!OwnerActor) return;

	if (OtherActor && OtherActor != OwnerActor && OtherActor != this)
	{
		OtherActor->TakeDamage(Damage, FDamageEvent(), OwnerActor->GetInstigatorController(), this);
	}

	this->Destroy();
}

