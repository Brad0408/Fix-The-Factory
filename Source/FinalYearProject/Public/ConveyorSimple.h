// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlaceableParent.h"
#include "ConveyorSimple.generated.h"


class UBoxComponent;
class UArrowComponent;

UCLASS()
class FINALYEARPROJECT_API AConveyorSimple : public APlaceableParent
{
	GENERATED_BODY()
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	float Speed = 85.0f;

	UPROPERTY()
	TObjectPtr<UBoxComponent> ConveyorOverlapBox;

	UPROPERTY()
	TObjectPtr<UArrowComponent> Arrow;
};
