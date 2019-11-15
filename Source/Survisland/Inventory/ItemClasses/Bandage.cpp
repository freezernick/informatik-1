


#include "Bandage.h"
#include "SurvislandCharacter.h"

ABandage::ABandage()
{
    SlotType = ESlotType::DEFAULT;
    ItemType = EItemType::BANDAGE;
    HealFactor = 10;
}

void ABandage::OnUse(ASurvislandCharacter* PlayerRef)
{
    PlayerRef->ChangeHealth(HealFactor);
}
