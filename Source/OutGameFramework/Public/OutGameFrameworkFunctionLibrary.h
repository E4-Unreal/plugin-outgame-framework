// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OutGameFrameworkFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class OUTGAMEFRAMEWORK_API UOutGameFrameworkFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure)
    static FString GetProjectVersion();
};
