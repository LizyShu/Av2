// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyProjectGameMode.h"
#include "MyHUD.h"
#include "MyCharacter.h"

AMyProjectGameMode::AMyProjectGameMode() {

	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("Blueprint'/Game/Blueprints/Character.Character'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/

	HUDClass = AMyHUD::StaticClass();

	DefaultPawnClass = AMyCharacter::StaticClass();

}


