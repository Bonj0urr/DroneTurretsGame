// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Tasks/DTG_BTTask_ClearValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UDTG_BTTask_ClearValue::UDTG_BTTask_ClearValue()
{
	NodeName = "Clear Blackboard Value";
}

EBTNodeResult::Type UDTG_BTTask_ClearValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent())
    {
        BlackboardComponent->ClearValue(GetSelectedBlackboardKey());

        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}
