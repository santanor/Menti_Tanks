// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collisions"))
class MENTI_TANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//-1 is downward speed, +1 y forward speed
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 40;

};
