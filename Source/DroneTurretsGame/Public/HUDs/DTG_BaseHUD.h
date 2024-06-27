// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DTG_BaseHUD.generated.h"

class UDTG_CoreWidget;

UCLASS()
class DRONETURRETSGAME_API ADTG_BaseHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	void ClearHUD();

	void InitHUD();

protected:
	virtual void BeginPlay();

private:
	UPROPERTY()
	TObjectPtr<UDTG_CoreWidget> CoreWidgetInstance;

	UPROPERTY(EditDefaultsOnly, Category = "DTG|WidgetClass")
	TSubclassOf<UDTG_CoreWidget> CoreWidgetClass;
};
