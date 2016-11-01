// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class MYPROJECT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void SetLife(int NewLife);
	int GetLife();


	FORCEINLINE int GetNewLine() const { return Life; }
	FORCEINLINE void AMyCharacter::GetNewLine(int NewLine) { Life = NewLine; }
	FORCEINLINE TArray<class AItem*>GetInventory() const { return Inventory; }
	FORCEINLINE TArray<class AItemCh*>GetInventori() const { return Inventori; }

	void OnDeath();

	
	
private: 
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere)
		UCameraComponent* PlayerCamera;

	UPROPERTY(EditAnywhere)
		USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere)
	int Life = 3;

	UPROPERTY(EditAnywhere)
		UAnimSequence* JumpAnim;


	UPROPERTY(EditAnywhere)
		UArrowComponent* ArrowComp;


	USphereComponent* CollectCollisionComp;
	TArray<class AItem*> Inventory;
	TArray<class AItemCh*> Inventori;
	TSubclassOf<class UUserWidget> UserWidget;

	USoundCue* FireSound;
	UAudioComponent* AudioComp;

	void MoveForward(float value);
	void MoveRight(float Value);
	void StartRun();
	void StopRun();
	void Jump();
	void DropProjectile();
	void Turn(float Value);
	void OnCollect();
	void OnCollectKey();
	void Pause();



	UPROPERTY(EditAnywhere)
		float DamageAmount = -1;

	//OnHit
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			FVector NormalImpulse, const FHitResult & Hit);


	
};
