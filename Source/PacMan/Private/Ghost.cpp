#include "Ghost.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIController.h"

// Constructor
AGhost::AGhost()
{
    // Initialize state flags
    bIsDead = false;
    bIsFrightened = false;
}

void AGhost::BeginPlay()
{
    Super::BeginPlay();

    // Setup AI controller and run behavior tree
    AAIController* AIController = Cast<AAIController>(GetController());
    if (AIController && TreeAsset)
    {
        AIController->RunBehaviorTree(TreeAsset);
    }
}

// Overlap event to handle interactions with Pac-Man or other entities
void AGhost::OnOverlap()
{
    if (bIsFrightened)
    {
        SetDeadMode();
    }
    else
    {
        // Logic for interaction with Pac-Man when not frightened
        // E.g., Pac-Man loses a life if ghost is not dead and not frightened
    }
}

// Set the ghost to "Alive" mode (chasing)
void AGhost::SetAliveMode()
{
    bIsDead = false;
    bIsFrightened = false;

    // Here you might want to set AI behavior to chase Pac-Man
    // Example: Run a different part of the behavior tree
}

// Set the ghost to "Dead" mode (returning to base)
void AGhost::SetDeadMode()
{
    bIsDead = true;

    // Possibly stop the current behavior tree and run one where the ghost returns to spawn
    // Example: AI logic to navigate back to a safe zone
}

// Set the ghost to "Frightened" mode (running away)
void AGhost::SetFrightenMode()
{
    bIsFrightened = true;

    // Adjust the AI behavior, possibly start running away from Pac-Man
    // Example: You could trigger a behavior that finds random locations
}
