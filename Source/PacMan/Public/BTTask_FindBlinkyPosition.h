

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindBlinkyPosition.generated.h"

UCLASS()
class PACMAN_API UBTTask_FindBlinkyPosition : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_FindBlinkyPosition();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category = "Blinky")
	TSubclassOf<AActor> BlinkyClass;  // Vous pouvez maintenant sélectionner la classe de Blinky dans l'éditeur
};
