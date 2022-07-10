// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLiftTestPlayerState.h"
#include "Net/UnrealNetwork.h"

void AGameLiftTestPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
  Super::GetLifetimeReplicatedProps(OutLifetimeProps);

  DOREPLIFETIME(AGameLiftTestPlayerState, Team);
}