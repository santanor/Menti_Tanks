// Fill out your copyright notice in the Description page of Project Settings.

#include "Menti_Tanks.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto playerTank = GetPlayerTank();

	if (playerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player controlled tank: %s"), *(playerTank->GetName()))
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (playerPawn) 
	{
		return Cast<ATank>(playerPawn);
	}
	return nullptr;
	 
}