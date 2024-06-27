// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DTG_CoreWidget.generated.h"

class UTextBlock;

UCLASS()
class DRONETURRETSGAME_API UDTG_CoreWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void UpdateHealth(int32 CurrentHealth);

	UFUNCTION()
	void UpdateAmmo(int32 CurrentAmmo);

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextCurrentHealth;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	TObjectPtr<UTextBlock> TextCurrentAmmo;
};
