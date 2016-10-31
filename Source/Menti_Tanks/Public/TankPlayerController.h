// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MENTI_TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
private: 
	
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const; 
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333f;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.f;
};
