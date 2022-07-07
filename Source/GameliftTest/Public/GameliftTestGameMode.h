// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameliftServerSDK.h"
#include "GameFramework/GameModeBase.h"
#include "GameliftTestGameMode.generated.h"


USTRUCT()
struct FStartGameSessionState {
	GENERATED_BODY();

  UPROPERTY()
  bool Status;

	FStartGameSessionState() {
		Status = false;
	}

};


USTRUCT()
struct FUpdateGameSessionState {
  GENERATED_BODY();

  FUpdateGameSessionState() {

  }

};

USTRUCT()
struct FProcessTerminateState {
  GENERATED_BODY();

  UPROPERTY()
  bool Status;

  long TerminationTime;

  FProcessTerminateState() {
    Status = false;
  }

};


USTRUCT()
struct FHealthCheckState {
  GENERATED_BODY();

  UPROPERTY()
  bool Status;

  FHealthCheckState() {
    Status = false;
  }

};

UCLASS(minimalapi)
class AGameliftTestGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameliftTestGameMode();



protected:
  virtual void BeginPlay() override;

private:

  UPROPERTY()
  FStartGameSessionState StartGameSessionState;

  UPROPERTY()
  FUpdateGameSessionState UpdateGameSessionState;

  UPROPERTY()
  FProcessTerminateState ProcessTerminateState;

  UPROPERTY()
  FHealthCheckState HealthCheckState;


};



