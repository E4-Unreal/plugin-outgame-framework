// Fill out your copyright notice in the Description page of Project Settings.


#include "LocalUIManagerSettings.h"

#include "Blueprint/UserWidget.h"

ULocalUIManagerSettings::ULocalUIManagerSettings()
{
    CategoryName = "Plugins";
    SectionName = "LocalUIManager";
}

TSubclassOf<UUserWidget> ULocalUIManagerSettings::GetDefaultAlertWidgetClass() const
{
    return DefaultAlertWidgetClass.LoadSynchronous();
}

TSubclassOf<UUserWidget> ULocalUIManagerSettings::GetDefaultConfirmWidgetClass() const
{
    return DefaultConfirmWidgetClass.LoadSynchronous();
}

TSubclassOf<UUserWidget> ULocalUIManagerSettings::GetDefaultPromptWidgetClass() const
{
    return DefaultPromptWidgetClass.LoadSynchronous();
}
