// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AGrid::AGrid()
{

}

// Called when the game starts or when spawned
void AGrid::BeginPlay()
{
	Super::BeginPlay();
	
	FillGrid();
}


void AGrid::FillGrid()
{
	

	GridArray.Empty();

	//CalculateCellSpawnPoints is called in blueprint and the return transform is used to 
	//spawn actor of grid cell and add the spawned actors to the GridArray.

}

//Function used to spawn in the cells that make up the grid that the player places tracks on
FTransform AGrid::CalculateCellSpawnPoints()
{
	float WorldOffset;

	WorldOffset = (GridSize * GridGapsize) * 0.5 - GridGapsize * 0.5;

	float XVector = 0.0f;
	float YVector = 0.0f;

	//Loops through both dimensions to create the grid
	for (int XIndex = 0; XIndex < GridX - 1; XIndex++)
	{
		XVector = (GridGapsize * XIndex) - WorldOffset;
	}

	for (int YIndex = 0; YIndex < GridX - 1; YIndex++)
	{
		YVector = (GridGapsize * YIndex) - WorldOffset;
	}

	//Create a location vector to spawn the cells
	FVector CellLocation = UKismetMathLibrary::MakeVector(XVector, YVector, 0.0f);
	FRotator CellRotation = FRotator(0.0f, 0.0f, 0.0f);
	FVector CellScale = FVector(1.0f, 1.0f, 1.0f);

	//Create a transform fot the cells
	FTransform CellTransform = UKismetMathLibrary::MakeTransform(CellLocation, CellRotation, CellScale);



	return CellTransform;
}



