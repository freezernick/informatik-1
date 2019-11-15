

#pragma once

#include "CoreMinimal.h"
#include "Inventory/PickableItem.h"
#include "Bandage.generated.h"

class ASurvislandCharacter;

UCLASS()
class SURVISLAND_API ABandage : public APickableItem
{
	GENERATED_BODY()
	
	ABandage();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
	int32 HealFactor;

public:

	virtual void OnUse(ASurvislandCharacter* PlayerRef) override;
};
