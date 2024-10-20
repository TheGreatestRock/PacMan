#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindPositionInFront.generated.h"

UCLASS()
class PACMAN_API UBTTask_FindPositionInFront : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_FindPositionInFront();

protected:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
    // Distance in front of PacMan
    UPROPERTY(EditAnywhere, Category = "Search")
    float Distance = 200.0f;
};
