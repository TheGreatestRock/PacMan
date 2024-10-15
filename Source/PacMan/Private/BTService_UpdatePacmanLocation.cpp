#include "BTService_UpdatePacmanLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTService_UpdatePacmanLocation::UBTService_UpdatePacmanLocation()
{
    PlayerLocationKey = "PacManLocation";  // Set the name of the blackboard key
}

void UBTService_UpdatePacmanLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    // Get the Pac-Man actor (assuming Pac-Man is player 0)
    APawn* PacmanPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    if (PacmanPawn)
    {
        // Update the Blackboard with Pac-Man's location
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(PlayerLocationKey, PacmanPawn->GetActorLocation());
        // Print player location
        FVector PlayerLocation = PacmanPawn->GetActorLocation();
        UE_LOG(LogTemp, Warning, TEXT("Player Location: %s"), *PlayerLocation.ToString());

    }
}
