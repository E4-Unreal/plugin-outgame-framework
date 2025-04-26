// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Settings/GameUserSettingsConfig.h"
#include "SoundSettingsConfig.generated.h"

/**
 * 소리 옵션 전용 GameUserSettingsConfig 클래스로 서브 클래스 필터 기능을 사용하기 위해 작성되었습니다.
 */
UCLASS(Abstract)
class OUTGAMEFRAMEWORK_API USoundSettingsConfig : public UGameUserSettingsConfig
{
    GENERATED_BODY()
};
