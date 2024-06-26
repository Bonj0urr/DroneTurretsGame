// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DTG_ProjectileDataAsset.generated.h"

UCLASS()
class DRONETURRETSGAME_API UDTG_ProjectileDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTG|Projectile")
    TObjectPtr<UStaticMeshComponent> ProjectileMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTG|Projectile")
    float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTG|Projectile")
    int32 MaxAmmoCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTG|Projectile")
    float LifeTime;
};
