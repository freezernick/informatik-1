

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SurvislandGI.generated.h"

class USelector;
class USurvislandSave;

/**
 * Native Class - Use Blueprit implementation
 */
UCLASS()
class SURVISLAND_API USurvislandGI : public UGameInstance
{
	GENERATED_BODY()

public:

	void Init();

	UPROPERTY(EditAnywhere)
	TSubclassOf<USurvislandSave> SaveGameObject;

	UPROPERTY(BlueprintReadOnly)
	USurvislandSave* SaveGameReference;

		/**
	 * Tries to add the main menu to the screen
	 * @return Whether the menu could be added or not
	 */
	UFUNCTION(BlueprintCallable)
	bool AddMainMenu();

	/**
	 * Tries to add the settings container to the screen
	 * @return Whether the settings widget could be added or not
	 */
	UFUNCTION(BlueprintCallable)
	bool AddSettings();

	/**
	 * Tries to add the HUD to the screen
	 * @return Whether the container could be added or not
	 */
	UFUNCTION(BlueprintCallable)
	bool AddHUD();

	/**
	 * Creates a new UUserWidget and tries to add it to the screen
	 * @param WidgetBP The WidgetBlueprint that should be created
	 * @return Whether the widget could be added to the screen or not
	 */
	bool CreateWidgetBP(TSubclassOf<class UUserWidget> WidgetBP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UMainMenu> MainMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class USettingsContainer> Settings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UHUDContainer> HUD;
};
