// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blasterman.h"
#include "GameFramework/Actor.h"
#include "BombActor.generated.h"


class ABlockActor;

UCLASS()
class BLASTERMAN_API ABombActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABombActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "BombActor")
	float MaxBlastDistance;

	UPROPERTY(EditAnywhere, Category = "BombActor")
	float BlastRadius;

	UFUNCTION(BlueprintCallable, Category = "BombActor")
	UPARAM(DisplayName="HasHit") bool QueryBlastInfo(FRotator dirRotator, float & distance, TArray<ACharacter*> & hitPlayers, TArray<ABombActor*> & hitBombs, ABlockActor* & hitBlock);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
