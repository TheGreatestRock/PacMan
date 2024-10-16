#include "PacEntity.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"


// Constructor
APacEntity::APacEntity()
{
    // Create movement component
    MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));
	MovementComponent->MaxSpeed = 80.0f; // Set max speed

    // Create a collision box
    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    RootComponent = CollisionBox; // Set as root component
}

// Called when the game starts
void APacEntity::BeginPlay()
{
    Super::BeginPlay();
}

// Setup player input
void APacEntity::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

