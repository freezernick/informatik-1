

#pragma once

#include "CoreMinimal.h"
#include "Inventory/PickableItem.h"
#include "Backpack.generated.h"

/**
 * 
 */
UCLASS()
class SURVISLAND_API ABackpack : public APickableItem
{
	GENERATED_BODY()
	
	ABackpack();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
	int32 WeightLimit;

public:

	UFUNCTION(BlueprintPure)
	int32 GetWeightLimit();
};
