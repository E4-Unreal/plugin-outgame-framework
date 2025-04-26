// Fill out your copyright notice in the Description page of Project Settings.


#include "OutGameUserSettings.h"

#include "AudioDevice.h"
#include "OutGameFrameworkSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Subsystems/LocalSoundSubsystem.h"

UOutGameUserSettings::UOutGameUserSettings()
{
    MusicSoundVolume = 1.f;
    AmbientSoundVolume = 1.f;
    UISoundVolume = 1.f;
    EffectSoundVolume = 1.f;
}

void UOutGameUserSettings::ApplySettings(bool bCheckForCommandLineOverrides)
{
    if (GEngine)
    {
        TArray<APlayerController*> LocalPlayerControllers;
        GEngine->GetAllLocalPlayerControllers(LocalPlayerControllers);

        if (!LocalPlayerControllers.IsEmpty())
        {
            if (ULocalPlayer* LocalPlayer = LocalPlayerControllers[0]->GetLocalPlayer())
            {
                if (auto LocalSoundSubsystem = LocalPlayer->GetSubsystem<ULocalSoundSubsystem>())
                {
                    LocalSoundSubsystem->ApplySoundSettings();
                }
            }
        }
    }

    Super::ApplySettings(bCheckForCommandLineOverrides);
}

UOutGameUserSettings* UOutGameUserSettings::GetOutGameUserSettings()
{
    return Cast<UOutGameUserSettings>(GetGameUserSettings());
}

float UOutGameUserSettings::GetMusicSoundVolume() const
{
    return MusicSoundVolume;
}

void UOutGameUserSettings::SetMusicSoundVolume(float Value)
{
    MusicSoundVolume = FMath::Clamp(Value, 0.f, 1.f);
}

float UOutGameUserSettings::GetAmbientSoundVolume() const
{
    return AmbientSoundVolume;
}

void UOutGameUserSettings::SetAmbientSoundVolume(float Value)
{
    AmbientSoundVolume = FMath::Clamp(Value, 0.f, 1.f);
}

float UOutGameUserSettings::GetUISoundVolume() const
{
    return UISoundVolume;
}

void UOutGameUserSettings::SetUISoundVolume(float Value)
{
    UISoundVolume = FMath::Clamp(Value, 0.f, 1.f);
}

float UOutGameUserSettings::GetEffectSoundVolume() const
{
    return EffectSoundVolume;
}

void UOutGameUserSettings::SetEffectSoundVolume(float Value)
{
    EffectSoundVolume = FMath::Clamp(Value, 0.f, 1.f);
}
