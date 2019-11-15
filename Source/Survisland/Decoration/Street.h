

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Street.generated.h"

class UStaticMesh;
class USplineComponent;
class UStaticMeshComponent;

UCLASS()
class SURVISLAND_API AStreet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStreet();

protected:

	UPROPERTY(BlueprintReadOnly)
	USplineComponent* Spline;

	UPROPERTY()
	UStaticMeshComponent* EndComponent;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* MeshReference;

	UPROPERTY(EditAnywhere, Category = "End Mesh")
	TSubclassOf<AActor> EndActor;

	UPROPERTY(EditAnywhere, Category = "End Mesh")
	UStaticMesh* EndMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TangentLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float EndTangentLength;

protected:

	void UpdateMesh();

	UFUNCTION(BlueprintCallable)
	void SpawnEndMesh();

	UFUNCTION(BlueprintCallable)
	void SpawnEndActor();
};
