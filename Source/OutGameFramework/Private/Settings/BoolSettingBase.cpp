// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/BoolSettingBase.h"

#include "Logging.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

FText UBoolSettingBase::GetSelectedOptionText_Implementation() const
{
    return GetSelectedOption() ? LOCTEXT("ON", "ON") : LOCTEXT("OFF", "OFF");
}

bool UBoolSettingBase::GetBoolByIndex(int32 Index)
{
    return Index > 0;
}

int32 UBoolSettingBase::GetIndexByBool(bool bEnabled)
{
    return bEnabled ? 1 : 0;
}

#undef LOCTEXT_NAMESPACE
