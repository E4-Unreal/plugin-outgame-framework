// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OptionPanelWidgetBase.h"
#include "GraphicOptionPanelWidget.generated.h"

class UGraphicSettingsConfig;

/**
 *
 */
UCLASS(Abstract)
class OUTGAMEFRAMEWORK_API UGraphicOptionPanelWidget : public UOptionPanelWidgetBase
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config")
    TArray<TObjectPtr<UGraphicSettingsConfig>> GraphicSettings;

public:
    /* OptionPanelWidgetBase */

    virtual TArray<UGameUserSettingsConfig*> GetGameUserSettingsConfigs() const override { return static_cast<TArray<UGameUserSettingsConfig*>>(GraphicSettings); }
};
