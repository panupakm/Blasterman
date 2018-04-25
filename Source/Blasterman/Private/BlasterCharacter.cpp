// Fill out your copyright notice in the Description page of Project Settings.

#include "BlasterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ABlasterCharacter::ABlasterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABlasterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	UCharacterMovementComponent * charMovementComp = FindComponentByClass<UCharacterMovementComponent>();
	charMovementComp->MaxWalkSpeed = DefaultWalkSpeed * CurrentWalkSpeedRatio;
}

// Called every frame
void ABlasterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bRemoteBombActivated) 
	{
		CurrentRemoteLifeSpan -= DeltaTime;
		bRemoteBombActivated = CurrentRemoteLifeSpan > 0.0f;
	}
}

// Called to bind functionality to input
void ABlasterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABlasterCharacter::IncreaseBlastDistance(float distance) 
{
	MaxBlastDistance += distance;
}

void ABlasterCharacter::IncreaseMaxBomb(int number)
{
	MaxBomb += number;
}

void ABlasterCharacter::IncreaseRunSpeed(float additiaonalSpeedRatio)
{
	UCharacterMovementComponent * charMovementComp = FindComponentByClass<UCharacterMovementComponent>();
	CurrentWalkSpeedRatio += additiaonalSpeedRatio;

	CurrentWalkSpeedRatio = FMath::Min<float>(CurrentWalkSpeedRatio, MaxWalkSpeedRatio);
	charMovementComp->MaxWalkSpeed = DefaultWalkSpeed * CurrentWalkSpeedRatio;
}

void ABlasterCharacter::ActivateRemoteBomb(float duration) 
{
	if (duration > 0) 
	{
		bRemoteBombActivated = true;
		CurrentRemoteLifeSpan = duration;
	}
}
