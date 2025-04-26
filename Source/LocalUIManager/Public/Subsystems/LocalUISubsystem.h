// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "LocalUISubsystem.generated.h"

struct FModalWidgetData;
class FOnConfirmDelegate;
class FOnCancelDelegate;
class FOnInputTextDelegate;

/**
 * 로컬 UI 관리 전용 서브 시스템
 * 위젯 클래스 별로 하나의 위젯만 생성되어 재사용됩니다.
 */
UCLASS()
class LOCALUIMANAGER_API ULocalUISubsystem : public ULocalPlayerSubsystem
{
    GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadOnly, Category = "State", Transient, meta = (AllowPrivateAccess = "true"))
    TArray<TObjectPtr<UUserWidget>> Widgets;

public:
    /* LocalPlayerSubsystem */

    UFUNCTION(BlueprintCallable)
    virtual void ShowWidgetByClass(TSubclassOf<UUserWidget> WidgetClass);

    UFUNCTION(BlueprintCallable)
    virtual void HideWidgetByClass(TSubclassOf<UUserWidget> WidgetClass);

    UFUNCTION(BlueprintCallable)
    virtual void RequestAlertModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass = nullptr);

    UFUNCTION(BlueprintCallable)
    virtual void RequestConfirmModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass = nullptr);

    UFUNCTION(BlueprintCallable)
    virtual void RequestPromptModal(const FModalWidgetData& InModalWidgetData, TSubclassOf<UUserWidget> WidgetClass = nullptr);

protected:
    UFUNCTION(BlueprintCallable)
    virtual UUserWidget* GetOrCreateModalWidget(TSubclassOf<UUserWidget> ModalWidgetClass);

    UFUNCTION(BlueprintCallable)
    virtual UUserWidget* CreateAndRegisterWidget(TSubclassOf<UUserWidget> WidgetClass);

    UFUNCTION(BlueprintCallable)
    virtual int32 GetWidgetIndex(TSubclassOf<UUserWidget> WidgetClass);

    UFUNCTION(BlueprintCallable)
    virtual UUserWidget* GetWidget(TSubclassOf<UUserWidget> WidgetClass);

    UFUNCTION(BlueprintCallable)
    virtual UUserWidget* GetOrCreateWidget(TSubclassOf<UUserWidget> WidgetClass);

    UFUNCTION(BlueprintCallable)
    virtual void RemoveWidget(TSubclassOf<UUserWidget> WidgetClass);

    UFUNCTION(BlueprintCallable)
    virtual void RemoveLastWidget();
};
