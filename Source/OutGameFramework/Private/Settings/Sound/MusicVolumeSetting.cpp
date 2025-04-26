// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Sound/MusicVolumeSetting.h"

#include "Logging.h"
#include "OutGameUserSettings.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UMusicVolumeSetting::UMusicVolumeSetting()
{
    OptionName = LOCTEXT("MusicVolume", "Music Volume");
}

void UMusicVolumeSetting::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    if (auto OutGameUserSettings = Cast<UOutGameUserSettings>(GameUserSettings))
    {
        SetCurrentOption(GetIndexByVolume(OutGameUserSettings->GetMusicSoundVolume()));
    }
}

void UMusicVolumeSetting::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (IsDirty())
    {
        if (auto OutGameUserSettings = Cast<UOutGameUserSettings>(GameUserSettings))
        {
            OutGameUserSettings->SetMusicSoundVolume(GetVolumeByIndex(GetSelectedOption()));
            SetCurrentOption(GetSelectedOption());

            LOG_S(Log)
        }
    }
}

#undef LOCTEXT_NAMESPACE
