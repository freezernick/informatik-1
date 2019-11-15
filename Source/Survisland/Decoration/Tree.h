

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tree.generated.h"

class UStaticMeshComponent;
class UStaticMesh;

UCLASS()
class SURVISLAND_API ATree : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATree();
	
	UPROPERTY(EditAnywhere)
	UStaticMesh* TrunkMesh;

	UPROPERTY(EditAnywhere)
	UStaticMesh* TopMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Trunk;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Top;

}; 