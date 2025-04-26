// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Sound/AmbientVolumeSetting.h"

#include "Logging.h"
#include "OutGameUserSettings.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UAmbientVolumeSetting::UAmbientVolumeSetting()
{
    OptionName = LOCTEXT("AmbientVolume", "Ambient Volume");
}

void UAmbientVolumeSetting::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    if (auto OutGameUserSettings = Cast<UOutGameUserSettings>(GameUserSettings))
    {
        SetCurrentOption(GetIndexByVolume(OutGameUserSettings->GetAmbientSoundVolume()));
    }
}

void UAmbientVolumeSetting::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (IsDirty())
    {
        if (auto OutGameUserSettings = Cast<UOutGameUserSettings>(GameUserSettings))
        {
            OutGameUserSettings->SetAmbientSoundVolume(GetVolumeByIndex(GetSelectedOption()));
            SetCurrentOption(GetSelectedOption());

            LOG_S(Log)
        }
    }
}

#undef LOCTEXT_NAMESPACE
