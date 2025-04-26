// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/ModalWidgetBase.h"
#include "ConfirmModalWidgetBase.generated.h"

class UTextBlock;
class UTextButtonWidgetBase;

/**
 * 질문 텍스트와 함께 확인 및 취소 버튼이 있는 모달 창 위젯 클래스
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class OUTGAMEFRAMEWORK_API UConfirmModalWidgetBase : public UModalWidgetBase
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> TitleText;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UTextBlock> MessageText;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UTextButtonWidgetBase> ConfirmButton;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UTextButtonWidgetBase> CancelButton;

public:
    /* Interface_ModalWidget */

    virtual void Init_Implementation(const FModalWidgetData& InModalWidgetData) override;

protected:
    /* UserWidget */

    virtual void NativeOnInitialized() override;
};
