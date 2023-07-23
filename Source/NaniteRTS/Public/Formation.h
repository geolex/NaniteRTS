// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Formation.generated.h"

UCLASS()
class NANITERTS_API UFormationHelper : public UObject
{
	GENERATED_BODY()
	
public:	
	UFUNCTION(BlueprintCallable)
	static TArray<FVector> SquareFormation(int nbPos, const FVector& startPos, const FVector& endPos, float spacing);

	UFUNCTION(BlueprintCallable)
	static TArray<FVector> HollowSquareFormation(int nbPos, const FVector& startPos, const FVector& endPos, float spacing, int wallThickness);
};
