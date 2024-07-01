// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DTG_MainMenuHUD.generated.h"

class UDTG_MainMenuWidget;

UCLASS()
class DRONETURRETSGAME_API ADTG_MainMenuHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	void InitHUD();

protected:
	virtual void BeginPlay();

private:
	UPROPERTY()
	TObjectPtr<UDTG_MainMenuWidget> MainMenuWidgetInstance;

	UPROPERTY(EditDefaultsOnly, Category = "DTG|WidgetClass")
	TSubclassOf<UDTG_MainMenuWidget> MainMenuWidgetClass;
};
