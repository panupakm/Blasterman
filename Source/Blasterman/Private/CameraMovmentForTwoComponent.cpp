// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraMovmentForTwoComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UCameraMovmentForTwoComponent::UCameraMovmentForTwoComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCameraMovmentForTwoComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CameraComponent = GetOwner()->FindComponentByClass<UCameraComponent>();
}


// Called every frame
void UCameraMovmentForTwoComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	FVector boundCamLocation(0, 0, 0);
	FVector middleLocation(0, 0, 0);
	const UWorld* world = GetWorld();
	int playerNum = 0;

	FConstPlayerControllerIterator iterator = world->GetPlayerControllerIterator();
	while (iterator)
	{
		APlayerController* playerController = iterator->Get();
		if (playerController && playerController->GetPawn())
		{
			middleLocation += playerController->GetPawn()->GetActorLocation();
			boundCamLocation = playerController->GetPawn()->GetActorLocation();
			++playerNum;
		}
		++iterator;
	}

	if (playerNum > 0) 
	{
		middleLocation /= playerNum;

		FVector midToBoundDir = (boundCamLocation - middleLocation);
		boundCamLocation.X = midToBoundDir.X * CameraComponent->AspectRatio;
		midToBoundDir.Normalize();
		boundCamLocation += midToBoundDir * OffsetCamBound;

		float toMiddleDistance = FVector::Distance( boundCamLocation, middleLocation );
		float camZ = toMiddleDistance/FMath::Tan(FMath::DegreesToRadians(CamAngle));

		middleLocation.Z = FMath::Max(MinZ,camZ);
		GetOwner()->SetActorLocation(middleLocation);
	}
}

