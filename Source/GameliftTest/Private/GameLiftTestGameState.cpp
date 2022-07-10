// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLiftTestGameState.h"
#include "Net/UnrealNetwork.h"


void AGameLiftTestGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
  Super::GetLifetimeReplicatedProps(OutLifetimeProps);

  DOREPLIFETIME(AGameLiftTestGameState, LatestEvent);
  DOREPLIFETIME(AGameLiftTestGameState, WinningTeam);
}