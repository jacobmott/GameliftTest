// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLiftTestWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/GameStateBase.h"
#include "GameLiftTestPlayerState.h"
#include "GameLiftTestGameState.h"
#include "GameLiftTestGameInstance.h"
#include "Kismet/GameplayStatics.h"




void UGameLiftTestWidget::NativeConstruct() {
  Super::NativeConstruct();

  TeamNameTextBlock = (UTextBlock*)GetWidgetFromName(TEXT("TextBlock_TeamName"));
  TeammateCountTextBlock = (UTextBlock*)GetWidgetFromName(TEXT("TextBlock_TeammateCount"));
  EventTextBlock = (UTextBlock*)GetWidgetFromName(TEXT("TextBlock_Event"));
  PingTextBlock = (UTextBlock*)GetWidgetFromName(TEXT("TextBlock_Ping"));

  GetWorld()->GetTimerManager().SetTimer(SetTeammateCountHandle, this, &UGameLiftTestWidget::SetTeammateCount, 1.0f, true, 1.0f);
  GetWorld()->GetTimerManager().SetTimer(SetLatestEventHandle, this, &UGameLiftTestWidget::SetLatestEvent, 1.0f, true, 1.0f);
  GetWorld()->GetTimerManager().SetTimer(SetAveragePlayerLatencyHandle, this, &UGameLiftTestWidget::SetAveragePlayerLatency, 1.0f, true, 1.0f);
}

void UGameLiftTestWidget::NativeDestruct() {
  GetWorld()->GetTimerManager().ClearTimer(SetTeammateCountHandle);
  GetWorld()->GetTimerManager().ClearTimer(SetLatestEventHandle);
  GetWorld()->GetTimerManager().ClearTimer(SetAveragePlayerLatencyHandle);
  Super::NativeDestruct();
}

void UGameLiftTestWidget::SetTeammateCount() {
  FString OwningPlayerTeam;
  APlayerState* OwningPlayerState = GetOwningPlayerState();

  if (OwningPlayerState != nullptr) {
    AGameLiftTestPlayerState* OwningGameLiftTutorialPlayerState = Cast<AGameLiftTestPlayerState>(OwningPlayerState);
    if (OwningGameLiftTutorialPlayerState != nullptr) {
      OwningPlayerTeam = OwningGameLiftTutorialPlayerState->Team;
      TeamNameTextBlock->SetText(FText::FromString("Team Name: " + OwningPlayerTeam));
    }
  }

  if (OwningPlayerTeam.Len() > 0) {
    TArray<APlayerState*> PlayerStates = GetWorld()->GetGameState()->PlayerArray;

    int TeammateCount = 0;

    for (APlayerState* PlayerState : PlayerStates) {
      if (PlayerState != nullptr) {
        AGameLiftTestPlayerState* GameLiftTutorialPlayerState = Cast<AGameLiftTestPlayerState>(PlayerState);
        if (GameLiftTutorialPlayerState != nullptr && GameLiftTutorialPlayerState->Team.Equals(OwningPlayerTeam)) {
          TeammateCount++;
        }
      }
    }

    TeammateCountTextBlock->SetText(FText::FromString("Teammate Count: " + FString::FromInt(TeammateCount)));
  }
}

void UGameLiftTestWidget::SetLatestEvent() {
  FString LatestEvent;
  FString WinningTeam;
  AGameStateBase* GameState = GetWorld()->GetGameState();

  if (GameState != nullptr) {
    AGameLiftTestGameState* GameLiftTutorialGameState = Cast<AGameLiftTestGameState>(GameState);
    if (GameLiftTutorialGameState != nullptr) {
      LatestEvent = GameLiftTutorialGameState->LatestEvent;
      WinningTeam = GameLiftTutorialGameState->WinningTeam;
    }
  }

  if (LatestEvent.Len() > 0) {
    if (LatestEvent.Equals("GameEnded")) {
      FString OwningPlayerTeam;
      APlayerState* OwningPlayerState = GetOwningPlayerState();

      if (OwningPlayerState != nullptr) {
        AGameLiftTestPlayerState* OwningGameLiftTutorialPlayerState = Cast<AGameLiftTestPlayerState>(OwningPlayerState);
        if (OwningGameLiftTutorialPlayerState != nullptr) {
          OwningPlayerTeam = OwningGameLiftTutorialPlayerState->Team;
        }
      }

      if (WinningTeam.Len() > 0 && OwningPlayerTeam.Len() > 0) {
        FString GameOverMessage = "You and the " + OwningPlayerTeam;
        if (OwningPlayerTeam.Equals(WinningTeam)) {
          EventTextBlock->SetText(FText::FromString(GameOverMessage + " won!"));
        }
        else {
          EventTextBlock->SetText(FText::FromString(GameOverMessage + " lost :("));
        }
      }
    }
    else {
      EventTextBlock->SetText(FText::FromString(LatestEvent));
    }
  }
}

void UGameLiftTestWidget::SetAveragePlayerLatency() {
  UGameInstance* GameInstance = GetGameInstance();
  if (GameInstance != nullptr) {
    UGameLiftTestGameInstance* GameLiftTutorialGameInstance = Cast<UGameLiftTestGameInstance>(GameInstance);
    if (GameLiftTutorialGameInstance != nullptr) {
      float TotalPlayerLatency = 0.0f;
      for (float PlayerLatency : GameLiftTutorialGameInstance->PlayerLatencies) {
        TotalPlayerLatency += PlayerLatency;
      }

      float AveragePlayerLatency = 60.0f;

      if (TotalPlayerLatency > 0) {
        AveragePlayerLatency = TotalPlayerLatency / GameLiftTutorialGameInstance->PlayerLatencies.Num();

        FString PingString = "Ping: " + FString::FromInt(FMath::RoundToInt(AveragePlayerLatency)) + "ms";
        PingTextBlock->SetText(FText::FromString(PingString));
      }
    }
  }
}