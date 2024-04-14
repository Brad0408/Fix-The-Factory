// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowerInstances.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AFlowerInstances::AFlowerInstances()
{

}


void AFlowerInstances::OnConstruction(const FTransform& Transform)
{

	//Names of the Instance components
	FName FirstInstanceMesh(TEXT("FlowerMeshOne"));
	FName SecondInstanceMesh(TEXT("FlowerMeshTwo"));

	DefaultRoot = FindComponentByClass<USceneComponent>();


	for (USceneComponent* ChildComponent : DefaultRoot->GetAttachChildren())
	{
		if (ChildComponent->GetName() == FirstInstanceMesh.ToString())
		{
			FlowerOne = Cast<UInstancedStaticMeshComponent>(ChildComponent);
		}

		if (ChildComponent->GetName() == SecondInstanceMesh.ToString())
		{
			FlowerTwo = Cast<UInstancedStaticMeshComponent>(ChildComponent);
		}
	}


	//Loop through dimensions (Z not really needed)
	int HeightIndex;
	int LengthIndex;
	int WidthIndex;


	for (int Index = 0; Height - 1; Index++)
	{
		HeightIndex = Index;
	}

	for (int Index = 0; Length - 1; Index++)
	{
		LengthIndex = Index;
	}

	for (int Index = 0; Width - 1; Index++)
	{
		WidthIndex = Index;
	}

	//Create a vector of the looped index values
	FVector FlowerLocation (LengthIndex, WidthIndex, HeightIndex);

	//Get a random spacing value for each dimension
	float RandomSpacingX = UKismetMathLibrary::RandomFloatInRange(0, Spacing.X);
	float RandomSpacingY = UKismetMathLibrary::RandomFloatInRange(0, Spacing.Y);
	float RandomSpacingZ = UKismetMathLibrary::RandomFloatInRange(0, Spacing.Z);

	//Get a random rotaion for each orientation
	float RandomRotationX = UKismetMathLibrary::RandomFloatInRange(0, RotationVariance.Roll);
	float RandomRotationY = UKismetMathLibrary::RandomFloatInRange(0, RotationVariance.Pitch);
	float RandomRotationZ = UKismetMathLibrary::RandomFloatInRange(0, RotationVariance.Yaw);

	//Create a vector to store the flower spacing
	FVector FlowerSpacing(RandomSpacingX, RandomSpacingY, RandomSpacingZ);

	//Create a rotator for the random rotations (Z not used)
	FRotator FlowerRotation(RandomRotationX, RandomRotationY, RandomRotationZ);

	//Double scale, flowers are small
	FVector FlowerScale(2.0f, 2.0f, 2.0f);

	//Create the actual flower location, mix of looped values and spacing together
	FVector ActualFlowerLocation = FlowerLocation * FlowerSpacing;

	//Create the transform from everything
	FTransform FlowerTransform(FlowerRotation, ActualFlowerLocation, FlowerScale);

	//Create the flower Instances
	FlowerOne->AddInstance(FlowerTransform, false);
	FlowerTwo->AddInstance(FlowerTransform, false);
}




