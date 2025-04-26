// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/LocalUIWidgetBase.h"
#include "OptionMenuWidgetBase.generated.h"

class UOptionPanelWidgetBase;
class UWidgetSwitcher;
class UButton;

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API UOptionMenuWidgetBase : public ULocalUIWidgetBase
{
    GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    TObjectPtr<UWidgetSwitcher> OptionPanelSwitcher;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UButton> ApplyButton;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UButton> ConfirmButton;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FModalWidgetData RequestConfirmData;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FModalWidgetData RequestApplyData;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TArray<TSubclassOf<UOptionPanelWidgetBase>> OptionPanelClasses;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    TArray<TObjectPtr<UOptionPanelWidgetBase>> OptionPanels;

public:
    UOptionMenuWidgetBase(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure, BlueprintNativeEvent)
    UButton* GetApplyButton() const;

    UFUNCTION(BlueprintPure, BlueprintNativeEvent)
    UButton* GetConfirmButton() const;

protected:
    virtual void NativeOnInitialized() override;
    virtual void NativePreConstruct() override;

    UFUNCTION(BlueprintPure)
    bool IsDirty() const;

    UFUNCTION(BlueprintCallable)
    virtual void Apply();

    UFUNCTION(BlueprintCallable)
    virtual void Confirm();

    UFUNCTION(BlueprintCallable)
    virtual void OnApplyButtonClicked();

    UFUNCTION(BlueprintCallable)
    virtual void OnConfirmButtonClicked();
};
