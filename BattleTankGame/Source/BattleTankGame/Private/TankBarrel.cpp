// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "ConstructorHelpers.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	// Given a max elevation speed, and the frame time
	
	float NewElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	UE_LOG(LogTemp, Warning, TEXT("RawNewElevation = %f"), NewElevation)
	SetRelativeRotation(FRotator(NewElevation, 0, 0));
}

