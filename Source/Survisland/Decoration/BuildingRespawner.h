

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuildingRespawner.generated.h"

/**
 * This class will get all BuildingSpawners in the current world and call RespawnBuilding() on them
 */
UCLASS()
class SURVISLAND_API ABuildingRespawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingRespawner();

	void OnConstruction(const FTransform& Transform) override;

};
