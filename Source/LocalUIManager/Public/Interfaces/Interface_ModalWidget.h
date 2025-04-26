// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Types/ModalWidgetData.h"
#include "UObject/Interface.h"
#include "Interface_ModalWidget.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UInterface_ModalWidget : public UInterface
{
    GENERATED_BODY()
};

/**
 * Interface for modal type widgets
 * ex) Alert, Confirm, Prompt
 */
class LOCALUIMANAGER_API IInterface_ModalWidget
{
    GENERATED_BODY()

    // Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Init(const FModalWidgetData& InModalWidgetData);
    virtual void Init_Implementation(const FModalWidgetData& InModalWidgetData);
};
