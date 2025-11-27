// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

USTRUCT(BlueprintType)
struct FStringArray
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<FString> Strings;
};

/**
 * 
 */
UCLASS()
class WORDLE_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "UMyBlueprintFunctionLibrary")
	static bool LoadWordsFromFile(FString FileName, int32 RequiredWordLength, TMap<int32, FStringArray>& Words);

	UFUNCTION(BlueprintCallable, Category = "UMyBlueprintFunctionLibrary")
	static bool IsLetter(FString String);	

};
