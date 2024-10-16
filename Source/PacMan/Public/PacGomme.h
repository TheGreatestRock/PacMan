// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eatable.h"
#include "PacGomme.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API APacGomme : public AEatable
{
	GENERATED_BODY()

protected:

	virtual void OnEat(AActor* MyActor, AActor* OtherActor);
	
};
