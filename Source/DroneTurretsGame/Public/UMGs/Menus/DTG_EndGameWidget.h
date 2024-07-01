// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DTG_EndGameWidget.generated.h"

class UTextBlock;
class UButton;

UCLASS()
class DRONETURRETSGAME_API UDTG_EndGameWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void SetNewTextEndGame(FString NewTextEndGame);

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnButtonRestartClicked();

	UFUNCTION()
	void OnButtonMainMenuClicked();

	void SetLevel(FName NameLevel);

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> ButtonRestart;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> ButtonMainMenu;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	TObjectPtr<UTextBlock> TextEndGame;
};
