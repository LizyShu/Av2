// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "AICharacter.h"

AMyAIController::AMyAIController() {
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));

}


void AMyAIController::Possess(APawn* Pawn) {

	Super::Possess(Pawn);

	AAiCharacter* Char = Cast<AAiCharacter>(Pawn);

	if(Char != nullptr && Char->Behavior != nullptr){
		BlackboardComp->InitializeBlackboard(*Char->Behavior->BlackboardAsset);


		EnemmyKeyID = BlackboardComp->GetKeyID("Target");

		BehaviorComp->StartTree(*Char->Behavior);
	}

}




