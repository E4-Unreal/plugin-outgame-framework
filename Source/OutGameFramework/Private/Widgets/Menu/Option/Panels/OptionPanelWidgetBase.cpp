// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Menu/Option/Panels/OptionPanelWidgetBase.h"

#include "Logging.h"
#include "Blueprint/WidgetTree.h"
#include "Components/UniformGridPanel.h"
#include "GameFramework/GameUserSettings.h"
#include "Widgets/Menu/Option/ButtonOptionWidgetBase.h"
#include "Settings/GameUserSettingsConfig.h"

void UOptionPanelWidgetBase::NativePreConstruct()
{
    Super::NativePreConstruct();

    if (OptionSlotWidgets.IsEmpty() && OptionPanel)
    {
        auto Settings = GetGameUserSettingsConfigs();
        for (int32 Index = 0; Index < Settings.Num(); ++Index)
        {
            if (OptionSlotWidgetClass)
            {
                auto OptionSlotWidget = CreateWidget<UOptionWidgetBase>(this, OptionSlotWidgetClass);
                OptionSlotWidget->SetGameUserSettingsConfig(Settings[Index]);
                OptionSlotWidgets.Emplace(OptionSlotWidget);
                OptionPanel->AddChildToUniformGrid(OptionSlotWidget, Index);
            }
        }
    }

    Load();
}

void UOptionPanelWidgetBase::Load()
{
    if (GEngine && GEngine->GetGameUserSettings())
    {
        auto GameUserSettings = GEngine->GetGameUserSettings();
        GameUserSettings->LoadSettings();
        for (auto GameUserSettingsConfig : GetGameUserSettingsConfigs())
        {
            if (GameUserSettingsConfig) GameUserSettingsConfig->Load(GameUserSettings);
        }
    }
}

void UOptionPanelWidgetBase::Apply()
{
    if (GEngine && GEngine->GetGameUserSettings())
    {
        auto GameUserSettings = GEngine->GetGameUserSettings();
        GameUserSettings->LoadSettings();
        for (auto GameUserSettingsConfig : GetGameUserSettingsConfigs())
        {
            if (GameUserSettingsConfig) GameUserSettingsConfig->Apply(GameUserSettings);
        }
        GameUserSettings->ApplySettings(false);
    }
}

bool UOptionPanelWidgetBase::IsDirty() const
{
    for (auto GameUserSettingsConfig : GetGameUserSettingsConfigs())
    {
        if (GameUserSettingsConfig && GameUserSettingsConfig->IsDirty()) return true;
    }

    return false;
}

TArray<UGameUserSettingsConfig*> UOptionPanelWidgetBase::GetGameUserSettingsConfigs() const
{
    LOG_TODO

    return TArray<UGameUserSettingsConfig*>();
}
