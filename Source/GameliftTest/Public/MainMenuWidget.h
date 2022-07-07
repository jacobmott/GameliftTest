// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "MainMenuWidget.generated.h"


class UWebBrowser;
class UButton;
class UTextBlock;

/**
 * 
 */
UCLASS()
class GAMELIFTTEST_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
  UMainMenuWidget(const FObjectInitializer& ObjectInitializer);

  UPROPERTY()
  FTimerHandle SetAveragePlayerLatencyHandle;

  UPROPERTY()
  FTimerHandle PollMatchmakingHandle;

protected:
  virtual void NativeConstruct() override;
  virtual void NativeDestruct() override;

private:
  FHttpModule* HttpModule;

  UPROPERTY()
  FString LoginUrl;

  UPROPERTY()
  FString ApiUrl;

  UPROPERTY()
  FString CallbackUrl;

  UPROPERTY()
  FString RegionCode;

  UPROPERTY()
  TObjectPtr<UWebBrowser> WebBrowser;

  UPROPERTY()
  TObjectPtr<UButton> MatchmakingButton;

  UPROPERTY()
  TObjectPtr<UTextBlock> WinsTextBlock;

  UPROPERTY()
  TObjectPtr<UTextBlock> LossesTextBlock;

  UPROPERTY()
  TObjectPtr<UTextBlock> PingTextBlock;

  UPROPERTY()
  TObjectPtr<UTextBlock> MatchmakingEventTextBlock;

  UPROPERTY()
  float AveragePlayerLatency;

  UPROPERTY()
  bool SearchingForGame;

  UFUNCTION()
  void HandleLoginUrlChange();

  UFUNCTION()
  void SetAveragePlayerLatency();

  UFUNCTION()
  void OnMatchmakingButtonClicked();

  UFUNCTION()
  void PollMatchmaking();

  void OnExchangeCodeForTokensResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
  void OnGetPlayerDataResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
  void OnStartMatchmakingResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
  void OnStopMatchmakingResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
  void OnPollMatchmakingResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

};
