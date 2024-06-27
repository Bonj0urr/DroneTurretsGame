// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDs/DTG_BaseHUD.h"
#include "UMGs/DTG_CoreWidget.h"

void ADTG_BaseHUD::BeginPlay()
{
	Super::BeginPlay();

	InitHUD();
}

void ADTG_BaseHUD::InitHUD()
{
	/* Focus input on the game */
	FInputModeGameOnly InputMode;
	this->GetOwningPlayerController()->SetInputMode(InputMode);
	this->GetOwningPlayerController()->SetShowMouseCursor(false);

	if (CoreWidgetClass)
	{
		if (CoreWidgetInstance = CreateWidget<UDTG_CoreWidget>(this->GetWorld(), CoreWidgetClass))
		{
			CoreWidgetInstance->AddToViewport();
		}
	}
}

void ADTG_BaseHUD::ClearHUD()
{
	if (CoreWidgetInstance)
	{
		CoreWidgetInstance->RemoveFromParent();
		CoreWidgetInstance = nullptr;
	}
}