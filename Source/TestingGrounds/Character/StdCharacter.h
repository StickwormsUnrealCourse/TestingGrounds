#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StdCharacter.generated.h"

UCLASS()
class TESTINGGROUNDS_API AStdCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AStdCharacter();

protected:
	virtual void BeginPlay() override;

public:	
//	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();
	bool IsDead() const;


private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* cam;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	class USkeletalMeshComponent* mesh1P;

//	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
//	class USkeletalMeshComponent* mesh3rdP; //Mesh already included in base class

	class AWeapon* weapon;

//	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
//	TSubclassOf<class AWeapon> weapon_BP;


	UPROPERTY(EditAnywhere, Category = "Weapon")
	class UChildActorComponent* weaponChildActor;

	float health;
	float maxHealth;


};
