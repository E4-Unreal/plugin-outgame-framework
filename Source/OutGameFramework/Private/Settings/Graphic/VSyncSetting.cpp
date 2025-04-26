// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Graphic/VSyncSetting.h"

#include "Logging.h"
#include "GameFramework/GameUserSettings.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UVSyncSetting::UVSyncSetting()
{
    OptionName = LOCTEXT("VSync", "VSync");
}

void UVSyncSetting::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    if (GameUserSettings)
    {
        SetCurrentOption(GetIndexByBool(GameUserSettings->IsVSyncEnabled()));
    }
}

void UVSyncSetting::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (IsDirty() && GameUserSettings)
    {
        GameUserSettings->SetVSyncEnabled(GetBoolByIndex(GetSelectedOption()));
        SetCurrentOption(GetSelectedOption());

        LOG_S(Log)
    }
}

#undef LOCTEXT_NAMESPACE
