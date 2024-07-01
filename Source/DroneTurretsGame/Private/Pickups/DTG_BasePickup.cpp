// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/DTG_BasePickup.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

ADTG_BasePickup::ADTG_BasePickup()
{
	PrimaryActorTick.bCanEverTick = true;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetupAttachment(PickupMesh);

	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ADTG_BasePickup::OnPickup);
}

void ADTG_BasePickup::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADTG_BasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADTG_BasePickup::OnPickup(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}



