

#pragma once

#include "CoreMinimal.h"
#include "Inventory/PickableItem.h"
#include "Food.generated.h"

class ASurvislandCharacter;

UCLASS()
class SURVISLAND_API AFood : public APickableItem
{
	GENERATED_BODY()
	
	AFood();

	virtual	void OnUse(ASurvislandCharacter* PlayerRef) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
	int32 FoodFactor;

public:

	UFUNCTION(BlueprintPure)
	int32 GetFoodFactor();

};
