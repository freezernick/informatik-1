


#include "GraphicSettings.h"

int32 UGraphicSettings::UpdateIndex(ESettingsType Type, int32 IndexDelta)
{
    /**
     * Settings for the renderer are applied as a console command. For this we get the current value and modify it
     * See https://docs.unrealengine.com/en-US/Programming/Development/Tools/ConsoleManager/index.html
     * for reference
    */
    IConsoleVariable* Variable = GetConsoleVar(Type);
    if(!Variable)
    {
        return -1;
    }

    int32 NewLevel = Variable->GetInt() + IndexDelta;
    if(NewLevel > 3 || NewLevel < 0) // Checks if the new level would be out of range for the variable
    {
        return -1;
    }

    Variable->Set(NewLevel);
    return NewLevel; // Allows us to update the user interface accordingly
}

int32 UGraphicSettings::GetIndex(ESettingsType Type)
{
    IConsoleVariable* Variable = GetConsoleVar(Type);
    if(!Variable)
    {
        return -1;
    }
    return Variable->GetInt();
}

IConsoleVariable* UGraphicSettings::GetConsoleVar(ESettingsType Type)
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
            return nullptr;
            break;
    }

    return IConsoleManager::Get().FindConsoleVariable(*VariableName);
}