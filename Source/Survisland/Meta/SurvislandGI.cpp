


#include "SurvislandGI.h"
#include "Kismet/GameplayStatics.h"
#include "UI/MainMenu.h"
#include "UI/Hud/HUDContainer.h"
#include "UI/SettingsContainer.h"
#include "Blueprint/UserWidget.h"
#include "Survisland.h"

void USurvislandGI::Init()
{
    if(!WITH_EDITOR) // we only want to show the main menu at runtime
    {
        AddMainMenu();
    }
}

bool USurvislandGI::AddMainMenu()
{
    if(MainMenu)
    {
        if(CreateWidgetBP(MainMenu))
        {
            UGameplayStatics::GetPlayerController(this, 0)->bShowMouseCursor = true;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        UE_LOG(Survisland, Error, TEXT("MainMenu widget is invalid!"));
        return false;
    }
}

bool USurvislandGI::AddSettings()
{
    if(Settings)
    {
        return CreateWidgetBP(Settings);
    }
    else
    {
        UE_LOG(Survisland, Error, TEXT("Settings widget is invalid!"));
        return false;
    }
}

bool USurvislandGI::AddHUD()
{
    if(HUD)
    {
        UGameplayStatics::GetPlayerController(this, 0)->bShowMouseCursor = false;
        return CreateWidgetBP(HUD);
    }
    else
    {
        UE_LOG(Survisland, Error, TEXT("HUDContainer widget is invalid!"));
        return false;
    }
}

bool USurvislandGI::CreateWidgetBP(TSubclassOf<UUserWidget> WidgetBP)
{
    /* We get the current PlayerController which will be the owner of the widget */
    APlayerController* Controller = UGameplayStatics::GetPlayerController(this, 0);
    /** Creates a widget that is a child of UUserWidet and has the Controller as an owner
     * and the WidgetBP Blueprint Implementation */
    UUserWidget* Widget = CreateWidget<UUserWidget>(Controller, WidgetBP); 
    return Widget->AddToPlayerScreen();
}