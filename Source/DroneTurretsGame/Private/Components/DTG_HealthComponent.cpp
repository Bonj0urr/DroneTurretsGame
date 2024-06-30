// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/DTG_HealthComponent.h"

UDTG_HealthComponent::UDTG_HealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	MaxHealth = 100;
	CurrentHealth = MaxHealth;
}

void UDTG_HealthComponent::AddHealth(int32 AdditinalHealth)
{
	CurrentHealth = FMath::Clamp(CurrentHealth + AdditinalHealth, 0, MaxHealth);
	OnHealthChangedDelegate.Broadcast(CurrentHealth);
}

void UDTG_HealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if (AActor* Owner = this->GetOwner())
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UDTG_HealthComponent::DamageTaken);
	}
}

void UDTG_HealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UDTG_HealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	AActor* Owner = this->GetOwner();

	if (!Owner || Damage <= 0.0f) return;

	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0, MaxHealth);
	OnHealthChangedDelegate.Broadcast(CurrentHealth);

	if (CurrentHealth <= 0)
	{
		Owner->Destroy();
	}
}

