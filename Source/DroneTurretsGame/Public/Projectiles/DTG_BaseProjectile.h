// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DTG_BaseProjectile.generated.h"

class UDTG_ProjectileDataAsset;
class UProjectileMovementComponent;

UCLASS()
class DRONETURRETSGAME_API ADTG_BaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ADTG_BaseProjectile();

public:
	virtual void Tick(float DeltaTime) override;

	void InitProjectile(UDTG_ProjectileDataAsset* ProjectileDataAsset);

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NarmalImpuls, const FHitResult& Hit);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UStaticMeshComponent> ProjectileMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "DTG|Projectile", meta = (AllowPrivateAccess = "true") )
    float Damage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "DTG|Projectile", meta = (AllowPrivateAccess = "true") )
    float LifeTime;
};