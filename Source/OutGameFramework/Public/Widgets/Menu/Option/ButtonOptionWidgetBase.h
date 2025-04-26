// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OptionWidgetBase.h"
#include "ButtonOptionWidgetBase.generated.h"

class UGameUserSettingsConfig;
class UTextBlock;
class UButton;

/**
 * 2개의 버튼을 통해 옵션을 설정하는 방식의 OptionBox
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class OUTGAMEFRAMEWORK_API UButtonOptionWidgetBase : public UOptionWidgetBase
{
    GENERATED_BODY()

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> OptionNameText;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> OptionText;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UButton> PreviousButton;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UButton> NextButton;

public:
    /* OptionWidgetBase */

    virtual void OnSelectedOptionChanged() override;

    /* ButtonOptionBoxBase */

    UFUNCTION(BlueprintPure, BlueprintNativeEvent)
    UTextBlock* GetOptionNameText() const;

    UFUNCTION(BlueprintPure, BlueprintNativeEvent)
    UTextBlock* GetOptionText() const;

    UFUNCTION(BlueprintPure, BlueprintNativeEvent)
    UButton* GetPreviousButton() const;

    UFUNCTION(BlueprintPure, BlueprintNativeEvent)
    UButton* GetNextButton() const;

protected:
    /* UserWidget */

    virtual void NativeOnInitialized() override;
    virtual void NativePreConstruct() override;

    /* ButtonOptionBoxBase */

    UFUNCTION(BlueprintCallable)
    virtual void RefreshAll();

    UFUNCTION(BlueprintCallable)
    virtual void RefreshOptionNameText();

    UFUNCTION(BlueprintCallable)
    virtual void RefreshOptionText();

    UFUNCTION(BlueprintCallable)
    virtual void OnPreviousButtonClicked();

    UFUNCTION(BlueprintCallable)
    virtual void OnNextButtonClicked();

    UFUNCTION(BlueprintCallable)
    void SetDisplayText(UTextBlock* Target, FText DisplayText);
};
