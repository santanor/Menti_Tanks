// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories=("Collisions"))
class MENTI_TANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is downward speed, +1 y forward speed
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 5;

	UPROPERTY(EditAnywhere)
	float MAxElevationDegrees = 20;

	UPROPERTY(EditAnywhere)
	float MinDegreesPerSecond = 0;
	
	
};
