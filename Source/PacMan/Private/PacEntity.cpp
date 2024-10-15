#include "PacEntity.h"
#include "Components/BoxComponent.h"

#include "PacEntity.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"


// Constructor
APacEntity::APacEntity()
{
    // Create movement component
    MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));

    // Create a collision box
    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    CollisionBox->SetupAttachment(RootComponent); // Attach to root component
}


// Called when the game starts
void APacEntity::BeginPlay()
{
    Super::BeginPlay();
}

// Setup player input component
void APacEntity::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Handle overlap events
void APacEntity::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    FVector NormalImpulse,
    const FHitResult& Hit)
{
    // Logic for handling overlaps (e.g. collecting items or collision with ghosts)
    if (OtherActor)
    {
        UE_LOG(LogTemp, Warning, TEXT("Overlapped with: %s"), *OtherActor->GetName());
    }
}
