// Fill out your copyright notice in the Description page of Project Settings.


#include "GlowingLight.h"

// Sets default values
AGlowingLight::AGlowingLight()
{

}

// Called when the game starts or when spawned
void AGlowingLight::BeginPlay()
{
	Super::BeginPlay();
	
	//Find the light component
	GlowLight = FindComponentByClass<UPointLightComponent>();

	//If set to red in the editor
	if (isRed)
	{
		//Set colour to red
		FLinearColor LightColour(1.0f, 0.0f, 0.0f, 1.0f);
		GlowLight->SetLightColor(LightColour, true);
	}
	else
	{
		//Set the colour to green
		FLinearColor LightColour(0.0f, 1.0f, 0.0f, 1.0f);
		GlowLight->SetLightColor(LightColour, true);
	}


	//Then in BP a timeline is used to modify the intensity of the light
}
