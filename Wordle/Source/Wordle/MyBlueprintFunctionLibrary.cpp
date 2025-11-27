// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "Kismet/KismetStringLibrary.h"

static bool isASCIILetter(char c)
{
	return(c >= 65 && c <= 90);
}
bool UMyBlueprintFunctionLibrary::LoadWordsFromFile(FString FileName, int32 RequiredWordLength, TMap<int32, FStringArray>& Words)
{
	FString parsedText;
	if (FFileHelper::LoadFileToString(parsedText, *(FPaths::ProjectContentDir() + FileName)) == false)
		return false;

	TArray<FString> parsedWords = UKismetStringLibrary::ParseIntoArray(parsedText, "\n"); // faut que "/" soit dans l'autre sens

	for (FString& word : parsedWords)
	{
		if (word.Len() < RequiredWordLength)
			continue;

		word.ToUpperInline();

		bool containsOnlyValidCharacter = true;
		for (const auto& letter : word.GetCharArray())
		{
			if (letter != '\0' && isASCIILetter(letter) == false)
			{
				containsOnlyValidCharacter = false;
				break;
			}
		}

		if (containsOnlyValidCharacter == true)
			Words.FindOrAdd(word.Len()).Strings.Add(word);
	}

	return true;
}

bool UMyBlueprintFunctionLibrary::IsLetter(FString String)
{
	if (String.Len() != 1)
		return false;

	return isASCIILetter(String.ToUpper().GetCharArray()[0]);
}

// ne pas oublier qu'il est constamment en debug mode