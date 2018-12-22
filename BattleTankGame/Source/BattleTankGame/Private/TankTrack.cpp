// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankTrack.h"
#include "Engine/Classes/Components/PrimitiveComponent.h"

void UTankTrack::SetThrottle(float Throttle)
{		
	Throttle = FMath::Clamp<float>(Throttle, -1.0, 1.0);	// TODO Clamp so throttle value can't adjust
	
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}