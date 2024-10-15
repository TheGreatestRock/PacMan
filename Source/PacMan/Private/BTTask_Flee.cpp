#include "BTTask_Flee.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "NavigationSystem.h"  // Include the navigation system for AI movement
#include "Kismet/GameplayStatics.h"
#include "NavigationSystemTypes.h"  // For FNavLocation
#include "Engine/Engine.h"  // For UE_LOG

UBTTask_Flee::UBTTask_Flee()
{
    NodeName = TEXT("Flee");
}

EBTNodeResult::Type UBTTask_Flee::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController)
    {
        UBlackboardComponent* BlackboardComp = AIController->GetBlackboardComponent();
        if (BlackboardComp)
        {
            // Get the position to flee from (stored in the blackboard)
            FVector FleeFromPosition = BlackboardComp->GetValueAsVector(TargetPositionKey.SelectedKeyName);

            // Get current location of AI
            FVector CurrentLocation = AIController->GetPawn()->GetActorLocation();

            // Log current locations
            UE_LOG(LogTemp, Warning, TEXT("Current AI Location: %s"), *CurrentLocation.ToString());
            UE_LOG(LogTemp, Warning, TEXT("Flee From Position: %s"), *FleeFromPosition.ToString());

            // Use NavigationSystem to find a valid flee location
            UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
            if (NavSystem)
            {
                FNavLocation FleeNavLocation;  // This will hold the result from the navigation system

                // Find a random reachable point in radius away from the FleeFromPosition
                if (NavSystem->GetRandomReachablePointInRadius(FleeFromPosition, 10000.0f, FleeNavLocation))
                {
                    // Ensure that the new flee location keeps the same Z value as the AI's current position
                    FVector NewFleeLocation = FleeNavLocation.Location;
                    NewFleeLocation.Z = CurrentLocation.Z;

                    // Log the new flee location
                    UE_LOG(LogTemp, Warning, TEXT("New Flee Location (with same Z): %s"), *NewFleeLocation.ToString());

                    // Update the blackboard with the new flee location
                    BlackboardComp->SetValueAsVector(FleeLocationKey.SelectedKeyName, NewFleeLocation);

                    // Move the AI to the flee location (optional: only if you want the AI to move immediately)
                    AIController->MoveToLocation(NewFleeLocation);

                    return EBTNodeResult::Succeeded; // Task completed successfully
                }
                else
                {
                    // Log failure to find a flee location
                    UE_LOG(LogTemp, Error, TEXT("Failed to find a valid flee location!"));
                }
            }
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Blackboard Component is null!"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("AI Controller is null!"));
    }

    return EBTNodeResult::Failed;
}
