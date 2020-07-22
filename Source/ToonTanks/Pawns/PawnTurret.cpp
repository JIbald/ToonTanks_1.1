// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
	//GetWorldTimerManager(); does the same. personal preference

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APawnTurret::CheckFireCondition()
{
	//if Player == null || is dead then no fire
	if (!PlayerPawn)
	{
		return;
	}

	//if player is in range then fire
	if (ReturnDistanceToPlayer() <= FireRange)
	{
		UE_LOG(LogTemp, Warning, TEXT("CheckFireCondition() Fire()"));
	}
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if (!PlayerPawn)
	{
		return 0.0f;
	}
	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}
