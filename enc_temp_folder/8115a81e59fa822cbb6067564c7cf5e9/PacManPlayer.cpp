#include "PacManPlayer.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/InputComponent.h"

// Constructor
APacManPlayer::APacManPlayer()
{
    // Set default movement speed
    MovementSpeed = 200.0f;

    // Enable tick so Pac-Man can respond to input every frame
    PrimaryActorTick.bCanEverTick = true;

    // Add a Pawn Movement Component to handle movement
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));
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

    // Bind movement to axis input (setup these axis in the Project Settings -> Input)
    PlayerInputComponent->BindAxis("MoveUp", this, &APacManPlayer::MoveUp);
    PlayerInputComponent->BindAxis("MoveRight", this, &APacManPlayer::MoveRight);
}

// Handle vertical movement (up/down)
void APacManPlayer::MoveUp(float Value)
{
    if (Value != 0.0f)
    {
        // Add movement in the forward direction (world space)
        AddMovementInput(FVector::ForwardVector, Value * MovementSpeed * GetWorld()->GetDeltaSeconds());
    }
}

// Handle horizontal movement (left/right)
void APacManPlayer::MoveRight(float Value)
{
    if (Value != 0.0f)
    {
        // Add movement in the right direction (world space)
        AddMovementInput(FVector::RightVector, Value * MovementSpeed * GetWorld()->GetDeltaSeconds());
    }
}
