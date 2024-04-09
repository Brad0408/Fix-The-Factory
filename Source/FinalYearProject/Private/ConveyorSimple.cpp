// Fill out your copyright notice in the Description page of Project Settings.


#include "ConveyorSimple.h"
#include "Components/BoxComponent.h" 
#include "Components/ArrowComponent.h" 
#include "Components/SceneComponent.h"
#include "Kismet/KismetMathLibrary.h"


void AConveyorSimple::BeginPlay()
{
	Super::BeginPlay();

	//Find the components
	ConveyorOverlapBox = FindComponentByClass<UBoxComponent>();

	Arrow = FindComponentByClass<UArrowComponent>();

}

void AConveyorSimple::Tick(float DeltaTime)
{
	//Create array of overlapped actors
	TArray<AActor*> OverlappingActors;

	//Actually store the actors once the overlap occurs
	ConveyorOverlapBox->GetOverlappingActors(OverlappingActors);

	//Using tick to constantly move - not the most effiecnet but works
	FVector VectorSpeed (Speed * DeltaTime, Speed * DeltaTime, Speed * DeltaTime);

	//Calculate the arrows direction in the world and its forwards vector
	FTransform ArrowTransform = Arrow->GetComponentToWorld();
	FRotator ArrowRotation = ArrowTransform.GetRotation().Rotator();
	FVector ArrowVector = UKismetMathLibrary::GetForwardVector(ArrowRotation);

	//Multiply the speed tick and arrow vector for the offset vector
	FVector OffSetVector = VectorSpeed * ArrowVector;

	//Loop through overlapping actors
	for (AActor* Actor : OverlappingActors)
	{
		USceneComponent* RootComp = Actor->GetRootComponent();

		//Actually apply the offset vector
		RootComp->AddWorldOffset(OffSetVector, false, false);
	}
}
