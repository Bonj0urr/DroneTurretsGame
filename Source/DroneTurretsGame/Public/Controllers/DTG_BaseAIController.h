// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DTG_BaseAIController.generated.h"

class UBehaviorTree;
class UAIPerceptionComponent;

UCLASS()
class DRONETURRETSGAME_API ADTG_BaseAIController : public AAIController
{
	GENERATED_BODY()

public:
	ADTG_BaseAIController();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void HandleStimulusUpdate(AActor* Actor, FAIStimulus Stimulus);

	void HandleSightSense(AActor* Actor, FAIStimulus Stimulus);
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DTG|AI", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "DTG|AI", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAIPerceptionComponent> AIPerceptionComponent;
};
