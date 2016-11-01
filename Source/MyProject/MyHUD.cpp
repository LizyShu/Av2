// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyHUD.h"
#include "Engine/Font.h"
#include "Engine/Canvas.h"
#include "Kismet/GamePlayStatics.h"
#include "MyCharacter.h"



AMyHUD::AMyHUD() {
	static ConstructorHelpers::FObjectFinder<UFont>Font(TEXT("Font'/Engine/EngineFonts/RobotoDistanceField.RobotoDistanceField'"));
	if (Font.Succeeded()) {
		HUDFont = Font.Object;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D> PotionTexture(TEXT("Texture2D'/Game/Textures/Dream_Potion_Sprite.Dream_Potion_Sprite'"));
	if (PotionTexture.Succeeded()) {
			Potion = PotionTexture.Object;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D> ChaveTexture(TEXT("Texture2D'/Game/Textures/14218.14218'"));
	if (ChaveTexture.Succeeded()) {
		MyItemCh = ChaveTexture.Object;
	}

}

void AMyHUD::DrawHUD() {
	Super::DrawHUD();

	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);


	AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	FString	LifeString = FString::Printf(TEXT("Life: %d "), MyCharacter->GetLife());
	DrawText(LifeString, FColor::Red, 250, 10, HUDFont);



	DrawTextureSimple(Potion, ScreenDimensions.X - Potion->GetSizeX()*2, 50, 1.0f, false);
	DrawTexture(Potion, 200, 200, MyCharacter->GetLife(), Potion->GetSizeY(), 0, 0, MyCharacter->GetLife()*3, Potion->GetSizeY(),
	FLinearColor::White, EBlendMode::BLEND_Translucent, 1.0f, false, 0.0f, FVector2D::ZeroVector);

	FString	PotionAmount = FString::Printf(TEXT("X %d "), MyCharacter->GetInventory().Num());
	DrawText(PotionAmount, FColor::Purple, ScreenDimensions.X - Potion->GetSizeX(),50,HUDFont);


	DrawTextureSimple(MyItemCh, ScreenDimensions.X - MyItemCh->GetSizeX() * 2, 150, 1.0f, false);
	DrawTexture(MyItemCh, 200, 200, MyCharacter->GetLife(), MyItemCh->GetSizeY(), 0, 0, MyCharacter->GetLife() * 3, MyItemCh->GetSizeY(),
		FLinearColor::White, EBlendMode::BLEND_Translucent, 1.0f, false, 0.0f, FVector2D::ZeroVector);

	FString	ChaveAmount = FString::Printf(TEXT("X %d "), MyCharacter->GetInventori().Num());
	DrawText(ChaveAmount, FColor::Yellow, ScreenDimensions.X - MyItemCh->GetSizeX(), 150, HUDFont);

}


