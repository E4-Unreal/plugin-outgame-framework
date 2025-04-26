// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Graphic/QualitySettingBase.h"

#include "Logging.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UQualitySettingBase::UQualitySettingBase()
{
    QualityList.Reserve(5);
    QualityList.Emplace(LOCTEXT("Low", "Low"));
    QualityList.Emplace(LOCTEXT("Medium", "Medium"));
    QualityList.Emplace(LOCTEXT("High", "High"));
    QualityList.Emplace(LOCTEXT("VeryHigh", "Very High"));
    QualityList.Emplace(LOCTEXT("Ultra", "Ultra"));
}

FText UQualitySettingBase::GetSelectedOptionText_Implementation() const
{
    return GetSelectedOption() < QualityList.Num() ? QualityList[GetSelectedOption()] : LOCTEXT("Error", "Error");
}

#undef LOCTEXT_NAMESPACE
