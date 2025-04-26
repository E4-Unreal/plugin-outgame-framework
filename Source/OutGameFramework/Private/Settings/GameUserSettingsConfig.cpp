// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/GameUserSettingsConfig.h"

#include "Logging.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

void UGameUserSettingsConfig::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    LOG_TODO
}

void UGameUserSettingsConfig::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    LOG_TODO
}

int32 UGameUserSettingsConfig::GetOptionNum_Implementation() const
{
    LOG_TODO

    return -1;
}

FText UGameUserSettingsConfig::GetSelectedOptionText_Implementation() const
{
    LOG_TODO

    return FText::GetEmpty();
}

void UGameUserSettingsConfig::SetCurrentOption(int32 InCurrentOption)
{
    CurrentOption = FMath::Clamp(InCurrentOption, 0, GetOptionNum() - 1);
    SetSelectedOption(CurrentOption);

    LOG(Log, TEXT("CurrentOption: %d"), CurrentOption)
}

void UGameUserSettingsConfig::SetSelectedOption(int32 InSelectedOption)
{
    int32 OldOption = SelectedOption;
    int32 NewOption = FMath::Clamp(InSelectedOption, 0, GetOptionNum() - 1);

    if (OldOption != NewOption)
    {
        SelectedOption = NewOption;
        SelectedOptionChanged.Broadcast();

        LOG(Log, TEXT("SelectedOption: %d"), SelectedOption)
    }
}

#undef LOCTEXT_NAMESPACE
