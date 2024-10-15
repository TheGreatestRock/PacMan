#pragma once

#include "PacEntity.h" // Include your base class header
#include "Ghost.generated.h"

// Forward declaration for AI controller
class AGhostAIController;

// The AGhost class represents the ghost character in your Pac-Man game
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
    // Function called when the ghost overlaps with another actor
    UFUNCTION()
    void OnOverlap();

    // Set the ghost to "Alive" mode (chasing)
    UFUNCTION(BlueprintCallable, Category = "AI")
    void SetAliveMode();

    // Set the ghost to "Dead" mode (returning to base)
    UFUNCTION(BlueprintCallable, Category = "AI")
    void SetDeadMode();

    // Set the ghost to "Frightened" mode (running away)
    UFUNCTION(BlueprintCallable, Category = "AI")
    void SetFrightenMode();

    // Function to update the ghost's state in the blackboard
    UFUNCTION(BlueprintCallable, Category = "AI")
    void UpdateBlackboardStates();

protected:
    // State flags
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    bool bIsDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    bool bIsFrightened;

    // Behavior Tree asset for the ghost's AI
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    class UBehaviorTree* TreeAsset;

    // Function to get the AI controller for this ghost
    AGhostAIController* GetGhostAIController() const;
};
