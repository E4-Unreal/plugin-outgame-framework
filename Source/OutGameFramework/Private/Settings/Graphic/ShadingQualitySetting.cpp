// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Graphic/ShadingQualitySetting.h"

#include "Logging.h"
#include "GameFramework/GameUserSettings.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UShadingQualitySetting::UShadingQualitySetting()
{
    OptionName = LOCTEXT("ShadingQuality", "Shading Quality");
}

void UShadingQualitySetting::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    if (GameUserSettings)
    {
        SetCurrentOption(GameUserSettings->GetShadingQuality());
    }
}

void UShadingQualitySetting::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (IsDirty() && GameUserSettings)
    {
        GameUserSettings->SetShadingQuality(GetSelectedOption());
        SetCurrentOption(GetSelectedOption());

        LOG_S(Log)
    }
}

#undef LOCTEXT_NAMESPACE
