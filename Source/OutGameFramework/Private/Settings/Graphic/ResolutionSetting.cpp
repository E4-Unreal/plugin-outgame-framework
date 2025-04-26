// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Graphic/ResolutionSetting.h"

#include "Logging.h"
#include "GameFramework/GameUserSettings.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UResolutionSetting::UResolutionSetting()
{
    OptionName = LOCTEXT("Resolution", "Resolution");

    Resolutions.Reserve(4);
    Resolutions.Emplace(FIntPoint(720, 480)); // SD
    Resolutions.Emplace(FIntPoint(1280, 720)); // HD
    Resolutions.Emplace(FIntPoint(1920, 1080)); // FHD
    Resolutions.Emplace(FIntPoint(2560, 1440)); // QHD
}

void UResolutionSetting::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    if (GameUserSettings)
    {
        SetCurrentOption(GetIndexByResolution(GameUserSettings->GetScreenResolution()));
    }
}

void UResolutionSetting::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (IsDirty() && GameUserSettings)
    {
        GameUserSettings->SetScreenResolution(GetResolutionByIndex(GetSelectedOption()));
        SetCurrentOption(GetSelectedOption());

        LOG_S(Log)
    }
}

FText UResolutionSetting::GetSelectedOptionText_Implementation() const
{
    const FIntPoint& Resolution = GetResolutionByIndex(GetSelectedOption());
    FString ResolutionString = FString::FromInt(Resolution.X) + "x" + FString::FromInt(Resolution.Y);

    return FText::FromString(ResolutionString);
}

const FIntPoint& UResolutionSetting::GetResolutionByIndex(int32 Index) const
{
    return Resolutions.Num() > Index ? Resolutions[Index] : FIntPoint::ZeroValue;
}

int32 UResolutionSetting::GetIndexByResolution(const FIntPoint& Resolution) const
{
    return Resolutions.Find(Resolution);
}

#undef LOCTEXT_NAMESPACE
