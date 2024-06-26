// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "DTG_BaseDrone.generated.h"

class UInputAction;
class UCameraComponent;
class UFloatingPawnMovement;
class UCapsuleComponent;
class UStaticMeshComponent;

UCLASS()
class DRONETURRETSGAME_API ADTG_BaseDrone : public APawn
{
	GENERATED_BODY()

public:
	ADTG_BaseDrone();

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void Look(const FInputActionValue& Value);

	UFUNCTION()
	void Fly(const FInputActionValue& Value);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UFloatingPawnMovement> FloatingPawnMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTG|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTG|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> FlyAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTG|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> ShootAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTG|Camera", meta = (AllowPrivateAccess = "true"))
	float MinClampCameraLook;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTG|Camera", meta = (AllowPrivateAccess = "true"))
	float MaxClampCameraLook;
};
