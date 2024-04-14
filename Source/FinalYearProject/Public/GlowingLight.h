// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PointLightComponent.h"
#include "GlowingLight.generated.h"



UCLASS()
class FINALYEARPROJECT_API AGlowingLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGlowingLight();

	//Default light colour is red
	bool isRed = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY()
	TObjectPtr<UPointLightComponent> GlowLight;

};
