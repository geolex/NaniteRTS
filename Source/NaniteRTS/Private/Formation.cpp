// Fill out your copyright notice in the Description page of Project Settings.


#include "Formation.h"

#include "VectorTypes.h"

TArray<FVector> UFormationHelper::SquareFormation(int nbPos, const FVector& startPos, const FVector& endPos, float spacing)
{
	float frontWidth = FVector::Distance(endPos, startPos);

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

TArray<FVector> UFormationHelper::HollowSquareFormation(int nbPos, const FVector& startPos, const FVector& endPos, float spacing, int wallThickness)
{
	float frontWidth = FVector::Distance(endPos, startPos);

	FVector side = (endPos - startPos).GetSafeNormal();
	FVector rear = FVector(side.Y, -side.X, 0);
	
	int nbFrontPos = ceil(frontWidth / spacing);

	int nbRanks = floor((nbPos - (nbFrontPos * 2 * wallThickness)) / (2 * wallThickness));
	
	TArray<FVector> positions;
	positions.Reserve(nbPos);

	int posCount = 0;
	for(int rank = 0; rank < nbRanks + 2 * wallThickness; rank++)
	{
		if(rank < wallThickness || rank >= nbRanks + wallThickness)
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

			for(int column = nbFrontPos - wallThickness; column < nbFrontPos; column++)
			{
				positions.Add((rear * rank + side * column) * spacing);
				posCount++;
			}
		}
	}
	
	return positions;
}
