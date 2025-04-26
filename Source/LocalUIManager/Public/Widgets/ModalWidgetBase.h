// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/Interface_ModalWidget.h"
#include "ModalWidgetBase.generated.h"

/**
 * Alert, Confirm, Prompt 용도로 사용하기 위한 기본 ModalWidget 클래스
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class LOCALUIMANAGER_API UModalWidgetBase : public UUserWidget, public IInterface_ModalWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadonly, Transient)
    FModalWidgetData ModalWidgetData;

public:
    /* Interface_ModalWidget */

    virtual void Init_Implementation(const FModalWidgetData& InModalWidgetData) override;

protected:
    UFUNCTION(BlueprintPure)
    virtual const FText& GetInputText() const;

    UFUNCTION(BlueprintCallable)
    virtual void OnConfirmButtonClicked();

    UFUNCTION(BlueprintCallable)
    virtual void OnCancelButtonClicked();
};
