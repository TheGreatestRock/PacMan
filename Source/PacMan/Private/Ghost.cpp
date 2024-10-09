#include "Ghost.h"

// Constructor
AGhost::AGhost()
{
    bIsDead = false;
    bIsFrightened = false;
}

// Called when the game starts
void AGhost::BeginPlay()
{
    Super::BeginPlay();
    // Initialize ghost state
}

// Handle overlap with Pac-Man or other entities
void AGhost::OnOverlap()
{
    // Logic for handling overlaps with Pac-Man
    if (bIsFrightened)
    {
        SetDeadMode();
    }
    else
    {
        // Logic when not frightened (possibly chasing Pac-Man)
        UE_LOG(LogTemp, Warning, TEXT("Ghost has overlapped with Pac-Man!"));
    }
}

// Set ghost to alive mode
void AGhost::SetAliveMode()
{
    bIsDead = false;
    UE_LOG(LogTemp, Warning, TEXT("Ghost is alive."));
}

// Set ghost to dead mode
void AGhost::SetDeadMode()
{
    bIsDead = true;
    UE_LOG(LogTemp, Warning, TEXT("Ghost is dead."));
}

// Set ghost to frightened mode
void AGhost::SetFrightenMode()
{
    bIsFrightened = true;
    UE_LOG(LogTemp, Warning, TEXT("Ghost is frightened."));
}
