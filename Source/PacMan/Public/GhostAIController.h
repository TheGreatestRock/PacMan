#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h" // Ajout de l'inclusion manquante
#include "GhostAIController.generated.h"

UCLASS()
class PACMAN_API AGhostAIController : public AAIController
{
    GENERATED_BODY()

public:
    AGhostAIController();

protected:
    virtual void OnPossess(APawn* InPawn) override;

private:
    UPROPERTY(Transient)
    UBehaviorTreeComponent* BehaviorComp;

    UPROPERTY(Transient)
    UBlackboardComponent* BlackboardComp;

    // For convenience: Blackboard key selectors
    FName TargetLocationKey;
    FName IsDeadKey;
    FName IsFrightenedKey;
};