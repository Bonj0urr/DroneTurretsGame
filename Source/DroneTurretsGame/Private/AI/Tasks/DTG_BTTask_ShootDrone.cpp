// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Tasks/DTG_BTTask_ShootDrone.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Pawns/DTG_BaseTurret.h"

UDTG_BTTask_ShootDrone::UDTG_BTTask_ShootDrone()
{
	NodeName = "Shoot Drone";
}

EBTNodeResult::Type UDTG_BTTask_ShootDrone::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (!AIController) return EBTNodeResult::Failed;

    APawn* AIPawn = AIController->GetPawn();
    if (!AIPawn) return EBTNodeResult::Failed;

    ADTG_BaseTurret* BaseTurret = Cast<ADTG_BaseTurret>(AIPawn);
    if (!BaseTurret) return EBTNodeResult::Failed;

    if (UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent())
    {
        FVector TargetLocation = BlackboardComponent->GetValueAsVector(GetSelectedBlackboardKey());
        BaseTurret->Shoot(TargetLocation);

        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}
