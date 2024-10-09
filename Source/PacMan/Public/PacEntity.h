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
    // Method to setup player input component
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Collision overlap event
    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComponent,
        class AActor* OtherActor,
        class UPrimitiveComponent* OtherComp,
        FVector NormalImpulse,
        const FHitResult& Hit);

    //movement component
	UPROPERTY(VisibleAnywhere)
	class UFloatingPawnMovement* MovementComponent;

protected:
    // Collision Box
    UPROPERTY(VisibleAnywhere)
    class UBoxComponent* CollisionBox;
};
