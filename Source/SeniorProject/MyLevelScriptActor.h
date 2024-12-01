// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "MyLevelScriptActor.generated.h"

class APlayerCharacter;
/**
 * 
 */
UCLASS()
class SENIORPROJECT_API AMyLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	virtual void LevelWon();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 LevelXP = 25;

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly, meta=(AllowPrivateAccess))
	TArray<FString> LevelSentences;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess))
	int32 CoinsInLevel = 0;

	UPROPERTY()
	APlayerCharacter* PlayerCharacter;

	UPROPERTY(EditDefaultsOnly, meta=(AllowPrivateAccess))
	int32 SentenceIndex = 0;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(AllowPrivateAccess))
	TArray<int32> TriesPerSentence;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(AllowPrivateAccess))
	TArray<float> TotalPercentagePerSentence;

	UPROPERTY(EditDefaultsOnly, meta=(AllowPrivateAccess))
	TSubclassOf<UUserWidget> WinWidgetClass;

	UUserWidget* WinWidget;

public:

	UFUNCTION(BlueprintCallable)
	FORCEINLINE TArray<FString> GetLevelSentences() const { return LevelSentences; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetSentenceIndex() const { return SentenceIndex; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void IncrementSentenceIndex() { ++SentenceIndex; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void IncrementSentenceTries(const int32 Index) { TriesPerSentence[Index]++; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE TArray<int32> GetTriesPerSentence() const { return TriesPerSentence; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetPercentagePerSentence(const TArray<float> Values) { TotalPercentagePerSentence = Values; }
	
};
