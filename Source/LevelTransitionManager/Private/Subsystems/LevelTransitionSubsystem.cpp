// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/LevelTransitionSubsystem.h"

#include "LevelTransitionManagerSettings.h"
#include "Logging.h"
#include "Kismet/GameplayStatics.h"

void ULevelTransitionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    CreateMoviePlayer();
}

void ULevelTransitionSubsystem::OpenLevelByName(FName LevelName)
{
    TSoftObjectPtr<UWorld> Level = ULevelTransitionManagerSettings::Get()->GetLevelByName(LevelName);
    UWorld* World = GetWorld();

    if (Level && World)
    {
        ShowLoadingScreen();
        UGameplayStatics::OpenLevelBySoftObjectPtr(World, Level);
    }
}

void ULevelTransitionSubsystem::ServerTravelByName(FName LevelName)
{
    TSoftObjectPtr<UWorld> Level = ULevelTransitionManagerSettings::Get()->GetLevelByName(LevelName);
    UWorld* World = GetWorld();

    if (Level && World)
    {
        ShowLoadingScreen();
        FString LevelPath = FPackageName::ObjectPathToPackageName(Level.ToString());
        World->ServerTravel(LevelPath);
    }
}

void ULevelTransitionSubsystem::AsyncOpenLevelByName(FName LevelName)
{
    TSoftObjectPtr<UWorld> Level = ULevelTransitionManagerSettings::Get()->GetLevelByName(LevelName);
    FString LevelPath = FPackageName::ObjectPathToPackageName(Level.ToString());
    int32 PackageID = LoadPackageAsync(LevelPath, FLoadPackageAsyncDelegate::CreateUObject(this, &ThisClass::OnOpenLevelReady));

    if(PackageID == INDEX_NONE)
    {
        LOG(Error, TEXT("LoadPackageAsync Failed"))
    }
    else
    {
        ShowLoadingScreen();
    }
}

void ULevelTransitionSubsystem::AsyncServerTravelByName(FName LevelName)
{
    TSoftObjectPtr<UWorld> Level = ULevelTransitionManagerSettings::Get()->GetLevelByName(LevelName);
    FString LevelPath = FPackageName::ObjectPathToPackageName(Level.ToString());
    int32 PackageID = LoadPackageAsync(LevelPath, FLoadPackageAsyncDelegate::CreateUObject(this, &ThisClass::OnServerTravelReady));

    if(PackageID == INDEX_NONE)
    {
        LOG(Error, TEXT("LoadPackageAsync Failed"))
    }
    else
    {
        ShowLoadingScreen();
    }
}

void ULevelTransitionSubsystem::ShowLoadingScreen()
{
    if(IGameMoviePlayer* MoviePlayer = GetMoviePlayer())
    {
        MoviePlayer->SetupLoadingScreen(ULevelTransitionManagerSettings::Get()->GetLoadingScreenAttributes(GetGameInstance()));
    }
}

void ULevelTransitionSubsystem::OnOpenLevelReady(const FName& LevelName, UPackage* LoadedPackage,
                                                 EAsyncLoadingResult::Type Result)
{
    switch (Result)
    {
    case EAsyncLoadingResult::Failed:
        LOG(Error, TEXT("Failed"));
        break;
    case EAsyncLoadingResult::Succeeded:
        LOG(Log, TEXT("Succeeded"));
        UGameplayStatics::OpenLevel(GetWorld(), LevelName);
        break;
    case EAsyncLoadingResult::Canceled:
        LOG(Warning, TEXT("Canceled"));
        break;
    }
}

void ULevelTransitionSubsystem::OnServerTravelReady(const FName& LevelName, UPackage* LoadedPackage,
    EAsyncLoadingResult::Type Result)
{
    switch (Result)
    {
    case EAsyncLoadingResult::Failed:
        LOG(Error, TEXT("Failed"));
        break;
    case EAsyncLoadingResult::Succeeded:
        LOG(Log, TEXT("Succeeded"));
        GetWorld()->ServerTravel(LevelName.ToString());
        break;
    case EAsyncLoadingResult::Canceled:
        LOG(Warning, TEXT("Canceled"));
        break;
    }
}
