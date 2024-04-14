// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "FlowerInstances.generated.h"

UCLASS()
class FINALYEARPROJECT_API AFlowerInstances : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlowerInstances();

	int Length = 0;
	int Width = 0;
	int Height = 0;

	FRotator RotationVariance;
	FVector Spacing;


protected:
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY()
	TObjectPtr<USceneComponent> DefaultRoot;

	UPROPERTY()
	TObjectPtr<UInstancedStaticMeshComponent> FlowerOne;

	UPROPERTY()
	TObjectPtr<UInstancedStaticMeshComponent> FlowerTwo;

};
