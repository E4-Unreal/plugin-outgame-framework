// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelTransitionManagerSettings.h"

#include "Logging.h"
#include "Blueprint/UserWidget.h"

ULevelTransitionManagerSettings::ULevelTransitionManagerSettings()
{
    CategoryName = "Plugins";
    SectionName = "LevelTransitionManager";

    bAllowInEarlyStartup = false;
    PlaybackType = MT_Normal;
    bAllowEngineTick = false;
    bWaitForManualStop = false;
    bAutoCompleteWhenLoadingCompletes = false;
    MinimumLoadingScreenDisplayTime = 2.f;
}

TSoftObjectPtr<UWorld> ULevelTransitionManagerSettings::GetLevelByName(FName LevelName) const
{
    auto LevelPtr = LevelMap.Find(LevelName);
    auto Level = LevelPtr == nullptr ? nullptr : *LevelPtr;
    Level.LoadSynchronous();

    if (Level == nullptr) LOG(Error, TEXT("%s is not found"), *LevelName.ToString())

    return Level;
}

FLoadingScreenAttributes ULevelTransitionManagerSettings::GetLoadingScreenAttributes(UGameInstance* GameInstance)
{
    if (LoadingScreenWidget == nullptr)
    {
        if (TSubclassOf<UUserWidget> WidgetClass = LoadingScreenWidgetClass.LoadSynchronous())
        {
            LoadingScreenWidget = CreateWidget(GameInstance, WidgetClass);
        }
    }

    FLoadingScreenAttributes LoadingScreenAttributes;
    LoadingScreenAttributes.bAllowInEarlyStartup = bAllowInEarlyStartup;
    LoadingScreenAttributes.PlaybackType = PlaybackType;
    LoadingScreenAttributes.bAllowEngineTick = bAllowEngineTick;
    LoadingScreenAttributes.bWaitForManualStop = bWaitForManualStop;
    LoadingScreenAttributes.bAutoCompleteWhenLoadingCompletes = bAutoCompleteWhenLoadingCompletes;
    LoadingScreenAttributes.MinimumLoadingScreenDisplayTime = MinimumLoadingScreenDisplayTime;
    LoadingScreenAttributes.WidgetLoadingScreen = LoadingScreenWidget->TakeWidget();

    return LoadingScreenAttributes;
}
