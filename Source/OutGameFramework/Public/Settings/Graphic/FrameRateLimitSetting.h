// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GraphicSettingsConfig.h"
#include "FrameRateLimitSetting.generated.h"

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API UFrameRateLimitSetting : public UGraphicSettingsConfig
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxFrameRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 FrameRateInterval;

public:
    UFrameRateLimitSetting();

    /* GameUserSettingsConfig */

    virtual void Load_Implementation(UGameUserSettings* GameUserSettings) override;
    virtual void Apply_Implementation(UGameUserSettings* GameUserSettings) override;
    virtual FText GetSelectedOptionText_Implementation() const override;
    virtual int32 GetOptionNum_Implementation() const override { return MaxFrameRate / FrameRateInterval + 1; }

    /* FrameRateLimitSetting */

    int32 GetFrameRateLimitByIndex(int32 Index) const;
    int32 GetIndexByFrameRateLimit(int32 FrameRate) const;
};
