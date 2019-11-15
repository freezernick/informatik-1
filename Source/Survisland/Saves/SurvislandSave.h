

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SurvislandSave.generated.h"

/**
 * The SaveGame Class
 */
UCLASS()
class SURVISLAND_API USurvislandSave : public USaveGame
{
	GENERATED_BODY()

public:

	int32 ShadowIndex;

	int32 EffectIndex;

	int32 ViewDistanceIndex;
};
