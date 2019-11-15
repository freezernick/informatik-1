


#include "SurvislandBFL.h"
#include "Kismet/GameplayStatics.h"
#include "Meta/SurvislandGI.h"
#include "SurvislandPC.h"
#include "Blueprint/UserWidget.h"
#include "Saves/SurvislandSave.h"
#include "Survisland.h"

USurvislandGI* USurvislandBFL::GetSurvislandGI(UObject* WorldContextObject)
{
    USurvislandGI* MyGI = Cast<USurvislandGI>(UGameplayStatics::GetGameInstance(WorldContextObject));
    return MyGI;
}

ASurvislandPC* USurvislandBFL::GetSurvislandPC(UObject* WorldContextObject)
{
    ASurvislandPC* MyPC = Cast<ASurvislandPC>(UGameplayStatics::GetPlayerController(WorldContextObject, 0));
    return MyPC;
}

USurvislandSave* USurvislandBFL::GetSurvislandSave(UObject* WorldContextObject)
{
    USurvislandGI* MyGI = GetSurvislandGI(WorldContextObject);
    return MyGI->SaveGameReference;
}

void USurvislandBFL::SaveSurvislandSave(UObject* WorldContextObject)
{
    USurvislandSave* Save = GetSurvislandSave(WorldContextObject);
    UGameplayStatics::SaveGameToSlot(Save, "SurvislandSave", 0);
}

void USurvislandBFL::SurvislandLog(FString LogMessage)
{
    UE_LOG(Survisland, Log, TEXT("%s"), *LogMessage);
}