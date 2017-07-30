// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	

	TArray<AActor*> GetPatrolPoints() const;

protected:

	UPROPERTY(EditInstanceOnly, Category = "Patrol")
	TArray<AActor*> patrolPoints;

};
