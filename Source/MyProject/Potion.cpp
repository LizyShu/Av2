// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "Potion.h"


APotion::APotion() {
	ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	if(Mesh.Succeeded()) {
		GetMeshComp()->SetStaticMesh(Mesh.Object);

	}

	GetMeshComp()->SetWorldScale3D(FVector(0.4f, 0.4f, 0.4f));
}

int APotion::Use() {
	return FMath::RandRange(1, 10);

}


