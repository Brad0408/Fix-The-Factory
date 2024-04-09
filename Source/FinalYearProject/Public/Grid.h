// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

UCLASS()
class FINALYEARPROJECT_API AGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrid();


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int GridX;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int GridY;

	UPROPERTY(BlueprintReadWrite)
	TArray<AActor*> GridArray;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	int GridSize;

	UPROPERTY(BlueprintReadWrite)
	int GridGapsize;


	UFUNCTION(BlueprintCallable)
	void FillGrid();

	UFUNCTION(BlueprintCallable)
	FTransform CalculateCellSpawnPoints();

};
