// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/Interface_ModalWidget.h"
#include "LocalUIWidgetBase.generated.h"

class ULocalUISubsystem;

/**
 * Basic widget for using LocalUISubsystem
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class LOCALUIMANAGER_API ULocalUIWidgetBase : public UUserWidget
{
    GENERATED_BODY()

public:
    ULocalUIWidgetBase(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintPure)
    virtual ULocalUISubsystem* GetLocalUISubsystem() const;

    UFUNCTION(BlueprintCallable)
    virtual void ShowWidgetByClass(TSubclassOf<UUserWidget> WidgetClass);

    UFUNCTION(BlueprintCallable)
    virtual void HideWidgetByClass(TSubclassOf<UUserWidget> WidgetClass);

    UFUNCTION(BlueprintCallable)
    virtual void RequestAlertModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass = nullptr);

    UFUNCTION(BlueprintCallable)
    virtual void RequestConfirmModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass = nullptr);

    UFUNCTION(BlueprintCallable)
    virtual void RequestPromptModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass = nullptr);
};
