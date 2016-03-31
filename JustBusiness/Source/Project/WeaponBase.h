// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class PROJECT_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Fire();

	UPROPERTY(Category = Ammo, EditDefaultsOnly)
	int32 maxAmmo;

	UPROPERTY(Category = Configuration, EditDefaultsOnly)
	float weaponSpread;

	UPROPERTY(Category = Configuration, EditDefaultsOnly)
	float weaponRange;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
	UBoxComponent* collisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
	UStaticMeshComponent* meshComponent;
	
};
