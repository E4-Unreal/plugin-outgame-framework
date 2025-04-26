// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Graphic/GraphicBoolSettingBase.h"

#include "Logging.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

FText UGraphicBoolSettingBase::GetSelectedOptionText_Implementation() const
{
    return GetSelectedOption() ? LOCTEXT("ON", "ON") : LOCTEXT("OFF", "OFF");
}

bool UGraphicBoolSettingBase::GetBoolByIndex(int32 Index)
{
    return Index > 0;
}

int32 UGraphicBoolSettingBase::GetIndexByBool(bool bEnabled)
{
    return bEnabled ? 1 : 0;
}

#undef LOCTEXT_NAMESPACE
