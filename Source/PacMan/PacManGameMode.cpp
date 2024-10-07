// Copyright Epic Games, Inc. All Rights Reserved.

#include "PacManGameMode.h"
#include "PacManCharacter.h"
#include "UObject/ConstructorHelpers.h"

APacManGameMode::APacManGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
