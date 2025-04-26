// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Graphic/ShadowQualitySetting.h"

#include "Logging.h"
#include "GameFramework/GameUserSettings.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UShadowQualitySetting::UShadowQualitySetting()
{
    OptionName = LOCTEXT("ShadowQuality", "Shadow Quality");
}

void UShadowQualitySetting::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    if (GameUserSettings)
    {
        SetCurrentOption(GameUserSettings->GetShadowQuality());
    }
}

void UShadowQualitySetting::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (IsDirty() && GameUserSettings)
    {
        GameUserSettings->SetShadowQuality(GetSelectedOption());
        SetCurrentOption(GetSelectedOption());

        LOG_S(Log)
    }
}

#undef LOCTEXT_NAMESPACE
