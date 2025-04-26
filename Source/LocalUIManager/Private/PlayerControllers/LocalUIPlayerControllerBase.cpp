// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllers/LocalUIPlayerControllerBase.h"

#include "Subsystems/LocalUISubsystem.h"

void ALocalUIPlayerControllerBase::BeginPlay()
{
    Super::BeginPlay();

    for (auto PlayerWidgetClass : PlayerWidgetClasses)
    {
        ShowWidgetByClass(PlayerWidgetClass);
    }
}

ULocalUISubsystem* ALocalUIPlayerControllerBase::GetLocalUISubsystem() const
{
    ULocalPlayer* OwningLocalPlayer = GetLocalPlayer();
    return OwningLocalPlayer ? OwningLocalPlayer->GetSubsystem<ULocalUISubsystem>() : nullptr;
}

void ALocalUIPlayerControllerBase::ShowWidgetByClass(TSubclassOf<UUserWidget> WidgetClass)
{
    if (auto Subsystem = GetLocalUISubsystem()) Subsystem->ShowWidgetByClass(WidgetClass);
}

void ALocalUIPlayerControllerBase::HideWidgetByClass(TSubclassOf<UUserWidget> WidgetClass)
{
    if (auto Subsystem = GetLocalUISubsystem()) Subsystem->HideWidgetByClass(WidgetClass);
}

void ALocalUIPlayerControllerBase::RequestAlertModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass)
{
    if (auto Subsystem = GetLocalUISubsystem()) Subsystem->RequestAlertModal(InModalWidgetData, WidgetClass);
}

void ALocalUIPlayerControllerBase::RequestConfirmModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass)
{
    if (auto Subsystem = GetLocalUISubsystem()) Subsystem->RequestConfirmModal(InModalWidgetData, WidgetClass);
}

void ALocalUIPlayerControllerBase::RequestPromptModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass)
{
    if (auto Subsystem = GetLocalUISubsystem()) Subsystem->RequestPromptModal(InModalWidgetData, WidgetClass);
}
