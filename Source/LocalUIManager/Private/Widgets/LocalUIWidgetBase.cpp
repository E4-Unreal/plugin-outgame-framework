// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/LocalUIWidgetBase.h"

#include "Subsystems/LocalUISubsystem.h"

ULocalUIWidgetBase::ULocalUIWidgetBase(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

ULocalUISubsystem* ULocalUIWidgetBase::GetLocalUISubsystem() const
{
    ULocalPlayer* OwningLocalPlayer = GetOwningLocalPlayer();
    return OwningLocalPlayer ? OwningLocalPlayer->GetSubsystem<ULocalUISubsystem>() : nullptr;
}

void ULocalUIWidgetBase::ShowWidgetByClass(TSubclassOf<UUserWidget> WidgetClass)
{
    if (auto Subsystem = GetLocalUISubsystem()) Subsystem->ShowWidgetByClass(WidgetClass);
}

void ULocalUIWidgetBase::HideWidgetByClass(TSubclassOf<UUserWidget> WidgetClass)
{
    if (auto Subsystem = GetLocalUISubsystem()) Subsystem->HideWidgetByClass(WidgetClass);
}

void ULocalUIWidgetBase::RequestAlertModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass)
{
    if (auto Subsystem = GetLocalUISubsystem()) Subsystem->RequestAlertModal(InModalWidgetData, WidgetClass);
}

void ULocalUIWidgetBase::RequestConfirmModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass)
{
    if (auto Subsystem = GetLocalUISubsystem()) Subsystem->RequestConfirmModal(InModalWidgetData, WidgetClass);
}

void ULocalUIWidgetBase::RequestPromptModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass)
{
    if (auto Subsystem = GetLocalUISubsystem()) Subsystem->RequestPromptModal(InModalWidgetData, WidgetClass);
}
