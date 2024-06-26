// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/DTG_BaseDrone.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/DTG_HealthComponent.h"

ADTG_BaseDrone::ADTG_BaseDrone()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	RootComponent = CapsuleComponent;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(StaticMeshComponent);
	FollowCamera->bUsePawnControlRotation = false;

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
	HealthComponent = CreateDefaultSubobject<UDTG_HealthComponent>(TEXT("HealthComponent"));
}

void ADTG_BaseDrone::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this->GetWorld(), 0))
	{
		CameraManager->ViewPitchMin = MinClampCameraLook;
		CameraManager->ViewPitchMax = MaxClampCameraLook;
	}
}

void ADTG_BaseDrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADTG_BaseDrone::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ADTG_BaseDrone::Fly(const FInputActionValue& Value)
{
	FVector FlyAxisVector = Value.Get<FVector>();

	if (FloatingPawnMovement && Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		const FVector UpDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Z);

		FloatingPawnMovement->AddInputVector(RightDirection * FlyAxisVector.X);
		FloatingPawnMovement->AddInputVector(ForwardDirection * FlyAxisVector.Y);
		FloatingPawnMovement->AddInputVector(UpDirection * FlyAxisVector.Z);
	}
}

void ADTG_BaseDrone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADTG_BaseDrone::Look);
		EnhancedInputComponent->BindAction(FlyAction, ETriggerEvent::Triggered, this, &ADTG_BaseDrone::Fly);
	}
}

