// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "FileWriter.generated.h"

/**
 *
 */
UCLASS()
class SUKO_API UFileWriter : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	static const FString ParticipantNumberFilePath_;
	static FString participantString_;
	static FString conditionString_;
	static uint32 participantNumber_;

	static TArray<FString> fileContent_;

	static uint32 GetCurrentParticipantNumber();
	static bool AdvanceCurrentParticipantNumber();

	static FString BuildPath();

public:
	UFUNCTION(BlueprintCallable)
	static bool NewParticipant(int& participantNumber);

	// Used for the file name, so choose something that will work on your OS.
	UFUNCTION(BlueprintCallable)
	static void NewCondition(FString condition);

	UFUNCTION(BlueprintCallable)
	static void AddContent(FString row);

	UFUNCTION(BlueprintCallable)
	static TArray<FString>& GetContent();

	// This also clears content.
	UFUNCTION(BlueprintCallable)
	static void WriteContent(FString fileName);

	// This also clears content.
	UFUNCTION(BlueprintCallable)
	static void WriteContentToCSV();

	UFUNCTION(BlueprintCallable)
	static bool WriteStrings(UPARAM(ref) TArray<FString>& strings, FString fileName);

	UFUNCTION(BlueprintCallable)
	static bool WriteStringsToCSV(TArray<FString> strings);
};
