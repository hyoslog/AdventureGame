// Fill out your copyright notice in the Description page of Project Settings.


#include "ATStartMenuScene.h"

#include "Components/WidgetComponent.h"

UATStartMenuScene::UATStartMenuScene()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetAsset(TEXT("/Game/UI/Scene/W_StartMenu.W_StartMenu_C"));
	check(WidgetAsset.Succeeded());

	WidgetClass = WidgetAsset.Class;
}
