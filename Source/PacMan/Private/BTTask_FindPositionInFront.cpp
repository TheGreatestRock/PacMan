#include "BTTask_FindPositionInFront.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "PacManPlayer.h"

UBTTask_FindPositionInFront::UBTTask_FindPositionInFront()
{
    NodeName = TEXT("Find Position In Front of PacMan");
}

EBTNodeResult::Type UBTTask_FindPositionInFront::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    // Get the PacMan player pawn
    APacManPlayer* PacManPlayer = Cast<APacManPlayer>(UGameplayStatics::GetPlayerPawn(OwnerComp.GetWorld(), 0));

    if (PacManPlayer)
    {
        // Calculate the position in front of PacMan
        FVector PositionInFront = PacManPlayer->GetActorLocation() + (PacManPlayer->GetActorForwardVector() * Distance);

        // Set the location in the blackboard
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("PositionInFront"), PositionInFront);

        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}
