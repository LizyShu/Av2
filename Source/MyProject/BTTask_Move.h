// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_Move.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTTask_Move : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


	
	
	
	
};
