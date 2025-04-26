// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Menu/Option/ButtonOptionWidgetBase.h"

#include "Logging.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Settings/GameUserSettingsConfig.h"

UTextBlock* UButtonOptionWidgetBase::GetOptionNameText_Implementation() const
{
    if (OptionNameText == nullptr) LOG_TODO

    return OptionNameText;
}

UTextBlock* UButtonOptionWidgetBase::GetOptionText_Implementation() const
{
    if (OptionText == nullptr) LOG_TODO

    return OptionText;
}

UButton* UButtonOptionWidgetBase::GetPreviousButton_Implementation() const
{
    if (PreviousButton == nullptr) LOG_TODO

    return PreviousButton;
}

UButton* UButtonOptionWidgetBase::GetNextButton_Implementation() const
{
    if (NextButton == nullptr) LOG_TODO

    return NextButton;
}

void UButtonOptionWidgetBase::OnSelectedOptionChanged()
{
    RefreshOptionText();
}

void UButtonOptionWidgetBase::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (GameUserSettingsConfig)
    {
        GameUserSettingsConfig->SelectedOptionChanged.AddDynamic(this, &ThisClass::RefreshOptionText);
    }

    if (UButton* LocalPreviousButton = GetPreviousButton())
    {
        LocalPreviousButton->OnClicked.AddDynamic(this, &ThisClass::OnPreviousButtonClicked);
    }

    if (UButton* LocalNextButton = GetNextButton())
    {
        LocalNextButton->OnClicked.AddDynamic(this, &ThisClass::OnNextButtonClicked);
    }
}

void UButtonOptionWidgetBase::NativePreConstruct()
{
    Super::NativePreConstruct();

    RefreshAll();
}

void UButtonOptionWidgetBase::RefreshAll()
{
    RefreshOptionNameText();
    RefreshOptionText();
}

void UButtonOptionWidgetBase::RefreshOptionNameText()
{
    if (GameUserSettingsConfig)
    {
        SetDisplayText(GetOptionNameText(), GameUserSettingsConfig->GetOptionName());
    }
}

void UButtonOptionWidgetBase::RefreshOptionText()
{
    if (GameUserSettingsConfig)
    {
        SetDisplayText(GetOptionText(), GameUserSettingsConfig->GetSelectedOptionText());
    }
}

void UButtonOptionWidgetBase::OnPreviousButtonClicked()
{
    if (GameUserSettingsConfig)
    {
        GameUserSettingsConfig->SetSelectedOption(GameUserSettingsConfig->GetSelectedOption() - 1);
    }
}

void UButtonOptionWidgetBase::OnNextButtonClicked()
{
    if (GameUserSettingsConfig)
    {
        GameUserSettingsConfig->SetSelectedOption(GameUserSettingsConfig->GetSelectedOption() + 1);
    }
}

void UButtonOptionWidgetBase::SetDisplayText(UTextBlock* Target, FText DisplayText)
{
    if (Target && !Target->GetText().EqualTo(DisplayText))
    {
        Target->SetText(DisplayText);
    }
}
