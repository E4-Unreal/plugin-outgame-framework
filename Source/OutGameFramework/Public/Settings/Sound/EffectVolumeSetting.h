// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VolumeSettingBase.h"
#include "EffectVolumeSetting.generated.h"

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API UEffectVolumeSetting : public UVolumeSettingBase
{
    GENERATED_BODY()

public:
    UEffectVolumeSetting();

    /* GameUserSettingsConfig */

    virtual void Load_Implementation(UGameUserSettings* GameUserSettings) override;
    virtual void Apply_Implementation(UGameUserSettings* GameUserSettings) override;
};
