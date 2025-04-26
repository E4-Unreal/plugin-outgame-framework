// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Menu/Main/MainMenuWidgetBase.h"

#include "Components/Button.h"
#include "Subsystems/LevelTransitionSubsystem.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UMainMenuWidgetBase::UMainMenuWidgetBase(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    MainLevelName = FName("Main");

    RequestExitData.Title = LOCTEXT("ExitGameTitle", "Exit Game");
    RequestExitData.Message = LOCTEXT("ExitGameMessage", "Are you sure you want to exit?");
    RequestExitData.ConfirmDelegate.BindDynamic(this, &ThisClass::Exit);
}

void UMainMenuWidgetBase::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (PlayButton) PlayButton->OnClicked.AddDynamic(this, &ThisClass::OnPlayButtonClicked);
    if (OptionsButton) OptionsButton->OnClicked.AddDynamic(this, &ThisClass::OnOptionsButtonClicked);
    if (ExitButton) ExitButton->OnClicked.AddDynamic(this, &ThisClass::OnExitButtonClicked);
}

void UMainMenuWidgetBase::OnPlayButtonClicked()
{
    Play();
}

void UMainMenuWidgetBase::OnOptionsButtonClicked()
{
    ShowOptionsMenuWidget();
}

void UMainMenuWidgetBase::OnExitButtonClicked()
{
    RequestConfirmModal(RequestExitData);
}

void UMainMenuWidgetBase::Play()
{
    if (auto LevelTransitionSubsystem = GetGameInstance()->GetSubsystem<ULevelTransitionSubsystem>())
    {
        LevelTransitionSubsystem->OpenLevelByName(MainLevelName);
    }
}

void UMainMenuWidgetBase::ShowOptionsMenuWidget()
{
    ShowWidgetByClass(OptionsWidgetClass);
}

void UMainMenuWidgetBase::Exit()
{
    if (ULocalPlayer* OwningLocalPlayer = GetOwningLocalPlayer())
    {
        OwningLocalPlayer->ConsoleCommand("quit");
    }
}

#undef LOCTEXT_NAMESPACE
