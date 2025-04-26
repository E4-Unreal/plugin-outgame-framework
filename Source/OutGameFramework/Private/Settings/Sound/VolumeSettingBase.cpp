// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Sound/VolumeSettingBase.h"

UVolumeSettingBase::UVolumeSettingBase()
{
    MaxVolume = 100;
}

FText UVolumeSettingBase::GetSelectedOptionText_Implementation() const
{
    return FText::FromString(FString::FromInt(GetSelectedOption()));
}

float UVolumeSettingBase::GetVolumeByIndex(int32 Index) const
{
    return Index / static_cast<float>(MaxVolume);
}

int32 UVolumeSettingBase::GetIndexByVolume(float Volume) const
{
    return static_cast<int32>(Volume * MaxVolume);
}
