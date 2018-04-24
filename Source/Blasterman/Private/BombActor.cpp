// Fill out your copyright notice in the Description page of Project Settings.

#include "BombActor.h"
#include "BomberCharacter.h"
#include "BlockActor.h"
#include "WorldCollision.h"
#include "CollisionDebugDrawingPublic.h"

// Sets default values
ABombActor::ABombActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MaxBlastDistance = 1000.0f;
	BlastRadius = 100.0f;
}

// Called when the game starts or when spawned
void ABombActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABombActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ABombActor::QueryBlastInfo( FRotator dirRotator, float & blastDistance, TArray<ACharacter*> & hitPlayers, TArray<ABombActor*> & hitBombs, ABlockActor* &hitBlock)
{	
	TArray<FHitResult> outHits;

	FVector start = GetActorLocation();
	FVector end = GetActorLocation() + dirRotator.Vector()*MaxBlastDistance;

	FCollisionQueryParams queryParams = FCollisionQueryParams( "Blast", true, this);

	FCollisionObjectQueryParams objectQueryParams = FCollisionObjectQueryParams(SweepObjectTypeQueries);
	FCollisionShape collisionShape = FCollisionShape::MakeSphere(BlastRadius);

	bool hasHits = false;
	GetWorld()->SweepMultiByObjectType(outHits, start, end, FQuat(0, 0, 0, 1), 
		objectQueryParams, collisionShape, queryParams);
	DrawSphereSweeps(GetWorld(), start, end, BlastRadius, outHits, 0.5f);
	
	//UE_LOG(LogTemp, Warning, TEXT("000000000000000000-- Actor(%s) ---000000000000000000000"), *GetName());
	hitBlock = NULL;
	blastDistance = MaxBlastDistance;
	for (int idx = 0; idx < outHits.Num(); ++idx) 
	{
		FHitResult & hitResult = outHits[idx];
		//UE_LOG(LogTemp, Warning, TEXT("--------------- Hit %s"), *hitResult.GetActor()->GetName());
		if (hitResult.GetActor()->IsA(ABombActor::StaticClass()))
		{
			//UE_LOG(LogTemp, Warning, TEXT("---------------Bomb Hit %s"), *hitResult.GetActor()->GetName());
			hasHits = true;
			hitBombs.Add( Cast<ABombActor>(hitResult.GetActor()));
		}
		else if (hitResult.GetActor()->IsA(ACharacter::StaticClass())) 
		{
			hasHits = true;
			hitPlayers.Add(Cast<ACharacter>(hitResult.GetActor()));
		}
		else if (hitResult.GetActor()->IsA(ABlockActor::StaticClass()))
		{
			if (blastDistance >= hitResult.Distance)
			{
				blastDistance = hitResult.Distance;
				hasHits = true;
				hitBlock = Cast<ABlockActor>(hitResult.GetActor());
			}
		}
	}
	//UE_LOG(LogTemp, Warning, TEXT("-------- HitBombs(%d) HitPlayers(%d) "), hitBombs.Num(), hitPlayers.Num());

	return hasHits;
}
