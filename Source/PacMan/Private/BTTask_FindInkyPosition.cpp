#include "BTTask_FindInkyPosition.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "NavigationSystem.h"  // Include the navigation system for AI movement
#include "Ghost.h"
#include "NavigationSystemTypes.h"  // For FNavLocation
#include "Engine/Engine.h"  // For UE_LOG

UBTTask_FindInkyPosition::UBTTask_FindInkyPosition()
{
    NodeName = "Find Inky Position";
}

EBTNodeResult::Type UBTTask_FindInkyPosition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp)
    {
        UE_LOG(LogTemp, Error, TEXT("Blackboard component not found!"));
        return EBTNodeResult::Failed;
    }

    // Récupérer les positions de Blinky et Pacman depuis le Blackboard
    FVector BlinkyPos = BlackboardComp->GetValueAsVector("BlinkyPosition");
    FVector PacmanPosition = BlackboardComp->GetValueAsVector("PacManLocation");

    // Logs pour vérifier les positions de Blinky et Pacman
    UE_LOG(LogTemp, Log, TEXT("Blinky Position: %s"), *BlinkyPos.ToString());
    UE_LOG(LogTemp, Log, TEXT("Pacman Position: %s"), *PacmanPosition.ToString());

    // Calculer la position cible d'Inky
    FVector BlinkyToPacman = PacmanPosition - BlinkyPos;
    FVector InkyDest = PacmanPosition + BlinkyToPacman;

    // Log pour la destination calculée d'Inky
    UE_LOG(LogTemp, Log, TEXT("Inky Destination (before NavMesh check): %s"), *InkyDest.ToString());

    // Vérifier si la destination est sur le NavMesh
    FNavLocation ProjectedLocation;
    UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
    if (NavSys && NavSys->ProjectPointToNavigation(InkyDest, ProjectedLocation))
    {
        // Log si la destination est valide et sur le NavMesh
        UE_LOG(LogTemp, Log, TEXT("Inky Destination is valid and on the NavMesh: %s"), *ProjectedLocation.Location.ToString());

        // Mettre à jour la destination dans le Blackboard
        BlackboardComp->SetValueAsVector("InkyDestination", ProjectedLocation.Location);
        return EBTNodeResult::Succeeded;
    }
    else
    {
        // Log si la destination n'est pas sur le NavMesh
        UE_LOG(LogTemp, Warning, TEXT("Inky Destination is not on the NavMesh: %s"), *InkyDest.ToString());
        return EBTNodeResult::Failed;
    }
}
