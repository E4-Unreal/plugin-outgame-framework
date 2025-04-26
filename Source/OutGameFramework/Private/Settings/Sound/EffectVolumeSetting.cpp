// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Sound/EffectVolumeSetting.h"

#include "Logging.h"
#include "OutGameUserSettings.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UEffectVolumeSetting::UEffectVolumeSetting()
{
    OptionName = LOCTEXT("EffectVolume", "Effect Volume");
}

void UEffectVolumeSetting::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    if (auto OutGameUserSettings = Cast<UOutGameUserSettings>(GameUserSettings))
    {
        SetCurrentOption(GetIndexByVolume(OutGameUserSettings->GetEffectSoundVolume()));
    }
}

void UEffectVolumeSetting::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (IsDirty())
    {
        if (auto OutGameUserSettings = Cast<UOutGameUserSettings>(GameUserSettings))
        {
            OutGameUserSettings->SetEffectSoundVolume(GetVolumeByIndex(GetSelectedOption()));
            SetCurrentOption(GetSelectedOption());

            LOG_S(Log)
        }
    }
}

#undef LOCTEXT_NAMESPACE
