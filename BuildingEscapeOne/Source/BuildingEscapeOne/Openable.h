// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Components/ActorComponent.h"
#include "Openable.generated.h"

// Posible switching conditions
UENUM()
enum class ESwitchingCondition : uint8
{
	AllOn,
	SingleOn,
	AllOrderedOn
};

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

	UPROPERTY(EditAnywhere)
	ESwitchingCondition SwitchingCondition = ESwitchingCondition::SingleOn;

	// Multiple depending switch can be chosen from Editor
	UPROPERTY(EditAnywhere)
	TArray<AActor*> DependingSwitches;

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

	// Remender the startup switch order (enable odered switching check)
	TArray<int>	ExpectedSwitchOrder;

	// Holds the actual active switches (could be used for switching checks)
	TArray<int>	ActualSwitchOrder;
	
};
