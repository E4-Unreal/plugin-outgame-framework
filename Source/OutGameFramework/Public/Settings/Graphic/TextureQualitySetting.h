// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QualitySettingBase.h"
#include "TextureQualitySetting.generated.h"

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API UTextureQualitySetting : public UQualitySettingBase
{
    GENERATED_BODY()

public:
    UTextureQualitySetting();

    /* GameUserSettingsConfig */

    virtual void Load_Implementation(UGameUserSettings* GameUserSettings) override;
    virtual void Apply_Implementation(UGameUserSettings* GameUserSettings) override;
};
