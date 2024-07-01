// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DTG_BaseHUD.generated.h"

class UDTG_CoreWidget;
class UDTG_EndGameWidget;

UCLASS()
class DRONETURRETSGAME_API ADTG_BaseHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	void ClearHUD();

	void InitHUD();

	UFUNCTION()
	void ShowEndGameWidget(bool IsWinner);

protected:
	virtual void BeginPlay();

private:
	UPROPERTY()
	TObjectPtr<UDTG_CoreWidget> CoreWidgetInstance;

	TObjectPtr<UDTG_EndGameWidget> EndGameWidgetInstance;

	UPROPERTY(EditDefaultsOnly, Category = "DTG|WidgetClass")
	TSubclassOf<UDTG_CoreWidget> CoreWidgetClass;

	UPROPERTY(EditAnywhere, Category = "DTG|WidgetClass")
	TSubclassOf<UDTG_EndGameWidget> EndGameWidgetClass;
};
