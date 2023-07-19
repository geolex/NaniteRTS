// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Formation.generated.h"

UCLASS()
class NANITERTS_API AFormation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFormation();

	UFUNCTION(BlueprintCallable)
	TArray<FVector> SquareFormation(int nbPos, const FVector& startPos, const FVector& endPos, float spacing);

	UFUNCTION(BlueprintCallable)
	TArray<FVector> HollowSquareFormation(int nbPos, const FVector& startPos, const FVector& endPos, float spacing, int wallThickness);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
