// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LocalUIPlayerControllerBase.generated.h"

class ULocalUISubsystem;
struct FModalWidgetData;

/**
 * Basic PlayerController For Using LocalUISubsystem
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class LOCALUIMANAGER_API ALocalUIPlayerControllerBase : public APlayerController
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config")
    TArray<TSubclassOf<UUserWidget>> PlayerWidgetClasses;

protected:
    /* Actor */

    virtual void BeginPlay() override;

    /* LocalUIPlayerControllerBase */

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
