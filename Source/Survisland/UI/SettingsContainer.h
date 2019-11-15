

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SettingsContainer.generated.h"

/**
 * Native Class - Use Blueprint instead
 */
UCLASS()
class SURVISLAND_API USettingsContainer : public UUserWidget
{
	GENERATED_BODY()

	/* Opens the menu */
	UFUNCTION(BlueprintCallable)
	void BackToMenu();
};
