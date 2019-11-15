
#include "Tree.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ATree::ATree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Trunk = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Trunk"));
	Trunk->SetupAttachment(RootComponent);
	if(TrunkMesh)
	{
		Trunk->SetStaticMesh(TrunkMesh);
	}
	Top = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Top"));
	Top->SetupAttachment(Trunk);
	if(TopMesh)
	{
		Top->SetStaticMesh(TopMesh);
	}

	FRotator RandomRotation = UKismetMathLibrary::RandomRotator();
	SetActorRotation(RandomRotation);

}