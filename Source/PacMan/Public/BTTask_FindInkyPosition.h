#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindInkyPosition.generated.h"

/**
 * Task that makes an AI flee from a specific position stored in the blackboard.
 */
UCLASS()
class PACMAN_API UBTTask_FindInkyPosition : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_FindInkyPosition();

protected:
    /** Executes the task when called in the behavior tree */
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

    // Clés du Blackboard pour les positions de Blinky et Pacman
    UPROPERTY(EditAnywhere, Category = "Blackboard")
    FName BlinkyPosition;

    UPROPERTY(EditAnywhere, Category = "Blackboard")
    FName PacManLocation;

    // Clé du Blackboard pour la destination calculée d'Inky
    UPROPERTY(EditAnywhere, Category = "Blackboard")
    FName InkyDestination;
};
