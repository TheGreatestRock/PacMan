// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Eatable.generated.h"

UCLASS()
class PACMAN_API AEatable : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* StaticMesh;

public:	
	// Sets default values for this actor's properties
	AEatable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnEat(AActor* MyActor, AActor* OtherActor);

private:
	UFUNCTION()
	void OnOverlap(AActor* MyActor, AActor* OtherActor);

};
