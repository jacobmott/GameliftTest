// Fill out your copyright notice in the Description page of Project Settings.


#include "TextReaderComponent.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include "Runtime/Core/Public/HAL/PlatformFilemanager.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"


// Sets default values for this component's properties
UTextReaderComponent::UTextReaderComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}




// Called when the game starts
//void UTextReaderComponent::BeginPlay()
//{
//	Super::BeginPlay();
//
//	// ...
//	
//}


// Called every frame
//void UTextReaderComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

FString UTextReaderComponent::ReadFile(FString FilePath) {
  FString DirectoryPath = FPaths::ProjectContentDir();
  FString FullPath = DirectoryPath + "/" + FilePath;
  FString Result;
  IPlatformFile& File = FPlatformFileManager::Get().GetPlatformFile();

  if (File.FileExists(*FullPath)) {
    FFileHelper::LoadFileToString(Result, *FullPath);
  }

  return Result;
}