// Fill out your copyright notice in the Description page of Project Settings.

#include "Menti_Tanks.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Tank.h"


void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
	Turret = TurretToSet;
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::Fire()
{
	bool isReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTimeInSeconds;
	//UE_LOG(LogTemp, Warning, TEXT("At second %f Tank %s last fire time %f isReloaded %b"), GetWorld()->GetTimeSeconds(),  *GetName(), LastFireTime, isReloaded)
	if (!Barrel || !isReloaded) return;

	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
		);
	Projectile->LaunchProjectile(LaunchSpeed);
	LastFireTime = GetWorld()->GetTimeSeconds();
}

