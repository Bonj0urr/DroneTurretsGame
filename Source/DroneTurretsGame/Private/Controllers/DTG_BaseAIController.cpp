// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/DTG_BaseAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionSystem.h"
#include "Perception/AISense_Sight.h"

ADTG_BaseAIController::ADTG_BaseAIController()
{
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
}

void ADTG_BaseAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIPerceptionComponent)
	{
		AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ADTG_BaseAIController::HandleStimulusUpdate);
	}

	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
}

void ADTG_BaseAIController::HandleStimulusUpdate(AActor* Actor, FAIStimulus Stimulus)
{
	if (this->GetPawn())
	{
		TSubclassOf<UAISense> StimulusClass = UAIPerceptionSystem::GetSenseClassForStimulus(this, Stimulus);

		if (StimulusClass == UAISense_Sight::StaticClass())
		{
			HandleSightSense(Actor, Stimulus);
		}
	}
}

void ADTG_BaseAIController::HandleSightSense(AActor* Actor, FAIStimulus Stimulus)
{
	if (!Stimulus.WasSuccessfullySensed()) return;

	if (UBlackboardComponent* BlackBoardComponent = GetBlackboardComponent())
	{
		BlackBoardComponent->SetValueAsVector("TargetLocation", Actor->GetActorLocation());
	}
}
