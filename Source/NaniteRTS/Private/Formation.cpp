// Fill out your copyright notice in the Description page of Project Settings.


#include "Formation.h"

#include "VectorTypes.h"

// Sets default values
AFormation::AFormation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFormation::BeginPlay()
{
	Super::BeginPlay();
	
}

TArray<FVector> AFormation::SquareFormation(int nbPos, FVector startPos, FVector endPos, float spacing)
{
	float frontWidth = UE::Geometry::Distance(endPos, startPos);

	FVector side = (endPos - startPos).GetSafeNormal();
	FVector rear = FVector(side.Y, -side.X, 0);
	
	int nbFrontPos = ceil(frontWidth / spacing);

	int nbRanks = ceil(nbPos / nbFrontPos);

	TArray<FVector> positions;
	positions.Reserve(nbPos);
	
	for(int i = 0; i < nbPos; i++)
	{
		int currentRank = floor(i / nbFrontPos);
		int currentColumn = i % nbFrontPos;
		positions.Add((currentRank * rear + currentColumn * side)*spacing);
	}
	
	return positions;
}


// Called every frame
void AFormation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

