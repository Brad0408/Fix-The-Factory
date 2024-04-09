// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlaceableParent.generated.h"

UCLASS()
class FINALYEARPROJECT_API APlaceableParent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlaceableParent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};


UENUM(BlueprintType)
enum class E_PlacedAssetType : uint8
{
	None,
	SimpleConveyorTrack,
	BouncingTrack,
	FastTrack,
	SlowTrack,
};