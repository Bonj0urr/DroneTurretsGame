// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "DTG_BTTask_ShootDrone.generated.h"

UCLASS()
class DRONETURRETSGAME_API UDTG_BTTask_ShootDrone : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UDTG_BTTask_ShootDrone();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
