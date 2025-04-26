// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "OutGameUserSettings.generated.h"

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API UOutGameUserSettings : public UGameUserSettings
{
    GENERATED_BODY()

protected:
    UPROPERTY(config)
    float MusicSoundVolume;

    UPROPERTY(config)
    float AmbientSoundVolume;

    UPROPERTY(config)
    float UISoundVolume;

    UPROPERTY(config)
    float EffectSoundVolume;

public:
    UOutGameUserSettings();

    virtual void ApplySettings(bool bCheckForCommandLineOverrides) override;

    UFUNCTION(BlueprintPure)
    static UOutGameUserSettings* GetOutGameUserSettings();

    UFUNCTION(BlueprintCallable, Category = "Settings")
    float GetMusicSoundVolume() const;

    UFUNCTION(BlueprintCallable, Category = "Settings")
    void SetMusicSoundVolume(float Value);

    UFUNCTION(BlueprintPure, Category = "Settings")
    float GetAmbientSoundVolume() const;

    UFUNCTION(BlueprintCallable, Category = "Settings")
    void SetAmbientSoundVolume(float Value);

    UFUNCTION(BlueprintPure, Category = "Settings")
    float GetUISoundVolume() const;

    UFUNCTION(BlueprintCallable, Category = "Settings")
    void SetUISoundVolume(float Value);

    UFUNCTION(BlueprintPure, Category = "Settings")
    float GetEffectSoundVolume() const;

    UFUNCTION(BlueprintCallable, Category = "Settings")
    void SetEffectSoundVolume(float Value);
};
