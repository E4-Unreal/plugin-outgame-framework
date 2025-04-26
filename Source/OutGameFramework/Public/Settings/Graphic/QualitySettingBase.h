// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GraphicSettingsConfig.h"
#include "QualitySettingBase.generated.h"

/**
 *
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class OUTGAMEFRAMEWORK_API UQualitySettingBase : public UGraphicSettingsConfig
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FText> QualityList;

public:
    UQualitySettingBase();

    /* GameUserSettingsConfig */

    virtual FText GetSelectedOptionText_Implementation() const override;
    virtual int32 GetOptionNum_Implementation() const override { return QualityList.Num(); }
};
