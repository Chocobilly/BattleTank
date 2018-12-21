// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "../Public/Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector HitLocation;
	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank) // Has "side-effect", is going to line trace
	{
		// TODO Move toward player tank

		// Aim towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// TODO limit firing rate
		ControlledTank->Fire();
	}
}