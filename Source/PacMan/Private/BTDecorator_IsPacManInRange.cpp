#include "BTDecorator_IsPacManInRange.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PacManPlayer.h"
#include "GameFramework/Pawn.h"

UBTDecorator_IsPacManInRange::UBTDecorator_IsPacManInRange()
{
    NodeName = "Is PacMan In Range";
}

bool UBTDecorator_IsPacManInRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

    // Get the AI Controller and the controlled Pawn (Clyde)
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (!AIController)
    {
        return false;
    }

    APawn* ControlledPawn = AIController->GetPawn();
    if (!ControlledPawn)
    {
        return false;
    }

    // Get the Blackboard component
    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp)
    {
        return false;
    }

    // Get Pac-Man's location from the Blackboard
    FVector PacManLocation = BlackboardComp->GetValueAsVector("PacManLocation");
    FVector ClydeLocation = ControlledPawn->GetActorLocation();

    // Calculate the distance between Pac-Man and Clyde
    float DistanceToPacMan = FVector::Dist(ClydeLocation, PacManLocation);

    // Set a threshold distance (you can modify this as needed)
    float ThresholdDistance = 500.0f; // Example: 500 units

    // Return true if Pac-Man is within range
    return DistanceToPacMan <= ThresholdDistance;
}
