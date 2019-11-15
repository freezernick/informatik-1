


#include "Food.h"
#include "SurvislandCharacter.h"

AFood::AFood()
{
    ItemType = EItemType::FOOD;
    SlotType = ESlotType::DEFAULT;
    FoodFactor = 10;
}

void AFood::OnUse(ASurvislandCharacter* PlayerRef)
{
    PlayerRef->ChangeFood(FoodFactor);
}

int32 AFood::GetFoodFactor()
{
    return FoodFactor;
}

