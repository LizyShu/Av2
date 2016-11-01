// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyItemCh.h"
#include "Avalanca.h"


AMyItemCh::AMyItemCh() {
	ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	if (Mesh.Succeeded()) {
		GetMeshComp()->SetStaticMesh(Mesh.Object);

	}

	GetMeshComp()->SetWorldScale3D(FVector(0.4f, 0.4f, 0.4f));
}

int AMyItemCh::Use() {
	return FMath::RandRange(1, 10);

}



