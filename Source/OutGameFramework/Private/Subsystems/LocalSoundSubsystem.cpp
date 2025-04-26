// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/LocalSoundSubsystem.h"

#include "OutGameFrameworkSettings.h"
#include "OutGameUserSettings.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

void ULocalSoundSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    if (auto GameUserSettings = UGameUserSettings::GetGameUserSettings())
    {
        GameUserSettings->LoadSettings();
        ApplySoundSettings();
    }
}

void ULocalSoundSubsystem::ApplySoundSettings()
{
    ULocalPlayer* LocalPlayer = GetLocalPlayer();
    auto OutGameFrameworkSettings = GetMutableDefault<UOutGameFrameworkSettings>();
    auto OutGameUserSettings = UOutGameUserSettings::GetOutGameUserSettings();

    if (LocalPlayer && OutGameFrameworkSettings && OutGameUserSettings)
    {
        USoundMix* SoundMix = OutGameFrameworkSettings->GetSoundMix();
        USoundClass* MusicSoundClass = OutGameFrameworkSettings->GetMusicSoundClass();
        USoundClass* AmbientSoundClass = OutGameFrameworkSettings->GetAmbientSoundClass();
        USoundClass* UISoundClass = OutGameFrameworkSettings->GetUISoundClass();
        USoundClass* EffectSoundClass = OutGameFrameworkSettings->GetEffectSoundClass();

        float MusicSoundVolume = OutGameUserSettings->GetMusicSoundVolume();
        float AmbientSoundVolume = OutGameUserSettings->GetAmbientSoundVolume();
        float UISoundVolume = OutGameUserSettings->GetUISoundVolume();
        float EffectSoundVolume = OutGameUserSettings->GetEffectSoundVolume();

        UGameplayStatics::SetBaseSoundMix(LocalPlayer, SoundMix);
        UGameplayStatics::SetSoundMixClassOverride(LocalPlayer, SoundMix, MusicSoundClass, MusicSoundVolume, 1, 0);
        UGameplayStatics::SetSoundMixClassOverride(LocalPlayer, SoundMix, AmbientSoundClass, AmbientSoundVolume, 1, 0);
        UGameplayStatics::SetSoundMixClassOverride(LocalPlayer, SoundMix, UISoundClass, UISoundVolume, 1, 0);
        UGameplayStatics::SetSoundMixClassOverride(LocalPlayer, SoundMix, EffectSoundClass, EffectSoundVolume, 1, 0);
    }
}

UAudioComponent* ULocalSoundSubsystem::CreateSoundPlayer(USoundCue* Sound)
{
    return UGameplayStatics::CreateSound2D(GetLocalPlayer(), Sound, 1, 1, 0, nullptr, true, false);
}

void ULocalSoundSubsystem::PlaySound(UAudioComponent* SoundPlayer, USoundCue* Sound)
{
    if (SoundPlayer && Sound)
    {
        SoundPlayer->Stop();
        SoundPlayer->SetSound(Sound);
        SoundPlayer->Play();
    }
}

void ULocalSoundSubsystem::StopSound(UAudioComponent* SoundPlayer)
{
    if (SoundPlayer) SoundPlayer->Stop();
}

void ULocalSoundSubsystem::PlayMusicSound(USoundCue* MusicSound)
{
    if (MusicSoundPlayer == nullptr)
    {
        MusicSoundPlayer = CreateSoundPlayer(MusicSound);
        MusicSoundPlayer->bIsMusic = true;
    }

    PlaySound(MusicSoundPlayer, MusicSound);
}

void ULocalSoundSubsystem::StopMusicSound()
{
    StopSound(MusicSoundPlayer);
}

void ULocalSoundSubsystem::PlayAmbientSound(USoundCue* AmbientSound)
{
    if (AmbientSoundPlayer == nullptr)
    {
        AmbientSoundPlayer = CreateSoundPlayer(AmbientSound);
        AmbientSoundPlayer->bIsMusic = true;
    }

    PlaySound(AmbientSoundPlayer, AmbientSound);
}

void ULocalSoundSubsystem::StopAmbientSound()
{
   StopSound(AmbientSoundPlayer);
}

void ULocalSoundSubsystem::PlayUISound(USoundCue* UISound)
{
    if (UISoundPlayer == nullptr)
    {
        UISoundPlayer = CreateSoundPlayer(UISound);
        UISoundPlayer->bIsUISound = true;
    }

    PlaySound(UISoundPlayer, UISound);
}

void ULocalSoundSubsystem::StopUISound()
{
    StopSound(UISoundPlayer);
}
