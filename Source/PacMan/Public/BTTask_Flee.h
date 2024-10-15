#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Flee.generated.h"

/**
 * Task that makes an AI flee from a specific position stored in the blackboard.
 */
UCLASS()
class PACMAN_API UBTTask_Flee : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_Flee();

protected:
    /** Executes the task when called in the behavior tree */
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

    /** The blackboard key to specify the position the AI should flee from */
    UPROPERTY(EditAnywhere, Category = "Blackboard")
    FBlackboardKeySelector TargetPositionKey;

    /** The blackboard key to store the new flee location */
    UPROPERTY(EditAnywhere, Category = "Blackboard")
    FBlackboardKeySelector FleeLocationKey;
};
