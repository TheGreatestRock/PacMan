// Fill out your copyright notice in the Description page of Project Settings.


#include "Eatable.h"
#include "Components/BoxComponent.h"
//#include "PacManPlayer.h"

// Sets default values
AEatable::AEatable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    // Create BoxComponent and set as RootComponent for the Actor
    BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
    RootComponent = BoxCollision;

    // Create StaticMeshComponent and Attach to BoxComponent
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(BoxCollision);

}

// Called when the game starts or when spawned
void AEatable::BeginPlay()
{
	Super::BeginPlay();

    // Bind function OnActorBeginOverlap with your class function OnOverlap
    this->OnActorBeginOverlap.AddDynamic(this, &AEatable::OnOverlap);
	
}

void AEatable::OnEat(AActor* MyActor, AActor* OtherActor)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Miam"));
    //if (OtherActor && OtherActor->IsA(APacManPlayer::StaticClass()))
    //{
    //    // Destroy the FallingBonus
    //    MyActor->Destroy();

    //    // Increment the bonus counter
    //    Score++;

    //}
    MyActor->Destroy();
}

void AEatable::OnOverlap(AActor* MyActor, AActor* OtherActor)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Overlap"));
    OnEat(MyActor, OtherActor);
}
