


#include "GraphicSettings.h"

int32 UGraphicSettings::UpdateIndex(ESettingsType Type, int32 IndexDelta)
{
    FString VariableName = "";
    switch(Type)
    {
        case ESettingsType::PP:
            VariableName = "sg.PostProcessQuality";
            break;
        case ESettingsType::Effects:
            VariableName = "sg.EffectsQuality";
            break;
        case ESettingsType::Shadows:
            VariableName = "sg.ShadowQuality";
            break;
        case ESettingsType::Textures:
            VariableName = "sg.TextureQuality";
            break;
        default:
            return -1; // A check for -1 prevents blindy copying potentially invalid indexes
    }

    /**
     * Settings for the renderer are applied as a console command. For this we get the current value and modify it
     * See https://docs.unrealengine.com/en-US/Programming/Development/Tools/ConsoleManager/index.html
     * for reference
    */
    IConsoleVariable* Variable = IConsoleManager::Get().FindConsoleVariable(*VariableName);
    if(Variable)
    {
        int32 NewLevel = Variable->GetInt() + IndexDelta;
        if(NewLevel <= 3 && NewLevel >= 0) // Checks if the new level would be in range of the variable
        {
            Variable->Set(NewLevel);
            return NewLevel; // Allows us to update the user interface accordingly
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}