
#pragma once

#include "CoreMinimal.h"

/** 'Survisland' is the name of the category, 'Log' the default verbosity and 'All' is the level of
 *  verbosity that will actually be compiled
 *  See https://docs.unrealengine.com/en-US/API/Runtime/Core/Logging/FLogCategoryBase/index.html
 *  and https://docs.unrealengine.com/en-US/API/Runtime/Core/Logging/ELogVerbosity__Type/index.html
 *  for reference */
DECLARE_LOG_CATEGORY_EXTERN(Survisland, Log, All);