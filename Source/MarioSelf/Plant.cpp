// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"
#include "TimerManager.h"

// Sets default values
APlant::APlant()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StartLocation = FVector(0.f);
	EndLocation = FVector(0.f);

	InterpSpeed = 2.0f;
	InterpTime = 1.f;
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	EndLocation += StartLocation;

	GetWorldTimerManager().SetTimer(InterpTimer, this, &APlant::ToggleInterping, InterpTime);

	Distance = (EndLocation - StartLocation).Size();
}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bInterping)
	{
		FVector CurrentLoc = GetActorLocation();
		FVector Interp = FMath::VInterpTo(CurrentLoc, EndLocation, DeltaTime, InterpSpeed);
		SetActorLocation(Interp);

		float DistanceTravelled = (GetActorLocation() - StartLocation).Size();
		if (Distance - DistanceTravelled <= 1.f)
		{
			ToggleInterping();

			GetWorldTimerManager().SetTimer(InterpTimer, this, &APlant::ToggleInterping, InterpTime);
			SwapVectors(StartLocation, EndLocation);
		}
	}
}

void APlant::ToggleInterping()
{
	bInterping = !bInterping;
}

void APlant::SwapVectors(FVector& VecOne, FVector& VecTwo)
{
	FVector Temp = VecOne;
	VecOne = VecTwo;
	VecTwo = Temp;
}

/*
// Called to bind functionality to input
void APlant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
*/

