// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Menu/Option/OptionMenuWidgetBase.h"

#include "Logging.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Widgets/Menu/Option/Panels/OptionPanelWidgetBase.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UOptionMenuWidgetBase::UOptionMenuWidgetBase(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    RequestApplyData.Title = LOCTEXT("ApplySettingsTitle", "Apply Settings");
    RequestApplyData.Message = LOCTEXT("ApplySettingsMessage", "Are you sure you want to apply the changes?");
    RequestApplyData.ConfirmDelegate.BindDynamic(this, &ThisClass::Apply);

    RequestConfirmData.Title = LOCTEXT("ConfirmSettingsTitle", "Confirm Settings");
    RequestConfirmData.Message = LOCTEXT("ConfirmSettingsMessage", "Settings have been changed. Would you like to apply these changes?");
    RequestConfirmData.ConfirmDelegate.BindDynamic(this, &ThisClass::Confirm);
    RequestConfirmData.CancelDelegate.BindDynamic(this, &ThisClass::RemoveFromParent);
}

UButton* UOptionMenuWidgetBase::GetApplyButton_Implementation() const
{
    if (ApplyButton == nullptr) LOG_TODO

    return ApplyButton;
}

UButton* UOptionMenuWidgetBase::GetConfirmButton_Implementation() const
{
    if (ConfirmButton == nullptr) LOG_TODO

    return ConfirmButton;
}

void UOptionMenuWidgetBase::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (GetApplyButton())
    {
        GetApplyButton()->OnClicked.AddDynamic(this, &ThisClass::OnApplyButtonClicked);
    }

    if (GetConfirmButton())
    {
        GetConfirmButton()->OnClicked.AddDynamic(this, &ThisClass::OnConfirmButtonClicked);
    }
}

void UOptionMenuWidgetBase::NativePreConstruct()
{
    Super::NativePreConstruct();

    if (OptionPanels.IsEmpty() && OptionPanelSwitcher)
    {
        for (auto OptionPanelClass : OptionPanelClasses)
        {
            if (OptionPanelClass)
            {
                auto OptionPanel = CreateWidget<UOptionPanelWidgetBase>(this, OptionPanelClass);
                OptionPanels.Emplace(OptionPanel);
                OptionPanelSwitcher->AddChild(OptionPanel);
            }
        }
    }
}

bool UOptionMenuWidgetBase::IsDirty() const
{
    for (auto OptionPanel : OptionPanels)
    {
        if (OptionPanel && OptionPanel->IsDirty()) return true;
    }

    return false;
}

void UOptionMenuWidgetBase::Apply()
{
    for (auto OptionPanel : OptionPanels)
    {
        if (OptionPanel) OptionPanel->Apply();
    }
}

void UOptionMenuWidgetBase::Confirm()
{
    Apply();
    RemoveFromParent();
}

void UOptionMenuWidgetBase::OnApplyButtonClicked()
{
    RequestConfirmModal(RequestApplyData);
}

void UOptionMenuWidgetBase::OnConfirmButtonClicked()
{
    if(IsDirty())
    {
        RequestConfirmModal(RequestConfirmData);
    }
    else
    {
        RemoveFromParent();
    }
}

#undef LOCTEXT_NAMESPACE
