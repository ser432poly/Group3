// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "WeaponBase.h"


// Sets default values
AWeaponBase::AWeaponBase(const FObjectInitializer& ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collisionComponent = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("collisionComponent"));
	RootComponent = collisionComponent;

	meshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("meshComponent"));
	meshComponent->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AWeaponBase::Fire()
{
	if (currentAmmo > 0) {
		//Fire Weapon

		//Handle Ammo
		UseAmmo();

		
	}
	else {
		//Reload
	}
}

void AWeaponBase::UseAmmo()
{
	currentAmmo--;
}


void AWeaponBase::HandleFiring(){

	//Aim direction

	//Trace weapon impact

	//Process hit
}

