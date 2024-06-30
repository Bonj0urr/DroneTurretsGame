// Fill out your copyright notice in the Description page of Project Settings.


#include "UMGs/Menus/DTG_MainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UDTG_MainMenuWidget::NativeConstruct()
{
	if (ButtonPlay && ButtonExit)
	{
		ButtonPlay->OnClicked.AddUniqueDynamic(this, &UDTG_MainMenuWidget::OnButtonPlayClicked);
		ButtonExit->OnClicked.AddUniqueDynamic(this, &UDTG_MainMenuWidget::OnButtonExitClicked);
	}
}

void UDTG_MainMenuWidget::OnButtonPlayClicked()
{
	SetLevel("Game_Map");
}

void UDTG_MainMenuWidget::OnButtonExitClicked()
{
	UKismetSystemLibrary::QuitGame(this->GetWorld(),
		UGameplayStatics::GetPlayerController(this->GetWorld(), 0), EQuitPreference::Quit, true);
}

void UDTG_MainMenuWidget::SetLevel(FName NameLevel)
{
	if (TObjectPtr<UWorld> World = GetWorld())
	{
		UGameplayStatics::OpenLevel(World, NameLevel);
	}
}
