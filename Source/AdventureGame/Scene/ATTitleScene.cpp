// Fill out your copyright notice in the Description page of Project Settings.


#include "ATTitleScene.h"

#include "Components/Image.h"
#include "Components/WidgetComponent.h"

#include "..\GameMode\ATStandbyGameState.h"
#include "..\GameMode\ATStandbyGameStateComponent.h"

UATTitleScene::UATTitleScene()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetAsset(TEXT("/Game/UI/Scene/W_Title.W_Title_C"));
	check(WidgetAsset.Succeeded());

	WidgetClass = WidgetAsset.Class;
}

void UATTitleScene::OnPostCreateWidgetInstance()
{
	Super::OnPostCreateWidgetInstance();

	if (IsValid(WidgetInstance) == false)
	{
		check(0);
		return;
	}

	TObjectPtr<UImage> BGImage = Cast<UImage>(WidgetInstance->GetWidgetFromName(TEXT("BG")));
	if (IsValid(BGImage) == false)
	{
		check(0);
		return;
	}
	
	BGImage->OnMouseButtonDownEvent.BindUFunction(this, TEXT("OnMouseButtonDownEvent"));
}

void UATTitleScene::OnMouseButtonDownEvent()
{
	if (IsValid(GWorld) == false)
	{
		check(0);
		return;
	}

	const TObjectPtr<const AATStandbyGameState> StandbyGameState = Cast<AATStandbyGameState>(GWorld->GetGameState());
	if (IsValid(StandbyGameState) == false)
	{
		check(0);
		return;
	}

	TObjectPtr<UATStandbyGameStateComponent> StandbyGameStateComponent = StandbyGameState->GetStandbyGameStateComponent();
	if (IsValid(StandbyGameStateComponent) == false)
	{
		check(0);
		return;
	}

	StandbyGameStateComponent->ChangeScene(UATStandbyGameStateComponent::EStandbyScene::StartMenu);
}
