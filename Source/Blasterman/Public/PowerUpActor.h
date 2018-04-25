// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerUpActor.generated.h"

UCLASS()
class BLASTERMAN_API APowerUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerUpActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//UFUNCTION(BlueprintCallable)
	UFUNCTION()
		void OnOverlappedWithActor(AActor* overlappedActor, AActor* otherActor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "PowerUp")
		void OnFinishedPowerUp();

	UPROPERTY(EditAnywhere, Category = "PowerUp")
		float BlastRangeIncrease;

	UPROPERTY(EditAnywhere, Category = "PowerUp")
		float BombIncrease;
	
	UPROPERTY(EditAnywhere, Category = "PowerUp")
		bool RemoteDetonate;

	UPROPERTY(EditAnywhere, Category = "PowerUp")
		float RemoteDetonateDuration;

	UPROPERTY(EditAnywhere, Category = "PowerUp")
		float RunSpeedIncrease;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
