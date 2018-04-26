// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerUpActor.h"
#include "BlasterCharacter.h"

// Sets default values
APowerUpActor::APowerUpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//UE_LOG(LogTemp, Warning, TEXT("APowerUpActor:APowerUpActor()"));

}

// Called when the game starts or when spawned
void APowerUpActor::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("APowerUpActor::BeginPlay()"));

	FScriptDelegate scriptDelegate;
	scriptDelegate.BindUFunction(this, FName("OnOverlappedWithActor"));
	OnActorBeginOverlap.Add(scriptDelegate);
}


void APowerUpActor::OnOverlappedWithActor(AActor* overlappedActor, AActor* otherActor) {

	ABlasterCharacter* targetPlayer = Cast<ABlasterCharacter>(otherActor);
	if (targetPlayer) 
	{
		targetPlayer->IncreaseBlastDistance( BlastRangeIncrease );
		targetPlayer->IncreaseMaxBomb(BombIncrease);
		targetPlayer->IncreaseRunSpeed(RunSpeedIncrease);
		targetPlayer->ActivateRemoteBomb(RemoteDetonateDuration);
		OnFinishedPowerUp();
	}
}

void APowerUpActor::OnFinishedPowerUp_Implementation()
{

}

void APowerUpActor::OnRemotePowerUpExpired_Implementation()
{

}

// Called every frame
void APowerUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

