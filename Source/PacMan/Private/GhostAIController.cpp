#include "GhostAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Ghost.h"

AGhostAIController::AGhostAIController()
{
    BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
    BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));

    // Set blackboard keys
    TargetLocationKey = "TargetLocation";
    IsDeadKey = "IsDead";
    IsFrightenedKey = "IsFrightened";
}

void AGhostAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    AGhost* GhostCharacter = Cast<AGhost>(InPawn);
    if (GhostCharacter && BehaviorTreeAsset && BlackboardAsset)
    {
        // Initialize blackboard
        BlackboardComp->InitializeBlackboard(*BlackboardAsset);

        // Start the behavior tree
        BehaviorComp->StartTree(*BehaviorTreeAsset);
    }
}
