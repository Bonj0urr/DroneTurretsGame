// Fill out your copyright notice in the Description page of Project Settings.


#include "UMGs/Menus/DTG_EndGameWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/TextBlock.h"

void UDTG_EndGameWidget::NativeConstruct()
{
	if (ButtonRestart && ButtonMainMenu)
	{
		ButtonRestart->OnClicked.AddUniqueDynamic(this, &UDTG_EndGameWidget::OnButtonRestartClicked);
		ButtonMainMenu->OnClicked.AddUniqueDynamic(this, &UDTG_EndGameWidget::OnButtonMainMenuClicked);
	}
}

void UDTG_EndGameWidget::OnButtonRestartClicked()
{
	SetLevel("Game_Map");
}

void UDTG_EndGameWidget::OnButtonMainMenuClicked()
{
	SetLevel("MainMenu_Map");
}

void UDTG_EndGameWidget::SetLevel(FName NameLevel)
{
	if (TObjectPtr<UWorld> World = GetWorld())
	{
		UGameplayStatics::OpenLevel(World, NameLevel);
	}
}

void UDTG_EndGameWidget::SetNewTextEndGame(FString NewTextEndGame)
{
	TextEndGame->SetText(FText::FromString(NewTextEndGame));
}
