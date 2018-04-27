// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraMovmentForTwoComponent.generated.h"

class UCameraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLASTERMAN_API UCameraMovmentForTwoComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCameraMovmentForTwoComponent();

protected:

	UPROPERTY(BlueprintReadWrite, Category = "AutoAdjust")
		float MinZ = 1250.0f;

	UPROPERTY(BlueprintReadWrite, Category = "AutoAdjust")
		float CamAngle = 45.0f;

	UPROPERTY(BlueprintReadWrite, Category = "AutoAdjust")
		float OffsetCamBound = 500.0f;

	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
private:
	UCameraComponent* CameraComponent;
};
