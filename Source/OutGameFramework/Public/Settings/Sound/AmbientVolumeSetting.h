// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VolumeSettingBase.h"
#include "AmbientVolumeSetting.generated.h"

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API UAmbientVolumeSetting : public UVolumeSettingBase
{
    GENERATED_BODY()

public:
    UAmbientVolumeSetting();

    /* GameUserSettingsConfig */

    virtual void Load_Implementation(UGameUserSettings* GameUserSettings) override;
    virtual void Apply_Implementation(UGameUserSettings* GameUserSettings) override;
};
