// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h" 
#include "FloorCleanup.generated.h"


UCLASS()
class FINALYEARPROJECT_API AFloorCleanup : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFloorCleanup();

	int AmountToFail = 3;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int DroppedCount = 0;

	UPROPERTY()
	TObjectPtr<UBoxComponent> BoxComponent;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	TObjectPtr<USoundBase> BoxPoofSound;

	UFUNCTION()
	void OnOverlapEvent(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void LossCheck();
};