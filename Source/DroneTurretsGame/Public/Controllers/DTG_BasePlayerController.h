// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DTG_BasePlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class DRONETURRETSGAME_API ADTG_BasePlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTG|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> DroneMappingContext;
};
