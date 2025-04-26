// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Graphic/FrameRateLimitSetting.h"

#include "Logging.h"
#include "GameFramework/GameUserSettings.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UFrameRateLimitSetting::UFrameRateLimitSetting()
{
    OptionName = LOCTEXT("FrameRateLimit", "Frame Rate Limit");

    MaxFrameRate = 240;
    FrameRateInterval = 30;
}

void UFrameRateLimitSetting::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    if (GameUserSettings)
    {
        SetCurrentOption(GetIndexByFrameRateLimit(GameUserSettings->GetFrameRateLimit()));
    }
}

void UFrameRateLimitSetting::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (IsDirty() && GameUserSettings)
    {
        GameUserSettings->SetFrameRateLimit(GetFrameRateLimitByIndex(GetSelectedOption()));
        SetCurrentOption(GetSelectedOption());

        LOG_S(Log)
    }
}

FText UFrameRateLimitSetting::GetSelectedOptionText_Implementation() const
{
    int32 FrameRateLimit = GetFrameRateLimitByIndex(GetSelectedOption());
    return FrameRateLimit == 0 ? LOCTEXT("Unlimited", "Unlimited") : FText::FromString(FString::FromInt(FrameRateLimit));
}

int32 UFrameRateLimitSetting::GetFrameRateLimitByIndex(int32 Index) const
{
    return Index == GetOptionNum() - 1 ? 0 : (Index + 1) * FrameRateInterval;
}

int32 UFrameRateLimitSetting::GetIndexByFrameRateLimit(int32 FrameRate) const
{
    return FrameRate == 0 ? GetOptionNum() - 1 : FrameRate / FrameRateInterval - 1;
}

#undef LOCTEXT_NAMESPACE
