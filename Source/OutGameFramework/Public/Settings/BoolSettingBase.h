// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameUserSettingsConfig.h"
#include "BoolSettingBase.generated.h"

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API UBoolSettingBase : public UGameUserSettingsConfig
{
    GENERATED_BODY()

public:
    /* GameUserSettingsConfig */

    virtual FText GetSelectedOptionText_Implementation() const override;
    virtual int32 GetOptionNum_Implementation() const override { return 2; }

    /* BoolSettingBase */

    static bool GetBoolByIndex(int32 Index);
    static int32 GetIndexByBool(bool bEnabled);
};
