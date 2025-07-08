// Fill out your copyright notice in the Description page of Project Settings.


#include "PlaygroundPawn.h"
#include "Engine/Canvas.h"

// Sets default values
APlaygroundPawn::APlaygroundPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlaygroundPawn::BeginPlay()
{
	Super::BeginPlay();

	DebugValue = FMath::RandRange(0, 100);
}

// Called every frame
void APlaygroundPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlaygroundPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlaygroundPawn::DisplayDebug(class UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL,
                                   float& YPos)
{
	Super::DisplayDebug(Canvas, DebugDisplay, YL, YPos);

	if (Canvas)
	{
		FDisplayDebugManager& DisplayDebugManager = Canvas->DisplayDebugManager;
		DisplayDebugManager.SetDrawColor(FColor(128, 50, 80));

		FString DebugString = FString::Printf(TEXT("PlaygroundPawn.DebugValue = %d"), DebugValue);
		DisplayDebugManager.DrawString(DebugString);
	}
}
