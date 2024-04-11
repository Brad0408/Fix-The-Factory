// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlaceableParent.h"
#include "SlowTrack.generated.h"


class UBoxComponent;
class UArrowComponent;
class USceneComponent;
class UBillboardComponent;


UCLASS()
class FINALYEARPROJECT_API ASlowTrack : public APlaceableParent
{
	GENERATED_BODY()



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	float Speed = 50.0f;

	UPROPERTY()
	TObjectPtr<USceneComponent> DefaultRoot;

	UPROPERTY()
	TObjectPtr<UBoxComponent> ConveyorOverlapBox;

	UPROPERTY()
	TObjectPtr<UBoxComponent> SnapBox;

	UPROPERTY()
	TObjectPtr<UArrowComponent> Arrow;

	UPROPERTY()
	TObjectPtr<UBillboardComponent> Billboard;

	UFUNCTION()
	void OnOverlapEvent(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
