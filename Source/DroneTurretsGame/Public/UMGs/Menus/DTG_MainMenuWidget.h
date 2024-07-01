// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DTG_MainMenuWidget.generated.h"

class UButton;

UCLASS()
class DRONETURRETSGAME_API UDTG_MainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnButtonPlayClicked();

	UFUNCTION()
	void OnButtonExitClicked();

	void SetLevel(FName NameLevel);

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> ButtonPlay;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> ButtonExit;
};
