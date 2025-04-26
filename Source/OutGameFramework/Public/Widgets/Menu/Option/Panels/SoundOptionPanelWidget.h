// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OptionPanelWidgetBase.h"
#include "SoundOptionPanelWidget.generated.h"

class USoundSettingsConfig;

/**
 *
 */
UCLASS(Abstract)
class OUTGAMEFRAMEWORK_API USoundOptionPanelWidget : public UOptionPanelWidgetBase
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config")
    TArray<TObjectPtr<USoundSettingsConfig>> SoundSettings;

public:
    /* OptionPanelWidgetBase */

    virtual TArray<UGameUserSettingsConfig*> GetGameUserSettingsConfigs() const override { return static_cast<TArray<UGameUserSettingsConfig*>>(SoundSettings); }
};
