// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDs/DTG_BaseHUD.h"
#include "UMGs/DTG_CoreWidget.h"
#include "UMGs/Menus/DTG_EndGameWidget.h"
#include "GameStates/DTG_BaseGameState.h"
#include "Kismet/GameplayStatics.h"

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

	if (EndGameWidgetClass)
	{
		if (EndGameWidgetInstance = CreateWidget<UDTG_EndGameWidget>(this->GetWorld(), EndGameWidgetClass))
		{
			EndGameWidgetInstance->AddToViewport();
		}
	}

	ADTG_BaseGameState* BaseGameState = Cast<ADTG_BaseGameState>(UGameplayStatics::GetGameState(this));
	if (BaseGameState)
	{
		BaseGameState->OnEndGameResultDelegate.AddDynamic(this, &ADTG_BaseHUD::ShowEndGameWidget);
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

void ADTG_BaseHUD::ShowEndGameWidget(bool IsWinner)
{
	EndGameWidgetInstance->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

	if (IsWinner)
	{
		EndGameWidgetInstance->SetNewTextEndGame("You Won!");
	}
	else
	{
		EndGameWidgetInstance->SetNewTextEndGame("You Lost!");
	}

	FInputModeUIOnly InputMode;
	GetOwningPlayerController()->SetInputMode(InputMode);
	GetOwningPlayerController()->SetShowMouseCursor(true);
}