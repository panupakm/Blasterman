// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BlasterCharacter.generated.h"

UCLASS()
class BLASTERMAN_API ABlasterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABlasterCharacter();

	UFUNCTION()
		void IncreaseBlastDistance(float distance);

	UFUNCTION()
		void IncreaseMaxBomb(int number);

	UFUNCTION()
		void IncreaseRunSpeed(float speed);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "BlasterMan", EditAnywhere)
		float MaxBlastDistance;

	UPROPERTY(BlueprintReadOnly, Category = "BlasterMan", EditAnywhere)
		float RunSpeed;

	UPROPERTY(BlueprintReadOnly, Category = "BlasterMan", EditAnywhere)
		float MaxBomb;

	UPROPERTY(BlueprintReadOnly, Category = "BlasterMan", EditAnywhere)
		float BlastRadius;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
};