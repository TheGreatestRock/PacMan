// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindBlinkyPosition.h"

#include "EngineUtils.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"  // For UE_LOG

UBTTask_FindBlinkyPosition::UBTTask_FindBlinkyPosition()
{
	NodeName = TEXT("Find Blinky Position");
}

EBTNodeResult::Type UBTTask_FindBlinkyPosition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Récupérer le Blackboard
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp)
	{
		return EBTNodeResult::Failed;
	}

	// Vérifier si la classe de Blinky est définie
	if (!BlinkyClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Blinky class is not set"));
		return EBTNodeResult::Failed;
	}

	// Récupérer tous les acteurs de la classe de Blinky dans la scène
	TArray<AActor*> FoundBlinkyActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), BlinkyClass, FoundBlinkyActors);

	// Si un acteur de la classe de Blinky est trouvé, récupérer sa position
	if (FoundBlinkyActors.Num() > 0)
	{
		AActor* BlinkyActor = FoundBlinkyActors[0]; // On suppose qu'il n'y a qu'un seul Blinky
		if (BlinkyActor)
		{
			BlackboardComp->SetValueAsVector("BlinkyPosition", BlinkyActor->GetActorLocation());
			return EBTNodeResult::Succeeded;
		}
	}

	// Si Blinky n'est pas trouvé, échouer
	UE_LOG(LogTemp, Warning, TEXT("Blinky not found"));
	return EBTNodeResult::Failed;
}