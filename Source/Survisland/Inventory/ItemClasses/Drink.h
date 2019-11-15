

#pragma once

#include "CoreMinimal.h"
#include "Inventory/PickableItem.h"
#include "Drink.generated.h"

class ASurvislandCharacter;

UCLASS()
class SURVISLAND_API ADrink : public APickableItem
{
	GENERATED_BODY()

	ADrink();

	virtual void OnUse(ASurvislandCharacter* PlayerRef) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 WaterFactor;

public:

	UFUNCTION(BlueprintPure)
	int32 GetWaterFactor();
};
