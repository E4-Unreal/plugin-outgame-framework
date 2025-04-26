// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameUserSettingsConfig.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSelectedOptionChangedDelegate);

/**
 *
 */
UCLASS(Abstract, Blueprintable, BlueprintType, EditInlineNew, DefaultToInstanced)
class OUTGAMEFRAMEWORK_API UGameUserSettingsConfig : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable)
    FSelectedOptionChangedDelegate SelectedOptionChanged;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    FText OptionName;

private:
    UPROPERTY(VisibleInstanceOnly, Getter, Setter, Transient, Category = "State")
    int32 CurrentOption;

    UPROPERTY(VisibleInstanceOnly, Getter, Setter, Transient, Category = "State")
    int32 SelectedOption;

public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Load(UGameUserSettings* GameUserSettings);

    UFUNCTION(BlueprintPure)
    bool IsDirty() const { return CurrentOption != SelectedOption; }

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Apply(UGameUserSettings* GameUserSettings);

    UFUNCTION(BlueprintPure)
    FText GetOptionName() const { return OptionName; }

    UFUNCTION(BlueprintPure, BlueprintNativeEvent)
    FText GetSelectedOptionText() const;

    UFUNCTION(BlueprintPure, BlueprintNativeEvent)
    int32 GetOptionNum() const;

    UFUNCTION(BlueprintPure)
    int32 GetCurrentOption() const { return CurrentOption; }

    UFUNCTION(BlueprintCallable)
    void SetCurrentOption(int32 InCurrentOption);

    UFUNCTION(BlueprintPure)
    int32 GetSelectedOption() const { return SelectedOption; }

    UFUNCTION(BlueprintCallable)
    void SetSelectedOption(int32 InSelectedOption);
};
