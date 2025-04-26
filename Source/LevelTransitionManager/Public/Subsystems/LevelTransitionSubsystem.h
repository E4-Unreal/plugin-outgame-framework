// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LevelTransitionSubsystem.generated.h"

/**
 * 레벨 이동 관리 전용 서브시스템
 */
UCLASS()
class LEVELTRANSITIONMANAGER_API ULevelTransitionSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    /* Subsystem */

    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    /* LevelTransitionSubsystem */

    UFUNCTION(BlueprintCallable)
    virtual void OpenLevelByName(FName LevelName);

    UFUNCTION(BlueprintCallable)
    virtual void ServerTravelByName(FName LevelName);

    UFUNCTION(BlueprintCallable)
    virtual void AsyncOpenLevelByName(FName LevelName);

    UFUNCTION(BlueprintCallable)
    virtual void AsyncServerTravelByName(FName LevelName);

protected:
    UFUNCTION(BlueprintCallable)
    virtual void ShowLoadingScreen();

    // FLoadPackageAsyncDelegate
    virtual void OnOpenLevelReady(const FName& LevelName, UPackage* LoadedPackage, EAsyncLoadingResult::Type Result);

    // FLoadPackageAsyncDelegate
    virtual void OnServerTravelReady(const FName& LevelName, UPackage* LoadedPackage, EAsyncLoadingResult::Type Result);
};
