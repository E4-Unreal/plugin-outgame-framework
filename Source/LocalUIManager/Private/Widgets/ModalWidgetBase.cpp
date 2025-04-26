// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ModalWidgetBase.h"

#include "Logging.h"

void UModalWidgetBase::Init_Implementation(const FModalWidgetData& InModalWidgetData)
{
    ModalWidgetData = InModalWidgetData;

    LOG(Log, TEXT("Title: %s, Message: %s"), *InModalWidgetData.Title.ToString(), *InModalWidgetData.Message.ToString())
}

const FText& UModalWidgetBase::GetInputText() const
{
    return FText::GetEmpty();
}

void UModalWidgetBase::OnConfirmButtonClicked()
{
    const FText& InputText = GetInputText();
    if (ModalWidgetData.InputTextDelegate.ExecuteIfBound(InputText)) LOG(Log, TEXT("InputTextDelegate is executed: %s"), *InputText.ToString());
    if (ModalWidgetData.ConfirmDelegate.ExecuteIfBound()) LOG(Log, TEXT("ConfirmDelegate is executed"));

    RemoveFromParent();
}

void UModalWidgetBase::OnCancelButtonClicked()
{
    if (ModalWidgetData.CancelDelegate.ExecuteIfBound()) LOG(Log, TEXT("CancelDelegate is executed"));

    RemoveFromParent();
}
