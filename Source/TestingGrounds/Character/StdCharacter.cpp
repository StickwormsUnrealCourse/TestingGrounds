// Fill out your copyright notice in the Description page of Project Settings.

#include "StdCharacter.h"


// Sets default values
AStdCharacter::AStdCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStdCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStdCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AStdCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

