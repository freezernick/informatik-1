


#include "Backpack.h"

ABackpack::ABackpack()
{
    SlotType = ESlotType::BACKPACK;
    ItemType = EItemType::BANDAGE;

    WeightLimit = 10;

}

int32 ABackpack::GetWeightLimit()
{
    return WeightLimit;
}