#pragma once

#include "PacEntity.h"
#include "Ghost.generated.h"

UCLASS()
class PACMAN_API AGhost : public APacEntity
{
    GENERATED_BODY()

public:
    // Constructor
    AGhost();

protected:
    virtual void BeginPlay() override;

public:
    UFUNCTION()
    void OnOverlap();

    void SetAliveMode();

    void SetDeadMode();
    void SetFrightenMode();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    class UBehaviorTree* TreeAsset;

protected:

    // State flags
    UPROPERTY(EditAnywhere)
    bool bIsDead;

    UPROPERTY(EditAnywhere)
    bool bIsFrightened;
};
