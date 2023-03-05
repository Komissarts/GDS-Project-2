// Copyright Epic Games, Inc. All Rights Reserved.

#include "MarioSelfGameMode.h"
#include "MarioSelfCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMarioSelfGameMode::AMarioSelfGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
