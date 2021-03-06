// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "Avalanca2.h"
#include "Porta2.h"



// Sets default values
AAvalanca2::AAvalanca2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	ConstructorHelpers::FObjectFinder<UStaticMesh>
		AlavancaMesh(TEXT("StaticMesh'/Game/StarterContent/Props/SM_MatPreviewMesh_02.SM_MatPreviewMesh_02'"));
	if (AlavancaMesh.Succeeded()) {
		MeshComp->SetStaticMesh(AlavancaMesh.Object);
	}

	ConstructorHelpers::FObjectFinder<UMaterial>
		Material(TEXT("Material'/Game/Material/DamageMaterial.DamageMaterial'"));
	if (Material.Succeeded()) {
		MeshComp->SetMaterial(0, Material.Object);
	}

	MeshComp->SetWorldScale3D(FVector(0.2f, 0.2f, 0.2f));
	RootComponent = MeshComp;

}

// Called when the game starts or when spawned
void AAvalanca2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAvalanca2::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );


}

void AAvalanca2::OnPressed() {
	TArray<AActor*> Portas;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APorta2::StaticClass(), Portas);
	UMaterial* Material;

	if (Portas.Num() > 0) {
		APorta2* Porta = Cast<APorta2>(Portas[0]);



		if (Porta->IsOpen()) {
			Porta->SetOpen(false);
			Material = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(),
				NULL, TEXT("Material'/Game/Material/DamageMaterial.DamageMaterial'")));
			UE_LOG(LogTemp, Warning, TEXT("Fechando a porta!"));
		}
		else {
			Porta->SetOpen(true);
			Material = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(),
				NULL, TEXT("Material'/Game/Material/LifeMaterial.LifeMaterial'")));
			UE_LOG(LogTemp, Warning, TEXT("Abrindo a porta!"));
		}

		if (Material != nullptr) {
			MeshComp->SetMaterial(0, Material);
		}
	}
}

