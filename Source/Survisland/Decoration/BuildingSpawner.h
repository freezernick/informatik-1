

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuildingSpawner.generated.h"

class UStaticMesh;
class UInstancedStaticMeshComponent;

/**
 * Native Class - Use Blueprint instead
 */
UCLASS()
class SURVISLAND_API ABuildingSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingSpawner();

	// Properties

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Width;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Length;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor WallColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* StairMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* FloorMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* WindowMesh;

	/* How many wall meshes should be places between two windows */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 WindowSpacing;

	/* Side of the building where the door should be placed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	int32 EntrancePosition;

	/* At which instance index the door mesh should be placed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	int32 EntranceOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	UStaticMesh* DoorMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* CustomMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MeshSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MeshHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bRespawn;

protected:

	UStaticMesh* MeshReference;

	UPROPERTY(SaveGame)
	TArray<FTransform> SavedTransforms;

public:

	// Functions

	/**
	 * Updated the internal mesh reference
	 * @param NewMesh The static mesh that should be used
	 */
	UFUNCTION(BlueprintCallable)
	void UpdateMesh(UStaticMesh* NewMesh, UStaticMesh* NewDoorMesh);

	/**
	 * Updates the InstancedStaticMeshComponent
	 */
	UFUNCTION(BlueprintCallable)
	void UpdateBuilding();

	/**
	 * Spawns a new building with the transforms saved in SavedTransforms
	 */
	UFUNCTION(BlueprintCallable)
	void RespawnBuilding();

	/**
	 * Clears all instances of the MeshComponent
	 */
	UFUNCTION(BlueprintCallable)
	void Clear();

	/**
	 * Empties the array with mesh transforms
	 */
	UFUNCTION(BlueprintCallable)
	void ClearSavedBuilding();

	// Components

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* DoorComponent;

	UPROPERTY(VisibleDefaultsOnly)
	UInstancedStaticMeshComponent* WindowComponent;

	UPROPERTY(VisibleDefaultsOnly)
	UInstancedStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleDefaultsOnly)
	UInstancedStaticMeshComponent* FloorComponent;

	UPROPERTY(VisibleDefaultsOnly)
	UInstancedStaticMeshComponent* StairsComponent;

};
