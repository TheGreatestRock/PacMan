#include "PacManPlayer.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/InputComponent.h"
#include "Ghost.h"

// Constructor
APacManPlayer::APacManPlayer()
{
    // Set default movement speed
    MovementSpeed = 200.0f;

    // Enable tick so Pac-Man can respond to input every frame
    PrimaryActorTick.bCanEverTick = true;

    // Initialize the current movement direction to zero (stationary)
    CurrentDirection = FVector::ZeroVector;

    Score = 0;
}

// Called when the game starts
void APacManPlayer::BeginPlay()
{
    Super::BeginPlay();
}

// Setup player input
void APacManPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind movement to axis input (setup these axes in the Project Settings -> Input)
    PlayerInputComponent->BindAxis("MoveUp", this, &APacManPlayer::MoveUp);
    PlayerInputComponent->BindAxis("MoveRight", this, &APacManPlayer::MoveRight);
}

// Handle vertical movement (up/down)
void APacManPlayer::MoveUp(float Value)
{
    if (Value != 0.0f)
    {
        // Set movement direction based on input (Y-axis)
        CurrentDirection = FVector(0.0f, (Value > 0 ? -1 : 1) * MovementSpeed, 0.0f);
    }
}

// Handle horizontal movement (left/right)
void APacManPlayer::MoveRight(float Value)
{
    if (Value != 0.0f)
    {
        // Set movement direction based on input (X-axis)
        CurrentDirection = FVector((Value > 0 ? 1 : -1) * MovementSpeed, 0.0f, 0.0f);
    }
}

void APacManPlayer::AddScore(int32 Value)
{
    Score += Value;
}

// Called every frame
void APacManPlayer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Move Pac-Man continuously in the current direction
    if (!CurrentDirection.IsZero())
    {
        FVector Movement = CurrentDirection * DeltaTime;
        MovementComponent->AddInputVector(Movement);
    }
}

