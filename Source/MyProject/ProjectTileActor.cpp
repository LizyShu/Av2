// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "ProjectTileActor.h"
#include "MyCharacter.h"



// Sets default values
AProjectTileActor::AProjectTileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("root"));
	Root->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	RootComponent = Root;
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	//Root->OnComponentBeginOverlap.AddDynamic(this, &AProjectTileActor::OnOverlapBegin);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent> (TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);

	}
	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	MeshComp->AttachTo(RootComponent);

	Particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	Particle->bAutoActivate = true;
	
	static ConstructorHelpers::FObjectFinder<UParticleSystem>
		ParticleSystem(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (ParticleSystem.Succeeded()) {
		Particle->SetTemplate(ParticleSystem.Object);
	}

	Particle->SetupAttachment(RootComponent);
	//Particle->ToggleActive();

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = Root;
	ProjectileMovement->InitialSpeed = 3000.0f;
	ProjectileMovement->MaxSpeed = 3000.0f;



	InitialLifeSpan = 5.0f;



}

// Called when the game starts or when spawned
void AProjectTileActor::BeginPlay()
{
	Super::BeginPlay();

	DefaultZ = GetActorLocation().Z;

	
}

// Called every frame
void AProjectTileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();
	Location.Z = DefaultZ;
	SetActorLocation(Location);

	RunningTime += DeltaTime;
	float DestroyTime = 2.0f * RunningTime;
	if (DestroyTime > 2.0f) {
		Destroy();
	}
}




