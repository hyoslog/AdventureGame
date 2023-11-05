// Fill out your copyright notice in the Description page of Project Settings.


#include "ATStandbyGameStateComponent.h"

#include "..\Scene\ATStartMenuScene.h"
#include "..\Scene\ATTitleScene.h"

UATStandbyGameStateComponent::UATStandbyGameStateComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, CurrentScene(EStandbyScene::Max)
{
	CreateScenes(ObjectInitializer);
}

void UATStandbyGameStateComponent::ChangeScene(const EStandbyScene InState)
{
	if (InState == EStandbyScene::Max)
	{
		check(0);
	}
	
	if (CurrentScene == InState)
	{
		return;
	}

	if (CurrentScene != EStandbyScene::Max)
	{
		Scenes[CurrentScene]->HideScene();
	}

	CurrentScene = InState;
	Scenes[CurrentScene]->ShowScene();
}

void UATStandbyGameStateComponent::CreateScenes(const FObjectInitializer& ObjectInitializer)
{	
	// Title
	Scenes[EStandbyScene::Title] = ObjectInitializer.CreateDefaultSubobject<UATTitleScene>(this, TEXT("TitleScene"));
	check(Scenes[EStandbyScene::Title]);

	// StartMenu
	Scenes[EStandbyScene::StartMenu] = ObjectInitializer.CreateDefaultSubobject<UATStartMenuScene>(this, TEXT("StartMenuScene"));
	check(Scenes[EStandbyScene::StartMenu]);

	// EStandbyScene에 해당하는 Scene Instance가 없는지 체크
#if UE_BUILD_SHIPPING
#else // UE_BUILD_SHIPPING	
	for(const TObjectPtr<const UATScene> Scene : Scenes)
	{
		if (Scene == nullptr)
		{
			check(0);
		}
	}
#endif // UE_BUILD_SHIPPING
}