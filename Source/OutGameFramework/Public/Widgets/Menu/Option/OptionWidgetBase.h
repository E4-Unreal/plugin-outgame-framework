// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OptionWidgetBase.generated.h"

class UGameUserSettingsConfig;

/**
 *
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class OUTGAMEFRAMEWORK_API UOptionWidgetBase : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    TObjectPtr<UGameUserSettingsConfig> GameUserSettingsConfig;

public:
    /* OptionWidgetBase */

    UFUNCTION(BlueprintCallable)
    virtual void SetGameUserSettingsConfig(UGameUserSettingsConfig* InGameUserSettingsConfig);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Load(UGameUserSettings* GameUserSettings);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Apply(UGameUserSettings* GameUserSettings);

    UFUNCTION(BlueprintPure)
    bool IsDirty() const;

protected:
    /* OptionWidgetBase */

    UFUNCTION(BlueprintCallable)
    virtual void OnSelectedOptionChanged();
};
