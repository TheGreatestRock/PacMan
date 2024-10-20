#include "Ghost.h"  
#include "GhostAIController.h"  
#include "BehaviorTree/BehaviorTreeComponent.h"  
#include "BehaviorTree/BlackboardComponent.h"  
#include "Kismet/GameplayStatics.h"  
#include "TimerManager.h" // Include TimerManager header

// Constructor  
AGhost::AGhost()  
{  
   // Initialize state flags  
   bIsDead = false;  
   bIsFrightened = false;  
}  

// Called when the game starts or when spawned  
void AGhost::BeginPlay()  
{  
   Super::BeginPlay();  

   UpdateBlackboardStates();  

   // Setup AI controller and run the behavior tree  
   AGhostAIController* AIController = Cast<AGhostAIController>(GetController());  
   if (AIController && TreeAsset)  
   {  
       // Initialize the blackboard with the TreeAsset  
       if (UBlackboardComponent* BlackboardComp = AIController->GetBlackboardComponent())  
       {  
           // Set initial values in the blackboard  
           BlackboardComp->SetValueAsBool(TEXT("IsDead"), bIsDead);  
           BlackboardComp->SetValueAsBool(TEXT("IsFrightened"), bIsFrightened);  
           BlackboardComp->SetValueAsVector(TEXT("TargetLocation"), GetActorLocation()); // Set initial target location  

           // Run the behavior tree  
           AIController->RunBehaviorTree(TreeAsset);  
       }  
   }  
}  

// Overlap event to handle interactions with Pac-Man or other entities  
void AGhost::OnOverlap()  
{  
   if (bIsFrightened)  
   {  
       SetDeadMode();  // Ghost dies if frightened and overlaps with Pac-Man  
   }  
   else  
   {  
       // Logic for interaction with Pac-Man when not frightened  
   }  
}  

void AGhost::SetAliveMode()  
{  
   bIsDead = false;  
   bIsFrightened = false;  
   UE_LOG(LogTemp, Warning, TEXT("The ghost is now in alive mode."));

   UpdateBlackboardStates();  
}  

// Set the ghost to "Dead" mode (returning to base)  
void AGhost::SetDeadMode()  
{  
   bIsDead = true;  
   bIsFrightened = false;
   UpdateBlackboardStates();  
} 

void AGhost::SetUnFrightened()
{
    bIsFrightened = false;
    UE_LOG(LogTemp, Warning, TEXT("The ghost is now in alive mode."));

    UpdateBlackboardStates();
}

// Set the ghost to "Frightened" mode (running away)  
void AGhost::SetFrightenMode()  
{  
   bIsFrightened = true;  

   // Sync with Blackboard  
   UpdateBlackboardStates();  


   GetWorldTimerManager().SetTimer(FrightenedTimerHandle, this, &AGhost::SetUnFrightened, 10.0f);
}  

void AGhost::UpdateBlackboardStates()  
{  
   if (AGhostAIController* AIController = GetGhostAIController())  
   {  
       if (UBlackboardComponent* BlackboardComp = AIController->GetBlackboardComponent())  
       {  
           BlackboardComp->SetValueAsBool(TEXT("IsDead"), bIsDead);  
           BlackboardComp->SetValueAsBool(TEXT("IsFrightened"), bIsFrightened);  
       }  
   }  
}  

// Function to get the AI controller for this ghost  
AGhostAIController* AGhost::GetGhostAIController() const  
{  
   return Cast<AGhostAIController>(GetController());  
}  