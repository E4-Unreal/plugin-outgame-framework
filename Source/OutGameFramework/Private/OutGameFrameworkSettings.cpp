// Fill out your copyright notice in the Description page of Project Settings.


#include "OutGameFrameworkSettings.h"

#include "Sound/SoundMix.h"
#include "Sound/SoundClass.h"

UOutGameFrameworkSettings::UOutGameFrameworkSettings()
{
    CategoryName = "Plugins";
    SectionName = "OutGameFramework";
}

USoundMix* UOutGameFrameworkSettings::GetSoundMix() const
{
    return SoundMix.LoadSynchronous();
}

USoundClass* UOutGameFrameworkSettings::GetMusicSoundClass() const
{
    return MusicSoundClass.LoadSynchronous();
}

USoundClass* UOutGameFrameworkSettings::GetAmbientSoundClass() const
{
    return AmbientSoundClass.LoadSynchronous();
}

USoundClass* UOutGameFrameworkSettings::GetUISoundClass() const
{
    return UISoundClass.LoadSynchronous();
}

USoundClass* UOutGameFrameworkSettings::GetEffectSoundClass() const
{
    return EffectSoundClass.LoadSynchronous();
}
