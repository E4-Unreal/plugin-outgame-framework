// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Graphic/TextureQualitySetting.h"

#include "Logging.h"
#include "GameFramework/GameUserSettings.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UTextureQualitySetting::UTextureQualitySetting()
{
    OptionName = LOCTEXT("TextureQuality", "Texture Quality");
}

void UTextureQualitySetting::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    if (GameUserSettings)
    {
        SetCurrentOption(GameUserSettings->GetTextureQuality());
    }
}

void UTextureQualitySetting::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (IsDirty() && GameUserSettings)
    {
        GameUserSettings->SetTextureQuality(GetSelectedOption());
        SetCurrentOption(GetSelectedOption());

        LOG_S(Log)
    }
}

#undef LOCTEXT_NAMESPACE
