

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InventoryBFL.generated.h"

UENUM(Blueprintable)
enum class ESlotType : uint8
{
	BACKPACK UMETA(DisplayName = "Backpack"),
	WEAPON UMETA(DisplayName = "Weapon"),
	DEFAULT UMETA(DisplayName = "Default")
};

UENUM(Blueprintable)
enum class EArmorType : uint8
{
	HELMET UMETA(DisplayName = "Helmet"),
	BODY UMETA(DisplayName = "Body"),
	LEGS UMETA(DisplayName = "Legs")
};

UCLASS()
class SURVISLAND_API UInventoryBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
};
