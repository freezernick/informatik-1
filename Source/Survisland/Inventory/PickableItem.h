

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryBFL.h"
#include "PickableItem.generated.h"

class UStaticMesh;
class UTexture2D;
class ASurvislandCharacter;

UENUM(Blueprintable)
enum class EItemType : uint8
{
	FOOD UMETA(DisplayName = "Food"),
	DRINK UMETA(DisplayName = "Drink"),
	GENERIC UMETA(DisplayName = "Generic"),
	BANDAGE UMETA(DisplayName = "Bandage"),
	BACKPACK UMETA(DisplayName = "Backpack")
};

UCLASS()
class SURVISLAND_API APickableItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickableItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Properties")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Properties")
	int32 Weight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Properties")
	ESlotType SlotType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Properties")
	int32 ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Properties")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Properties")
	UStaticMesh* ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Properties")
	UTexture2D* ItemTexture;

	virtual void OnUse(ASurvislandCharacter* PlayerRef);
};
