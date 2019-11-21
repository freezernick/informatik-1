

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
 * The name we want to show for the user for a specific index
 */
UENUM(BlueprintType)
enum class ESettingsLevel : uint8
{
	Low,
	Medium,
	High,
	Epic
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

	/**
	 * Gets the current index of the selected settings type
	 * @param Type The settings group of which the index should be returned
	 * @return The current Index. 0-3 if it's successful, -1 if it faied
	 */
	UFUNCTION(BlueprintPure)
	int32 GetIndex(ESettingsType Type);

	/**
	 * Gets the command variable of the selected console command
	 * @param Type The settings group of which command variable should be returned
	 * @return The command variable
	 */
	IConsoleVariable* GetConsoleVar(ESettingsType Type);
};
