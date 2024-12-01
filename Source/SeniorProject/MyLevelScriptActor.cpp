// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLevelScriptActor.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"
#include "Blueprint/UserWidget.h"

void AMyLevelScriptActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AMyLevelScriptActor::LevelWon()
{
	if(WinWidgetClass)
	{
		WinWidget = Cast<UUserWidget>(CreateWidget(GetWorld(), WinWidgetClass));
	}

	if(WinWidget)
	{
		WinWidget->AddToViewport();
	}
}

void AMyLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	for(FString String : LevelSentences)
	{
		TriesPerSentence.Add(0);
	}
}
