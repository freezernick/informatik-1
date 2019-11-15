

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * Native Class - Use Blueprint instead
 */
UCLASS()
class SURVISLAND_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:

	void Construct();

	/* Defines whether the 'Continue' button should be displayed or not */
	UPROPERTY(BlueprintReadOnly)
	bool bDoesSaveExist;

	/* Loads the saved game */
	UFUNCTION(BlueprintCallable)
	void ContinueGame();

	/* Creates a new save game */
	UFUNCTION(BlueprintCallable)
	void NewGame();

	/* Shows the settings window */
	UFUNCTION(BlueprintCallable)
	void Settings();
};
