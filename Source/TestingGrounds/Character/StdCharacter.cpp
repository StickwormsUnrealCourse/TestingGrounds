#include "StdCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Weapon/Weapon.h"

// Sets default values
AStdCharacter::AStdCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	cam->SetupAttachment(GetCapsuleComponent());
	cam->RelativeLocation = FVector(-39.56f, 1.75f, 64.f);
	cam->bUsePawnControlRotation = true;

	mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh 1P"));
	mesh1P->SetupAttachment(cam);
	mesh1P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	mesh1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);

	weaponChildActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("Weapon Child"));
	weaponChildActor->SetChildActorClass(AWeapon::StaticClass());
	weaponChildActor->SetupAttachment(mesh1P);
}




// Called when the game starts or when spawned
void AStdCharacter::BeginPlay()
{
	Super::BeginPlay();

	//weapon = GetWorld()->SpawnActor<AWeapon>(weaponChild->GetChildActorClass()); //Spawn a second copy of the weapon?
	weapon = Cast<AWeapon>(weaponChildActor->GetChildActor());

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	weapon->AttachToComponent(mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	weapon->AnimInstance = mesh1P->GetAnimInstance();

}

/*
void AStdCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
*/

// Called to bind functionality to input
void AStdCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AStdCharacter::Fire()
{	
	weapon->OnFire();
}

bool AStdCharacter::IsDead() const
{
	return false;
}

