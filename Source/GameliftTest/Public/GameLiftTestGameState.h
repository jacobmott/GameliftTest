// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GameLiftTestGameState.generated.h"

/**
 * 
 */
UCLASS()
class GAMELIFTTEST_API AGameLiftTestGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
  UPROPERTY(Replicated)
    FString LatestEvent;

  UPROPERTY(Replicated)
    FString WinningTeam;



};
