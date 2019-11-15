
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SurvislandGameMode.generated.h"

UENUM(BlueprintType)
enum class EGameState : uint8
{
	Menu,
	Game
};

UCLASS(minimalapi)
class ASurvislandGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	UPROPERTY()
	EGameState State;

	UFUNCTION(BlueprintCallable)
	void Menu();

	UFUNCTION(BlueprintCallable)
	void Game();
};