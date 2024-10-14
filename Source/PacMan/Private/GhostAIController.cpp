#include "GhostAIController.h"  
#include "BehaviorTree/BlackboardComponent.h"  
#include "BehaviorTree/BehaviorTreeComponent.h"  
#include "BehaviorTree/BehaviorTree.h"  // Ajout de cette ligne
#include "Ghost.h"  

AGhostAIController::AGhostAIController()  
{  
   BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));  
   BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));  

   // Set blackboard keys  
   TargetLocationKey = "TargetLocation";  
   IsDeadKey = "IsDead";  
   IsFrightenedKey = "IsFrightened";  
}  

void AGhostAIController::OnPossess(APawn* InPawn)  
{  
   Super::OnPossess(InPawn);  

   AGhost* GhostCharacter = Cast<AGhost>(InPawn);  
   if (GhostCharacter && GhostCharacter->TreeAsset)  
   {  
       BlackboardComp->InitializeBlackboard(*GhostCharacter->TreeAsset->BlackboardAsset);  
       BehaviorComp->StartTree(*GhostCharacter->TreeAsset);  
   }  
}