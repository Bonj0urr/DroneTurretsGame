// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDs/DTG_MainMenuHUD.h"
#include "UMGs/Menus/DTG_MainMenuWidget.h"

void ADTG_MainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	InitHUD();
}

void ADTG_MainMenuHUD::InitHUD()
{
	FInputModeGameAndUI InputMode;
	this->GetOwningPlayerController()->SetInputMode(InputMode);
	this->GetOwningPlayerController()->SetShowMouseCursor(true);

	if (MainMenuWidgetClass)
	{
		if (MainMenuWidgetInstance = CreateWidget<UDTG_MainMenuWidget>(this->GetWorld(), MainMenuWidgetClass))
		{
			MainMenuWidgetInstance->AddToViewport();
		}
	}
}

