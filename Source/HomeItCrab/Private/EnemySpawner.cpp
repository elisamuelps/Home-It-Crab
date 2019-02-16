// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySpawner.h"

// Sets default values
AActorSpawner::AActorSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawn Area"));
	
}

// Called when the game starts or when spawned
void AActorSpawner::BeginPlay()
{
	Super::BeginPlay();

	if (bStartTimer) GetWorldTimerManager().SetTimer(SpawnTimer, this, &AActorSpawner::Spawn, InitialSpawn, false);
}

void AActorSpawner::Spawn()
{
	//Random Time
	float Random = FMath::FRandRange(0, RandomSecsRange);
	UWorld* theWorld = GetWorld();

	for (int i = 0; i < NumberToSpawn; ++i)
	{
		FHitResult ZTrace;

		//Random Position
		float RandomX = FMath::FRandRange(LocationRandomRange.X - SpawnArea->GetScaledBoxExtent().X,
										  LocationRandomRange.X + SpawnArea->GetScaledBoxExtent().X);

		float RandomY = FMath::FRandRange(LocationRandomRange.Y - SpawnArea->GetScaledBoxExtent().Y,
										  LocationRandomRange.Y + SpawnArea->GetScaledBoxExtent().Y);

		//RayTrace Z
		theWorld->LineTraceSingleByChannel(ZTrace, FVector(RandomX, RandomY, 3000),
										   FVector(RandomX, RandomY, -400),
										   ECC_Visibility, FCollisionQueryParams(FName("ALESPA"), true),
										   FCollisionResponseParams::DefaultResponseParam);

		FTransform SpawnLocation = FTransform(FVector(RandomX + GetActorLocation().X,
													  RandomY + GetActorLocation().Y,
													  ZTrace.ImpactPoint.Z + 500));

		GetWorld()->SpawnActor<AActor>(SpawnEntity, SpawnLocation, FActorSpawnParameters());
	}

	GetWorldTimerManager().SetTimer(SpawnTimer, this, &AActorSpawner::Spawn, SpawnFlow + Random, false);

}

// Called every frame
void AActorSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

