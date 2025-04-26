// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LanguageSettingsConfig.h"
#include "TextLanguageSetting.generated.h"

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API UTextLanguageSetting : public ULanguageSettingsConfig
{
    GENERATED_BODY()

public:
    UTextLanguageSetting();

    /* GameUserSettingsConfig */

    virtual void Load_Implementation(UGameUserSettings* GameUserSettings) override;
    virtual void Apply_Implementation(UGameUserSettings* GameUserSettings) override;
    virtual FText GetSelectedOptionText_Implementation() const override;
    virtual int32 GetOptionNum_Implementation() const override;

    /* ResolutionSetting */

    static FString GetLanguageByIndex(int32 Index);
    static int32 GetIndexByLanguage(const FString& Language);
};
