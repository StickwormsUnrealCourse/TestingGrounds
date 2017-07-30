#include "SelectNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"


EBTNodeResult::Type USelectNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemeory)
{
	auto pawn = OwnerComp.GetAIOwner()->GetPawn();
	auto patrolRoute = pawn->FindComponentByClass<UPatrolRoute>();

	if (!ensure(patrolRoute)) { return EBTNodeResult::Failed; }

	auto patrolPoints = patrolRoute->GetPatrolPoints();
	if (patrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Patrol Points Set for: %s"), *(pawn->GetName()));
		return EBTNodeResult::Failed;
	}


	auto blackboard = OwnerComp.GetBlackboardComponent();
	auto index = blackboard->GetValueAsInt(indexKey.SelectedKeyName);
	blackboard->SetValueAsObject(wayPointKey.SelectedKeyName, patrolPoints[index]);

	auto nextIndex = (index + 1) % patrolPoints.Num();
	blackboard->SetValueAsInt(indexKey.SelectedKeyName, nextIndex);

	//UE_LOG(LogTemp, Warning, TEXT("Index: %i"), index);

	return EBTNodeResult::Succeeded;
}