// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxSpawner.h"
#include "HeavyBoxes.h"
#include "Boxes.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BillboardComponent.h"

// Sets default values
ABoxSpawner::ABoxSpawner()
{

}

// Called when the game starts or when spawned
void ABoxSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	//Names of the mesh component
	FName MeshToFind(TEXT("SpawnerOutside"));

	for (USceneComponent* ChildComponent : DefaultRoot->GetAttachChildren())
	{
		if (ChildComponent->GetName() == MeshToFind.ToString())
		{
			SpawnerMesh = Cast<UStaticMesh>(ChildComponent);
		}
	}

	//Call
	ChangeMaterial();

	//Initalise TimerEvent
	World->GetTimerManager().SetTimer(TimerHandle, this, &ABoxSpawner::TimerEvent, Time, true);
}



void ABoxSpawner::TimerEvent()
{

	FVector SpawnLocation = GetActorLocation();

	//Check sound is assigned
	if (SpawnSound)
	{
		//Play sound cue at location
		UGameplayStatics::PlaySoundAtLocation(this, SpawnSound, SpawnLocation);
	}

	//Get a location of the billboard component
	FTransform SpawnLoaction = Billboard->GetComponentTransform();

	//Actually spawn a box
	World->SpawnActor<ABoxes>(ABoxes::StaticClass(), SpawnLoaction);

	//Increase Spawned box counter
	BoxSpawnCount += 1;

	if (BoxSpawnCount >= BoxesToSpawn)
	{
		//Clear and invalidate the timer handle
		World->GetTimerManager().ClearTimer(TimerHandle);
	}
}

//Changes apparence based of the box type its spawning
void ABoxSpawner::ChangeMaterial()
{
	//Find the material to change the spawner apperance
    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialFinder(TEXT("Game/c011185l/Materials/FlatColours/M_PurpleShiny.uasset"));
    MeshMaterial = MaterialFinder.Object;

    //Get the heavy box class
    UClass* HeavyBoxClass = AHeavyBoxes::StaticClass();

	//If the spawner is set to spawn heavy boxes, change the meterial
    if (BoxType == HeavyBoxClass && MeshMaterial)
    {
		SpawnerMesh->SetMaterial(0, MeshMaterial);
    }

}
