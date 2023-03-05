// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Plant.generated.h"

UCLASS()
class MARIOSELF_API APlant : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlant();

	UPROPERTY(EditAnywhere)
	FVector StartLocation;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"))
	FVector EndLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plant")
	float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plant")
	float InterpTime;

	FTimerHandle InterpTimer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plant")
	bool bInterping;

	float Distance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	*/

	void ToggleInterping();

	void SwapVectors(FVector& VecOne, FVector& VecTwo);

};
