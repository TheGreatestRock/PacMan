#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Ghost.h"
#include "AIController.h"
#include "BTTask_SetAlive.generated.h"

/**
 *
 */
UCLASS()
class PACMAN_API UBTTask_SetAlive : public UBTTaskNode
{
    GENERATED_BODY()

public:
    // Constructor
    UBTTask_SetAlive();

protected:
    // Override the ExecuteTask method
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};