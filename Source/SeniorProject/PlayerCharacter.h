// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SENIORPROJECT_API APlayerCharacter : public APaperCharacter
{
	GENERATED_BODY()

private:

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess))
	int32 CoinsCollected = 0;

public:

	FORCEINLINE void SetCoinsCollected(const int32 Amount) { CoinsCollected = Amount; }
	FORCEINLINE int32 GetCoinsCollected() const { return CoinsCollected; }
	
};
