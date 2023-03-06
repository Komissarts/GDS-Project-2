// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	StartLocation = FVector(0.f);
	EndLocation = FVector(0.f);

	InterpSpeed = 500.0f;
	InterpTime = 1.f;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	EndLocation += StartLocation;

	GetWorldTimerManager().SetTimer(InterpTimer, this, &AEnemy::ToggleInterping, InterpTime);

	Distance = (EndLocation - StartLocation).Size();
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bInterping)
	{
		FVector CurrentLoc = GetActorLocation();
		FVector Interp = FMath::VInterpConstantTo(CurrentLoc, EndLocation, DeltaTime, InterpSpeed);
		SetActorLocation(Interp);

		float DistanceTravelled = (GetActorLocation() - StartLocation).Size();
		if (Distance - DistanceTravelled <= 1.f)
		{
			ToggleInterping();

			GetWorldTimerManager().SetTimer(InterpTimer, this, &AEnemy::ToggleInterping, InterpTime);
			SwapVectors(StartLocation, EndLocation);
		}
	}

	
}

void AEnemy::ToggleInterping()
{
	bInterping = !bInterping;
}

void AEnemy::SwapVectors(FVector& VecOne, FVector& VecTwo)
{
	FVector Temp = VecOne;
	VecOne = VecTwo;
	VecTwo = Temp;
}

