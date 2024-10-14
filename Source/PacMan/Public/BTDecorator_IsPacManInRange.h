#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsPacManInRange.generated.h"

/**
 * Decorator to check if Pac-Man is within a certain range of the AI-controlled character (Clyde).
 */
UCLASS()
class PACMAN_API UBTDecorator_IsPacManInRange : public UBTDecorator
{
    GENERATED_BODY()

public:
    // Constructor
    UBTDecorator_IsPacManInRange();

protected:
    // Override the function to calculate the condition value
    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
