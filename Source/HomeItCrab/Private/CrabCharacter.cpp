// Fill out your copyright notice in the Description page of Project Settings.

#include "CrabCharacter.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"

// Sets default values
ACrabCharacter::ACrabCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACrabCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrabCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACrabCharacter::SetCrabMood(EMood mood)
{
	eMood = mood;
}

EMood ACrabCharacter::GetCrabMood()
{
	return eMood;
}

void ACrabCharacter::SetCrabStealthState(EStealthState stealthState)
{
	eStealthState = stealthState;
}

EStealthState ACrabCharacter::GetCrabStealthState()
{
	return eStealthState;
}

void ACrabCharacter::CrabHasBeenHit(int damage)
{
	CrabTakeDamage(damage);
}

// Called to bind functionality to input
void ACrabCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACrabCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACrabCharacter::MoveRight);
}

void ACrabCharacter::MoveForward(float amount)
{
	AddMovementInput(GetActorForwardVector(), amount);
}

void ACrabCharacter::MoveRight(float amount)
{
	AddMovementInput(GetActorRightVector(), amount);
}

void ACrabCharacter::CrabTakeDamage(int amount)
{
	if (Armour > 0)
	{
		Armour -= amount;
		if (Armour <= 0)
		{
			Life += Armour;
			ShellHasBroken();
			Armour = 0;
		}
	}
	else
	{
		Life -= amount;
	}
	if (Life <= 0)
	{
		CrabHasDied();
	}
}
