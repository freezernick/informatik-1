


#include "BuildingRespawner.h"
#include "Kismet/GameplayStatics.h"
#include "BuildingSpawner.h"

// Sets default values
ABuildingRespawner::ABuildingRespawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ABuildingRespawner::OnConstruction(const FTransform& Transform)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(this, ABuildingSpawner::StaticClass(), FoundActors);
	for(AActor* Actor : FoundActors)
	{
		ABuildingSpawner* Spawner = Cast<ABuildingSpawner>(Actor);
		if(Spawner)
		{
			Spawner->RespawnBuilding();
		}
	}
}