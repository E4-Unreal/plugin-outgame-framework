// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Menu/Option/OptionWidgetBase.h"

#include "Logging.h"
#include "Settings/GameUserSettingsConfig.h"

void UOptionWidgetBase::SetGameUserSettingsConfig(UGameUserSettingsConfig* InGameUserSettingsConfig)
{
    if (GameUserSettingsConfig && GameUserSettingsConfig->SelectedOptionChanged.IsAlreadyBound(this, &ThisClass::OnSelectedOptionChanged))
    {
        GameUserSettingsConfig->SelectedOptionChanged.RemoveDynamic(this, &ThisClass::OnSelectedOptionChanged);
    }

    GameUserSettingsConfig = InGameUserSettingsConfig;

    if (GameUserSettingsConfig && !GameUserSettingsConfig->SelectedOptionChanged.IsAlreadyBound(this, &ThisClass::OnSelectedOptionChanged))
    {
        GameUserSettingsConfig->SelectedOptionChanged.AddDynamic(this, &ThisClass::OnSelectedOptionChanged);
    }
}

void UOptionWidgetBase::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    if (GameUserSettingsConfig)
    {
        GameUserSettingsConfig->Load(GameUserSettings);
    }
}

void UOptionWidgetBase::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (GameUserSettingsConfig)
    {
        GameUserSettingsConfig->Apply(GameUserSettings);
    }
}

bool UOptionWidgetBase::IsDirty() const
{
    return GameUserSettingsConfig ? GameUserSettingsConfig->IsDirty() : false;
}

void UOptionWidgetBase::OnSelectedOptionChanged()
{
    LOG_TODO
}
