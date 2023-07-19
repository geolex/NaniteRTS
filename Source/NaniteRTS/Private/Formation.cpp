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

TArray<FVector> AFormation::HollowSquareFormation(int nbPos, FVector startPos, FVector endPos, float spacing, int wallThickness)
{
	float frontWidth = UE::Geometry::Distance(endPos, startPos);

	FVector side = (endPos - startPos).GetSafeNormal();
	FVector rear = FVector(side.Y, -side.X, 0);
	
	int nbFrontPos = ceil(frontWidth / spacing);

	int nbRanks = ceil((nbPos - (frontWidth * 2 * wallThickness)) / (2 * wallThickness));
	
	TArray<FVector> positions;
	positions.Reserve(nbPos);

	int posCount = 0;
	for(int rank = 0; rank < nbRanks; rank++)
	{
		if(rank < wallThickness || rank >= nbRanks - wallThickness)
		{
			for(int column = 0; column < nbFrontPos; column++)
			{
				if(posCount == nbPos)
					return positions;
				
				positions.Add((rear * rank + side * column) * spacing);
				posCount++;
			}
		}else
		{
			for(int column = 0; column < wallThickness; column++)
			{
				positions.Add((rear * rank + side * column) * spacing);
				posCount++;
			}

			for(int column = nbFrontPos - 1 - wallThickness; column < nbFrontPos; column++)
			{
				positions.Add((rear * rank + side * column) * spacing);
				posCount++;
			}
		}
	}
	
	return positions;
}


// Called every frame
void AFormation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

