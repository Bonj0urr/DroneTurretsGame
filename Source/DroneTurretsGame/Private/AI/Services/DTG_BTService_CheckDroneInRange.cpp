// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Services/DTG_BTService_CheckDroneInRange.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#include "AIController.h"

UDTG_BTService_CheckDroneInRange::UDTG_BTService_CheckDroneInRange()
{
    NodeName = "Check Drone In Range";
    Interval = 1.0f;
    RandomDeviation = 0.1f;
}

void UDTG_BTService_CheckDroneInRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    AAIController* AIController = OwnerComp.GetAIOwner();
    if (!AIController) return;

    if (UAIPerceptionComponent* AIPerceptionComponent = AIController->GetAIPerceptionComponent())
    {
        TArray<AActor*> PerceivedActors;
        AIPerceptionComponent->GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), PerceivedActors);

        if (PerceivedActors.IsEmpty())
        {
            OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
        }
    }
}
