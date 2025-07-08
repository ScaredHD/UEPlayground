// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugTest.h"

#include "Engine/Canvas.h"

// Sets default values
ADebugTest::ADebugTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADebugTest::BeginPlay()
{
	Super::BeginPlay();

	DebugValue = FMath::RandRange(0, 100);
	
}

// Called every frame
void ADebugTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADebugTest::DisplayDebug(class UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL,
	float& YPos)
{
	FDisplayDebugManager& DisplayDebugManager = Canvas->DisplayDebugManager;
	DisplayDebugManager.SetDrawColor(FColor(255, 0, 0));

	if (Canvas)
	{
		FString DebugString = FString::Printf(TEXT("DebugTestActor.DebugValue = %d"), DebugValue);
		DisplayDebugManager.DrawString(DebugString);
	}
}

