// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogLocalUIManager, Log, All)

#undef CATEGORY
#define CATEGORY LogLocalUIManager

#define CALL_INFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

#define LOG_S(Verbosity) UE_LOG(CATEGORY, Verbosity, TEXT("%s > %s"), *GetName(), *CALL_INFO)

#define LOG(Verbosity, Format, ...) UE_LOG(CATEGORY, Verbosity, TEXT("%s > %s > %s"), *GetName(), *CALL_INFO, *FString::Printf(Format, ##__VA_ARGS__))

#define LOG_TODO LOG(Warning, TEXT("Need to be implemented"))

#define LOG_TODO_INTERFACE UE_LOG(CATEGORY, Warning, TEXT("%s > Need to be implemented"), *CALL_INFO)

#define LOG_NULL(Variable) if(Variable == nullptr) LOG(Error, TEXT("%s is NULL"), *FString(#Variable))
