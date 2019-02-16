// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "UnrealMath.h"
#include "TimerManager.h"
#include "AICharacter.h"
#include "EnemySpawner.generated.h"


/************************************************************************/
/* Just Leaving This Piece Of Code in Case if we Need it				*/
/************************************************************************/
UENUM(BlueprintType)
enum class ESpawnerType : uint8
{
	Rubbish				UMETA(DisplayName = "Rubbish"),
	Enemy				UMETA(DisplayName = "Enemy")
};

UCLASS()
class HOMEITCRAB_API AActorSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorSpawner();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawner Shape", meta = (DisplayName = "Spawn Area"))
	UBoxComponent* SpawnArea;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Options", meta = (DisplayName = "Actor To Spawn"))
	TSubclassOf<AActor> SpawnEntity;

	//Starts the spawn countdown at the beginning of the game
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Options", meta = (DisplayName = "Start Timer at Game Start"))
	bool bStartTimer = true;

	UPROPERTY(BlueprintInternalUseOnly)
	FTimerHandle SpawnTimer;
	
	//Number of Entities To Spawn at the same time
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Options", meta = (ClampMax = 5, ClampMin = 0, DisplayName = "Number Of Entities To Spawn"))
	uint8 NumberToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Options", meta = (DisplayName = "Initial Spawn Time", ToolTip = "Buffer of seconds before the first spawn happens on the level"))
	float InitialSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Options", meta = (DisplayName = "Spawn Flow", ToolTip = "Standard Spawn Time in Seconds"))
	float SpawnFlow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Options", meta = (DisplayName = "Random Range", ToolTip = "Range of Seconds to add randomness to spawn enemies"))
	float RandomSecsRange;

	//Start Range of spawned objects location, the more you add, the less close to the center.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Options", meta = (DisplayName = "Location Start Range"))
	FVector LocationRandomRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Options", meta = (DisplayName = "Spawner Type", ToolTip = "What object should this spawner create?"))
	ESpawnerType SpawnerType;

	//Spawns Enemies around the Area
	UFUNCTION(BlueprintCallable, Category = "Spawner", meta = (ToolTip = "Starts to Spawn Enemies"))
	void Spawn();

};
