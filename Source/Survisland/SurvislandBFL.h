

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SurvislandBFL.generated.h"

/**
 * Helper class
 */
UCLASS()
class SURVISLAND_API USurvislandBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/**
	 * Function that gets the current GameInstance and casts to USurvislandGI
	 */
	UFUNCTION(BlueprintPure, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "Utility")
	static class USurvislandGI* GetSurvislandGI(UObject* WorldContextObject);

	/**
	 * Function that gets the current PlayerController and casts to ASurvislandPC
	 */
	UFUNCTION(BlueprintPure, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "Utility")
	static class ASurvislandPC* GetSurvislandPC(UObject* WorldContextObject);

	/**
	 * Returns the current SaveGameReference in the SurvislandGI
	 * @return The SaveGameObject
	 */
	UFUNCTION(BlueprintPure, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "Utility|Save")
	static class USurvislandSave* GetSurvislandSave(UObject* WorldContextObject);

	/**
	 * Saves the current values to the save game
	 */
	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "Utility|Save")
	static void SaveSurvislandSave(UObject* WorldContextObject);

	/**
	 * Logs the specified message with the 'Survisland' log category
	 * Only supports 'Log' verbosity
	 * @param Message The message that should be logged 
	 */
	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "Utility|Logging")
	static void SurvislandLog(FString LogMessage);
};
