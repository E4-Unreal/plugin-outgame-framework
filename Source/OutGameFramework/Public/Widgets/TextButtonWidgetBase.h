// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "TextButtonWidgetBase.generated.h"

class USizeBox;
class UTextBlock;

/**
 * 텍스트 박스가 포함된 버튼
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class OUTGAMEFRAMEWORK_API UTextButtonWidgetBase : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(BlueprintGetter = GetSizeBox, meta = (BindWidget))
    TObjectPtr<USizeBox> SizeBox;

    UPROPERTY(BlueprintGetter = GetButton, meta = (BindWidget))
    TObjectPtr<UButton> Button;

    UPROPERTY(BlueprintGetter = GetTextBlock, meta = (BindWidget))
    TObjectPtr<UTextBlock> TextBlock;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config", meta = (MultiLine = "true"))
    FText Text;

    // Called when the button is clicked
    UPROPERTY(BlueprintAssignable)
    FOnButtonClickedEvent OnClicked;

    // Called when the button is pressed
    UPROPERTY(BlueprintAssignable)
    FOnButtonPressedEvent OnPressed;

    // Called when the button is released
    UPROPERTY(BlueprintAssignable)
    FOnButtonReleasedEvent OnReleased;

    // Called when the button is hovered
    UPROPERTY( BlueprintAssignable)
    FOnButtonHoverEvent OnHovered;

    // Called when the button is unhovered
    UPROPERTY( BlueprintAssignable)
    FOnButtonHoverEvent OnUnhovered;

public:
    UTextButtonWidgetBase(const FObjectInitializer& ObjectInitializer);

    /* UserWidget */

    virtual void NativePreConstruct() override;
    virtual void NativeOnInitialized() override;

    /* TextButtonWidgetBase */

    UFUNCTION()
    FORCEINLINE void OnClicked_Event() { OnClicked.Broadcast(); }

    UFUNCTION()
    FORCEINLINE void OnPressed_Event() { OnPressed.Broadcast(); }

    UFUNCTION()
    FORCEINLINE void OnReleased_Event() { OnReleased.Broadcast(); }

    UFUNCTION()
    FORCEINLINE void OnHovered_Event() { OnHovered.Broadcast(); }

    UFUNCTION()
    FORCEINLINE void OnUnhovered_Event() { OnUnhovered.Broadcast(); }

    /* Getter */

    UFUNCTION(BlueprintGetter)
    FORCEINLINE USizeBox* GetSizeBox() const { return SizeBox.Get(); }

    UFUNCTION(BlueprintGetter)
    FORCEINLINE UButton* GetButton() const { return Button.Get(); }

    UFUNCTION(BlueprintGetter)
    FORCEINLINE UTextBlock* GetTextBlock() const { return TextBlock.Get(); }
};
