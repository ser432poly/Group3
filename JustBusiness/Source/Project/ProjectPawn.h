// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Pawn.h"
#include "WeaponBase.h"
#include "ProjectPawn.generated.h"


UCLASS(config=Game)
class AProjectPawn : public APawn
{
	GENERATED_BODY()

	/** StaticMesh component that will be the visuals for our flying pawn */
	UPROPERTY(Category = Mesh, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PlaneMesh;

	/** Spring arm that will offset the camera */
	UPROPERTY(Category = Camera, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;

	/** Camera component that will be our viewpoint */
	UPROPERTY(Category = Camera, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

public:
	AProjectPawn();

	// Begin AActor overrides
	virtual void Tick(float DeltaSeconds) override;
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
	// End AActor overrides

	UPROPERTY(Category = Weapon, EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AWeaponBase> WeaponSpawn;

	UPROPERTY(Category = Weapon, EditAnywhere, BlueprintReadWrite)
	AWeaponBase* PrimaryWeapon;

	UPROPERTY(Category = Weapon, EditAnywhere, BlueprintReadWrite)
	AWeaponBase* SecondaryWeapon;

	UPROPERTY(EditDefaultsOnly, Category = "Condition", BlueprintReadWrite)
	float Health;

	UFUNCTION(BlueprintCallable, Category = Event)
	virtual void BeginPlay() override;

	/** Returns the Current Health */
	UFUNCTION(BlueprintCallable, Category = "Condition")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Condition")
	int32 GetCurrency();

	UFUNCTION(BlueprintCallable, Category = "Condition")
		int32 ReduceCurrency(int32 amount);

	UFUNCTION(BlueprintCallable, Category = "Condition")
		int32 IncreaseCurrency(int32 amount);

	/** Returns the Max Health */
	UFUNCTION(BlueprintCallable, Category = "Condition")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Condition")
	bool IsAlive() const;

	/* Take damage & handle death */
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

	virtual bool Die(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser);

	virtual void OnDeath(float KillingDamage, FDamageEvent const& DamageEvent, APawn* PawnInstigator, AActor* DamageCauser);

	virtual void PlayHit(float DamageTaken, struct FDamageEvent const& DamageEvent, APawn* PawnInstigator, AActor* DamageCauser, bool bKilled);

protected:


		int32 Currency;

	// Begin APawn overrides
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override; // Allows binding actions/axes to functions
	// End APawn overrides

	/** Bound to the thrust axis */
	void ThrustInput(float Val);
	
	/** Bound to the vertical axis */
	void MoveUpInput(float Val);

	/** Bound to the horizontal axis */
	void MoveRightInput(float Val);

private:

	/** How quickly forward speed changes */
	UPROPERTY(Category=Plane, EditAnywhere)
	float Acceleration;

	/** How quickly pawn can steer */
	UPROPERTY(Category=Plane, EditAnywhere)
	float TurnSpeed;

	/** Max forward speed */
	UPROPERTY(Category = Pitch, EditAnywhere)
	float MaxSpeed;

	/** Min forward speed */
	UPROPERTY(Category=Yaw, EditAnywhere)
	float MinSpeed;

	/** Current forward speed */
	float CurrentForwardSpeed;

	/** Current yaw speed */
	float CurrentYawSpeed;

	/** Current pitch speed */
	float CurrentPitchSpeed;

	/** Current roll speed */
	float CurrentRollSpeed;

public:
	/** Returns PlaneMesh subobject **/
	FORCEINLINE class UStaticMeshComponent* GetPlaneMesh() const { return PlaneMesh; }
	/** Returns SpringArm subobject **/
	FORCEINLINE class USpringArmComponent* GetSpringArm() const { return SpringArm; }
	/** Returns Camera subobject **/
	FORCEINLINE class UCameraComponent* GetCamera() const { return Camera; }
};
