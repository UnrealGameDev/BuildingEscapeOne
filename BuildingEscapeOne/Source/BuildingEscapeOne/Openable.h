// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Components/ActorComponent.h"
#include "Openable.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOpenEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPEONE_API UOpenable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenable();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	// Depending switch can be chosen from Editor
	UPROPERTY(EditAnywhere)
	AActor* DependingSwitch;

	// Generate event if opened (used in BluePrint)
	UPROPERTY(BlueprintAssignable)
	FOpenEvent OnOpen;

	// Generate event if closed (used in BluePrint)
	UPROPERTY(BlueprintAssignable)
	FOpenEvent OnClose;

private:
	// Called if switch event detected
	UFUNCTION()
	void OnSwichtChange(AActor* SwitchingActor, bool SwitchState);
	
};
