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
	
	UFUNCTION()
		void ActivateRemoteBomb(float duration);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "BlasterMan", EditAnywhere)
		float MaxBlastDistance = 300;

	UPROPERTY(BlueprintReadOnly, Category = "BlasterMan", EditAnywhere)
		float DefaultWalkSpeed = 600.0f;

	UPROPERTY(BlueprintReadOnly, Category = "BlasterMan", EditAnywhere)
		int MaxBomb = 1;

	UPROPERTY(BlueprintReadOnly, Category = "BlasterMan", EditAnywhere)
		float BlastRadius = 30.0f;

	UPROPERTY(BlueprintReadOnly, Category = "BlasterMan", EditAnywhere)
		float MaxWalkSpeedRatio = 3.0f;

	UPROPERTY(BlueprintReadOnly, Category = "BlasterMan", EditAnywhere)
		bool bRemoteBombActivated = false;
private:
	float CurrentWalkSpeedRatio = 1.0f;
	float CurrentRemoteLifeSpan = 0.0f;

};
