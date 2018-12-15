// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "../Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();

	FVector GetSightRayHitLocation();

	FVector GetReachLineEnd();
	FVector GetReachLineStart();

	UPROPERTY(EditAnywhere)
	float Reach = 10000.0f;

	// return OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
