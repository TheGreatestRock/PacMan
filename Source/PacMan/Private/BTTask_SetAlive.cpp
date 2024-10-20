#include "BTTask_SetAlive.h"
#include "BehaviorTree/BlackboardComponent.h"

// Constructor implementation
UBTTask_SetAlive::UBTTask_SetAlive()
{
    // You can initialize any default values or properties here
    NodeName = TEXT("Set Alive"); // Example: Set the name of the task
}

EBTNodeResult::Type UBTTask_SetAlive::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    // Get the AI controller
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (!AIController)
    {
        return EBTNodeResult::Failed; // No AI Controller
    }

    // Get the ghost
    AGhost* Ghost = Cast<AGhost>(AIController->GetPawn());
    if (Ghost)
    {
        // Apply set alive to ghost
        Ghost->SetAliveMode();
        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed; // Ghost is not valid
}
