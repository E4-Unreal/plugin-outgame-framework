// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "LocalSoundSubsystem.generated.h"

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API ULocalSoundSubsystem : public ULocalPlayerSubsystem
{
    GENERATED_BODY()

protected:
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
    TObjectPtr<UAudioComponent> MusicSoundPlayer;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
    TObjectPtr<UAudioComponent> AmbientSoundPlayer;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
    TObjectPtr<UAudioComponent> UISoundPlayer;

public:
    /* Subsystem */

    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    /* LocalSoundSubsystem */

    UFUNCTION(BlueprintCallable)
    virtual void ApplySoundSettings();

    UFUNCTION(BlueprintCallable)
    virtual void PlayMusicSound(USoundCue* MusicSound);

    UFUNCTION(BlueprintCallable)
    virtual void StopMusicSound();

    UFUNCTION(BlueprintCallable)
    virtual void PlayAmbientSound(USoundCue* AmbientSound);

    UFUNCTION(BlueprintCallable)
    virtual void StopAmbientSound();

    UFUNCTION(BlueprintCallable)
    virtual void PlayUISound(USoundCue* UISound);

    UFUNCTION(BlueprintCallable)
    virtual void StopUISound();

protected:
    /* LocalSoundSubsystem */

    UFUNCTION(BlueprintCallable)
    virtual UAudioComponent* CreateSoundPlayer(USoundCue* Sound);

    UFUNCTION(BlueprintCallable)
    virtual void PlaySound(UAudioComponent* SoundPlayer, USoundCue* Sound);

    UFUNCTION(BlueprintCallable)
    virtual void StopSound(UAudioComponent* SoundPlayer);
};
