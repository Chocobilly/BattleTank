// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKGAME_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	// -1 is max downward speed, and +1 is max upward speed
	void Rotate(float RotateRelativeSpeed);

private:

	UPROPERTY(EditDefaultsOnly)
	float MaxDegreesPerSecond = 25.0;
};
