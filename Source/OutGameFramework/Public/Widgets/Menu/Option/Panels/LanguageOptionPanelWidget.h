// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OptionPanelWidgetBase.h"
#include "LanguageOptionPanelWidget.generated.h"

class ULanguageSettingsConfig;

/**
 *
 */
UCLASS(Abstract)
class OUTGAMEFRAMEWORK_API ULanguageOptionPanelWidget : public UOptionPanelWidgetBase
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config")
    TArray<TObjectPtr<ULanguageSettingsConfig>> LanguageSettings;

public:
    /* OptionPanelWidgetBase */

    virtual TArray<UGameUserSettingsConfig*> GetGameUserSettingsConfigs() const override { return static_cast<TArray<UGameUserSettingsConfig*>>(LanguageSettings); }
};
