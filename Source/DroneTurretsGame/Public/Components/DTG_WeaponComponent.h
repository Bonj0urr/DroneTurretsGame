// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DTG_WeaponComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAmmoChangedSignature, int32, CurrentAmmo);

class ADTG_BaseProjectile;

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

	FORCEINLINE int32 GetMaxAmmo() const { return MaxAmmo; }
	FORCEINLINE int32 GetCurrentAmmo() const { return CurrentAmmo; }

	UFUNCTION()
	void AddAmmo(int32 AdditinalAmmo);

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnAmmoChangedSignature OnAmmoChangedDelegate;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTG", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ADTG_BaseProjectile> ProjectileClass;

	UPROPERTY()
	FTimerHandle ShootDelayTimer;

	UPROPERTY()
	bool bCanShoot;

	UPROPERTY(EditDefaultsOnly)
	int32 MaxAmmo;

	UPROPERTY()
	int32 CurrentAmmo;
};
