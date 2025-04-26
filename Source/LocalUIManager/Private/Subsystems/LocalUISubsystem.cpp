// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/LocalUISubsystem.h"

#include "LocalUIManagerSettings.h"
#include "Logging.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/Interface_ModalWidget.h"

void ULocalUISubsystem::ShowWidgetByClass(TSubclassOf<UUserWidget> WidgetClass)
{
    if (UUserWidget* Widget = GetOrCreateWidget(WidgetClass))
    {
        if (!Widget->IsInViewport()) Widget->AddToViewport();
    }
}

void ULocalUISubsystem::HideWidgetByClass(TSubclassOf<UUserWidget> WidgetClass)
{
    if (UUserWidget* Widget = GetOrCreateWidget(WidgetClass))
    {
        if (Widget->IsInViewport()) Widget->RemoveFromParent();
    }
}

void ULocalUISubsystem::RequestAlertModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass)
{
    WidgetClass = WidgetClass == nullptr ? ULocalUIManagerSettings::Get()->GetDefaultAlertWidgetClass() : WidgetClass;
    if (WidgetClass == nullptr) return;

    if (UUserWidget* ModalWidget = GetOrCreateModalWidget(WidgetClass))
    {
        IInterface_ModalWidget::Execute_Init(ModalWidget, InModalWidgetData);
        if (!ModalWidget->IsInViewport()) ModalWidget->AddToViewport();
    }
}

void ULocalUISubsystem::RequestConfirmModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass)
{
    WidgetClass = WidgetClass == nullptr ? ULocalUIManagerSettings::Get()->GetDefaultConfirmWidgetClass() : WidgetClass;
    if (WidgetClass == nullptr) return;

    if (UUserWidget* ModalWidget = GetOrCreateModalWidget(WidgetClass))
    {
        IInterface_ModalWidget::Execute_Init(ModalWidget, InModalWidgetData);
        if (!ModalWidget->IsInViewport()) ModalWidget->AddToViewport();
    }
}

void ULocalUISubsystem::RequestPromptModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass)
{
    WidgetClass = WidgetClass == nullptr ? ULocalUIManagerSettings::Get()->GetDefaultPromptWidgetClass() : WidgetClass;
    if (WidgetClass == nullptr) return;

    if (UUserWidget* ModalWidget = GetOrCreateModalWidget(WidgetClass))
    {
        IInterface_ModalWidget::Execute_Init(ModalWidget, InModalWidgetData);
        if (!ModalWidget->IsInViewport()) ModalWidget->AddToViewport();
    }
}

UUserWidget* ULocalUISubsystem::GetOrCreateModalWidget(TSubclassOf<UUserWidget> ModalWidgetClass)
{
    if (ModalWidgetClass == nullptr || !ModalWidgetClass->ImplementsInterface(UInterface_ModalWidget::StaticClass())) return nullptr;

    return GetOrCreateWidget(ModalWidgetClass);
}

UUserWidget* ULocalUISubsystem::CreateAndRegisterWidget(TSubclassOf<UUserWidget> WidgetClass)
{
    // 유효성 검사
    LOG_NULL(WidgetClass);
    if (WidgetClass == nullptr) return nullptr;

    // 위젯 생성
    if (APlayerController* LocalPlayerController = GetLocalPlayer()->GetPlayerController(GetWorld()))
    {
        UUserWidget* NewWidget = CreateWidget(LocalPlayerController, WidgetClass);
        Widgets.Emplace(NewWidget);

        return NewWidget;
    }

    return nullptr;
}

int32 ULocalUISubsystem::GetWidgetIndex(TSubclassOf<UUserWidget> WidgetClass)
{
    // 유효성 검사
    LOG_NULL(WidgetClass);
    if (WidgetClass == nullptr) return -1;

    // 등록된 위젯 찾기
    for (int Index = 0; Index < Widgets.Num(); ++Index)
    {
        UUserWidget* Widget = Widgets[Index];
        if (Widget->GetClass() == WidgetClass)
        {
            return Index;
        }
    }

    // 등록된 위젯에 존재하지 않는 경우
    return -1;
}

UUserWidget* ULocalUISubsystem::GetWidget(TSubclassOf<UUserWidget> WidgetClass)
{
    // 유효성 검사
    LOG_NULL(WidgetClass);
    if (WidgetClass == nullptr) return nullptr;

    // 등록된 위젯 찾기
    int32 Index = GetWidgetIndex(WidgetClass);

    return Index >= 0 ? Widgets[Index] : nullptr;
}

UUserWidget* ULocalUISubsystem::GetOrCreateWidget(TSubclassOf<UUserWidget> WidgetClass)
{
    // Get
    UUserWidget* Widget = GetWidget(WidgetClass);

    // Create
    if (Widget == nullptr) Widget = CreateAndRegisterWidget(WidgetClass);

    return Widget;
}

void ULocalUISubsystem::RemoveWidget(TSubclassOf<UUserWidget> WidgetClass)
{
    // 유효성 검사
    LOG_NULL(WidgetClass);
    if (WidgetClass == nullptr) return;

    // 위젯 제거
    int32 Index = GetWidgetIndex(WidgetClass);
    if (Index >= 0)
    {
        UUserWidget* Widget = Widgets[Index];
        if (Widget->IsInViewport()) Widget->RemoveFromParent();
        Widgets.RemoveAt(Index, EAllowShrinking::No);
    }
}

void ULocalUISubsystem::RemoveLastWidget()
{
    if (!Widgets.IsEmpty())
    {
        Widgets.RemoveAt(Widgets.Num() - 1);
    }
}
