// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/LocalUIWidgetBase.h"
#include "OptionPanelWidgetBase.generated.h"

class UUniformGridPanel;
class UButton;
class UGameUserSettingsConfig;
class UOptionWidgetBase;

/**
 *
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class OUTGAMEFRAMEWORK_API UOptionPanelWidgetBase : public ULocalUIWidgetBase
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UUniformGridPanel> OptionPanel;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config")
    TSubclassOf<UOptionWidgetBase> OptionSlotWidgetClass;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category = "State")
    TArray<TObjectPtr<UOptionWidgetBase>> OptionSlotWidgets;

protected:
    /* UserWidget */

    virtual void NativePreConstruct() override;

public:
    /* OptionMenuWidgetBase */

    UFUNCTION(BlueprintCallable)
    virtual void Load();

    UFUNCTION(BlueprintCallable)
    virtual void Apply();

    UFUNCTION(BlueprintPure)
    virtual bool IsDirty() const;

protected:
    /* OptionMenuWidgetBase */

    UFUNCTION(BlueprintPure)
    virtual TArray<UGameUserSettingsConfig*> GetGameUserSettingsConfigs() const;
};
