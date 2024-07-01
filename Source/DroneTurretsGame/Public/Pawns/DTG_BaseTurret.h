// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DTG_BaseTurret.generated.h"

class UDTG_HealthComponent;
class UCapsuleComponent;
class ADTG_BaseProjectile;

UCLASS()
class DRONETURRETSGAME_API ADTG_BaseTurret : public APawn
{
	GENERATED_BODY()

public:
	ADTG_BaseTurret();

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE USceneComponent* GetProjectileSpawnPoint() const { return ProjectileSpawnPoint; }

	UFUNCTION()
    void Shoot(FVector TargetLocation);

	UFUNCTION(BlueprintImplementableEvent)
	void RotateTurretTower(FRotator DirectionRotation);

	UFUNCTION(BlueprintCallable)
	void SpawnProjectile(FRotator ProjectileRotation);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTG|Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDTG_HealthComponent> HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> TurretBaseMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> TurretTowerMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTG", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ADTG_BaseProjectile> ProjectileClass;

};
