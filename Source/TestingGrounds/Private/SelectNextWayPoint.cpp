#include "SelectNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h" //TODO Remove coupleing



EBTNodeResult::Type USelectNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemeory)
{
	//TODO Protect against empty patrol routes

	auto aiController = OwnerComp.GetAIOwner();
	auto pawn = aiController->GetPawn();
	auto patrollingGuard = Cast<APatrollingGuard>(pawn);
	auto patrolPoints = patrollingGuard->GetPatrolPoints();

	auto blackboard = OwnerComp.GetBlackboardComponent();
	auto index = blackboard->GetValueAsInt(indexKey.SelectedKeyName);
	blackboard->SetValueAsObject(wayPointKey.SelectedKeyName, patrolPoints[index]);

	auto nextIndex = (index + 1) % patrolPoints.Num();
	blackboard->SetValueAsInt(indexKey.SelectedKeyName, nextIndex);

	//UE_LOG(LogTemp, Warning, TEXT("Index: %i"), index);

	return EBTNodeResult::Succeeded;
}