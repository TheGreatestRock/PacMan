// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperPacGomme.h"
#include "Ghost.h"
#include <Kismet/GameplayStatics.h>

void ASuperPacGomme::OnEat(AActor* MyActor, AActor* OtherActor)
{
	Super::OnEat(MyActor, OtherActor);

    TArray<AActor*> FoundGhosts;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGhost::StaticClass(), FoundGhosts);

    // Mettre chaque fantôme en mode effrayé
    for (AActor* Actor : FoundGhosts)
    {
        AGhost* Ghost = Cast<AGhost>(Actor);
        if (Ghost)
        {
            Ghost->SetFrightenMode();
        }
    }
}
