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
	UPatrolRoute();

	TArray<AActor*> GetPatrolPoints();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly, Category = "Patrol")
	TArray<AActor*> patrolPoints;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
