// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "LocalUIManagerSettings.generated.h"

/**
 * Local UI Manager 플러그인 전용 데이터 클래스
 */
UCLASS(config = OutGameFramework, meta = (DisplayName = "Local UI Manager", ToolTip = "Settings for LocalUIManager Module in OutGameFramework Plugin"))
class LOCALUIMANAGER_API ULocalUIManagerSettings : public UDeveloperSettings
{
    GENERATED_BODY()

protected:
    UPROPERTY(Config, EditDefaultsOnly, Category = "Settings", meta = (MustImplement = "Interface_ModalWidget"))
    TSoftClassPtr<UUserWidget> DefaultAlertWidgetClass;

    UPROPERTY(Config, EditDefaultsOnly, Category = "Settings", meta = (MustImplement = "Interface_ModalWidget"))
    TSoftClassPtr<UUserWidget> DefaultConfirmWidgetClass;

    UPROPERTY(Config, EditDefaultsOnly, Category = "Settings", meta = (MustImplement = "Interface_ModalWidget"))
    TSoftClassPtr<UUserWidget> DefaultPromptWidgetClass;

public:
    ULocalUIManagerSettings();

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get LocalUIManagerSettings"))
    static ULocalUIManagerSettings* Get() { return GetMutableDefault<ULocalUIManagerSettings>(); }

    UFUNCTION(BlueprintPure)
    TSubclassOf<UUserWidget> GetDefaultAlertWidgetClass() const;

    UFUNCTION(BlueprintPure)
    TSubclassOf<UUserWidget> GetDefaultConfirmWidgetClass() const;

    UFUNCTION(BlueprintPure)
    TSubclassOf<UUserWidget> GetDefaultPromptWidgetClass() const;
};
