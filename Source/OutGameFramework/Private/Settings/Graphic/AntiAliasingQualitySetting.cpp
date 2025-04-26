// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Graphic/AntiAliasingQualitySetting.h"

#include "Logging.h"
#include "GameFramework/GameUserSettings.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UAntiAliasingQualitySetting::UAntiAliasingQualitySetting()
{
    OptionName = LOCTEXT("AntiAliasingQuality", "Anti Aliasing Quality");
}

void UAntiAliasingQualitySetting::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    if (GameUserSettings)
    {
        SetCurrentOption(GameUserSettings->GetAntiAliasingQuality());
    }
}

void UAntiAliasingQualitySetting::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (IsDirty() && GameUserSettings)
    {
        GameUserSettings->SetAntiAliasingQuality(GetSelectedOption());
        SetCurrentOption(GetSelectedOption());

        LOG_S(Log)
    }
}

#undef LOCTEXT_NAMESPACE
