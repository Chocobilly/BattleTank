// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankTrack.h"
#include "Engine/Classes/Components/PrimitiveComponent.h"

void UTankTrack::SetThrottle(float Throttle)
{		
		// TODO Clamp so throttle value can't adjust
	
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}