// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankTurret.h"
#include "ConstructorHelpers.h"

void UTankTurret::Rotate(float RotateRelativeSpeed)
{
	// Move the turret the right amount this frame
	RotateRelativeSpeed = FMath::Clamp<float>(RotateRelativeSpeed, -1.0, 1.0);
	auto RotationChange = RotateRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	// Given a max rotation speed, and the frame time
	
	SetRelativeRotation(FRotator(0.0, Rotation, 0.0));
}