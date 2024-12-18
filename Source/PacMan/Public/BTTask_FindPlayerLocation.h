// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindPlayerLocation.generated.h"

UCLASS()
class PACMAN_API UBTTask_FindPlayerLocation : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_FindPlayerLocation();

protected:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
