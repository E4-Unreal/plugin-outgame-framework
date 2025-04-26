// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/LocalUIWidgetBase.h"
#include "MainMenuWidgetBase.generated.h"

class UButton;

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API UMainMenuWidgetBase : public ULocalUIWidgetBase
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> PlayButton;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> OptionsButton;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> ExitButton;

    UPROPERTY(EditDefaultsOnly)
    FName MainLevelName;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
    TSubclassOf<UUserWidget> OptionsWidgetClass;

    UPROPERTY(EditDefaultsOnly)
    FModalWidgetData RequestExitData;

public:
    UMainMenuWidgetBase(const FObjectInitializer& ObjectInitializer);

protected:
    /* UserWidget */

    virtual void NativeOnInitialized() override;

    /* MainMenuWidgetBase */

    UFUNCTION()
    virtual void OnPlayButtonClicked();

    UFUNCTION()
    virtual void OnOptionsButtonClicked();

    UFUNCTION()
    virtual void OnExitButtonClicked();

    UFUNCTION(BlueprintCallable)
    virtual void Play();

    UFUNCTION(BlueprintCallable)
    virtual void ShowOptionsMenuWidget();

    UFUNCTION(BlueprintCallable)
    virtual void Exit();
};
