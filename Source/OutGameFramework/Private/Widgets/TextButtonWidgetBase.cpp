// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/TextButtonWidgetBase.h"

#include "Components/SizeBox.h"
#include "Components/TextBlock.h"

UTextButtonWidgetBase::UTextButtonWidgetBase(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    // TextBlock
    Text = FText::FromString(TEXT("Button"));
}

void UTextButtonWidgetBase::NativePreConstruct()
{
    Super::NativePreConstruct();

    // TextBlock
    if (TextBlock) TextBlock->SetText(Text);
}

void UTextButtonWidgetBase::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    // Button
    if (Button)
    {
        Button->OnClicked.AddDynamic(this, &ThisClass::OnClicked_Event);
        Button->OnPressed.AddDynamic(this, &ThisClass::OnPressed_Event);
        Button->OnReleased.AddDynamic(this, &ThisClass::OnReleased_Event);
        Button->OnHovered.AddDynamic(this, &ThisClass::OnHovered_Event);
        Button->OnUnhovered.AddDynamic(this, &ThisClass::OnUnhovered_Event);
    }
}
