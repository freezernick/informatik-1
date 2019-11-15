

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GraphicSettings.generated.h"

/**
 * All settings or groups of settings that we allow to be changed
 * See https://docs.unrealengine.com/en-US/Engine/Performance/Scalability/ScalabilityReference/index.html
 * for reference
*/
UENUM(BlueprintType)
enum class ESettingsType : uint8
{
	PP UMETA(DisplayName="Post Processing"),
	Shadows,
	Textures,
	Effects
};

/**
 * Native Class - Use Blueprint instead
 */
UCLASS()
class SURVISLAND_API UGraphicSettings : public UUserWidget
{
	GENERATED_BODY()

	/**
	 * Increases or decreases the index for the selected type
	 * @param Type The variable or settings group that should be updated
	 * @param Index The new index (should be +/-1)
	 * @return The new index. Returns -1 if the index is out of range or console variable couldn't be found
	 */
	UFUNCTION(BlueprintCallable)
	int32 UpdateIndex(ESettingsType Type, int32 Index);
};
