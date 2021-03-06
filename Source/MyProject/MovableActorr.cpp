// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MovableActorr.h"


// Sets default values
AMovableActorr::AMovableActorr()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->SetSimulatePhysics(true);
	Root->SetCollisionProfileName("PhysicsActor");
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);


}

// Called when the game starts or when spawned
void AMovableActorr::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovableActorr::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

