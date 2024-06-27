// Fill out your copyright notice in the Description page of Project Settings.


#include "UMGs/DTG_CoreWidget.h"
#include "Pawns/DTG_BaseDrone.h"
#include "Components/DTG_HealthComponent.h"
#include "Components/DTG_WeaponComponent.h"
#include "Components/TextBlock.h"

void UDTG_CoreWidget::NativeConstruct()
{
	ADTG_BaseDrone* Owner = Cast<ADTG_BaseDrone>(GetOwningPlayerPawn());
	if (!Owner) return;

	if (UDTG_HealthComponent* HealthComponent = Owner->GetHealthComponent())
	{
		HealthComponent->OnHealthChangedDelegate.AddDynamic(this, &UDTG_CoreWidget::UpdateHealth);
		HealthComponent->OnHealthChangedDelegate.Broadcast(HealthComponent->GetMaxHealth());
	}

	if (UDTG_WeaponComponent* WeaponComponent = Owner->GetWeaponComponent())
	{
		WeaponComponent->OnAmmoChangedDelegate.AddDynamic(this, &UDTG_CoreWidget::UpdateAmmo);
		WeaponComponent->OnAmmoChangedDelegate.Broadcast(WeaponComponent->GetMaxAmmo());
	}
}

void UDTG_CoreWidget::UpdateHealth(int32 CurrentHealth)
{
	TextCurrentHealth->SetText(FText::FromString(FString::FromInt(CurrentHealth)));
}

void UDTG_CoreWidget::UpdateAmmo(int32 CurrentAmmo)
{
	TextCurrentAmmo->SetText(FText::FromString(FString::FromInt(CurrentAmmo)));
}