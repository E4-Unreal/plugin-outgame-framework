// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GraphicBoolSettingBase.h"
#include "VSyncSetting.generated.h"

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API UVSyncSetting : public UGraphicBoolSettingBase
{
    GENERATED_BODY()

public:
    UVSyncSetting();

    /* GameUserSettingsConfig */

    virtual void Load_Implementation(UGameUserSettings* GameUserSettings) override;
    virtual void Apply_Implementation(UGameUserSettings* GameUserSettings) override;
};
