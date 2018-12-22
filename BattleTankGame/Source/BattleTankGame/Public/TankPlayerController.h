// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();

	// return OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector & HitLocation) const;
	bool GetLookVectorHitLocation(FVector & LookDirection, FVector & HitLocation) const;
	bool GetLookDirection(FVector2D & ScreenLocation, FVector & LookDirection) const;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.33333;

protected:
	UFUNCTION(BluePrintCallable, Category = Setup)
	ATank* GetControlledTank() const;
};
