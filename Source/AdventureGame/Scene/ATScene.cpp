// Fill out your copyright notice in the Description page of Project Settings.


#include "ATScene.h"

#include "Components/WidgetComponent.h"

void UATScene::ShowScene()
{
	if (IsValid(WidgetClass) == false)
	{
		check(0);
		return;
	}

	if (IsValid(WidgetInstance) == false)
	{
		WidgetInstance = Cast<UUserWidget>(CreateWidget(GetWorld(), WidgetClass));

		if (IsValid(WidgetInstance) == false)
		{
			check(0);
			return;
		}

		WidgetInstance->AddToViewport();

		OnPostCreateWidgetInstance();
	}

	WidgetInstance->SetVisibility(ESlateVisibility::Visible);
}

void UATScene::HideScene()
{
	if (IsValid(WidgetInstance) == false)
	{
		check(0);
		return;
	}

	WidgetInstance->SetVisibility(ESlateVisibility::Hidden);
}

void UATScene::OnPostCreateWidgetInstance()
{
}

