// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "OutGameFrameworkSettings.generated.h"

/**
 * OutGame Framework 플러그인 전용 데이터 클래스
 */
UCLASS(config = OutGameFramework, meta = (DisplayName = "OutGame Framework", ToolTip = "Settings for OutGame Framework Plugin"))
class OUTGAMEFRAMEWORK_API UOutGameFrameworkSettings : public UDeveloperSettings
{
    GENERATED_BODY()

protected:
    UPROPERTY(Config, EditDefaultsOnly, Category = "Settings")
    TSoftObjectPtr<USoundMix> SoundMix;

    UPROPERTY(Config, EditDefaultsOnly, Category = "Settings")
    TSoftObjectPtr<USoundClass> MusicSoundClass;

    UPROPERTY(Config, EditDefaultsOnly, Category = "Settings")
    TSoftObjectPtr<USoundClass> AmbientSoundClass;

    UPROPERTY(Config, EditDefaultsOnly, Category = "Settings")
    TSoftObjectPtr<USoundClass> UISoundClass;

    UPROPERTY(Config, EditDefaultsOnly, Category = "Settings")
    TSoftObjectPtr<USoundClass> EffectSoundClass;

public:
    UOutGameFrameworkSettings();

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get OutGameFrameworkSettings"))
    static UOutGameFrameworkSettings* Get() { return GetMutableDefault<UOutGameFrameworkSettings>(); }

    UFUNCTION(BlueprintPure)
    USoundMix* GetSoundMix() const;

    UFUNCTION(BlueprintPure)
    USoundClass* GetMusicSoundClass() const;

    UFUNCTION(BlueprintPure)
    USoundClass* GetAmbientSoundClass() const;

    UFUNCTION(BlueprintPure)
    USoundClass* GetUISoundClass() const;

    UFUNCTION(BlueprintPure)
    USoundClass* GetEffectSoundClass() const;
};
