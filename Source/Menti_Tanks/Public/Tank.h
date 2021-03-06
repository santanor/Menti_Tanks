// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class AProjectile;
class UTankBarrel;
class UTankTurret;

UCLASS()
class MENTI_TANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	

	UFUNCTION(BluePrintCallable, Category=Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	UFUNCTION(BluePrintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BluePrintCallable, Category=Firing)
	void Fire();

protected:

	//UPROPERTY()
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 8000.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	

	UPROPERTY(EditAnywhere, Category = Firing)
	float ReloadTimeInSeconds = 3;
	float LastFireTime = 0;
};
