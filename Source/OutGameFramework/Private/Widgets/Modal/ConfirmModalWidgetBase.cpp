// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Modal/ConfirmModalWidgetBase.h"

#include "Components/TextBlock.h"
#include "Widgets/TextButtonWidgetBase.h"

void UConfirmModalWidgetBase::Init_Implementation(const FModalWidgetData& InModalWidgetData)
{
    Super::Init_Implementation(InModalWidgetData);

    if (TitleText) TitleText->SetText(InModalWidgetData.Title);
    if (MessageText) MessageText->SetText(InModalWidgetData.Message);
}

void UConfirmModalWidgetBase::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (ConfirmButton) ConfirmButton->OnClicked.AddDynamic(this, &ThisClass::OnConfirmButtonClicked);
    if (CancelButton) CancelButton->OnClicked.AddDynamic(this, &ThisClass::OnCancelButtonClicked);
}
