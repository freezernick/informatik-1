


#include "PickableItem.h"
#include "SurvislandCharacter.h"
#include "Engine/StaticMesh.h"
#include "Engine/Texture2D.h"

// Sets default values
APickableItem::APickableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Weight = 0;
	SlotType = ESlotType::DEFAULT;

	ItemID = 0;
	Name = "";

	ItemMesh = nullptr;
	ItemTexture = nullptr;

}

// Called when the game starts or when spawned
void APickableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickableItem::OnUse(ASurvislandCharacter* PlayerRef)
{
	
}