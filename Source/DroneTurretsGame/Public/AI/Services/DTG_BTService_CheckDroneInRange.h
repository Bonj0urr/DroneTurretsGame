// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "DTG_BTService_CheckDroneInRange.generated.h"

UCLASS()
class DRONETURRETSGAME_API UDTG_BTService_CheckDroneInRange : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UDTG_BTService_CheckDroneInRange();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
