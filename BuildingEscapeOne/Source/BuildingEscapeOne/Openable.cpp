// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingEscapeOne.h"
#include "Openable.h"
#include "Switchable.h"

// Sets default values for this component's properties
UOpenable::UOpenable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenable::BeginPlay()
{
	Super::BeginPlay();

	if (!DependingSwitch)
	{
		UE_LOG(LogTemp, Warning, TEXT("No depending switch choosen for %s"), *GetOwner()->GetName());
		return;
	}

	USwitchable* Switchable = DependingSwitch->FindComponentByClass<USwitchable>();
	if (Switchable)
	{
		Switchable->SwitchEvent.AddDynamic(this, &UOpenable::OnSwichtChange);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Switchable component found for %s assigned to %s"), *DependingSwitch->GetName(), *GetOwner()->GetName());
	}
	
	
}


// Called every frame
void UOpenable::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UOpenable::OnSwichtChange(AActor * SwitchingActor, bool SwitchState)
{
	if (SwitchState)
	{
		OnOpen.Broadcast();
	}
	else
	{
		OnClose.Broadcast();
	}
}

