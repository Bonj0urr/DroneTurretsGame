// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DTG_WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DRONETURRETSGAME_API UDTG_WeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDTG_WeaponComponent();
	
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
    void Shoot();

protected:
	virtual void BeginPlay() override;


		
};
