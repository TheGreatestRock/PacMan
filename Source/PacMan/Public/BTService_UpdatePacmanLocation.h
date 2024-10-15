#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_UpdatePacmanLocation.generated.h"

UCLASS()
class PACMAN_API UBTService_UpdatePacmanLocation : public UBTService
{
    GENERATED_BODY()

public:
    UBTService_UpdatePacmanLocation();

protected:
    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

    // The name of the Blackboard key where Pac-Man's location will be stored
    UPROPERTY(EditAnywhere, Category = "Blackboard")
    FName PlayerLocationKey;
};
