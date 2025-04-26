// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GraphicSettingsConfig.h"
#include "WindowModeSetting.generated.h"

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API UWindowModeSetting : public UGraphicSettingsConfig
{
    GENERATED_BODY()

public:
    UWindowModeSetting();

    /* GameUserSettingsConfig */

    virtual void Load_Implementation(UGameUserSettings* GameUserSettings) override;
    virtual void Apply_Implementation(UGameUserSettings* GameUserSettings) override;
    virtual FText GetSelectedOptionText_Implementation() const override;
    virtual int32 GetOptionNum_Implementation() const override { return 3; }

    /* WindowModeSetting */

    static EWindowMode::Type GetWindowModeByIndex(int32 Index);
    static int32 GetIndexByWindowMode(EWindowMode::Type WindowMode);
};
