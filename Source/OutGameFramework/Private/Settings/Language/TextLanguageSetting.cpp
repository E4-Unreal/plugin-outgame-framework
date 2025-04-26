// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/Language/TextLanguageSetting.h"

#include "Logging.h"
#include "Kismet/KismetInternationalizationLibrary.h"

#define LOCTEXT_NAMESPACE "OutGameFrameworkStringTable"

UTextLanguageSetting::UTextLanguageSetting()
{
    OptionName = LOCTEXT("TextLanguage", "Text Language");
}

void UTextLanguageSetting::Load_Implementation(UGameUserSettings* GameUserSettings)
{
    SetCurrentOption(GetIndexByLanguage(UKismetInternationalizationLibrary::GetCurrentCulture()));
}

void UTextLanguageSetting::Apply_Implementation(UGameUserSettings* GameUserSettings)
{
    if (IsDirty())
    {
        UKismetInternationalizationLibrary::SetCurrentCulture(GetLanguageByIndex(GetSelectedOption()));
        SetCurrentOption(GetSelectedOption());

        LOG_S(Log)
    }
}

FText UTextLanguageSetting::GetSelectedOptionText_Implementation() const
{
    return FText::FromString(UKismetInternationalizationLibrary::GetCultureDisplayName(GetLanguageByIndex(GetSelectedOption()), false));
}

int32 UTextLanguageSetting::GetOptionNum_Implementation() const
{
    return UKismetInternationalizationLibrary::GetLocalizedCultures().Num();
}

FString UTextLanguageSetting::GetLanguageByIndex(int32 Index)
{
    TArray<FString> Languages = UKismetInternationalizationLibrary::GetLocalizedCultures();

    return Index < 0 || Index > Languages.Num() - 1 ? FString("Error") : Languages[Index];
}

int32 UTextLanguageSetting::GetIndexByLanguage(const FString& Language)
{
    TArray<FString> Languages = UKismetInternationalizationLibrary::GetLocalizedCultures();

    return Languages.Find(Language);
}

#undef LOCTEXT_NAMESPACE
