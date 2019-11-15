


#include "Drink.h"
#include "SurvislandCharacter.h"

ADrink::ADrink()
{
    SlotType = ESlotType::DEFAULT;
    ItemType = EItemType::DRINK;

    WaterFactor = 10;
}

void ADrink::OnUse(ASurvislandCharacter* PlayerRef)
{
    PlayerRef->ChangeWater(WaterFactor);
}

int32 ADrink::GetWaterFactor()
{
    return WaterFactor;
}
