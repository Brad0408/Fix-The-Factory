// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorCleanup.h"
#include "Boxes.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFloorCleanup::AFloorCleanup()
{


}

// Called when the game starts or when spawned
void AFloorCleanup::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComponent = FindComponentByClass<UBoxComponent>();


	//Call Overlap Logic
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AFloorCleanup::OnOverlapEvent);
}


void AFloorCleanup::OnOverlapEvent(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//GetRef to the box that overlapped
	ABoxes* BoxesRef = Cast<ABoxes>(OtherActor);

	//Increase Dropped Count
	DroppedCount += 1;

	//UI is also increased here in BP

	//Destroy the box
	BoxesRef->Destroy();

	FVector SpawnLocation = GetActorLocation();

	//Check sound is assigned
	if (BoxPoofSound)
	{
		//Play sound cue at location
		UGameplayStatics::PlaySoundAtLocation(this, BoxPoofSound, SpawnLocation);
	}


	LossCheck();
}

//Ends the game is too much is dropped
void AFloorCleanup::LossCheck()
{
	if (DroppedCount >= AmountToFail)
	{

		//An Event Dispatcher is also called here ("EndGameLoss") in BP, this is being listening to in the GameMode

		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}



