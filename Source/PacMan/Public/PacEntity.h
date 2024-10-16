#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PacEntity.generated.h"

UCLASS()
class PACMAN_API APacEntity : public APawn
{
    GENERATED_BODY()

public:
    // Constructor
    APacEntity();

protected:
    virtual void BeginPlay() override;

public:
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
    // Collision box component
    UPROPERTY(VisibleAnywhere)
    class UBoxComponent* CollisionBox;

    // Movement component
    UPROPERTY(VisibleAnywhere)
    class UFloatingPawnMovement* MovementComponent;
};
