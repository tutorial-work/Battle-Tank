// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
    ATank* PlayerTank = GetPlayerTank();
    
    // Log AI Tank
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
	}
    
    // Log Player Tank
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player not possessing a Tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Player possessing: %s"), *(PlayerTank->GetName()));
    }

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!PlayerPawn)
    {
        return nullptr;
    }
    return Cast<ATank>(PlayerPawn);
}
