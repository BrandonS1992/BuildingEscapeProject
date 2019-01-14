// Copyright Brandon Santangelo 2018.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h" //generated.h has to be the last #include

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BluePrintAssignable)
		FOnOpenRequest OnOpenRequest;

private: 
	UPROPERTY(EditAnywhere) //Macro = dangerous if wrong
		float OpenAngle = -90.0f;

	UPROPERTY(EditAnywhere) //Macro = dangerous if wrong
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 1.f;

		float LastDoorOpenTime;

		// The owning door
		AActor* Owner = nullptr; 
	
		// Returns total mass in kg
		float GetTotalMassOfActorsOnPlate();

};

