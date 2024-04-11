// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowTrack.h"
#include "Components/BoxComponent.h" 
#include "Components/ArrowComponent.h" 
#include "Components/SceneComponent.h"
#include "Components/BillboardComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "BoxNormal.h"

void ASlowTrack::BeginPlay()
{

	Super::BeginPlay();



	//Names of the Box components
	FName ConveyorBoxToFind(TEXT("Box"));
	FName SnapBoxToFind(TEXT("SnapBox"));

	//Find the Components
	Arrow = FindComponentByClass<UArrowComponent>();
	Billboard = FindComponentByClass<UBillboardComponent>();


	for (USceneComponent* ChildComponent : DefaultRoot->GetAttachChildren())
	{
		if (ChildComponent->GetName() == ConveyorBoxToFind.ToString())
		{
			ConveyorOverlapBox = Cast<UBoxComponent>(ChildComponent);
		}

		if (ChildComponent->GetName() == SnapBoxToFind.ToString())
		{
			SnapBox = Cast<UBoxComponent>(ChildComponent);
		}
	}

	//Call Overlap Logic
	SnapBox->OnComponentBeginOverlap.AddDynamic(this, &ASlowTrack::OnOverlapEvent);
}


void ASlowTrack::Tick(float DeltaTime)
{

	//Create array of overlapped actors
	TArray<AActor*> OverlappingActors;

	//Actually store the actors once the overlap occurs
	ConveyorOverlapBox->GetOverlappingActors(OverlappingActors);

	//Using tick to constantly move - not the most effiecnet but works
	FVector VectorSpeed(Speed * DeltaTime, Speed * DeltaTime, Speed * DeltaTime);

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

void ASlowTrack::OnOverlapEvent(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Get the class of the overlapped actor
	UClass* ActorClass = OtherActor->GetClass();

	//Get the class of the box that is overlapping, only normals can bounce so only normal needs checking
	UClass* BoxNormalClass = ABoxNormal::StaticClass();


	if (ActorClass == BoxNormalClass)
	{
		FVector SnapLocation = Billboard->GetComponentLocation();
		
		FRotator NewRotaion(0.0f, 0.0f, 0.0f);

		OtherActor->SetActorLocation(SnapLocation, false, false);
		OtherActor->SetActorRotation(NewRotaion);
	}

}
