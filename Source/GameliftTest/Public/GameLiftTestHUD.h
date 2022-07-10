// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameLiftTestHUD.generated.h"


class UUserWidget;
  
/**
 * 
 */
UCLASS()
class GAMELIFTTEST_API AGameLiftTestHUD : public AHUD
{
	GENERATED_BODY()
	
public:
  AGameLiftTestHUD();

protected:
  virtual void BeginPlay() override;

private:
  UPROPERTY()
  TSubclassOf<UUserWidget> GameWidgetClass;



};
