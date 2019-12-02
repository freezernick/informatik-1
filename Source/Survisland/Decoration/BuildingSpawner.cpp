
#include "BuildingSpawner.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
ABuildingSpawner::ABuildingSpawner()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	WallComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("WallComponent"));
	WallComponent->SetupAttachment(RootComponent);
	if(MeshReference)
	{
		WallComponent->SetStaticMesh(MeshReference);
		MeshSize = MeshReference->GetBounds().BoxExtent.X;
		MeshHeight = MeshReference->GetBounds().BoxExtent.Z;
	}

	DoorComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorComponent"));
	DoorComponent->SetupAttachment(RootComponent);
	if(DoorMesh)
	{
		DoorComponent->SetStaticMesh(DoorMesh);
	}

	FloorComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("FloorComponent"));
	FloorComponent->SetupAttachment(RootComponent);
	if(FloorMesh)
	{
		FloorComponent->SetStaticMesh(FloorMesh);
	}

	WindowComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("WindowComponent"));
	WindowComponent->SetupAttachment(RootComponent);
	if(WindowMesh)
	{
		WindowComponent->SetStaticMesh(WindowMesh);
	}

	StairsComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("StairComponent"));
	StairsComponent->SetupAttachment(RootComponent);
	if(StairMesh)
	{
		StairsComponent->SetStaticMesh(StairMesh);
	}


 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Width = 2;
	Height = 0;
	Length = 2;
	Color = FColor(120, 120, 120, 255);

	WallMaterial = WallComponent->CreateDynamicMaterialInstance(0, BaseMaterial);
	FloorMaterial = FloorComponent->CreateDynamicMaterialInstance(0, BaseMaterial);
	DoorMaterial = DoorComponent->CreateDynamicMaterialInstance(0, BaseMaterial);
	WindowMaterial = WindowComponent->CreateDynamicMaterialInstance(0, BaseMaterial);
}

void ABuildingSpawner::UpdateMesh(UStaticMesh* NewMesh, UStaticMesh* NewDoorMesh)
{
	if(NewMesh)
	{
		MeshReference = NewMesh;
		WallComponent->SetStaticMesh(MeshReference);
	}
	if(NewDoorMesh)
	{
		DoorMesh = NewDoorMesh;
		DoorComponent->SetStaticMesh(DoorMesh);
	}

}

void ABuildingSpawner::OnConstruction(const FTransform& Transform)
{
	if(WallMaterial)
	{
		WallMaterial->SetVectorParameterValue("Color", Color);
	}
	if(FloorMaterial)
	{
		FloorMaterial->SetVectorParameterValue("Color", Color);
	}
	if(DoorMaterial)
	{
		DoorMaterial->SetVectorParameterValue("Color", Color);
	}
	if(WindowMaterial)
	{
		WindowMaterial->SetVectorParameterValue("Color", Color);
	}
}

void ABuildingSpawner::UpdateBuilding()
{
	Clear();
	// if(MeshReference)
	// {
	// 	for(int n = 0; n <= Height; n++)
	// 	{
	// 		for(int i = 0; i <= Width; i++)
	// 		{
	// 			FTransform Transform1 = FTransform(FVector(MeshSize*i,0,MeshHeight*n));
	// 			SavedTransforms.Add(Transform1);
	// 			WallComponent->AddInstance(Transform1);
	// 			FTransform Transform2 = FTransform(FVector(MeshSize*i, MeshSize*(Length+1),MeshHeight*n));
	// 			SavedTransforms.Add(Transform2);
	// 			WallComponent->AddInstance(Transform2);
	// 		}
	// 		for(int k = 0; k <= Length; k++)
	// 		{
	// 			FTransform Transform1 = FTransform(FRotator(0,90,0), FVector(0, MeshSize*k, n*MeshHeight));
	// 			SavedTransforms.Add(Transform1);
	// 			WallComponent->AddInstance(Transform1);
	// 			FTransform Transform2 = FTransform(FRotator(0,90,0), FVector(MeshSize*(Width+1), MeshSize*k, n*MeshHeight));
	// 			SavedTransforms.Add(Transform2);
	// 			WallComponent->AddInstance(Transform2);
	// 		}
	// 	}
	// }

	if(!MeshReference)
	{
		return;
	}

	for(int i = 0; i <= Height; i++)
	{
		for(int n = 0; n <= Width; n++)
		{

		}

		for(int x = 0; x <= Length; x++)
		{

		}
	}
}

void ABuildingSpawner::RespawnBuilding()
{
	Clear();
	for(FTransform Transform : SavedTransforms)
	{
		WallComponent->AddInstance(Transform);
	}
}

void ABuildingSpawner::Clear()
{
	WallComponent->ClearInstances();
	StairsComponent->ClearInstances();
	FloorComponent->ClearInstances();
}

void ABuildingSpawner::ClearSavedBuilding()
{
	SavedTransforms.Empty();
}

void ABuildingSpawner::ChangeColor(FLinearColor NewColor)
{
	Color = NewColor;
}