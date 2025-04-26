// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Sound/UIVolumeSetting.h"

#include "Logging.h"
#include "OutGameUserSettings.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UUIVolumeSetting::UUIVolumeSetting()
{
    OptionName = LOCTEXT("UIVolume", "UI Volume");
}

void UUIVolumeSetting::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    if (auto OutGameUserSettings = Cast<UOutGameUserSettings>(GameUserSettings))
    {
        SetCurrentOption(GetIndexByVolume(OutGameUserSettings->GetUISoundVolume()));
    }
}

void UUIVolumeSetting::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (IsDirty())
    {
        if (auto OutGameUserSettings = Cast<UOutGameUserSettings>(GameUserSettings))
        {
            OutGameUserSettings->SetUISoundVolume(GetVolumeByIndex(GetSelectedOption()));
            SetCurrentOption(GetSelectedOption());

            LOG_S(Log)
        }
    }
}

#undef LOCTEXT_NAMESPACE
