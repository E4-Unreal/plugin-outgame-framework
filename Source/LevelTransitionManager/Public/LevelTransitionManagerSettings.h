// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "MoviePlayer.h"
#include "LevelTransitionManagerSettings.generated.h"

/**
 * LevelTransitionManager 모듈 전용 싱글톤 데이터 클래스
 */
UCLASS(config = OutGameFramework, meta = (DisplayName = "Level Transition Manager", ToolTip = "Settings for LevelTransitionManager Module in OutGameFramework Plugin"))
class LEVELTRANSITIONMANAGER_API ULevelTransitionManagerSettings : public UDeveloperSettings
{
    GENERATED_BODY()

protected:
    UPROPERTY(Config, EditDefaultsOnly, Category = "Settings")
    TMap<FName, TSoftObjectPtr<UWorld>> LevelMap;

    UPROPERTY(Config, EditDefaultsOnly, Category = "LoadingScreen")
    TSoftClassPtr<UUserWidget> LoadingScreenWidgetClass;

    UPROPERTY(Transient)
    TObjectPtr<UUserWidget> LoadingScreenWidget;

    UPROPERTY(Config, EditDefaultsOnly, Category = "LoadingScreen")
    TArray<FString> MoviePaths;

    UPROPERTY(Config, EditDefaultsOnly, Category = "LoadingScreen")
    float MinimumLoadingScreenDisplayTime;

    UPROPERTY(Config, EditDefaultsOnly, Category = "LoadingScreen")
    bool bAutoCompleteWhenLoadingCompletes;

    UPROPERTY(Config, EditDefaultsOnly, Category = "LoadingScreen")
    bool bMoviesAreSkippable;

    UPROPERTY(Config, EditDefaultsOnly, Category = "LoadingScreen")
    bool bWaitForManualStop;

    UPROPERTY(Config, EditDefaultsOnly, Category = "LoadingScreen")
    bool bAllowInEarlyStartup;

    UPROPERTY(Config, EditDefaultsOnly, Category = "LoadingScreen")
    bool bAllowEngineTick;

    UPROPERTY(Config, EditDefaultsOnly, Category = "LoadingScreen")
    TEnumAsByte<EMoviePlaybackType> PlaybackType;

public:
    ULevelTransitionManagerSettings();

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get LevelTransitionManagerSettings"))
    static ULevelTransitionManagerSettings* Get() { return GetMutableDefault<ULevelTransitionManagerSettings>(); }

    UFUNCTION(BlueprintPure)
    TSoftObjectPtr<UWorld> GetLevelByName(FName LevelName) const;

    FLoadingScreenAttributes GetLoadingScreenAttributes(UGameInstance* GameInstance);
};
