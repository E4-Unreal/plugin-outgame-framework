// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GraphicSettingsConfig.h"
#include "ResolutionSetting.generated.h"

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API UResolutionSetting : public UGraphicSettingsConfig
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FIntPoint> Resolutions;

public:
    UResolutionSetting();

    /* GameUserSettingsConfig */

    virtual void Load_Implementation(UGameUserSettings* GameUserSettings) override;
    virtual void Apply_Implementation(UGameUserSettings* GameUserSettings) override;
    virtual FText GetSelectedOptionText_Implementation() const override;
    virtual int32 GetOptionNum_Implementation() const override { return Resolutions.Num(); }

    /* ResolutionSetting */

    const FIntPoint& GetResolutionByIndex(int32 Index) const;
    int32 GetIndexByResolution(const FIntPoint& Resolution) const;
};
