
#include "BuildingSpawner.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Engine/StaticMesh.h"

// Sets default values
ABuildingSpawner::ABuildingSpawner()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
	if(MeshReference)
	{
		MeshComponent->SetStaticMesh(MeshReference);
		MeshSize = MeshReference->GetBounds().BoxExtent.X;
		MeshHeight = MeshReference->GetBounds().BoxExtent.Z;
	}

	DoorComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorComponent"));
	DoorComponent->SetupAttachment(RootComponent);
	if(DoorMesh)
	{
		DoorComponent->SetStaticMesh(DoorMesh);
	}
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Width = 2;
	Height = 0;
	Length = 2;
	WallColor = FColor(120, 120, 120, 255);
}

void ABuildingSpawner::UpdateMesh(UStaticMesh* NewMesh, UStaticMesh* NewDoorMesh)
{
	if(NewMesh)
	{
		MeshReference = NewMesh;
		MeshComponent->SetStaticMesh(MeshReference);
	}
	if(NewDoorMesh)
	{
		DoorMesh = NewDoorMesh;
		DoorComponent->SetStaticMesh(DoorMesh);
	}
}

void ABuildingSpawner::UpdateBuilding()
{
	Clear();
	if(MeshReference)
	{
		for(int n = 0; n <= Height; n++)
		{
			for(int i = 0; i <= Width; i++)
			{
				FTransform Transform1 = FTransform(FVector(MeshSize*i,0,MeshHeight*n));
				SavedTransforms.Add(Transform1);
				MeshComponent->AddInstance(Transform1);
				FTransform Transform2 = FTransform(FVector(MeshSize*i, MeshSize*(Length+1),MeshHeight*n));
				SavedTransforms.Add(Transform2);
				MeshComponent->AddInstance(Transform2);
			}
			for(int k = 0; k <= Length; k++)
			{
				FTransform Transform1 = FTransform(FRotator(0,90,0), FVector(0, MeshSize*k, n*MeshHeight));
				SavedTransforms.Add(Transform1);
				MeshComponent->AddInstance(Transform1);
				FTransform Transform2 = FTransform(FRotator(0,90,0), FVector(MeshSize*(Width+1), MeshSize*k, n*MeshHeight));
				SavedTransforms.Add(Transform2);
				MeshComponent->AddInstance(Transform2);
			}
		}
	}
}

void ABuildingSpawner::RespawnBuilding()
{
	Clear();
	for(FTransform Transform : SavedTransforms)
	{
		MeshComponent->AddInstance(Transform);
	}
}

void ABuildingSpawner::Clear()
{
	MeshComponent->ClearInstances();
	StairsComponent->ClearInstances();
	FloorComponent->ClearInstances();
}

void ABuildingSpawner::ClearSavedBuilding()
{
	SavedTransforms.Empty();
}