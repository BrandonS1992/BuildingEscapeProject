// Copyright Brandon Santangelo 2018.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h" //generated.h has to be the last #include


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

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private: 
	UPROPERTY(VisibleAnywhere) //Macro = dangerous if wrong
		float OpenAngle = 90.0f;

	UPROPERTY(EditAnywhere) //Macro = dangerous if wrong
		ATriggerVolume* PressurePlate;

		AActor* ActorThatOpens; 
	
};
