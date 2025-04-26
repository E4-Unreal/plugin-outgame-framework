// Fill out your copyright notice in the Description page of Project Settings.


#include "OutGameFrameworkFunctionLibrary.h"

#include "GeneralProjectSettings.h"

FString UOutGameFrameworkFunctionLibrary::GetProjectVersion()
{
    return GetMutableDefault<UGeneralProjectSettings>()->ProjectVersion;
}
