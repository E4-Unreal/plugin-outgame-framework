// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ModalWidgetData.generated.h"

DECLARE_DYNAMIC_DELEGATE(FOnConfirmDelegate);
DECLARE_DYNAMIC_DELEGATE(FOnCancelDelegate);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnInputTextDelegate, FText, InputText);

/**
 * Struct For ModalWidget
 */
USTRUCT(Atomic, BlueprintType)
struct FModalWidgetData
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Title;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Message;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FOnConfirmDelegate ConfirmDelegate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FOnCancelDelegate CancelDelegate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FOnInputTextDelegate InputTextDelegate;
};
