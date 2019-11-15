


#include "MainMenu.h"
#include "SurvislandBFL.h"
#include "Kismet/GameplayStatics.h"
#include "Saves/SurvislandSave.h"
#include "Meta/SurvislandGI.h"

void UMainMenu::Construct()
{
    if(UGameplayStatics::DoesSaveGameExist("SurvislandSave", 0))
    {
        bDoesSaveExist = true;
    }
}

void UMainMenu::ContinueGame()
{
    USurvislandGI* MyGI = USurvislandBFL::GetSurvislandGI(this);
    MyGI->SaveGameReference = Cast<USurvislandSave>(UGameplayStatics::LoadGameFromSlot("SurvislandSave", 0));
}

void UMainMenu::NewGame()
{
    USurvislandGI* MyGI = USurvislandBFL::GetSurvislandGI(this);
    MyGI->SaveGameReference = Cast<USurvislandSave>(UGameplayStatics::CreateSaveGameObject(USurvislandSave::StaticClass()));
}

void UMainMenu::Settings()
{
    RemoveFromParent();
}