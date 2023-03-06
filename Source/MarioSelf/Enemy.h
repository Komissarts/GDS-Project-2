// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class MARIOSELF_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy")
		class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		FVector StartLocation;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"))
		FVector EndLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
		float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
		float InterpTime;

	FTimerHandle InterpTimer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
		bool bInterping;

	float Distance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ToggleInterping();

	void SwapVectors(FVector& VecOne, FVector& VecTwo);
};
