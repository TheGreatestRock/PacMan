// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindPlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTTask_FindPlayerLocation::UBTTask_FindPlayerLocation()
{
    NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UBTTask_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    // Get the player pawn
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(OwnerComp.GetWorld(), 0);
    if (PlayerPawn)
    {
        // Get the player's location
        FVector PlayerLocation = PlayerPawn->GetActorLocation();

        // Set the location in the blackboard
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("PacManLocation"), PlayerLocation);

        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}
