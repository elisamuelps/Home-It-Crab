// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CrabCharacter.generated.h"

UENUM(BlueprintType)
enum EMood
{
	ENeutral UMETA(DisplayName = "NeutralMood"),
	ESad  UMETA(DisplayName = "SadMood"),
	EHappy UMETA(DisplayName = "HappyMood"),
	ENumMoods
};

UENUM(BlueprintType)
enum EStealthState
{
	EVisible UMETA(DisplayName = "Visible"),
	EHidden UMETA(DisplayName = "Hidden"),
	ENumStates
};

UCLASS()
class HOMEITCRAB_API ACrabCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACrabCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set the mood of the Crab"))
	void SetCrabMood(EMood mood);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get the mood of the Crab"))
	EMood GetCrabMood();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set the stealth state of the Crab"))
	void SetCrabStealthState(EStealthState stealthState);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get the stealth state of the Crab"))
	EStealthState GetCrabStealthState();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Shell Breaks"))
	void ShellHasBroken();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Crab Has No Life"))
	void CrabHasDied();

	UFUNCTION(BlueprintCallable, meta = (ToolTip = "Crab has been hit"))
	void CrabHasBeenHit(int damage);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Life of crab", Category = "Crab"))
	int Life;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Armour of crab", Category = "Crab"))
	int Armour;

private:

	void MoveForward(float amount);

	void MoveRight(float amount);

	void CrabTakeDamage(int amount);

private:

	EMood eMood;

	EStealthState eStealthState;
};
