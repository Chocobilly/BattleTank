// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankBarrel.h"
#include "ConstructorHelpers.h"

void UTankBarrel::Elevate(float ElevateRelativeSpeed)
{
	// Move the barrel the right amount this frame
	ElevateRelativeSpeed = FMath::Clamp<float>(ElevateRelativeSpeed, -1.0, 1.0);
	auto ElevationChange = ElevateRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	// Given a max elevation speed, and the frame time
	
	float NewElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	
	SetRelativeRotation(FRotator(NewElevation, 0.0, 0.0));
}

