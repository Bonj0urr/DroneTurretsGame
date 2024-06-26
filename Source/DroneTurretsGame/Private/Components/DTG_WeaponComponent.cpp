// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/DTG_WeaponComponent.h"

UDTG_WeaponComponent::UDTG_WeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
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

}

