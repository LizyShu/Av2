// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyActor2.h"
#include "MyCharacter.h"


// Sets default values
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent >(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &AMyActor2::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoColision");
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector LocalizacaoAtual = GetActorLocation();
	

	if(LocalizacaoAtual.X != LocalizacaoAtual.Y){
		float DeltaHeight = (FMath::Sin(RunningTime - DeltaTime) - FMath::Sin(RunningTime));
		LocalizacaoAtual.X -= DeltaHeight * 400;
		RunningTime -= DeltaTime;
		SetActorLocation(LocalizacaoAtual);
	}




	if (LocalizacaoAtual.Y != LocalizacaoAtual.X) {
		float DeltaHeight = (FMath::Sin(RunningTime1 + DeltaTime) - FMath::Sin(RunningTime1));
		LocalizacaoAtual.Y += DeltaHeight * 400;
		RunningTime1 += DeltaTime;
		SetActorLocation(LocalizacaoAtual);
	}



	if (LocalizacaoAtual.X != LocalizacaoAtual.Y) {
		float DeltaHeight = (FMath::Sin(RunningTime2 - DeltaTime) - FMath::Sin(RunningTime2));
		LocalizacaoAtual.X -= DeltaHeight * 400;
		RunningTime2 -= DeltaTime;
		SetActorLocation(LocalizacaoAtual);
	}



	if (LocalizacaoAtual.Y != LocalizacaoAtual.X) {
		float DeltaHeight = (FMath::Sin(RunningTime3 + DeltaTime) - FMath::Sin(RunningTime3));
		LocalizacaoAtual.Y += DeltaHeight * 400;
		RunningTime3 += DeltaTime;
		SetActorLocation(LocalizacaoAtual);
	}


	
}

void AMyActor2::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass()))) {

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetLife(MyCharacter->GetLife() + DamageAmount);
		MyCharacter->OnDeath();
		UE_LOG(LogTemp, Warning, TEXT("Life = %d"), MyCharacter->GetLife());

	}
}






