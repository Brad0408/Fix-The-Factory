// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/Material.h"
#include "BoxSpawner.generated.h"


UCLASS()
class FINALYEARPROJECT_API ABoxSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoxSpawner();

	UClass* BoxType;

	float Time = 4.5f;

	int BoxesToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UWorld* World = GetWorld();

	FTimerHandle TimerHandle;

	int BoxSpawnCount = 0;

	UPROPERTY()
	TObjectPtr<USceneComponent> DefaultRoot;

	UPROPERTY()
	TObjectPtr<UMaterial> MeshMaterial;

	UPROPERTY()
	TObjectPtr<UStaticMesh> SpawnerMesh;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	TObjectPtr<USoundBase> SpawnSound;

	UPROPERTY()
	TObjectPtr<UBillboardComponent> Billboard;

	UFUNCTION()
	void ChangeMaterial();

	UFUNCTION()
	void TimerEvent();
};
