#include "BTTask_Flee.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Actor.h"

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
            AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject(TargetActorKey.SelectedKeyName));
            if (TargetActor)
            {
                FVector CurrentLocation = AIController->GetPawn()->GetActorLocation();
                FVector DirectionToFlee = CurrentLocation - TargetActor->GetActorLocation();
                DirectionToFlee.Normalize();

                FVector FleeLocation = CurrentLocation + (DirectionToFlee * 1000); // Adjust this multiplier as needed
                AIController->MoveToLocation(FleeLocation);

                return EBTNodeResult::InProgress; // You may want to check the condition to return Success or Failure
            }
        }
    }
    return EBTNodeResult::Failed;
}
