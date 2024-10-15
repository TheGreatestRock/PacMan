#pragma once

#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h" // Include this header
#include "GhostAIController.generated.h"

UCLASS()
class PACMAN_API AGhostAIController : public AAIController
{
    GENERATED_BODY()

public:
    AGhostAIController();

    virtual void OnPossess(APawn* InPawn) override;

protected:
    UPROPERTY(EditDefaultsOnly, Category = "AI")
    UBehaviorTree* BehaviorTreeAsset; // Reference to the Behavior Tree asset

    UPROPERTY(EditDefaultsOnly, Category = "AI")
    UBlackboardData* BlackboardAsset; // Reference to the Blackboard asset

    UBehaviorTreeComponent* BehaviorComp;
    UBlackboardComponent* BlackboardComp;

    // Blackboard keys
    FName TargetLocationKey;
    FName IsDeadKey;
    FName IsFrightenedKey;
};
