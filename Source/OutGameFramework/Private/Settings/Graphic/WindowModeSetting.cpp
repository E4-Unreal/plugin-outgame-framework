// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Graphic/WindowModeSetting.h"

#include "Logging.h"
#include "GameFramework/GameUserSettings.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UWindowModeSetting::UWindowModeSetting()
{
    OptionName = LOCTEXT("WindowMode", "Window Mode");
}

void UWindowModeSetting::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    if (GameUserSettings)
    {
        SetCurrentOption(GetIndexByWindowMode(GameUserSettings->GetFullscreenMode()));
    }
}

void UWindowModeSetting::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (IsDirty() && GameUserSettings)
    {
        GameUserSettings->SetFullscreenMode(GetWindowModeByIndex(GetSelectedOption()));
        SetCurrentOption(GetSelectedOption());

        LOG_S(Log)
    }
}

FText UWindowModeSetting::GetSelectedOptionText_Implementation() const
{
    auto SelectedWindowMode = GetWindowModeByIndex(GetSelectedOption());

    FText DisplayText;
    switch (SelectedWindowMode)
    {
    case EWindowMode::Fullscreen:
        DisplayText = LOCTEXT("Fullscreen", "Fullscreen");
        break;
    case EWindowMode::WindowedFullscreen:
        DisplayText = LOCTEXT("WindowedFullscreen", "WindowedFullscreen");
        break;
    case EWindowMode::Windowed:
        DisplayText = LOCTEXT("Windowed", "Windowed");
        break;
    default:
        DisplayText = LOCTEXT("Error", "Error");
        break;
    }

    return DisplayText;
}

EWindowMode::Type UWindowModeSetting::GetWindowModeByIndex(int32 Index)
{
    return static_cast<EWindowMode::Type>(FMath::Clamp(Index, 0, EWindowMode::Type::NumWindowModes - 1));
}

int32 UWindowModeSetting::GetIndexByWindowMode(EWindowMode::Type WindowMode)
{
    return WindowMode;
}

#undef LOCTEXT_NAMESPACE
