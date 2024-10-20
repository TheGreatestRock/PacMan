#pragma once

#include "PacEntity.h"
#include "PacManPlayer.generated.h"

UCLASS()
class PACMAN_API APacManPlayer : public APacEntity
{
    GENERATED_BODY()

public:
    // Constructor
    APacManPlayer();

protected:
    virtual void BeginPlay() override;

public:
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Custom method for handling movement input
    void MoveUp(float Value);
    void MoveRight(float Value);
    void AddScore(int32 Value);

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    FVector GetPositionInFront(float Distance) const;

protected:
    // Score property
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Score;

    FVector CurrentDirection;

    // Movement speed of Pac-Man
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float MovementSpeed;
};
