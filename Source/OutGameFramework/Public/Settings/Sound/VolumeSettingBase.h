// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SoundSettingsConfig.h"
#include "VolumeSettingBase.generated.h"

/**
 *
 */
UCLASS(Abstract)
class OUTGAMEFRAMEWORK_API UVolumeSettingBase : public USoundSettingsConfig
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config", meta = (ClampMin = 1, ClampMax = 100))
    int32 MaxVolume;

public:
    UVolumeSettingBase();

    /* GameUserSettingsConfig */

    virtual FText GetSelectedOptionText_Implementation() const override;
    virtual int32 GetOptionNum_Implementation() const override { return MaxVolume + 1; }

    /* VolumeSettingBase */

    float GetVolumeByIndex(int32 Index) const;
    int32 GetIndexByVolume(float Volume) const;
};
