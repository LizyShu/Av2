// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "BTTask_Move.h"
#include "MyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "MyCharacter.h"


EBTNodeResult::Type UBTTask_Move::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {


	AMyAIController *PC = Cast<AMyAIController>(OwnerComp.GetAIOwner());


	AMyCharacter* Player = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(PC->EnemmyKeyID));

	if (Player != nullptr) {
		PC->MoveToActor(Player, 20.0f, true, true, true, 0, true);
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "seguindo!");
		return EBTNodeResult::Succeeded;

	}

	return EBTNodeResult::Failed;

}




